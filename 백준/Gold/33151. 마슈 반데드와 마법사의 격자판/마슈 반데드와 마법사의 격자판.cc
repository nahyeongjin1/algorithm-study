/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 33151                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/33151                          #+#        #+#      #+#    */
/*   Solved: 2025/03/22 19:36:09 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

void count_groups(uint16_t n, uint32_t &cnt0, uint32_t &cnt1)
{
    uint32_t total = n * n;
    if (n % 2 == 0)
    {
        cnt0 = cnt1 = total / 2;
    }
    else
    {
        cnt0 = (total + 1) / 2; // (0,0)부터 시작하므로 그룹0이 한 칸 더 많다.
        cnt1 = total / 2;
    }
}

bool solve_option(uint16_t n, uint32_t k, uint32_t constant_count, uint32_t variable_count,
                  uint32_t &base_val, uint32_t &num_plus)
{
    uint32_t total = n * n;
    // 모든 변수 셀에 base_val+1 (또는 base_val==0인 경우 1)을 채워 k가 정확히 variable_count가 될 수 있는 경우
    uint32_t b_min;
    if (k > variable_count)
        b_min = (k - variable_count + total - 1) / total; // 올림 나눗셈
    else
        b_min = 0;
    uint32_t b_max = (k + variable_count) / total;

    for (uint32_t b = b_min; b <= b_max; b++)
    {
        int64_t candidate = static_cast<int64_t>(k) - static_cast<int64_t>(total) * b + variable_count;
        if (candidate < 0 || candidate > 2LL * variable_count)
            continue;
        if (candidate % 2 != 0)
            continue;
        uint32_t cur_num_plus = candidate / 2;
        if (cur_num_plus > variable_count)
            continue;
        base_val = b;
        num_plus = cur_num_plus;
        return true;
    }
    return false;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 1,000
    uint32_t k; // 1 <= k <= 1,000,000,000
    std::cin >> n >> k;

    // 1x1 격자는 특별 처리
    if (n == 1)
    {
        std::cout << k << '\n';
        return 0;
    }

    uint32_t cnt0, cnt1;
    count_groups(n, cnt0, cnt1);

    // 최소 필요한 동전 개수는 두 그룹 중 더 적은 개수이다.
    uint32_t min_possible = std::min(cnt0, cnt1);
    if (k < min_possible)
    {
        std::cout << -1 << "\n";
        return 0;
    }
    // n이 짝수인 경우 두 그룹의 셀 개수가 같으므로, k의 홀짝이 맞아야 한다.
    if ((n % 2 == 0) && (k % 2 != ((n * n / 2) % 2)))
    {
        std::cout << -1 << "\n";
        return 0;
    }

    uint32_t base_val, num_plus;
    bool solved = false;
    bool option = false; // false: Option A (상수 그룹은 그룹0), true: Option B (상수 그룹은 그룹1)

    if (solve_option(n, k, cnt0, cnt1, base_val, num_plus))
    {
        solved = true;
        option = false;
    }
    else if (solve_option(n, k, cnt1, cnt0, base_val, num_plus))
    {
        solved = true;
        option = true;
    }
    if (!solved)
    {
        std::cout << -1 << "\n";
        return 0;
    }

    vector<vector<uint32_t>> grid(n, vector<uint32_t>(n, 0));
    // 격자판 채우기: Option A에서는 (i+j)%2==0인 셀에 상수, Option B에서는 (i+j)%2==1인 셀에 상수.
    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < n; j++)
        {
            int color = (i + j) & 1; // 0 또는 1
            bool is_constant = (!option ? (color == 0) : (color == 1));
            if (is_constant)
            {
                grid[i][j] = base_val;
            }
            else
            {
                if (base_val == 0)
                {
                    grid[i][j] = 1;
                }
                else
                {
                    if (num_plus > 0)
                    {
                        grid[i][j] = base_val + 1;
                        num_plus--;
                    }
                    else
                    {
                        grid[i][j] = base_val - 1;
                    }
                }
            }
        }
    }

    for (const vector<uint32_t> &row : grid)
    {
        for (uint16_t i = 0; i < n; i++)
        {
            std::cout << (i ? " " : "") << row[i];
        }
        std::cout << '\n';
    }

    return 0;
}
