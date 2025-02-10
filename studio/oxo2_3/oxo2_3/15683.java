package org.example;

import java.io.*;
import java.util.*;

public class Main {
    static class Pair {
        int x, y;
        int type;

        public Pair(int x, int y, int type) {
            this.x = x;
            this.y = y;
            this.type = type;
        }
    }
    static int numCctv = 0;
    static int N,M;
    static int[][] bmap;
    static List<Pair> cctvList = new ArrayList<>();
    static int result = -1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        bmap = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                bmap[i][j] = sc.nextInt();
                if (1 <= bmap[i][j] && bmap[i][j] <= 5) {
                    numCctv++;
                    cctvList.add(new Pair(i, j, bmap[i][j]));
                }
            }
        }

        //when
        dfs(0);
        System.out.println(result);

    }

    static void dfs(int k) { //0 indexed
        //탈출조건
        if (k >= numCctv) {
            int temp = numOfZero();
            if (result == -1) {
                result = temp;
            } else if(result>temp) {
                result = temp;
            }
            return;
        }
        //탐색
        Pair node = cctvList.get(k);
        int type = node.type;
        int[][] original = new int[N][M];
        for (int i = 0; i < N; i++) {
            original[i] = bmap[i].clone();
        }

        if (type == 1|| type == 3 || type==4) {
            for (int i = 0; i < 4; i++) {
                paintView(node, type, i);
                dfs(k + 1);
                for (int j = 0; j < N; j++) {
                    bmap[j] = original[j].clone();
                }
            }
        } else if (type == 2) {
            for (int i = 0; i < 2; i++) {
                paintView(node, 2, i);
                dfs(k + 1);
                for (int j = 0; j < N; j++) {
                    bmap[j] = original[j].clone();
                }
            }
        } else if (type == 5) {
                paintView(node, 5, 0);
                dfs(k + 1);
        }

    }

    //bmap의 0의 개수 세기
    static int numOfZero() {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(bmap[i][j]==0) count++;
            }
        }
        return count;
    }

    static void paintView(Pair node, int type, int dir) {
        //cctv는 통과, 6은 미통과
        if (type == 1) {
            switch(dir) {
                case 0: printUp(node);
                    break;
                case 1: printRight(node);
                    break;
                case 2: printDown(node);
                    break;
                case 3: printLeft(node);
                    break;
            }
        } else if (type == 2) {
            switch (dir) {
                case 0:
                    printUp(node);
                    printDown(node);
                    break;
                case 1:
                    printRight(node);
                    printLeft(node);
                    break;
            }
        } else if (type == 3) {
            switch(dir) {
                case 0:
                    printUp(node);
                    printRight(node);
                    break;
                case 1:
                    printRight(node);
                    printDown(node);
                    break;
                case 2:
                    printDown(node);
                    printLeft(node);
                    break;
                case 3:
                    printLeft(node);
                    printUp(node);
                    break;
            }
        } else if (type == 4) {
            switch(dir) {
                case 0:
                    printUp(node);
                    printLeft(node);
                    printRight(node);
                    break;
                case 1:
                    printRight(node);
                    printUp(node);
                    printDown(node);
                    break;
                case 2:
                    printDown(node);
                    printRight(node);
                    printLeft(node);
                    break;
                case 3:
                    printLeft(node);
                    printUp(node);
                    printDown(node);
                    break;
            }
        } else if (type == 5) {
            printDown(node);
            printUp(node);
            printRight(node);
            printLeft(node);
        }
    }

    static void printUp(Pair node) {
        int x = node.x;
        int y = node.y;
        for (int k = x-1; k >= 0; k--) {
            int nx = k;
            if(bmap[nx][y]==6) break;
            bmap[nx][y] = -1;
        }
    }

    static void printDown(Pair node) {
        int x = node.x;
        int y = node.y;
        for (int k = x + 1; k < N; k++) {
            if(bmap[k][y]==6) break;
            bmap[k][y] = -1;
        }
    }

    static void printRight(Pair node) {
        for (int k = node.y + 1; k < M; k++) {
            if(bmap[node.x][k]==6) break;
            bmap[node.x][k] = -1;
        }
    }
    static  void printLeft(Pair node) {
        for (int k = node.y -1; k >= 0; k--) {
            if(bmap[node.x][k]==6) break;
            bmap[node.x][k] = -1;
        }
    }

}
