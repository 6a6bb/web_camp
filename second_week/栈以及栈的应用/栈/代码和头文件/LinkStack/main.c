#include "LinkStack.c"
#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void show()
{
	system("CLS");		//清屏
	printf("************************************************************************************************************************\n");
	printf("*                                              链栈(基于链表的)                                                        *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1 初始化栈                                                               *\n");
	printf("*                                             2 判断栈是否为空                                                         *\n");
	printf("*                                             3 得到栈顶元素                                                           *\n");
	printf("*                                             4 清空栈                                                                 *\n");
	printf("*                                             5 销毁栈                                                                 *\n");
	printf("*                                             6 检测栈长度                                                             *\n");
	printf("*                                             7 入栈                                                                   *\n");
	printf("*                                             8 出栈                                                                   *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,按字母退出:");
}
int main()
{
	LinkStack *s;
	s=malloc(sizeof(LinkStack));
	s->top=NULL;
	ElemType *e;
	e=malloc(sizeof(int));
	int x,n=ERROR,length,q;
	int t=0;
	show();
	while(scanf("%d",&x)==1)
	{
		if(t==0&&x!=1) 						//提醒用户先初始化栈
		{
			printf("请先初始化栈！\n");
			printf("请重新选择功能:");
			continue;
		}
		switch(x)
		{
		case 1: initLStack(s);					//初始化栈
			t=1;
			break;
		case 2: n=isEmptyLStack(s);				//判断栈是否为空
			if(n==SUCCESS)  printf("栈为空\n");
			else		printf("栈不为空\n");
			break;
		case 3: n=getTopLStack(s,e);				//得到栈顶元素
			if(n==SUCCESS)  printf("栈顶元素为%d\n",*e);
			break;
		case 4:	n=clearLStack(s);					//清空栈
			if(n==SUCCESS)  printf("清空成功\n");
			break;
		case 5:	n=destroyLStack(s);				//销毁栈
			if(n==SUCCESS)
			{
				printf("销毁成功,程序结束\n");
				return 0;
			}
			else	printf("销毁失败\n");
			break;
		case 6:	printf("你觉得长度为\n");		//检测栈长度
			scanf("%d",&length);
			n=LStackLength(s,&length);
			if(n==SUCCESS)  printf("栈长度的确为%d\n",length);
			else		printf("猜错啦\n");
			break;
		case 7: printf("请输入要放的数");			//入栈
			scanf("%d",&q);
			n=pushLStack(s,q);
			if(n==SUCCESS)  printf("入栈成功\n");
			else		printf("栈已满\n");
			break;
		case 8: n=popLStack(s,e);				//出栈
			if(n==SUCCESS)  printf("出栈的值为%d\n",*e);
			else		 printf("该栈为空\n");
			break;
		default:
			printf("请输入1到8的数\n");
		}
		getchar();
		system("pause");					//防止清屏后结果一闪而过
		show();
	}

	system("pause");
	getchar();
	return 0;
}
