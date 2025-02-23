package org.example;

import java.util.*;
import java.io.*;

public class Main {


    static int N;
    static long[] arr;
    static int[] result;

    public static void main(String[] args) throws IOException {
        //중복 수가 최대인 카드를 찾음(동점일 시, 작은 수)
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        N=Integer.valueOf(br.readLine());;
        arr=new long[N];
        result=new int[N];

        for(int i=0;i<N;i++)
        {
            arr[i]=Long.valueOf(br.readLine());
        }

        //when
        Arrays.sort(arr);

        Long prev=0L;
        boolean counting=false;
        int count=0;

        for(int i=0;i<N;i++)
        {
            if (i == 0) {
                prev = arr[i];
                continue;
            }

            if(counting)
            {
                if(prev==arr[i])
                {
                    count++;
                }else{  //counting 종료
                    counting=false;
                    result[i-1]=count;
                    count=0;
                }

            }else{
                if(prev==arr[i])    //counting시작
                {
                    counting=true;
                    count++;
                }
            }
            prev=arr[i];
        }
        if (counting) {
            result[N-1]=count;
        }

        //result[]에 중복 횟수 저장완료
        int maxIdx=-1;
        int max=0;
        for(int i=0;i<N;i++)
        {
            if(result[i]>max)
            {
                max=result[i];
                maxIdx=i;
            }
        }

        System.out.print(arr[maxIdx==-1?0:maxIdx]);
    }
}
