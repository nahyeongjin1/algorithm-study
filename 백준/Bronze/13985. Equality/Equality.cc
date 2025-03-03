/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13985                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13985                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 21:45:33 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t a, b, c;
    uint8_t sign;
    std::cin >> a >> sign >> b >> sign >> c;
    std::cout << (a + b == c ? "YES" : "NO") << '\n';

    return 0;
}