#include <iostream>
#include <queue>

using std::pair;
using std::queue;

uint32_t a, b;
queue<pair<uint16_t, uint32_t>> q;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> a >> b;

    q.push({1, a});

    while (!q.empty())
    {
        auto [cur_cnt, cur_num] = q.front();
        q.pop();

        /** A를 B로 바꾼 경우 */
        if (cur_num == b)
        {
            std::cout << cur_cnt << '\n';
            return 0;
        }

        if (cur_num > b / 2)
            continue;

        q.push({cur_cnt + 1, cur_num * 2});

        if (cur_num > b / 10)
            continue;

        q.push({cur_cnt + 1, cur_num * 10 + 1});
    }

    /** A를 B로 바꾸지 못한 경우 */
    std::cout << -1 << '\n';
    return 0;
}
