#ifndef HTTPSERVEREXP_H
#define HTTPSERVEREXP_H

#include "HTTPServerDef.h"

#ifdef WIN32

#ifdef HTTPSERVER_EXPORTS
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

#else
#define DLLAPI
#endif


#ifdef __cplusplus
extern "C"{
#endif

	/* ���ܣ�����HTTP����
	** ������nPort��[IN]������˿�
	** pListener��[IN], �ص���������
	** ����ֵ��
	**       0���ɹ��� ������������
	** ˵������
	*/
	DLLAPI int StartHTTPServer(int nPort, RequstListener* pListener);

	/* ���ܣ�ֹͣHTTP����
	** ��������
	** ����ֵ��
	**		0���ɹ��� ������������
	** ˵������
	*/
	DLLAPI int StopHTTPServer();

#ifdef __cplusplus
}
#endif

#endif