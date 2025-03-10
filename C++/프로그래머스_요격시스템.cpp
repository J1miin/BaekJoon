/*
정렬 (sort 함수 이용) / 시간복잡도 = O(nlogn) << sort함수가 nlogn이고, 반복문은 O(N)이므로!
공간 복잡도는 입력 데이터의 크기에 기반하므로 사용한 벡터에 의해서 O(n)이 된다.

→ 처음부터 혼자 풀지는 못해서 찾아보니 
y좌표 값을 기준으로 정렬한 후 끝에서부터 요격지점을 설정하여 접근해야한다는 아이디어는 참고를 함. 
그리고 최적해를 찾기 때문에 greedy 알고리즘을 사용해야하는데, 
뭐 특별한 접근법이 있는 건 아니라서 
어떻게 해야 최고의 선택을 할 수 있는지 생각할 수 있는 힘을 길러야할 것 같음!
*/
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
bool compare (vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare); //end 기준으로 정렬
    
    double iShoot = targets[0][1]-0.1;
    answer++;
    
    for (int i=1;i<targets.size();++i){
        if (targets[i][0]<iShoot){
            continue;
        }else{
            iShoot=targets[i][1]-0.1;
            answer++;
        }
    }
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
bool compare (vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare); //end 기준으로 정렬
    
    int iShoot = targets[0][1]-1; //1. 요격지점은 실수 구간이지만, 이렇게 정수로 하고
    answer++;
    
    for (int i=1;i<targets.size();++i){
        if (targets[i][0]<=iShoot){ //2. 여기서 <=로 해주면 실수구간과 같은 효과 내기 가능
            continue;
        }else{
            iShoot=targets[i][1]-1;
            answer++;
        }
    }
    
    return answer;
}
*/