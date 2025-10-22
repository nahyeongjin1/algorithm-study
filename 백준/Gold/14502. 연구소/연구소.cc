#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n, m, safe_area = 0;

    std::cin >> n >> m;

    // 동적할당을 위한 벡터 사용
    vector<vector<uint16_t>> map(n, vector<uint16_t>(m, 0));
    vector<pair<uint16_t, uint16_t>> empty_space;

    // BFS를 위해 queue로 복사 예정
    queue<pair<uint16_t, uint16_t>> viruses;

    // 지도 입력 & 불필요한 탐색을 줄이기 위해 빈 칸과 바이러스의 좌표 저장
    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < m; j++)
        {
            uint16_t input;
            std::cin >> input;
            if (input == 0)
                empty_space.push_back({i, j});
            else
            {
                if (input == 2)
                    viruses.push({i, j});
                map[i][j] = input;
            }
        }
    }

    /**
     * 3중 for문 활용한 brute-force
     * 겹치지 않는 세 좌표를 선택
     * 모든 가능한 조합에 대하여 벽 설치 & 바이러스 전파
     */

    uint16_t loop = empty_space.size();
    for (uint16_t i = 0; i < loop - 2; i++)
    {
        for (uint16_t j = i + 1; j < loop - 1; j++)
        {
            for (uint16_t k = j + 1; k < loop; k++)
            {
                // 지도 원본 보존을 위해 복사본 사용
                vector<vector<uint16_t>> copied_map(map);

                // 벽 3개 설치
                const auto &[y_i, x_i] = empty_space[i];
                const auto &[y_j, x_j] = empty_space[j];
                const auto &[y_k, x_k] = empty_space[k];
                copied_map[y_i][x_i] = 1;
                copied_map[y_j][x_j] = 1;
                copied_map[y_k][x_k] = 1;

                // 바이러스 전파 (BFS)
                queue<pair<uint16_t, uint16_t>> q(viruses);
                while (!q.empty())
                {
                    const auto &[cur_y, cur_x] = q.front();
                    q.pop();
                    if (cur_y != 0 && copied_map[cur_y - 1][cur_x] == 0)
                    {
                        q.push({cur_y - 1, cur_x});
                        copied_map[cur_y - 1][cur_x] = 2;
                    }
                    if (cur_x != 0 && copied_map[cur_y][cur_x - 1] == 0)
                    {
                        q.push({cur_y, cur_x - 1});
                        copied_map[cur_y][cur_x - 1] = 2;
                    }
                    if (cur_y != n - 1 && copied_map[cur_y + 1][cur_x] == 0)
                    {
                        q.push({cur_y + 1, cur_x});
                        copied_map[cur_y + 1][cur_x] = 2;
                    }
                    if (cur_x != m - 1 && copied_map[cur_y][cur_x + 1] == 0)
                    {
                        q.push({cur_y, cur_x + 1});
                        copied_map[cur_y][cur_x + 1] = 2;
                    }
                }

                // 바이러스가 전파되지 않은 공간 카운팅
                uint16_t count = 0;
                for (const auto &[y, x] : empty_space)
                {
                    count += (copied_map[y][x] == 0) ? 1 : 0;
                }

                // safe_area와 이번 회차의 안전 영역에 max
                safe_area = std::max(safe_area, count);
            }
        }
    }

    std::cout << safe_area << '\n';

    return 0;
}