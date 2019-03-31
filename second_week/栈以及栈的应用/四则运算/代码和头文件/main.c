#include <stdio.h>
#include <math.h>
#include<windows.h>
#define SIZE      100
#define ok          0
#define error       1

typedef struct
{
	float data[SIZE];
	int top;
}DATA;

//初始化
int Init(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	p->top = -1;
	return ok;
}

//判断空栈
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
	return p->top == SIZE - 1;
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

//判断优先级
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

int decide(char a[])								//判断式子是否合法
{
	int b,c,num1,num2;
	c=b=num1=num2=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i+1]=='.'&&a[i+2]=='.')					//4..
		{
			printf("输入有误,请重新输入\n");
			return 1;
		}
		if((a[i] >= '0' && a[i] <= '9')&&(a[i+1] < '0' || a[i+1] > '9')&&a[i+1]!='.'&&a[i+1]!='\0'&&a[i+2]!='-'&&a[i+1]!=')'&&a[i+2]!='(')
		{
			if(a[i+2]=='\0')
			{

				printf("输入有误,请重新输入\n");
				return 1;
			}
		}
		if(a[i]=='(')  num1++;
		if(a[i]==')')  num2++;
		if(num1<num2)				//此时右括号多于左括号,说明二者不匹配
		{
			printf("输入有误,请重新输入\n");
			return 1;
		}
	}
	if(num1!=num2)					//最终左右括号数应相同
	{
		printf("输入有误,请重新输入\n");
		return 1;
	}
	return 0;
}

void calu(char a[])							//数值处理计算函数
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


int main()
{
	char a[SIZE] = {0};
	int i=0;
	printf("请输入(第一个输入为#时结束程序):\n");
	while(scanf("%s",a)==1)
	{
		if(a[i]=='#')
		{
			printf("程序结束\n");
			break;
		}
		if(decide(a)==1) continue;
		calu(a);
		system("pause");
		system("CLS");		//清屏
		printf("请输入(第一个输入为#时结束程序):\n");
	}
	system("pause");
	return 0;
}
