#include "duLinkedList.h"
#include "duLinkedList.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int t=0;			//链表是否存在的标记
int y,i;
DuLNode q;
DuLNode *p;
ElemType *e;
void show()
{
	system("CLS");
	printf("************************************************************************************************************************\n");
	printf("*                                               双链表ADT                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                       1 仅用头节点初始化空链接列表                                                   *\n");
	printf("*                                       2 销毁链接列表                                                                 *\n");
	printf("*                                       3 在节点p之前插入节点q                                                         *\n");
	printf("*                                       4 在节点p后插入节点q                                                           *\n");
	printf("*                                       5 删除节点p之后的第一个节点，并将其值赋给e                                     *\n");
	printf("*                                       6 遍历链接列表                                                                 *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,按字母退出:");
}

void main()
{
	DuLinkedList *L;
	*L=malloc(sizeof(DuLNode));
	int x,n=ERROR;								//没进行操作时,标记为失败，以便判断后面的操作是否成功进行
	show();
	while(scanf("%d",&x)==1)
	{
		switch(x)
		{
		case 1: printf("请输入链表,用空格隔开,以字母为结束标志\n");
			n=InitList_DuL(L);
			if(n==SUCCESS) printf("初始化链表成功\n"),t=1;		//链表成功初始化
			else printf("初始化链表失败\n");
			break;
		case 2: DestroyList_DuL(L);
			printf("删除链表成功\n");
			t=0;							//链表不存在,t为1
			break;
		case 3: printf("输入节点q储存的值\n");
			scanf("%d",&q.data);
			printf("请问你想插入到第几个节点前面呢\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y-1;i++)  p=p->next;				//找到p前一个节点的地址
			n=InsertBeforeList_DuL(p,&q);
			if(n==SUCCESS) printf("插入成功\n");
			else printf("插入失败\n");
			break;
		case 4: printf("输入节点q储存的值\n");
			scanf("%d",&q.data);
			printf("请问你想插入到第几个节点后面呢\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y;i++)  p=p->next;				//找到p地址
			n=InsertAfterList_DuL(p,&q);
			if(n==SUCCESS) printf("插入成功\n");
			else printf("插入失败\n");
			break;
		case 5: printf("请问你想删去第几个节点后面的第一个节点\n");
			scanf("%d",&y);
			p=(*L)->next;
			for(i=0;i<y-1;i++)  p=p->next;
			n=DeleteList_DuL(p,e);
			if(n==SUCCESS) printf("删除成功\n");
			else printf("删除失败\n");
			break;
		case 6: if(t==1) TraverseList_DuL(*L);			//链表存在时遍历
			else printf("链表不存在,请先初始化哦\n");	//不存在则提醒用户进行初始化
			break;
		}
		getchar();
		system("pause");					//防止清屏后结果一闪而过
		show();
	}
}
