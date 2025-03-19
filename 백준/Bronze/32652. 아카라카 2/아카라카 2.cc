/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 32652                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/32652                          #+#        #+#      #+#    */
/*   Solved: 2025/03/19 14:50:45 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t k; // 1 <= k <= 50
    std::cin >> k;
    std::cout << "AKA";
    while (k--)
    {
        std::cout << "RAKA";
    }
    std::cout << '\n';

    return 0;
}