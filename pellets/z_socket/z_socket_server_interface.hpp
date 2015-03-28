#pragma once

///> ͨ�ŷ��������ӿ�
class IZLServerSocket
{
public:
    /**
    * @brief     ����ͨ�����
    * @param[in] pszBindAddress     ������ַ
    * @param[in] usPort             �����˿�
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Start(LPCWSTR pszBindAddress, USHORT usPort) = 0;

    /**
    * @brief     �ر�ͨ�����
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Stop() = 0;

    /**
    * @brief     ��������
    * @param[in] connId     ����ID
    * @param[in] pBuffer    �������ݻ�����
    * @param[in] iLength    �������ݳ���
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Send(ZLConnectId connId, const BYTE* pBuffer, int iLength) = 0;

    /**
    * @brief     �Ͽ�����
    * @param[in] connId     ����ID
    * @param[in] bForce     �Ƿ�ǿ�ƶϿ�����
    * @return    TRUE �ɹ� FALSE ʧ�ܣ���ͨ�� GetLastError() ��ȡ������룩
    */
    virtual BOOL Disconnect(ZLConnectId connId, BOOL bForce = TRUE) = 0;

public:
    virtual BOOL HasStarted()                                                               = 0;
    virtual emZLServiceState GetState()                                                     = 0;
    virtual emZLServerError GetLastError()                                                  = 0;
    virtual BOOL GetListenAddress(CStringW& strAddress, USHORT& usPort)                     = 0;
    virtual BOOL GetClientAddress(ZLConnectId connId, CStringW& strAddress, USHORT& usPort) = 0;

    ///> ���ù����߳�������ͨ��Ϊ2*CPU+2��
    virtual void SetWorkerThreadCount(DWORD dwWorkerThreadCount)        = 0;
    ///> ����AcceptԤͶ��socket������ͨ��Ϊ�����߳�1-2����
    virtual void SetAcceptSocketCount(DWORD dwAcceptSocketCount)        = 0;
    ///> ����ͨ�Ż�������С������ͨ�Ű���С������ͨ��Ϊ1024�ı�����
    virtual void SetSocketBufferSize(DWORD dwSocketBufferSize)          = 0;
    ///> ���ü���socket�ĵȴ����д�С�����ݲ�����������������
    virtual void SetSocketListenQueue(DWORD dwSocketListenQueue)        = 0;
    ///> ����socket����صĴ�С��ͨ��Ϊƽ��������������1/3-1/2��
    virtual void SetFreeSocketObjPool(DWORD dwFreeSocketObjPool)        = 0;
    ///> �����ڴ�黺��صĴ�С��ͨ��Ϊsocket����ص�2-3����
    virtual void SetFreeBufferObjPool(DWORD dwFreeBufferObjPool)        = 0;
    ///> ����socket����ػ��շ�ֵ��ͨ��Ϊsocket����ص�3����
    virtual void SetFreeSocketObjHold(DWORD dwFreeSocketObjPool)        = 0;
    ///> �����ڴ�黺��ػ��շ�ֵ��ͨ��Ϊ�ڴ�黺��ش�С��3����
    virtual void SetFreeBufferObjHold(DWORD dwFreeBufferObjHold)        = 0;
    ///> �������������
    virtual void SetKeepAliveTime(DWORD dwKeepAliveTime)                = 0;
    ///> ����������ȷ�ϼ����
    virtual void SetKeepAliveInterval(DWORD dwKeepAliveInterval)        = 0;
    ///> ���ùرշ���ǰ�ȴ����ӹرյ��ʱ��
    virtual void SetMaxShutdownWaitTime(DWORD dwMaxShutdownWaitTime)    = 0;

    virtual DWORD GetWorkThreadCount()                                  = 0;
    virtual DWORD GetAcceptSocketCount()                                = 0;
    virtual DWORD GetSocketBufferSize()                                 = 0;
    virtual DWORD GetSocketListenQueue()                                = 0;
    virtual DWORD GetFreeSocketObjPool()                                = 0;
    virtual DWORD GetFreeBufferObjPool()                                = 0;
    virtual DWORD GetFreeSocketObjHold()                                = 0;
    virtual DWORD GetFreeBufferObjHold()                                = 0;
    virtual DWORD GetKeepAliveTime()                                    = 0;
    virtual DWORD GetKeepAliveInterval()                                = 0;
    virtual DWORD GetMaxShutdownWaitTime()                              = 0;

public:
    virtual ~IZLServerSocket() {}
};
