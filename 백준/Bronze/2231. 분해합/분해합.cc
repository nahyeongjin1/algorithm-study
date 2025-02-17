/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2231                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2231                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 22:35:21 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, output = 0;
    std::string str;
    std::cin >> n;

    while (true)
    {
        if (output > n)
        {
            std::cout << 0;
            break;
        }
        int temp = ++output;
        str = std::to_string(output);
        for (auto i = str.begin(); i != str.end(); i++)
        {
            temp += *i - '0';
        }
        if (temp == n)
        {
            std::cout << output;
            break;
        }
    }

    return 0;
}