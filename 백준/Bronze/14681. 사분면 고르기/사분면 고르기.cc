/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14681                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14681                          #+#        #+#      #+#    */
/*   Solved: 2025/02/02 15:04:45 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int x, y, output;
    std::cin >> x >> y;
    if (x > 0 && y > 0)
        output = 1;
    else if (x < 0 && y > 0)
        output = 2;
    else if (x < 0 && y < 0)
        output = 3;
    else
        output = 4;
    std::cout << output << std::endl;
    return 0;
}