#include <iostream>
#include <vector>
#include <queue>

using namespace std;

uint16_t N, M;                 // [1, 100]
vector<uint16_t> A;            // [1, 100]
vector<uint16_t> B;            // [1, 100]
uint16_t idx_A = 0, idx_B = 0; // 공통 부분 추적시 사용할 인덱스 정보
queue<uint16_t> q;             // 공통 부분 수열 중 사전 순으로 가장 나중인 수열

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    // 입력
    cin >> N;
    A.resize(N);
    for (uint16_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> M;
    B.resize(M);
    for (uint16_t i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    /*큰 것부터 순서대로 고르기*/
    /*중복값을 처리하기 위해 공통 값 찾으면 다시 100부터*/
    while (idx_A < N && idx_B < M)
    {
        bool found = false;
        for (uint16_t val = 100; val >= 1; val--)
        {
            bool in_A = false;
            bool in_B = false;
            uint16_t i = idx_A;
            uint16_t j = idx_B;

            for (i; i < N; i++)
            {
                if (A[i] == val)
                {
                    in_A = true;
                    break;
                }
            }
            for (j; j < M; j++)
            {
                if (B[j] == val)
                {
                    in_B = true;
                    break;
                }
            }

            if (in_A && in_B)
            {
                idx_A = i + 1;
                idx_B = j + 1;
                q.push(val);
                found = true;
                break;
            }
        }

        /* 못 찾으면 종료 */
        if (!found)
            break;
    }

    cout << q.size() << '\n';

    if (q.empty())
    {
        return 0;
    }

    cout << q.front();
    q.pop();

    while (!q.empty())
    {
        cout << ' ' << q.front();
        q.pop();
    }
    cout << '\n';

    return 0;
}
