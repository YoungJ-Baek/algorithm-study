/**
 * @file q15655.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15655, https://www.acmicpc.net/problem/15655
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
vector<int> result;

void dfs(int count, int start);

int main() {
  cin >> N >> M;
  for (int index = 0; index < N; index++) cin >> input[index];
  sort(input, input + N);
  dfs(0, 0);
}

void dfs(int count, int start) {
  if (count == M) {
    for (int index = 0; index < M; index++) cout << result[index] << ' ';
    cout << '\n';
    return;
  } else {
    for (int index = start; index < N; index++) {
      result.push_back(input[index]);
      dfs(count + 1, index + 1);
      result.pop_back();
    }
  }
}
