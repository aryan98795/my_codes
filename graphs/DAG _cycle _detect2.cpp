#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n = 6;
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}}, deg(n, 0);
    for (int i = 0; i < n; i++)
        for (int child : adj[i])
            deg[child]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0)
            q.push(i);
    int processed = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        processed++;
        for (int child : adj[node])
            if (--deg[child] == 0)
                q.push(child);
    }
    cout << "\n";
    // If processed nodes != total nodes → cycle exists
    if (processed != n)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
}
