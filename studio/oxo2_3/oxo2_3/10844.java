import java.util.*;
import java.io.*;


//N
//1 : 0개
//2 : 7*2 + 2=16개 (12, 23, 21, 32, 34, 43,45... 89,87, )98,
//3 : 1 2_ _/ 2 _ _
//4 : 1 _ _ _

//dp[N][M] === N자리 이고 M으로 시작하는 계단 수
public class Main{

    static long[][] dp;
    static long[] dpZero;
    static int N;

    public static void main(String[] args) throws IOException{

        //given
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        N=Integer.valueOf(br.readLine());
        dp=new long[N][9];
        dpZero=new long[N+1];

        //when
        //1 0
        // 1 0 _
        // 1 0 _ _ = 2시작 한자리수 + 1
        // 1 0 _ _ _ = 2시작 두자리수 + 1(0시작 두자리수)
        // 1 0 _ _ _ _ = 2시작 세자리수 + 0시작 세자리수

        //dp
        Arrays.fill(dp[0],1);
        dpZero[0]=1L;
        dpZero[1]=1L;


        for(int i=1;i<N;i++)
        {
            if (i >= 2) { //0포함 3자리수부터
                dpZero[i] = (dp[i - 2][1] + dpZero[i - 2])%1000000000;
            }
            for(int j=0;j<9;j++)
            {
                if(j==0)
                {
                    //1 _ _
                    dp[i][0]=(dp[i-1][1] + dpZero[i-1])%1000000000;
                }
                else if(j==8)
                {
                    //9 _ _
                    dp[i][8]=dp[i-1][7];
                }
                else{
                    //2 _ _
                    dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1])%1000000000;
                }
            }
        }

        //then
        //N자리 의 계단수
        long result=0L;

        for(long num: dp[N-1])
        {
            result+=num%1000000000;
        }

        System.out.print(result%1000000000);
    }


}