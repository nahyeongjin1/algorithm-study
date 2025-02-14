/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1654                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1654                           #+#        #+#      #+#    */
/*   Solved: 2025/02/13 23:38:01 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long k, n, max, min, mid;

    std::cin >> k >> n;
    std::vector<long long> fostjs(k);
    for (auto i = 0; i < k; i++)
    {
        std::cin >> fostjs.at(i);
        max += fostjs.at(i);
    }
    min = 1;
    max = max / n + 1;
    mid = (max + min) / 2;

    while (max > min + 1)
    {
        long long count = 0;

        for (auto i : fostjs)
        {
            count += i / mid;
        }

        if (count >= n)
        {
            min = mid;
        }
        else if (count < n)
        {
            max = mid;
        }
        mid = (max + min) / 2;
    }

    std::cout << mid;

    return 0;
}