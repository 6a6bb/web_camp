#include "BinaryTree.c"
#include "BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void show()
{
	system("CLS");		//����
	printf("************************************************************************************************************************\n");
	printf("*                                                ������                                                        	       *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1  ����ն�����                                                          *\n");
	printf("*                                             2  �ݻٶ�����                                                            *\n");
	printf("*                                             3  ���������                                                            *\n");
	printf("*                                             4  �������                                                      	       *\n");
	printf("*                                             5  �������                                                              *\n");
	printf("*                                             6  �������                                                              *\n");
	printf("*                                             7  �������                                                              *\n");
	printf("*                                             8  ��������ֵ                                                            *\n");
	printf("*                                             9  �������������T���ǵݹ飩                                             *\n");
	printf("*                                             10 �������������T���ǵݹ飩                                             *\n");
	printf("*                                             11 �������������T���ǵݹ飩                                             *\n");
	printf("************************************************************************************************************************\n");
	printf("��ѡ����,���������ʱ�˳�:");
}
int main()
{
	char* definition="+*3##4##2##";
	int x,t=0,n=1;
	BiTNode* T=malloc(sizeof(BiTNode));
	show();
	while(scanf("%d",&x)==1)
	{
		if((t==0&&x!=1)||(n==0&&x==3)) 						//�����û��ȳ�ʼ��
		{
			printf("���ȳ�ʼ����\n");
			printf("������ѡ����:");
			continue;
		}
		if(t==1&&n==1&&x!=3)							//�����û���ʼ����Ҫ���������
		{
			printf("�빹������\n");
			printf("������ѡ����:");
			continue;
		}
		switch(x)
		{
		case 1: InitBiTree(T);
			printf("��ʼ���ɹ�\n");
			n=t=1;
			break;
		case 2: DestroyBiTree(T);
			printf("���ٳɹ�,�������\n");
			return 0;
			break;
		case 3:	T=createBiTree(T,definition);
			printf("����ɹ�\n");
			n=0;								  //���nΪ0����ֹ�û�����������
			break;
		case 4: PreOrderTraverse(T,visit);
			break;
		case 5: InOrderTraverse(T,visit);
			break;
		case 6: PostOrderTraverse(T,visit);
			break;
		case 7: LevelOrderTraverse(T,visit);
			break;
		case 8: Value(T);
			break;
		case 9: PreOrderByLoop(T,visit);
			break;
		case 10:InOrderByLoop(T,visit);
			break;
		case 11:PostOrderByLoop(T,visit);
			break;
		default:
			printf("������1��11����\n");
		}
		getchar();
		system("pause");					//��ֹ��������һ������
		show();
	}
	printf("�������\n");
	system("pause");
	getchar();
	return 0;
}


