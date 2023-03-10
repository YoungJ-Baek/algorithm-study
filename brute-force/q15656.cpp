/**
 * @file q15656.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15656, https://www.acmicpc.net/problem/15656
 * @version 0.1
 * @date 2023-03-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 9

using namespace std;

int N, M;
int input[MAX];
vector<int> output;

void dfs(int count);

int main() {
  cin >> N >> M;
  for (int index = 0; index < N; index++) cin >> input[index];
  sort(input, input + N);
  dfs(0);
  return 0;
}

void dfs(int count) {
  if (count == M) {
    for (int index = 0; index < M; index++) cout << output[index] << ' ';
    cout << '\n';
  } else {
    for (int index = 0; index < N; index++) {
      output.push_back(input[index]);
      dfs(count + 1);
      output.pop_back();
    }
  }
}
