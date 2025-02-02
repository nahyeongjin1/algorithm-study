/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2884                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2884                           #+#        #+#      #+#    */
/*   Solved: 2025/02/02 15:07:44 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int ih, im, oh, om;
    std::cin >> ih >> im;

    if (ih == 0 && im < 45)
    {
        oh = 23;
        om = im + 60 - 45;
    }
    else if (im < 45)
    {
        oh = ih - 1;
        om = im + 60 - 45;
    }
    else
    {
        oh = ih;
        om = im - 45;
    }

    std::cout << oh << ' ' << om << std::endl;
    return 0;
}