// 28323
#include <iostream>
#include <vector>

using namespace std;

uint32_t N;         // [1, 300_000]
vector<uint32_t> A; // [1, 100_000]

/*홀짝이 번갈아 나와야 함*/

int32_t solve(vector<uint32_t> &A, bool expect_odd)
{
    uint32_t count = 0;
    for (uint32_t x : A)
    {
        if ((x % 2) == expect_odd)
        {
            count++;
            expect_odd = !expect_odd;
        }
    }
    return count;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    A.resize(N);

    for (uint32_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << max(solve(A, true), solve(A, false)) << '\n';

    return EXIT_SUCCESS;
}