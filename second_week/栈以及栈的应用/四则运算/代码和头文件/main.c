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

//��ʼ��
int Init(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	p->top = -1;
	return ok;
}

//�жϿ�ջ
int Empty(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	return p->top == -1;
}

//�ж���ջ
int Full(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	return p->top == SIZE - 1;
}

//ѹջ
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

//��ջ
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



//��ȡջ��Ԫ��
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
		printf("%c ",(int)p->data[i]);				//ǿ������ת������������
		printf("\n");
}

//�ж����ȼ�
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

int decide(char a[])								//�ж�ʽ���Ƿ�Ϸ�
{
	int b,c,num1,num2;
	c=b=num1=num2=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i+1]=='.'&&a[i+2]=='.')					//4..
		{
			printf("��������,����������\n");
			return 1;
		}
		if((a[i] >= '0' && a[i] <= '9')&&(a[i+1] < '0' || a[i+1] > '9')&&a[i+1]!='.'&&a[i+1]!='\0'&&a[i+2]!='-'&&a[i+1]!=')'&&a[i+2]!='(')
		{
			if(a[i+2]=='\0')
			{

				printf("��������,����������\n");
				return 1;
			}
		}
		if(a[i]=='(')  num1++;
		if(a[i]==')')  num2++;
		if(num1<num2)				//��ʱ�����Ŷ���������,˵�����߲�ƥ��
		{
			printf("��������,����������\n");
			return 1;
		}
	}
	if(num1!=num2)					//��������������Ӧ��ͬ
	{
		printf("��������,����������\n");
		return 1;
	}
	return 0;
}

void calu(char a[])							//��ֵ������㺯��
{
	DATA num,opt;
	Init(&num);
	Init(&opt);
	int i = 0;
	int t=0,m=0;							//tΪ���ڸ������ı��,mΪ���ڸ����ı��
	float temp = 0;
	float j;
	int doub=0;
	int n=1,k=0;
	while(a[i] != '\0' || Empty(&opt) != 1)				//����ʽ��ջopt��Ϊ��ʱִ��ѭ��
	{
		//��ȡ����������(������������)���������ֺ������
		if(a[i] >= '0' && a[i] <= '9')				//a[i]ָ����
		{
			temp = temp * 10 + a[i] - '0';			//��֤��ȡ��һλ���λ����
			i++;
			if(t==1) doub++;
			if(a[i]=='.') 					//��ǵ�ǰ���ڸ�����
			{
				i++,t=1;
				if(a[i] < '0' || a[i] > '9')		//����4.+65һ������
				{
					Push(&num,temp);
					temp=t=0;
				}
			}
			else if(a[i] < '0' || a[i] > '9')		//��ָ������������
			{
				if(temp>pow(10,8)) 			//��temp����ʱ
				{
					k=1;
					printf("��һ��ֵ̫����\n");
				}
				if(m==1) temp=-temp/pow(10,doub);
				else temp/=pow(10,doub);		//�õ�������
				Push(&num,temp);
				m=t=doub=temp = 0;			//�����0
			}
		}
		else							//a[i]ָ����
		{
			if(a[i]=='('&&a[i+1]=='-')
			{
				Push(&opt,a[i]);
				i=i+2;
				m=1;					//��ǵ�ǰ���ڸ���
				continue;
			}
			if((a[i] != '\0' && Empty(&opt)) || (a[i] != ')' && Getpop(&opt) == '(') || (judge(a[i]) > judge(Getpop(&opt))))
			{
				Push(&opt,a[i]);
				i++;
				continue;
			}
			if(a[i] == ')' && Getpop(&opt) == '(')		//ȥ��(
			{
				Pop(&opt);
				i++;
				continue;
			}
			printf("��%d��\n",n);				//���ÿ��ջ�����.����ʦ�ּ��
			n++;
			travel1(&num);
			travel2(&opt);

		//��������
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
						if(j==0) 			//��ֹ0Ϊ�������Ĵ���
						{
							printf("0���ܱ���,����������\n");
							k=1;
						}
						else Push(&num,Pop(&num)/j);
						break;
					}
					case '+':
					{
						if(num.top==0) break;				//��ֹ1+2+-6.1֮��Ĵ���
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
	printf("������(��һ������Ϊ#ʱ��������):\n");
	while(scanf("%s",a)==1)
	{
		if(a[i]=='#')
		{
			printf("�������\n");
			break;
		}
		if(decide(a)==1) continue;
		calu(a);
		system("pause");
		system("CLS");		//����
		printf("������(��һ������Ϊ#ʱ��������):\n");
	}
	system("pause");
	return 0;
}
