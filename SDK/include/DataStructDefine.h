//////////////////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE  
/// Copyright(c)2019,�п�Ժ�����о�Ժ���ܰ�ȫ�����о�����  ����Ȩ������  
/// All rights reserved.  
/// \file DataStructDefine.h 
/// \brief ���ݽṹ
/// \detail Ϊ�˵��ø��ӷ��㣬��ƻص����������Ķ������Ϸ�֤�����Զ����ûص��������ض�Ӧ֤���Ľṹ������
/// \author plusone_chen 
/// \version V1.0(main.min�����汾.�ְ汾��ʽ)  
/// \date 2019/12/27
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DataStructDefine_H
#define DataStructDefine_H

#ifdef _WIN32  //Windowsƽ̨��
	#define DLL_CALL __cdecl  //���庯�����÷�ʽ
#else
	#define DLL_CALL
#endif

	/// \breif �豸����  0 �а�δ���豸  1 �����豸
	typedef enum DeviceType
	{
		ChinaSafe = 0,  //�а�δ��
		JingLun = 1     //����
	}DeviceType;

	/// \breif ���֤��Ϣ
	typedef struct IDCardReadInfos
	{
		int idType;///<breif ���֤���� 0-�������֤ 1-��������֤ 2-�۰�̨��ס֤
		char *name;///< brief ����
		char *gender;///< brief �Ա� 
		char *folk;///< brief ����
		char *birthDay;///< brief ��������
		char *code;///< brief ���֤��
		char *address;///< brief ��ַ
		char *agency;///< brief ��֤����
		char *expireStart;///< brief ��Ч����
		char *expireEnd;///< brief ��Ч��ֹ

		char *eName;///<breif Ӣ������
		char *prCode;///<breif ���þ�ס����
		char *nation;///<breif ���������ڵ�������
		char *idVersion;///<breif ֤���汾��
		char *agencyCode;///<breif ������ش���
	
		IDCardReadInfos()  //���ݳ�ʼ��
		{
			idType = 0;
			name = 0;
			eName = 0;
			gender = 0;
			folk = 0;
			birthDay = 0;
			code = 0;
			address = 0;
			agency = 0;
			expireStart = 0;
			expireEnd = 0;
			prCode = 0;
			nation = 0;
			idVersion = 0;
			agencyCode = 0;

		}
	}IDCardReadInfos;

	///<breif �����۰�ͨ��֤ 2014��  ����ţ�22
	typedef struct HK_MPassPermitInfos
	{
		char *retainedFiele;///<breif �����ֶ�
		char *code; ///<breif ֤������
		char *name;///<breif ��������
		char *eName;///<breif Ӣ������
		char *birthDay;///<breif ��������
		char *gender;///<breif �Ա�
		char *expireDate;///< brief ��Ч����
		char *issuePlace;///<breif ǩ���ص�
		char *MRZ1;///<breif ��һ��MRZ
		char *MRZ2;///<breif �ڶ���MRZ
		char *MRZ3;///<breif ������MRZ
		char *issueDate;///<breif ǩ������
		char *expireEnd;///<breif ��Ч����
		HK_MPassPermitInfos()
		{
			retainedFiele = 0;///<breif �����ֶ�
			code = 0; ///<breif ֤������
			name = 0;///<breif ��������
			eName = 0;///<breif Ӣ������
			birthDay = 0;///<breif ��������
			gender = 0;///<breif �Ա�
			expireDate = 0;///< brief ��Ч����
			issuePlace = 0;///<breif ǩ���ص�
			MRZ1 = 0;///<breif ��һ��MRZ
			MRZ2 = 0;///<breif �ڶ���MRZ
			MRZ3 = 0;///<breif ������MRZ
			issueDate = 0;///<breif ǩ������
			expireEnd = 0;///<breif ��Ч����
		}

	}HK_MPassPermitInfos;

	///<breif ����̨��ͨ��֤ 2017 ��-��Ƭҳ ����ţ�29
	typedef struct TaiWanPassPermitInfos
	{
		char *retainedFiele;///<breif �����ֶ�
		char *code; ///<breif ֤������
		char *name;///<breif ��������
		char *eName;///<breif Ӣ������
		char *birthDay;///<breif ��������
		char *gender;///<breif �Ա�
		char *expireDate;///< brief ��Ч����
		char *issuePlace;///<breif ǩ���ص�
		char *MRZ1;///<breif ��һ��MRZ
		char *MRZ2;///<breif �ڶ���MRZ
		char *MRZ3;///<breif ������MRZ
		char *agency;///< brief ��֤����
		TaiWanPassPermitInfos()
		{
			retainedFiele = 0;///<breif �����ֶ�
			code = 0; ///<breif ֤������
			name = 0;///<breif ��������
			eName = 0;///<breif Ӣ������
			birthDay = 0;///<breif ��������
			gender = 0;///<breif �Ա�
			expireDate = 0;///< brief ��Ч����
			issuePlace = 0;///<breif ǩ���ص�
			MRZ1 = 0;///<breif ��һ��MRZ
			MRZ2 = 0;///<breif �ڶ���MRZ
			MRZ3 = 0;///<breif ������MRZ
			agency = 0;///< brief ��֤����
		}
	}TanWanPassPermitInfos;

	///<breif �۰ľ��������ڵ�ͨ ��֤-��Ƭҳ  ����ţ�14
	typedef struct HK_MToMotherLandPassPermitInfos
	{
		char *retainedFiele;///<breif �����ֶ�
		char *code; ///<breif ֤������
		char *name;///<breif ��������
		char *eName;///<breif Ӣ������
		char *gender;///<breif �Ա�
		char *birthDay;///<breif ��������
		char *expireEnd;///<breif ��Ч����
		char *eName_F; ///<breif Ӣ����
		char *eName_S;///<breif Ӣ����
		char *HK_Mcode;///<breif �۰�֤������
		char *issueDate;///<breif ǩ������
		char *expireDate;///< brief ��Ч����
		char *agency;///< brief ��֤����
		char *changeCardNum;///<breif ��֤����
		char *otherName;///<breif ��������

		HK_MToMotherLandPassPermitInfos()
		{
			retainedFiele = 0;///<breif �����ֶ�
			code = 0; ///<breif ֤������
			name = 0;///<breif ��������
			eName = 0;///<breif Ӣ������
			gender = 0;///<breif �Ա�
			birthDay = 0;///<breif ��������
			expireEnd = 0;///<breif ��Ч����
			eName_F = 0; ///<breif Ӣ����
			eName_S = 0;///<breif Ӣ����
			HK_Mcode = 0;///<breif �۰�֤������
			issueDate = 0;///<breif ǩ������
			expireDate = 0;///< brief ��Ч����
			agency = 0;///< brief ��֤����
			changeCardNum = 0;///<breif ��֤����
			otherName = 0;///<breif ��������
		}
	}HK_MToMotherLandPassPermitInfos;

	///<breif ̨�����������½ͨ ��֤ 2015 ��-��Ƭҳ  ����ţ�25
	typedef struct TaiWanToMotherLandPassPermitInfos
	{
		char *retainedFiele;///<breif �����ֶ�
		char *name;///<breif ��������
		char *eName;///<breif Ӣ������
		char *birthDay;///<breif ��������
		char *gender;///<breif �Ա�
		char *expireDate;///< brief ��Ч����
		char *issuePlace;///<breif ǩ���ص�
		char *code; ///<breif ֤������
		char *issueNum;///<breif ǩ������
		char *agency;///< brief ��֤����

		TaiWanToMotherLandPassPermitInfos()
		{
			retainedFiele = 0;///<breif �����ֶ�
			name = 0;///<breif ��������
			eName = 0;///<breif Ӣ������
			birthDay = 0;///<breif ��������
			gender = 0;///<breif �Ա�
			expireDate = 0;///< brief ��Ч����
			issuePlace = 0;///<breif ǩ���ص�
			code = 0; ///<breif ֤������
			issueNum = 0;///<breif ǩ������
			agency = 0;///< brief ��֤����
		}
	}TaiWanToMotherLandPassPermitInfos;



	///<breif ������Ϣ  ����ţ�13
	typedef struct PassPortInfos
	{
		char *passPortType;///<breif ��������  PO:�л����񹲺͹�����
		char *code; ///<breif ���պ��� MRZʶ��
		char *nationName;///<breif ��������
		char *eName;///<breif Ӣ������
		char *gender;///<breif �Ա�
		char *birthDay;///<breif ��������
		char *expireEnd;///< brief ��Ч��ֹ
		char *countryCode;///<breif ǩ��������
		char *eName_F;///<breif Ӣ����
		char *eName_S;///<breif Ӣ����
		char *MRZ1;///<breif ��һ��MRZ
		char *MRZ2;///<breif �ڶ���MRZ
		char *nationalityCode;///<breif ��������
		char *codeOCR;///<breif ���պ���
		char *birthAddress;//<breif �����ص� �������й��� �գ�
		char *issuePlace;///<breif ǩ���ص�
		char *issueDate;///<breif ǩ������
		char *rfidMRZ;///<breif RFID MRZ
		char *ocrMRZ;///<breif OCR MRZ
		char *birthAddressPinYin;///<breif �����ص�ƴ��
		char *issuePlacePinYin;///<breif ǩ���ص�ƴ��
		char *idcardCode;///<breif ���֤���� ��������̨�弰��������
		char *nationNamePinYinOCR;///<breif ��������ƴ�� OCR
		char *genderOCR;///<breif �Ա�OCR
		char *nationalityCodeOCR;///<breif ��֤�˹�������OCR
		char *idcardCodeOCR;///<breif ���֤����OCR
		char *birthDayOCR;///<breif ��������OCR
		char *expireEndOCR;///< brief ��Ч��ֹOCR
		char *countryCodeOCR;///<breif ǩ������OCR
		char *nation_F;///<breif ������
		char *nation_S;///<breif ������
		PassPortInfos() //���ݳ�ʼ��
		{
			passPortType = 0;///<breif ��������  PO:�л����񹲺͹�����
			code = 0; ///<breif ���պ��� MRZʶ��
			nationName = 0;///<breif ��������
			eName = 0;///<breif Ӣ������
			gender = 0;///<breif �Ա�
			birthDay = 0;///<breif ��������
			expireEnd = 0;///< brief ��Ч��ֹ
			countryCode = 0;///<breif ǩ��������
			eName_F = 0;///<breif Ӣ����
			eName_S = 0;///<breif Ӣ����
			MRZ1 = 0;///<breif ��һ��MRZ
			MRZ2 = 0;///<breif �ڶ���MRZ
			nationalityCode = 0;///<breif ��������
			codeOCR = 0;///<breif ���պ���
			birthAddress = 0;//<breif �����ص� �������й��� �գ�
			issuePlace = 0;///<breif ǩ���ص�
			issueDate = 0;///<breif ǩ������
			rfidMRZ = 0;///<breif RFID MRZ
			ocrMRZ = 0;///<breif OCR MRZ
			birthAddressPinYin = 0;///<breif �����ص�ƴ��
			issuePlacePinYin = 0;///<breif ǩ���ص�ƴ��
			idcardCode = 0;///<breif ���֤���� ��������̨�弰��������
			nationNamePinYinOCR = 0;///<breif ��������ƴ�� OCR
			genderOCR = 0;///<breif �Ա�OCR
			nationalityCodeOCR = 0;///<breif ��֤�˹�������OCR
			idcardCodeOCR = 0;///<breif ���֤����OCR
			birthDayOCR = 0;///<breif ��������OCR
			expireEndOCR = 0;///< brief ��Ч��ֹOCR
			countryCodeOCR = 0;///<breif ǩ������OCR
			nation_F = 0;///<breif ������
			nation_S = 0;///<breif ������
		}

	}PassPortInfos;

	/// \breif ��������Ӧ��ص�����
	///
	/// ��������Ӧ�ص������øûص����������֤��������ȡ���ݺ��Զ���Ӧ������֤����Ϣ
	///
	/// \param idCardReadInfos[out]-���֤��Ϣ
	/// \param userData[out]-�û���Ϣ
	typedef void (DLL_CALL *IDCardReadCB)(IDCardReadInfos *idCardReadInfos ,void *userData);

	/// \brief �����������¼�
	/// \param userData[out]-�û���Ϣ
	typedef void (DLL_CALL *IDCardReadOnlineCB)(void *userData);
	/// \brief �����������¼�
	/// \param userData[out]-�û���Ϣ
	typedef void (DLL_CALL *IDCardReadOfflineCB)(void *userData);


	/// \breif ����ʶ���豸��Ӧ��ص�����
	///
	/// ����ʶ���豸��Ӧ�����øûص���������ʶ���豸�Զ���Ӧ������֤����Ϣ
	///
	/// \param passportInfos[out]-������Ϣ����ʶ��Ĳ��Ǹ����ͷ���NULL
	/// \param hk_mPassPermitInfos[out]-�����۰�֤����Ϣ����ʶ��Ĳ��Ǹ����ͷ���NULL
	/// \param taiwanPassPermitInfos[out]-����̨��֤����Ϣ����ʶ��Ĳ��Ǹ����ͷ���NULL
	/// \param hk_mToMotherLandPassPermitInfos[out]-�۰�������½֤����Ϣ����ʶ��Ĳ��Ǹ����ͷ���NULL
	/// \param TaiWanToMotherLandPassPermitInfos[out]-̨��������½֤����Ϣ����ʶ��Ĳ��Ǹ����ͷ���NULL
	/// \param userData[out]-�û���Ϣ
	typedef void (DLL_CALL *IDCardRecogCB)(PassPortInfos *passportInfos,
                                               HK_MPassPermitInfos *hk_mPassPermitInfos,
                                               TaiWanPassPermitInfos *taiwanPassPermitInfos,
                                               HK_MToMotherLandPassPermitInfos *hk_mToMotherLandPassPermitInfos,
                                               TaiWanToMotherLandPassPermitInfos *TaiWanToMotherLandPassPermitInfos,
                                               void *userData);
	/// \brief �����������¼�
	/// \param userData[out]-�û���Ϣ
	typedef void (DLL_CALL *IDCardRecogOnlineCB)(void *userData);
	/// \brief �����������¼�
	/// \param userData[out]-�û���Ϣ
	typedef void (DLL_CALL *IDCardRecogOfflineCB)(void *userData);

#endif
