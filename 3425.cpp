//출력부분 오류 나중에 수정 ㅎ

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 1000000000
using namespace std;
typedef long long ll;

stack<ll> s;
vector<string> cmd;
vector<ll> NUM_X;
int n, first, errorCheck, NUM_top;
string str;
ll x;
void init() {
  errorCheck = 0;
  NUM_X.clear();
  cmd.clear();
}

int NUM(ll x) {
  s.push(x);
  return 0;
}
int POP() {
  if (s.empty()) {
    return 1;
  }
  s.pop();
  return 0;
}

int INV() {
  if (s.empty()) {
    return 1;
  }
  ll x = -(s.top());
  s.pop();
  s.push(x);
  return 0;
}

int DUP() {
  if (s.empty()) {
    return 1;
  }
  s.push(s.top());
  return 0;
}

int SWP() {
  if (s.empty()) {
    return 1;
  }
  ll x = s.top();
  s.pop();
  if (s.empty()) {
    return 1;
  }
  ll y = s.top();
  s.pop();
  s.push(x);
  s.push(y);

  return 0;
}

int ADD() {
  if (s.empty()) {
    return 1;
  }
  ll x = s.top();
  s.pop();
  if (s.empty()) {
    return 1;
  }
  x += s.top();
  s.pop();
  s.push(x);

  return 0;
}

int SUB() {
  if (s.empty()) {
    return 1;
  }
  ll x = s.top();
  s.pop();
  if (s.empty()) {
    return 1;
  }
  ll y = s.top();
  ll z = y - x;
  s.pop();
  s.push(z);

  return 0;
}

int MUL() {
  if (s.empty()) {
    return 1;
  }
  ll x = s.top();
  s.pop();
  if (s.empty()) {
    return 1;
  }
  x *= s.top();
  s.pop();
  s.push(x);

  return 0;
}

int DIV() {
  int neg = 0;
  if (s.empty()) {
    return 1;
  }
  ll x = s.top();
  if (x < 0) {
    ++neg;
  }
  s.pop();
  if (s.empty()) {
    return 1;
  }
  ll y = s.top();
  if (y < 0) {
    ++neg;
  }
  x = y / x;
  if (neg == 1) {
    x = -(abs(x));
  } else {
    x = abs(x);
  }

  s.pop();
  s.push(x);

  return 0;
}
int MOD() {
  int neg = 0;
  if (s.empty()) {
    return 1;
  }
  ll x = s.top();
  s.pop();
  if (s.empty()) {
    return 1;
  }
  ll y = s.top();
  if (y < 0) {
    ++neg;
  }
  x = y % x;
  if (neg == 1) {
    x = -(abs(x));
  } else {
    x = abs(x);
  }
  s.pop();
  s.push(x);

  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  double arr[MAX];
  int res = 0;
  while (1) {
    init();
    errorCheck = 0;
    while (1) {
      cin >> str;
      if (str == "NUM") {
        cin >> x;
        NUM_X.push_back(x);
      } else if (str == "QUIT") {
        return 0;
      } else if (str == "END") {
        break;
      }
      cmd.push_back(str);
    }
    cin >> n;
    while (n--) {
      NUM_top = 0;
      cin >> first;
      s.push(first);

      for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i] == "NUM")
          errorCheck = NUM(NUM_X[NUM_top++]);
        else if (cmd[i] == "INV")
          errorCheck = INV();
        else if (cmd[i] == "POP")
          errorCheck = POP();
        else if (cmd[i] == "DUP")
          errorCheck = DUP();
        else if (cmd[i] == "SWP")
          errorCheck = SWP();
        else if (cmd[i] == "ADD")
          errorCheck = ADD();
        else if (cmd[i] == "SUB")
          errorCheck = SUB();
        else if (cmd[i] == "MUL")
          errorCheck = MUL();
        else if (cmd[i] == "DIV")
          errorCheck = DIV();
        else if (cmd[i] == "MOD")
          errorCheck = MOD();

        if (!s.empty() && (s.top() > MAX || s.top() < -MAX)) {
          errorCheck = 1;
        }
        if (errorCheck) {
          break;
        }
      }

      if (errorCheck == 1 || s.size() != 1) {
        cout << "ERROR\n";
      } else {
        cout << s.top() << "\n";
      }
      while (!s.empty()) {
        s.pop();
      }
    }
    for (int i = 0; i < res; i++) {
      cout << arr[i] << "\n";
    }
    cout << endl;
  }
}
