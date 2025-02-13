package org.example;

import java.io.*;
import java.util.*;
//하나의 시도에 블럭은 한번의 머지만 가능
//3개가 있는 경우엔 방향 위쪽의 블럭이 머지의 대상
public class Main {

    static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x=x;
            this.y = y;
        }
    }
    static int N,M;
    static int result = 0;
    static int numChicken=0;
    static List<Pair> chickens = new ArrayList<>();
    static List<Pair> homes = new ArrayList<>();
    static int[] selected; //선택된 치킨집 인덱스
    static int[][] bmap;    //1 indexed

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        bmap = new int[N + 1][N + 1]; //1 indexed
        selected = new int[M];// 0 indexed

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                bmap[i][j] = sc.nextInt();
                if (bmap[i][j] == 2) {
                    numChicken++;
                    chickens.add(new Pair(i, j));
                } else if (bmap[i][j] == 1) {
                    homes.add(new Pair(i, j));
                }
            }
        }

        //when
        dfs(0,0);

        System.out.println(result);

    }

    static void dfs(int k, int start) {    //0 indexed
        //탈출조건
        if (k >= M) {
            int sum = getDistance();
            if(sum<result || result==0) result = sum;
            return;
        }

        //탐색
        for (int i = start; i < numChicken; i++) {
            selected[k] = i;
            dfs(k+1, i+1);
        }

    }

    static int getDistance() {  //도시 치킨거리
        int cityDist = 0;
        for (Pair home : homes) {
            //selected 치킨 집 중 최소거리
            int distance = 0;
            for (int i : selected) {
                Pair posChicken = chickens.get(i);
                int dx = Math.abs(posChicken.x - home.x);
                int dy = Math.abs(posChicken.y - home.y);
                if (distance > (dx + dy) || distance == 0) {
                    distance = dx + dy;
                }

            }
            cityDist += distance;
        }
        return cityDist;
    }
}