#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int N, W;
    cin >> N >> W;

    int w[N + 1], v[N + 1];

    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    int dp[N + 1][W + 1]{};

    for (int j = 1; j <= W; j++) {
        for (int i = 1; i <= N; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (w[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[N][W];

    return 0;
}