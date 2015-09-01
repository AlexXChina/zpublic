#pragma once

///> PULL ģ������ӿ�
class IZLPullClient
{
public:
    /**
    * @brief     ץȡ����
    * @param[in] pBuffer                ����ץȡ������
    * @param[in] iLength                ץȡ���ݳ���
    * @return    TRUE �ɹ� FALSE ʧ��
    */
    virtual BOOL Fetch(BYTE* pBuffer, int iLength) = 0;

    /**
    * @brief     ��̽���ݣ������Ƴ����������ݣ�
    * @param[in] pBuffer                ����ץȡ������
    * @param[in] iLength                ץȡ���ݳ���
    * @return    TRUE �ɹ� FALSE ʧ��
    */
    virtual BOOL Peek(BYTE* pBuffer, int iLength) = 0;

public:
    virtual ~IZLPullClient() {}
};
