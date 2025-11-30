#include <iostream>
#include <vector>

using std::vector;

// 재귀 백트래킹
void pick(uint16_t n, uint16_t m, uint16_t start, vector<uint16_t> &selected)
{
    // 종료 조건
    if (selected.size() == m)
    {
        for (uint16_t i = 0; i < m; i++)
        {
            std::cout << (i ? " " : "") << selected[i];
        }
        std::cout << '\n';
        return;
    }
    for (uint16_t i = start; i <= n; i++)
    {
        selected.push_back(i);
        pick(n, m, i + 1, selected);
        selected.pop_back();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // 1 <= m <= n <= 8
    uint16_t n;
    uint16_t m;
    std::cin >> n >> m;

    // 현재까지 고른 숫자들
    vector<uint16_t> selected;
    pick(n, m, 1, selected);

    return 0;
}