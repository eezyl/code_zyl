//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1182/C
//   Date    :   2019/06/11
//
//********************************************************

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int n;
    scanf("%d", &n);
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    map<pair<int, char>, vector<string> > dict;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        char last_vowel = 'a';
        int vowel_num = 0;
        for (int j = 0; j < str.size(); ++j)
            if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u') {
                vowel_num++;
                last_vowel = str[j];
            }
        auto it = dict.find(make_pair(vowel_num, last_vowel));
        if (it == dict.end()) {
            vector<string> v;
            v.push_back(str);
            dict[make_pair(vowel_num, last_vowel)] = v;
        } else
            it->second.push_back(str);
    }
    vector<string> ans_line1_1;
    vector<string> ans_line1_2;
    vector<string> ans_line2_1;
    vector<string> ans_line2_2;
    for (auto it: dict) {
        s.insert(it.first.first);
        //cout << it.first.first << " " << it.first.second << " " << it.second.size() << endl;
    }
    //cout << "aaa" << endl;
    for (auto i: s) {
        //cout << i << endl;
        string fi;
        for (int j = 0; j < 5; ++j) {
            //cout << j << endl;
            auto it = dict.find(make_pair(i, vowels[j]));
            if (it != dict.end()) {
                if (it->second.size() % 2) { // odd number
                    if (fi.empty())
                        fi = it->second.back();
                    else {
                        ans_line1_1.push_back(fi);
                        ans_line2_1.push_back(it->second.back());
                        fi.clear();
                    }
                }
                for (int k = 0; k < it->second.size(); k+=2) {
                    if (k+1 < it->second.size()) {
                        ans_line1_2.push_back(it->second[k]);
                        ans_line2_2.push_back(it->second[k+1]);
                    }
                }
            }
        }
    }
    //cout << "bbb" << endl;
    //cout << ans_line1_1.size() << " " << ans_line2_2.size() << endl;
    int ans = ans_line2_2.size() ;
    int diff = 0;
    if (ans_line2_2.size() > ans_line1_1.size()) {
        ans = (ans_line2_2.size() + ans_line1_1.size())/2;
        diff = ans_line2_2.size()-ans;
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++) {
        if (i < ans_line1_1.size()) {
            cout << ans_line1_1[i] << " " << ans_line1_2[i] << "\n";
            cout << ans_line2_1[i] << " " << ans_line2_2[i] << "\n";
        }
        else {
            cout << ans_line1_2[i+diff] << " " << ans_line1_2[i] << "\n";
            cout << ans_line2_2[i+diff] << " " << ans_line2_2[i] << "\n";
        }
    }




#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
