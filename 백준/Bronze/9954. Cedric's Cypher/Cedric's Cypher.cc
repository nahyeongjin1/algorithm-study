// 9954
#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    while (true)
    {
        string input;

        getline(cin, input);

        if (input == "#")
            break;

        string result = "";

        char diff = input.back() - 'A';
        input = input.substr(0, input.length() - 1);

        for (char c : input)
        {
            if (c >= 'a' && c <= 'z')
            {
                if (c - diff < 'a')
                {
                    result += c - diff + 'z' - 'a' + 1;
                }
                else
                {
                    result += c - diff;
                }
            }
            else if (c >= 'A' && c <= 'Z')
            {
                if (c - diff < 'A')
                {
                    result += c - diff + 'Z' - 'A' + 1;
                }
                else
                {
                    result += c - diff;
                }
            }
            else
            {
                result += c;
            }
        }
        cout << result << '\n';
    }

    return EXIT_SUCCESS;
}
