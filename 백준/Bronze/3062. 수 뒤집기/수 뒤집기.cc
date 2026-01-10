// 3062
#include <iostream>
#include <cmath>

using namespace std;

uint64_t T; // 범위가 없으니 일단 크게

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        string input;
        cin >> input;

        auto it_forward = input.begin();
        auto it_reverse = input.rbegin();
        uint32_t sum = 0;

        /*뒤집어서 더하기*/
        for (uint32_t i = 0; i < input.size(); i++)
        {
            sum += ((*it_forward - '0') + (*it_reverse - '0')) * pow(10, i);
            it_forward++;
            it_reverse++;
        }

        /*sum이 대칭인지 확인*/
        string result = to_string(sum);
        bool is_sym = true;
        for (uint32_t i = 0; i < result.size() / 2; i++)
        {
            if (result[i] != result[result.size() - i - 1])
            {
                is_sym = false;
                break;
            }
        }

        cout << (is_sym ? "YES" : "NO") << '\n';
    }

    return 0;
}
