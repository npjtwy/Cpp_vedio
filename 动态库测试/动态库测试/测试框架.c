#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()//2016.9.6   与动态库连接不成功   原因不明
{
	int ret = 0;
	void *handle = NULL;

	char buf_send[128];
	int buf_send_len = 3;

	char buf_rev[128] = { 0 };
	int buf_rev_len;

	strcpy(buf_send, "123");

	ret =  cltSocketInit(&handle /*out*/);

	//客户端发报文
	ret = cltSocketSend(handle /*in*/, buf_send/*in*/, buf_send_len /*in*/);
	printf("buf_send(out):%s\n", buf_send);

	//客户端收报文
	ret = cltSocketRev(handle /*in*/, buf_rev/*in*/, &buf_rev_len);

	printf("buf_Rev(out):%s\n",buf_rev);

	//客户端释放资源
	ret = cltSocketDestory(handle/*in*/);


	system("pause");
}