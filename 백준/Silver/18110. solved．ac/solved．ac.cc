/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18110                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18110                          #+#        #+#      #+#    */
/*   Solved: 2025/02/14 22:24:00 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    long long outlier;
    long double output = 0;
    short input;
    std::vector<short> difficulties;

    std::cin >> n;
    if (n == 0)
    {
        std::cout << 0;
        return 0;
    }

    outlier = std::llround(n * 0.15);

    for (auto i = 0; i < n; i++)
    {
        std::cin >> input;
        difficulties.push_back(input);
    }
    std::sort<>(difficulties.begin(), difficulties.end());
    for (auto i = outlier; i < difficulties.size() - outlier; i++)
    {
        output += difficulties.at(i);
    }
    output /= difficulties.size() - 2 * outlier;

    std::cout << std::llround(output);

    return 0;
}