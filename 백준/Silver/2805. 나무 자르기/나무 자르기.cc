/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2805                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2805                           #+#        #+#      #+#    */
/*   Solved: 2025/02/23 18:37:46 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    long long m;
    std::cin >> n >> m;
    std::vector<long long> trees(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> trees.at(i);
    }

    long long min = 0;
    long long max = *std::max_element(trees.begin(), trees.end());
    long long ans = 0;
    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (trees[i] > mid)
                sum += trees[i] - mid;
        }
        if (sum >= m)
        {
            ans = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    std::cout << ans << "\n";
    return 0;
}
