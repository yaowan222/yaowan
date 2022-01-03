#include <iostream>
using namespace std;
 
void GreedyChoose(int len,int *s,int *f,bool *flag);
 
int main(int argc, char* argv[])
{
	int s[11] ={1,3,0,5,3,5,6,8,8,2,12};
	int f[11] ={4,5,6,7,8,9,10,11,12,13,14};
 
	bool mark[11] = {0};
 
	GreedyChoose(11,s,f,mark);
	for(int i=0;i<11;i++)
		if(mark[i])
			cout<<i<<" ";
	system("pause");
	return 0;
}
 
void GreedyChoose(int len,int *s,int *f,bool *flag)
{
	flag[0] = true;
	int j = 0;
	for(int i=1;i<len;++i)
		if(s[i] >= f[j])
		{
			flag[i] = true;
			j = i;
		}
}



#include <iostream>
using namespace std;
 
void GreedyChoose(int len,int *s,int *f,bool *flag);
 
int main(int argc, char* argv[])
{
	int s[11] ={1,3,0,5,3,5,6,8,8,2,12};
	int f[11] ={4,5,6,7,8,9,10,11,12,13,14};
 
	bool mark[11] = {0};
 
	GreedyChoose(11,s,f,mark);
	for(int i=0;i<11;i++)
		if(mark[i])
			cout<<i<<" ";
	system("pause");
	return 0;
}
 
void GreedyChoose(int len,int *s,int *f,bool *flag)
{
	flag[0] = true;
	int j = 0;
	for(int i=1;i<len;++i)
		if(s[i] >= f[j])
		{
			flag[i] = true;
			j = i;
		}
}










#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
	int s[10] = {2,3,4,5,6,7,8,9,10,11};
	int f[10] = {3,5,7,6,9,8,12,10,13,15};
	int TotalLength = (3-2);                 
 
	for(int i=1,int j=0; i<10 ; ++i)
	{
		if(s[i] >= f[j])
		{
			TotalLength += (f[i]-s[i]);
			j = i;
		}
		else
		{
			if(f[i] <= f[j])
				continue;
			else
			{
				TotalLength += f[i] - f[j];
				j = i;
			}
		}
	}
 
	cout<<TotalLength<<endl;
	system("pause");
	return 0;
}








#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
	int array[10];
	for(int i=0;i<10;i++)
		cin>>array[i];
 
	int temp;
	for(i=0; i<=9 ; ++i)
		for(int j=0;j<10-1-i;j++)
			if(array[j] > array[j+1] )
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	for(i=0;i<10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
