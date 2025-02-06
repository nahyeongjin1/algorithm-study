/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1018                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1018                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 22:06:44 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const short SIZE = 8;
    short n, m, min = 32;
    std::vector<std::string> board;
    std::string input;

    std::cin >> n >> m;
    for (short i = 0; i < n; i++)
    {
        std::cin >> input;
        board.push_back(input);
    }

    for (short i = 0; i <= m - SIZE; i++)
    {
        for (short j = 0; j <= n - SIZE; j++)
        {
            short countCaseB = 0;
            short countCaseW = 0;
            for (short k = i; k < i + 8; k++)
            {
                for (short l = j; l < j + 8; l++)
                {
                    char nowComparisonB, nowComparisonW;
                    if (((k - i) % 2 == 0 && (l - j) % 2 == 0) || ((k - i) % 2 == 1 && (l - j) % 2 == 1))
                    {
                        nowComparisonB = 'B';
                        nowComparisonW = 'W';
                    }
                    else
                    {
                        nowComparisonB = 'W';
                        nowComparisonW = 'B';
                    }

                    if (board.at(l).at(k) != nowComparisonB)
                    {
                        countCaseB += 1;
                    }
                    else if (board.at(l).at(k) != nowComparisonW)
                    {
                        countCaseW += 1;
                    }
                }
            }
            if (min > countCaseB)
            {
                min = countCaseB;
            }
            if (min > countCaseW)
            {
                min = countCaseW;
            }
        }
    }
    std::cout << min;
    return 0;
}