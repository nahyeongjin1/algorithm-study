/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17488                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17488                          #+#        #+#      #+#    */
/*   Solved: 2025/03/04 21:15:17 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n, m;
    std::cin >> n >> m;

    vector<uint16_t> sugang_limit(m);
    vector<vector<bool>> result(n, vector<bool>(m, false));

    for (uint16_t i = 0; i < m; i++)
    {
        std::cin >> sugang_limit[i];
    }
    for (uint16_t i = 0; i < 2; i++)
    {
        vector<vector<bool>> suguni(n, vector<bool>(m, false));
        for (uint16_t j = 0; j < n; j++)
        {
            while (true)
            {
                int16_t input;
                std::cin >> input;
                if (input == -1)
                {
                    break;
                }
                suguni[j][input - 1] = true;
            }
        }
        // 각 과목별 count 체크
        for (uint16_t j = 0; j < m; j++)
        {
            uint16_t students = 0;
            vector<bool> apply_list(n, false);
            for (uint16_t k = 0; k < n; k++)
            {
                if (suguni[k][j])
                {
                    students++;
                    apply_list[k] = true;
                }
            }
            if (students <= sugang_limit[j])
            {
                sugang_limit[j] -= students;
                for (auto l = 0; l < n; l++)
                {
                    if (apply_list[l])
                    {
                        result[l][j] = true;
                    }
                }
            }
            else
            {
                sugang_limit[j] = 0;
            }
        }
    }

    for (const auto &r : result)
    {
        bool first = true;
        bool fail = true;
        for (uint16_t i = 0; i < r.size(); i++)
        {
            if (r[i])
            {
                fail = false;
                if (first)
                {
                    first = false;
                    std::cout << i + 1;
                }
                else
                {
                    std::cout << ' ' << i + 1;
                }
            }
        }
        if (fail)
        {
            std::cout << "망했어요";
        }
        std::cout << '\n';
    }

    return 0;
}