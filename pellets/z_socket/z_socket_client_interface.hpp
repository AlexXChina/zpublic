#pragma once

///> ͨ�ſͻ�������ӿ�
class IZLClientSocket
{
public:
    /**
    * @brief     ����ͨ�����
    * @param[in] pszRemoteAddress   ����˵�ַ
    * @param[in] usPort             ����˶˿�
    * @param[in] bAsyncConnect      �Ƿ�����첽 Connnect
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Start(
        LPCWSTR pszRemoteAddress,
        USHORT usPort,
        BOOL bAsyncConnect = FALSE) = 0;

    /**
    * @brief     �ر�ͨ�����
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Stop() = 0;

    /**
    * @brief     ��������
    * @param[in] pBuffer    �������ݻ�����
    * @param[in] iLength    �������ݳ���
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Send(const BYTE* pBuffer, int iLength) = 0;

public:
    virtual BOOL HasStarted()                                           = 0;
    virtual emZLServiceState GetState()                                 = 0;
    virtual emZLClientError GetLastError()                              = 0;
    virtual ZLConnectId GetConnectionID()                               = 0;
    virtual BOOL GetLocalAddress(CStringW& strAddress, USHORT& usPort)  = 0;

    virtual void SetSocketBufferSize(DWORD dwSocketBufferSize)          = 0;
    virtual void SetKeepAliveTime(DWORD dwKeepAliveTime)                = 0;
    virtual void SetKeepAliveInterval(DWORD dwKeepAliveInterval)        = 0;
    virtual DWORD GetSocketBufferSize()                                 = 0;
    virtual DWORD GetKeepAliveTime()                                    = 0;
    virtual DWORD GetKeepAliveInterval()                                = 0;

public:
    virtual ~IZLClientSocket() {}
};
