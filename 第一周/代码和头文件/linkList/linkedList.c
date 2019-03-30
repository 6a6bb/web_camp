#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	int n=0;
	LinkedList p1,p2;
	*L=p1=p2=malloc(sizeof(LNode));
	while(scanf("%d",&p1->data)==1)
	{
		n=1;
		p2->next=p1;
		p2=p1;
		p1=malloc(sizeof(LNode));
	}
	p2->next=NULL;
	if(n==1) return SUCCESS;
	else return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p1,p2;
	p1=p2=*L;
	while(p2)
	{
		p1=p2->next;
		free(p2);
		p2=p1;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	q->next=p->next;
	p->next=q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	e=&(p->next->data);
	if(p->next->next==NULL)					//当要删的节点为尾节点时
	{
		p->next=NULL;
	}
	else							//正常情况下
	{
		p->next=p->next->next;
	}
	printf("被删节点储存的值为%d\n",*e);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L) {
	if(L) ;
	else printf("链表不存在,请先初始化哦\n");
	while(L)
	{
                printf("%d ",L->data);
                L=L->next;
	}
	printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	while(L!=NULL)
	{
		if(L->data==e) return SUCCESS;
		L=L->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p,q,head,r;
	head=*L;
	if(NULL==head|| NULL==head->next) return SUCCESS;    //少于两个节点没有反转的必要。
	p = head;
	q = head->next;
	head->next = NULL; //旧的头指针是新的尾指针，next需要指向NULL
	while(q)
	{
		r = q->next; //先保留下一个step要处理的指针
		q->next = p; //然后p q交替工作进行反向
		p = q;
		q = r;
	}
	*L=p; // 最后q必然指向NULL，所以返回了p作为新的头指针
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
 //使用快慢指针,若快慢指针会相遇,则存在环,若快指针直接到尽头,则不存在环
Status IsLoopList(LinkedList L) {
	LinkedList fast,slow;
	fast=slow=L;
	while(1)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow) return SUCCESS;
		else if(fast==NULL) return ERROR;
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p,q;

	//return head;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
 //使用快慢指针,当快指针为空时，慢指针刚好指向中间
LNode* FindMidNode(LinkedList *L) {
	LinkedList fast,slow;
	fast = slow = *L;
	while(fast && fast->next )
	{
		fast = fast->next ->next ;
		slow = slow->next;
	}
	return slow;
}

