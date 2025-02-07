/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1546                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1546                           #+#        #+#      #+#    */
/*   Solved: 2025/02/07 19:52:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short n;
    long double m = 0, input, average = 0;
    std::vector<long double> test_scores;

    std::cin >> n;
    for (short i = 0; i < n; i++)
    {
        std::cin >> input;
        m = (input > m) ? input : m;
        test_scores.push_back(input);
    }
    for (short i = 0; i < n; i++)
    {
        test_scores.at(i) = test_scores.at(i) / m * (long double)100.0;
        average += test_scores.at(i);
    }
    std::cout << average / (long double)n;
    return 0;
}