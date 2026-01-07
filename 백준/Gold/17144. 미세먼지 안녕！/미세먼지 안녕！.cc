#include <iostream>
#include <vector>
#include <array>

using namespace std;

/**
 * -1: 공기청정기
 * 0 ~1 _000: 미세먼지 양
 */
array<vector<vector<int16_t>>, 2> fine_dust;
uint16_t R, C, T; // (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000)
int16_t purifier_top = -1;
int16_t purifier_down;
uint32_t total = 0;
pair<int16_t, int16_t> diff[] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> R >> C >> T;

    fine_dust[0].resize(R, vector<int16_t>(C, 0));
    fine_dust[1].resize(R, vector<int16_t>(C, 0));

    // 먼저 2개의 방 정보를 똑같이 입력받음
    for (uint16_t i = 0; i < R; i++)
    {
        for (uint16_t j = 0; j < C; j++)
        {
            int16_t temp;
            cin >> temp;
            if (temp == -1 && purifier_top == -1)
            {
                purifier_top = i;
                purifier_down = i + 1;
            }
            fine_dust[0][i][j] = temp;
            fine_dust[1][i][j] = temp;
        }
    }

    while (T--)
    {
        // T % 2로 보존시킬 공간과 확산 & 공기청정기 가동할 공간 결정
        uint16_t reserve_idx = T % 2;
        uint16_t target_idx = (T + 1) % 2;

        // 확산 결과를 합하고 공기청정기 작동결과까지 저장할 2차원 벡터 초기화
        for (auto &vec : fine_dust[target_idx])
        {
            for (uint16_t i = 0; i < vec.size(); i++)
            {
                // 공기청정기 위치를 잃지 않기 위해 -1은 유지하고 나머지는 0 할당
                vec[i] = (vec[i] == -1 ? -1 : 0);
            }
        }

        /* 1. 확산 */
        for (int16_t cur_r = 0; cur_r < R; cur_r++)
        {
            for (int16_t cur_c = 0; cur_c < C; cur_c++)
            {
                /*reserve_idx traverse하면서 더해*/
                int16_t amount = fine_dust[reserve_idx][cur_r][cur_c];
                /*공기청정기면 패스*/
                if (amount == -1)
                    continue;
                /*복사*/
                fine_dust[target_idx][cur_r][cur_c] += amount;
                /*확산될 양*/
                amount /= 5;
                /*reserve_idx 기준으로 상하좌우 빈 공간 찾기*/
                for (auto [dr, dc] : diff)
                {
                    int16_t next_r = cur_r + dr;
                    int16_t next_c = cur_c + dc;

                    /*dr과 dc를 더해서 r과 c의 범위를 벗어나는지,*/
                    if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C)
                        continue;
                    /*purifier_top(+1) && col == 0인지 확인*/
                    if (next_c == 0 && (next_r == purifier_top || next_r == purifier_top + 1))
                        continue;

                    /*target_idx 기준으로 옆 공간에 amount 더하고*/
                    fine_dust[target_idx][next_r][next_c] += amount;
                    /*기준 위치는 amount를 빼고*/
                    fine_dust[target_idx][cur_r][cur_c] -= amount;
                }
            }
        }

        /* 2. 공기청정기 작동 */

        /*위쪽*/
        for (int16_t i = purifier_top - 1; i > 0; i--)
        {
            fine_dust[target_idx][i][0] = fine_dust[target_idx][i - 1][0];
        }
        for (int16_t i = 0; i < C - 1; i++)
        {
            fine_dust[target_idx][0][i] = fine_dust[target_idx][0][i + 1];
        }
        for (int16_t i = 0; i < purifier_top; i++)
        {
            fine_dust[target_idx][i][C - 1] = fine_dust[target_idx][i + 1][C - 1];
        }
        for (int16_t i = C - 1; i > 1; i--)
        {
            fine_dust[target_idx][purifier_top][i] = fine_dust[target_idx][purifier_top][i - 1];
        }

        /*아래쪽*/
        for (int16_t i = purifier_down + 1; i < R - 1; i++)
        {
            fine_dust[target_idx][i][0] = fine_dust[target_idx][i + 1][0];
        }
        for (int16_t i = 0; i < C - 1; i++)
        {
            fine_dust[target_idx][R - 1][i] = fine_dust[target_idx][R - 1][i + 1];
        }
        for (int16_t i = R - 1; i > purifier_down; i--)
        {
            fine_dust[target_idx][i][C - 1] = fine_dust[target_idx][i - 1][C - 1];
        }
        for (int16_t i = C - 1; i > 1; i--)
        {
            fine_dust[target_idx][purifier_down][i] = fine_dust[target_idx][purifier_down][i - 1];
        }

        // 공기청정기 바람 바로 앞 자리 0으로 갱신
        fine_dust[target_idx][purifier_top][1] = 0;
        fine_dust[target_idx][purifier_down][1] = 0;
    }

    // 전체 합
    // fine_dust[1] 에 들어있는거 합하면 됨
    for (auto &vec : fine_dust[1])
    {
        for (auto &v : vec)
        {
            total += v;
        }
    }

    cout << total + 2 << '\n';

    return 0;
}