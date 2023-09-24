//시간초과
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int Top = -1;

int arr[MAX_SIZE];
int num = 0;

inline int empty() { arr[num++] = Top == -1 ? 1 : 0; }

inline int push(int x) { stack[++Top] = x; }

inline int pop() {
  if (Top == -1) {
    arr[num++] = -1;

  } else {
    arr[num++] = stack[Top--];
  }
}

inline int top() {
  if (Top == -1) {
    arr[num++] = -1;

  } else {
    arr[num++] = stack[Top];
  }
}

inline int size() { arr[num++] = Top + 1; }

int main() {

  int n, b;
  scanf("%d", &n);
  char a[6];

  for (int i = 0; i < n; i++) {
    scanf("%s", a);
    if (strcmp(a, "pop") == 0) {
      pop();
    } else if (strcmp(a, "size") == 0) {
      size();
    } else if (strcmp(a, "empty") == 0) {
      empty();
    } else if (strcmp(a, "top") == 0) {
      top();
    } else if (strcmp(a, "push") == 0) {
      scanf("%d", &b);
      push(b);
    }
  }
  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }

  return 0;
}
