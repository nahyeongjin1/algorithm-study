/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27532                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27532                          #+#        #+#      #+#    */
/*   Solved: 2025/03/20 20:42:22 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    constexpr uint16_t TWELVE = 720;

    uint16_t m; // 1 <= m <= 1,500
    std::cin >> m;
    char temp;
    vector<int32_t> time(m);
    for (uint16_t i = 0; i < m; i++)
    {
        int32_t a, b;
        std::cin >> a >> temp >> b;
        time[i] = (a * 60 + b) % TWELVE; // 12시를 00시로 보기 위해
    }

    uint16_t n = UINT16_MAX;
    for (uint16_t r = 0; r < TWELVE; r++)
    {
        if (n == 1)
        {
            break;
        }
        unordered_set<uint16_t> initial;
        for (uint16_t i = 0; i < m; i++)
        {
            int32_t temp = time[i] - r * i;
            while (temp < 0)
            {
                temp += TWELVE;
            }
            temp %= TWELVE;
            initial.insert(temp);
        }
        n = std::min(n, uint16_t(initial.size()));
    }
    std::cout << n << '\n';

    return 0;
}

/*
모든 R에 대해 연산을 수행
R이 0이상의 모든 정수가 가능하긴 하지만
아날로그 시계에 대한 문제이기에
문제 영역을 12시간, 720분으로 축소할 수 있음
모든 가능한 R에 대해 연산을 수행해주면 문제를 풀 수 있다
 */