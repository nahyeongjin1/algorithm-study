/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2979                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2979                           #+#        #+#      #+#    */
/*   Solved: 2025/02/19 22:21:10 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    /*
    1-2 1대 1*5 = 5
    2-3 2대 2*3 = 6
    3-4 3대 3*1 = 3
    4-5 3대 3*1 = 3
    5-6 2대 2*3 = 6
    6-7 1대 1*5 = 5
    6-8 1대 1*5 = 5
    5 + 6 + 6 + 6 + 10 = 33
    5
    6
    3
    3
    6
    5
    5
    겹치는 시간 * 대수 * 대수에 따른 요금

    겹치는 시간을 어케 구하노
    그냥 벡터 만들어버릴까
    벡터 3개 만들고 가장 가장 큰 값 들어온거 맞춰서 미리 사이즈 맞춰버려
    그리고 for문 각자 3개 돌려서 0이나 1로 채워놓고
    for문 하나 더 만들어서 더해버려 각 인덱스에서
    0이면 그냥 넘어가는거고
    1이면 a 더해주고
    2면 b 더해주고
    3이면 c 더해주고
     */
    short a, b, c, max = 0, fee = 0;
    std::cin >> a >> b >> c;
    std::vector<std::pair<short, short>> time(3);
    for (auto i = 0; i < 3; i++)
    {
        short start, end;
        std::cin >> start >> end;
        max = (end > max) ? end : max;
        time.at(i) = {start, end};
    }
    std::vector<std::vector<short>> trucks(3, std::vector<short>(max, 0));
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = time.at(i).first - 1; j < time.at(i).second; j++)
        {
            trucks.at(i).at(j) = 1;
        }
    }

    for (auto i = 0; i < max - 1; i++)
    {
        short temp = 0;
        for (auto j = 0; j < 3; j++)
        {
            temp += trucks.at(j).at(i) & trucks.at(j).at(i + 1);
        }
        switch (temp)
        {
        case 1:
            fee += a;
            break;
        case 2:
            fee += b * 2;
            break;
        case 3:
            fee += c * 3;
            break;
        default:
            break;
        }
    }
    std::cout << fee << '\n';

    return 0;
}