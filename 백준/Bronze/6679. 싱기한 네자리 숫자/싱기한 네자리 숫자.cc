// 6679
#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    for (uint16_t four_digit = 1000; four_digit <= 9999; four_digit++)
    {
        uint16_t decimal = four_digit % 10 + four_digit / 10 % 10 + four_digit / 100 % 10 + four_digit / 1000 % 10;
        uint16_t duodecimal = four_digit % 12 + four_digit / 12 % 12 + four_digit / 144 % 12 + four_digit / 1728 % 12;
        uint16_t hexadecimal = four_digit % 16 + four_digit / 16 % 16 + four_digit / 256 % 16 + four_digit / 4096 % 16;
        if (decimal == duodecimal && duodecimal == hexadecimal)
            cout << four_digit << '\n';
    }

    return 0;
}
