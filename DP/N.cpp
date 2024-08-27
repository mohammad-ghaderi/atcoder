#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 404;
const int inf = 1e18;

int dp[SIZE][SIZE][2]{};


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) for (int j = i; j <= n; j++) dp[i][j][0] = dp[i][j][1] = inf;
    for (int i = 0; i < n; i++) cin >> dp[i][i][0], dp[i][i][1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                int sm1 = dp[i][k][0] + dp[k + 1][j][0];
                int sm2 = dp[i][k][1] + dp[k + 1][j][1];
                if (dp[i][j][1] > sm1 + sm2) {
                    dp[i][j][0] = sm1;
                    dp[i][j][1] = sm1 + sm2;
                }
            }
        }
    }

    cout << dp[0][n - 1][1] << endl;

    return 0;
}