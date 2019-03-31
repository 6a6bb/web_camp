#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->count=0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(s->count==0) return SUCCESS;
	else return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(s->count==0) return ERROR;
	else
	{
		*e=s->top->data;
	}
	return SUCCESS;
}

Status clearLStack(LinkStack *s)   //清空栈
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

Status destroyLStack(LinkStack *s)   //销毁栈
{
	clearLStack(s);
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	if(s->count==*length) return SUCCESS;
	else return ERROR;
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
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

Status popLStack(LinkStack *s,ElemType *data)   //出栈
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
