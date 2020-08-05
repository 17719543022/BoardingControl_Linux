//////////////////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright(c)2019,�п�Ժ�����о�Ժ���ܰ�ȫ�����о�����  ����Ȩ������
/// All rights reserved.
/// \file IDCardRead_RecogSDK.h
/// \brief ���֤�����ա��۰�ͨ��֤�Ķ��� SDK��װ
/// \detail Ϊ���ݸ������ҵ��Ķ��������������ҵ�SDK���з�װ���γ�ͳһ�ĳ��ڹ��ϲ�Ӧ�õ���
///         Ŀǰ֧�� �а�δ��KR220 ֤��OCRʶ�����֤��ȡ������idr210 ���֤��ȡ.֧���豸������Զ������豸
/// \author plusone_chen
/// \version V1.0(main.min�����汾.�ְ汾��ʽ)
/// \date 2019/12/20
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef IDCardRead_RecogSDK_H
#define IDCardRead_RecogSDK_H

#include "DataStructDefine.h"

#ifdef _WIN32  //Windowsƽ̨��
        //#define DLL_CALL __cdecl  //���庯�����÷�ʽ
        #ifdef __cplusplus  //C++�ļ�
                #define DLL_EXPORT_C_DECL extern "C" __declspec(dllexport)  //��C++����C�ķ�ʽ����dll
                #define DLL_IMPORT_C_DECL extern "C" __declspec(dllimport)  //��C++����C�ķ�ʽ����dll
                #define DLL_EXPORT_DECL extern __declspec(dllexport)  //��C++����C++�ķ�ʽ����dll
                #define DLL_IMPORT_DECL extern __declspec(dllimport)  //��C++����C++�ķ�ʽ����dll
                #define DLL_EXPORT_CLASS_DECL __declspec(dllexport)  //��C++����C++�ķ�ʽ����dll
                #define DLL_IMPORT_CLASS_DECL __declspec(dllimport)  //��C++����C++�ķ�ʽ����dll
        #else
                #define DLL_EXPORT_DECL __declspec(dllexport)  //C���Ե���
                #define DLL_IMPORT_DECL __declspec(dllimport)  //C���Ե���
        #endif
#else  //����ƽ̨  �磺Linux,Arm
        //#define DLL_CALL  //���庯�����÷�ʽ
        #ifdef __cplusplus
                #define DLL_EXPORT_C_DECL extern "C"  //��C++����C�ķ�ʽ����dll
                #define DLL_IMPORT_C_DECL extern "C"  //��C++����C�ķ�ʽ����dll
                #define DLL_EXPORT_DECL extern
                #define DLL_IMPORT_DECL extern
                #define DLL_EXPORT_CLASS_DECL
                #define DLL_IMPORT_CLASS_DECL
        #else
                #define DLL_EXPORT_DECL extern  //C���Ե���
                #define DLL_IMPORT_DECL extern  //C���Ե���
        #endif
#endif


        /// \breif ��ʼ���豸
        ///
        ///��ʼ���豸;�����豸���ģ��豸��ʼ�����������ѡ���豸�����
        ///
        /// \param deviceType[in]-�豸���ͣ�0 �а�δ�� 1 ����
        /// \param deviceParam[in]-�����豸���������ж��������","���� ��
        /// device=0ʱ,deviceParam="0,1",0-��ʾʶ��˿ں��ı��,1-ѭ������ʱ����;
        /// device=1ʱ,deviceParam = "0",0-��ʾ���֤ѭ������ʱ����;
        /// \return  0:�ɹ�  ����:�쳣.
        /// \note
        /// \warning

    DLL_IMPORT_C_DECL int DLL_CALL IDCardSDKInit(DeviceType deviceType,const char* deviceParam);

        /// \breif �������֤�����ص�����
    DLL_IMPORT_C_DECL void DLL_CALL SetIDCardReadCB(IDCardReadCB idCardReadCB,void *userPtr,IDCardReadOnlineCB idCardReadOnlineCB,IDCardReadOfflineCB idCardReadOfflineCB);

        /// \breif ���û���ʶ��ص�����
    DLL_IMPORT_C_DECL void DLL_CALL SetIDCardRecogCB(IDCardRecogCB idCardRecogCB,void *userPtr,IDCardRecogOnlineCB idCardRecogOnlineCB,IDCardRecogOfflineCB idCardRecogOfflineCB);

        /// \breif �ͷŶ������֤�Ķ����ڴ�
    DLL_IMPORT_C_DECL void DLL_CALL IDCardSDKRelease();

#endif










