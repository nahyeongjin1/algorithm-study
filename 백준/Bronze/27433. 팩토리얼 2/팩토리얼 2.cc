/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27433                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27433                          #+#        #+#      #+#    */
/*   Solved: 2025/02/19 21:11:20 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n;
    long long int factorial = 1;
    std::cin >> n;

    for (auto i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    std::cout << factorial;

    return 0;
}