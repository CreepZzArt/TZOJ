//一道结构体排序，看懂结构体基本上就没问题了 
#include<iostream>
#include<algorithm>
#include<cstring>
#pragma GCC optimize(2)
#define ll long long
using namespace std;
struct mate{
	string name;
	int F,IQ;
}a[200000];
int cmpF(mate a, mate b){
	if(a.F == b.F){
		if(a.IQ == b.IQ){
			return a.name < b.name;	
		}else{
			return a.IQ > b.IQ;	
		}
			
	}else{
		return a.F > b.F;
	}
}
int cmpIQ(mate a, mate b){
	if(a.IQ == b.IQ){
		if(a.F == b.F){
			return a.name < b.name;	
		}else{
			return a.F > b.F;	
		}
			
	}else{
		return a.IQ > b.IQ;
	}
}
int main(){
	ll n, ans = 1;
	while(cin >> n){
		ans = 1;
		for(int i = 1;i <= n;i++){
			cin >> a[i].name >> a[i].F >> a[i].IQ;
		}
		sort(a + 1,a + n + 1,cmpF);
		for(int i = 1;i<=n;i++){
			if(a[i - 1].F == a[i].F && a[i - 1].IQ == a[i].IQ /*&& i < n*/){
				cout << ans << " " << a[i].name << " " << a[i].F << " " << a[i].IQ << endl;
			}else{
				ans = i;
				cout << ans << " " << a[i].name << " " << a[i].F << " " << a[i].IQ << endl;
			}
		}
		cout << "\n";
		sort(a + 1,a + n + 1,cmpIQ);
		ans = 1;
		for(int i = 1;i<=n;i++){
			if(a[i - 1].IQ == a[i].IQ && a[i - 1].F == a[i].F /*&& i < n*/){
				cout << ans << " " << a[i].name << " " << a[i].F << " " << a[i].IQ << endl;
			}else{
				ans = i;
				cout << ans << " " << a[i].name << " " << a[i].F << " " << a[i].IQ << endl;
			}
		}
	}

}
