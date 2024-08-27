#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 3003;

int dp[SIZE][SIZE][2]{};

int n;

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) dp[i][j][0] = dp[i][j][1] = 0;

    for (int i = 0; i < n; i++) dp[i][i][0] = a[i], dp[i][i][1] = -a[i];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
            dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]); 
        }
    }

    cout << dp[0][n - 1][0] << endl;
    return 0;
}