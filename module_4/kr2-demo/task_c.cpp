#include <cstdint>
#include <iostream>
#include <vector>

int64_t inf = 1LL << 62;

struct Edge {
    int f = 0;
    int t = 0;
    int64_t w = 0;
};

int main() {
    int n = 0, m = 0, start = 0 ;
    std::cin >> n >> start >> m;
    std::vector<Edge> edges(m);
    for (auto& [f, t, w] : edges) {
        std::cin >> f >> t >> w;
    }
    std::vector<int64_t> dist(n + 1, inf);
    dist[start] = 0;
    bool isRelax = true;
    while (isRelax) {
        isRelax = false;
        for (auto [f, t, w] : edges) {
            if (dist[f] == inf) continue;
            if (dist[t] > dist[f] + w) {
                dist[t] = dist[f] + w;
                isRelax = true;
            }
        }
    }
    for (int i = 1; i < dist.size(); ++i) {
        if (dist[i] == inf) {
            std::cout << '?' << ' ';
        } else {
            std::cout << dist[i] << ' ';
        }
    }
    return 0;
}