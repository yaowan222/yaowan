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





#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define pb push_back
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
const int N=1e5+10;
int n,head;
int v[N],ne[N];
struct node
{
	int now,v,ne;
};
vector<node>a,ans;
int main()
{
	cin>>head>>n;
	fir(i,1,n)
	{
		int t;cin>>t;
		cin>>v[t]>>ne[t];
	}
	int p=head;
	while(p!=-1)
	{
		node temp={p,v[p]};
		a.pb(temp);
		p=ne[p];
	}
	int i=0,j=a.size()-1;
	while(1)//这里不能是i!=j 否则若只有一个就无法输出 
	{
		ans.pb(a[j]);	
		if(j==i) break;//奇数	
		ans.pb(a[i]);
		j--;
		if(j==i) break;//偶数 
		i++;
	}
	for(int i=0;i<ans.size();i++)
	{
		if(i!=ans.size()-1) ans[i].ne=ans[i+1].now;
		else ans[i].ne=-1;
	}
	for(auto x:ans)
	{
		if(x.ne!=-1) printf("%05d %d %05d\n",x.now,x.v,x.ne);
		else printf("%05d %d -1\n",x.now,x.v);
	}
	return 0;
}
