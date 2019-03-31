#include "SqStack.h"
#include<stdio.h>
#include<stdlib.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->top=-1;
	s->elem=malloc(sizes*sizeof(int));
	s->size=sizes;
	return SUCCESS;
}

Status  isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s->top==-1) return SUCCESS;
	else return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(isEmptyStack(s)) return ERROR;	//链表为空
	else
	{
		*e=s->elem[s->top];
		return SUCCESS;
	}
}

Status clearStack(SqStack *s)   //清空栈
{
	while(s->top>-1)
	{
		free(&(s->elem[s->top]));
		s->top--;
	}
	return SUCCESS;
}

Status destroyStack(SqStack *s)  //销毁栈
{
	clearStack(s);
	s->elem=NULL;
	s->size=0;
	s->top=-1;
	free(s);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	if(*length==s->top+1) return SUCCESS;
	else return ERROR;
}

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->top==s->size-1)  return ERROR;		//满了就不能入栈
	else
	{
		s->top++;     		//指针先加1
		s->elem[s->top]=data;	//再把数据存进对应的“格子”
		return SUCCESS;
	}

}

Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if(s->top==-1)  return ERROR;		//空时不能出栈
	else
	{
		*data=s->elem[s->top];	//赋值
		s->top--;     		//指针减1
		return SUCCESS;
	}
}

