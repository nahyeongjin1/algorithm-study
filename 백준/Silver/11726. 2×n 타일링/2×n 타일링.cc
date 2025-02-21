/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11726                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11726                          #+#        #+#      #+#    */
/*   Solved: 2025/02/20 23:20:35 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n;
    std::cin >> n;

    std::vector<unsigned long long> fibonacci(n);

    fibonacci.at(0) = 1;

    if (n >= 2)
    {
        fibonacci.at(1) = 2;
    }
    for (auto i = 2; i < n; i++)
    {
        fibonacci.at(i) = (fibonacci.at(i - 1) + fibonacci.at(i - 2)) % 10007;
    }

    std::cout << fibonacci.at(n - 1) << '\n';

    return 0;
}