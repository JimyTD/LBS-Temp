#ifndef EXTERNFUNC_H_INCLUDED
#define EXTERNFUNC_H_INCLUDED

using namespace std;


static void SetMap(HWND hwnd,HDC hdc,int nWidth,int nHeight)
{
    RECT rt;
    GetClientRect(hwnd,&rt);
    SetMapMode(hdc,MM_ANISOTROPIC);
    SetWindowExtEx(hdc,nWidth,nHeight,NULL);
    SetViewportExtEx(hdc,rt.right,rt.bottom,NULL);
    SetViewportOrgEx(hdc,0,0,NULL);


}
typedef BOOL (FAR WINAPI *LAYERFUNC)(HWND,COLORREF,BYTE,DWORD);
static BOOL SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags)
{
    LAYERFUNC SetLayer;
    HMODULE hmod = LoadLibrary("user32.dll");
    SetLayer=(LAYERFUNC)GetProcAddress(hmod,"SetLayeredWindowAttributes");
    BOOL bReturn = SetLayer(hwnd,crKey,bAlpha,dwFlags);
    FreeLibrary(hmod);
    return bReturn;
}

typedef struct TDFONT
{
	HFONT hOldFont;
	HFONT hFont;
}TDFONT,*LPTDFONT;


static LPTDFONT ChangeFontTd(HDC hdc,long height)
{
	LOGFONT logfont;
	ZeroMemory(&logfont,sizeof(LOGFONT));
	logfont.lfCharSet=GB2312_CHARSET;
	logfont.lfHeight=height;
	HFONT hFont=CreateFontIndirect(&logfont);
	HFONT hOldFont=(HFONT)::SelectObject(hdc,hFont);
	LPTDFONT pFont= new TDFONT;
	(*pFont).hOldFont=hOldFont;
	(*pFont).hFont=hFont;
	return pFont;
}
static int DeleteFontTd(HDC hdc,LPTDFONT pFont)
{
    SelectObject(hdc,(*pFont).hOldFont);
    DeleteObject((*pFont).hFont);
	delete pFont;
	return 0;
}

#endif // EXTERNFUNC_H_INCLUDED
