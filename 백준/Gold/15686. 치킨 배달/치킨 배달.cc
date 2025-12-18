#include <iostream>
#include <vector>

using std::pair;
using std::vector;

short n, m;
short total_min = INT16_MAX;
vector<short> selected;
vector<pair<short, short>> houses;
vector<pair<short, short>> chickens;

/**
 * @param start 조합에서 중복 방지를 위한 시작 인덱스
 * @param selected 현재까지 선택한 치킨집 인덱스들
 */
void backtrack(short start, vector<short> &selected)
{
    if (selected.size() == m)
    {
        /** 모든 집에 대해 선택된 치킨 집들에 대한 치킨 거리 합 계산 */
        /** 치킨 거리는 최소 거리의 치킨집까지의 거리 */
        short cur_dist = 0;
        for (auto [house_row, house_col] : houses)
        {
            short min_dist = INT16_MAX;
            for (short i : selected)
            {
                /** 모든 집들에서 현재 치킨집까지의 Manhattan distance 계산 */
                auto [chicken_row, chicken_col] = chickens[i];
                min_dist = std::min(min_dist, short(abs(chicken_row - house_row) + abs(chicken_col - house_col)));
            }
            cur_dist += min_dist;
        }

        /** 전역 최솟값과 비교하여 min으로 갱신 */
        total_min = std::min(total_min, cur_dist);

        return;
    }

    for (short i = start; i < chickens.size(); i++)
    {
        selected.push_back(i);
        backtrack(i + 1, selected);
        selected.pop_back();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> n >> m;

    selected.reserve(m);

    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < n; j++)
        {
            short temp;
            std::cin >> temp;
            switch (temp)
            {
            case 1:
                houses.push_back({i, j});
                break;
            case 2:
                chickens.push_back({i, j});
                break;
            }
        }
    }

    backtrack(0, selected);
    std::cout << total_min << '\n';

    return 0;
}