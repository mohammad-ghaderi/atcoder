#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 1e5 + 5;
int n, m;

vector<int> g[SIZE]{};
bool vis[SIZE]{};
int dep[SIZE]{};

int dfs(int u) {
    if (vis[u]) return dep[u];
    
    int mx = 0;
    for (auto v: g[u]) {
        mx = max(mx, dfs(v) + 1);
    }

    vis[u] = true;
    return dep[u] = mx;
}



int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    int ans = 0;
    for (int u = 1; u <= n; u++) ans = max(ans, dep[u]);
    cout << ans;

    return 0;
}