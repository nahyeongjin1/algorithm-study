// 2239
#include <iostream>
#include <array>

using namespace std;

constexpr uint16_t LEN = 9;
array<array<uint16_t, LEN>, LEN> sudoku;

bool is_valid(uint16_t row, uint16_t col, uint16_t num)
{
    // 행 체크
    for (uint16_t i = 0; i < LEN; i++)
    {
        if (sudoku[i][col] == num)
            return false;
    }

    // 열 체크
    for (uint16_t i = 0; i < LEN; i++)
    {
        if (sudoku[row][i] == num)
            return false;
    }

    // 3x3 박스 체크
    for (uint16_t i = 0; i < 3; i++)
    {
        for (uint16_t j = 0; j < 3; j++)
        {
            if (sudoku[row / 3 * 3 + i][col / 3 * 3 + j] == num)
                return false;
        }
    }

    return true;
}

bool solve(uint16_t row, uint16_t col)
{
    // 빈 칸 찾기
    for (uint16_t i = row; i < LEN; i++)
    {
        // 이미 지나간 위치는 스킵
        for (uint16_t j = (i == row ? col : 0); j < LEN; j++)
        {
            if (sudoku[i][j])
                continue;
            // 빈 칸일 때만 1~9 시도
            for (uint16_t k = 1; k <= 9; k++)
            {
                // 유효하면?
                if (is_valid(i, j, k))
                {
                    // 넣고
                    sudoku[i][j] = k;
                    // 재귀가 true면
                    if (solve(i, j))
                    {
                        return true;
                    }
                    // 재귀가 false면
                    else
                    {
                        sudoku[i][j] = 0;
                    }
                }
            }
            // 1 ~ 9까지 모든 숫자가 유효하지 않으면
            return false;
        }
    }
    // 빈 칸 없을 때
    return true;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    for (uint16_t i = 0; i < LEN; i++)
    {
        for (uint16_t j = 0; j < LEN; j++)
        {
            sudoku[i][j] = getchar() - '0';
        }
        getchar();
    }

    solve(0, 0);

    for (auto s : sudoku)
    {
        for (auto n : s)
        {
            cout << n;
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}
