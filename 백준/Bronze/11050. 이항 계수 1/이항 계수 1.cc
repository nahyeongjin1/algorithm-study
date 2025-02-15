/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11050                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11050                          #+#        #+#      #+#    */
/*   Solved: 2025/02/15 21:12:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, k, temp1, temp2;

    std::cin >> n >> k;
    if (n == k || k == 0)
    {
        std::cout << 1;
        return 0;
    }
    k = ((n - k) < (double)n / 2) ? n - k : k;
    temp1 = n;
    temp2 = k;

    for (auto i = 1; i < k; i++)
    {
        temp1 = temp1 * (n - i);
        temp2 = temp2 * (k - i);
    }
    std::cout << temp1 / temp2;

    return 0;
}