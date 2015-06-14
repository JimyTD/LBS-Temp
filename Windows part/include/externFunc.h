#ifndef EXTERNFUNC_H_INCLUDED
#define EXTERNFUNC_H_INCLUDED



#endif // EXTERNFUNC_H_INCLUDED
void SetMap(HWND hwnd,HDC hdc,int nWidth,int nHeight)
{
    RECT rt;
    GetClientRect(hwnd,&rt);
    SetMapMode(hdc,MM_ANISOTROPIC);
    SetWindowExtEx(hdc,nWidth,nHeight,NULL);
    SetViewportExtEx(hdc,rt.right,rt.bottom,NULL);
    SetViewportOrgEx(hdc,0,0,NULL);


}
typedef BOOL (FAR WINAPI *LAYERFUNC)(HWND,COLORREF,BYTE,DWORD);
BOOL SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags)
{
LAYERFUNC SetLayer;
HMODULE hmod = LoadLibrary("user32.dll");
SetLayer=(LAYERFUNC)GetProcAddress(hmod,"SetLayeredWindowAttributes");
BOOL bReturn = SetLayer(hwnd,crKey,bAlpha,dwFlags);
FreeLibrary(hmod);
return bReturn;
}
