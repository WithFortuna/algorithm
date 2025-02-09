package org.example;

import java.io.*;
import java.util.*;

public class Main {
    static int N,M;
    static int[] arr = new int[10];
    static int[] numbers;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        int[] container = new int[N];
        for (int i = 0; i < N; i++) {
            container[i] = sc.nextInt();
        }
        Arrays.sort(container);
        numbers = Arrays.copyOf(container, container.length);
        solution();
        System.out.println(sb.toString());
    }

    private static void solution() {
        dfs(0);
    }

    private static void dfs(int k) { //0 indexed
        //탈출조건
        if (k >= M) {
            for (int a : arr) {
                if (a != 0) {
                    sb.append(a+" ");
                }
            }
            sb.append("\n");
            return;
        }
        //탐색
        for (int i = 0; i < N; i++) {
            int num = numbers[i];
            arr[k] = num;
            dfs(k + 1);
            /*if (k == 0) {
                arr[k]=num;
                dfs(k+1);
            } else if (numbers[i] > arr[k - 1]) {
                arr[k]=num;
                dfs(k + 1);
            }*/
        }
    }


}
