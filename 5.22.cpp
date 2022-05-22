#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define mem(a,x) memset(a,x,sizeof(a));
#define pb push_back
typedef long long ll;
const int N=1e3+10;
int n,m;
double a[N][N];
vector<int>g[N];
int ge[N];
int toint(string a)
{
	int ans=0;
	for(int i=0;a[i];i++)
	{
		if(a[i]>='0'&&a[i]<='9') ans=ans*10+a[i]-'0';
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	fir(i,1,m)
	{
		int t;cin>>t;
		while(t--)
		{
			string tt;cin>>tt;
			int ttt=toint(tt);
			if(tt[0]=='-') ge[ttt]=-1;
			else ge[ttt]=1;
			g[i].pb(ttt);
		}
	}
	string x,y;cin>>x>>y;
	int f1=0,f2=0;
	int xx=toint(x),yy=toint(y);
	if(x[0]=='-') f1=-1,f2=1;
	else f1=1,f2=-1;
	
	fir(i,1,m)
	{
		int f=0;
		for(auto u:g[i])
		{
			if(u==xx||u==yy) f=1;
		}
		vector<int>bo,gi;
		if(f)//有 
		{
			for(auto u:g[i])
			{
				if(ge[u]==1) bo.pb(u);
				else gi.pb(u);
			}
			for(auto u:bo)
				for(auto v:gi)
				{
					a[u][v]+=1.0/g[i].size();
					a[v][u]+=1.0/g[i].size();
				}						
		}
	}
		
	double max1=-1,max2=-1;
	fir(i,0,n-1)
		max1=max(max1,a[xx][i]);
	fir(i,0,n-1)
		max2=max(max2,a[yy][i]);
	
	if(max1==a[xx][yy]&&max2==a[yy][xx])
	{
		cout<<x<<" "<<y;return 0;
	}
	
	fir(i,0,n-1)
	{
		if(a[xx][i]==max1)
		{
			cout<<x<<" ";
			if(f1==1) cout<<"-";
			cout<<i<<endl;
		}
	}
	fir(i,0,n-1)
	{
		if(a[yy][i]==max2)
		{
			cout<<y<<" ";
			if(f2==1) cout<<"-";
			cout<<i<<endl;
		}
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
#define mem(a,x) memset(a,x,sizeof(a));
#define pb push_back
typedef long long ll;
const int N=1e4+10;
int v[N];int l,r;
map<int,int>mp,d;
void solve(int x)
{
	memset(v,0,sizeof(v));
	int xx=x;
	while(x!=1)
	{
		int y=0;
		while(x)
		{
			y+=((x%10)*(x%10));
			x/=10;
		}
		x=y;
		v[x]++;		
		if(v[x]==2) return;//死循环 
	}	
	x=xx;
	int t=0;
	while(x!=1)
	{
		mp[x]++;
		int y=0;
		while(x)
		{
			y+=((x%10)*(x%10));
			x/=10;
		}
		x=y;		
		t++;
	}
	d[xx]=t;
}
int isp(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	cin>>l>>r;
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		solve(i);
	}
	
	for(int i=l;i<=r;i++)
	{
		if(mp[i]==1)
		{
			cout<<i<<" ";
			int t=d[i];
			if(isp(i)) t*=2;
			cout<<t<<endl;
			ans++;
		}
	}
	if(!ans) cout<<"SAD";
	return 0;
}
