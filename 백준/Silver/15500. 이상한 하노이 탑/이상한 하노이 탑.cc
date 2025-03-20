/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15500                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15500                          #+#        #+#      #+#    */
/*   Solved: 2025/03/20 19:15:07 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using std::deque;
using std::stack;
using std::vector;

struct op
{
    uint16_t from;
    uint16_t to;
    op(uint16_t a, uint16_t b) : from(a), to(b) {}
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 123
    std::cin >> n;

    // 0-indexed: 원판은 모두 첫 번째 작업 장대(인덱스 0)에 있다.
    vector<uint16_t> cur_pos(n, 0);
    vector<stack<uint16_t>> poles(2);
    deque<op> result;

    uint16_t target = n; // 처리할 목표 원판 개수 (가장 큰 원판부터)

    // 입력: 첫 번째 장대에 쌓인 원판들을 맨 아래부터 읽어 스택에 넣음
    while (n--)
    {
        uint16_t input;
        std::cin >> input;
        poles[0].push(input - 1); // 내부적으로는 0-indexed로 저장
    }

    // 목표 원판을 하나씩 세 번째 장대로 옮기는 과정
    while (target--)
    {
        uint16_t pole_num = cur_pos[target];   // 0 or 1
        uint16_t another = (pole_num ? 0 : 1); // 1 or 0
        stack<uint16_t> &cur_pole = poles[pole_num];

        // 현재 장대에서 목표 원판을 찾을 때까지 원판 이동
        while (!cur_pole.empty())
        {
            uint16_t top_plate = cur_pole.top();
            cur_pole.pop();
            // 목표 원판이면 세 번째 장대로 이동
            if (top_plate == target)
            {
                result.push_back({pole_num + 1, 3});
                cur_pos[top_plate] = 2; // 2는 세 번째 장대를 의미
                break;
            }
            // 목표가 아니면 다른 작업 장대로 이동
            poles[another].push(top_plate);
            result.push_back({pole_num + 1, another + 1});
            cur_pos[top_plate] = another;
        }
    }

    // 이동 횟수와 이동 명령들을 출력
    std::cout << result.size() << '\n';
    for (const op &o : result)
    {
        std::cout << o.from << ' ' << o.to << '\n';
    }

    return 0;
}