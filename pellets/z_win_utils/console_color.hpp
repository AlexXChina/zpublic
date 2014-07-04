/*************************************************************************
 *                                                                       *
 *  I|*j^3Cl|a   "+!*%                  qt          Nd   gW              *
 *  l]{y+l?MM*  !#Wla\NNP               NW          MM   I|              *
 *        PW    ?E|    tWg              Wg  sC!     AW           ~@v~    *
 *       NC     ?M!    yN|  WW     MK   MW@K1Y%M@   RM   #Q    QP@tim    *
 *     CM|      |WQCljAE|   MD     Mg   RN     cM~  NM   WQ   MQ         *
 *    #M        aQ?         MW     M3   Mg      Q(  HQ   YR  IM|         *
 *   Dq         {Ql         MH    iMX   Mg     MM   QP   QM   Eg         *
 * !EWNaPRag2$  +M"          $WNaHaN%   MQE$%EXW    QQ   CM    %M%a$D    *
 *                                                                       *
 *               Website: https://github.com/zpublic/zpublic             *
 *                                                                       *
 ************************************************************************/
#pragma once
#include "win_utils_header.h"

namespace zl
{
namespace WinUtils
{
    typedef enum _emConsoleColor
    {
        emConsoleColourBlack = 0,
        emConsoleColourYellow = 6,
        emConsoleColourGray = 8, 
//         0=��ɫ          8=��ɫ
//         1=��ɫ          9=����ɫ
//         2=��ɫ          A=����ɫ
//         3=����ɫ        B=��ǳ��ɫ
//         4=��ɫ          C=����ɫ
//         5=��ɫ          D=����ɫ
//         6=��ɫ          E=����ɫ
//         7=��ɫ          F=����ɫ 
    }emConsoleColor;

    class ZLConsoleColor
    {
    public:
        ZLConsoleColor() {}
        ~ZLConsoleColor() {}

    public:
        static BOOL SetConsoleForegroundColor(emConsoleColor color)
        {
            HANDLE hOutPutHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOutPutHandle != INVALID_HANDLE_VALUE)
            {
                WORD wColor = GetConsoleColor() & 0xf0;
                return ::SetConsoleTextAttribute(hOutPutHandle, wColor | (BYTE)color);
            }
            return FALSE;
        }

        static BOOL SetConsoleBackgroundColor(emConsoleColor color)
        {
            HANDLE hOutPutHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOutPutHandle != INVALID_HANDLE_VALUE)
            {
                WORD wColor = GetConsoleColor() & 0xf;
                return ::SetConsoleTextAttribute(hOutPutHandle, wColor | ((WORD((BYTE)color) << 4)));
            }
            return FALSE;
        }

        static BOOL SetColorFontDefault()
        {
            HANDLE hOutPutHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOutPutHandle != INVALID_HANDLE_VALUE)
            {
                return ::SetConsoleTextAttribute(hOutPutHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            }
            return FALSE;
        }

        static WORD GetConsoleColor()
        {
            WORD wRet = 0;
            HANDLE hOutPutHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOutPutHandle != INVALID_HANDLE_VALUE)
            {
                CONSOLE_SCREEN_BUFFER_INFO consoleInfo = {0};
                if (::GetConsoleScreenBufferInfo(hOutPutHandle, &consoleInfo))
                {
                    wRet = consoleInfo.wAttributes;
                }
            }
            return wRet;
        }
    };

}
}