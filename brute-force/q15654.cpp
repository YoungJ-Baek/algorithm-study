/**
 * @file q15654.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #15654, https://www.acmicpc.net/problem/15654
 * @version 0.1
 * @date 2023-02-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 9

using namespace std;

int input[MAX];
vector<int> result;
int visited[MAX];
int N, M;

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
    for (auto iter = result.begin(); iter != result.end(); iter++)
      cout << *iter << ' ';
    cout << '\n';
  } else {
    for (int index = 0; index < N; index++)
      if (visited[index] == true)
        continue;
      else {
        visited[index] = true;
        result.push_back(input[index]);
        dfs(count + 1);
        result.pop_back();
        visited[index] = false;
      }
  }
}
