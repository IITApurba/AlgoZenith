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
#define per(i, a, b) for (int i = (b); i-- > (a);)

// Input and Output
#define fast_io()                \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;

// Function to read multiple inputs
template <typename T>
void read(T &t) { cin >> t; }

template <typename T, typename... Args>
void read(T &t, Args &...args)
{
    cin >> t;
    read(args...);
}

// Function to print multiple outputs
template <typename T>
void print(T t) { cout << t << '\n'; }

template <typename T, typename... Args>
void print(T t, Args... args)
{
    cout << t << ' ';
    print(args...);
}

int n;
int k;
int arr[100100];

bool check(int x)
{
    int cnt = 0, i;

    for (i = 0; i < x; i++)
    {
        //Count the number of 
        if (arr[i] == 0)
            cnt++;
    }
    //If number of zero is less than k then it fine 
    if (cnt <= k)
        return true;
    for (i = x; i < n; i++)
    {
        if (arr[i - x] == 0)
            cnt--;
        if (arr[i] == 0)
            cnt++;
        if (cnt <= k)
            return true;
    }
    return false;
}

void solve()
{

    read(n, k);

    rep(i, 0, n)
    {
        read(arr[i]);
    }

    // Binary search over all possible answers
    int lo = k;
    int hi = n;
    int ans = k;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    print(ans);
}
// Main function
int main()
{
    fast_io();

    int t;
    read(t);
    while (t--)
    {
        solve();
    }

    return 0;
}