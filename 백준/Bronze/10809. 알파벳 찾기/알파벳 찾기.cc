/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10809                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10809                          #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:47:10 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string input;
    const short LOOP = 26;
    short alphabet[LOOP];

    for (short i = 0; i < LOOP; i++)
    {
        alphabet[i] = -1;
    }

    std::cin >> input;
    for (short i = 0; i < input.length(); i++)
    {
        short index = input.at(i) - 'a';
        if (alphabet[index] == -1)
        {
            alphabet[index] = i;
        }
    }

    for (short i = 0; i < LOOP; i++)
    {
        std::cout << alphabet[i] << ' ';
    }
    return 0;
}