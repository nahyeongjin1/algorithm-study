/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 30030                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/30030                          #+#        #+#      #+#    */
/*   Solved: 2025/02/19 21:14:09 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short a, b;
    std::cin >> b;
    a = (b / 11) * 10;
    std::cout << a;

    return 0;
}