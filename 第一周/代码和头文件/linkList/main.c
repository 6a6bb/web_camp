#include "linkedList.h"
#include "linkedList.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int t=0;			//�����Ƿ���ڵı��
int y,i;
LinkedList m=NULL;
ElemType *e;
LNode *p;
LNode q;
void show()
{
	system("CLS");		//����
	printf("************************************************************************************************************************\n");
	printf("*                                               ������ADT                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1 ��ʼ������                                                             *\n");
	printf("*                                             2 ɾ������                                                               *\n");
	printf("*                                             3 ����ڵ�                                                               *\n");
	printf("*                                             4 ɾ���ڵ�                                                               *\n");
	printf("*                                             5 ��������                                                               *\n");
	printf("*                                             6 ������ֵ                                                               *\n");
	printf("*                                             7 ��ת����                                                               *\n");
	printf("*                                             8 �ж������Ƿ��л�                                                       *\n");
	printf("*                                             9 ��ת�����е�ż���ڵ�(������)                                           *\n");
	printf("*                                             10 �������б��в����м�ڵ�                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("��ѡ����,����ĸ�˳�:");
}

void main()
{
	LinkedList *L;
	int x,n=ERROR;						//û���в���ʱ,���Ϊʧ�ܣ��Ա��жϺ���Ĳ����Ƿ�ɹ�����
	show();
	while(scanf("%d",&x)==1)
	{
		switch(x)
		{
		case 1: printf("����������,�ÿո����,����ĸΪ������־\n");
			n=InitList(L);
			if(n==SUCCESS) printf("��ʼ������ɹ�\n"),t=1;	//����ɹ���ʼ��
			else printf("��ʼ������ʧ��\n");
			break;
		case 2: DestroyList(L);
			printf("ɾ������ɹ�\n");
			t=0;						//��������,tΪ1
			break;
		case 3: printf("����ڵ�q�����ֵ\n");
			scanf("%d",&q.data);
			printf("����������뵽�ڼ����ڵ������\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y-1;i++)  p=p->next;
			n=InsertList(p,&q);
			if(n==SUCCESS) printf("����ɹ�\n");
			else printf("����ʧ��\n");
			break;
		case 4:	printf("��������ɾȥ�ڼ����ڵ����ĵ�һ���ڵ�\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y-1;i++)  p=p->next;
			n=DeleteList(p,e);
			if(n==SUCCESS) printf("ɾ���ɹ�\n");
			else printf("ɾ��ʧ��\n");
			break;
		case 5: if(t==1)TraverseList(*L);				//�������ʱ����
			else printf("��������,���ȳ�ʼ��Ŷ\n");		//�������������û����г�ʼ��
			break;
		case 6:	printf("������Ҫ�����:");
			scanf("%d",&n);
			n=SearchList(*L,n);
			if(n==SUCCESS) printf("��������\n");
			else printf("����������\n");
			break;
		case 7: n=ReverseList(L);
			if(n==SUCCESS) printf("��ת����ɹ�\n");
			else printf("��ת����ʧ��\n");
			break;
		case 8: if(t==1)
			{
				n=IsLoopList(*L);
				if(n==SUCCESS) printf("���ڻ�\n");
				else printf("�����ڻ�\n");
			}
			else printf("��������,���ȳ�ʼ��Ŷ\n");		//�������������û����г�ʼ��
			break;
		case 9: //ReverseEvenList
			break;
		case 10:m=FindMidNode(L);
			printf("�м�ڵ�洢��ֵΪ%d\n",*m);
			break;
		}
		getchar();
		system("pause");						//��ֹ��������һ������
		show();
	}
}
