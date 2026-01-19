// 1268
#include <iostream>
#include <vector>

using namespace std;

uint16_t num_of_students;            // [3, 1'000]
vector<vector<uint16_t>> class_info; // [학생][학년] = 반 번호(1 ~ 9)
vector<vector<bool>> is_same_class;
uint16_t maximum = 0;
uint16_t result_student_num = 1;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> num_of_students;

    class_info.resize(num_of_students, vector<uint16_t>(5, 0));
    is_same_class.resize(num_of_students, vector<bool>(num_of_students, false));

    /* 입력 */
    for (uint16_t student = 0; student < num_of_students; student++)
    {
        for (uint16_t grade = 0; grade < 5; grade++)
        {
            uint16_t class_num;
            cin >> class_num;
            class_info[student][grade] = class_num;
        }
    }

    /* 중복 회피  */
    for (uint16_t i = 0; i < num_of_students; i++)
    {
        for (uint16_t j = i + 1; j < num_of_students; j++)
        {
            for (uint16_t grade = 0; grade < 5; grade++)
            {
                if (class_info[i][grade] == class_info[j][grade])
                {
                    is_same_class[i][j] = true;
                    is_same_class[j][i] = true;
                    break;
                }
            }
        }
    }

    /* 카운팅 */
    for (uint16_t i = 0; i < is_same_class.size(); i++)
    {
        uint16_t cnt = 0;
        for (auto same : is_same_class[i])
        {
            if (same)
            {
                cnt++;
            }
        }
        if (maximum < cnt)
        {
            maximum = cnt;
            result_student_num = i + 1;
        }
    }

    cout << result_student_num << '\n';

    return EXIT_SUCCESS;
}
