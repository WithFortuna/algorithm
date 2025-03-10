package org.example;
import java.util.*;
import java.io.*;


public class Main {

    static int T;
    static int[][] darr;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();

        T=Integer.valueOf(br.readLine());
        int t=T;
        while(t-- > 0)
        {
            StringTokenizer tokens=new StringTokenizer(br.readLine()," ");
            int M, N, x, y;
            M=Integer.valueOf(tokens.nextToken());
            N=Integer.valueOf(tokens.nextToken());
            x=Integer.valueOf(tokens.nextToken());
            y=Integer.valueOf(tokens.nextToken());


            //when
            int num=x;
            boolean flag=true;
            while(num<=M*N)
            {
                if(num % N == y)
                {
                    sb.append(num+"\n");
                    flag=false;
                    break;
                } else if ((num % N == 0) && y == N) {
                    sb.append(num + "\n");
                    flag=false;
                    break;
                } else {
                    num += M;
                }
            }

            if(flag)
            {
                sb.append(-1+"\n");
            }
        }

        //then
        System.out.print(sb.toString());

    }


}
