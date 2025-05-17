//https://codeforces.com/problemset/problem/1873/H
#include <bits/stdc++.h>
using namespace std;

const int M = -1;

int32_t main() {

    int t;
    cin >> t;
      
    while (t--) {
        int n, a, b, f = 0;
        cin >> n >> a >> b;

        vector<vector<int>> G(n + 1);
        vector<pair<int, int>> edges;

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            edges.emplace_back(u, v);
        }

        if (a == b) {
            cout << "NO\n";
            continue;
        }

        auto bfs = [&](int node) -> vector<int> {
            vector<int> dis(n + 1, M);
            queue<int> q;
            dis[node] = 0;
            q.push(node);
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                for (auto& child : G[u]) {
                    if (dis[child] == M) {
                        q.push(child);
                        dis[child] = 1 + dis[u];
                    }
                }
            }
            return dis;
        };

        auto cycle_node = [&](int n, const vector<pair<int, int>>& edges) {
            vector<vector<int>> g(n + 1);
            vector<int> deg(n + 1), inCycle(n + 1, 1);

            for (auto [u, v] : edges) {
                g[u].push_back(v);
                g[v].push_back(u);
                deg[u]++;
                deg[v]++;
            }

            queue<int> q;
            for (int i = 1; i <= n; ++i)
                if (deg[i] <= 1) q.push(i);

            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                inCycle[u] = 0;
                for (auto v : g[u])
                    if (--deg[v] == 1)
                        q.push(v);
            }
            vector<int> res;
            for (int i = 1; i <= n; ++i)
                if (inCycle[i]) res.push_back(i);
            return res;
        };

        vector<int> dis_a = bfs(a), dis_b = bfs(b), cyc = cycle_node(n, edges);
        for (auto &i : cyc)
            if (dis_b[i] < dis_a[i]) f = 1;
        cout << (f ? "YES\n" : "NO\n");
    }
}
