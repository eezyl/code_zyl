//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/490/A
//   Date    :   2019/04/18 (upload date)
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

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL


    vector<int> P;
    vector<int> M;
    vector<int> PE;

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            P.push_back(i);
            break;
        case 2:
            M.push_back(i);
            break;
        case 3:
            PE.push_back(i);
            break;
        }
    }
    int ans = min(P.size(), M.size());
    ans = min(ans, (int)PE.size());

    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
        printf("%d %d %d\n", P[i], M[i], PE[i]);





    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
