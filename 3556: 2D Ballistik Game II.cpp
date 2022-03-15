//来着台州学院新生有奖月赛
//对每列的和进行判断大小保留最小
//被题目里面的多种情况坑了不然直接就AC了!
#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[50][50];
    int m, n;
    while (cin >> m >> n){      //多种情况
        int min0 = 210000000, ans = 0;
        for (int i = 0; i < m; ++i) {         //如果你基础足够好你完全可以在输入这里就做一个判断
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        //核心判断
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if(a[i][j] == 'A'){
                    ans++;
                    continue;
                }
                if(a[i][j] == 'B'){
                    ans += 2;
                    continue;
                }
                if(a[i][j] == 'C'){
                    ans += 3;
                    continue;
                }
            }
            min0 = min(min0, ans);
            ans = 0;
        }
        cout << min0 <<endl;
    }
    //总结：题目简单需要对二维数组有详细的了解
}
