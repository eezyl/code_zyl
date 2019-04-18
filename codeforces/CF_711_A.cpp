//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/711/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL


    int n;
    scanf("%d", &n);
    vector<string> v(n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!ans && v[i][0] == 'O' && v[i][1] == 'O')
        {
            v[i][0] = v[i][1] = '+';
            ans = 1;
        }
        if (!ans && v[i][3] == 'O' && v[i][4] == 'O')
        {
            v[i][3] = v[i][4] = '+';
            ans = 1;
        }
    }

    if (ans)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        cout << v[i] << endl;
    }
    else
        printf("NO\n");






    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
