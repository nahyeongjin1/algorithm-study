/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5525                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5525                           #+#        #+#      #+#    */
/*   Solved: 2025/02/26 16:32:28 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef unsigned int ui;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    ui n;
    ui m;
    std::string s;
    std::cin >> n >> m >> s;

    ui count = 0;
    ui output = 0;

    for (auto i = 1; i < s.size() - 1; i++)
    {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I')
        {
            count++;
            i++;
            if (count >= n)
            {
                output++;
            }
        }
        else
        {
            count = 0;
        }
    }
    std::cout << output << '\n';

    return 0;
}