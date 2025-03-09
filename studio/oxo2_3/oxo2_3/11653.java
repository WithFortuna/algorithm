package org.example;
import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static StringBuilder sb=new StringBuilder();

    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        N=sc.nextInt();

        //when
        if (N != 1) {
            dfs(N);
            System.out.print(sb.toString());
        }

    }

    public static void dfs(int k)
    {
        boolean isPrime=true;

        for(int i=2;i<k;i++)    //2~k-1 숫자들 중에서 k를 나눈 나머지가 0인 수가 없다면 소수이다.
        {
            if(k%i==0) //k = i x q
            {
                int q=k/i;
                dfs(i);
                dfs(q);
                isPrime=false;
                break;
            }
        }

        if(isPrime)
        {
            sb.append(k+"\n");
        }


    }
}
