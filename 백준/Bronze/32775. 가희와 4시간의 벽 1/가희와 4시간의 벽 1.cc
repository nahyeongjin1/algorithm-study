// 32775
#include <iostream>

using namespace std;

uint16_t S_ab, F_ab;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> S_ab >> F_ab;

    if (S_ab <= F_ab)
    {
        cout << "high speed rail" << '\n';
    }
    else
    {
        cout << "flight" << '\n';
    }

    return 0;
}