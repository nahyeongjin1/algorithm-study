/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1931                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1931                           #+#        #+#      #+#    */
/*   Solved: 2025/02/24 21:50:08 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using std::pair;
using std::vector;

typedef unsigned int ui;

bool Compare(const pair<ui, ui> &p1, const pair<ui, ui> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    ui n, max_meetings = 1, end_time;
    std::cin >> n;

    vector<pair<ui, ui>> meetings(n);
    for (auto i = 0; i < n; i++)
    {
        ui a, b;
        std::cin >> a >> b;
        meetings.at(i) = {a, b};
    }
    std::sort(meetings.begin(), meetings.end(), Compare);
    end_time = meetings.at(0).second;
    for (auto i = 1; i < meetings.size(); i++)
    {
        if (end_time <= meetings.at(i).first)
        {
            end_time = meetings.at(i).second;
            max_meetings += 1;
        }
    }
    std::cout << max_meetings << '\n';

    return 0;
}