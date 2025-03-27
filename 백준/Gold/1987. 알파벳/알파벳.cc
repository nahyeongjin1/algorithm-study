/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1987                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1987                           #+#        #+#      #+#    */
/*   Solved: 2025/03/25 14:48:48 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

uint16_t R, C;
vector<vector<char>> board;
uint16_t max_count = 0;

// 상하좌우 이동을 위한 배열
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// mask는 지금까지 방문한 알파벳을 비트마스크(26비트)로 표현
void dfs(int16_t r, int16_t c, uint16_t count, uint32_t mask)
{
    max_count = std::max(max_count, count);
    for (int i = 0; i < 4; i++)
    {
        int16_t nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;
        uint16_t letter = board[nr][nc] - 'A';
        // 해당 알파벳이 이미 방문되었다면 건너뜀
        if (mask & (1 << letter))
            continue;
        dfs(nr, nc, count + 1, mask | (1 << letter));
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> R >> C;
    board.resize(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            std::cin >> board[i][j];
        }
    }
    // 초기 방문 상태: 시작 칸의 알파벳 방문 처리
    uint32_t initialMask = 1 << (board[0][0] - 'A');
    dfs(0, 0, 1, initialMask);
    std::cout << max_count << "\n";
    return 0;
}