#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLinkedList p,r;
	p=*L;
	int x;
	while(scanf("%d",&x)==1)
	{
		r=malloc(sizeof(DuLNode));		//r开辟新节点
		p->next=r;
		r->data=x;				//存入数据
		r->prior=p;
		r->next=NULL;				//使r指向空
		p=r;
	}
	return SUCCESS;
}
/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p1,p2;
	p1=p2=(*L)->next;
	free(L);
	while(p2)
	{
		p1=p2->next;
		p2->prior=NULL;					//先去除向前的指向
		free(p2);					//再去除向后的指向
		p2=p1;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p->next==NULL)
	{
		p->next=q;
		q->prior=p;
		q->next=NULL;
	}
	else
	{
		q->next=p->next;
		p->next->prior=q;
		p->next=q;
		q->prior=p;
	}
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p->next==NULL)
	{
		p->next=q;
		q->prior=p;
		q->next=NULL;
	}
	else
	{
		q->next=p->next;
		p->next->prior=q;
		p->next=q;
		q->prior=p;
	}
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	e=&(p->next->data);
	DuLNode *q;
	if(p->next->next==NULL)					//当要删的节点为尾节点时
	{
		p->next->prior=NULL;
		p->next=NULL;
	}
	else							//正常情况下
	{
		p->next->prior=NULL;
		p->next->next->prior=p;
		q=p->next->next;				//用q存储p后第二格节点的地址,以便去除p->next的指向
		p->next->next=NULL;
		p->next=q;

	}
	printf("被删节点储存的值为%d\n",*e);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L ) {
	DuLinkedList p=L->next;
	if (p==NULL)							//判断链表是否存在
	{
		printf("链表为空\n");
	}
	else
	{
		while(p)						//逐个打印
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
}

