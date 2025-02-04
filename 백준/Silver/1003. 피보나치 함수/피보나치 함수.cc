/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1003                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1003                           #+#        #+#      #+#    */
/*   Solved: 2025/02/03 23:41:26 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    const int TEST = 42;
    int test_case, input;
    std::vector<long long> fibonacci;
    long long odd = 0, even = 1;

    // 예제를 확인해보니 {1, 0}부터 시작하는 피보나치 수열로 확인됨.
    // N번째와 N+1번째를 출력해주면 됨
    // 40까지의 경우의 수를 전부 벡터에 순서대로
    for (int i = 0; i < TEST; i++)
    {
        if (i % 2 == 0)
        {
            fibonacci.push_back(even);
            even += odd;
        }
        else
        {
            fibonacci.push_back(odd);
            odd += even;
        }
    }

    std::cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        std::cin >> input;
        std::cout << fibonacci[input] << ' ' << fibonacci[input + 1] << std::endl;
    }
    return 0;
}