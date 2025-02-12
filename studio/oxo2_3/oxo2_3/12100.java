package org.example;

import java.io.*;
import java.util.*;
//하나의 시도에 블럭은 한번의 머지만 가능
//3개가 있는 경우엔 방향 위쪽의 블럭이 머지의 대상
public class Main {
    static int N;
    static int[][] bmap;
    static int result = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        bmap = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                bmap[i][j] = sc.nextInt();

        //0:빈칸
        //1~k: 블럭

        dfs(0);
        System.out.println(result);
    }

    static void dfs(int k) {
        //탈출조건
        if (k >= 5) {
            int trialMax = findMax();
            if (trialMax > result) result = trialMax;
            return;
        }
        //탐색
        int[][] original = new int[N][N];
        for (int i = 0; i < bmap.length; i++) {
            System.arraycopy(bmap[i], 0, original[i], 0, N);
        }
        for (int i = 0; i < 4; i++) {
            moveDir(i);
            dfs(k + 1);
            //--- restore map
            for (int j = 0; j < bmap.length; j++) {
                System.arraycopy(original[j], 0, bmap[j], 0, N);
            }
            //---
        }
    }

    static int findMax() {
        int temp = 0;
        for (int[] row : bmap) {
            for (int num : row) {
                if (temp < num) temp = num;
            }
        }
        return temp;
    }

    static void moveDir(int dir) {
        boolean[][] visited = new boolean[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        switch (dir) {
            case 0: //상
                for (int col = 0; col < N; col++) {

                    for (int row = 0; row < N; row++) {
                        if (row == 0 || bmap[row][col] == 0) continue;
                        slide(row, col, 0, visited);
                    }
                }
                break;
            case 1: //하:
                for (int col = 0; col < N; col++) {
                    for (int row = N - 1; row >= 0; row--) {
                        if (row == N - 1 || bmap[row][col] == 0) continue;
                        slide(row, col, 1, visited);
                    }
                }
                break;
            case 2: //좌:
                for (int row = 0; row < N; row++) {
                    for (int col = 0; col < N; col++) {
                        if (col == 0 || bmap[row][col] == 0) continue;
                        slide(row, col, 2, visited);
                    }
                }
                break;
            case 3: //우:
                for (int row = 0; row < N; row++) {
                    for (int col = N - 1; col >= 0; col--) {
                        if (col == N - 1 || bmap[row][col] == 0) continue;
                        slide(row, col, 3, visited);
                    }
                }
                break;
        }
    }

    static void slide(int x, int y, int dir, boolean[][] visited) {

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int nx = x;
        int ny = y;
        int pos = bmap[x][y];
        int newPos;

        while (true) {
            nx += dx[dir];
            ny += dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                nx -= dx[dir];
                ny -= dy[dir];
                bmap[nx][ny] = bmap[x][y];
                bmap[x][y] = 0;
                return;
            }
            newPos = bmap[nx][ny];
            if (newPos == 0) {
                continue;
            } else if (newPos == pos && !visited[nx][ny]) {
                //merge
                bmap[nx][ny] *= 2;
                bmap[x][y] = 0;
                return;
            } else {
                //stop
                nx -= dx[dir];
                ny -= dy[dir];
                bmap[nx][ny] = bmap[x][y];
                bmap[x][y] = 0;
                return;
            }


            /*else if (bmap[nx][ny] != 0) {
                if (bmap[nx][ny] == bmap[x][y] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    bmap[nx][ny] *= 2;
                } else {
                    bmap[nx - dx[dir]][ny - dy[dir]] = bmap[x][y];
                }
                bmap[x][y] = 0;
                return;
            }*/
        }
    }

}