#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dp;
const long long mod = 1e9 + 7;

int dfs(int node, int n) {
    if (dp[node] != -1) return dp[node];
    if (node == n) return 1;
    
    long long ans = 0;
    for (auto v : g[node]) {
        ans = (ans + dfs(v, n)) % mod;
    }
    
    return dp[node] = ans;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    dp.assign(n + 1, -1);
    g.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    int ans = dfs(1, n);
    cout << ans << '\n';
}