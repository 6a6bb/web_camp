#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LQueue.h"


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Q->front = Q->rear= (Node*)malloc(sizeof(Node));//创建一个头结点
	Q->front->next = NULL;
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description [: 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	ClearLQueue(Q);
	free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (IsEmptyLQueue(Q))
	{
		printf("队列为空!\n");
		return FALSE;
	}
	e=Q->front->next->data;  //pCur指向队列的第一个元素，即头结点的下一个结点
	printf("%s\n",(char *)e);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	//创建一个新结点
	Node* pNewNode = malloc(sizeof(Node));
	pNewNode->data = data;  //将数据元素赋值给结点的数据域
	pNewNode->next = NULL;  //将结点的指针域置空
	Q->rear->next = pNewNode;   //将原来队列的队尾指针指向新结点
	Q->rear = pNewNode;      //将队尾指针指向新结点
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if (IsEmptyLQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	Node* pDel = Q->front->next;
	Q->front->next = pDel->next;  //使指向头结点的指针指向pDel的下一个结点
	//如果队列中只有一个元素,将队列置空
	if (Q->rear = pDel)
	{
		Q->rear = Q->front;
	}
	free(pDel);   //释放pDel指向的空间
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->length==0)
	{
		printf("队列为空\n");
		return FALSE;
	}
	printf("队列为\n");
	void *q;
	Node *p=Q->front->next;
	while(p!=NULL)
	{
		q=p->data;
		foo(q);			//用操作函数打印出每一个元素
		p=p->next;
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q)
{
	printf("%s ",(char *)q);
}
