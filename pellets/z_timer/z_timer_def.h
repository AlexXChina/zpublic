#pragma once
#include <windows.h>

///> ���ʱ��������������ִ�е㣬��bootʱ��ͳ���ִ��ʱ�䶼�ǿ��Ե�
inline unsigned int TimerGetTime()
{
    return ::GetTickCount();
}

///> ����ִ�д���Ϊ99999�������ظ�
#define TaskRepeatDef 99999
