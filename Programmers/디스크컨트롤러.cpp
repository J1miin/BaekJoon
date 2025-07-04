/*놓친 부분 : 계속 대기큐만 생각했다. 
대기 큐안에서의 우선순위만 생각하느라 대기큐가 비어있을 때, 
그냥 온 순서대로 처리하는게 먼저인 로직을 아예 빼먹고 solution을 썼었다.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct JobInfo {
    int iJobNum;
    int iRequestTime;
    int iProcessTime;
};
struct Compare {
    bool operator() (JobInfo a, JobInfo b){
        if (a.iProcessTime != b.iProcessTime){
            return a.iProcessTime > b.iProcessTime;
        }else if (a.iRequestTime != b.iRequestTime){
            return a.iRequestTime > b.iRequestTime;
        }
        return a.iJobNum < b.iJobNum;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(),jobs.end());
    priority_queue<JobInfo, vector<JobInfo>, Compare> pq ; //대기큐
    int answer = 0;
    int time = 0;
    int idx = 0;
    int count = 0;
    int n = jobs.size();
    
    vector<pair<int,int>> vTurnAround;
    
    while (count < n) {
        while (idx < n && jobs[idx][0] <= time) {
            JobInfo j;
            j.iJobNum = idx;
            j.iRequestTime = jobs[idx][0];
            j.iProcessTime = jobs[idx][1];
            pq.push(j);
            ++idx;
        }

        if (!pq.empty()) {
            JobInfo info = pq.top(); pq.pop();
            time += info.iProcessTime;
            vTurnAround.push_back({info.iRequestTime, time});
            ++count;
        } else {
            time = jobs[idx][0];
        }
    }

    int sum =0;

    for (auto a: vTurnAround){
        sum = sum + (a.second-a.first);
    }
    answer = sum/(vTurnAround.size());
    return answer;
}

// int solution(vector<vector<int>> jobs) {
//     priority_queue<JobInfo, vector<JobInfo>, Compare> pq ;
//     int answer = 0;
//     vector<pair<int,int>> vTurnAround;
    
//     for (int i=0;i<jobs.size();++i){
//         JobInfo j;
//         j.iJobNum = i;
//         j.iRequestTime = jobs[i][0];
//         j.iProcessTime = jobs[i][1];
//         // cout<<"iJobNum: "<<j.iJobNum<<" iRequestTime: "<< 
//         // j.iRequestTime<< " iProcessTime: "<<j.iProcessTime<<endl;
//         pq.push(j);
//     }
    
//     int iStartTime, iEndTime ;
//     int time = pq.top().iRequestTime;
//     //print
//     cout<<time<<endl;
//     while (!pq.empty()){
//         iStartTime = time;
//         JobInfo info = pq.top();
//         pq.pop();
//         time += info.iProcessTime;
//         iEndTime = time;
//         vTurnAround.push_back({iStartTime,iEndTime});
//     }
//     int sum =0;
//     for (auto a: vTurnAround){
//         sum = sum + (iEndTime-iStartTime);
//     }
//     answer = sum/(vTurnAround.size());
//     return answer;
// }

int main(){
    int answer = solution({{0, 3}, {1, 9}, {3, 5}});
    cout<<answer;
}