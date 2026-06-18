#include <cstdint>
#include <iostream>
#include <vector>

std::vector<int> used;
std::vector<std::vector<int>> gr;

void dfs(int v) {
    used[v] = true;
    for (int to = 0; to < gr[v].size(); ++to) {
        if (gr[v][to] == 1 && !used[to]) {
            dfs(to);
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    used.assign(n, false);
    gr.assign(n, std::vector<int>(n));
    int count_edge = 0;
    for (auto& v : gr) {
        for (auto& item : v) {
            std::cin >> item;
            count_edge += item;
        }
    }
    dfs(0);
    int count_vertex = 0;
    for (auto item : used) {
        count_vertex += item;
    }
    if (count_edge == 2 * (n - 1) && count_vertex == n) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}