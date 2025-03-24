#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int iV, iE; // 정점과 간선의 개수 
    int iA, iB, iC;
    int iRes = 0;
    cin >> iV >> iE;
    
    vector<bool> vVisited(iV + 1, false);
    vector<vector<pair<int, int>>> adjList(iV + 1); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    
    for (int i = 0; i < iE; ++i) {
        cin >> iA >> iB >> iC;
        adjList[iA].push_back({iC, iB}); 
        adjList[iB].push_back({iC, iA}); 
    }

    
    pq.push({0, 1}); 

    while (!pq.empty()) {
        int currentWeight = pq.top().first; 
        int currentNode = pq.top().second; 
        pq.pop();

        if (vVisited[currentNode]) continue;

        vVisited[currentNode] = true;
        iRes += currentWeight;

        for (auto& edge : adjList[currentNode]) {
            int nextNode = edge.second; 
            int weight = edge.first; 

            if (!vVisited[nextNode]) {
                pq.push({weight, nextNode}); 
            }
        }
    }

    cout << iRes;

    return 0;
}

/*
adjList[1] = { {3, 2}, {4, 3} };  // 1번 정점: (가중치 3, 정점 2), (가중치 4, 정점 3)
adjList[2] = { {3, 1}, {5, 5} };  // 2번 정점: (가중치 3, 정점 1), (가중치 5, 정점 5)
adjList[3] = { {4, 1}, {7, 6} };  // 3번 정점: (가중치 4, 정점 1), (가중치 7, 정점 6)
adjList[4] = {};                 // 4번 정점: 연결된 정점 없음
adjList[5] = { {5, 2}, {7, 6} }; // 5번 정점: (가중치 5, 정점 2), (가중치 7, 정점 6)
adjList[6] = { {7, 3}, {7, 5} }; // 6번 정점: (가중치 7, 정점 3), (가중치 7, 정점 5)
*/