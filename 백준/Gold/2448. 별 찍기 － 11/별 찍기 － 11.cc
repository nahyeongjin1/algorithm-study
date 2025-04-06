/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2448                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2448                           #+#        #+#      #+#    */
/*   Solved: 2025/03/28 22:17:32 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

vector<string> make_triangle(uint16_t n)
{
    // 기저 사례: n == 3인 경우 기본 삼각형 패턴
    if (n == 3)
    {
        return {
            "  *  ",
            " * * ",
            "*****",
        };
    }

    // 재귀적으로 n/2 크기의 삼각형 패턴 구하기
    vector<string> prev = make_triangle(n / 2);
    vector<string> curr;

    uint16_t total_width = 2 * n - 1;
    uint16_t pad = n / 2;

    // 상단: prev 삼각형을 가운데 정렬
    for (const auto &line : prev)
    {
        string top_line = string(pad, ' ') + line;
        top_line.resize(total_width, ' ');
        curr.push_back(top_line);
    }

    // 하단: prev 삼각형의 각 행을 좌우로 붙여 중간에 공백 추가
    for (const auto &line : prev)
    {
        string bottom_line = line + " " + line;
        bottom_line.resize(total_width, ' ');
        curr.push_back(bottom_line);
    }

    return curr;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // n = 3*2^k (0 <= k <= 10, k는 정수)

    std::cin >> n;

    vector<string> result = make_triangle(n);
    for (const string &str : result)
    {
        std::cout << str << '\n';
    }

    return 0;
}