#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

enum DIRECTION
{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
};

// 진행방향이 우하방, 행과 열이 증가하는 경우만 존재하기에
// 음수 체크는 하지 않아도 되고 그렇기에 unsigend를 써도 무방
uint16_t n;                                         // [3, 16]
uint32_t cases = 0;                                 // [0, 1_000_000]
vector<vector<bool>> isWall;                        // 벽 위치
queue<pair<DIRECTION, pair<uint16_t, uint16_t>>> q; // {놓여진 방향, {행, 열}}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> n;

    isWall.resize(n, vector<bool>(n, false));

    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < n; j++)
        {
            bool input;
            std::cin >> input;
            isWall[i][j] = input;
        }
    }

    q.push({HORIZONTAL, {0, 1}});

    while (!q.empty())
    {
        auto [cur_dir, cur_coord] = q.front();
        auto [cur_row, cur_col] = cur_coord;
        q.pop();

        if (cur_row == n - 1 && cur_col == n - 1)
        {
            cases++;
            continue;
        }

        switch (cur_dir)
        {
        case HORIZONTAL:

            // 1. 우측 벽 체크해서 있으면 break;
            if (cur_col + 1 > n - 1 || isWall[cur_row][cur_col + 1])
                break;
            q.push({HORIZONTAL, {cur_row, cur_col + 1}});

            // 2. 우하단, 하단 벽 체크
            if (cur_row + 1 > n - 1 || isWall[cur_row + 1][cur_col] || isWall[cur_row + 1][cur_col + 1])
                break;
            q.push({DIAGONAL, {cur_row + 1, cur_col + 1}});

            break;

        case VERTICAL:

            // 1. 하단 벽 체크해서 있으면 break;
            if (cur_row + 1 > n - 1 || isWall[cur_row + 1][cur_col])
                break;
            q.push({VERTICAL, {cur_row + 1, cur_col}});

            // 2. 우하단, 우측 벽 체크
            if (cur_col + 1 > n - 1 || isWall[cur_row][cur_col + 1] || isWall[cur_row + 1][cur_col + 1])
                break;
            q.push({DIAGONAL, {cur_row + 1, cur_col + 1}});

            break;

        case DIAGONAL:

            uint16_t cond = 2;

            // 1. 우측
            if (cur_col + 1 <= n - 1 && !isWall[cur_row][cur_col + 1])
            {
                q.push({HORIZONTAL, {cur_row, cur_col + 1}});
                cond--;
            }

            // 2. 하단
            if (cur_row + 1 <= n - 1 && !isWall[cur_row + 1][cur_col])
            {
                q.push({VERTICAL, {cur_row + 1, cur_col}});
                cond--;
            }

            // 3. 우하단
            if (!cond && !isWall[cur_row + 1][cur_col + 1])
                q.push({DIAGONAL, {cur_row + 1, cur_col + 1}});

            break;
        }
    }

    std::cout << cases << '\n';

    return 0;
}