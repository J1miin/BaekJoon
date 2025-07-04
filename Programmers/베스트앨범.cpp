/*조심하자. vector는 하나의 값만 받는다. pair로 넣을 것!
bool comp custom 할 때는 비교할 벡터의 기본형을 넣어주기 !!
-> const pair<string, pair<int,int>> &a 이런식으로!
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp2(const pair<string, pair<int,int>> &a, const pair<string, pair<int,int>> &b){
    return a.second.second > b.second.second;
    
}
bool comp(const pair<string,int> &a, const pair<string,int> &b){
    return a.second > b.second;
    
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    int temp = 0;
    unordered_map<string,int> hMap;
    vector<pair<string,int>> top_genres;
    vector<pair<string, pair<int,int>>> genre_play;
    vector<int> answer;
    
    for (int i=0;i<genres.size();++i){
        hMap[genres[i]]+=plays[i];
        genre_play.push_back(make_pair(genres[i],make_pair(i,plays[i])));
    }
    
    for (auto a: hMap){
        top_genres.push_back(make_pair(a.first,a.second));
    }
    
    sort(top_genres.begin(),top_genres.end(),comp);
    sort(genre_play.begin(),genre_play.end(),comp2);

    for(int i=0;i<top_genres.size();++i){
        int cnt =0;    
        for (auto a: genre_play){
            if (a.first==top_genres[i].first && cnt<2){
                answer.push_back(a.second.first);
                cnt++;
            }
        }  
    }
    return answer;
}