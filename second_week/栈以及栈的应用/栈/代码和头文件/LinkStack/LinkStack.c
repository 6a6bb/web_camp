#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->count=0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(s->count==0) return SUCCESS;
	else return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if(s->count==0) return ERROR;
	else
	{
		*e=s->top->data;
	}
	return SUCCESS;
}

Status clearLStack(LinkStack *s)   //���ջ
{
	StackNode *p;
	while(s->top!=NULL)
	{
		p=s->top;
		s->top=s->top->next;
		free(p);
		s->count--;
	}
	s->count=0;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //����ջ
{
	clearLStack(s);
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	if(s->count==*length) return SUCCESS;
	else return ERROR;
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	StackNode *p=malloc(sizeof(StackNode));
	p->data=data;
	if(s->count==0)
	{
		s->top=p;
		p->next=NULL;
	}
	else
	{
		p->next=s->top;
		s->top=p;
	}
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	StackNode *p;
	if(s->count==0) return ERROR;
	else
	{	p=s->top;
		*data=s->top->data;
		s->top=p->next;
		free(p);
	}
	s->count--;
	return SUCCESS;
}
