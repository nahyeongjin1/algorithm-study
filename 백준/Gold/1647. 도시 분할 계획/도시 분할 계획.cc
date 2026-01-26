// 1647
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

uint32_t N;                                        // [2, 100'000]
uint32_t M;                                        // [1, 1'000'000]
uint32_t A, B, C;                                  // C = [1, 1'000]
vector<tuple<uint16_t, uint32_t, uint32_t>> edges; // {{ 유지비(C), A번 집, B번 집 }}
vector<uint32_t> parent;                           // 사이클을 회피하기 위한 부모 정보
uint32_t cnt = 0;                                  // 연결할 길의 개수
uint64_t result = 0;

uint32_t find(uint32_t v);
void unite(uint32_t a, uint32_t b);

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    // 부모 초기화
    parent.resize(N + 1);

    for (uint32_t i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // 간선 입력
    edges.resize(M);

    for (uint32_t i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        edges[i] = {C, A, B};
    }

    // 오름차순 정렬
    sort(edges.begin(), edges.end());

    for (auto [weight, from, to] : edges)
    {
        if (cnt == N - 2)
            break;

        if (find(from) != find(to))
        {
            unite(from, to);
            result += weight;
            cnt++;
        }
    }

    cout << result << '\n';

    return 0;
}

uint32_t find(uint32_t v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unite(uint32_t a, uint32_t b)
{
    parent[find(a)] = find(b);
}
