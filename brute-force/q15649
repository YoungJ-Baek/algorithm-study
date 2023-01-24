/**
 * @file q15649.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15649, https://www.acmicpc.net/problem/15649
 * @version 0.1
 * @date 2023-01-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#define MAX 9

int N, M;           // two inputs, N(range of sequence), M(size of sequence)
int sequence[MAX];  // array for generated sequences
bool visited[MAX];  // array for checking dfs

void dfs(int cnt);

int main() {
  std::cin >> N >> M;
  dfs(0);
}

void dfs(int cnt) {
  if (cnt == M)  // array size reaches maximum size
  {
    for (int index = 0; index < M; index++) std::cout << sequence[index] << ' ';
    std::cout << '\n';
    return;
  } else {
    for (int index = 1; index <= N; index++) {
      if (visited[index] == false) {
        visited[index] = true;
        sequence[cnt] = index;
        dfs(cnt + 1);
        visited[index] = false;
      }
    }
  }
}
