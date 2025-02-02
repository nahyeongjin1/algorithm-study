/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9498                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9498                           #+#        #+#      #+#    */
/*   Solved: 2025/02/02 14:42:02 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int input;
    char output;
    std::cin >> input;
    if (input <= 100 && input >= 90)
        output = 'A';
    else if (input <= 89 && input >= 80)
        output = 'B';
    else if (input <= 79 && input >= 70)
        output = 'C';
    else if (input <= 69 && input >= 60)
        output = 'D';
    else
        output = 'F';
    std::cout << output << std::endl;
    return 0;
}