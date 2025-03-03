/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18870                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18870                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 16:06:27 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::unique;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t n; // 1 <= n <= 1,000,000
    std::cin >> n;

    vector<int32_t> vec(n, 0);

    for (uint32_t i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }

    vector<int32_t> sorted = vec;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    std::unordered_map<int32_t, int32_t> um;

    for (uint32_t i = 0; i < sorted.size(); i++)
    {
        um[sorted[i]] = i;
    }
    for (int32_t i = 0; i < n; i++)
    {
        std::cout << (i ? " " : "") << um[vec[i]];
    }
    std::cout << '\n';

    return 0;
}