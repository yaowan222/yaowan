#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int calu(int num)
{
	int ans = 0;
	while(num)
	{
		if(num%10==2)
			ans++;
		num/=10;
	}
	return ans;
}
int main()
{
	int cnt = 0;
	for(int i = 1; i <=2020; i++)
	{
		cnt+=calu(i);
	}
	cout << cnt <<endl;
	return 0;
} 


#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
	int ans = 0;
	for(int i = 1; i <= 2020; i++)
	{
		for(int j = 1; j <= 2020; j++)
		{
			if(gcd(i,j)==1)
			{
				ans++;
			}
		}
	}
	cout << ans <<endl;
	return 0;
}




#include<iostream>

using namespace std;

int main()
{
	//首先计算第20行20列位于三角形第几行，用公式算出是2*20-1=39行
	//计算39行的最后一个数 
	int n = 20;
	n = n*2-1;
	int ans = 0,sum =  0;
	for(int i = 1; i <=n ;i++)
	{
		sum+=i; 
	} 
	ans = (sum+sum-n+1)/2;
	cout << ans <<endl;
	return 0;
	 
} 




#include<iostream>

using namespace std;
int run(int year)
{
	return (year%400==0)||(year%4==0&&year%100!=0);
}
int main()
{
	int monNum = 0,weekNum = 0,monWeek = 0,days = 0,ans = 0;
	int monDay[13] = {0,31,30,31,30,31,30,31,31,30,31,30,31};
	for(int i = 2000; i <= 2020; i++)
	{
		//闰年处理 
		if(run(i)) 
			monDay[2] = 29;
		else 
			monDay[2] = 28;
		//计算总天数和月份 
		for(int j = 1; j <= 12; j++)
		{
			if(i==2020&&j==10) break;
			monNum += 1;
			days+=monDay[j];
			if((days+1)%7==3)
			{
				monWeek++;
			}
			
		}
	} 
	weekNum += days/7;
	if(days%7>=3) 
		weekNum++;
	//cout << days+1 << ends << weekNum <<ends << monNum+1 << ends << monWeek <<endl;
	ans = days+1 + weekNum +monNum+1 - monWeek;
	cout << ans <<endl;


	return 0;
}



#include<iostream>

using namespace std;

int main()
{
	int n = 10000;
	int run = 600/60;//每秒的消耗 
	int time = 0;
	while(n)
	{
		
		if(n-600 <0)
		{
			time  = time*60+n/run;
			break;
		}
		n-=600;
		n+=300;
		time+=2;
	}
	cout << time;
	return 0;
} 
