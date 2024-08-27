#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 3000;
int n;
double a[SIZE];
double mem[SIZE][SIZE];

double dp(int i, int cnt) {

    if (i == -1) return cnt >= (n + (n%2))/2;
    

    if (mem[i][cnt] != -1) return mem[i][cnt];
    
    double t = (1 - a[i]) * dp(i - 1, cnt);
    double h = a[i] * dp(i - 1, cnt + 1);

    return mem[i][cnt] = h + t;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) mem[i][j] = -1;

    cout << fixed << setprecision(10);
    cout << dp(n - 1, 0) << endl;

    return 0;
}