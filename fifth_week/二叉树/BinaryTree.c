#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "BinaryTree.h"
int i=0;	//���������Tʱ��¼������Ч����
int j=0;	//�����׺���ʽ���ʱ��¼������Ч����
/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree T)
{
	T->rchild=NULL;		//�ÿ�
	T->lchild=NULL;
	i=0;
	return SUCCESS;
}


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree T)
{
	if(T ==NULL)
        return SUCCESS;
	DestroyBiTree(T->lchild);	//���ú�������������ٶ�����
	DestroyBiTree(T->rchild);
	T= NULL;
}


/**
 *  @name        : BiTNode* createBiTree(BiTree T,char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
//���ǰ׺���ʽ�Ƿ�Ϸ�
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
	if (h=='#')			//#Ϊ������־
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
 *  @description : �Խ��������ֵ����
 *  @param       : ������洢��ֵ
 */
Status visit(TElemType e)
{
	printf("%c ", e);		//��ӡ�ڵ��ֵ
}

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{

    if (T==NULL)
    {
        return SUCCESS;
    }
    visit(T->data);
    PreOrderTraverse(T->lchild,visit);		//����������ڵ��������
    PreOrderTraverse(T->rchild,visit);		//����������ڵ��������
}


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T == NULL) return SUCCESS;
	InOrderTraverse(T->lchild,visit);	//������������������
	visit(T->data);				//���ʸ��ڵ�
	InOrderTraverse(T->rchild,visit);	//������������������
	return SUCCESS;

}


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T == NULL) return SUCCESS;
	PostOrderTraverse(T->lchild,visit);	//�������ڵ��������
	PostOrderTraverse(T->rchild,visit);	//�������ڵ��������
	visit(T->data);				//���ʸ��ڵ�
	return SUCCESS;

}


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T!=NULL)
	{
		int front=-1;				//ÿһ��ѭ���б�ʾ�����ҵĸ��ڵ������
		int rear=-1;				//ÿһ��ѭ������������ʾfront��һ��ø��ڵ������ӽڵ�ı仯����
		BiTNode *Q[100];			//�����洢ÿһ������ҵ�ÿһ�����ڵ�
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





//��ǰ׺���ʽ��������ú�����������������������
Status get(BiTree T,char *a)
{
	if(T == NULL) return SUCCESS;
	get(T->lchild,a);
	a[j]=T->data;
	j++;
	get(T->rchild,a);
	return SUCCESS;
}

//��ʼ��ջ
int Init(DATA *p)
{
	if(p == NULL)
	{
		return error;
	}
	p->top = -1;
	return ok;
}

//�ж��Ƿ�Ϊ��ջ
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
	return p->top == 99;
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

//�ж���������ȼ�
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

//��ֵ������㺯��
void calu(char a[])
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

/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T)
{
	j=0;			//jÿ��Ӧ��ʼ��Ϊ0����ֹ��μ������
	char a[100];
	get(T,a);		//��ǰ׺���ʽ��������ú�����������������������
	a[j]='\0';		//������ӽ�β
	calu(a);		//������׺���ʽ
}

/**
 *  @name        : Status PreOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T���ǵݹ飩
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */

Status PreOrderByLoop(BiTree T, Status (*visit)(TElemType e))
{
	BiTree *s;
	BiTree p;
	int top=-1;
	//����ջ��
	s=malloc((21)*sizeof(BiTree));
	//��ʼ��ջ��
	s[++top]=T;
	//�ǵݹ�ǰ�������
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
 *  @description : �������������T���ǵݹ飩
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderByLoop(BiTree T, Status (*visit)(TElemType e))
{
	BiTree *s;
	BiTree p,q;
	int top=-1;
	//����ջ��
	s=(BiTree *)malloc((21*sizeof(BiTree)));
	//�ǵݹ����������
	if(T)
	{
		while(T)   					//һֱ����������ֱ���ý������ӿ�Ϊֹ
		{
			s[++top]=T;   				//���������Ӵ���ջ��
			T=T->lchild;     			//ָ����һ��������
		}
		while(top!=-1)  				//ջ��ʱ����ѭ��
		{
			p=s[top--];				//�տ�ʼ����pָ�����½ǵ����ӣ���������ý��ĸ����
			visit(p->data); 			//������½ǵĽ��
			while(p->rchild)  			//�����ƶ�������û���ҽ��
			{
				s[++top]=p->rchild;   		//�����������������ջ
				q=p->rchild;			//�����������㸳��q
				while(q->lchild)     		//�жϽ��q��û��������
				{
					s[++top]=q->lchild;  	//����������������������������������������ջ
					q=q->lchild;
				}
			break;  				//������ǰѭ��
			}
		}
	}
}


/**
 *  @name        : Status PostOrderByLoop(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T���ǵݹ飩
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderByLoop(BiTree T, Status (*visit)(TElemType e))
{
	BiTree *s;
	BiTree p;
	int top=-1;
	//����ջ��
	s=(BiTree *)malloc(21*sizeof(BiTree ));
	//�ǵݹ���������
	do
	{
		while(T)    					 //һֱ����������ֱ���������������ӿ�Ϊֹ��
		{
			s[++top]=T;    				 //���������Ӵ���ջ�У�
			T=T->lchild;  				 //ָ����һ����������
		}
		p=NULL;
		while(top!=-1)
		{
			T=s[top];
			if(T->rchild==p)  			 //p:��ʾΪnull���������ӽڵ㱻���ʹ���;
			{
				visit(T->data);  		 //������������
				top--;         			 //����Ժ�top--��
				p=T;  				 //p��¼�¸ոշ��ʵĽڵ�;
			}
			else
			{
				T=T->rchild;  			 //������������㣻
				break;
			}
		}
	}while(top!=-1);
}

