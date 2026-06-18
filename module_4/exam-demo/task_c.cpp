#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n = 0, s = 0, m = 0;
    std::cin >> n >> s >> m;
    std::vector<std::vector<int>> gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int f = 0, t = 0;
        std::cin >> f >> t;
        gr[t].push_back(f);
    }
    std::vector<int> dist(n + 1, -1);
    dist[s] = 0;
    std::queue<int> q({s});
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : gr[cur]) {
            if (dist[to] == -1) {
                dist[to] = dist[cur] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        std::cout << dist[i] << ' ';
    }
    return 0;
}