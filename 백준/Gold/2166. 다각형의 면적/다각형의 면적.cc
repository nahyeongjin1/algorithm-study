// 2166
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

uint16_t N; // [3, 10_000]
vector<pair<int32_t, int32_t>> coordinates;
double space = 0;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    coordinates.resize(N);

    for (uint16_t i = 0; i < N; i++)
    {

        cin >> coordinates[i].first >> coordinates[i].second;
    }

    /**
     * 기준점 O(0, 0)
     * 기준점으로부터 모든 변을 외적함
     * 기준점에서 각 변의 양 끝점으로 가는 두 벡터를 외적한다
     */
    for (uint16_t i = 0; i < N; i++)
    {
        auto [x_i0, y_i0] = coordinates[i];
        auto [x_i1, y_i1] = coordinates[(i + 1) % N];

        space += (int64_t)x_i0 * y_i1 - (int64_t)y_i0 * x_i1;
    }
    space = abs(space) / 2.0;

    cout << fixed << setprecision(1);
    cout << space << '\n';

    return 0;
}
