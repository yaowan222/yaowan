#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define pb push_back
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
const int N=1e5+10;
int n,head;
map<int,int>mp;
int a[N],ne[N];//某个地址的键值、下一个地址 
struct node
{
	int v,d;
};
vector<node>ans1,ans2;
int main()
{
	cin>>head>>n;
	fir(i,1,n)
	{
		int t;cin>>t;
		cin>>a[t]>>ne[t];
		//不能直接cin>>t>>a[t]>>ne[t]
		//因为不回车是输入不进t的（？） 
	}
	int p=head;	
	//关键
	while(p!=-1)
	{		
		if(mp[abs(a[p])]==0)
		{
			ans1.pb({a[p],p});
			mp[abs(a[p])]=1;
		}
		else
		{
			ans2.pb({a[p],p});
		}
		p=ne[p];
	}
	//后面都是输出，注意格式即可
	int t=0;
	printf("%05d %d",ans1[0].d,ans1[0].v);
	for(auto x:ans1)
	{
		if(t)
		{
			printf(" %05d\n",x.d);
			printf("%05d %d",x.d,x.v);
		}
		t++;
	}
	cout<<" "<<-1<<endl;
	if(ans2.size())
	{
		t=0;
		printf("%05d %d",ans2[0].d,ans2[0].v);
		for(auto x:ans2)
		{
			if(t)
			{
				printf(" %05d\n",x.d);
				printf("%05d %d",x.d,x.v);
			}
			t++;
		}
		cout<<" "<<-1<<endl;
	}
	return 0;
}





#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define pb push_back
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
const int N=1e5+10;
int n;
string a;
int main()
{
	getline(cin,a);
	int ans=1;
	for(int i=0;a[i];i++)
	{
		//a[i]是中轴 
		int t=1;
		int j1=i-1,j2=i+1;
		while(j1>=0&&j2<a.size()&&a[j1]==a[j2])
		{
			j1--;j2++;
			t+=2;
		}
		ans=max(ans,t);
		
		//无中轴
		t=0;
		j1=i,j2=i+1;
		while(j1>=0&&j2<a.size()&&a[j1]==a[j2])
		{
			j1--;j2++;
			t+=2;
		 } 
		 ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}







#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define pb push_back
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
const int N=1e5+10;
int n,m,m1,m2;
double a[N],b[N],c[N];//a[i]表示该指数对应的系数 
int main()
{
	cin>>n;
	//指数 系数
	fir(i,1,n)
	{
		int x,y;cin>>x>>y;
		m1=max(x,m1);
		a[x]=y;
	} 
	cin>>m;
	fir(i,1,m)
	{
		int x,y;cin>>x>>y;
		m2=max(x,m2);
		b[x]=y;
	} 
	
	int t1=m1,t2=m2;
	
	//核心 
	while(t1>=t2)
	{
		double tt=a[t1]/b[t2];
		c[t1-t2]=tt;
		for(int i=t1,j=t2;j>=0;j--,i--) a[i]-=b[j]*tt;//核心中核心 
		while(abs(a[t1])<0.000001) t1--;//如果系数是0就不参加运算——否则会TLE 
	}
	
	int f=0,sum1=0;
	for(int i=0;i<=m1;i++)
	{				
		if(c[i]>=0.05||c[i]<=-0.05) //找最大的系数 
		{
			f=i;
			sum1++;
		}
	} 
	
	if(sum1)
	{
		cout<<sum1;
		for(int i=f;i>=0;i--)
		{			
			if(c[i]>=0.05||c[i]<=-0.05) printf(" %d %.1f",i,c[i]);
		}
	}
	else printf("0 0 0.0");
	
	int ff=0,sum2=0;
	for(int i=0;i<=m2;i++)
	{		
		if(a[i]>=0.05||a[i]<=-0.05) //找最大的系数 
		{
			ff=i;
			sum2++;
		}
	} 
	cout<<endl;
	
	if(sum2)
	{
		cout<<sum2;
		for(int i=ff;i>=0;i--)
		{			
			if(a[i]>=0.05||a[i]<=-0.05) printf(" %d %.1f",i,a[i]);
		}
	}
	else printf("0 0 0.0");
	return 0;
}





#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define pb push_back
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
const int N=1e5+10;
int n;double z,r;
vector<int>g[N];
int d[N];//得道 
double a[N];
double anss;
struct node
{
	double v;
	int u;
};
void bfs()
{
	queue<node>q;
	q.push({z,0});
	while(q.size())
	{
		node temp=q.front();
		q.pop();
		
		if(g[temp.u].size())
		{
			for(auto x:g[temp.u])
			{
				node t={temp.v*r,x};
				a[x]=temp.v*r;
				q.push(t);
			}
		}
		else
		{
			anss+=temp.v*d[temp.u];
		}		
	}
}
int main()
{
	cin>>n>>z>>r;
	r=100-r;
	r*=0.01;
	
	fir(i,0,n-1)
	{
		int k;cin>>k;
		if(!k)
		{
			cin>>d[i];
		}
		while(k--)
		{
			int t;cin>>t;
			g[i].pb(t);
		}
	}
	
	a[0]=z;
	bfs();	

	cout<<(int)anss;
	return 0;
}
