/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1043                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1043                           #+#        #+#      #+#    */
/*   Solved: 2025/03/04 08:50:03 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using std::unordered_set;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n, m; // 1 <= n, m <= 50
    std::cin >> n >> m;

    vector<bool> truth_known(n, false);
    vector<vector<uint16_t>> party(m);
    vector<unordered_set<uint16_t>> adj_list(n);

    uint16_t truth_count;
    std::cin >> truth_count;

    std::queue<uint16_t> q;

    // 진실을 아는 사람
    while (truth_count--)
    {
        uint16_t number;
        std::cin >> number;
        truth_known[number - 1] = true;
        q.push(number - 1);
    }
    // 파티 입력
    for (uint16_t i = 0; i < m; i++)
    {
        uint16_t count;
        std::cin >> count;
        for (uint16_t j = 0; j < count; j++)
        {
            uint16_t number;
            std::cin >> number;
            party[i].push_back(number - 1);
        }
    }
    // 인접 리스트 초기화
    for (uint16_t i = 0; i < m; i++)
    {
        for (uint16_t j = 0; j < party[i].size() - 1; j++)
        {
            for (uint16_t k = j + 1; k < party[i].size(); k++)
            {
                if (party[i][j] != party[i][k])
                {
                    adj_list[party[i][j]].insert(party[i][k]);
                    adj_list[party[i][k]].insert(party[i][j]);
                }
            }
        }
    }
    // 연결 탐색을 통해 위험인물 색출
    while (!q.empty())
    {
        uint16_t cur = q.front();
        q.pop();
        for (const uint16_t &node : adj_list[cur])
        {
            if (!truth_known[node])
            {
                q.push(node);
                truth_known[node] = true;
            }
        }
    }
    // 파티 재탐색을 통해 위험한 자리 확인
    for (const auto &p : party)
    {
        for (const auto &num : p)
        {
            if (truth_known[num])
            {
                m--;
                break;
            }
        }
    }

    std::cout << m;

    return 0;
}