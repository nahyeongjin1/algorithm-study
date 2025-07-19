/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14626                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14626                          #+#        #+#      #+#    */
/*   Solved: 2025/07/19 19:47:05 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using std::string;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    string damaged_isbn;
    std::cin >> damaged_isbn;

    size_t pos = damaged_isbn.find('*');

    uint32_t total = 0;

    for (size_t i = 0; i < 13; i++)
    {
        if (i == pos)
            continue;
        total += (i & 1) ? (damaged_isbn[i] - '0') * 3 : (damaged_isbn[i] - '0');
    }
    total %= 10;

    uint16_t result;
    if (pos & 1)
    {
        while (total % 3)
        {
            total += 10;
        }
        total /= 3;
        result = 10 - total;
    }
    else
    {
        result = 10 - total;
    }
    std::cout << result % 10 << '\n';

    return 0;
}