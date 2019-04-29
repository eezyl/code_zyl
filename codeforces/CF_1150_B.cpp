//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1150/B
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
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                //cout << i << " " << j << endl;
                if (i+1 < n) {
                    if (j-1 < 0 || board[i+1][j-1] == '#') {
                        printf("NO\n");
                        return 0;
                    } else
                        board[i+1][j-1] = '#';

                    if (board[i+1][j] == '#') {
                        printf("NO\n");
                        return 0;
                    } else
                        board[i+1][j] = '#';

                    if (j+1 >= n || board[i+1][j+1] == '#') {
                        printf("NO\n");
                        return 0;
                    } else
                        board[i+1][j+1] = '#';

                } else {
                    printf("NO\n");
                    return 0;
                }
                if (i+2 < n && board[i+2][j] == '.')
                    board[i+2][j] = '#';
                else {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
