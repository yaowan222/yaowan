#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(1){
		cout << "10进制：";
		cin >> n;
		if(n==-1) break; 
		stack<int> st;
		while(n){
			int a=n%8;
			n/=8;
			st.push(a);
		}
		cout << "8进制：";
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
	return 0;
}





#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	stack<char> st;
	int f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('||s[i]=='[') st.push(s[i]);
		else{
			if(st.empty()) f=0;
			else if((s[i]==')'&&st.top()!='(')||(s[i]==']'&&st.top()!='[')) f=0;
			else if((s[i]==')'&&st.top()=='(')||(s[i]==']'&&st.top()=='[')){
				st.pop();
			}
		}
	}
	
	if(!st.empty()) f=0;
	
	cout << f << endl;
	return 0;
}




#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> v;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) v.push_back(i);
		int add=1;
		while(v.size()>3){
			
			if(add==1){
				for(int i=1;i<v.size();i++){
					v.erase(v.begin()+i,v.begin()+i+1);
				}
				add=2;
			}
			else{
				for(int i=2;i<v.size();i+=2){
					v.erase(v.begin()+i,v.begin()+i+1);
				}
				add=1;
			}
			
		}
		
		for(int i=0;i<v.size();i++){
			if(!i) cout << v[i];
			else cout << ' ' << v[i];
		}
		cout << endl;	 
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin >> n&&n){
		set<string> s1,s2;
		string a,b;
		while(n--){
			cin >> a >> b;
			s1.insert(a);
			s1.insert(b);
			s2.insert(b);	
		}
		if(s1.size()-s2.size()==1) cout << "Yes" << endl;
		else cout << "No" << endl;

	}
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
int main(){//注意多组数据输入 
	int n;
	while(cin >> n){
		map<string,int> shop;//运用map ，一种映射 
		map<string,int>::iterator it;//迭代器 
		for(int i=1;i<=n;i++){
			string s;
			cin >> s;
			shop[s]=0;//可有可无，默认是0 
		}
		
		int day;
		cin >> day;
		while(day--){
			int a;
			string s;
			for(int i=1;i<=n;i++){
				cin >> a >> s;
				shop[s]+=a;//在迭代器中加入增加的值	
			} 
			
			//开始运用迭代器循环找出memory第几名
			int rank=1;//记录排名 
			for(it=shop.begin();it!=shop.end();it++){
				if(it->second>shop["memory"]) rank++; 
			} 
			cout << rank << endl;
		} 
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
int main(){//注意多组数据输入 
	int n;
	while(cin >> n){
		map<string,int> shop;//运用map ，一种映射 
		map<string,int>::iterator it;//迭代器 
		for(int i=1;i<=n;i++){
			string s;
			cin >> s;
			shop[s]=0;//可有可无，默认是0 
		}
		
		int day;
		cin >> day;
		while(day--){
			int a;
			string s;
			for(int i=1;i<=n;i++){
				cin >> a >> s;
				shop[s]+=a;//在迭代器中加入增加的值	
			} 
			
			//开始运用迭代器循环找出memory第几名
			int rank=1;//记录排名 
			for(it=shop.begin();it!=shop.end();it++){
				if(it->second>shop["memory"]) rank++; 
			} 
			cout << rank << endl;
		} 
	}
	return 0;
}
