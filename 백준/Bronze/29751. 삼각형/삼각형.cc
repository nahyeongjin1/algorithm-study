// 29751
#include <iostream>
#include <iomanip>

using namespace std;

uint16_t W, H; // [1, 100]

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> W >> H;
    cout << fixed << setprecision(1);
    cout << W * H / 2.0 << '\n';

    return 0;
}