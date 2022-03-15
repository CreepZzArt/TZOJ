#include <bits/stdc++.h>
#pragma GCC optimize(2) 
#define ll long long
using namespace std;
int main()
{
    string name[100];
    string str1[35], str2;
    int n, m, k, len, ans = 0;
    cin >> n >>m;
    for (int i = 0; i < n * m; ++i) {
        cin >> name[i];
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> str1[i];
    }
    for (int i = 0; i < n * m; ++i) {
        if(name[i] != "null"){
            /*len = name[i].length();                 //这里原本想着是xiao21然后把21割掉在判断是否相等结果似乎不如人意所有我注释掉了这里再次上传结果Ac
            basic_string<char>str2=name[i].substr(0,len - 2);*/
            str2 = name[i];
            for (int j = 0; j < k; ++j) {
                if(str2 == str1[j] + "21"){
                    ans++;
                    str1[j] = "";
                }
            }
        }
    }
    if(ans == k){
        cout << "Study hard!\n";
    }else{
        for (int i = 0; i < k; ++i) {
            if(str1[i] != ""){
                cout << str1[i] <<endl;
            }
        }
    }

}
