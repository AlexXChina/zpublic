#pragma once

///> �ͻ��� Socket �������ӿ�
class IZLClientSocketListener : public IZLSocketListener
{
public:
    /**
    * @brief     ׼������֪ͨ������Socket ѡ�����õȶ��⹤����
    * @param[in] connId         ���� ID
    * @param[in] socket         �ͻ��� Socket
    * @return    HR_OK / HR_IGNORE ����ִ�У�HR_ERROR ��ֹ����
    */
    virtual emZLSocketHandleResult OnPrepareConnect(ZLConnectId connId, SOCKET socket) = 0;

    /**
    * @brief     �������֪ͨ������Socket ѡ�����õȶ��⹤����
    * @param[in] connId         ���� ID
    * @return    HR_OK / HR_IGNORE ����ִ�У�HR_ERROR ͬ��������ֹ���� �첽���ӹر�����
    */
    virtual emZLSocketHandleResult OnConnect(ZLConnectId connId) = 0;
};
