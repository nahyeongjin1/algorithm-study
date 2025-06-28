/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9663                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9663                           #+#        #+#      #+#    */
/*   Solved: 2025/06/24 09:47:13 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

// 카운트를 위한 전역 변수
uint64_t count = 0;

void backtrack(uint32_t n, uint32_t col, uint32_t left_diag, uint32_t right_diag, uint32_t row);

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    std::cin >> n;

    // 초기 상태로 백트래킹 함수 호출
    backtrack(n, 0, 0, 0, 0);

    // 결과 출력
    std::cout << count << '\n';

    return 0;
}

/**
 * @brief 백트래킹을 사용하여 N-Queen 문제를 해결
 *
 * @param n 체스판의 크기 (N)
 * @param col 현재 열에 퀸이 배치된 상태를 비트마스크로 표현
 * @param left_diag 왼쪽 대각선에 퀸이 배치된 상태를 비트마스크로 표현
 * @param right_diag 오른쪽 대각선에 퀸이 배치된 상태를 비트마스크로 표현
 * @param row 현재 행 번호
 */
void backtrack(uint32_t n, uint32_t col, uint32_t left_diag, uint32_t right_diag, uint32_t row)
{
    // 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수를 추적
    if (row == n)
    {
        count++;
        return;
    }

    for (uint16_t c = 0; c < n; ++c)
    {
        // 현재 열, 왼쪽 대각선, 오른쪽 대각선에 퀸을 배치할 수 있는지 확인
        if ((col & (1U << c)) || (left_diag & (1U << (row + c))) || (right_diag & (1U << (row - c + n - 1))))
        {
            continue; // 이미 공격 가능한 위치에 퀸이 있는 경우, 다음 열로
        }

        // 퀸을 현재 위치에 배치
        backtrack(n, col | (1U << c), left_diag | (1U << (row + c)), right_diag | (1U << (row - c + n - 1)), row + 1);
    }
}