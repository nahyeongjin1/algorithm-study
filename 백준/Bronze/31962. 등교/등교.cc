/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 31962                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/31962                          #+#        #+#      #+#    */
/*   Solved: 2025/02/12 19:13:58 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short n, x, s, t, max = 0;

    std::cin >> n >> x;
    for (auto i = 0; i < n; i++)
    {
        std::cin >> s >> t;
        if (s + t <= x && s > max)
        {
            max = s;
        }
    }
    if (max == 0)
    {
        max = -1;
    }
    std::cout << max;

    return 0;
}