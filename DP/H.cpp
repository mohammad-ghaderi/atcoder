#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int h, w;
    cin >> h >> w;

    string mp[h];
    for (int i = 0; i < h; i++) cin >> mp[i];

    int dp[h][w]{};
    dp[h - 1][w - 1] = 1;

    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (mp[i][j] == '#') continue;
            if (i > 0) dp[i - 1][j] = mod(dp[i - 1][j] + dp[i][j]);
            if (j > 0) dp[i][j - 1] = mod(dp[i][j - 1] + dp[i][j]);
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}