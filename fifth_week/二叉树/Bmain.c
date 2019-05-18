#include "BinaryTree.c"
#include "BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void show()
{
	system("CLS");		//清屏
	printf("************************************************************************************************************************\n");
	printf("*                                                二叉树                                                        	       *\n");
	printf("************************************************************************************************************************\n");
	printf("*                                             1  构造空二叉树                                                          *\n");
	printf("*                                             2  摧毁二叉树                                                            *\n");
	printf("*                                             3  构造二叉树                                                            *\n");
	printf("*                                             4  先序遍历                                                      	       *\n");
	printf("*                                             5  中序遍历                                                              *\n");
	printf("*                                             6  后序遍历                                                              *\n");
	printf("*                                             7  层序遍历                                                              *\n");
	printf("*                                             8  二叉树求值                                                            *\n");
	printf("*                                             9  先序遍历二叉树T（非递归）                                             *\n");
	printf("*                                             10 中序遍历二叉树T（非递归）                                             *\n");
	printf("*                                             11 后序遍历二叉树T（非递归）                                             *\n");
	printf("************************************************************************************************************************\n");
	printf("请选择功能,输入非数字时退出:");
}
int main()
{
	char* definition="+*3##4##2##";
	int x,t=0,n=1;
	BiTNode* T=malloc(sizeof(BiTNode));
	show();
	while(scanf("%d",&x)==1)
	{
		if((t==0&&x!=1)||(n==0&&x==3)) 						//提醒用户先初始化
		{
			printf("请先初始化！\n");
			printf("请重新选择功能:");
			continue;
		}
		if(t==1&&n==1&&x!=3)							//提醒用户初始化后要构造二叉树
		{
			printf("请构造树！\n");
			printf("请重新选择功能:");
			continue;
		}
		switch(x)
		{
		case 1: InitBiTree(T);
			printf("初始化成功\n");
			n=t=1;
			break;
		case 2: DestroyBiTree(T);
			printf("销毁成功,程序结束\n");
			return 0;
			break;
		case 3:	T=createBiTree(T,definition);
			printf("构造成功\n");
			n=0;								  //标记n为0，防止用户连续构造树
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
			printf("请输入1到11的数\n");
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


