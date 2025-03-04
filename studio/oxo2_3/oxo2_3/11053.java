package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] arr;
    static int[] dp;    //dp[k]== index 0~k 중 k를 포함하며 가장 긴 조합의 길이

    //DP인데 k,k+1으로 제한적이지 않음. (ex. dp[k+1]==dp[?]+1)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.valueOf(br.readLine());
        arr = new int[N];
        dp = new int[N];

        StringTokenizer tokens = new StringTokenizer(br.readLine(), " ");

        int size=0;
        while (tokens.hasMoreTokens()) {
            arr[size++] = Integer.valueOf(tokens.nextToken());
        }

        //when
        Arrays.fill(dp, 1);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int max=0;
        for (int num : dp) {
            if(max<num) max = num;
        }
        System.out.println(max);
    }



}
