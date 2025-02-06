/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10807                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10807                          #+#        #+#      #+#    */
/*   Solved: 2025/02/06 20:46:00 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short n, input, v, output = 0;
    std::vector<short> vector;
    std::cin >> n;
    for (short i = 0; i < n; i++)
    {
        std::cin >> input;
        vector.push_back(input);
    }
    std::cin >> v;
    for (short i = 0; i < n; i++)
    {
        if (vector.at(i) == v)
        {
            output += 1;
        }
    }
    std::cout << output;
    return 0;
}