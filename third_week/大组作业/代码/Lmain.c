#include "LQueue.c"
#include "LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void show()
{
	system("CLS");		//清屏
	printf("************************************************************************************************************************\n");
	printf("*                                              队列(链式存储)                                                          *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1  初始化队列                                                            *\n");
	printf("*                                             2  销毁队列                                                              *\n");
	printf("*                                             3  检查队列是否为空                                                      *\n");
	printf("*                                             4  查看队头元素                                                          *\n");
	printf("*                                             5  确定队列长度                                                          *\n");
	printf("*                                             6  入队                                                                  *\n");
	printf("*                                             7  出队                                                                  *\n");
	printf("*                                             8  清空队列                                                              *\n");
	printf("*                                             9  遍历函数                                                              *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,输入非数字时退出:");
}
int main()
{
	LQueue *Q=malloc(sizeof(LQueue));
	int x,n=0,t=0,i=0;
	char b[20][100]={0};
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
		case 1: InitLQueue(Q);
			printf("初始化成功\n");
			t=1;
			break;
		case 2: DestoryLQueue(Q);
			printf("销毁成功,程序结束\n");
			return 0;
			break;
		case 3: if(IsEmptyLQueue(Q)) printf("队列是空的\n");
			else 		     printf("队列不是空的\n");
			break;
		case 4: if(!GetHeadLQueue(Q,e)) printf("查看队头元素失败\n");
			break;
		case 5: printf("队列长度为%d\n",LengthLQueue(Q));
			break;
		case 6: printf("请输入(不可输入空格)\n");
			scanf("%s",b[i]);
			data=b[i];
			if(EnLQueue(Q,data))	printf("入队成功\n");
			else			printf("入队失败");
			i++;
			break;
		case 7: if(DeLQueue(Q))		printf("出队成功\n");
			else 			printf("出队失败\n");
			break;
		case 8: ClearLQueue(Q);
			printf("清空队列成功\n");
			break;
		case 9: TraverseLQueue(Q,LPrint);
			break;
		default:
			printf("请输入1到9的数\n");
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



