class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


#include<iostream>
using namespace std;

int array[5] = { 1,2,3,4,5 };
int array[10] = {};
int length = 5;
int length2 = 10;

int  one( int array[], int value)
{
	value = array[0];
	int pos = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[i] < value)
		{
			value = array[i];
			pos = i;
		}
	}
	return value;
	array[pos] = array[length - 1];
	length--;
}

void three(int array[],int x)
{
	int k = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] == x)
		{
			k++;

		}
		else
		{
			array[i - k] = array[i];
		}
	}
	length = length - k;
}


bool four(int array[], int s, int t)
{
	int k = 0;
	if (length == 0 || s >= t)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (array[i]<t || array[i]>s)
		{
			k++;
		}
		else
		{
			array[i - k] = array[i];
		}
	}

}


void seven(int array1[], int array2[], int array[])
{
	int i = 0, j = 0, k = 0;
	while (i < length && j < length2)
	{
		if (array1[i] < array2[j])
		{
			array[k++] = array1[i++];
		}
		else
		{
			array[k++] = array2[j++];
		}
	}
	while (i < length)
	{
		array[k++] = array1[i++];
	}
	while (j < length2)
	{
		array[k++] = array2[j++];
	}
	length = length + length2;
}







PNODE create_list(void)
{
	int len;//用来存放有效节点的个数
	int i;
	int val;//用来临时存放用户输入的节点的值

	//分配了一个不存放有效数据的头节点
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(NULL==pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	printf("请输入您需要生成的链表节点的个数：len=");
	scanf("%d",&len);

	for (i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);

		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		if(NULL==pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data=val;//挂
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	return pHead;
}



#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;//数据域
	struct Node * pNext;//指针域
}NODE,*PNODE;//NODE等价于struct Node，PNODE等价于struct Node *
//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
	PNODE pHead=NULL;//等价于struct Node *pHead=NULL；
	pHead=create_list();//creat_list()功能：创建一个非循环单链表,并将该链表的头节点的地址付给pHead
	traverse_list(pHead);
	return 0;
}

PNODE create_list(void)
{
	int len;//用来存放有效节点的个数
	int i;
	int val;//用来临时存放用户输入的节点的值

	//分配了一个不存放有效数据的头节点
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(NULL==pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	printf("请输入您需要生成的链表节点的个数：len=");
	scanf("%d",&len);

	for (i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);

		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		if(NULL==pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data=val;//挂
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p=pHead->pNext;
	while(NULL!=p)
	{
		printf("%d ",p->data);	
		p=p->pNext;//不连续，不能用p++
	}
	printf("\n");
	return;
}
