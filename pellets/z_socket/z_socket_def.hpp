#pragma once

///> ����ID������
typedef ULONG ZLConnectId;

///> �¼�֪ͨ��������Ӱ��ͨ������ĺ�����Ϊ��
enum emZLSocketHandleResult
{
    emZLSocketHandleResultOk        = 0,        ///> �ɹ�
    emZLSocketHandleResultIgnore    = 1,        ///> ����
    emZLSocketHandleResultError     = 2,        ///> ����
};

///> Socket �������ͣ�����OnErrror��ʶ���´���Ĳ������ͣ�
enum emZLSocketOperation
{
    emZLSocketOperationUnknown  = 0,
    emZLSocketOperationAccept   = 1,
    emZLSocketOperationConnect  = 2,
    emZLSocketOperationSend     = 3,
    emZLSocketOperationReceive  = 4,
};

///> ͨ���������״̬
enum emZLServiceState
{
    emZLServiceStateStarting    = 0,    // ��������
    emZLServiceStateStarted     = 1,    // �Ѿ�����
    emZLServiceStateStoping     = 2,    // ����ֹͣ
    emZLServiceStateStoped      = 3,    // �Ѿ�����
};
