#include <stdio.h>
#include<stdlib.h>
#include "AQueue.h"
#define MAXQUEUE 10
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;  //把对头和队尾指针同时置0
	Q->length=0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	ClearAQueue(Q);
	free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	e=Q->data[Q->front];
	printf("%s\n",(char *)e);
	return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列已满\n");
		return FALSE;
	}
	Q->data[Q->rear] = data;  //在队尾插入元素data
	Q->rear = Q->rear + 1;     //队尾指针后移一位
	Q->length++;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	Q->front = (Q->front)+1;      //队尾指针后移一位
	Q->length--;
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;
	Q->length=0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(Q->length==0)
	{
		printf("队列为空\n");
		return	FALSE;
	}
	printf("队列为\n");
	void *q;
	int i = Q->front;
	while(i<Q->rear)
	{
		q=Q->data[i];
		foo(q);			//用操作函数打印出每一个元素
		i++;
	}
	printf("\n");
	return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)
{
	printf("%s ",(char *)q);
}
