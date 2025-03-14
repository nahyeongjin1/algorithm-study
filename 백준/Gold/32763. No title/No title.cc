/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 32763                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/32763                          #+#        #+#      #+#    */
/*   Solved: 2025/03/11 12:57:15 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::endl;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 3 <= n <= 1,000
    std::cin >> n;
    vector<char> ans(n, '?');
    vector<char> mul(n - 1, '?');
    for (uint16_t i = 0; i < n - 1; i++)
    {
        std::cout << "? " << i + 1 << " * " << i + 2 << endl;
        std::cin >> mul[i];
    }

    int16_t base_index = -1; // 인접 곱 쿼리에서 '+'가 나온 쌍의 시작 인덱스 (0-indexed)
    for (uint16_t i = 0; i < n - 1; i++)
    {
        if (mul[i] == '+')
        {
            base_index = i;
            break;
        }
    }

    if (base_index != -1)
    {
        // 인접한 두 원소가 같은 부호임을 확인한 경우:
        // 해당 쌍에 대해 합 쿼리를 진행하여 실제 부호를 결정한다.
        std::cout << "? " << base_index + 1 << " + " << base_index + 2 << endl;
        char s;
        std::cin >> s; // s는 '+' 또는 '-' (0은 나올 수 없음)
        ans[base_index] = s;
        ans[base_index + 1] = s;

        // 기준 쌍을 기준으로 왼쪽으로 전파
        for (int i = base_index - 1; i >= 0; i--)
        {
            // 곱 쿼리 결과가 '+'면 같은 부호, '-'면 반대 부호
            ans[i] = (mul[i] == '+') ? ans[i + 1] : (ans[i + 1] == '+' ? '-' : '+');
        }

        // 기준 쌍을 기준으로 오른쪽으로 전파
        for (int i = base_index + 1; i < n - 1; i++)
        {
            ans[i + 1] = (mul[i] == '+') ? ans[i] : (ans[i] == '+' ? '-' : '+');
        }
    }
    else
    {
        // 인접한 모든 곱 쿼리의 결과가 '-'인 경우,
        // 수열은 교대 형태임이 보장된다.
        // 교대인 경우, 1번과 3번 원소는 같은 부호이므로 이 둘을 기준으로 삼는다.
        std::cout << "? 1 + 3" << endl;
        char s;
        std::cin >> s; // s는 1번과 3번의 부호 (둘은 같은 부호임)
        ans[0] = s;
        ans[2] = s;
        // 1번과 2번의 곱 쿼리 결과는 '-'이므로 2번 원소는 1번과 반대 부호
        ans[1] = (mul[0] == '+') ? ans[0] : (ans[0] == '+' ? '-' : '+');
        // 오른쪽 전파 (인접 곱 쿼리는 모두 '-'이므로 교대가 유지됨)
        for (int i = 2; i < n - 1; i++)
        {
            ans[i + 1] = (mul[i] == '+') ? ans[i] : (ans[i] == '+' ? '-' : '+');
        }
    }

    // 최종 부호 출력
    std::cout << "!";
    for (int i = 0; i < n; i++)
    {
        std::cout << " " << ans[i];
    }
    std::cout << '\n';

    return 0;
}
