#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "BinaryTree.h"
int i=0;	//构造二叉树T时记录数组有效个数
int j=0;	//获得中缀表达式结果时记录数组有效个数
/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
Status InitBiTree(BiTree T)
{
	T->rchild=NULL;		//置空
	T->lchild=NULL;
	i=0;
	return SUCCESS;
}


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
 */
Status DestroyBiTree(BiTree T)
{
	if(T ==NULL)
        return SUCCESS;
	DestroyBiTree(T->lchild);	//利用后序遍历规则销毁二叉树
	DestroyBiTree(T->rchild);
	T= NULL;
}


/**
 *  @name        : BiTNode* createBiTree(BiTree T,char* definition);
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
 */
//检查前缀表达式是否合法
int  examine(char* definition)
{
	if(definition[0]=='#') return ERROR;
	for(int i=0;definition[i]!='\0';i++)
	{
		if(definition[i]>='0'&&definition[i]<='9'||definition[i]=='+'||definition[i]=='-'||definition[i]=='*'||definition[i]=='/')
		{
			continue;
		}
		else if(definition[i]=='#'&&definition[i+1]=='#'&&definition[i+2]!='#')
		{
			i++;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
BiTNode* createBiTree(BiTree T,char* definition)
{
	char h=definition[i];
	if (h=='#')			//#为结束标志
	{
		i++;
		return NULL;
	}
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		memset(T,0,sizeof(BiTNode));
		T->data = h;
		i++;
		T->lchild = createBiTree(T->lchild,definition);
		T->rchild = createBiTree(T->rchild,definition);
	}
	return T;
}


/**
 *  @name        : Status visit(TElemType e);
 *  @description : 对结点进行输出值操作
 *  @param       : 结点所存储的值
 */
Status visit(TElemType e)
{
	printf("%c ", e);		//打印节点的值
}

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{

    if (T==NULL)
    {
        return SUCCESS;
    }
    visit(T->data);
    PreOrderTraverse(T->lchild,visit);		//先序遍历根节点的左子树
    PreOrderTraverse(T->rchild,visit);		//先序遍历根节点的右子树
}


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T == NULL) return SUCCESS;
	InOrderTraverse(T->lchild,visit);	//遍历二叉树的左子树
	visit(T->data);				//访问根节点
	InOrderTraverse(T->rchild,visit);	//遍历二叉树的右子树
	return SUCCESS;

}


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T == NULL) return SUCCESS;
	PostOrderTraverse(T->lchild,visit);	//遍历根节点的左子树
	PostOrderTraverse(T->rchild,visit);	//遍历根节点的右子树
	visit(T->data);				//访问根节点
	return SUCCESS;

}


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T!=NULL)
	{
		int front=-1;				//每一次循环中表示从左到右的父节点的增加
		int rear=-1;				//每一次循环当中用来表示front下一层该父节点左右子节点的变化增加
		BiTNode *Q[100];			//用来存储每一层从左到右的每一个树节点
		Q[++rear]=T;
		visit(T->data);
		while(front!=rear)
		{
			BiTNode *p;
			p=Q[++front];
			if(p->lchild)
			{
				Q[++rear]=p->lchild;
				visit(p->lchild->data);
			}
			if(p->rchild)
			{
				Q[++rear]=p->rchild;
				visit(p->rchild->data);
			}
		}

	}
}





//由前缀表达式二叉树获得含二叉树中序遍历结果的数组
Status get(BiTree T,char *a)
{
	if(T == NULL) return SUCCESS;
	get(T->lchild,a);
	a[j]=T->data;
	j++;
	get(T->rchild,a);
	return SUCCESS;
}

//初始化栈
int Init(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	p->top = -1;
	return ok;
}

//判断是否为空栈
int Empty(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	return p->top == -1;
}

//判断满栈
int Full(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	return p->top == 99;
}

