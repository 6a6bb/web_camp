#include "AQueue.c"
#include "AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAXQUEUE 10
void show()
{
	system("CLS");		//����
	printf("************************************************************************************************************************\n");
	printf("*                                              ����(˳��洢)                                                          *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1  ��ʼ������                                                            *\n");
	printf("*                                             2  ���ٶ���                                                              *\n");
	printf("*                                             3  �������Ƿ�����                                                      *\n");
	printf("*                                             4  �������Ƿ�Ϊ��                                                      *\n");
	printf("*                                             5  �鿴��ͷԪ��                                                          *\n");
	printf("*                                             6  ȷ�����г���                                                          *\n");
	printf("*                                             7  ���                                                                  *\n");
	printf("*                                             8  ����                                                                  *\n");
	printf("*                                             9  ��ն���                                                              *\n");
	printf("*                                             10 ��������                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("��ѡ����,���������ʱ�˳�:");
}
int main()
{
	AQueue *Q=malloc(sizeof(AQueue));
	int x,n=0,t=0,i=0;
	char b[MAXQUEUE][100]={0};
	void *data;
	void *e;
	show();
	while(scanf("%d",&x)==1)
	{
		if(t==0&&x!=1) 						//�����û��ȳ�ʼ��
		{
			printf("���ȳ�ʼ�����У�\n");
			printf("������ѡ����:");
			continue;
		}
		switch(x)
		{
		case 1: InitAQueue(Q);
			printf("��ʼ���ɹ�\n");
			t=1;
			break;
		case 2: DestoryAQueue(Q);
			printf("���ٳɹ�,�������\n");
			return 0;
			break;
		case 3: if(IsFullAQueue(Q)) printf("��������\n");
			else		    printf("����δ��\n");
			break;
		case 4: if(IsEmptyAQueue(Q)) printf("�����ǿյ�\n");
			else 		     printf("���в��ǿյ�\n");
			break;
		case 5: if(!GetHeadAQueue(Q,e))  printf("�鿴��ͷԪ��ʧ��\n");
			break;
		case 6: printf("���г���Ϊ%d\n",LengthAQueue(Q));
			break;
		case 7: printf("������(��������ո�)\n");
			scanf("%s",b[i]);
			data=b[i];
			if(EnAQueue(Q,data))	printf("��ӳɹ�\n");
			else			printf("���ʧ��");
			i++;
			break;
		case 8: if(DeAQueue(Q))		printf("���ӳɹ�\n");
			else 			printf("����ʧ��\n");
			break;
		case 9: ClearAQueue(Q);
			printf("��ն��гɹ�\n");
			break;
		case 10:TraverseAQueue(Q,APrint);
			break;
		default:
			printf("������1��10����\n");
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


