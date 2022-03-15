//今天值得纪念上传一段恶心人的代码 
#include <bits/stdc++.h>
using namespace std;
map<string, int> tian, gan, three, four, five;
string stian[] = {"jia", "yi",   "bing", "ding", "wu",
                  "ji",  "geng", "xin",  "ren",  "gui"};
string sgan[] = {"zi", "chou", "yin",  "mao", "chen", "si",
                 "wu", "wei",  "shen", "you", "xu",   "hai"};
string sthree[] = {"hi", "tsuki", "hoshi"};
string sfour[] = {"haru", "natsu", "aki", "fuyu"};
string sfive[] = {"ka", "mizu", "ki", "kin", "tsuchi"};
vector<string> tb;
void init() {
    for (auto& s : stian) tian[s] = &s - stian;
    for (auto& s : sgan) gan[s] = &s - sgan;
    for (auto& s : sthree) three[s] = &s - sthree;
    for (auto& s : sfour) four[s] = &s - sfour;
    for (auto& s : sfive) five[s] = &s - sfive;
}
const int offset = 3;
void cast(string& s1, string& s2) {
    int g = gan[s2], t = tian[s1];
    int val;
    for (int k = 0; k < 5; ++k) {
        if ((val = k * 12 + g) % 10 == t) break;
    }
    val += offset + 60, val %= 60;
    int v3 = val % 5, v2 = val % 4, v1 = val % 3;
    cout << sthree[v1] << ' ' << sfour[v2] << ' ' << sfive[v3] << endl;
}

void cast(string& s1, string& s2, string& s3) {
    int v1 = three[s1], v2 = four[s2], v3 = five[s3];
    int val;
    for (int k = 0; k < 12; ++k) {
        if ((val = k * 5 + v3) % 4 == v2 && val % 3 == v1) break;
    }
    val += -offset + 60, val %= 60;
    v1 = val % 10, v2 = val % 12;
    cout << stian[v1] << ' ' << sgan[v2] << endl;
}

int main() {
    init();
    int q, tp;
    cin >> q;
    while (q--) {
        string s1, s2, s3;
        cin >> tp;
        if (tp == 1) {
            cin >> s1 >> s2 >> s3;
            cast(s1, s2, s3);
        } else {
            cin >> s1 >> s2;
            cast(s1, s2);
        }
    }
    return 0;
}
