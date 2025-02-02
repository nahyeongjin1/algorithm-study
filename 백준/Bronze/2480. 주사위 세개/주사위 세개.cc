/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2480                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2480                           #+#        #+#      #+#    */
/*   Solved: 2025/02/02 15:42:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    size_t a, b, c;
    long long output;
    std::cin >> a >> b >> c;
    // 같은 눈이 3개
    if (a == b && b == c)
    {
        output = 10000 + a * 1000;
    }
    // 다 다른 경우
    else if (a != b && b != c && c != a)
    {
        // a가 가장 큰 경우
        if (a > b && a > c)
        {
            output = a * 100;
        }
        // b가 가장 큰 경우
        else if (b > c && b > a)
        {
            output = b * 100;
        }
        // c가 가장 큰 경우
        else
        {
            output = c * 100;
        }
    }
    // 같은 눈이 2개
    else
    {
        // a == b
        if (a == b)
        {
            output = 1000 + a * 100;
        }
        // b == c
        else if (b == c)
        {
            output = 1000 + b * 100;
        }
        // c == a
        else
        {
            output = 1000 + c * 100;
        }
    }
    std::cout << output << std::endl;
    return 0;
}