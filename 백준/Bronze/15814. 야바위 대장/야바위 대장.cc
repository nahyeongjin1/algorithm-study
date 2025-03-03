/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15814                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15814                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 21:45:19 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    uint16_t t;
    std::cin >> s >> t;
    for (uint16_t i = 0; i < t; i++)
    {
        uint16_t a, b;
        std::cin >> a >> b;
        std::swap(s[a], s[b]);
    }
    std::cout << s << '\n';

    return 0;
}