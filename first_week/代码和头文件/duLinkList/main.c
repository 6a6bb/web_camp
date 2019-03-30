#include "duLinkedList.h"
#include "duLinkedList.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int t=0;			//�����Ƿ���ڵı��
int y,i;
DuLNode q;
DuLNode *p;
ElemType *e;
void show()
{
	system("CLS");
	printf("************************************************************************************************************************\n");
	printf("*                                               ˫����ADT                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                       1 ����ͷ�ڵ��ʼ���������б�                                                   *\n");
	printf("*                                       2 ���������б�                                                                 *\n");
	printf("*                                       3 �ڽڵ�p֮ǰ����ڵ�q                                                         *\n");
	printf("*                                       4 �ڽڵ�p�����ڵ�q                                                           *\n");
	printf("*                                       5 ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e                                     *\n");
	printf("*                                       6 ���������б�                                                                 *\n");
	printf("************************************************************************************************************************\n");
	printf("��ѡ����,����ĸ�˳�:");
}

void main()
{
	DuLinkedList *L;
	*L=malloc(sizeof(DuLNode));
	int x,n=ERROR;								//û���в���ʱ,���Ϊʧ�ܣ��Ա��жϺ���Ĳ����Ƿ�ɹ�����
	show();
	while(scanf("%d",&x)==1)
	{
		switch(x)
		{
		case 1: printf("����������,�ÿո����,����ĸΪ������־\n");
			n=InitList_DuL(L);
			if(n==SUCCESS) printf("��ʼ������ɹ�\n"),t=1;		//����ɹ���ʼ��
			else printf("��ʼ������ʧ��\n");
			break;
		case 2: DestroyList_DuL(L);
			printf("ɾ������ɹ�\n");
			t=0;							//��������,tΪ1
			break;
		case 3: printf("����ڵ�q�����ֵ\n");
			scanf("%d",&q.data);
			printf("����������뵽�ڼ����ڵ�ǰ����\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y-1;i++)  p=p->next;				//�ҵ�pǰһ���ڵ�ĵ�ַ
			n=InsertBeforeList_DuL(p,&q);
			if(n==SUCCESS) printf("����ɹ�\n");
			else printf("����ʧ��\n");
			break;
		case 4: printf("����ڵ�q�����ֵ\n");
			scanf("%d",&q.data);
			printf("����������뵽�ڼ����ڵ������\n");
			scanf("%d",&y);
			p=*L;
			for(i=0;i<y;i++)  p=p->next;				//�ҵ�p��ַ
			n=InsertAfterList_DuL(p,&q);
			if(n==SUCCESS) printf("����ɹ�\n");
			else printf("����ʧ��\n");
			break;
		case 5: printf("��������ɾȥ�ڼ����ڵ����ĵ�һ���ڵ�\n");
			scanf("%d",&y);
			p=(*L)->next;
			for(i=0;i<y-1;i++)  p=p->next;
			n=DeleteList_DuL(p,e);
			if(n==SUCCESS) printf("ɾ���ɹ�\n");
			else printf("ɾ��ʧ��\n");
			break;
		case 6: if(t==1) TraverseList_DuL(*L);			//�������ʱ����
			else printf("��������,���ȳ�ʼ��Ŷ\n");	//�������������û����г�ʼ��
			break;
		}
		getchar();
		system("pause");					//��ֹ��������һ������
		show();
	}
}
