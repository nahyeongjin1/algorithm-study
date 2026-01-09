// 10797
#include <iostream>

using namespace std;

uint16_t n;
uint16_t temp;
uint16_t result = 0;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;

    for (uint16_t i = 0; i < 5; i++)
    {
        cin >> temp;
        if (n == temp)
        {
            result++;
        }
    }

    cout << result;

    return 0;
}