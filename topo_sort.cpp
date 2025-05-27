#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n = 6;
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}}, vis(n + 1);
    stack<int> st;
    auto dfs = [&](auto dfs, int node) -> void {
        vis[node] = 1;
        for (auto& child : adj[node]) {
            if (!vis[child]) dfs(dfs, child);
        }
        st.push(node);
    };
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(dfs, i);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
