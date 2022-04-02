#include <iostream>
#include <algorithm>
using namespace std;
int a[3][10000],b[100001];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i];
        b[i]=a[0][i]*3600+a[1][i]*60+a[2][i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        cout<<b[i]/3600<<" "<<b[i]%3600/60<<" "<<b[i]%3600%60<<endl;
    }
    return 0;
}




void Work(int a[],int n)
{
    int ans = 0;
    for(int i=0;i<n;i++)
        ans ^= a[i];
    int t1 = ans;
    int t2 = ans;
    int cnt = 0;
    while(!(t1 & 1))
    {
        t1 >>= 1;
        cnt++;
    }
    for(int i=0;i<n;i++)
    {
        if((a[i] >> cnt) & 1)
            ans ^= a[i];
    }
    int x = ans;
    int y = ans ^ t2;
    if(x > y) swap(x,y);
    cout<<x<<" "<<y<<endl;
}







void  Merge(List *list1, List *list2)  
{ 
    Node *p, *q, *r, *last;
    p = list1->next;  
    q = list2->next;
    last = list1;
    last->next = NULL;
    while(p && q) 
    {  
        if(p->data < q->data) 
        {
            r = p;
            p = p->next;
        }
        else 
        {
            r = q;
            q = q->next;
        }
        r->next = last->next;
        last->next = r;
        last = r;
    }
    if(p) last->next = p;    
    else  last->next = q;
    list2->next = NULL;
}







#include<bits/stdc++.h>
using namespace std;
int team[20][6];
int vis[20];
int max_sum = 0;
void dfs(int index, int sum){
	if(index == 6){
		max_sum = max(max_sum, sum);
		return;
	}
	for(int i = 0; i < 20; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(index + 1, sum + team[i][index]);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("team.txt", "r", stdin);
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 6; j++)
			cin>>team[i][j];
	dfs(1, 0);
	cout<<max_sum<<endl;
	return 0;
}




#include<bits/stdc++.h>
using namespace std;
int main(){
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ans[5];
	int index = 0;
	int n = 2019;
	while(n){
		int t = n % 26;
		n = n / 26;
		ans[index] = str[t - 1];
		index++; 
	}
	for(int i = index - 1; i >= 0; i--){
		cout<<ans[i];
	}
	return 0;
}

