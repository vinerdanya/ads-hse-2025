#include <cstdint>
#include <iostream>
#include <vector>
#include <set>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::set<int>> gr(n + 1);

    for (int i = 0; i < m; ++i) {
        int v = 0, u = 0;
        std::cin >> v >> u;
        gr[v].insert(u);
        gr[u].insert(v);
    }
    int count = 0;
    for (int from = 0; from < n + 1; ++from) {
        for (auto to : gr[from]) {
            if (from < to) {
                ++count;
            }
        }
    }
    std::cout << n << ' ' << count << '\n';
    for (int from = 0; from < n + 1; ++from) {
        for (auto to : gr[from]) {
            if (from < to) {
                std::cout << from << ' '  << to << '\n';
            }
        }
    }
    return 0;
}