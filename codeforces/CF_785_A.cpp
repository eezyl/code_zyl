//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/785/A
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

    int n;
    scanf("%d", &n);
/*
    char* Tetrahedron = "Tetrahedron";
    char* Cube = "Cube";
    char* Octahedron = "Octahedron";
    char* Dodecahedron = "Dodecahedron";
    char* Icosahedron = "Icosahedron";

    int ans = 0;
    char str[20];
    for (int i = 0; i < n; i++) {
        scanf(" %s", str);
        if (!strcmp(str, Tetrahedron))
            ans += 4;
        else if (!strcmp(str, Cube))
            ans += 6;
        else if (!strcmp(str, Octahedron))
            ans += 8;
        else if (!strcmp(str, Dodecahedron))
            ans += 12;
        else if (!strcmp(str, Icosahedron))
            ans += 20;
    }
*/
    map<string, int> m;
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;

    int ans = 0;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        ans += m[str];
    }

    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
