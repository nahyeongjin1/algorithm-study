/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 32930                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/32930                          #+#        #+#      #+#    */
/*   Solved: 2025/03/10 21:51:03 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <list>

typedef struct Point
{
    int16_t x;
    int16_t y;
    Point(int16_t a, int16_t b) : x(a), y(b) {}
} point;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n, m; // 1 <= n, m <= 100
    std::cin >> n >> m;

    std::list<point> targets;
    for (uint16_t i = 0; i < n; i++)
    {
        int16_t a, b; // 100 <= a, b <= 100
        std::cin >> a >> b;
        targets.push_back({a, b});
    }

    point cur = {0, 0};
    uint32_t output = 0;
    while (m--)
    {
        uint32_t max = 0;
        std::list<point>::iterator target;
        for (auto i = targets.begin(); i != targets.end(); i++)
        {
            uint32_t dist = (i->x - cur.x) * (i->x - cur.x) + (i->y - cur.y) * (i->y - cur.y);
            if (dist > max)
            {
                max = dist;
                target = i;
            }
        }
        cur = {target->x, target->y};
        targets.erase(target);
        output += max;
        int16_t a, b;
        std::cin >> a >> b;
        targets.push_back({a, b});
    }
    std::cout << output << '\n';

    return 0;
}