#pragma once

///> ��һ�����Ϣ������
class CPlayerBasicInfo
{
public:
    CPlayerBasicInfo();
    ~CPlayerBasicInfo();

    ULONGLONG GetShenli()
    {
        z_mutex_guard g(m_mutex_ullShenli);
        return m_ullShenli;
    }

    void SetShenli(ULONGLONG n)
    {
        z_mutex_guard g(m_mutex_ullShenli);
        m_ullShenli = n;
    }

    void AddShenli(ULONGLONG n)
    {
        z_mutex_guard g(m_mutex_ullShenli);
        m_ullShenli += n;
    }

    bool SubShenli(ULONGLONG n)
    {
        z_mutex_guard g(m_mutex_ullShenli);
        if (n > m_ullShenli)
        {
            return false;
        }
        m_ullShenli -= n;
        return true;
    }

private:
    CString             m_sPalyerName;
    ULONGLONG           m_ullShenli;
    z_mutex             m_mutex_ullShenli;
};

