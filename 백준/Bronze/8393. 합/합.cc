/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8393                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8393                           #+#        #+#      #+#    */
/*   Solved: 2025/02/04 21:13:28 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int n;
    long long output = 0;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        output += i;
    }

    std::cout << output << std::endl;
    return 0;
}