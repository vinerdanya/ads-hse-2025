// ооочень медленное решение

#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    double d = .0;
    std::cin >> n >> d;
    std::vector<std::pair<int, int> > points(n);
    for (auto &[x, y]: points) {
        std::cin >> x >> y;
    }
    auto dist = [](int x1, int y1, int x2, int y2) -> double {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return std::sqrt(dx * dx + dy * dy);
    };

    double inf = 1e10;
    std::vector<std::vector<double> > gr(n, std::vector<double>(n, inf));
    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
            auto [x1, y1] = points[v];
            auto [x2, y2] = points[u];
            double r = dist(x1, y1, x2, y2);
            if (r <= d + 0.000000001) {
                gr[v][u] = gr[u][v] = r;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (gr[i][k] == inf || gr[k][j] == inf) continue;
                gr[i][j] = std::min(gr[i][k] + gr[k][j], gr[i][j]);
            }
        }
    }

    int k = 0;
    std::cin >> k;
    std::cout << std::setprecision(9) << std::fixed;
    while (k--) {
        int start = 0, finish = 0;
        std::cin >> start >> finish;
        if (gr[start - 1][finish - 1] == inf) {
            std::cout << -1 << '\n';
            continue;
        }
        std::cout << gr[start - 1][finish - 1] << '\n';
    }
    return 0;
}