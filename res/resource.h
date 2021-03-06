//stamp:0afd78b7e46fd6a5
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				page_client = _T("LAYOUT:page_client");
				page_server = _T("LAYOUT:page_server");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * page_client;
			const TCHAR * page_server;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
			}
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_add_int",65548},
		{L"btn_add_str",65551},
		{L"btn_clear_log",65547},
		{L"btn_close",65537},
		{L"btn_connect",65545},
		{L"btn_copy_id",65559},
		{L"btn_disconnect",65546},
		{L"btn_hello",65560},
		{L"btn_max",65538},
		{L"btn_min",65540},
		{L"btn_restore",65539},
		{L"btn_sum",65554},
		{L"edit_int_a",65549},
		{L"edit_int_b",65550},
		{L"edit_n",65555},
		{L"edit_str_a",65552},
		{L"edit_str_b",65553},
		{L"edit_sum",65556},
		{L"edit_svr_id",65544},
		{L"log_client",65557},
		{L"log_svr",65561},
		{L"page_client",65542},
		{L"page_server",65543},
		{L"tab_mode",65541},
		{L"txt_svr_id",65558},
		{L"txt_title",65536}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_add_int = namedXmlID[1].strName;
			btn_add_str = namedXmlID[2].strName;
			btn_clear_log = namedXmlID[3].strName;
			btn_close = namedXmlID[4].strName;
			btn_connect = namedXmlID[5].strName;
			btn_copy_id = namedXmlID[6].strName;
			btn_disconnect = namedXmlID[7].strName;
			btn_hello = namedXmlID[8].strName;
			btn_max = namedXmlID[9].strName;
			btn_min = namedXmlID[10].strName;
			btn_restore = namedXmlID[11].strName;
			btn_sum = namedXmlID[12].strName;
			edit_int_a = namedXmlID[13].strName;
			edit_int_b = namedXmlID[14].strName;
			edit_n = namedXmlID[15].strName;
			edit_str_a = namedXmlID[16].strName;
			edit_str_b = namedXmlID[17].strName;
			edit_sum = namedXmlID[18].strName;
			edit_svr_id = namedXmlID[19].strName;
			log_client = namedXmlID[20].strName;
			log_svr = namedXmlID[21].strName;
			page_client = namedXmlID[22].strName;
			page_server = namedXmlID[23].strName;
			tab_mode = namedXmlID[24].strName;
			txt_svr_id = namedXmlID[25].strName;
			txt_title = namedXmlID[26].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_add_int;
		 const wchar_t * btn_add_str;
		 const wchar_t * btn_clear_log;
		 const wchar_t * btn_close;
		 const wchar_t * btn_connect;
		 const wchar_t * btn_copy_id;
		 const wchar_t * btn_disconnect;
		 const wchar_t * btn_hello;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_sum;
		 const wchar_t * edit_int_a;
		 const wchar_t * edit_int_b;
		 const wchar_t * edit_n;
		 const wchar_t * edit_str_a;
		 const wchar_t * edit_str_b;
		 const wchar_t * edit_sum;
		 const wchar_t * edit_svr_id;
		 const wchar_t * log_client;
		 const wchar_t * log_svr;
		 const wchar_t * page_client;
		 const wchar_t * page_server;
		 const wchar_t * tab_mode;
		 const wchar_t * txt_svr_id;
		 const wchar_t * txt_title;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_add_int	=	65548;
		const static int btn_add_str	=	65551;
		const static int btn_clear_log	=	65547;
		const static int btn_close	=	65537;
		const static int btn_connect	=	65545;
		const static int btn_copy_id	=	65559;
		const static int btn_disconnect	=	65546;
		const static int btn_hello	=	65560;
		const static int btn_max	=	65538;
		const static int btn_min	=	65540;
		const static int btn_restore	=	65539;
		const static int btn_sum	=	65554;
		const static int edit_int_a	=	65549;
		const static int edit_int_b	=	65550;
		const static int edit_n	=	65555;
		const static int edit_str_a	=	65552;
		const static int edit_str_b	=	65553;
		const static int edit_sum	=	65556;
		const static int edit_svr_id	=	65544;
		const static int log_client	=	65557;
		const static int log_svr	=	65561;
		const static int page_client	=	65542;
		const static int page_server	=	65543;
		const static int tab_mode	=	65541;
		const static int txt_svr_id	=	65558;
		const static int txt_title	=	65536;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
