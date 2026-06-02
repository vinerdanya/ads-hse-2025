#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n = 0, m = 0, p = 0, q = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::cin >> n >> m >> p >> q >> x1 >> y1 >> x2 >> y2;
    std::vector<std::vector<int> > field(n, std::vector<int>(m, -1));
    std::vector<std::pair<int, int> > steps = {
        {p, q},
        {q, p},
        {p, -q},
        {q, -p},
        {-p, q},
        {-q, p},
        {-p, -q},
        {-q, -p}
    };
    field[x1 - 1][y1 - 1] = 0;
    std::queue<std::pair<int ,int>> queue;
    queue.emplace(x1 - 1, y1 - 1);
    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop();
        for (auto [dx, dy] : steps) {
            if (x + dx < 0 || x + dx >= n) continue;
            if (y + dy < 0 || y + dy >= m) continue;
            if (field[x + dx][y + dy] == -1) {
                field[x + dx][y + dy] = field[x][y] + 1;
                queue.emplace(x + dx, y + dy);
            }
        }
    }
    std::cout << field[x2 - 1][y2 - 1];
    return 0;
}