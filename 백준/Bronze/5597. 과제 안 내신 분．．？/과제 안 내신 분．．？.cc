/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5597                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5597                           #+#        #+#      #+#    */
/*   Solved: 2025/02/06 21:18:23 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short input;
    const short MAX = 30;
    std::list<short> number;

    for (short i = 0; i < MAX; i++)
    {
        number.push_back(i + 1);
    }
    for (short i = 0; i < MAX - 2; i++)
    {
        std::cin >> input;
        number.remove(input);
    }
    std::cout << number.front() << '\n'
              << number.back();
    return 0;
}