//压栈
float Push(DATA *p,float data)
{
	if(p == NULL)
	{
		return error;
	}
	if(Full(p) != ok)
	{
		return error;
	}

	p->top++;
	p->data[p->top] = data;
	return ok;
}

//出栈
float Pop(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	if(Empty(p) != ok)
	{
		return error;
	}
	float data;
	data = p->data[p->top];
	p->top--;

	return data;
}

//获取栈顶元素
float Getpop(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	if(Empty(p) != ok)
	{
		return error;
	}

	return p->data[p->top];
}

void travel1(DATA *p)
{
	for(int i=0;i<=p->top;i++)
		printf("%lf ",p->data[i]);
		printf("\n");
}

void travel2(DATA *p)
{
	for(int i=0;i<=p->top;i++)
		printf("%c ",(int)p->data[i]);				//强制类型转换以输出运算符
		printf("\n");
}

//判断运算符优先级
int judge(char ch)
{
	switch (ch)
	{
		case '(' :
		{
			return 3;
		}
		case '*' :
		{
			return 2;
		}
		case '/' :
		{
			return 2;
		}
		case '+' :
		{
			return 1;
		}
		case '-' :
		{
			return 1;
		}
		default :
		{
			return error;
		}
	}
}

//数值处理计算函数
void calu(char a[])
{
	DATA num,opt;
	Init(&num);
	Init(&opt);
	int i = 0;
	int t=0,m=0;							//t为存在浮点数的标记,m为存在负数的标记
	float temp = 0;
	float j;
	int doub=0;
	int n=1,k=0;
	while(a[i] != '\0' || Empty(&opt) != 1)				//运算式或栈opt不为空时执行循环
	{
		//读取出到右括号(不包括右括号)的所有数字和运算符
		if(a[i] >= '0' && a[i] <= '9')				//a[i]指数字
		{
			temp = temp * 10 + a[i] - '0';			//保证提取出一位或多位数字
			i++;
			if(t==1) doub++;
			if(a[i]=='.') 					//标记当前存在浮点数
			{
				i++,t=1;
				if(a[i] < '0' || a[i] > '9')		//考虑4.+65一类的情况
				{
					Push(&num,temp);
					temp=t=0;
				}
			}
			else if(a[i] < '0' || a[i] > '9')		//先指数字再遇符号
			{
				if(temp>pow(10,8)) 			//当temp过大时
				{
					k=1;
					printf("有一项值太大了\n");
				}
				if(m==1) temp=-temp/pow(10,doub);
				else temp/=pow(10,doub);		//得到浮点数
				Push(&num,temp);
				m=t=doub=temp = 0;			//标记置0
			}
		}
		else							//a[i]指符号
		{
			if(a[i]=='('&&a[i+1]=='-')
			{
				Push(&opt,a[i]);
				i=i+2;
				m=1;					//标记当前存在负数
				continue;
			}
			if((a[i] != '\0' && Empty(&opt)) || (a[i] != ')' && Getpop(&opt) == '(') || (judge(a[i]) > judge(Getpop(&opt))))
			{
				Push(&opt,a[i]);
				i++;
				continue;
			}
			if(a[i] == ')' && Getpop(&opt) == '(')		//去掉(
			{
				Pop(&opt);
				i++;
				continue;
			}
			printf("第%d次\n",n);				//输出每次栈的情况.方便师兄检查
			n++;
			travel1(&num);
			travel2(&opt);

			//进行运算
			if(a[i] == '\0' || a[i] == ')' || judge(a[i]) <= judge(Getpop(&opt)))
			{
				switch ((int)Pop(&opt))
				{
					case '*' :
					{
						Push(&num,Pop(&num)*Pop(&num));
						break;
					}
					case '/':
					{
						j = Pop(&num);
						if(j==0) 			//防止0为被除数的错误
						{
							printf("0不能被除,请重新输入\n");
							k=1;
						}
						else Push(&num,Pop(&num)/j);
						break;
					}
					case '+':
					{
						if(num.top==0) break;				//防止1+2+-6.1之类的错误
						else Push(&num,Pop(&num)+Pop(&num));
						printf("%d\n",num.top);
						break;
					}
					case '-':
					{
						if(num.top==0) break;
						else
						{
							j = Pop(&num);
							Push(&num,Pop(&num)-j);
						}
						break;
					}
					default:
					{
						break;
					}
				}
				continue;
			}
		}


	}
	if(k==0)
	printf("\n%s = %f\n",a,Pop(&num));
}

