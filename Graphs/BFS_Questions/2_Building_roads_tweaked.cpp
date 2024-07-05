#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> visited;
vector<int> component_root;

void dfs(int node, int root) {
    visited[node] = 1;

    for(auto v : g[node]) {
        if(!visited[v]) {
            dfs(v, root);
        }
    }
}

void solve() {
    int n, m;

    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    component_root.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        // If undirected graph
        g[b].push_back(a);
    }

    int num_comp = 0;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            component_root[num_comp++] = i;
            dfs(i, i);
        }
    }

    cout << num_comp - 1 << endl;
    for(int i = 1; i < num_comp; i++) {
        cout << component_root[i - 1] << " " << component_root[i] << endl;
    }
}

int main() {
    solve();
}
