// 8370
#include <iostream>

using namespace std;

uint32_t n1, k1, n2, k2; // [1, 1'000]

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n1 >> k1 >> n2 >> k2;

    cout << n1 * k1 + n2 * k2 << '\n';

    return EXIT_SUCCESS;
}