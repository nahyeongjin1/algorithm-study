/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1008                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1008                           #+#        #+#      #+#    */
/*   Solved: 2025/02/01 19:17:55 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    double a, b;
    std::cin >> a >> b;
    std::cout.precision(12);
    std::cout << std::fixed;
    std::cout << a / b << std::endl;
    return 0;
}