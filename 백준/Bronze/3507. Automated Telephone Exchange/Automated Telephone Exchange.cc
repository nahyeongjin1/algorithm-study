// 3507
#include <iostream>

using namespace std;

uint16_t ATE; // [100, 999]
uint16_t result = 1;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> ATE;

    if (ATE > 198)
    {
        cout << 0 << '\n';
        return EXIT_SUCCESS;
    }

    result += 198 - ATE;

    cout << result << '\n';

    return EXIT_SUCCESS;
}
