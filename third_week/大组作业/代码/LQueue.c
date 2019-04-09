#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LQueue.h"


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Q->front = Q->rear= (Node*)malloc(sizeof(Node));//����һ��ͷ���
	Q->front->next = NULL;
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description [: ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	ClearLQueue(Q);
	free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->length==0)
	{
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (IsEmptyLQueue(Q))
	{
		printf("����Ϊ��!\n");
		return FALSE;
	}
	e=Q->front->next->data;  //pCurָ����еĵ�һ��Ԫ�أ���ͷ������һ�����
	printf("%s\n",(char *)e);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
	//����һ���½��
	Node* pNewNode = malloc(sizeof(Node));
	pNewNode->data = data;  //������Ԫ�ظ�ֵ������������
	pNewNode->next = NULL;  //������ָ�����ÿ�
	Q->rear->next = pNewNode;   //��ԭ�����еĶ�βָ��ָ���½��
	Q->rear = pNewNode;      //����βָ��ָ���½��
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	Node* pDel = Q->front->next;
	Q->front->next = pDel->next;  //ʹָ��ͷ����ָ��ָ��pDel����һ�����
	//���������ֻ��һ��Ԫ��,�������ÿ�
	if (Q->rear = pDel)
	{
		Q->rear = Q->front;
	}
	free(pDel);   //�ͷ�pDelָ��Ŀռ�
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node* p1,*p2;
	p1=p2=Q->front->next;
	while (p1 != NULL)
	{
		p1=p2->next;
		free(p2);
		p2=p1;
	}
	Q->rear=Q->front;
	Q->length=0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->length==0)
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	printf("����Ϊ\n");
	void *q;
	Node *p=Q->front->next;
	while(p!=NULL)
	{
		q=p->data;
		foo(q);			//�ò���������ӡ��ÿһ��Ԫ��
		p=p->next;
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
	printf("%s ",(char *)q);
}
