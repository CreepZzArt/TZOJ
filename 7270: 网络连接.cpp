//其实题目不难但ERR条件的判断太多了，很多可能考虑不到 
//很多条件要判断 
//举个例子
//1.符合'.'和符号':'的个数可能会出现少或多的情况
//2.':'和'.'出现的位置可能会互换出现:在前.在后的情况(这是看洛谷大佬知道的)
//3.'.' 或':' 后面没有数字（比如有负号，或者直接没有数字)
//其他就是比较常规的判断，比如题目要求的前导0，数字范围。但长度我是没想到的
#include <bits/stdc++.h>
using namespace std;
int Maxor(int Max, string s) {
    int x = 0;
    if (s.size() == 0 || s.size() > 5) return -1;       //避免数字太长，x存不下。
    if (s[0] == '0' && s.size() > 1) return -1;         //不能有前导0
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') return -1;        //判断是不是数字如(92.-153.1.1)
        x = x * 10 + s[i] - '0';
    }
    if (x >= 0 && x <= Max) return x;  //数字范围是否合法
    return -1;
}
int check(string s) {
    int onedot = 0, towdot = 0, x = 0;
    vector<int> d;
    string t = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') {
            onedot++;
            x = Maxor(255, t);
            t = "";
            if(x == -1) return 1;
            d.push_back(x);

        } else if(s[i] == ':') {
            if(onedot != 3) return 2;
            towdot++;
            x = Maxor(255, t);
            t = "";
            if(x == -1) return 1;
            d.push_back(x);
        } else {
            t += s[i];
        }
    }
    if(onedot != 3 || towdot != 1) return 8;
    x = Maxor(65535, t);
    if(x == -1) return 1;
    d.push_back(x);
    if(d.size() != 5) return 5;
    return 0;
}
map<string, int> List;
int main(){
    int n, c1 = 0;
    string TEXT, IP;
    cin >> n;
    while(n--) {
        cin >> TEXT >> IP;
        c1++;
        int flag = check(IP);
        if(flag) {     //当flag != 0时说命不符合规范。
            cout << "ERR\n";
        } else {
            if(TEXT == "Server") {
                if(List[IP] == 0) {
                    cout << "OK\n";
                    List[IP] = c1;
                } else {
                    cout << "FAIL\n";
                }
            }
            else if(TEXT == "Client"){
                if(List[IP] == 0) {
                    cout << "FAIL\n";
                } else {
                    cout << List[IP] << "\n";
                }
            }
        }
    }
}
