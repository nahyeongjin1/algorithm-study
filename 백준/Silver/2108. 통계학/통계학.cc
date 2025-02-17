/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2108                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2108                           #+#        #+#      #+#    */
/*   Solved: 2025/02/17 18:21:29 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool Compare(int a, int b)
{
    return a < b;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, sum = 0;
    int min_val = 4000, max_val = -4000;
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<int> frequent(8001, 0);
    for (auto i = 0; i < n; i++)
    {
        int input;

        std::cin >> input;

        vec.at(i) = input;
        sum += input;

        // for range
        min_val = std::min(input, min_val);
        max_val = std::max(input, max_val);

        // for mode
        // -4000 == 0, 0 == 4000, -3999 == 1
        frequent.at(input + 4000) += 1;
    }

    int max_freq = 0;
    for (auto i = 0; i < 8001; i++)
    {
        if (frequent.at(i) > max_freq)
        {
            max_freq = frequent.at(i);
        }
    }
    std::vector<int> modes;
    int mode;
    for (auto i = 0; i < 8001; i++)
    {
        if (frequent.at(i) == max_freq)
        {
            modes.push_back(i - 4000);
        }
    }

    if (modes.size() == 1)
    {
        mode = modes.front();
    }
    else
    {
        mode = modes.at(1);
    }

    std::sort(vec.begin(), vec.end(), Compare);
    std::cout << std::lround((double)sum / n) << '\n'
              << vec.at(n / 2) << '\n'
              << mode << '\n'
              << max_val - min_val;

    return 0;
}