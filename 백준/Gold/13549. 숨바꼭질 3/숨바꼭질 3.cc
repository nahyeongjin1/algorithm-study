#include <iostream>
#include <deque>
#include <array>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    constexpr uint32_t LIMIT = 100001;

    uint32_t n, k;
    std::cin >> n >> k;

    // *2는 시간이 그대로라서 우선 처리, +-1은 시간이 추가되니 후에 처리하여 최적해 보장
    std::deque<uint32_t> deq;
    deq.push_front(n);

    // 소요 시간 (초)
    std::array<uint32_t, LIMIT> secs;
    secs.fill(0);

    while (!deq.empty())
    {
        uint32_t cur_index = deq.front();
        deq.pop_front();
        if (cur_index == k)
        {
            break;
        }
        if (cur_index != LIMIT - 1)
        {
            if (secs[cur_index + 1] == 0 || secs[cur_index] + 1 < secs[cur_index + 1])
            {
                deq.push_back(cur_index + 1);
                secs[cur_index + 1] = secs[cur_index] + 1;
            }
        }
        if (cur_index != 0)
        {
            if (secs[cur_index + -1] == 0 || secs[cur_index] + 1 < secs[cur_index - 1])
            {
                deq.push_back(cur_index - 1);
                secs[cur_index - 1] = secs[cur_index] + 1;
            }
            if (cur_index <= LIMIT / 2)
            {
                if (secs[cur_index * 2] == 0 || secs[cur_index] < secs[cur_index * 2])
                {
                    deq.push_front(cur_index * 2);
                    secs[cur_index * 2] = secs[cur_index];
                }
            }
        }
    }

    std::cout << secs[k] << '\n';

    return 0;
}