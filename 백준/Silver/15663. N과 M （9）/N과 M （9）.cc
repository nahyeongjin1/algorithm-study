#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/** 1 <= m <= n <= 8 */
uint16_t n, m;
vector<uint16_t> input;
vector<uint16_t> selected;
vector<bool> used;

void backtrack(uint16_t depth)
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

    for (int i = 0; i < n; i++)
    {
        if (used[i] || (i > 0 && input[i] == input[i - 1] && !used[i - 1]))
            continue;

        // 1. 선택
        selected.push_back(input[i]);
        used[i] = true;
        // 2. 다음 자리 채우러 감 (재귀)
        backtrack(depth + 1);
        // 3. 되돌리기
        used[i] = false;
        selected.pop_back();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> n >> m;

    input.resize(n);     // 메모리 및 값 할당
    used.resize(n);      // 메모리 및 값 할당
    selected.reserve(m); // 메모리만 할당

    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }
    std::sort(input.begin(), input.end());

    backtrack(0);

    return 0;
}