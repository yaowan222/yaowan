#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<math.h>

using namespace std;

char s[1001];
int num[10] = { 0,0,0,0,0,0,0,0,0,0 };

int main()
{
    
    cin >> s;
    
    int len = sizeof(s);

    for (int i = 0; i < len; i++)
    {
        num[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++)
        if (num[i])
            printf("%d:%d\n", i, num[i]);

    return 0;
}






#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c;
	int m = sqrt((n+1) / 2);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < (2*(m-i) - 1); j ++)
		{
			cout << c;
		}
		cout << endl;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < m - i-1; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << c;
		}
		cout << endl;
	}
	cout << n - 2 * m * m + 1;
	return 0;
}




#include <stdio.h>
int main()
{
    int n, a[20], index = 1;
    char c[11][6] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    scanf("%d", &n);
    if (n < 0)
    {
        printf("fu ");
        n = -n;
    }
    a[0] = n % 10;
    while (n / 10 > 0)//存各个位数上的数字
    {
        n /= 10;
        a[index++] = n % 10;
    }
    for (int i = index - 1; i > 0; i--)
        printf("%s ", c[a[i]]);
    printf("%s", c[a[0]]);

    return 0;
}





#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include <iomanip>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int count = 0,sum=0;
	for (int i = n; i <=m; i++)
	{
		sum += i;
		cout << setw(5) << i;
		count++;
		if (count % 5 == 0)
		{
			cout << endl;
		}
	}
	if (count % 5 != 0)
		printf("\n");
	cout << "Sum = " << sum << endl;
	return 0;
}





#include<bitsdc++.h>
using namespace std;

int n=3;
int a[3];
int main()
{
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3);
    cout<<a[0]<<"->"<<a[1]<<"->"<<a[2]<<endl;
    return 0;
}




#include<bitsdc++.h>
using namespace std;
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    int a[10];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(is_prime(a[i])==1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
