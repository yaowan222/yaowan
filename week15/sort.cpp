class Sort
{
public:
	Sort(int a[], int n);
	~Sort();
	void BubbleSort();//冒泡排序
	void QuickSort(int l, int r);//快速排序
	void InsertSort();//插入排序
	void ShellSort();//希尔排序
	void heapsort1();//大根堆
	void heapsort2();//小根堆
	void MergeSort1(int first, int last);//归并排序
	void BucketSort(int a[], int n);//桶排序
	void Counting_Sort(int r[], int n);//计数排序

	void print();
private:
	int* data;
	int length;
	int Partition(int first, int last);//快速排序，一次划分
	void sift1(int k, int last);//堆排序，堆调整
	void sift2(int k, int last);//堆排序，堆调整
	void Merge(int first1, int last1, int last2);//归并排序，合并相邻有序序列
};


Sort::Sort(int a[], int n)
{
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];

	}
	length = n;
	
}


Sort::~Sort()
{
	delete[]data;

}


void Sort::print()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i]<<"\t";
	}
	cout << endl;
}


void Sort::BubbleSort()
{
	int j, exchange, bound, temp;
	exchange = length - 1; //第一趟起泡排序的区间是[0~length-1]
	while (exchange != 0)
	{
		bound = exchange; exchange = 0;
		for (j = 0; j < bound; j++) //一趟起泡排序的区间是[0~bound]
			if (data[j] > data[j + 1]) {
				temp = data[j]; data[j] = data[j + 1]; data[j + 1] = temp;
				exchange = j; //记载每一次记录交换的位置
			}
	}
}



int Sort::Partition(int first, int last)
{
	int i = first, j = last, temp; //初始化一次划分的区间
	while (i < j)
	{
		while (i < j && data[i] <= data[j]) j--; //右侧扫描
		if (i < j) {
			temp = data[i]; data[i] = data[j]; data[j] = temp;
			i++;
		}
		while (i < j && data[i] <= data[j])
			i++; //左侧扫描
		if (i < j) {
			temp = data[i]; data[i] = data[j]; data[j] = temp;
			j--;
		}
	}
	return i; // i为轴值记录的最终位置
}



void Sort::QuickSort(int l, int r)
{
	/*int first = *(data + l);
	int last = *(data +  - 1);*/
	if (l >= r)
		return; //区间长度为1，递归结束
	else
	{
		int pivot = Partition(l, r); //一次划分
		QuickSort(l, pivot - 1); //对左侧子序列进行快速排序
		QuickSort(pivot + 1, r); //对右侧子序列进行快速排序
	}
}


void Sort::InsertSort()
{
	int i,j;
	int temp;
	for(i = 1; i < length; i++)
	{
		temp = data[i];
		for(j = i-1; j >= 0 && temp < data[j]; j--)
			data[j+1] = data[j];
		data[j+1] = temp;
	}
}



void Sort::ShellSort()
{
	int d;
	int i, j;
	int temp;
	for (d = length + 1; d >= 1; d = d / 2)
	{
		for (i = d; i < length; i++)
		{
			temp = data[i];
			for (j = i - d; j >= 0 && temp < data[j]; j = j - d)
				data[j + d] = data[j];
			data[j + d] = temp;
		}
	}
}




void Sort::sift1(int k, int last)  //大根堆的实现
{
	int i, j, temp;
	i = k; j = 2 * i + 1;
	while (j <= last)
	{
		if (j < last && data[j] < data[j + 1])
			j++;
		if (data[i] > data[j])	break;
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i = j; j = 2 * i + 1;
		}
	}
}


void Sort::sift2(int k, int last)  //小根堆的实现
{
	int i, j, temp;
	i = k; j = 2 * i + 1;
	while (j <= last)
	{
		if (j < last && data[j] > data[j + 1])
			j++;
		if (data[i] < data[j])	break;
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i = j; j = 2 * i + 1;
		}
	}
}


void Sort::heapsort1()  //大根堆的重建
{
	int i, temp;
	for (i = ceil(length / 2) - 1; i >= 0; i--)
	{
		sift1(i, length - 1);
	}
	for (i = 1; i < length; i++)
	{
		temp = data[0];
		data[0] = data[length - i];
		data[length - i] = temp;
		sift1(0, length - i - 1);
	}
}


void Sort::heapsort2()  //小根堆的重建
{
	int i, temp;
	for (i = ceil(length / 2) - 1; i >= 0; i--)
	{
		sift2(i, length - 1);
	}
	for (i = 1; i < length; i++)
	{
		temp = data[0];
		data[0] = data[length - i];
		data[length - i] = temp;
		sift2(0, length - i - 1);
	}
}


void Sort::Merge(int first1, int last1, int last2)
{
	int* temp = new int[length]; //数组temp作为合并的辅助空间
	int i = first1, j = last1 + 1, k = first1;
	while (i <= last1 && j <= last2)
	{
		if (data[i] <= data[j])
			temp[k++] = data[i++]; //取较小者放入temp[k]
		else
			temp[k++] = data[j++];
	}
	while (i <= last1) //对第一个子序列进行收尾处理
		temp[k++] = data[i++];
	while (j <= last2) //对第二个子序列进行收尾处理
		temp[k++] = data[j++];
	for (i = first1; i <= last2; i++) //将合并结果传回数组r
		data[i] = temp[i];
	delete[] temp;
}


