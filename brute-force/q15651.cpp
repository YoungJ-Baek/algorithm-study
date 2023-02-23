/**
 * @file q15651.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15651, https://www.acmicpc.net/problem/15651
 * @version 0.1
 * @date 2023-02-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#define MAX 8

int N, M;           // two inputs, N(range of sequence), M(size of sequence)
int sequence[MAX];  // array for generated sequences

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
      sequence[cnt] = index;
      dfs(cnt + 1);
    }
  }
}
