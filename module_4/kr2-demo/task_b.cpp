#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int inf = 1 << 20;

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<int> baron(n + 1);
    for (int i = 1; i < baron.size(); ++i) {
        std::cin >> baron[i];
    }
    std::vector<std::vector<int>> gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int v = 0, u = 0;
        std::cin >> v >> u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    std::vector<int> dist(n + 1, inf);
    std::vector<int> p(n + 1, -1);
    std::set<std::pair<int, int>> st;
    // first - текущие расстояние, second - номер вершины
    st.emplace(0, 1);
    dist[1] = 0;
    while (!st.empty()) {
        auto [d, cur] = *st.begin();
        st.erase(st.begin());
        for (auto to : gr[cur]) {
            int w = 0;
            if (baron[cur] != baron[to]) {
                w = 1 + (cur + 1) % 2;
            }
            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;
                st.emplace(dist[to], to);
                p[to] = cur;
            }
        }
    }
    if (dist[n] == inf) {
        std::cout << "impossible";
    } else {
        std::vector<int> path;
        int v = n;
        while (v != -1) {
            path.push_back(v);
            v = p[v];
        }
        std::cout << dist[n] << ' ' << path.size() << '\n';
        std::reverse(path.begin(), path.end());
        for (auto item : path) {
            std::cout << item << ' ';
        }
    }

    return 0;
}