package org.example;

import java.util.*;

public class Main {


    static int N,M;
    static int[] result = new int[10];
    static boolean[] used = new boolean[10];

    public static void func(int k) { //1 indexed
        //탈출조건
        if (k > N) {
            for (int num : result) {
                System.out.print(num + " ");
                System.out.print("\n");
            }
            return;
        } else {
            //탐색
            for (int i = 1; i <= N; i++) {
                if (!used[i]) {
                    //used=true
                    used[i] = true;
                    func(k+1);
                    used[i] = false;
                }
            }
        }


    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        //when
        func(1);

    }

}