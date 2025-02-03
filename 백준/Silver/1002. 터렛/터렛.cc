/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1002                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1002                           #+#        #+#      #+#    */
/*   Solved: 2025/02/02 16:10:12 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

int main()
{
    long long test_case;
    long long x_1, y_1, r_1, x_2, y_2, r_2;
    long long smallRadius, bigRadius;
    long long squaredDistance; // 최대한 정수 범위 내에서 계산하기 위함함
    int output;

    std::cin >> test_case;

    for (long long i = 0; i < test_case; i++)
    {
        std::cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

        // 원 중심 사이의 거리
        squaredDistance = (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);

        // 계산 편의성을 위해 큰 원과 작은 원 분류
        if (r_1 > r_2)
        {
            bigRadius = r_1;
            smallRadius = r_2;
        }
        else
        {
            bigRadius = r_2;
            smallRadius = r_1;
        }

        // 동일 좌표 동일 반지름 = 점 무한 개 발생
        if (squaredDistance == 0 && r_1 == r_2)
        {
            output = -1;
        }
        // 밖에서 접한거
        else if (squaredDistance == (bigRadius + smallRadius) * (bigRadius + smallRadius))
        {
            output = 1;
        }
        // 안에서 접한거
        else if (squaredDistance == (bigRadius - smallRadius) * (bigRadius - smallRadius))
        {
            output = 1;
        }
        // 2개의 교점이 발생하는
        else if ((bigRadius + smallRadius) * (bigRadius + smallRadius) > squaredDistance && squaredDistance > (bigRadius - smallRadius) * (bigRadius - smallRadius))
        {
            output = 2;
        }
        // 교점 없이 작은 원이 큰 원 안에 속하는거
        else if (squaredDistance < (bigRadius - smallRadius) * (bigRadius - smallRadius))
        {
            output = 0;
        }
        // 교점 없이 두 원이 떨어져있는거
        else if (squaredDistance > (bigRadius + smallRadius) * (bigRadius + smallRadius))
        {
            output = 0;
        }

        std::cout << output << std::endl;
    }
    return 0;
}