/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6888                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6888                           #+#        #+#      #+#    */
/*   Solved: 2025/02/12 19:14:12 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short x, y;

    std::cin >> x >> y;
    for (auto i = x; i <= y; i += 60)
    {
        std::cout << "All positions change in year " << i << '\n';
    }

    return 0;
}
