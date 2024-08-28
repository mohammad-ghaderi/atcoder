#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 1e5 + 5;
int n;
vector<int> g[SIZE]{};
bool vis[SIZE]{};
int mem[SIZE][2];

int dfs(int u, int par, bool c) { // c => true: black, false: white 
    if (~mem[u][c]) return mem[u][c];

    int ans = 1;
    for (auto v : g[u]) {
        if (v == par) continue;
        if (c) {
            ans = mod(ans * dfs(v, u, !c));
        } else {
            ans = mod(ans * mod(dfs(v, u, false) + dfs(v, u, true)));
        }
    }

    return mem[u][c] = mod(ans);
}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i <= n; i++) mem[i][0] = mem[i][1] = -1;

    cout << mod(dfs(1, 0, false) + dfs(1, 0, true)) << endl;

    return 0;
}