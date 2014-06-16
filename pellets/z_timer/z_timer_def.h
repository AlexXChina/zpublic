#pragma once
#include <windows.h>

///> ���ʱ��������������ִ�е㣬��bootʱ��ͳ���ִ��ʱ�䶼�ǿ��Ե�
inline unsigned int TimerGetTime()
{
    return ::GetTickCount();
}

inline unsigned int TimerCalcMilliseconds(
    unsigned int h,
    unsigned int m,
    unsigned int s)
{
    return h * 3600000 + m * 60000 + s * 1000;
}

inline unsigned int TimerCalcMilliseconds(
    unsigned int m,
    unsigned int s)
{
    return m * 60000 + s * 1000;
}

inline unsigned int TimerCalcMilliseconds(
    unsigned int s)
{
    return s * 1000;
}

///> ����ִ�д���Ϊ99999�������ظ�
#define TaskRepeatDef 99999
