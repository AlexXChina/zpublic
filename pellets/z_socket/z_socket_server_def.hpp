#pragma once

///> ����˲����������
enum emZLServerError
{
    emZLServerErrorOk                   = 0,    // �ɹ�
    emZLServerErrorIllegalState         = 1,    // ��ǰ״̬���������
    emZLServerErrorInvalidParam         = 2,    // �Ƿ�����
    emZLServerErrorSocketCreateFail     = 3,    // ���� Socket ʧ��
    emZLServerErrorSocketBindFail       = 4,    // �󶨼�����ַʧ��
    emZLServerErrorSocketPrepareFail    = 5,    // ���ü��� Socket ʧ��
    emZLServerErrorSocketListenFail     = 6,    // ��������ʧ��
    emZLServerErrorCpCreateFail         = 7,    // ������ɶ˿�ʧ��
    emZLServerErrorWorkerCreateFail     = 8,    // ���������߳�ʧ��
    emZLServerErrorSocketAttachCpFail   = 9,    // ���� Socket �󶨵���ɶ˿�ʧ��
    emZLServerErrorAcceptCreateFail     = 10,   // ���������߳�ʧ��
    emZLServerErrorGetFuncPtrFail       = 11,   // WSAIoctlȡ������ַʧ��
};

///> ���ݻ�����
typedef struct _TBufferObj
{
    OVERLAPPED          ov;
    WSABUF              buf;
    emZLSocketOperation oper;
    SOCKET              client;
}TBufferObj;

///> socket������
typedef struct _TSocketObj
{
    SOCKET              socket;
    sockaddr_in         clientAddr;
    ZLConnectId         connId;
    z_mutex*            pmutex;
}TSocketObj;

typedef std::list<TBufferObj*>              TBufferObjList;
typedef std::list<TSocketObj*>              TSocketObjList;
typedef std::map<ZLConnectId, TSocketObj*>  TSocketObjMap;
