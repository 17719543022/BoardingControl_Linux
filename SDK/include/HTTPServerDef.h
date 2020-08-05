#ifndef HTTPSERVERDEF_H
#define HTTPSERVERDEF_H

#include <map>
#include <string>

#define HTTPSER_OK	0     //OK
#define HTTPSER_ERR_PARAM  5001//��������

typedef struct _DataInfo
{
	char* szBuf;
	int   nLen;

	_DataInfo():szBuf(nullptr), nLen(0){}
}DataInfo;

//�����¼�����������
class RequstListener
{
public:
	RequstListener(){}
	virtual ~RequstListener(){}

	/* ���ܣ����ڻص�HTTP multipart/form-data����
	** ������uri, ����uri
	**      mapDataInfo��������Json�������ļ�ֵ�ԣ�
	**	    strResponse���������Response;
	** ����ֵ����
	** ˵������
	*/
	virtual void MultipartRequstListen(const std::string& uri, const std::map<std::string, DataInfo>& mapDataInfo, std::string& strResponse) = 0;

	/* ���ܣ����ڻص�HTTP����Content-Type������
	** ������uri, ����uri
	**      strRequstBody��HTTP��������
	**		strResponse���������Response;
	** ����ֵ����
	** ˵��:��
	*/
	virtual void CommonRequstListen(const std::string& uri, const std::string& strRequstBody, std::string& strResponse) = 0;
};

#endif