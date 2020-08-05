// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LIBHTTP_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LIBHTTP_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef WIN32
#ifdef LIBHTTP_EXPORTS
#define LIBHTTP_API __declspec(dllexport)
#else
#define LIBHTTP_API __declspec(dllimport)
#endif
#else
#define LIBHTTP_API
#endif

#include "json/value.h"

#define MAX_POSTID        100                 //post id ����

//ERROR CODE
#define	LIBERROR_OK          0					 //�ɹ�
#define	LIBERROR_OTHER       2001                //�ڲ�����
#define LIBERROR_PARAM       2002                //��������
#define	LIBERROR_RIGIST_URL            2003      //��ע��url
#define LIBERROR_ID_FINISHED           2004      //ID�þ�
#define LIBERROR_ID_NOTFIND            2005      //IDδ�ҵ�
#define LIBERROR_JSON_EXCEPTION        2006      //json�쳣


#ifdef _WIN32 
#ifndef CALLBACK
#define CALLBACK __stdcall
#endif
#else
#define CALLBACK
#endif

/* ���ܣ� POST�첽�ص�
** ������
**       url,url��ַ
**       result,0�ɹ�,����������
**       value, ����json����
**       userData,�û�����
** ����ֵ��
**       ��
*/
typedef void (CALLBACK *ResponseCB)(const char* url, int result, const Json::Value& value, void* userData);

/* ���ܣ� POST�첽�ص�
** ������
**       url,url��ַ
**       result,0�ɹ�,����������
**       json, ����json�ַ���
**       jsonLen, ����json�ַ�������
**       userData,�û�����
** ����ֵ��
**       ��
*/
typedef void (CALLBACK *ResponseCBEx)(const char* url, int result, const char* json, int jsonLen, void* userData);

#ifdef __cplusplus
extern "C"
{
#endif

	/* ���ܣ���ʼ��
	** ������
	**      caPath ��CA֤��·����[IN]
	** ����ֵ��
	**      0,�ɹ���������������
	*/
	LIBHTTP_API int LIBInit(const char* caPath);

	/* ���ܣ�����ʼ��
	** ����ֵ��
	**      0,�ɹ���������������
	*/
	LIBHTTP_API int LIBUnInit();

	/* ���ܣ� ����HTTPͷ
	** ������
	**       url,   url��ַ,   [IN]
	**       header,HTTPͷ�ֶ�,[IN]
	** ����ֵ��
	**       0���ɹ��� ������������
	** ˵���� �ڲ�Ĭ������Content-Type ��apiId ��apiKey��timestamp��sign�������Ҫ���ö�Ӧ�����������ã����ִ�Сд��
	*/
	LIBHTTP_API int LIBSetHeader(const char* url, const Json::Value& header);

	/* ���ܣ� ����HTTPͷ
	** ������
	**       url,   url��ַ,   [IN]
	**       header,HTTPͷ�ֶ�json�ַ���,[IN]
	** ����ֵ��
	**       0���ɹ��� ������������
	** ˵���� �ڲ�Ĭ������Content-Type ��apiId ��apiKey��timestamp��sign�������Ҫ���ö�Ӧ�����������ã����ִ�Сд��
	*/
	LIBHTTP_API int LIBSetHeaderEx(const char* url, const char* header);


	/* ���ܣ� �Ƴ�HTTPͷ����
	** ������ 
	**      url,  url��ַ,   [IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBRemoveHeader(const char* url);

	/* ���ܣ� ע���첽�ص�����
	** ������ 
	**      cb, �ص�����, [IN]
	**      userData, �û����ݣ� [IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBSetResponseCB(ResponseCB cb, void* userData);

	/* ���ܣ� ע���첽�ص�����
	** ������ 
	**      cb, �ص�����, [IN]
	**      userData, �û����ݣ� [IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBSetResponseCBEx(ResponseCBEx cb, void* userData);

	/* ���ܣ� POST�첽
	** ������ 
	**      ipAddr, ip��ַ, [IN]		   https://192.168.1.105:4433/security-server  
	**      apiAddr, �ӿڵ�ַ��[IN]	   /api/v1/face/security/manual-check
	**      body, ��������json���� [IN]
	**      https, �Ƿ�ʹ��https,[IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBPost(const char* ipAddr, const char* apiAddr, const Json::Value& body, bool https);

	/* ���ܣ� POST�첽
	** ������ 
	**      ipAddr, ip��ַ, [IN]		   https://192.168.1.105:4433/security-server  
	**      apiAddr, �ӿڵ�ַ��[IN]	   /api/v1/face/security/manual-check
	**      body, ��������json�ַ����� [IN]
	**      https, �Ƿ�ʹ��https,[IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBPostEx(const char* ipAddr, const char* apiAddr, const char* body, bool https);

	/* ���ܣ� POSTͬ��
	** ������ 
	**      ipAddr, ip��ַ, [IN]		   https://192.168.1.105:4433/security-server  
	**      apiAddr, �ӿڵ�ַ��[IN]	   /api/v1/face/security/manual-check
	**      body, ��������json���� [IN]
	**      response�� ����������json���� [OUT]
	**      https, �Ƿ�ʹ��https,[IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBPostSyn(const char* ipAddr, const char* apiAddr, const Json::Value& body, Json::Value& response, bool https);

	/* ���ܣ� POSTͬ��
	** ������ 
	**		ipAddr, ip��ַ, [IN]		   https://192.168.1.105:4433/security-server  
	**      apiAddr, �ӿڵ�ַ��[IN]	   /api/v1/face/security/manual-check
	**      body, ��������json�ַ����� [IN]
	**      response�� ����������json�ַ����� [OUT]
	**      resLen, ����������json�ַ�������, [OUT]
	**      https, �Ƿ�ʹ��https,[IN]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBPostSynEx(const char* ipAddr, const char* apiAddr, const char* body, char** response, int* resLen, bool https);

	/* ���ܣ� MD5����
	** ������
	**      src��Դ�ַ�����[IN]
	**      dst, ���ܺ��ַ�����[OUT]
	**      dstLen, ���ܺ��ַ������ȣ�[OUT]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBMD5Encode(const char* src, char** dst, int* dstLen);

	/* ���ܣ�Base64����
	** ������
	**      src, Դ���ݣ�[IN]
	**      len, Դ���ݳ���,[IN]
	**      dst, base64�ַ�����[OUT]
	**      dstLen, ���ܺ��ַ������ȣ�[OUT]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBBase64Encode(const char* src, int len, char** dst, int* dstLen);

	/* ���ܣ�Base64����
	** ������
	**      src, base64���ݣ�[IN]
	**      dst, ���������,[OUT]
	**      len, ���ݳ��ȣ�[OUT]
	** ����ֵ��
	**      0���ɹ���������������
	*/
	LIBHTTP_API int LIBBase64Decode(const char* src, char** dst, int* len);


#ifdef __cplusplus
}
#endif