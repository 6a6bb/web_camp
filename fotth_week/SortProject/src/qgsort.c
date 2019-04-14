#include "qgsort.h"
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
	//������д����
	FILE *fpWrite=fopen("C:\\SortProject\\src\\555.txt","w");
	if(fpWrite==NULL)
	{
		return ;
	}
	for(int i=0;i<size;i++)
		fprintf(fpWrite,"%d ",a[i]);
	fclose(fpWrite);
}

/**
 *  @name        : void swap(int *a,int i,int j)
 *  @description : ��ʼ������
 *  @param       : ����ָ�� a,temp, �����Сsize
 */
int read(int *a)
{
	int i;
	//�����Ƕ�����
	FILE *fpRead=fopen("C:\\SortProject\\src\\555.txt","r");
	if(fpRead==NULL)
	{
		return 0;
	}
	for(i=0;!feof(fpRead);i++)
	{
		fscanf(fpRead,"%d ",&a[i]);
	}
	return i;
}

/**
 *  @name        : void swap(int *a,int i,int j)
 *  @description : ����
 *  @param       : ����ָ�� a, ��Ԫ���±�i��j
 */
void swap(int *a,int i,int j)
{
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;

}
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
	int i, j;
	int temp;  			//����һ����ʱ���������ڽ�������ʱ�洢
	for(i=1;i<n;i++)  		//��Ϊ����Ҫ�Ըô������е�ÿһ��Ԫ�ض���ǰ������ź�������н��в��룬�������ǻ�����н��б���
	{
		for(j=0;j<i;j++)	//�ڶ���ѭ����Ҫ���ڶ����ź�������н���ɨ�裬��Ҫ������������ݽ�����һ�Ƚϣ�Ȼ��������뵽����
		{
			if(a[j]>a[i])//��ǰ��������ź����Ԫ�غʹ�����Ԫ�ؽ��д�С�Ƚϣ�Ȼ��ֱ���ҵ�һ��Ԫ�رȱ�����Ԫ�ش��򽻻�λ��
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}

		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
        int i = begin;				//������ָ��
        int j = mid+1;				//������ָ��
        int t = 0;				//��ʱ����ָ��
        while (i<=mid && j<=end)
	{
		if(a[i]<=a[j])
		{
			temp[t++] = a[i++];
		}
		else
		{
			temp[t++] = a[j++];
		}
        }
        while(i<=mid)				//�����ʣ��Ԫ������temp��
        {
		temp[t++] = a[i++];
        }
        while(j<=end)				//��������ʣ��Ԫ������temp��
        {
		temp[t++] = a[j++];
        }
        t = 0;
        while(begin <= end)			//��temp�е�Ԫ��ȫ��������ԭ������
	{
		a[begin++] = temp[t++];
        }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	if(begin<end)
	{
		int mid = (begin+end)/2;
		MergeSort(a,begin,mid,temp);				//��߹鲢����ʹ��������������
		MergeSort(a,mid+1,end,temp);				//�ұ߹鲢����ʹ��������������
		MergeArray(a,begin,mid,end,temp);			//����������������ϲ�����
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int par = Partition(a, begin, end);
	if (par>begin + 1)//��������������������
	{
		QuickSort_Recursion(a, begin, par - 1);
	}
	if (par<end - 1)//����ұ���������������
	{
		QuickSort_Recursion(a, par + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size)
{
	//1.����һ���ڴ浱ջ
	//2.����һ�ο��������ҵ���׼
	//3.����� �ұߵ����Խ�����ջ
	//4.ȡ�����ݽ���һ�˿�������
	//5.top>0
	int *stack = (int *)malloc(sizeof(int) * size);//����ջ�Ĵ�С

	int top = 0;
	int low = 0;
	int high = size - 1;
	int par = Partition(a, low, high);
	if (par>low + 1)//�������������������ʱ  ��ջ
	{
		stack[top++] = low;
		stack[top++] = par - 1;
	}
	if (par<high - 1)//�ұ��������������������ʱ  ��ջ
	    {
		stack[top++] = par + 1;
		stack[top++] = high;
	}
	while (top>0)//��ջ  ջ���գ���Ҫȡ�������ݳ�������
	{
		high = stack[--top];
		low = stack[--top];
		par = Partition(a, low, high);
		if (par>low + 1)
		{
			stack[top++] = low;
			stack[top++] = par - 1;
		}
		if (par<high - 1)
		{
		stack[top++] = par + 1;
		stack[top++] = high;
		}
	}
	free(stack);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
	int tmp = a[begin];
	while (begin<end)
	{
		while (begin < end && a[end] >= tmp)
		{
			end--;
		}
		if (begin>= end)
		{
			break;
		}
		else
		{
			a[begin] = a[end];
		}
		while (begin<end && a[begin] <= tmp)
		{
			begin++;
		}
		if (begin >= end)
		{
			break;
		}
		else
		{
			a[end] = a[begin];
		}
	}
	a[begin] = tmp;
	return begin;//par��׼
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
	int b[size];
	int c[max+1];
	for(int i=0;i<max+1;i++)
	{
		c[i]=0;
	}
	int i;
	//ͳ��ÿ��Ԫ���м���
	for (int i=0;i<size;++i)
	{
		++c[a[i]];
	}
	//ǰ׺��
	for (int i=1;i<=max;++i)
	{
		c[i]+=c[i-1];
	}
	//�������
	for (int i=size-1;i>=0;--i)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	for (i=0;i<size;i++)
	{
		a[i]=b[i];                //����a������Ϊ��������
	}
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
	int index, pval, i, j, n;	//nΪҪ�����Ԫ�ظ�����kΪ������pΪλ�ĸ�����
	int p=2;
	int k=10;
	n=size;
	/*Ϊ�������������ռ�*/
	int counts[k], temp[size];
      	/*��Ԫ�ص����λ�����λ��ʼ����*/
	for(n=0; n<p; n++)
	{
		/*��ʼ��������*/
		for(i=0; i<k; i++)
			counts[i] = 0;
		/*����λ��ֵ��������k��n�η���*/
		pval = (int)pow((double)k,(double)n);

		/*ͳ�Ƶ�ǰλ��ÿ����ֵ���ֵĴ���*/
		for(j=0; j<size; j++)
		{
			index = (int)(a[j] / pval) % k;
			counts[index] = counts[index]+1;
		}
		/*����ƫ����������Ĵ�������ǰһ��Ԫ�ش�����*/
		for(i=1; i<k; i++)
			counts[i] = counts[i] + counts[i-1];

		/*ʹ�ü���������Ԫ��λ��*/
		for(j=size-1; j>=0; j--)
		{
			index = (int)(a[j] / pval) % k;
			temp[counts[index]-1] = a[j];
			counts[index] = counts[index] - 1;
		}
		/*��������Ԫ�ؿ�����data*/
		memcpy(a, temp, size*sizeof(int));
	}
}




/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
	for(int i=0;i<size;i++)
	{
		a[i]=rand()%3;   //����С��3��Ԫ��
	}
	printf("�������ɵ�����Ϊ");
	print(a,size);
        int left =0;
        int right = size-1;
        int i=0;
        while(i<=right)
	{
		if(a[i]==0)
		{
			swap(a,i++,left++);
		}
		else if(a[i]==2)
		{
			swap(a,i,right--);
		}
		else
		{
			i++;
		}
        }
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a�����鳤��size
 */
int quick_select(int a[], int l, int r, int k)
{
	int p = rand() % (r - l + 1) + l; 			//����λ��һ���ڱ�
	int x = a[p];
	{int t = a[p]; a[p] = a[r]; a[r] = t;}
	int i = l, j = r;
	while(i < j)
	{
		while(i < j && a[i] < x)			//����ÿ���ڱ�Ѱ���Լ���λ��
		{
			i++;
		}
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
		while(i < j && a[j] > x)
		{
			j--;
		}
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}
	}
	a[i] = x;
	p = i;
	if(i - l + 1 == k) return a[i];//�ҵ���
	if(i - l + 1 < k) return quick_select(a,i+1,r,k-(i-l+1)); 	//û�ҵ�������ȷ����λ�ñ�kС��Ҳ����ǰ�涼����С������λ�ò�δ�ﵽk�������°���k��λ��Ҫ��ȥ�ϰ�����������
	else return quick_select(a, l, i - 1, k);			//û�ҵ�������ȷ����λ�ñ�k����ǰ�������ң�k���䡣
}



/**
 *  @name        : void print(int *a,int size)
 *  @description : �������Ԫ��
 *  @param       : ����ָ��a�����鳤��size
 */
void print(int *a,int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

/**
 *  @name        : void print(int *a,int size)
 *  @description : �õ�����Ԫ�����ֵ
 *  @param       : ����ָ��a�����鳤��size
 */
int getmax(int *a,int size)
{
	int max=a[0];							//�ó��������ֵ
	for (int i=1;i<size;++i)
	{
		if (a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

