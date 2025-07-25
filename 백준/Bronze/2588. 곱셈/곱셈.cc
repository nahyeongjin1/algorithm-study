/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2588                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2588                           #+#        #+#      #+#    */
/*   Solved: 2025/02/01 21:23:03 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a * (b % 10) << std::endl;
    std::cout << a * ((b / 10) % 10) << std::endl;
    std::cout << a * ((b / 100) % 10) << std::endl;
    std::cout << a * b << std::endl;
    return 0;
}