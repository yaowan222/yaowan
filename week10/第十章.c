void insertionSort(int a[],int n){
int i,j,tmp;
for(i=1;i<n;i++){
tmp=a[i];
for(j=i;j>0&&a[j-1]>tmp;j--)
a[j]=a[j-1];
a[j]=tmp;
}
}



//贪婪
#include<stdio.h>
void schedule(int m,int n,int *t){
	//初始化
	int i,j,k,max=0;
	int d[100],s[100][100],count[100];
	for(i=0;i<m;i++){
		d[i]=0;
		for(j=0;j<n;j++){
			s[i][j]=-1;//-1代表不执行任何任务，不与第0号任务混淆
		}
	}
	//分配前m个任务
	//必然是每个机器先分别接受1个任务
	for(i=0;i<m;i++){
		s[i][0]=i;
		d[i]=d[i]+t[i];
		count[i]=1;
	}
	//之后判断哪个机器任务耗时最少，让其接受任务
	//尽可能地并行，平均分配任务
	for(i=m;i<n;i++){
		int min=d[0];
		k=0;
		for(j=1;j<m;j++){//确定空闲机器，实质是在求当期任务总时间最少的机器
			if(min>d[j]){
				min=d[j];
				k=j;//机器k空闲
			}
		}
		s[k][count[k]]=i;//在机器k的执行队列添加第i号任务
		count[k]=count[k]+1;//机器k的任务数+1
		d[k]=d[k]+t[i];//机器k的任务执行时间+t[i]，也就是+第i号任务的耗时		
	}
	
	for(i=0;i<m;i++){//确定完成所有任务需要的时间，实质是求分配完所有任务之后，耗时最多的机器
		if(max<d[i]){
			max=d[i];
		}			
	}
	printf("完成所有任务需要的时间：%d\n",max);
	printf("各个机器执行的耗时一览：\n");
	for(i=0;i<m;i++){
		printf("%d:",i);
		for(j=0;j<n;j++){
			if(s[i][j]==-1){
				break;
			}
			printf("%d\t",t[s[i][j]]);
		}
		printf("\n");
	}
}
void main(){//测试用例
	int time[7]={16,14,6,5,4,3,2};#include<stdio.h>
void main(){
	int a[4]={1,3,2,4};
	int max=a[0];
	for(int i=0;i<4;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	printf("%d",max);
}

		

//分治
#include<stdio.h>
int getMax(int array[], int begin, int end){
	int Max1 = 0;
	int Max2 = 0;
	if (begin == end) {//划分到最后，剩余1个数
		return array[begin] = array[end];
	}
	else if(begin+1==end){//划分到最后，剩余2个数
		return array[begin]> array[end]?array[begin]: array[end];//谁大返回谁。
	}
	else{//如果剩余的数多于2个，划分成两段，选出这两段的最大值
		int mid=(begin+end)/2;
		Max1=getMax(array,begin,mid);
		Max2=getMax(array,mid+1,end);
		return Max1>Max2?Max1:Max2;
	}
};
void main(){
	int a[4]={1,3,2,4};	
	printf("%d",getMax(a,0,3));
}







//随机化


#include <stdio.h>  
#include <stdlib.h>  
#include<time.h>  
void display(int array[], int maxlen)  
{  
    int i;  
    for(i = 0; i < maxlen; i++)  
    {  
        printf("%-3d ", array[i]);  
    }  
    printf("\n");  
    return ;  
}   
void swap(int *a, int *b)    
{  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
    return ;  
}  
void quicksort(int array[], int maxlen, int begin, int end)  
{  
    int i, j;  
  
    if(begin < end)  
    {  
        i = begin + 1;  
        j = end;       
            
        while(i < j)  
        {  
            if(array[i] > array[begin])  
            {  
                swap(&array[i], &array[j]);  
                j--;  
            }  
            else  
            {  
                i++;    
            }  
        }  
        if(array[i] >= array[begin]) 
        {  
            i--;  
        }  
        swap(&array[begin], &array[i]);  
          
        quicksort(array, maxlen, begin, i);  
        quicksort(array, maxlen, j, end);  
    }  
}  
int Partition(int *arr, int beg, int end)  
{  
    int j;  
    int sentinel = arr[end];  
    int i = beg-1;  
    for(j=beg; j <= end-1; ++j)  
    {  
        if(arr[j] <= sentinel)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i+1], &arr[end]);  
    return i+1;  
}    
int RandomPartition(int *arr, int beg, int end)  
{  
    int i = beg + rand() % (end-beg+1);  
    swap(&arr[i], &arr[end]);  
    return Partition(arr, beg, end);  
}  
void RandomQuickSort(int *arr, int beg, int end)  
{  
    if(beg < end)  
    {  
        int pivot = RandomPartition(arr, beg, end);  
        RandomQuickSort(arr, beg, pivot-1);    
        RandomQuickSort(arr, pivot+1, end);  
    }  
}  
// 主函数  
int main()  
{  
    clock_t start,end;
     double    duration;
    int n,i,array[100000];
    printf("请输入快排数组个数:");
    scanf("%d",&n);
    srand(time(NULL));//定义产生随机数组
    for(i=1;i<=n;i++)
    {
        array[i]=rand()%20000+1;
    }
    int maxlen=n;     
    //display(array, maxlen);  
     start=clock(); 
    quicksort(array, maxlen, 0, maxlen-1);  // 快速排序  
      end=clock(); 
       duration = (double)(end- start) / CLOCKS_PER_SEC;
     printf( "快排时间:%f seconds\n", duration ); 
    //display(array, maxlen);  
     srand(time(0));  
    for(i=0; i <n; i++)  
    {  
        array[i] = rand()%20000+1;       
    }  
    start=clock(); 
      RandomQuickSort(array, 0, n-1); 
       end=clock(); 
       duration = (double)(end- start) / CLOCKS_PER_SEC;
       printf( "随机化快排时间:%f seconds\n", duration );
       for(i=1;i<=n;i++)
    {
        array[i]=i;
    }
        start=clock(); 
    quicksort(array, maxlen, 0, n-1);  // 快速排序  
      end=clock(); 
       duration = (double)(end- start) / CLOCKS_PER_SEC;
     printf( "快排有序数组时间:%f seconds\n", duration);
      start=clock(); 
      RandomQuickSort(array, 0, n-1); 
       end=clock(); 
       duration = (double)(end- start) / CLOCKS_PER_SEC;
       printf( "随机化快排有序数组时间:%f seconds\n", duration );
        return 0;  
}  



// 回溯法四皇后
//
 
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define M 4
int queue[M] = { -1 };//用来保存4个皇后的列数
int count = 0;//方法总数
int issafe(int row, int column)//用于判断该位置是否安全
{
	for (int i = 0; i<row; i++)//遍历前面放置了皇后的行
	{
		if (queue[i] == column)return 0;//同一列不安全
		if ((row - i) == (column - queue[i]))return 0;//同一主对角线，行之差和列之差相等
		if ((row - i) + (column - queue[i]) == 0)return 0;//副对角线，行之差列之差的和为0
	}
	return 1;
}
 
void pickqueue(int num)  //递归
{
	//printf("序号num= %d\n", num);
    //------>1.循环
	for (int i = 0; i<M; i++)//遍历所有列数，找出能放的列 
	{
		//printf("皇后序号num= %d，列数i= %d\n", num, i);
        //------>2.满足条件
		if (issafe(num, i))//判断当前皇后放在哪列式安全的
		{
			//printf("==皇后序号num= %d，列数i= %d\n",num,i);
			queue[num] = i;//保存当前列数
			if (num == 3)//满4个皇后
			{
				count++;
				for (int j = 0; j < M; j++)
				{
					printf("%3d", queue[j]);
				}
				printf("\n");
			}
			int next = num + 1;
		//	printf("开始调用\n");
            //------>3.满足条件，递归调用下一个
			pickqueue(next);//下一个皇后
		}
	}
	//遍历完所有列数后都找不到位置，即说明上一个皇后需要重新放置
	if (num == 0)//若到退到0列都找不到合适位置，即返回
	{
		//printf("最后 \n");
		return;
	}
	else
	{
     //------>4.不满足条件，回溯
		
		queue[--num] = -1;//上一个皇后列数清除
        printf("清除上一个皇后序号num= %d \n", num);
	}
}
void main()
{
	pickqueue(0);//第一个皇后
	printf("总数为:%d", count);
	system("pause");
}

