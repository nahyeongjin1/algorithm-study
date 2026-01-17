// 31844
#include <iostream>

using namespace std;

string warehouse; // len = 10, '.' | '@' | '#' | '!'
uint16_t robot_pos;
uint16_t box_pos;
uint16_t flag_pos;

bool case_1, case_2;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> warehouse;

    robot_pos = warehouse.find('@');
    box_pos = warehouse.find('#');
    flag_pos = warehouse.find('!');

    case_1 = robot_pos < box_pos && box_pos < flag_pos;
    case_2 = flag_pos < box_pos && box_pos < robot_pos;

    // 박스를 원하는 칸으로 옮길 수 없는 경우
    if (!case_1 && !case_2)
    {
        cout << -1 << '\n';
        return EXIT_SUCCESS;
    }

    cout << abs(robot_pos - flag_pos) - 1 << '\n';
    return EXIT_SUCCESS;
}