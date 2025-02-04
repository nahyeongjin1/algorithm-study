/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11022                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11022                          #+#        #+#      #+#    */
/*   Solved: 2025/02/04 22:00:41 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    short a, b;

    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> a >> b;
        std::cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << '\n';
    }

    return 0;
}