void Sort::MergeSort1(int first, int last)
{
	if (first == last)
		return; //待排序序列只有1个记录，递归结束
	else {
		int mid = (first + last) / 2;
		MergeSort1(first, mid); //归并排序前半个子序列
		MergeSort1(mid + 1, last); //归并排序后半个子序列
		Merge(first, mid, last); //将两个已排序的子序列合并
	}
}


/*桶排序*/
void Sort::BucketSort(int a[], int n)
{
	int max = a[0];//假设最大为a[0]
	for (int x = 1; x < n; x++)//遍历比较，找到大的赋值给max
	{
		if (a[x] > max)
			max = a[x];
	}
	int temp = max + 1;
	int* tmp = new int[temp];//获得空桶大小
	int i, j;
	for (i = 0; i < temp; i++)//空桶初始化
		tmp[i] = 0;
	for (i = 0; i < n; i++)//寻访序列，放到对应的桶中
		tmp[a[i]]++;
	for (i = 0, j = 0; i < temp; i++)
	{
		while (tmp[i] != 0)//对每个非空桶进行排序
		{
			a[j] = i;//从不是空的桶子里把项目再放回原来的序列中。i为索引,数组的索引位置表示值
			j++;
			tmp[i]--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
}



/*计数排序*/
void Sort::Counting_Sort(int r[], int n)//假设数组中存储的都是非负整数 
{
	if (n <= 1)
	{
		return;
	}
	int max = r[0];
	for (int i = 1; i < n; i++)//寻找数组的最大值 
	{
		if (r[i] > max)
		{
			max = r[i];
		}
	}
	int* c = (int*)malloc(sizeof(int) * (max + 1));//定义一个计数数组, 统计每个元素的个数，向系统申请内存空间
	memset(c, 0, sizeof(int) * (max + 1));//调用函数初始化，数组清零
	for (int a = 0; a < n; a++)
	{
		c[r[a]]++;
	}
	for (int b = 1; b <= max; b++)//对计数数组累计求和 
	{
		c[b] = c[b] + c[b - 1];
	}
	int* p = (int*)malloc(sizeof(int) * n);//临时存放排好序的数据  
	for (int m = n - 1; m >= 0; m--)//倒序遍历数组，将元素放入正确的位置
	{
		p[c[r[m]] - 1] = r[m];
		c[r[m]]--;
	}
	for (int q = 0; q < n; q++)
	{
		r[q] = p[q];
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = r[i];
	}
}




/*基数排序*/
Node* RadixSort(Node* first, int d)//d是记录的最大位数
{
	Node* front[10], * rear[10], * tail = nullptr;//tail用于首尾相接时指向队尾
	int i, j, k, base = 1;//base是被除数
	for (i = 1; i <= d; i++)//进行d趟基数排序
	{
		for (j = 0; j < 10; j++)
			front[j] = rear[j] = NULL;//清空每一个队列
		while (first != NULL)//分配，将记录分配到队列中
		{
			k = (first->data / base) % 10;
			if (front[k] == NULL) front[k] = rear[k] = first;
			else rear[k] = rear[k]->next = first;
			first = first->next;
		}
		for (j = 0; j < 10; j++)//收集，将队列首尾相接
		{
			if (front[j] == NULL) continue;
			if (first == NULL) first = front[j];
			else tail->next = front[j];
			tail = rear[j];
		}
		tail->next = NULL;//收集后单链表加尾标志
		base = base * 10;
	}
	return first;
}
Node* Creat(int r[], int n)
{
	Node* first = new Node;//生成头结点
	first->data = r[0];
	Node* p = first, * s = NULL;//尾指针初始化
	for (int i = 1; i < n; i++)
	{
		s = new Node; s->data = r[i];
		p->next = s; p = s;//将结点s插入到终端结点之后
	}
	p->next = NULL;//单链表建立完毕，将终端结点的指针域置空
	return first;
}
void Print(Node* first)
{
	Node* p = first;//工作指针p初始化
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;//工作指针p后移，注意不能写作p++
	}
	cout << endl;
}






int* RandomArray(int n, int rangeL, int rangeR)
{
	int* arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	}
	return arr;
}


void Bubble(double a[], int size)
{
	int i, j,  flag;
	double t;
	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size -i- 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t=a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 1;
			}
		}
	}
}

int main()
{
	cout << "----------排序算法比较课程设计----------" << endl;
	cout << "将要被排序的数字数量:";
	int n;
	cin >> n;
	int *a=RandomArray(n, 0, 1000);
	//int b[] = { 0 };
	int* b = new int[n];
	for(int i=0;i<n;i++)
	{ 
		b[i] = a[i];
	}
	//Sort A(RandomArray(n, 0, 100), n);
	Sort A(b, n);
	cout << "初始顺序为:" << endl;
	A.print();
}
