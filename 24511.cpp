//시간초과 ㅎㅎ 
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N; // 자료구조의 개수 N 입력

  vector<int> types(N); // 각 자료구조의 타입을 저장하는 배열
  vector<deque<int>> data(N); // N개의 자료구조를 저장하는 벡터.

  for (int i = 0; i < N; i++) {
    cin >> types[i]; // 각 자료구조의 타입을 입력
    int x;
    cin >> x;
    data[i].push_back(x); // 각 자료구조에 초기 원소를 삽입
  }

  int M;
  cin >> M; // 삽입할 수열의 길이 M 입력

  vector<int> res(M); // 결과를 저장할 벡터

  for (int i = 0; i < M; i++) {
    int x;
    cin >> x; // 삽입할 수열의 원소를 입력

    // 각 자료구조에 원소를 삽입하고 반환
    for (int j = 0; j < N; j++) {
      data[j].push_back(x);  // 원소를 삽입
      if (types[j] == 0) {   // Queue
        x = data[j].front(); // 가장 왼쪽 큐에서 반환
        data[j].pop_front(); // 반환한 원소를 큐에서 제거
      } else {               // Stack
        x = data[j].back();  // 가장 오른쪽 스택에서 반환
        data[j].pop_back();  // 반환한 원소를 스택에서 제거
      }
      if (j == N - 1) {
        res[i] = x; // 마지막 자료구조에서 반환된 값만 저장
      }
    }
  }

  for (int i = 0; i < res.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }

  return 0;
}
