#include "linkedList.h"
#include "linkedList.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int t=0;			//链表是否存在的标记
int y,i;
LinkedList m=NULL;
ElemType *e;
LNode *p;
LNode q;
void show()
{
	system("CLS");		//清屏
	printf("************************************************************************************************************************\n");
	printf("*                                               单链表ADT                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1 初始化链表                                                             *\n");
	printf("*                                             2 删除链表                                                               *\n");
	printf("*                                             3 插入节点                                                               *\n");
	printf("*                                             4 删除节点                                                               *\n");
	printf("*                                             5 遍历链表                                                               *\n");
	printf("*                                             6 查找数值                                                               *\n");
	printf("*                                             7 反转链表                                                               *\n");
	printf("*                                             8 判断链表是否有环                                                       *\n");
	printf("*                                             9 倒转链表中的偶数节点(不会做)                                           *\n");
	printf("*                                             10 在链接列表中查找中间节点                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,按字母退出:");
}

void main()
{
	LinkedList *L;
	int x,n=ERROR;						//没进行操作时,标记为失败，以便判断后面的操作是否成功进行
	show();
	while(scanf("%d",&x)==1)
	{
		switch(x)
		{
		case 1: printf("请输入链表,用空格隔开,以字母为结束标志\n");
			n=InitList(L);
			if(n==SUCCESS) printf("初始化链表成功\n"),t=1;	//链表成功初始化
			else printf("初始化链表失败\n");
			break;
		case 2: DestroyList(L);
			printf("删除链表成功\n");
			t=0;						//链表不存在,t为1
			break;
		case 3: printf("输入节点q储存的值\n");
			scanf("%d",&q.data);
			printf("请问你想插入到第几个节点后面呢\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y-1;i++)  p=p->next;
			n=InsertList(p,&q);
			if(n==SUCCESS) printf("插入成功\n");
			else printf("插入失败\n");
			break;
		case 4:	printf("请问你想删去第几个节点后面的第一个节点\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y-1;i++)  p=p->next;
			n=DeleteList(p,e);
			if(n==SUCCESS) printf("删除成功\n");
			else printf("删除失败\n");
			break;
		case 5: if(t==1)TraverseList(*L);				//链表存在时遍历
			else printf("链表不存在,请先初始化哦\n");		//不存在则提醒用户进行初始化
			break;
		case 6:	printf("请输入要查的数:");
			scanf("%d",&n);
			n=SearchList(*L,n);
			if(n==SUCCESS) printf("该数存在\n");
			else printf("该数不存在\n");
			break;
		case 7: n=ReverseList(L);
			if(n==SUCCESS) printf("反转链表成功\n");
			else printf("反转链表失败\n");
			break;
		case 8: if(t==1)
			{
				n=IsLoopList(*L);
				if(n==SUCCESS) printf("存在环\n");
				else printf("不存在环\n");
			}
			else printf("链表不存在,请先初始化哦\n");		//不存在则提醒用户进行初始化
			break;
		case 9: //ReverseEvenList
			break;
		case 10:m=FindMidNode(L);
			printf("中间节点存储的值为%d\n",*m);
			break;
		}
		getchar();
		system("pause");						//防止清屏后结果一闪而过
		show();
	}
}
