/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10430                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10430                          #+#        #+#      #+#    */
/*   Solved: 2025/02/01 21:19:46 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (a + b) % c << std::endl;
    std::cout << ((a % c) + (b % c)) % c << std::endl;
    std::cout << (a * b) % c << std::endl;
    std::cout << ((a % c) * (b % c)) % c << std::endl;
    return 0;
}