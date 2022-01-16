#include <stdio.h>

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int array[], int x, int y) {
    int key  = array[x];
    array[x] = array[y];
    array[y] = key;
}

// 从大到小排序
// void Down(int array[], int i, int n) {
//     int child = 2 * i + 1;
//     int key   = array[i];
//     while (child < n) {
//         if (child + 1 < n && array[child] > array[child + 1]) {
//             child++;
//         }
//         if (key > array[child]) {
//             swap(array, i, child);
//             i = child;
//         } else {
//             break;
//         }
//         child = child * 2 + 1;
//     }
// }

// 从小到大排序
void Down(int array[], int i, int n) { // 最后结果就是大顶堆
    int parent = i;                    // 父节点下标
    int child  = 2 * i + 1;            // 子节点下标
    while (child < n) {
        if (child + 1 < n && array[child] < array[child + 1]) { // 判断子节点那个大，大的与父节点比较
            child++;
        }
        if (array[parent] < array[child]) { // 判断父节点是否小于子节点
            swap(array, parent, child);     // 交换父节点和子节点
            parent = child;                 // 子节点下标 赋给 父节点下标
        }
        child = child * 2 + 1; // 换行，比较下面的父节点和子节点
    }
}

void BuildHeap(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
        Down(array, i, size);                 // 否则有的不符合大顶堆定义
    }
}

void HeapSort(int array[], int size) {
    printf("初始化数组：");
    BuildHeap(array, size); // 初始化堆
    display(array, size);   // 查看初始化结果
    for (int i = size - 1; i > 0; i--) {
        swap(array, 0, i); // 交换顶点和第 i 个数据
                           // 因为只有array[0]改变，其它都符合大顶堆的定义，所以可以从上往下重新建立
        Down(array, 0, i); // 重新建立大顶堆

        printf("排序的数组：");
        display(array, size);
    }
}

int main() {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49, 10};
    int size    = sizeof(array) / sizeof(int);

    // 打印数据
    printf("%d \n", size);
    printf("排序前数组：");
    display(array, size);
    HeapSort(array, size);

    return 0;
}







#include<iostream>
using namespace std;
void quickSort(int a[], int m,int n);
int partion(int a[], int m, int n);
int main()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int m = 0;
	int n = (sizeof(a) / 4)-1;
	quickSort(a, m,n);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
}
 
void quickSort(int a[], int m, int n)
{
	if (m < n)
	{
		int q = partion(a, m, n);
		quickSort(a, m, q );
		quickSort(a, q + 1, n);
	}
}
int partion(int a[], int m, int n)
{
	int key=m;
	int j= n,i=m;
	int temp1, temp2;
	while (i != j)
	{
		while (a[j] > a[key] && i < j)
		{
			--j;
		}
		
		while ((a[i] < a[key]) && (i < j))
		{
			++i;
		}if (i < j)
		{
			temp1 = a[j];
			a[j] = a[i];
			a[i] = temp1;
		}
	}
		temp2 = a[key];
		a[key] = a[i];
		a[i] = temp2;
		return i;
}







/**
* name:基数排序
* time:15/8/16 15:00
* environment: ubuntu 14.04， sublime text 3
*/
#include <iostream>
using namespace std;
 
/*
* 打印数组
*/
void printArray(int array[],int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
/*
*求数据的最大位数,决定排序次数
*/
int maxbit(int data[], int n) 
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int tmp[n];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
}
 
int main()
{
	int array[10] = {73,22,93,43,55,14,28,65,39,81};
	radixsort(array,10);
	printArray(array,10);
	return 0;
}
 







#include <iostream>
#include <vector>
using namespace std;
void countSort(vector<int>& arr)
{
    int len = arr.size();
    if(len == 0)
        return;
    //这里需要一个原始的数组拷贝
    vector<int> tempArr(arr.begin(),arr.end());
    //查找min，max
    int min = tempArr[0],max = min;
    for(int i=1;i<len;++i)
    {
        if(min>tempArr[i])
            min = tempArr[i];
        if(max<tempArr[i])
            max = tempArr[i];
    }

	//计算k值
    const int k = max-min+1;
    int count[k]={0};
    for(int i=0;i<len;++i)
        ++count[tempArr[i]-min];//这里需要一个偏移量min，因为数组是从下标0开始的，统计次数
    for(int i=1;i<k;++i)
        count[i] +=count[i-1];//后面的键值出现的位置为前面所有键值出现的次数之和，也就是每个数所在的范围

	//这里是逆序排序，这个和我们统计每个数字出现的位置有关系，
	//比如0出现了3次，加上之前-1出现的次数，就是4。
	//我们倒序排序第一个key值为0的时候，那么在count中的大小应该是4，那么它在arr数组的下标就该是4-1，count自减1为3
	//排序第二个key值为0的时候，count为3，在arr数组的下标是3-1
    for(int i=len-1;i>=0;--i)
        arr[--count[tempArr[i] - min]] = tempArr[i]; 
        //这里--count[tempArr[i] - min]很精简
        //又解决了下标需要减1的问题，对应的count数组中的值也减1

}

int main()
{
    vector<int> arr{-1,3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4,
                    7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    countSort(arr);
    for(auto value:arr)
        cout<<value<<" ";
    cout<<endl;
    return 0;
}
