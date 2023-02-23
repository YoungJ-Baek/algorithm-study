/**
 * @file q15652.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15652, https://www.acmicpc.net/problem/15652
 * @version 0.1
 * @date 2023-02-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
int N, M;

void dfs(int count, int start);

int main() {
  cin >> N >> M;
  dfs(0, 1);
  return 0;
}

void dfs(int count, int start) {
  if (count == M) {
    for (auto iter = result.begin(); iter != result.end(); iter++)
      cout << *iter << ' ';
    cout << '\n';
  } else {
    for (int index = start; index <= N; index++) {
      result.push_back(index);
      dfs(count + 1, index);
      result.pop_back();
    }
  }
}
