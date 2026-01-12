// 1106
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

uint16_t C;                              // [1, 1_000]
uint16_t N;                              // [1, 20]
uint16_t cost, customer;                 // [1, 100]
vector<pair<uint16_t, uint16_t>> cities; // {cost, customer}
vector<uint32_t> dp;
uint16_t dp_len;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> C >> N;

    cities.resize(N);

    dp_len = C + 101;
    dp.resize(dp_len, INT32_MAX);
    dp[0] = 0;

    for (uint16_t i = 0; i < N; i++)
    {
        cin >> cost >> customer;
        cities[i] = {cost, customer};
    }

    for (auto city : cities)
    {
        auto [cur_cost, cur_customer] = city;

        for (uint16_t i = cur_customer; i < dp_len; i++)
        {
            dp[i] = min(dp[i], dp[i - cur_customer] + cur_cost);
        }
    }

    cout << *min_element(dp.begin() + C, dp.end()) << '\n';

    return EXIT_SUCCESS;
}
