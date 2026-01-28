// 20254
#include <iostream>

using namespace std;

uint16_t U_R, T_R, U_O, T_O;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> U_R >> T_R >> U_O >> T_O;

    cout << 56 * U_R + 24 * T_R + 14 * U_O + 6 * T_O << '\n';

    return EXIT_SUCCESS;
}