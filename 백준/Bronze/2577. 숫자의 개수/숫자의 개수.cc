/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2577                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2577                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:46:20 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const short SIZE = 10;
    int a, b, c;
    int output[SIZE];
    std::string temp;

    std::cin >> a >> b >> c;
    temp = std::to_string(a * b * c);
    for (short i = 0; i < SIZE; i++)
    {
        output[i] = 0;
    }
    for (short i = 0; i < temp.length(); i++)
    {
        output[temp.at(i) - '0']++;
    }
    for (short i = 0; i < SIZE; i++)
    {
        std::cout << output[i] << '\n';
    }
    return 0;
}