#include "SqStack.h"
#include "SqStack.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void show()
{
	system("CLS");		//����
	printf("************************************************************************************************************************\n");
	printf("*                                              ˳��ջ(���������)                                                      *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1 ��ʼ��ջ                                                               *\n");
	printf("*                                             2 �ж�ջ�Ƿ�Ϊ��                                                         *\n");
	printf("*                                             3 �õ�ջ��Ԫ��                                                           *\n");
	printf("*                                             4 ���ջ                                                                 *\n");
	printf("*                                             5 ����ջ                                                                 *\n");
	printf("*                                             6 ���ջ����                                                             *\n");
	printf("*                                             7 ��ջ                                                                   *\n");
	printf("*                                             8 ��ջ                                                                   *\n");
	printf("************************************************************************************************************************\n");
	printf("��ѡ����,����ĸ�˳�:");

}
int main()
{
	int x,n=ERROR,length,q;
	int t=0;						//�ж�ջ�Ƿ��ѳ�ʼ��,�տ�ʼû�г�ʼ��,t��Ϊ0
	ElemType *e;
	e=malloc(sizeof(int));
	show();
	SqStack *s=malloc(sizeof(SqStack));
	while(scanf("%d",&x)==1)				//�ж�������Ƿ�Ϊ����
	{
		if(t==0&&x!=1) 					//�����û��ȳ�ʼ��ջ
		{
			printf("���ȳ�ʼ��ջ��\n");
			printf("������ѡ����:");
			continue;
		}
		switch(x)
		{
		case 1: printf("������ջ�Ĵ�С");		//��ʼ��ջ
			scanf("%d",&q);
			n=initStack(s,q);
			if(n==SUCCESS)  printf("��ʼ��ջ�ɹ�\n");
			t=1;
			break;
		case 2:	n=isEmptyStack(s);			//�ж�ջ�Ƿ�Ϊ��
			if(n==SUCCESS)  printf("ջΪ��\n");
			else		printf("ջ��Ϊ��\n");
			break;
		case 3:	n=getTopStack(s,e);			//�õ�ջ��Ԫ��
			if(n==SUCCESS)  printf("ջ��Ԫ��Ϊ%d\n",*e);
			break;
		case 4: n=clearStack(s);			 //���ջ
			if(n==SUCCESS)  printf("��ճɹ�\n");
			break;
		case 5: n=destroyStack(s);			//����ջ
			if(n==SUCCESS)
			{
				printf("���ٳɹ�,�������\n");
				return 0;
			}
			else	printf("����ʧ��\n");
			break;
		case 6: printf("����ó���Ϊ\n");		//���ջ����
			scanf("%d",&length);
			n=stackLength(s,&length);
			if(n==SUCCESS)  printf("ջ���ȵ�ȷΪ%d\n",length);
			else		printf("�´���\n");
			break;
		case 7: printf("������Ҫ�ŵ���");		//��ջ
			scanf("%d",&q);
			n=pushStack(s,q);
			if(n==SUCCESS)  printf("��ջ�ɹ�\n");
			else		printf("ջ����\n");
			break;
		case 8: n=popStack(s,e);			//��ջ
			if(n==SUCCESS)  printf("��ջ��ֵΪ%d\n",*e);
			else 		printf("��ջΪ��\n");
			break;
		default:printf("������1��8����\n");
		}
		getchar();
		system("pause");						//��ֹ��������һ������
		show();
	}
	return 0;
}
