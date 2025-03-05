/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2116                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2116                           #+#        #+#      #+#    */
/*   Solved: 2025/03/04 21:15:24 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

int get_opposite(int idx)
{
    if (idx == 0)
        return 5;
    if (idx == 1)
        return 3;
    if (idx == 2)
        return 4;
    if (idx == 3)
        return 1;
    if (idx == 4)
        return 2;
    if (idx == 5)
        return 0;
    return -1;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    vector<vector<int>> dice(n, vector<int>(6));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cin >> dice[i][j];
        }
    }

    int answer = 0;
    for (int bottom = 0; bottom < 6; bottom++)
    {
        int sum = 0;
        int top = dice[0][get_opposite(bottom)];
        int max_side = 0;
        for (int k = 0; k < 6; k++)
        {
            if (k == bottom || k == get_opposite(bottom))
                continue;
            max_side = std::max(max_side, dice[0][k]);
        }
        sum += max_side;

        int current_top = top;
        for (int i = 1; i < n; i++)
        {
            int current_bottom;
            for (int j = 0; j < 6; j++)
            {
                if (dice[i][j] == current_top)
                {
                    current_bottom = j;
                    break;
                }
            }
            int curren_top_index = get_opposite(current_bottom);
            current_top = dice[i][curren_top_index];

            max_side = 0;
            for (int j = 0; j < 6; j++)
            {
                if (j == current_bottom || j == curren_top_index)
                    continue;
                max_side = std::max(max_side, dice[i][j]);
            }
            sum += max_side;
        }
        answer = std::max(answer, sum);
    }
    std::cout << answer << "\n";
    return 0;
}