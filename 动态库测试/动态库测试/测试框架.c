#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()//2016.9.6   �붯̬�����Ӳ��ɹ�   ԭ����
{
	int ret = 0;
	void *handle = NULL;

	char buf_send[128];
	int buf_send_len = 3;

	char buf_rev[128] = { 0 };
	int buf_rev_len;

	strcpy(buf_send, "123");

	ret =  cltSocketInit(&handle /*out*/);

	//�ͻ��˷�����
	ret = cltSocketSend(handle /*in*/, buf_send/*in*/, buf_send_len /*in*/);
	printf("buf_send(out):%s\n", buf_send);

	//�ͻ����ձ���
	ret = cltSocketRev(handle /*in*/, buf_rev/*in*/, &buf_rev_len);

	printf("buf_Rev(out):%s\n",buf_rev);

	//�ͻ����ͷ���Դ
	ret = cltSocketDestory(handle/*in*/);


	system("pause");
}