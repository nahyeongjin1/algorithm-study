/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2869                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2869                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 21:27:23 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, v, output;

    std::cin >> a >> b >> v;
    v -= b;
    output = ceil(v / (a - b));
    output += (v % (a - b) == 0) ? 0 : 1;
    std::cout << output;

    return 0;
}