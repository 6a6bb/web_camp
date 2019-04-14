#include "qgsort.h"
#include "qgsort.c"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
void show()
{
	system("CLS");		//清屏
	printf("************************************************************************************************************************\n");
	printf("*                                                排序                                                                  *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                            -1 从文件555读入数组元素                                                  *\n");
	printf("*                                             0 在这里初始化数组并写入                                                 *\n");
	printf("*                                             1 插入排序                                                               *\n");
	printf("*                                             2 归并排序                                                               *\n");
	printf("*                                             3 快速排序（递归版）                                                     *\n");
	printf("*                                             4 快速排序（非递归版）                                                   *\n");
	printf("*                                             5 计数排序                                                               *\n");
	printf("*                                             6 基数计数排序                                                           *\n");
	printf("*                                             7 颜色排序（将重新生成元素为0-2的数组）                                  *\n");
	printf("*                                             8 在一个无序序列中找到第k小的数                                          *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,按字母退出:");
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
			printf("原数组为 ");
			print(a,size);
		}
		else if(t==0&&x!=0&&x!=-1)
		{
			printf("请先初始化数组\n");
			printf("请重新选择功能:");
			continue;
		}
		switch(x)
		{
		case -1:a=malloc(size*sizeof(int));
			temp=malloc(size*sizeof(int));
			size=read(a);
			t=1;
			break;
		case 0:	printf("请输入要创建的数组大小:");
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
		case 8: printf("要找第几小的数呢?");
			scanf("%d",&k);
			if(k>size||k<=0)
			{
				printf("输入有误,输入的数应为正整数且小于数组元素个数\n");
				break;
			}
			printf("第%d小的数为%d\n", k,quick_select(a, 0, size-1, k));		//找到第K个小的元素
			break;
		default:
			printf("请输入-1到8的数\n");
		}
		printf("现在数组为 "),print(a,size);
		getchar();
		system("pause");						//防止清屏后结果一闪而过
		show();
	}
	printf("程序结束\n");
	system("pause");
	getchar();
	return 0;
}
