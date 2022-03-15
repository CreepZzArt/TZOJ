//只要你会分解，这题对你来说就是小意思 
#include <iostream>
#include <cstring>
using namespace std;
int b[10], sum = 0;
int split_number(int n)         //分解存入数组的函数
{
    int i = 0;
    while(n)
    {
        b[i++]=n%10;
        n=n/10;
    }
}
int main() {
    int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, n;
    cin >> n;
    split_number(n);
    for (int i = 0; i < 3; ++i) {   //遍历每一位数
        sum += a[b[i]];
    }
    cout << sum;
    return 0;
}
