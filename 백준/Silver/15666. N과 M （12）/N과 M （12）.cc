#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

uint16_t n, m;
vector<uint16_t> input;
vector<uint16_t> selected;

void backtrack(uint16_t depth, uint16_t start)
{
    if (depth == m)
    {
        for (uint16_t i = 0; i < m; i++)
        {
            std::cout << (i ? " " : "") << selected[i];
        }
        std::cout << '\n';
        return;
    }

    for (uint16_t i = start; i < n; i++)
    {
        if (i > start && input[i] == input[i - 1])
            continue;

        // 1. 선택
        selected.push_back(input[i]);

        // 2. 다음 자리 채우러 감
        backtrack(depth + 1, i);

        // 3. 되돌리기
        selected.pop_back();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> n >> m;

    input.resize(n);
    selected.reserve(m);

    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }
    std::sort(input.begin(), input.end());

    backtrack(0, 0);

    return 0;
}