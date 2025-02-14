/*
package org.example;

import java.io.*;
import java.util.Scanner;

public class Main {

    static int N;
    static int[] arr;

    static int[] newArr;

    public static void main(String[] args) throws IOException{
//        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//        N = sc.nextInt();

        N = Integer.valueOf(br.readLine());
        newArr = new int[N];
        arr = new int[N];
        for (int i = 0; i<N;i++) {
            arr[i] = Integer.valueOf(br.readLine());
//            arr[i] = sc.nextInt();
        }



//        mergeSort(0, N - 1);

        StringBuilder sb = new StringBuilder();
        for (int num : arr) {
            sb.append(num + "\n");
        }

        System.out.println(sb.toString());

    }

    static void mergeSort(int st, int end) {    //0 indexed
        //탈출조건
        if (st==end) {
            return;
        }

        int medium = st+ (end-st) / 2; //길이
        */
/*
        int[] front = new int[medium];
        int[] back = new int[len - medium];
        System.arraycopy(arr,0,front,0,medium);
        System.arraycopy(arr, medium, back, 0, len - medium);
        *//*

        mergeSort(st, medium);              //범위 내 배열은 정렬됨
        mergeSort(medium + 1, end);     //범위 내 배열은 정렬됨

        merge(st, medium, end);
    }

    static void merge(int st, int medium, int end) {
        //arr1: st~medium
        //arr2: medium+1~end

//        int[] newArr = new int[end - st + 1];
        int count = 0;

        int pos1 = st;
        int pos2 = medium + 1;

        //정렬된 두개의 배열 비교
        while (pos1 != medium+1 && pos2 != end+1) {
            if (arr[pos1] < arr[pos2]) {
                newArr[count++] = arr[pos1++];
            } else {
                newArr[count++] = arr[pos2++];
            }
        }

        //누가 먼저 소진됐나
        if (pos1 == medium + 1) {
            while (pos2 != end + 1) {
                newArr[count++] = arr[pos2++];
            }
        } else if (pos2 == end + 1) {
            while (pos1 != medium + 1) {
                newArr[count++] = arr[pos1++];
            }
        }

        System.arraycopy(newArr, 0, arr, st, end-st+1);
    }
}*/
