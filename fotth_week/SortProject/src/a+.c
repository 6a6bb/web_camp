#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>                    //����ʱ����������
/**
 *  @name        : void swap(int *a,int i,int j)
 *  @description : ��ʼ������
 *  @param       : ����ָ�� a,temp, �����Сsize
 */
void intiliaze(int *a,int *temp,int size)
{
	int n;
	for(int i=0;i<size;i++)
	{
		temp[i]=0;
	}
	srand((unsigned)time(NULL));         //��������
	for(int i=0;i<size;i++)
	{
		a[i]=rand()%100;   //����С�ڵ�100��Ԫ��
	}
}
int main()
{
	int *a,*temp;
	int size;
	printf("������Ҫ�����������С:");
	scanf("%d",&size);
	a=malloc(size*sizeof(int));
	temp=malloc(size*sizeof(int));
	intiliaze(a,temp,size);
	//������д����
	FILE *fpWrite=fopen("C:\\SortProject\\src\\555.txt","w");
	if(fpWrite==NULL)
	{
		return 0;
	}
	for(int i=0;i<size;i++)
		fprintf(fpWrite,"%d ",a[i]);
	fclose(fpWrite);
	//�����Ƕ�����
	printf("����Ϊ\n");
	FILE *fpRead=fopen("C:\\SortProject\\src\\555.txt","r");
	if(fpRead==NULL)
	{
		return 0;
	}
	for(int i=0;!feof(fpRead);i++)
	{
		fscanf(fpRead,"%d ",&a[i]);
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("д��ɹ�");
	getchar();//�ȴ�
	getchar();//�ȴ�
	return 1;
}

