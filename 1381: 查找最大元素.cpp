//会写判断就可以1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[105];
    while (cin >> a){
        int len = strlen(a);
        int max = 0;
        char maxn = a[0];
        for (int i = 0; i < len; ++i) {
            if(a[i] > maxn){
                maxn = a[i];
            }
        }
        for (int i = 0; a[i] != '\0'; ++i) {
            if(a[i] != maxn){
                cout << a[i];
            }else{
                cout  << a[i]<< "(max)";
            }
        }
        cout << "\n";
    }
}
