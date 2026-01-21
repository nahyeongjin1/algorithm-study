// 6812
#include <iostream>

using namespace std;

int32_t input;
pair<int32_t, string> time_diff_for_city[] = {{0, "Ottawa"},
                                              {-300, "Victoria"},
                                              {-200, "Edmonton"},
                                              {-100, "Winnipeg"},
                                              {0, "Toronto"},
                                              {100, "Halifax"},
                                              {130, "St. John's"}};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> input;

    for (auto [diff, city] : time_diff_for_city)
    {
        int32_t calc = input + diff;
        if (calc % 100 >= 60)
        {
            calc += 40;
        }
        calc = (calc + 2400) % 2400;
        cout << calc << " in " << city << '\n';
    }

    return 0;
}