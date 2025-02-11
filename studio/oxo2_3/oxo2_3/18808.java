package org.example;

import java.io.*;
import java.util.*;

public class Main {

    static int N,M, numSticker;
    static int[][]bmap;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        numSticker = sc.nextInt();

        bmap = new int[N][M];
        int temp = numSticker;
        while (temp-- > 0) {
            //스티커 받기
            int sn, sm;
            sn = sc.nextInt();
            sm = sc.nextInt();
            int[][] sticker = new int[sn][sm];
            for (int i = 0; i < sn; i++) {
                for (int j = 0; j < sm; j++) {
                    sticker[i][j] = sc.nextInt();
                }
            }
            //붙이기
//            -----------
/*            int[][] original = new int[N][M];
            for (int i = 0; i < N; i++) {
                System.arraycopy(bmap[i], 0, original[i], 0, M);
            }*/
//            ------------
            for (int i = 0; i < 4; i++) {
                //방향탐색
                if (printSticker(sticker)) {
                    break;
                } else {
/*
                    //bmap복구
                    for (int k = 0; k < N; k++) {
                        System.arraycopy(original[i], 0, bmap[i], 0, M);
                    }
*/
                    sticker = rotateSticker(sticker);
                }
            }
        }

        System.out.println(getResult());
    }

    private static boolean printSticker(int[][] sticker) {
        //move
        int difX = N - sticker.length;
        int difY = M - sticker[0].length;
        for (int i = 0; i <= difX; i++) { //move down
            for (int j = 0; j <= difY; j++) { //move right

                boolean flag = true;
                for (int n = 0; n < sticker.length; n++) {
                    for (int m = 0; m < sticker[0].length; m++) {
                        if (sticker[n][m] == 1 && bmap[n+i][m+j] != 0) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if (flag) {//스티커 붙이기 가능
                    for (int n = 0; n < sticker.length; n++) {
                        for (int m = 0; m < sticker[0].length; m++) {
                            if(sticker[n][m]==0) continue;
                            bmap[n + i][m + j] = sticker[n][m];
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }

    private static int[][] rotateSticker(int[][] sticker) {
        //column -> row
        int row =sticker.length;
        int col = sticker[0].length;

        int[][] nSticker = new int[col][row];
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                int nx=i;
                int ny = row - 1 - j;
                nSticker[nx][ny] = sticker[j][i];
            }
        }
        return nSticker;
    }

    private static int getResult() {
        int result=0;
        for (int[] row : bmap) {
            for (int num : row) {
                if(num==1) result++;
            }
        }
        return result;
    }
}
