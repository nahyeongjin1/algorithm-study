// 16715
#include <iostream>

using namespace std;

uint32_t N;                 // [2, 100'000]
uint64_t max_digit_sum = 0; // 이거 자리수 다 더하면 얼마 나옴? 몰라 일단 크게 가
uint32_t max_system = N;    // [2, 100'000]

void recursive()
{
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    // N진법부터 줄여가면서 구하기
    for (uint32_t n = N; n >= 2; n--)
    {
        uint64_t cur_sum = 0;
        uint64_t temp = N;
        while (temp > 0)
        {
            cur_sum += temp % n;
            temp /= n;
        }
        if (cur_sum >= max_digit_sum)
        {
            max_digit_sum = cur_sum;
            max_system = n;
        }
    }

    cout << max_digit_sum << ' ' << max_system << '\n';

    return EXIT_SUCCESS;
}
