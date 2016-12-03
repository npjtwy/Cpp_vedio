#ifndef __CFG_OP_H_
#define __CFG_OP_H_

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

//===============第一套API接口==============//
//客户端初始化
int cltSocketInit(void ** handle /*out*/);

//客户端发报文
int cltSocketSend(void *handle /*in*/, unsigned char *buf/*in*/, int buflen /*in*/);

//客户端收报文
int cltSocketRev(void * handle /*in*/, unsigned char *buf/*in*/, int *buflen);

//客户端释放资源
int cltSocketDestory(void *handle/*in*/);

//===============第一套API接口==============//



#ifdef __cplusplus
}
#endif 
#endif // !__CFG_OP_H_