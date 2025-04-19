// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     vector<int> v { 1, 2, 3};
//     vector<vector<int>> combinations; // 모든 조합을 저장할 벡터
//     //r개의 원소는 1, (n-r)개의 원소는 0인 배열 temp를 만든다.
//     /*ex. 3C2 라면 2개의 원소는 1, 1개의 원소는 0인 배열 temp 만들기 
//     아래의 경우는 5C2 예시 */
//     vector<int> temp{ 0, 1, 1 };

//     sort (v.begin(),v.end());
//     do {
//         vector<int> current_combination; // 현재 조합을 저장할 임시 벡터
//         for (int i = 0; i < v.size(); i++) {
//             if (temp[i] == 1) {
//                 current_combination.push_back(v[i]); // 선택된 원소를 임시 벡터에 추가
//             }
//         }
//         combinations.push_back(current_combination); // 현재 조합을 저장
//     } while (next_permutation(temp.begin(), temp.end()));

//     // 저장된 모든 조합 출력
//     for (const auto& combination : combinations) {
//         for (int x : combination) {
//             cout << x << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = { 1, 2, 3 };  // 원본 벡터

    vector<vector<int>> all_combinations;  // 모든 부분집합을 저장할 벡터

    // 전체 부분집합을 구하기 위해 1부터 크기까지 순회
    int n = v.size();
    for (int r = 1; r <= n; ++r) {
        vector<int> temp(n, 0);
        fill(temp.end() - r, temp.end(), 1);  // 크기 r만큼 1로 채우기

        sort(v.begin(), v.end());
        
        do {
            vector<int> current_combination;
            for (int i = 0; i < n; i++) {
                if (temp[i] == 1) {
                    current_combination.push_back(v[i]);
                }
            }
            all_combinations.push_back(current_combination);  // 현재 조합을 저장
        } while (next_permutation(temp.begin(), temp.end()));  // 순열을 통해 모든 조합을 구함
    }

    // 저장된 모든 부분집합 출력 (크기별로)
    for (int r = 1; r <= n; ++r) {
        cout << "부분집합 크기 " << r << "인 경우:\n";
        for (const auto& combination : all_combinations) {
            if (combination.size() == r) {  // 크기가 r인 부분집합만 출력
                for (int x : combination) {
                    cout << x << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
