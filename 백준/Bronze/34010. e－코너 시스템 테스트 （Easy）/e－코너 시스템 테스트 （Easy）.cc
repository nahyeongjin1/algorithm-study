// 34010
#include <iostream>

using namespace std;

uint16_t N; // [2, 502]

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    cout << 2 * (N - 1) << ' ' << 2 * (N - 1) - 1 << '\n';

    return 0;
}