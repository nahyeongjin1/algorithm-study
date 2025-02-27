/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7576                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7576                           #+#        #+#      #+#    */
/*   Solved: 2025/02/26 16:32:03 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using std::queue;

typedef unsigned short us;
typedef unsigned int ui;

typedef struct Point
{
    us x;
    us y;
    Point(us a, us b) : x(a), y(b) {};
} point;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us m, n;
    std::cin >> m >> n;

    int *storage = new int[m * n];
    queue<point> q;
    ui total = 0;
    ui riped = 0;
    for (us i = 0; i < n; i++)
    {
        for (us j = 0; j < m; j++)
        {
            ui input, index = j + i * m;
            std::cin >> input;
            if (input == 1)
            {
                riped++;
                q.push({j, i});
            }
            total += (input != -1) ? 1 : 0;
            storage[index] = input;
        }
    }

    int days = -1;

    while (!q.empty())
    {
        ui q_size = q.size();
        days++;
        while (q_size--)
        {
            point cur = q.front();
            q.pop();
            us x = cur.x;
            us y = cur.y;
            ui idx = x + m * y;
            if (x != 0)
            {
                ui nidx = idx - 1;
                if (storage[nidx] == 0)
                {
                    riped++;
                    storage[nidx] = 1;
                    q.push({x - 1, y});
                }
            }
            if (x != m - 1)
            {
                ui nidx = idx + 1;
                if (storage[nidx] == 0)
                {
                    riped++;
                    storage[nidx] = 1;
                    q.push({x + 1, y});
                }
            }
            if (y != 0)
            {
                ui nidx = idx - m;
                if (storage[nidx] == 0)
                {
                    riped++;
                    storage[nidx] = 1;
                    q.push({x, y - 1});
                }
            }
            if (y != n - 1)
            {
                ui nidx = idx + m;
                if (storage[nidx] == 0)
                {
                    riped++;
                    storage[nidx] = 1;
                    q.push({x, y + 1});
                }
            }
        }
    }
    std::cout << (total == riped ? days : -1) << '\n';
    delete[] storage;
    return 0;
}