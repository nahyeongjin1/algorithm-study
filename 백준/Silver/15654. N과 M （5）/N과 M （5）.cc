#include <iostream>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

void permute(uint16_t n, uint16_t m, vector<uint16_t> &numPool, vector<bool> &visited, vector<uint16_t> &selected)
{
    if (selected.size() == m)
    {
        for (uint16_t i = 0; i < m; i++)
        {
            std::cout << (i ? " " : "") << selected[i];
        }
        std::cout << '\n';
        return;
    }
    for (uint16_t i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        selected.push_back(numPool[i]);
        visited[i] = true;
        permute(n, m, numPool, visited, selected);
        selected.pop_back();
        visited[i] = false;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // 1 <= m <= n <= 8
    uint16_t n, m;
    std::cin >> n >> m;

    vector<bool> visited(n);
    vector<uint16_t> numPool(n);

    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> numPool[i];
    }
    sort(numPool.begin(), numPool.end());

    vector<uint16_t> selected;

    permute(n, m, numPool, visited, selected);

    return 0;
}