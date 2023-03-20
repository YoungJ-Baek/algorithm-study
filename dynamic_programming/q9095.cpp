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
#define MAX 11

using namespace std;

int T, n[MAX],
    cache[MAX] = {
        0,
};

int DP(int target);

int main() {
  cin >> T;
  for (int index = 0; index < T; index++) {
    cin >> n[index];
    cout << DP(n[index]) << '\n';
  }
}

int DP(int target) {
  if (target == 1)
    return 1;
  else if (target == 2)
    return 2;
  else if (target == 3)
    return 4;
  else if (cache[target] != 0)
    return cache[target];
  else {
    return DP(target - 1) + DP(target - 2) + DP(target - 3);
  }
}
