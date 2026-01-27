// 1806
#include <iostream>
#include <vector>

using namespace std;

uint32_t N;                // [10. 100'000]
uint32_t S;                // (0, 100'000'000]
vector<uint16_t> sequence; // 각각 [1, 10'000]
uint32_t l = 0;
uint32_t r = 0;
uint32_t sum = 0;
uint32_t result = UINT32_MAX;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> S;

    sequence.resize(N);

    for (uint32_t i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    while (r < N || sum >= S)
    {
        if (sum < S)
        {
            sum += sequence[r++];
        }
        else
        {
            result = min(result, r - l);
            sum -= sequence[l++];
        }
    }

    cout << (result == UINT32_MAX ? 0 : result) << '\n';

    return EXIT_SUCCESS;
}
