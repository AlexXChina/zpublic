/*************************************************************************
 *                                                                       *
 *  I|*j^3Cl|a   "+!*%                  qt          Nd   gW              *
 *  l]{y+l?MM*  !#Wla\NNP               NW          MM   I|              *
 *        PW    ?E|    tWg              Wg  sC!     AW           ~@v~    *
 *       NC     ?M!    yN|  WW     MK   MW@K1Y%M@   RM   #Q    QP@tim    *
 *     CM|      |WQCljAE|   MD     Mg   RN     cM~  NM   WQ   MQ         *
 *    #M        aQ?         MW     M3   Mg      Q(  HQ   YR  IM|         *
 *   Dq         {Ql         MH    iMX   Mg     MM   QP   QM   Eg         *
 * !EWNaPRag2$  +M"          $WNaHaN%   MQE$%EXW    QQ   CM    %M%a$D    *
 *                                                                       *
 *               Website: https://github.com/zpublic/zpublic             *
 *                                                                       *
 ************************************************************************/

/**
 * @file
 * @brief �ļ���Ϣ���
 * 
 *      �ļ���Ϣ������С,�޸�ʱ���.
 */


#pragma once
#include "win_utils_header.h"

namespace zl
{
namespace WinUtils
{
    /**
     * @brief �ļ���Ϣ��غ�������
     */
    class ZLFileInfo
    {
    public:

        /**
         * @brief ��ȡ�ļ���С
         * @param[in] lpFilePath �ļ�·��
         * @param[out] lSize     ���ڴ洢�ļ��Ĵ�С��Ϣ
         * @return �ɹ�����TRUE, ����lSize�д�ŵ����ļ��Ĵ�С��Ϣ, ʧ�ܷ���FALSE.
         */
        static BOOL GetFileSize(LPCTSTR lpFilePath, LONGLONG &lSize)
        {
            BOOL bReturn = FALSE;

            HANDLE hFile = ::CreateFile(
                lpFilePath,
                GENERIC_READ,
                FILE_SHARE_READ | FILE_SHARE_WRITE |FILE_SHARE_DELETE,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL);

            if (INVALID_HANDLE_VALUE != hFile)
            {
                LARGE_INTEGER lFileSize = {0};
                if (::GetFileSizeEx(hFile, &lFileSize))
                {
                    lSize = lFileSize.QuadPart;
                    bReturn = TRUE;
                }

                ::CloseHandle(hFile);
            }

            return bReturn;
        }

        /**
         * @brief ��ȡ�ļ��Ĵ���ʱ��,����ʱ�估�޸�ʱ��
         * @param[in]  lpFilePath   �ļ�·��
         * @param[out] pftCreate    ���ڴ洢�õ��Ĵ���ʱ��,����Ҫ����NULL
         * @param[out] pftAccess    ���ڴ洢�õ��ķ���ʱ��,����Ҫ����NULL
         * @param[out] pftWrite     ���ڴ洢�õ����޸�ʱ��,����Ҫ����NULL
         * @return �ɹ�����TRUE,ʧ�ܷ���FALSE
         */
        static BOOL GetFileTimeInfo(
            LPCTSTR   lpFilePath,
            PFILETIME pftCreate,
            PFILETIME pftAccess,
            PFILETIME pftWrite)
        {
            BOOL bReturn = FALSE;

            HANDLE hFile = ::CreateFile(
                lpFilePath,
                GENERIC_READ, 
                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 
                NULL, 
                OPEN_EXISTING, 
                FILE_ATTRIBUTE_NORMAL, 
                NULL);

            if (hFile != INVALID_HANDLE_VALUE)
            {
                bReturn = ::GetFileTime(hFile, pftCreate, pftAccess, pftWrite);

                ::CloseHandle(hFile);
            }

            return bReturn;
        }

