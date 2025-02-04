/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1004                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1004                           #+#        #+#      #+#    */
/*   Solved: 2025/02/04 20:12:21 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int test_case;
    std::cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int x1, y1, x2, y2;
        int n, output = 0;

        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cin >> n;

        for (int j = 0; j < n; j++)
        {
            int x, y, r;
            std::cin >> x >> y >> r;
            int rSqueared = r * r;
            int dist1Squared = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
            int dist2Squared = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);

            // 둘 다 동시에 속하는 경우
            if (rSqueared >= dist1Squared && rSqueared >= dist2Squared)
            {
                continue;
            }
            // 둘 다 동시에 안 속하는 경우
            if (rSqueared < dist1Squared && rSqueared < dist2Squared)
            {
                continue;
            }
            // 둘 중 하나만 속하는 경우
            else
            {
                output += 1;
            }
        }

        std::cout << output << std::endl;
        output = 0;
    }

    return 0;
}