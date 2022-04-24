#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c>d)
    {
        if(c>=b&&d<a)
        {
            cout<<c<<"-Y "<<d<<"-Y"<<endl;
            cout<<"qing 1 zhao gu hao 2"<<endl;
        }
        else if(c>=b&&d>=b)
        {
            cout<<c<<"-Y "<<d<<"-Y"<<endl;
            cout<<"huan ying ru guan"<<endl;
        }
        else if(c<a&&d<a)
        {
            cout<<c<<"-N "<<d<<"-N"<<endl;
            cout<<"zhang da zai lai ba"<<endl;
        }
        else if(c>=a&&c<b&&d<a)
        {
            cout<<c<<"-Y "<<d<<"-N"<<endl;
            cout<<1<<": huan ying ru guan"<<endl;
        }
    }
    
    if(c<d)
    {
        if(d>=b&&c<a)
        {
            cout<<c<<"-Y "<<d<<"-Y"<<endl;
            cout<<"qing 2 zhao gu hao 1"<<endl;
        }
        else if(d>=b&&c>=b)
        {
            cout<<c<<"-Y "<<d<<"-Y"<<endl;
            cout<<"huan ying ru guan"<<endl;
        }
        else if(d<a&&c<a)
        {
            cout<<c<<"-N "<<d<<"-N"<<endl;
            cout<<"zhang da zai lai ba"<<endl;
        }
        else if(d>=a&&d<b&&c<a)
        {
            cout<<c<<"-N "<<d<<"-Y"<<endl;
            cout<<2<<": huan ying ru guan"<<endl;
        }
    }
    return 0;
    
}




#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*f(n-1);
    }
}

int main()
{
    int a,b,c;
    cin>>a>>b;
    c=a+b;
    cout<<f(c)<<endl;
    return 0;
}







#include<bits/stdc++.h>
using namespace std;

int b=6,c=6,d=6,e=6,f=6,g=6;


int main()
{   
    int a[6],z[6];
    
    int n;
    for(int i=0;i<6;i++)
    {
        cin>>a[i];
    }
    cin>>n;
    
    for(int i=0;i<6;i++)
    {
    	z[i]=a[i];
	}
    
    
    //
	int aa(int n)
	{
		for(int k=b;k>0;k--)
    	{
        	if(n==k||n==z[0]) continue;       
	        else
			{
				n=k;
				b--;
				break;
			}                         
   		}
    	return n;
	}


	int cc(int n)
	{
		for(int k=c;k>0;k--)
  	  {
    	    if(n==k||n==z[1]) continue;
    	    else
			{
				n=k;
				c--;
				break;
			}                         
    	}
    	return n;
	}

	int dd(int n)
	{
		for(int k=d;k>0;k--)
    	{
        	if(n==k||n==z[2]) continue;
        	else
			{
				n=k;
				d--;
				break;
			}                         
    	}
    	return n;
	}

	int ee(int n)
	{
		for(int k=e;k>0;k--)
    	{
        	if(n==k||n==z[3]) continue;
        	else
			{
				n=k;
				e--;
				break;
			}                         
    	}
    	return n;
	}

	int ff(int n)
	{
		for(int k=f;k>0;k--)
    	{
        	if(n==k||n==z[4]) continue;
        	else
			{	
				n=k;
				f--;
				break;
			}                         
    	}
    	return n;
	}

	int gg(int n)
	{
		for(int k=g;k>0;k--)
    	{
        	if(n==k||n==z[5]) continue;
        	else
			{
				n=k;
				g--;
				break;
			}                         
    	}
    	return n;
	}

    //
    
    
    
    for(int i=0;i<n;i++)
    {
    	a[0]=aa(a[0]);
    	
	}
	cout<<a[0]<<" ";
    
    for(int i=0;i<n;i++)
    {
    	a[1]=cc(a[1]);
    	
	}
	cout<<a[0]<<" ";
	
	for(int i=0;i<n;i++)
    {
    	a[2]=dd(a[2]);
    	
	}
	cout<<a[2]<<" ";
	
	for(int i=0;i<n;i++)
    {
    	a[3]=ee(a[3]);
    	
	}
	cout<<a[3]<<" ";
	
	for(int i=0;i<n;i++)
    {
    	a[4]=ff(a[4]);
    	
	}
	cout<<a[4]<<" ";
	
	for(int i=0;i<n;i++)
    {
    	a[5]=gg(a[5]);
    	
	}
	cout<<a[5];
    
    
    
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
        {
        	a[j]=f(a[j]);
            for(int k=6;k>0;k--)
            {
                if(a[j]==k) continue;
                else
				{
					a[j]=k;
					break;
				}                         
            }
        }
    }*/
    /*for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[5];*/
    return 0;
}



#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int max(int n,int m)
{
    if(n>m) return n;
    else return m;
}
int main()
{
	string n,m,x="",y="";
	cin>>n>>m;
    //int l1=strlen(n),l2=strlen(m);
    for(int i = 1; i < 10000; i++)
    {
        if (n[i] % 2 == n[i-1] % 2)
        {
            x += max(n[i], n[i-1]);
        }
    }
    for(int i = 1; i < 10000; i++)
    {
        if (m[i] % 2 == m[i-1] % 2)
        {
            y += max(m[i], m[i-1]);
        }
    }
    if(x==y)
    {
        cout<<x<<endl;
    }
    else
    {
        cout<<x<<endl;
        cout<<y<<endl;
    }
    /*int index=0;
    string n="abc";
    for(int i=0;i<100;i++)
	{
		if(n[i]!='\0')
		{
			index++;
		}
	 } 
	 cout<<index;*/
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
void change(int n)
{
    if(n==0)
    {
        n=1;
    }
    else n=1;
}
int main()
{
    int n,m,q,index=0,x,y;
    cin>>n>>m>>q;
    int a[100][100]={0};
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        if(x==0)
        {
            for(int i=0;i<m;i++)
            {
                a[y-1][i]=1;
            }
        }
        if(x==1)
        {
            for(int i=0;i<n;i++)
            {
                a[i][y-1]=1;
            }
        }
        else continue;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                index++;
            }
        }
    }
    cout<<index;
    
    return 0;
}
