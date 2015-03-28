#pragma once

///> �ͻ��˲����������
enum emZLClientError
{
    emZLClientErrorOk                   = 0,    // �ɹ�
    emZLClientErrorIllegalState         = 1,    // ��ǰ״̬���������
    emZLClientErrorInvalidParam         = 2,    // �Ƿ�����
    emZLClientErrorSocketCreateFail     = 3,    // ���� Client Socket ʧ��
    emZLClientErrorSocketPrepareFail    = 4,    // ���� Client Socket ʧ��
    emZLClientErrorConnectServerFail    = 5,    // ���ӷ�����ʧ��
    emZLClientErrorWorkerCreateFail     = 6,    // ���������߳�ʧ��
    emZLClientErrorNetworkError         = 7,    // �������
    emZLClientErrorDataProcError        = 8,    // ���ݴ������
};

typedef std::list<zl::WinUtils::ZLBuffer*>      ZLBufferList;
