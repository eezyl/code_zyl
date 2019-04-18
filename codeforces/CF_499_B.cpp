//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/499/B
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

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
#include <unordered_map>
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n, m;
    scanf("%d %d", &n, &m);
    unordered_map<string, string> ma;
    string str1, str2;
    for (int i = 0; i < m; i++) {
        cin >> str1 >> str2;
        if (str1.size() <= str2.size()) {
            ma[str1] = str1;
            ma[str2] = str1;
        }
        else {
            ma[str1] = str2;
            ma[str2] = str2;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> str1;
        cout << ma[str1] << " ";
    }
    cout << endl;

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
