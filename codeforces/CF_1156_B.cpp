//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1156/B
//   Date    :   2019/05/01
//
//********************************************************

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <stack>
#include <bitset>


using namespace std;

typedef long long LL;

const int INF = 1 << 25;
const LL LL_INF = 1ll << 61;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int T;
    scanf("%d", &T);
    while (T--) {
        string str;
        cin >> str;
        string ori_str = str;
        vector<int> ch(150, 0);
        for (int i = 0; i < str.size(); i++) {
            ch[str[i]]++;
        }
        sort(str.begin(), str.end());
        str.resize(unique(str.begin(), str.end()) - str.begin());
        //cout << str << endl;
        if (str.size() == 2) {
            if (str[1] - str[0] == 1) {
                printf("No answer\n");
                continue;
            }
            for (int i = 0 ; i < str.size(); i++) {
                for (int j = 0; j < ch[str[i]]; j++)
                    printf("%c", str[i]);
            }
            printf("\n");

        }  else if (str.size() == 3) {
            if (str[1] - str[0] == 1 && str[2] - str[1] == 1) {
                printf("No answer\n");
                continue;
            }
            if (str[1] - str[0] == 1) {
                swap(str[0], str[1]);
                swap(str[1], str[2]);
            } else if (str[2] - str[1] == 1)
                swap(str[0], str[1]);
            for (int i = 0 ; i < str.size(); i++) {
                for (int j = 0; j < ch[str[i]]; j++)
                    printf("%c", str[i]);
            }
            printf("\n");
        } else if (str.size() == 1) {
            cout << ori_str << endl;
            continue;
        } else {
            string new_order = str;
            new_order[0] = str[2];
            new_order[1] = str[0];
            new_order[2] = str[3];
            new_order[3] = str[1];
            for (int i = 5; i < str.size(); i++) if (i%2==1) {
                new_order[i] = str[i];
                swap(new_order[i], new_order[(i+1)%5]);
            }

            for (int i = 0 ; i < new_order.size(); i++) {
                for (int j = 0; j < ch[new_order[i]]; j++)
                    printf("%c", new_order[i]);
            }
            printf("\n");
        }
    }


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
