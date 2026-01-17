// 26145
#include <iostream>
#include <vector>

using namespace std;

uint16_t N;              // 출제자 수 [1, 1'000]
uint16_t M;              // 검수자 수 [1, 1'000]
uint32_t S;              // 각 출제자가 받은 출제비 [0, 100'000]
uint32_t T;              // 출제자가 운영자에게 나눠주기로 한 돈 [0, 100'000]
vector<uint32_t> admins; // 각 운영자가 받게 될 돈

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    admins.resize(N + M, 0);

    for (uint16_t i = 0; i < N; i++)
    {
        cin >> S;
        admins[i] = S;
    }

    for (uint16_t i = 0; i < N; i++)
    {
        for (uint16_t j = 0; j < N + M; j++)
        {
            cin >> T;
            admins[i] -= T;
            admins[j] += T;
        }
    }

    for (uint16_t i = 0; i < admins.size(); i++)
    {
        cout << (i ? " " : "") << admins[i];
    }
    cout << '\n';

    return EXIT_SUCCESS;
}