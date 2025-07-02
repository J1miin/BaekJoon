#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//시간초과
bool solution(vector<string> phone_book) {
    bool answer = true;
    for (int i=0;i<phone_book.size();++i){
        for(int j=0;j<phone_book.size();++j){
            if (i==j) continue;
            if ( phone_book[i].find(phone_book[j])==0){
                answer = false; 
                break;
            }
        }
    }
    return answer;
}

//해시와 substr이용하기
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool solution2(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> hMap;
    for(auto a: phone_book){
        hMap[a]++;
    }

    for (int i=0;i<phone_book.size();++i){
        for(int j=0;j<phone_book[i].size()-1;++j){
            //자기 자신 제외하기 위해서 size()-1
            string checkString = phone_book[i].substr(0,j+1);
            if (hMap[checkString]) {
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}