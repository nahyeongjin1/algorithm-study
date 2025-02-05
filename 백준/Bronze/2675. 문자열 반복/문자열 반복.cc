/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2675                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2675                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 11:20:42 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short t, r;
    std::string s;
    std::cin >> t;
    for (short i = 0; i < t; i++)
    {
        std::string p = "";
        std::cin >> r >> s;
        for (short j = 0; j < s.length(); j++)
        {
            for (short k = 0; k < r; k++)
            {
                p += s[j];
            }
        }
        std::cout << p << '\n';
        p.empty();
    }
    return 0;
}