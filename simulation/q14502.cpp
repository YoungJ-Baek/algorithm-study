/**
 * @file q14502.cpp
 * @author YoungJ-Baek (qordudwls1@gmail.com)
 * @brief solution for BOJ #14502, https://www.acmicpc.net/problem/14502
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <queue>
#include <vector>
#define MAX 8

using namespace std;

int N, M, answer;
int map1[MAX][MAX],
    map2[MAX][MAX];  // map1 for original map, map2 for virus spreading
vector<pair<int, int>> virus_initial;              // initial location of virus
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};  // virus movement -> use pair

void deepCopy(int src[MAX][MAX], int dst[MAX][MAX]);  // to avoid shallow copy
void generateWall(int count, int start);              // generate 3 wall
void spreadVirus();  // spread virus after generateWall()

int main() {
  // get input
  cin >> N >> M;
  for (int row = 0; row < N; row++)
    for (int col = 0; col < M; col++) {
      cin >> map1[row][col];
      if (map1[row][col] == 2)
        virus_initial.push_back(
            make_pair(row, col));  // mark initial position of virus
    }
  generateWall(0, 0);
  // generate wall via DFS
  // if count == 3, copy map1 into map2 and spread virus
  // queue empty -> count safe_area
  // print answer
  cout << answer;
  return 0;
}

/**
 * @brief Copy 2d array from src to dst, avoiding shallow copy
 *
 * @param src source 2d array
 * @param dst destination 2d array
 */
void deepCopy(int src[MAX][MAX], int dst[MAX][MAX]) {
  for (int row = 0; row < N; row++)
    for (int col = 0; col < M; col++) dst[row][col] = src[row][col];
}

/**
 * @brief Generate 3 wall with DFS, then toss map to spreadVirus()
 *
 * @param count depth of wall
 * @param start start index to reduce repetitive operation
 */
void generateWall(int count, int start) {
  if (count == 3) {
    deepCopy(map1, map2);
    spreadVirus();
  } else {
    for (int row = start; row < N; row++)
      for (int col = 0; col < M; col++)
        if (map1[row][col] == 0) {
          map1[row][col] = 1;
          generateWall(count + 1, row);
          map1[row][col] = 0;
        }
  }
}

/**
 * @brief Spread virus via BFS, and compare safe area with answer
 *
 */
void spreadVirus() {
  queue<pair<int, int>> virus_queue;
  for (int index = 0; index < virus_initial.size(); index++)
    virus_queue.push(virus_initial[index]);

  while (!virus_queue.empty()) {
    int y = virus_queue.front().first;
    int x = virus_queue.front().second;
    virus_queue.pop();

    for (int index = 0; index < 4; index++) {
      int ny = y + dy[index];
      int nx = x + dx[index];

      if (ny >= 0 && ny < N && nx >= 0 && nx < M && map2[ny][nx] == 0) {
        map2[ny][nx] = 2;
        virus_queue.push(make_pair(ny, nx));
      }
    }
  }
  int safe_area = 0;
  for (int row = 0; row < N; row++)
    for (int col = 0; col < M; col++)
      if (map2[row][col] == 0) safe_area += 1;
  answer = safe_area > answer ? safe_area : answer;
}
