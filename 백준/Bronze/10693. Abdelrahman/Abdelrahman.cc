// 10693
#include <iostream>

using namespace std;

uint16_t T; // [1, 100]
uint16_t N; // [1, 10'000]
uint32_t M; // [N-1, 100'000]

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;

    for (uint16_t i = 1; i <= T; i++)
    {
        cin >> N >> M;
        cout << "Case " << i << ": " << M - (N - 1) << '\n';
    }

    return 0;
}