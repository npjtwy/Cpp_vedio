#ifndef __CFG_OP_H_
#define __CFG_OP_H_

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

//===============��һ��API�ӿ�==============//
//�ͻ��˳�ʼ��
int cltSocketInit(void ** handle /*out*/);

//�ͻ��˷�����
int cltSocketSend(void *handle /*in*/, unsigned char *buf/*in*/, int buflen /*in*/);

//�ͻ����ձ���
int cltSocketRev(void * handle /*in*/, unsigned char *buf/*in*/, int *buflen);

//�ͻ����ͷ���Դ
int cltSocketDestory(void *handle/*in*/);

//===============��һ��API�ӿ�==============//



#ifdef __cplusplus
}
#endif 
#endif // !__CFG_OP_H_