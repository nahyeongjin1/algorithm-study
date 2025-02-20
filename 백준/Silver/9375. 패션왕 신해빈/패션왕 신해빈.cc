/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9375                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9375                           #+#        #+#      #+#    */
/*   Solved: 2025/02/20 21:23:42 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using std::vector, std::string, std::pair;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short t;

    std::cin >> t;
    for (short i = 0; i < t; i++)
    {
        short n;
        long long int output = 1;
        std::cin >> n;
        vector<pair<string, vector<string>>> clothes;

        for (short j = 0; j < n; j++)
        {
            string name, category;
            std::cin >> name >> category;

            // 첫 의상
            if (j == 0)
            {
                clothes.push_back({category, vector<string>(1, name)});
                continue;
            }
            vector<pair<string, vector<string>>>::iterator k;
            for (k = clothes.begin(); k != clothes.end(); k++)
            {
                // 중복되는 의상 종류가 있는 경우
                if (category == k->first)
                {
                    k->second.push_back(name);
                    break;
                }
            }
            // 중복되는 의상 종류가 없는 경우
            if (k == clothes.end())
            {
                clothes.push_back({category, vector<string>(1, name)});
            }
        }
        for (auto j = clothes.begin(); j != clothes.end(); j++)
        {
            output *= (j->second.size() + 1);
        }
        // 의상이 0개일 경우에는 output의 초기값이 1이기에 문제 없음
        std::cout << output - 1 << '\n';
    }

    return 0;
}