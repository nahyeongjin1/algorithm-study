/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10818                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10818                          #+#        #+#      #+#    */
/*   Solved: 2025/02/05 11:20:51 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n, input, min, max;
    std::cin >> n >> input;
    min = input;
    max = input;
    for (int i = 1; i < n; i++)
    {
        std::cin >> input;
        if (input > max)
            max = input;
        if (input < min)
            min = input;
    }
    std::cout << min << ' ' << max << '\n';
    return 0;
}