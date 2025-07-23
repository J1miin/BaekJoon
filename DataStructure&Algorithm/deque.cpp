#include <bits/stdc++.h>
using namespace std;
//head는 값을 가리키고 있고, tail은 마지막 값보다 하나 뒤에 있으니까..
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
    dat[--head]=x;
}

void push_back(int x){
    dat[tail++]=x;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

void test(){
  push_back(30); // 30
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 30
  push_front(25); // 25 30
  push_back(12); // 25 30 12
  cout << back() << '\n'; // 12
  push_back(62); // 25 30 12 62
  pop_front(); // 30 12 62
  cout << front() << '\n'; // 30
  pop_front(); // 12 62
  cout << back() << '\n'; // 62
}

int main(void){
  test();
}