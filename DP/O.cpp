#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 21;
int n;
int memo[SIZE][(1<<SIZE)]{};
bool m[SIZE][SIZE]{};

int dp(int i, int mask) {
    if (i == n and mask == (1 << n)-1) return 1;
    if (i == n) return 0;
    if (~memo[i][mask]) return memo[i][mask];

    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (!(mask & (1 << j)) and m[i][j]) {
            ans += dp(i + 1, mask | (1 << j));
            ans = mod(ans);
        }
    }

    return memo[i][mask] = ans;
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < n; j++) cin >> x, m[i][j] = (x == 1);
    }

    memset(memo, -1, sizeof memo);

    cout << dp(0, 0) << endl;

    return 0;
}