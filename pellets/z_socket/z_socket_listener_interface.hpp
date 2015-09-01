#pragma once

///> Socket �������ӿ�
class IZLSocketListener
{
public:
    /**
    * @brief     �ѷ�������֪ͨ
    * @param[in] connId         ���� ID
    * @param[in] pData          �ѷ������ݻ�����
    * @param[in] iLength        �ѷ������ݳ���
    * @return    HR_OK/HR_IGNORE ����ִ�� , �������� HR_ERROR
    */
    virtual emZLSocketHandleResult OnSend(
        ZLConnectId connId,
        const BYTE* pData,
        int iLength) = 0;

    /**
    * @brief     �ѽ�������֪ͨ��PUSH ģ�ͣ�
    * @param[in] connId         ���� ID
    * @param[in] pData          �ѽ������ݻ�����
    * @param[in] iLength        �ѽ������ݳ���
    * @return    HR_OK/HR_IGNORE ����ִ�� , HR_ERROR���� OnError() �¼�ʱ�䲢�ر�����
    */
    virtual emZLSocketHandleResult OnReceive(
        ZLConnectId connId,
        const BYTE* pData,
        int iLength) = 0;

    /**
    * @brief     ���ݵ���֪ͨ��PULL ģ�ͣ�
    * @param[in] connId         ���� ID
    * @param[in] iLength        �ѽ������ݳ���
    * @return    HR_OK/HR_IGNORE ����ִ�� , HR_ERROR���� OnError() �¼�ʱ�䲢�ر�����
    */
    virtual emZLSocketHandleResult OnReceive(ZLConnectId connId, int iLength) = 0;

    /**
    * @brief     �ѹر�����֪ͨ
    * @param[in] connId         ���� ID
    * @return    void
    */
    virtual void OnClose(ZLConnectId connId) = 0;

    /**
    * @brief     ͨ�Ŵ���֪ͨ
    * @param[in] connId         ���� ID
    * @param[in] emOperation    Socket ��������
    * @param[in] iErrorCode     �������
    * @return    void
    */
    virtual void OnError(
        ZLConnectId connId,
        emZLSocketOperation emOperation,
        int iErrorCode) = 0;

public:
    virtual ~IZLSocketListener() {}
};