/**
 *  @name        : int Value(BiTree T);
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
 */
int Value(BiTree T)
{
	j=0;			//j每次应初始化为0，防止多次计算出错
	char a[100];
	get(T,a);		//由前缀表达式二叉树获得含二叉树中序遍历结果的数组
	a[j]='\0';		//给数组加结尾
	calu(a);		//计算中缀表达式
}

/**
 *  @name        : Status PreOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : 先序遍历二叉树T（非递归）
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */

Status PreOrderByLoop(BiTree T, Status (*visit)(TElemType e))
{
	BiTree *s;
	BiTree p;
	int top=-1;
	//创建栈；
	s=malloc((21)*sizeof(BiTree));
	//初始化栈；
	s[++top]=T;
	//非递归前序遍历；
	while(top!=-1)
	{
		p=s[top--];
		visit(p->data);
		if(p->rchild)
			s[++top]=p->rchild;
		if(p->lchild)
			s[++top]=p->lchild;
	}
	free(s);
}


/**
 *  @name        : Status InOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : 中序遍历二叉树T（非递归）
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status InOrderByLoop(BiTree T, Status (*visit)(TElemType e))
{
	BiTree *s;
	BiTree p,q;
	int top=-1;
	//创建栈；
	s=(BiTree *)malloc((21*sizeof(BiTree)));
	//非递归中序遍历；
	if(T)
	{
		while(T)   					//一直遍历左子树直到该结点的左孩子空为止
		{
			s[++top]=T;   				//将所有左孩子存入栈中
			T=T->lchild;     			//指向下一个左子树
		}
		while(top!=-1)  				//栈空时结束循环
		{
			p=s[top--];				//刚开始将最p指向左下角的左孩子，并且移向该结点的父结点
			visit(p->data); 			//输出左下角的结点
			while(p->rchild)  			//遍历移动后结点有没有右结点
			{
				s[++top]=p->rchild;   		//将这个结点的右子树入栈
				q=p->rchild;			//这个右子树结点赋给q
				while(q->lchild)     		//判断结点q有没有左子树
				{
					s[++top]=q->lchild;  	//有左子树，将与这个结点相连的所有左子树都入栈
					q=q->lchild;
				}
			break;  				//结束当前循环
			}
		}
	}
}


/**
 *  @name        : Status PostOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : 后序遍历二叉树T（非递归）
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PostOrderByLoop(BiTree T, Status (*visit)(TElemType e))
{
	BiTree *s;
	BiTree p;
	int top=-1;
	//创建栈；
	s=(BiTree *)malloc(21*sizeof(BiTree ));
	//非递归后序遍历；
	do
	{
		while(T)    					 //一直遍历左子树直到该左子树的左孩子空为止；
		{
			s[++top]=T;    				 //将所有左孩子存入栈中；
			T=T->lchild;  				 //指向下一个左子树；
		}
		p=NULL;
		while(top!=-1)
		{
			T=s[top];
			if(T->rchild==p)  			 //p:表示为null，或者右子节点被访问过了;
			{
				visit(T->data);  		 //输出结点数据域；
				top--;         			 //输出以后，top--；
				p=T;  				 //p记录下刚刚访问的节点;
			}
			else
			{
				T=T->rchild;  			 //访问右子树结点；
				break;
			}
		}
	}while(top!=-1);
}

