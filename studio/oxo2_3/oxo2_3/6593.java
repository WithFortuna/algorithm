package org.example;

import java.io.*;
import java.util.*;

public class Main {
    static int L,N,M;

    static class Pos {
        int x, y, z;
        int length;

        public Pos() {
        }

        public Pos(int x, int y, int z, int length) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.length = length;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            L = sc.nextInt();
            N=sc.nextInt();
            M = sc.nextInt();
            if(L==0) break;

            Pos start = new Pos();

            char[][][] bmap = new char[L][N][M];
            for (int i = 0; i < L; i++) {
                for (int n = 0; n < N; n++) {
                        String str = sc.next();
                        for(int k=0;k<str.length();k++)
                            if(str.charAt(k)=='S'){
                                start.x = n;
                                start.y = k;
                                start.z = i;
                                start.length=0;
                            }
                        bmap[i][n] = str.toCharArray();
                }
            }
            //when
            //bfs
            int result = bfs(bmap, start);
            if (result != -1) {
                System.out.println("Escaped in "+result+" minute(s).");

            }else{
                System.out.println("Trapped!");
            }



        }
    }

    static int bfs(char[][][] bmap, Pos start) {
        //initialize
        Queue<Pos> q = new LinkedList<>();
        boolean[][][] visited = new boolean[bmap.length][bmap[0].length][bmap[0][0].length];

        q.offer(start);
        visited[start.z][start.x][start.y] = true;
        int row = bmap[0].length;
        int col = bmap[0][0].length;
        int height = bmap.length;
        int[] dx = {1, -1, 0, 0, 0, 0};
        int[] dy = {0, 0, 1, -1, 0, 0};
        int[] dz = {0, 0, 0, 0, 1, -1};
        while (!q.isEmpty()) {
            //q.poll
            Pos node = q.poll();
            if (bmap[node.z][node.x][node.y] == 'E') {
                return node.length;
            }
            //탐색
            for (int i = 0; i < 6; i++) {
                int nx = node.x + dx[i];
                int ny = node.y + dy[i];
                int nz = node.z + dz[i];
                if(nx<0||ny<0||nz<0||nx>=row||ny>=col||nz>=height) continue;
                    //visited=true, q.offer
                else if ((bmap[nz][nx][ny] == '.' || bmap[nz][nx][ny]=='E') && !visited[nz][nx][ny]) {
                    visited[nz][nx][ny] = true;
                    q.offer(new Pos(nx, ny, nz, node.length + 1));
                }
            }

        }
        return -1;

    }

}
