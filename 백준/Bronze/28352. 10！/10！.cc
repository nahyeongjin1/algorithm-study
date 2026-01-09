// 28352
#include <iostream>

using namespace std;

uint16_t fact;
uint32_t result = 6;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> fact;

    // 근데 이거 10!이 6주면
    // 그 다음부터는 그냥 6부터 곱하면 되는거 아님?

    for (uint16_t i = fact; i > 10; i--)
    {
        result *= i;
    }

    cout << result << '\n';

    return 0;
}