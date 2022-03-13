#include <iostream>
using namespace std;
int main()
{
	int n,m,x=1,sum=0;
	cin>>n>>m;
	int array[n];
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		array[i]=a;
		
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			sum+=array[j];
			x++;
			if(sum=m)
			{
				cout<<x;
			}
			if(sum>m)
			{
				break;
			}
		}
	
	}
	if(sum=0)
	{
		cout<<0;
	}
	
	return 0;
 } 



#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<n;i++)
	{
		int x=1;
		for(j=i-1;j>=1;j--)
		{
			int sum=j,k=j;
			while(k)
			{
				sum+=k%10;
				k/=10;
			}
			if(sum==i)
			{
				x=0;
				break;
			}
		}
		if(x==1)
		{
			cout<<i<<endl;
		}
	}
	return 0;
}



#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if(n<k)
	{
		cout<<2;	
	}
	else
	{
		if(n*2%k==0)
		{		
			int a=n*2/k;
			cout<<a;
		}
		else
		{
			int b=n*2/k+1;
			cout<<b;
		}
	}
	
	return 0;
}




#include <iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int t=2,sum=s[0]-'0';
		for(;t<=4;t++)
		{
			sum+=(s[t]-'0')*t;
		}
		t++;
		for(;t<=10;t++)
		{
			sum+=(s[t]-'0')*(t-1);
		}
		t++;
		
		sum=sum%11;
		if(sum==10&&s[t]=='X')
		{
			cout<<"Right"<<endl;
		}
		else
		{
			if(sum==s[t]-'0')
			{
				cout<<"Right"<<endl;
			}
			else
			{
				if(sum==10)
				{
					s[t]='X';
					cout<<s<<endl;
				}
				else
				{
					s[t]=sum+'0';
					cout<<s<<endl;
				}
			}
		}
	}
	return 0;
}
