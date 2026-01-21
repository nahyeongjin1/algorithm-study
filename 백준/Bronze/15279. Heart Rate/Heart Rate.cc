// 15279
#include <iostream>
#include <iomanip>

using namespace std;

uint16_t N;    // [1, 1'000]
uint16_t b;    // [2, 1'000]
long double p; // (0, 1'000)
long double min_ABPM, calc_BPM, max_ABPM;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    for (uint16_t i = 0; i < N; i++)
    {
        cin >> b >> p;
        calc_BPM = 60 * b / p;
        min_ABPM = calc_BPM - 60 / p;
        max_ABPM = calc_BPM + 60 / p;
        cout << fixed << setprecision(4);
        cout << min_ABPM << ' ';
        cout << calc_BPM << ' ';
        cout << max_ABPM << '\n';
    }

    return 0;
}