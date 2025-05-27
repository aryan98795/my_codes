#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n = 6;
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}}, deg(n + 1);
    for (int i = 0; i < n;i++)
        for (auto child : adj[i]) deg[child]++;
    queue<int> q;
    for (int i = 0; i < n;i++)
        if (!deg[i]) q.push(i);
    while(!q.empty()){
        cout << q.front() << " ";
        for (auto child : adj[q.front()])
            if (!(--deg[child])) q.push(child);
        q.pop();
    }
}
