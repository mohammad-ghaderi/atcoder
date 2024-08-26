#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 3003;
string a, b;

int mem[SIZE][SIZE]{};
pair<int,int> nex[SIZE][SIZE];

int dp(int i, int j) {
    // Base case
    if (i == a.size() or j == b.size()) return mem[i][j] = 0;
    if (~mem[i][j]) return mem[i][j];

    // Recursive case
    int ans = dp(i + 1, j);
    nex[i][j] = {i + 1, j};

    for (int tj = j; tj < b.size(); tj++) {
        if (b[tj] != a[i]) continue;
        int an = dp(i + 1, tj + 1) + 1;
        if (an > ans) {
            ans = an;
            nex[i][j] = {i + 1, tj + 1};
        }
        break;
    }

    return mem[i][j] = ans;
}

void back_tracking(int i, int j) {
    if (i == -1 or j == -1) return;
    if (i == a.size() or j == b.size()) return;

    int ti = nex[i][j].first, tj = nex[i][j].second;
    if (mem[ti][tj] != mem[i][j]) cout << a[i];
    back_tracking(ti, tj);
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) mem[i][j] = -1, nex[i][j] = {-1, -1};
    }
    
    auto ans = dp(0, 0);

    back_tracking(0, 0);
    return 0;
}