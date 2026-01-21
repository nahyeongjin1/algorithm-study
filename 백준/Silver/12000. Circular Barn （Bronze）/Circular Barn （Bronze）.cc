// 12000
#include <iostream>
#include <vector>

using namespace std;

uint16_t n;                     // [3, 1'000]
vector<uint16_t> cows_per_room; // r_i [1, 100]
uint32_t result = UINT32_MAX;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;

    cows_per_room.resize(n);

    for (uint16_t i = 0; i < n; i++)
    {
        cin >> cows_per_room[i];
    }

    for (uint16_t i = 0; i < n; i++)
    {
        uint32_t sum = 0;
        for (uint16_t j = 0; j < n; j++)
        {
            sum += cows_per_room[(i + j) % n] * j;
        }
        result = min(result, sum);
    }

    cout << result << '\n';

    return 0;
}