/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1920                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1920                           #+#        #+#      #+#    */
/*   Solved: 2025/02/17 21:51:08 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

short binary_search(const std::vector<int> &a, const int input)
{
    int min, max;
    min = 0;
    max = a.size() - 1;

    while (max >= min)
    {
        int mid = (min + max) / 2;
        if (a.at(mid) < input)
        {
            min = mid + 1;
        }
        if (a.at(mid) > input)
        {
            max = mid - 1;
        }
        if (a.at(mid) == input)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int input;
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto i = 0; i < n; i++)
    {
        std::cin >> a.at(i);
    }
    std::sort(a.begin(), a.end());
    int m;
    std::cin >> m;
    for (auto i = 0; i < m; i++)
    {
        std::cin >> input;
        std::cout << binary_search(a, input) << '\n';
    }

    return 0;
}