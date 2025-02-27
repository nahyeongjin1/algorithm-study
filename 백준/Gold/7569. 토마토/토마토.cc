/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7569                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7569                           #+#        #+#      #+#    */
/*   Solved: 2025/02/26 16:32:11 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>

using std::queue;

typedef unsigned short us;
typedef unsigned int ui;

typedef struct Point
{
    int x;
    int y;
    int z;
    Point(int a, int b, int c) : x(a), y(b), z(c) {};
} point;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us m; // 2 <= m <= 100
    us n; // 2 <= n <= 100
    us h; // 1 <= h <= 100

    std::cin >> m >> n >> h;

    const int size = h * n * m;
    int *storage = new int[h * n * m];

    queue<point> q;
    int tomatoes = 0;
    int riped = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                ui index = k + m * j + m * n * i;
                std::cin >> storage[index];
                if (storage[index] == 1)
                {
                    riped++;
                    q.push({k, j, i});
                }
                tomatoes += (storage[index] == -1) ? 0 : 1;
            }
        }
    }

    int days = -1;
    while (!q.empty())
    {
        days++;
        ui q_size = q.size();
        while (q_size--)
        {
            point cur = q.front();
            int x = cur.x;
            int y = cur.y;
            int z = cur.z;
            ui idx = x + m * y + m * n * z;
            q.pop();

            if (x != 0)
            {
                ui nidx = idx - 1;
                if (storage[nidx] == 0)
                {
                    storage[nidx] = 1;
                    q.push({x - 1, y, z});
                    riped++;
                }
            }
            if (x != m - 1)
            {
                ui nidx = idx + 1;
                if (storage[nidx] == 0)
                {
                    storage[nidx] = 1;
                    q.push({x + 1, y, z});
                    riped++;
                }
            }
            if (y != 0)
            {
                ui nidx = idx - m;
                if (storage[nidx] == 0)
                {
                    storage[nidx] = 1;
                    q.push({x, y - 1, z});
                    riped++;
                }
            }
            if (y != n - 1)
            {
                ui nidx = idx + m;
                if (storage[nidx] == 0)
                {
                    storage[nidx] = 1;
                    q.push({x, y + 1, z});
                    riped++;
                }
            }
            if (z != 0)
            {
                ui nidx = idx - m * n;
                if (storage[nidx] == 0)
                {
                    storage[nidx] = 1;
                    q.push({x, y, z - 1});
                    riped++;
                }
            }
            if (z != h - 1)
            {
                ui nidx = idx + m * n;
                if (storage[nidx] == 0)
                {
                    storage[nidx] = 1;
                    q.push({x, y, z + 1});
                    riped++;
                }
            }
        }
    }
    std::cout << (riped == tomatoes ? days : -1) << '\n';
    delete[] storage;

    return 0;
}