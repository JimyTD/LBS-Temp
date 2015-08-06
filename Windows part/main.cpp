#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
///////////////////////////////
#include <windows.h>
#include"externFunc.h"
#include <tchar.h>
#include<commctrl.h>
#include<iostream>


#include"Barage.h"
#include"BUnit.h"
//////////////////////////////
using namespace std;
#define LWA_COLORKEY 0x00000001
#define LWA_ALPHA 0x00000002
#define WIDTH 1024
#define HEIGHT 768
#define IDT_TIMER1 456
#define LINES 16
////////////
int test=0;
/////



/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
Barage bar;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = CreateSolidBrush(RGB(255,255,255));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_POPUP|WS_EX_LAYERED, /* default window *///////////////////////////////////
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           GetSystemMetrics(SM_CXSCREEN),                 /* The programs width */
           GetSystemMetrics(SM_CYSCREEN),                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /////////INITIALIZE....
    SetWindowPos(hwnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
    SetWindowLong(hwnd,GWL_EXSTYLE,GetWindowLong(hwnd,GWL_EXSTYLE)|WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, RGB(0,0,0),255,LWA_ALPHA|LWA_COLORKEY);
    bar.setWnd(hwnd);
    bar.InitTimer();
    srand(GetTickCount());


    //////////


    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {

        case WM_DESTROY:
            {
                PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
                break;
            }

        case WM_PAINT:
            {

                PAINTSTRUCT ps;
                HDC hdc=BeginPaint(hwnd,&ps);
                SetMap(hwnd,hdc,WIDTH,HEIGHT);
                SetBkMode(hdc,TRANSPARENT);
                bar.draw(hdc,hwnd);
                EndPaint(hwnd,&ps);

                break;
            }
        case WM_CHAR:
            {
                bar.Clear();
                KillTimer(hwnd,IDT_TIMER1);
                exit(1);
                break;
            }
        case WM_TIMER:
            {
                bar.GetBarageT();
                bar.move();
                //test++;
                InvalidateRect(hwnd,NULL,1);
                break;

            }
        case WM_ERASEBKGND:
            {
               break;
            }

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

