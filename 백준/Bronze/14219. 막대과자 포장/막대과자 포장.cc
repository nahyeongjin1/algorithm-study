// 14219
#include <iostream>

using namespace std;

uint16_t n, m; // [1, 500]

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    cout << (n % 3 == 0 || m % 3 == 0 ? "YES" : "NO") << '\n';

    return EXIT_SUCCESS;
}