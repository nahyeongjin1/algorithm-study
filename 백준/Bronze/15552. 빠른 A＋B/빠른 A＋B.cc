/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15552                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15552                          #+#        #+#      #+#    */
/*   Solved: 2025/02/04 21:42:04 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int test_case;
    short a, b;

    std::cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        std::cin >> a >> b;
        std::cout << a + b << '\n';
    }

    return 0;
}