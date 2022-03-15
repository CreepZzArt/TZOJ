//2≤n≤L≤R≤109,暴力就会死想都不用想
//所有只要判断在不在这个区间就好 
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, L, R;
    cin >> n >> L >> R;
    if (L / n != R / n) cout << n - 1;
    else cout << R % n;
    return 0;
}
