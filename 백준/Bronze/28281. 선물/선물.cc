// 28281
#include <iostream>
#include <vector>

using namespace std;

uint32_t N, X;
vector<uint16_t> costs;
uint32_t candiate = 0;
uint64_t result;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> X;

    costs.resize(N);

    for (uint32_t i = 0; i < N; i++)
    {
        cin >> costs[i];
    }

    for (uint32_t i = 1; i < N - 1; i++)
    {
        if (costs[candiate] + costs[candiate + 1] > costs[i] + costs[i + 1])
        {
            candiate = i;
        }
    }

    result = uint64_t(costs[candiate] + costs[candiate + 1]) * X;

    cout << result << '\n';

    return EXIT_SUCCESS;
}