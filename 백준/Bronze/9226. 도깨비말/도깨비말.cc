// 9226
#include <iostream>
#include <algorithm>

using namespace std;

string input;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    while (true)
    {
        cin >> input;

        if (input == "#")
        {
            break;
        }

        size_t min_pos = min({
            input.find('a'),
            input.find('e'),
            input.find('i'),
            input.find('o'),
            input.find('u'),
        });

        uint16_t idx = (min_pos == SIZE_MAX) ? 0 : min_pos;

        for (uint16_t i = idx; i < input.length(); i++)
        {
            cout << input[i];
        }

        for (uint16_t i = 0; i < idx; i++)
        {
            cout << input[i];
        }

        cout << "ay" << '\n';
    }

    return 0;
}