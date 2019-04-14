#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>                    //利用时间生成种子
/**
 *  @name        : void swap(int *a,int i,int j)
 *  @description : 初始化数组
 *  @param       : 数组指针 a,temp, 数组大小size
 */
void intiliaze(int *a,int *temp,int size)
{
	int n;
	for(int i=0;i<size;i++)
	{
		temp[i]=0;
	}
	srand((unsigned)time(NULL));         //生成种子
	for(int i=0;i<size;i++)
	{
		a[i]=rand()%100;   //生成小于的100的元素
	}
}
int main()
{
	int *a,*temp;
	int size;
	printf("请输入要创建的数组大小:");
	scanf("%d",&size);
	a=malloc(size*sizeof(int));
	temp=malloc(size*sizeof(int));
	intiliaze(a,temp,size);
	//下面是写数据
	FILE *fpWrite=fopen("C:\\SortProject\\src\\555.txt","w");
	if(fpWrite==NULL)
	{
		return 0;
	}
	for(int i=0;i<size;i++)
		fprintf(fpWrite,"%d ",a[i]);
	fclose(fpWrite);
	//下面是读数据
	printf("数组为\n");
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
	printf("写入成功");
	getchar();//等待
	getchar();//等待
	return 1;
}

