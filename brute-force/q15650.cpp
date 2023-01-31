/**
 * @file q15650.cpp
 * @author your name (you@domain.com)
 * @brief solution for BOJ #15650, https://www.acmicpc.net/problem/15650
 * @version 0.1
 * @date 2023-01-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#define MAX 9  // considering usage, 0~8 -> 1~9

int N, M;           // input N(range), M(size)
int sequence[MAX];  // result sequence
bool visited[MAX];  // to filter repeated elements

void dfs(int index, int cnt);

int main() {
  std::cin >> N >> M;
  dfs(1, 0);
  return 0;
}

void dfs(int index, int cnt) {
  if (cnt == M) {
    for (int iter = 0; iter < M; iter++) std::cout << sequence[iter] << ' ';
    std::cout << '\n';
    return;
  } else {
    for (int iter = index; iter <= N; iter++) {
      if (visited[iter] == false) {
        visited[iter] = true;
        sequence[cnt] = iter;
        dfs(iter + 1, cnt + 1);
        visited[iter] = false;
      }
    }
  }
}
