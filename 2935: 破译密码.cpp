//一开始不理解END和这STAR有什么用写着写着就发现雀氏没有什么用 
//知道加密怎么写这题答案就出来了
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	char alpha[30];
  string strsta, str, strend;
	for(int i=0;i<26;i++)         //加密
	{
		if('A'+i-5<'A')
			alpha[i]='A'+i-5+26;
		else
			alpha[i]='A'+i-5;
	}
	while(1)                 //getchar()是为了吃掉结尾的换行不然你输入的第一个字符串就会消失
	{
		cin >> strsta;
    getchar();
		if(strsta == "ENDOFINPUT")
			break;
    getline(cin , str);
    getchar();
		int len=str.length();
		for(int i=0;i<len;i++)
		{
			if(isalpha(str[i]))
				printf("%c",alpha[str[i]-'A']);
			else
				printf("%c",str[i]);
		}
		putchar('\n');
		cin >> strend;
    getchar();
	}
	return 0;
}
