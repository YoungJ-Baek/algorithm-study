/**
 * @file q15657.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15657, https://www.acmicpc.net/problem/15657
 * @version 0.1
 * @date 2023-03-12
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

void dfs(int count, int start);

int main() {
  cin >> N >> M;
  for (int index = 0; index < N; index++) cin >> input[index];
  sort(input, input + N);
  dfs(0, 0);
}

void dfs(int count, int start) {
  if (count == M) {
    for (int index = 0; index < M; index++) cout << output[index] << ' ';
    cout << '\n';
  } else {
    for (int index = start; index < N; index++) {
      output.push_back(input[index]);
      dfs(count + 1, index);
      output.pop_back();
    }
  }
}
