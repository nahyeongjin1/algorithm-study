// 1197
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

uint16_t V;                                       // [1, 10'000]
uint32_t E;                                       // [1, 100'000]
vector<tuple<int32_t, uint16_t, uint16_t>> edges; // [{ weight, from, to }]
vector<uint16_t> parent;                          // 각 정점의 부모를 저장
int64_t MST_total_weight = 0;                     // 명시된 범위는 int32_t를 벗어나지 않지만 계산 도중 벗어날 수 있음
uint16_t selected_e_cnt = 0;

uint16_t find(uint16_t v);          // 루트를 재귀적으로 찾는 함수
void unite(uint16_t a, uint16_t b); // 두 집합을 합치는 함수

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> V >> E;

    edges.resize(E);

    for (uint32_t i = 0; i < E; i++)
    {
        uint16_t from, to; // 입력 노드
        int32_t weight;    // 입력 가중치 [-1'000'000, 1'000'000]
        cin >> from >> to >> weight;
        edges[i] = {weight, from, to};
    }

    // weight 기준 오름차순 정렬
    sort(edges.begin(), edges.end());

    // 초기화 (자기 자신을 부모로 설정)
    parent.resize(V + 1);
    for (uint16_t i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    // 가장 작은 가중치의 간선부터 unite
    for (auto [weight, from, to] : edges)
    {
        // 종료 조건: 사이클이 생기지 않게 모든 정점을 연결
        if (selected_e_cnt == V - 1)
            break;

        // 정점이 같지 않을 때만 연결
        if (find(from) != find(to))
        {
            unite(from, to);
            MST_total_weight += weight;
            selected_e_cnt++;
        }
    }

    cout << MST_total_weight << '\n';

    return EXIT_SUCCESS;
}

uint16_t find(uint16_t v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unite(uint16_t a, uint16_t b)
{
    parent[find(a)] = find(b);
}
