#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>


struct Comp {
    bool operator()(std::pair<int, double>& p1, std::pair<int, double>& p2) {
        return p1.second > p2.second;
    }
};

double dist(int x1, int y1, int x2, int y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

std::vector<std::pair<int, int>> vertex;
std::vector<std::vector<std::pair<int, double>>> gr;
double dijkstra(int start, int finish, int n) {
    std::vector<double> dist(n, -1.0);
    std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, Comp> pq;
    pq.emplace(start, 0.0);
    dist[start] = 0.0;
    while (!pq.empty()) {
        auto [from, f_val] = pq.top(); pq.pop();
        if (dist[from] < f_val) { continue; }
        for (auto [to, t_val] : gr[from]) {
            if (dist[to] == -1.0 || dist[to] > dist[from] + t_val) {
                dist[to] = dist[from] + t_val;
                pq.emplace(to, dist[to]);
            }
        }
    }
    return dist[finish];
}

int main() {
    int n, d;
    std::cin >> n >> d;
    vertex.resize(n);
    gr.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vertex[i].first >> vertex[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int x1 = vertex[i].first;
        int y1 = vertex[i].second;
        for (int j = 0; j < i; ++j) {
            int x2 = vertex[j].first;
            int y2 = vertex[j].second;
            double distance = dist(x1, y1, x2, y2);
            if (d >= distance) {
                gr[i].emplace_back(j, distance);
                gr[j].emplace_back(i, distance);
            }
        }
    }
    int k = 0;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int start, finish;
        std::cin >> start >> finish;
        --start, --finish;
        double ans = dijkstra(start, finish, n);
        if (ans == -1){ std::cout << -1 << '\n'; continue; }
        std::cout << std::fixed << std::setprecision(9) << ans << '\n';
    }
    return 0;
}