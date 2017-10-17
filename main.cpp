#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;
SYSTEMTIME SysTime;
UINT hour;

const UINT Id_t = 1;



BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        SetTimer(hwndDlg, Id_t, 1000, NULL);
    }
    return TRUE;

    case WM_CLOSE:
    {
        KillTimer(hwndDlg, Id_t);
        EndDialog(hwndDlg, 0);
        PostQuitMessage(0);
    }
    return TRUE;

    case WM_TIMER:
    {
        GetLocalTime(&SysTime);
        if (SysTime.wMinute == 50)
        {
            if (hour != SysTime.wHour)
                {
                    hour = SysTime.wHour;
                    MessageBox(NULL, "Качайся", "Качайся", MB_SYSTEMMODAL);
                }
        }

    }

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
