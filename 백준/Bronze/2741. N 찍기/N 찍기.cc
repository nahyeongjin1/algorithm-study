/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2741                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2741                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:46:28 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t n;

    std::cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        std::cout << i << '\n';
    }

    return 0;
}