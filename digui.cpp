#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110;
int n;
char start[N], aim[N];

void turn(int i)
{
	if (start[i] == '*') start[i] = 'o';
	else start[i] = '*';
}

int main()
{
	cin >> start >> aim;
	n = strlen(start);
	int res = 0;
	for (int i = 0; i <= n; i++)
	{
		if (start[i] != aim[i])
		{
			turn(i);
			turn(i + 1);
			res++;

		}
	}
	cout << res << endl;
	return 0;
}




#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
int n,m;
const int N = 30;
int way[N];

void dfs(int u,int start)
{
	if (u == m+1)
	{
		for (int i = 1; i <= m; i++)
		{
			printf("%d", way[i]);
			
		}
		puts("");
		return;
	}
	for (int i = start; i <= n; i++)
	{
		way[u] = i;
		dfs(u + 1, i + 1);
		way[u] = 0;
	}
}

int main()
{
	cin >> n >> m;

	dfs(1,1);
	return 0;
}




#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 16;
int n;
int st[N];

void dfs(int u)
{
	if (u > n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (st[i] == 1)
			{
				printf("%d ", i);
			}
		}
		puts("");
		return;
	}
	st[u] = 2;
	dfs(u + 1);
	st[u] = 0;

	st[u] = 1;
	dfs(u + 1);
	st[u] = 0;
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
}





#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
const int N = 10;
int state[N];
bool used[N];

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", state[i]);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            state[u] = i;
            used[i] = true;
            dfs(n + 1);
            //恢复现场
            state[u] = 0;
            used[i] = false;
        }

    }
}

int main()
{
    cin >> n;
    dfs(1);

    return 0;

}
