/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10757                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10757                          #+#        #+#      #+#    */
/*   Solved: 2025/02/12 18:47:22 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a, b, sum = "";
    short temp, carry = 0;

    std::cin >> a >> b;
    if (a.length() > b.length())
    {
        while (a.length() != b.length())
        {
            b = '0' + b;
        }
    }
    else if (a.length() < b.length())
    {
        while (a.length() != b.length())
        {
            a = '0' + a;
        }
    }
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (auto i = 0; i < a.length(); i++)
    {
        temp = (a.at(i) - '0') + (b.at(i) - '0') + carry;
        carry = temp / 10;
        temp = temp % 10;
        sum += (temp + '0');
    }
    std::reverse(sum.begin(), sum.end());

    if (carry == 1)
    {
        sum = '1' + sum;
    }

    std::cout << sum;

    return 0;
}