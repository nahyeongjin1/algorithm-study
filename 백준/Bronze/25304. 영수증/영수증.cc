/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25304                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25304                          #+#        #+#      #+#    */
/*   Solved: 2025/02/04 21:23:22 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    int total, n, a, b;
    std::string output;
    std::cin >> total;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        total -= a * b;
    }

    output = (total == 0) ? "Yes" : "No";
    std::cout << output << std::endl;
}