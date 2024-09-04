#include <bits/stdc++.h>
using namespace std;

// Shortened types
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Constants
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

// Utility functions
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (b); i-- > (a); )

// Input and Output
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;

// Function to read multiple inputs
template<typename T>
void read(T& t) { cin >> t; }

template<typename T, typename... Args>
void read(T& t, Args&... args) { cin >> t; read(args...); }

// Function to print multiple outputs
template<typename T>
void print(T t) { cout << t << '\n'; }

template<typename T, typename... Args>
void print(T t, Args... args) { cout << t << ' '; print(args...); }

#define N 1000005
int a[N], b[N];

void solve(){

    int n,m,k;
    read(n,m,k);
    rep(i, 0, n) read(a[i]);
    rep(i, 0, m) read(b[i]);

    // take a as smaller array
    if (n > m)
    {
        swap(a, b);
        swap(n, m);
    }
    sort(a, a + n);
    sort(b, b + m);

    int l = a[0] + b[0], r = a[n - 1] + b[m - 1];
    int ans = a[0] + b[0];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = upper_bound(b, b + m, mid - a[i]) - b;
            cur += x;
        }
        if (cur >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    print(ans);
}
// Main function
int main() {
    fast_io();
    
    int t;
    read(t);
    while(t--) {
        solve();
    }
    
    
    
    return 0;
}
