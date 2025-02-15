/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15829                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15829                          #+#        #+#      #+#    */
/*   Solved: 2025/02/15 18:25:10 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <math.h>

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    unsigned long long int hash = 0;
    const int R = 31, M = 1234567891;
    std::string input;
    std::cin >> input;
    std::cin >> input;

    for (auto i = 0; i < input.length(); i++)
    {
        short unique = input.at(i) - 'a' + 1;
        unsigned long long int r = 1;
        for (auto j = 0; j < i; j++)
        {
            r = (r * R) % M;
        }
        hash += (unique * r) % M;
        hash %= M;
    }

    std::cout << hash;
    return 0;
}