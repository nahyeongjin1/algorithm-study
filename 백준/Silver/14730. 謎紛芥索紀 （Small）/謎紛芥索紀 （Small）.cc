// 14730
#include <iostream>

using namespace std;

uint16_t N; // [1, 100]
int32_t C;  // [100, 100], != 0
int32_t K;  // [1, 1'000]
int32_t sum = 0;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    while (N--)
    {
        cin >> C >> K;
        sum += C * K;
    }
    cout << sum << '\n';

    return 0;
}