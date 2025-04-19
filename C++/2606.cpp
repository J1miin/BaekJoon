/*
 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다
 누가 누구랑 연결되어 있냐"를 쌍으로 표현해야 되니까 2차원으로 표현 필요
 */
#include <iostream>
using namespace std; 
#define MAX_NUM 101
#include <stack>

int iCom, iPair; //컴퓨터 개수 1부터 카운트
int iNetwork[MAX_NUM][MAX_NUM] = {0,}; //1-2연결 시, (1,2), (2,1) 둘 다 1표시
int iVisited[MAX_NUM] = {false, };
int iCnt = 0;

void DFS(int start){
    stack<int> st;
    st.push(start);
    iVisited[start] = true;

    
    while (!st.empty()){
        int curr = st.top();
        st.pop();
        for (int i = 1; i <= iCom; ++i) {
            if (iNetwork[curr][i] == 1 && !iVisited[i]) {
                st.push(i);
                iVisited[i] = true;
                iCnt++;
            }
        }
    }
}
int main(){
    int iInput1, iInput2;
    cin >> iCom >> iPair;
    for (int i=0;i<iPair;++i){
        cin >> iInput1 >> iInput2; 
        iNetwork[iInput1][iInput2]=1;
        iNetwork[iInput2][iInput1]=1;
    }
    DFS(1);
    cout << iCnt << endl; // 1번 제외 감염된 컴퓨터 수
}