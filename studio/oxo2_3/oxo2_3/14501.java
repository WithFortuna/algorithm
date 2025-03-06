import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.*;
import java.io.*;
import java.util.*;
import java.io.*;

import java.util.*;
import java.io.*;

public class Main{
    static int N;
    static int[][] darr;
    static int[] dp;

    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        N=Integer.valueOf(br.readLine());
        darr=new int[N][2];
        dp=new int[N];

        for(int i=0;i<N;i++)
        {
            StringTokenizer tokens=new StringTokenizer(br.readLine()," ");
            darr[i][0]=Integer.valueOf(tokens.nextToken());
            darr[i][1]=Integer.valueOf(tokens.nextToken());
        }

        //when
        for(int i=0;i<N;i++)
        {
            if(darr[i][0]-1+i<N) dp[i]=darr[i][1];
            else dp[i]=0;
        }

        for(int i=1;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j+darr[j][0]-1<i) //[이전] 기간이 영향을 미치지 않음
                {
                    if(i+darr[i][0]-1<N) //in deadline
                    {
                        dp[i]=Math.max(dp[i],dp[j]+darr[i][1]);
                    }
                }
            }
        }

        int max=0;
        for(int num: dp)
        {
            if(num>max) max=num;
        }

        System.out.println(max);

    }


}