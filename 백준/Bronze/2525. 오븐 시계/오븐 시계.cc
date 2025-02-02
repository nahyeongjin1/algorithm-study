/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2525                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2525                           #+#        #+#      #+#    */
/*   Solved: 2025/02/02 15:15:18 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

int main()
{
    int ih, im, em, oh, om;
    std::cin >> ih >> im >> em;
    em += im;
    if (em >= 60)
    {
        oh = ih + (int)floor(em / 60);
        oh = (oh >= 24) ? oh - 24 : oh;
        om = em % 60;
    }
    else
    {
        oh = ih;
        om = em;
    }
    std::cout << oh << ' ' << om << std::endl;
    return 0;
}