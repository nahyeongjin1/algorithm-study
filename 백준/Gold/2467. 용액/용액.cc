// 2467
#include <iostream>
#include <vector>

using namespace std;

uint32_t N; // [2, 100_000]
vector<int32_t> solutions;
uint32_t min_abs_sum = UINT32_MAX;
uint32_t min_idx_1, min_idx_2;
uint32_t l_idx = 0, r_idx;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    solutions.resize(N);
    r_idx = N - 1;

    for (uint32_t i = 0; i < N; i++)
    {
        cin >> solutions[i];
    }

    // 양 끝에서 포인터를 좁혀오면서 계산
    // n^2에서 n으로 복잡도 개선
    while (l_idx < r_idx)
    {
        int32_t sum = solutions[l_idx] + solutions[r_idx];
        uint32_t abs_sum = abs(sum);

        if (abs_sum < min_abs_sum)
        {
            min_idx_1 = l_idx;
            min_idx_2 = r_idx;
            min_abs_sum = abs_sum;
        }

        if (sum < 0)
        {
            l_idx++;
        }
        else if (sum > 0)
        {
            r_idx--;
        }
        else
        {
            break;
        }
    }

    cout << solutions[min_idx_1] << ' ' << solutions[min_idx_2] << '\n';

    return EXIT_SUCCESS;
}