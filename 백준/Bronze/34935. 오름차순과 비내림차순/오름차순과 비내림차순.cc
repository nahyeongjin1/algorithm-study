// 34935
#include <iostream>

using namespace std;

uint32_t N;                // [1, 1'000'000]
int64_t previous, current; // [-1'000'000'000'000'000'000, 1'000'000'000'000'000'000]
bool is_asc = true;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    cin >> previous;

    for (uint32_t i = 1; i < N; i++)
    {
        cin >> current;
        if (previous >= current)
        {
            is_asc = false;
            break;
        }
        previous = current;
    }

    cout << is_asc ? 1 : 0 << '\n';

    return EXIT_SUCCESS;
}