//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/519/B
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


    int n;
    scanf("%d", &n);

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (m.count(a))
            m[a]++;
        else
            m[a] = 1;
    }

    map<int, int> m2;
    n--;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (m2.count(a))
            m2[a]++;
        else
            m2[a] = 1;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        if (it->second != m2[it->first])
        {
            printf("%d\n", it->first);
            break;
        }
    m = m2;

    m2.clear();
    n--;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (m2.count(a))
            m2[a]++;
        else
            m2[a] = 1;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        if (it->second != m2[it->first])
        {
            printf("%d\n", it->first);
            break;
        }


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
