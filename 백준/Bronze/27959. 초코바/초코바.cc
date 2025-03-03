/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27959                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27959                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 21:14:57 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 100
    uint16_t m; // 1 <= m <= 10,000

    std::cin >> n >> m;

    std::string output = (n * 100 >= m) ? "Yes" : "No";
    std::cout << output << '\n';

    return 0;
}