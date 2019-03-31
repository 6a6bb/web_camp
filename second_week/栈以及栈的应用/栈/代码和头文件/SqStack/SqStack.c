#include "SqStack.h"
#include<stdio.h>
#include<stdlib.h>
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s->top=-1;
	s->elem=malloc(sizes*sizeof(int));
	s->size=sizes;
	return SUCCESS;
}

Status  isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1) return SUCCESS;
	else return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(isEmptyStack(s)) return ERROR;	//����Ϊ��
	else
	{
		*e=s->elem[s->top];
		return SUCCESS;
	}
}

Status clearStack(SqStack *s)   //���ջ
{
	while(s->top>-1)
	{
		free(&(s->elem[s->top]));
		s->top--;
	}
	return SUCCESS;
}

Status destroyStack(SqStack *s)  //����ջ
{
	clearStack(s);
	s->elem=NULL;
	s->size=0;
	s->top=-1;
	free(s);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //���ջ����
{
	if(*length==s->top+1) return SUCCESS;
	else return ERROR;
}

Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s->top==s->size-1)  return ERROR;		//���˾Ͳ�����ջ
	else
	{
		s->top++;     		//ָ���ȼ�1
		s->elem[s->top]=data;	//�ٰ����ݴ����Ӧ�ġ����ӡ�
		return SUCCESS;
	}

}

Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if(s->top==-1)  return ERROR;		//��ʱ���ܳ�ջ
	else
	{
		*data=s->elem[s->top];	//��ֵ
		s->top--;     		//ָ���1
		return SUCCESS;
	}
}

