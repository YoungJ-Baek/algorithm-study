/**
 * @file q9095.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #9095, https://www.acmicpc.net/problem/9095
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int T, n;
vector<int> output;
int case_count = 0;

void dfs(int n);

int main() {
  cin >> T;

  for (int index = 0; index < T; index++) {
    cin >> n;
    dfs(n);
    output.push_back(case_count);
    case_count = 0;
  }
  for (int index = 0; index < T; index++) cout << output[index] << '\n';
}

void dfs(int n) {
  if (n == 0) {
    case_count++;
    return;
  } else if (n < 0)
    return;
  else {
    for (int sub = 1; sub <= 3; sub++) dfs(n - sub);
  }
}
