#include "qgsort.h"
#include "qgsort.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
void show()
{
	system("CLS");		//����
	printf("************************************************************************************************************************\n");
	printf("*                                                ����                                                                  *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                            -1 ���ļ�555��������Ԫ��                                                  *\n");
	printf("*                                             0 �������ʼ�����鲢д��                                                 *\n");
	printf("*                                             1 ��������                                                               *\n");
	printf("*                                             2 �鲢����                                                               *\n");
	printf("*                                             3 �������򣨵ݹ�棩                                                     *\n");
	printf("*                                             4 �������򣨷ǵݹ�棩                                                   *\n");
	printf("*                                             5 ��������                                                               *\n");
	printf("*                                             6 ������������                                                           *\n");
	printf("*                                             7 ��ɫ���򣨽���������Ԫ��Ϊ0-2�����飩                                  *\n");
	printf("*                                             8 ��һ�������������ҵ���kС����                                          *\n");
	printf("************************************************************************************************************************\n");
	printf("��ѡ����,����ĸ�˳�:");
}
int main()
{
	show();
	int *a,*temp,t=0,max;
	int size,x=0,k;
	while(scanf("%d",&x)==1)
	{
		if(t==1)
		{
			printf("ԭ����Ϊ ");
			print(a,size);
		}
		else if(t==0&&x!=0&&x!=-1)
		{
			printf("���ȳ�ʼ������\n");
			printf("������ѡ����:");
			continue;
		}
		switch(x)
		{
		case -1:a=malloc(size*sizeof(int));
			temp=malloc(size*sizeof(int));
			size=read(a);
			t=1;
			break;
		case 0:	printf("������Ҫ�����������С:");
			scanf("%d",&size);
			a=malloc(size*sizeof(int));
			temp=malloc(size*sizeof(int));
			intiliaze(a,temp,size);
			t=1;
			break;
		case 1: insertSort(a,size);
			break;
		case 2: MergeSort(a,0,size-1,temp);
			break;
		case 3: QuickSort_Recursion(a,0,size-1);
			break;
		case 4: QuickSort(a,size);
			break;
		case 5:	max=getmax(a,size);
			CountSort(a,size,max);
			break;
		case 6: RadixCountSort(a,size);
			break;
		case 7: ColorSort(a,size);
			break;
		case 8: printf("Ҫ�ҵڼ�С������?");
			scanf("%d",&k);
			if(k>size||k<=0)
			{
				printf("��������,�������ӦΪ��������С������Ԫ�ظ���\n");
				break;
			}
			printf("��%dС����Ϊ%d\n", k,quick_select(a, 0, size-1, k));		//�ҵ���K��С��Ԫ��
			break;
		default:
			printf("������-1��8����\n");
		}
		printf("��������Ϊ "),print(a,size);
		getchar();
		system("pause");						//��ֹ��������һ������
		show();
	}
	printf("�������\n");
	system("pause");
	getchar();
	return 0;
}
