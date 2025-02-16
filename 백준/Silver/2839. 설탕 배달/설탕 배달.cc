/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2839                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2839                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 21:27:13 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, output;
    std::cin >> n;
    short mod_five = n % 5;
    short div_five = n / 5;
    if (mod_five == 0)
    {
        output = div_five;
    }
    while (mod_five != 0)
    {
        if (mod_five > n)
        {
            output = -1;
            break;
        }
        short mod_three = mod_five % 3;
        short div_three = mod_five / 3;
        if (mod_three == 0)
        {
            output = div_five + div_three;
            break;
        }
        mod_five += 5;
        div_five -= 1;
    }

    std::cout << output;

    return 0;
}