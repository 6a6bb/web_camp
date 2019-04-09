#include <stdio.h>
#include<stdlib.h>
#include "AQueue.h"
#define MAXQUEUE 10
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;  //�Ѷ�ͷ�Ͷ�βָ��ͬʱ��0
	Q->length=0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	ClearAQueue(Q);
	free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if (Q->length == MAXQUEUE)
	{
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->length==0)
	{
		return TRUE;
	}
	return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	e=Q->data[Q->front];
	printf("%s\n",(char *)e);
	return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("��������\n");
		return FALSE;
	}
	Q->data[Q->rear] = data;  //�ڶ�β����Ԫ��data
	Q->rear = Q->rear + 1;     //��βָ�����һλ
	Q->length++;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	Q->front = (Q->front)+1;      //��βָ�����һλ
	Q->length--;
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;
	Q->length=0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(Q->length==0)
	{
		printf("����Ϊ��\n");
		return	FALSE;
	}
	printf("����Ϊ\n");
	void *q;
	int i = Q->front;
	while(i<Q->rear)
	{
		q=Q->data[i];
		foo(q);			//�ò���������ӡ��ÿһ��Ԫ��
		i++;
	}
	printf("\n");
	return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q)
{
	printf("%s ",(char *)q);
}
