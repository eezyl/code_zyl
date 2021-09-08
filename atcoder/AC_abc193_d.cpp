// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template v2.2
//   Address :
//   Date    :   2021/02/27
// =====================================================
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<db> vdb;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pdb> vpdb;
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

#define rep(i,x,y) for (int i = (x); i < (y); ++i)
#define repr(i,y,x) for (int i = (y-1); i >= (x); --i)
#define trav(a,x) for (auto& a: x)

const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

// TO_STRING
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
string ts(bool b) { return b ? "true" : "false"; }
string ts(vector<bool> v) { string res; rep(i,0,sz(v)) res += char('0'+v[i]); return res; }
template<size_t SZ> string ts(bitset<SZ> b) { string res; rep(i,0,SZ) res += char('0'+b[i]); return res; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

// BIT
const int TX = 1;
int tree[1];
int sum(int k, int a = 0) { while (k >= 1) { a += tree[k]; k -= k&-k; } return a; }
void add(int k, int x) { while (k <= TX) { tree[k] += x; k += k&-k; } }
// Disjoint Set
int find(vi& ds, int i) { return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]); }
void join(vector<int> &ds, int a, int b) {
    int i = find(ds, a), j = find(ds, b);
    if (i != j) {
        if (ds[i] > ds[j]) swap(i, j);
        ds[i] += ds[j]; ds[j] = i; }
}




const ll MOD = 998244353; // 998244353;
const int MX = 1e5+5;

bool can_win(string& str1, string& str2) {
    vi card1(10, 0);
    trav(c, str1)
        card1[c-'0']++;
    int score1 = 0;
    rep(i, 1, 10) {
        score1 += i * pow(10, card1[i]);
    }

    vi card2(10, 0);
    trav(c, str2)
        card2[c-'0']++;
    int score2 = 0;
    rep(i, 1, 10) {
        score2 += i * pow(10, card2[i]);
    }
    return score1 > score2;
}

void solve()
{
    double K;
    cin >> K;
    vll card(10, K);
    string str1, str2;
    cin >> str1 >> str2;
    double total_card = 9*K-8;
    rep(i, 0, 4) {
        card[str1[i]-'0']--;
        card[str2[i]-'0']--;
    }
    double prob = 0.0;
    rep(i, 1, 10) {
        str1[4] = i+'0';
        rep(j, 1, 10) {
            str2[4] = j+'0';
            if (can_win(str1, str2)) {
                if (i != j) {
                    prob += card[i]*card[j] / total_card / (total_card-1);
                } else {
                    prob += card[i] * (card[i]-1) / total_card / (total_card-1);
                }
            }
        }
    }
    printf("%.6f\n", prob);

}

int main()
{
//#define LOCAL
#ifndef LOCAL
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
#ifdef LOCAL
    freopen("data.in", "r", stdin); while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    //cin >> t;
    while (t--) solve();

#ifdef LOCAL
    }    printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
