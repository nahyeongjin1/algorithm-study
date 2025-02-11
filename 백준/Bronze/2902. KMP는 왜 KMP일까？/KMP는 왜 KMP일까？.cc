/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2902                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2902                           #+#        #+#      #+#    */
/*   Solved: 2025/02/11 11:53:08 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string input;

    std::cin >> input;
    std::cout << input.at(0);
    for (auto i = 1; i < input.length(); i++)
    {
        if (input.at(i) == '-')
        {
            std::cout << input.at(i + 1);
        }
    }
    return 0;
}