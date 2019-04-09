#include "AQueue.c"
#include "AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAXQUEUE 10
void show()
{
	system("CLS");		//清屏
	printf("************************************************************************************************************************\n");
	printf("*                                              队列(顺序存储)                                                          *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1  初始化队列                                                            *\n");
	printf("*                                             2  销毁队列                                                              *\n");
	printf("*                                             3  检查队列是否已满                                                      *\n");
	printf("*                                             4  检查队列是否为空                                                      *\n");
	printf("*                                             5  查看队头元素                                                          *\n");
	printf("*                                             6  确定队列长度                                                          *\n");
	printf("*                                             7  入队                                                                  *\n");
	printf("*                                             8  出队                                                                  *\n");
	printf("*                                             9  清空队列                                                              *\n");
	printf("*                                             10 遍历函数                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,输入非数字时退出:");
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
		if(t==0&&x!=1) 						//提醒用户先初始化
		{
			printf("请先初始化队列！\n");
			printf("请重新选择功能:");
			continue;
		}
		switch(x)
		{
		case 1: InitAQueue(Q);
			printf("初始化成功\n");
			t=1;
			break;
		case 2: DestoryAQueue(Q);
			printf("销毁成功,程序结束\n");
			return 0;
			break;
		case 3: if(IsFullAQueue(Q)) printf("队列已满\n");
			else		    printf("队列未满\n");
			break;
		case 4: if(IsEmptyAQueue(Q)) printf("队列是空的\n");
			else 		     printf("队列不是空的\n");
			break;
		case 5: if(!GetHeadAQueue(Q,e))  printf("查看队头元素失败\n");
			break;
		case 6: printf("队列长度为%d\n",LengthAQueue(Q));
			break;
		case 7: printf("请输入(不可输入空格)\n");
			scanf("%s",b[i]);
			data=b[i];
			if(EnAQueue(Q,data))	printf("入队成功\n");
			else			printf("入队失败");
			i++;
			break;
		case 8: if(DeAQueue(Q))		printf("出队成功\n");
			else 			printf("出队失败\n");
			break;
		case 9: ClearAQueue(Q);
			printf("清空队列成功\n");
			break;
		case 10:TraverseAQueue(Q,APrint);
			break;
		default:
			printf("请输入1到10的数\n");
		}
		getchar();
		system("pause");					//防止清屏后结果一闪而过
		show();
	}
	printf("程序结束\n");
	system("pause");
	getchar();
	return 0;
}


