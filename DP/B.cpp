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

void solve() {

    int n, k;
    cin >> n >> k;
    int h[n]{};
    int dp[n + 1]{};

    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) dp[i] = inf;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j >= n) break;
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }

    cout << dp[n - 1] << endl;

}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    while (t--) solve();

    return 0;
}