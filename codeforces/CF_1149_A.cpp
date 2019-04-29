//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1149/A
//   Date    :   2019/04/29
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

    int n;
    scanf("%d", &n);
    vector<int> count(3, 0);
    for (int i = 0; i < n; i++)  {
        int num;
        scanf("%d", &num);
        count[num]++;
    }

    if (count[1] == 0) {
        for (int i = 0; i < count[2]; i++)
            printf("2 ");
        printf("\n");
    }
    /*
    else if (count[1] == 1) {
        if (count[2] == 0) {
            printf("1\n");
        } else {
            printf("2 1 ");
            count[2]--;
            for (int i = 0; i < count[2]; i++)
                printf("2 ");
            printf("\n");
        }
    }*/
     else {
        if (count[2] == 0) {
            for (int i = 0; i < count[1]; i++)
                printf("1 ");
            printf("\n");
        } else {
            printf("2 1 ");
            count[2]--;
            count[1]--;
            for (int i = 0; i < count[2]; i++)
                printf("2 ");
            for (int i = 0; i < count[1]; i++)
                printf("1 ");
            printf("\n");
        }
    }


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