        /**
         * @brief �ļ���Ϣ��
         * @author Manuel Laflamme
         */
        class ZLFileVersion
        {
        public:
            ZLFileVersion()
            {
                m_lpVersionData = NULL;
                m_dwLangCharset = 0;
            }
            ~ZLFileVersion()
            {
                Close();
            }
        public:
            /**
             * @brief ��ȡ�ļ�����Ϣ
             * @param[in]  lpFilePath   �ļ�·��
             * @return �ɹ�����TRUE,ʧ�ܷ���FALSE
             */
            BOOL Open(LPCTSTR lpszModuleName)
            {
                if (m_lpVersionData || !lpszModuleName)
                {
                    return FALSE;
                }

                DWORD dwHandle;
                DWORD dwDataSize = ::GetFileVersionInfoSize((LPTSTR)lpszModuleName, &dwHandle);
                if ( dwDataSize == 0 )
                    return FALSE;

                m_lpVersionData = new BYTE[dwDataSize];
                if (!::GetFileVersionInfo((LPTSTR)lpszModuleName, dwHandle, dwDataSize,
                    (void**)m_lpVersionData) )
                {
                    Close();
                    return FALSE;
                }

                UINT nQuerySize;
                DWORD* pTransTable;
                if (!::VerQueryValue(m_lpVersionData, _T("\\VarFileInfo\\Translation"),
                    (void **)&pTransTable, &nQuerySize) )
                {
                    Close();
                    return FALSE;
                }

                m_dwLangCharset = MAKELONG(HIWORD(pTransTable[0]), LOWORD(pTransTable[0]));
                return TRUE;
            }

            /**
             * @brief �ر��ļ�
             */
            void Close()
            {
                if (m_lpVersionData)
                {
                    delete[] m_lpVersionData;
                    m_lpVersionData = NULL;
                }
                m_dwLangCharset = 0;
            }
            
            /**
             * @brief ��ȡָ����Ϣ���μ�MSDN��VerQueryValue������
             * @param[in]  lpszValueName   ��ȡ����Ϣ��
             * @param[in]  dwLangCharset   ����ID
             * @return ���ز�ѯ�����ַ�����Ϣ
             */
            CString QueryValue(LPCTSTR lpszValueName, DWORD dwLangCharset = 0)
            {
                if ( m_lpVersionData == NULL )
                    return (CString)_T("");

                if ( dwLangCharset == 0 )
                    dwLangCharset = m_dwLangCharset;

                UINT nQuerySize;
                LPVOID lpData;
                CString strValue, strBlockName;
                strBlockName.Format(_T("\\StringFileInfo\\%08lx\\%s"),
                    dwLangCharset, lpszValueName);
                if ( ::VerQueryValue((void **)m_lpVersionData, strBlockName.GetBuffer(),
                    &lpData, &nQuerySize) )
                    strValue = (LPCTSTR)lpData;
                strBlockName.ReleaseBuffer();
                return strValue;
            }

            CString GetFileDescription() {return QueryValue(_T("FileDescription")); };
            CString GetFileVersion() {return QueryValue(_T("FileVersion")); };
            CString GetInternalName() {return QueryValue(_T("InternalName")); };
            CString GetCompanyName() {return QueryValue(_T("CompanyName")); };
            CString GetLegalCopyright() {return QueryValue(_T("LegalCopyright")); };
            CString GetOriginalFilename() {return QueryValue(_T("OriginalFilename"));};
            CString GetProductName() {return QueryValue(_T("ProductName")); };
            CString GetProductVersion() {return QueryValue(_T("ProductVersion")); };
            
            /**
             * @brief ��ȡVS_FIXEDFILEINFO��Ϣ
             * @param[out]  vsffi   ��Ϣ�ṹ��
             * @return �ɹ�����TRUE,ʧ�ܷ���FALSE
             */
            BOOL GetFixedInfo(VS_FIXEDFILEINFO& vsffi)
            {
                if ( m_lpVersionData == NULL )
                    return FALSE;
                UINT nQuerySize;
                VS_FIXEDFILEINFO* pVsffi;
                if ( ::VerQueryValue((void **)m_lpVersionData, _T("\\"),
                    (void**)&pVsffi, &nQuerySize) )
                {
                    vsffi = *pVsffi;
                    return TRUE;
                }
                return FALSE;
            }
        protected:
            LPBYTE m_lpVersionData;
            DWORD m_dwLangCharset;
        };
    };
}
}
