//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/122/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

bool is_lucky(int num)
{

    bool flag = true;
    while (num != 0)
    {
        int d = num % 10;
        if (d != 4 && d != 7)
            flag = false;
        num = num / 10;
    }
    return flag;
}

int main()
{
    int num;
    scanf("%d", &num);
    vector<int> div;

    for (int i = 1; i <= 1000; i++)
        if (is_lucky(i))
            div.push_back(i);

    for (int i = 0; i < div.size(); i++)
        if (num % div[i] == 0)
        {
            printf("YES\n");
            return 0;
        }

    printf("NO\n");
    return 0;
}
