//写烦了直接百度了CSDN链接：https://blog.csdn.net/qq_40688707/article/details/79401804
//解题思路：众所周知二级制想转十六进制就毕业要有四位数列来转换。
//所有我们在一开始对字符串进行补0操作。然后开始四位四位的取二级制进行转换。 
//一开始想不通怎么解决16进制长度的问题看到大佬的代码瞬间茅塞顿开开窍了。
#include <bits/stdc++.h>
using namespace std;
#define N 10000
#define N2 4
char s[N + 5];
char convert[] = "0123456789ABCDEF";
int main()
{
    long n,len,digits,i,k;
    cin >> n;
    getchar();
    while(n--)
    {
        gets(s + N2);//给这个数组前面开出四个空间进行补零
        s[0] = s[1] = s[2] = s[3] = '0';
        len = strlen(s + N2); //二进制长度//(s + N2) 即为二进制长度，并不会在原来长度上加四，此时（s + N2）可以理解我 二进制的名字
        digits = (len + N2 - 1) / N2;//十六进制长度
        len += N2 - 1;//对二进制进行补位操作，因为最少是四个二进制变为一个16进制so最少补三位
        for(i = 1, k = len; i <= digits; i++)
        {
            s[k--] = convert[(s[len - 3] - '0')*8 + (s[len - 2] - '0')*4 + (s[len - 1] - '0')*2 + s[len] - '0'];//842就是进制转换中对应的权
            len -= N2;//每四个一转，所以len - 4
        }
        printf("%s\n",s+k+1);//或printf("%s\n",&s[k + 1]);这里要输出从s数组中从[k+1]项开始的所有数据，
    }
    return 0;
}
