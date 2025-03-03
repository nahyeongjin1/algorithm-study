/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11282                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11282                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 21:45:39 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    char utf8[4];
    uint16_t unicode = 0;
    std::cin >> unicode;
    unicode += 44031;

    utf8[0] = (0xe0) | ((unicode & 0xf000) >> 12);
    utf8[1] = 128 | ((unicode & 0xf00) >> 6) | ((unicode & 0xc0) >> 6);
    utf8[2] = 128 | (unicode & 0x3f);
    utf8[3] = '\0';

    std::cout << utf8 << '\n';

    return 0;
}