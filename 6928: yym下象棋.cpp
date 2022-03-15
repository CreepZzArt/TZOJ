//"不考虑黑或红，且数据保证不存在拌马脚的情况",不需要特判撇马脚所有这题目很简单只要判断8个点有没有棋子有 
//例如H放置在矩阵的（i，j）位置上，其他棋子只要放置在矩阵的（i-2，j+1），（i-1，j+2），（i+1，j+2），（i+2，j+1），（i+2，j-1），（i+1，j-2），（i-1，j-2），（i-2，j-1）
//之中的一个位置上就加一;
#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[17][17] = {""}, x;
    int ansX, ansY, i, j, sex = 0;
    //有了思路我们就扩展棋盘这样就不需要判断马在角落了只要棋盘够大就好
    //但会增加代码长度酌情考虑
    for (int i = 0; i <= 17; ++i) {
        for (int j = 0; j <= 17; ++j) {
            a[i][j] = '.';
        }
    }
    for (i = 3; i <= 11; ++i) {
        for (j = 3; j <=11; ++j) {
            cin >> x;
            a[i][j] = x;
            if(x == 'H'){
                ansX = i;
                ansY = j;
            }
        }
    }
    //判断位置是否有棋子
    if(a[ansX - 2][ansY + 1] != '.'){
        sex++;
    }
    if(a[ansX - 1][ansY + 2] != '.'){
        sex++;
    }
    if(a[ansX + 1][ansY + 2] != '.'){
        sex++;
    }
    if(a[ansX + 2][ansY + 1] != '.'){
        sex++;
    }
    if(a[ansX + 2][ansY - 1] != '.'){
        sex++;
    }
    if(a[ansX + 1][ansY - 2] != '.'){
        sex++;
    }
    if(a[ansX - 1][ansY - 2] != '.'){
        sex++;
    }
    if(a[ansX - 2][ansY - 1] != '.'){
        sex++;
    }
    cout << sex;



}
