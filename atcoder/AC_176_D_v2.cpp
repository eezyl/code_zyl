// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :
//   Date    :   2020/08/26
// =====================================================
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<vi> vvi;

#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { return b ? "true" : "false"; }
str ts(vector<bool> v) { str res; F0R(i,sz(v)) res += char('0'+v[i]); return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res; F0R(i,SZ) res += char('0'+b[i]); return res; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

const ll MOD = 1e9+7; // 998244353;
const int MX = 3e5+5;

int grid[1005][1005] = {};
int cost[1005][1005] = {};

void solve() {
    int H, W;
    cin >> H >> W;
    int Ch, Cw;
    cin >> Ch >> Cw;
    Ch--; Cw--;
    int Dh, Dw;
    cin >> Dh >> Dw;
    Dh--; Dw--;
    for (int i = 0; i < H; ++i) {
        str s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            if (s[j] == '#')
                grid[i][j] = 1;
            //cout << grid[i][j+1];
            cost[i][j] = INT_MAX;
        }
        //cout << endl;
    }

    deque<int> dx;
    deque<int> dy;
    cost[Ch][Cw] = 0;
    dx.pb(Ch);
    dy.pb(Cw);
    int count = 0;
    while (!dx.empty()) {
        ++count;
        int cx = dx.ft; dx.pop_front();
        int cy = dy.ft; dy.pop_front();
        if (cx == Dh && cy == Dw)
            break;
        grid[cx][cy] = 1;
        //cout << cx << " " << cy << endl;
        for (int i = 0; i < 4; ++i) {
            int nx = cx+d4i[i];
            int ny = cy+d4j[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] != 0)
                continue;
            ckmin(cost[nx][ny], cost[cx][cy]);
            dx.pf(nx);
            dy.pf(ny);
        }
        for (int nx = cx-2; nx <= cx+2; ++nx) {
            for (int ny = cy-2; ny <= cy+2; ++ny) {
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] != 0)
                    continue;
                ckmin(cost[nx][ny], cost[cx][cy]+1);
                dx.pb(nx);
                dy.pb(ny);
            }
        }
    }
    //cout << count << endl;
    if (cost[Dh][Dw] == INT_MAX)
        cout << "-1\n";
    else
        cout << cost[Dh][Dw] << endl;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define LOCAL
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
