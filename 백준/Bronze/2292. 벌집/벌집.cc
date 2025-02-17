/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2292                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2292                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 22:35:27 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    short count = 1;

    std::cin >> n;
    n--;
    while (n > 0)
    {
        n -= count++ * 6;
    }
    std::cout << count;

    return 0;
}