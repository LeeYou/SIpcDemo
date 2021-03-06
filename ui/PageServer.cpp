#include "stdafx.h"
#include "PageServer.h"
#define LOG_FILTER "server"


class GlobalMemory {
	HGLOBAL hand;
public:
	void *ptr;
	GlobalMemory() : hand(0), ptr(0) {
	}
	GlobalMemory(HGLOBAL hand_) : hand(hand_), ptr(0) {
		if (hand) {
			ptr = ::GlobalLock(hand);
		}
	}
	~GlobalMemory() {
		SASSERT(!ptr);
	}
	void Allocate(size_t bytes) {
		hand = ::GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, bytes);
		if (hand) {
			ptr = ::GlobalLock(hand);
		}
	}
	HGLOBAL Unlock() {
		SASSERT(ptr);
		HGLOBAL handCopy = hand;
		::GlobalUnlock(hand);
		ptr = 0;
		hand = 0;
		return handCopy;
	}
	void SetClip(UINT uFormat) {
		::SetClipboardData(uFormat, Unlock());
	}
	operator bool() const {
		return ptr != 0;
	}
	SIZE_T Size() {
		return ::GlobalSize(hand);
	}
};


CSvrConnect::CSvrConnect(IIpcHandle * pHandle) :m_ipcHandle(pHandle)
{
}

CSvrConnect::~CSvrConnect()
{
	m_ipcHandle = NULL;
}

IIpcHandle * CSvrConnect::GetIpcHandle()
{
	return m_ipcHandle;
}

void CSvrConnect::BuildShareBufferName(ULONG_PTR idLocal, ULONG_PTR idRemote, TCHAR szBuf[MAX_PATH]) const
{
	_stprintf(szBuf, DEMO_SHARE_BUF_NAME_FMT, (DWORD)(((LPARAM)idLocal) & 0xffffffff), (DWORD)(((LPARAM)idRemote) & 0xffffffff));
}

void CSvrConnect::OnAddInt(Param_AddInt & param)
{
	SLOG_INFO("execute add int, a: " << param.a << " b:" << param.b);
	param.ret = param.a + param.b;
}
void CSvrConnect::OnAddStr(Param_AddString & param)
{
	SLOG_INFO("execute add string, a: " << param.a.c_str() << " b:" << param.b.c_str());
	param.ret = AddBack(param.a, param.b, 20, 50);
	SLOG_INFO("add string ret: " << param.ret.c_str());
}

void CSvrConnect::SayHello(const std::string & name)
{
	SLOG_INFO("execute say hello, name= " << name.c_str());

	Param_Hello param;
	param.text = name;
	m_ipcHandle->CallFun(&param);
}

std::string CSvrConnect::AddBack(const std::string & a, const std::string & b, int a2, int b2)
{
	SLOG_INFO("execute AddBack");
	Param_AddBack param;
	param.a = a;
	param.b = b;
	param.a2 = a2;
	param.b2 = b2;
	m_ipcHandle->CallFun(&param);
	return param.ret;

}


void CSvrConnect::OnSum(Param_Sum & param)
{
	//recursive call to calc sum (1,n);
	SASSERT(param.n >= 1);
	if (param.n == 1)
	{
		param.nRet = 1;
	}
	else
	{
		Param_Sum p2;
		p2.n = param.n - 1;
		m_ipcHandle->CallFun(&p2);
		param.nRet = param.n + p2.nRet;
		SLOGFMTD("sum(1,%d)=%d", p2.n, p2.nRet);
	}
}
///////////////////////////////////////////////////////////////////
CPageServer::CPageServer()
{
	CAutoRefPtr<IIpcFactory> ipcFac;
	m_comMgr.CreateIpcObject((IObjRef**)&ipcFac);
	ipcFac->CreateIpcServer(&m_ipcSvr);
}


CPageServer::~CPageServer()
{
	m_ipcSvr = NULL;
}

void CPageServer::OnInit(SWindow * pRoot)
{
	__super::OnInit(pRoot);
	m_pLogView = FindChildByID2<SRichEdit>(R.id.log_svr);
	HWND hHost = pRoot->GetContainer()->GetHostHwnd();
	SWindow *pTxtSvr = FindChildByID(R.id.txt_svr_id);
	SASSERT(pTxtSvr);
	pTxtSvr->SetWindowText(SStringT().Format(_T("0x%08x"), (DWORD)hHost));
	m_ipcSvr->Init((ULONG_PTR)hHost, this);
	::SetTimer(hHost,100,50,NULL);
}

void CPageServer::onLog(int level, const char * filter, const SStringW &buf)
{
	if (strcmp(filter, LOG_FILTER) != 0)
		return;
	m_pLogView->ReplaceSel(buf, FALSE);
	m_pLogView->SSendMessage(WM_VSCROLL, MAKEWPARAM(SB_BOTTOM, 0));
	int nLines = m_pLogView->SSendMessage(EM_GETLINECOUNT);
	if (nLines>60000)
	{
		int iLineIdx = m_pLogView->SSendMessage(EM_LINEINDEX, 30000);
		m_pLogView->SSendMessage(EM_SETSEL, 0, iLineIdx);
		m_pLogView->ReplaceSel(L"", FALSE);
	}
}

void CPageServer::OnCopySvrId()
{
	SStringT str = FindChildByID(R.id.txt_svr_id)->GetWindowText();
	HWND hHost = GetRoot()->GetContainer()->GetHostHwnd();
	if (OpenClipboard(hHost))
	{
		::EmptyClipboard();
		GlobalMemory mem;
		SStringW strBuf = S_CT2W(str);
		mem.Allocate((strBuf.GetLength()+1) * sizeof(WCHAR));
		memcpy(mem.ptr, (LPCWSTR)strBuf, (strBuf.GetLength() + 1) * sizeof(WCHAR));
		mem.SetClip(CF_UNICODETEXT);
		CloseClipboard();
		SLOG_INFO("server id had been copied to clipboard!");
	}
	else
	{
		SLOG_ERROR("open clipboard failied!!!");
	}
}

void CPageServer::DoSayHello(IIpcConnection *pConn,ULONG_PTR data)
{
	CPageServer * _this = (CPageServer*)data;
	Param_Hello param;
	param.text = "hello, i'm server";
	pConn->GetIpcHandle()->CallFun(&param);
}

void CPageServer::OnHello()
{
	m_ipcSvr->EnumClient(&CPageServer::DoSayHello,(ULONG_PTR)this);
}

void CPageServer::OnClearLog()
{
	m_pLogView->SetWindowText(NULL);
}

void CPageServer::OnNewConnection(IIpcHandle * pIpcHandle, IIpcConnection ** ppConn)
{
	*ppConn = new CSvrConnect(pIpcHandle);
}

int CPageServer::GetBufSize() const
{
	return 1024;
}

void * CPageServer::GetSecurityAttr() const
{
	return NULL;
}

void CPageServer::ReleaseSecurityAttr(void * psa) const
{
}

void CPageServer::OnTimer(UINT_PTR id)
{
	if(id==100)
	{
		m_ipcSvr->CheckConnectivity();
	}else
	{
		SetMsgHandled(FALSE);
	}
}

void CPageServer::OnConnected(IIpcConnection * pConn)
{
	SLOG_INFO("new connection accepted,client id:"<<pConn->GetIpcHandle()->GetRemoteId());
}

void CPageServer::OnDisconnected(IIpcConnection * pConn)
{
	SLOG_INFO("connection disconnected,client id:" << pConn->GetIpcHandle()->GetRemoteId());
}
