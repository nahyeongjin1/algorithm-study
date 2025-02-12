/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1259                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1259                           #+#        #+#      #+#    */
/*   Solved: 2025/02/12 21:10:41 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input, reversed_input, output;

    while (true)
    {
        std::cin >> input;
        if (input == "0")
        {
            break;
        }
        reversed_input = input;
        std::reverse(reversed_input.begin(), reversed_input.end());
        output = input == reversed_input ? "yes" : "no";
        std::cout << output << '\n';
    }
    return 0;
}