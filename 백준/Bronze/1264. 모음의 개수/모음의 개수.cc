// 1264
#include <iostream>

using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
string sentence;
uint16_t vowel_cnt;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    while (true)
    {
        getline(cin, sentence);

        if (sentence == "#")
            break;
        vowel_cnt = 0;
        for (char c : sentence)
        {
            for (char vowel : vowels)
            {
                if (c == vowel)
                {
                    vowel_cnt++;
                }
            }
        }
        cout << vowel_cnt << '\n';
    }

    return 0;
}