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

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    bool dp[k + 1][2]{};

    for (int c = 0; c <= k; c++) {
        for (int i = 0; i < n; i++) {
            if (c + a[i] > k) continue;
            dp[c + a[i]][0] |= !dp[c][1];
            dp[c + a[i]][1] |= !dp[c][0];
        }
    }

    cout << (dp[k][0]?"First":"Second") << endl;
    return 0;
}