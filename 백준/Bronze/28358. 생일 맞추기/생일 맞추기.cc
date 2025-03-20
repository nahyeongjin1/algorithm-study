/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28358                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28358                          #+#        #+#      #+#    */
/*   Solved: 2025/03/19 14:55:13 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t t;
    std::cin >> t;
    while (t--)
    {
        vector<uint16_t> digits_in_id(10);
        for (uint16_t i = 0; i < 10; i++)
        {
            std::cin >> digits_in_id[i];
        }

        vector<uint16_t> month_days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        uint16_t count = 0;

        for (uint16_t m = 1; m <= 12; m++)
        {
            std::string m_str = std::to_string(m);
            bool month_valid = true;
            for (char ch : m_str)
            {
                if (digits_in_id[ch - '0'])
                {
                    month_valid = false;
                    break;
                }
            }
            if (!month_valid)
            {
                continue;
            }

            for (int d = 1; d <= month_days[m - 1]; d++)
            {
                std::string d_str = std::to_string(d);
                bool day_valid = true;
                for (char ch : d_str)
                {
                    if (digits_in_id[ch - '0'])
                    {
                        day_valid = false;
                        break;
                    }
                }
                if (day_valid)
                {
                    count++;
                }
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}