#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int inf = 1e9;


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;

    int a[n], b[n], c[n], dp[3][n];

    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < n; i++) dp[0][i] = inf, dp[1][i] = inf, dp[2][i] = inf;
    
    dp[0][0] = a[0], dp[1][0] = b[0], dp[2][0] = c[0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    }

    cout << max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);
    return 0;
}