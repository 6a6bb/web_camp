#include "qgsort.h"
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
	//下面是写数据
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
 *  @description : 初始化数组
 *  @param       : 数组指针 a,temp, 数组大小size
 */
int read(int *a)
{
	int i;
	//下面是读数据
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
 *  @description : 交换
 *  @param       : 数组指针 a, 两元素下标i，j
 */
void swap(int *a,int i,int j)
{
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;

}
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
	int i, j;
	int temp;  			//定义一个临时变量，用于交换数据时存储
	for(i=1;i<n;i++)  		//因为我们要对该待排序列的每一个元素都和前面的已排好序的序列进行插入，所以我们会对序列进行遍历
	{
		for(j=0;j<i;j++)	//第二层循环主要用于对已排好序的序列进行扫描，和要插入进来的数据进行逐一比较，然后决定插入到哪里
		{
			if(a[j]>a[i])//从前往后对已排好序的元素和待插入元素进行大小比较，然后直到找到一个元素比被插入元素大，则交换位置
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
        int i = begin;				//左序列指针
        int j = mid+1;				//右序列指针
        int t = 0;				//临时数组指针
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
        while(i<=mid)				//将左边剩余元素填充进temp中
        {
		temp[t++] = a[i++];
        }
        while(j<=end)				//将右序列剩余元素填充进temp中
        {
		temp[t++] = a[j++];
        }
        t = 0;
        while(begin <= end)			//将temp中的元素全部拷贝到原数组中
	{
		a[begin++] = temp[t++];
        }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	if(begin<end)
	{
		int mid = (begin+end)/2;
		MergeSort(a,begin,mid,temp);				//左边归并排序，使得左子序列有序
		MergeSort(a,mid+1,end,temp);				//右边归并排序，使得右子序列有序
		MergeArray(a,begin,mid,end,temp);			//将两个有序子数组合并操作
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int par = Partition(a, begin, end);
	if (par>begin + 1)//如果左边有两个数据以上
	{
		QuickSort_Recursion(a, begin, par - 1);
	}
	if (par<end - 1)//如果右边有两个数据以上
	{
		QuickSort_Recursion(a, par + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size)
{
	//1.申请一块内存当栈
	//2.进行一次快速排序，找到基准
	//3.把左边 右边的数对进行入栈
	//4.取出数据进行一趟快速排序
	//5.top>0
	int *stack = (int *)malloc(sizeof(int) * size);//定义栈的大小

	int top = 0;
	int low = 0;
	int high = size - 1;
	int par = Partition(a, low, high);
	if (par>low + 1)//左边有两个数据以上数时  入栈
	{
		stack[top++] = low;
		stack[top++] = par - 1;
	}
	if (par<high - 1)//右边左边有两个数据以上数时  入栈
	    {
		stack[top++] = par + 1;
		stack[top++] = high;
	}
	while (top>0)//出栈  栈不空，需要取两个数据出来排序
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
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
	return begin;//par基准
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
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
	//统计每个元素有几个
	for (int i=0;i<size;++i)
	{
		++c[a[i]];
	}
	//前缀和
	for (int i=1;i<=max;++i)
	{
		c[i]+=c[i-1];
	}
	//反向填充
	for (int i=size-1;i>=0;--i)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	for (i=0;i<size;i++)
	{
		a[i]=b[i];                //返回a数组作为有序序列
	}
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
	int index, pval, i, j, n;	//n为要排序的元素个数，k为基数，p为位的个数。
	int p=2;
	int k=10;
	n=size;
	/*为计数器数组分配空间*/
	int counts[k], temp[size];
      	/*从元素的最低位到最高位开始排序*/
	for(n=0; n<p; n++)
	{
		/*初始化计数器*/
		for(i=0; i<k; i++)
			counts[i] = 0;
		/*计算位置值（幂运算k的n次方）*/
		pval = (int)pow((double)k,(double)n);

		/*统计当前位上每个数值出现的次数*/
		for(j=0; j<size; j++)
		{
			index = (int)(a[j] / pval) % k;
			counts[index] = counts[index]+1;
		}
		/*计算偏移量（本身的次数加上前一个元素次数）*/
		for(i=1; i<k; i++)
			counts[i] = counts[i] + counts[i-1];

		/*使用计数器放置元素位置*/
		for(j=size-1; j>=0; j--)
		{
			index = (int)(a[j] / pval) % k;
			temp[counts[index]-1] = a[j];
			counts[index] = counts[index] - 1;
		}
		/*将已排序元素拷贝回data*/
		memcpy(a, temp, size*sizeof(int));
	}
}




/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
	for(int i=0;i<size;i++)
	{
		a[i]=rand()%3;   //生成小于3的元素
	}
	printf("重新生成的数组为");
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
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K小的数
 *  @param       : 数组指针a，数组长度size
 */
int quick_select(int a[], int l, int r, int k)
{
	int p = rand() % (r - l + 1) + l; 			//任意位置一个哨兵
	int x = a[p];
	{int t = a[p]; a[p] = a[r]; a[r] = t;}
	int i = l, j = r;
	while(i < j)
	{
		while(i < j && a[i] < x)			//快排每次哨兵寻找自己的位置
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
	if(i - l + 1 == k) return a[i];//找到了
	if(i - l + 1 < k) return quick_select(a,i+1,r,k-(i-l+1)); 	//没找到，但是确定的位置比k小，也就是前面都比他小，但是位置并未达到k，分治下半区k的位置要减去上半区的数量；
	else return quick_select(a, l, i - 1, k);			//没找到，但是确定的位置比k大，在前半区里找，k不变。
}



/**
 *  @name        : void print(int *a,int size)
 *  @description : 输出数组元素
 *  @param       : 数组指针a，数组长度size
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
 *  @description : 得到数组元素最大值
 *  @param       : 数组指针a，数组长度size
 */
int getmax(int *a,int size)
{
	int max=a[0];							//得出数组最大值
	for (int i=1;i<size;++i)
	{
		if (a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

