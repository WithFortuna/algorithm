import java.util.*;
import java.io.*;


//N
//1 : 0개
//2 : 7*2 + 2=16개 (12, 23, 21, 32, 34, 43,45... 89,87, )98,
//3 : 1 2_ _/ 2 _ _
//4 : 1 _ _ _

//dp[N][M] === N자리 이고 M으로 시작하는 계단 수
public class Main{

    static int N,K;
    static List<Integer> ls1 = new ArrayList<>();
    static List<Integer> ls2 = new ArrayList<>();

    public static void main(String[] args) throws IOException{
        Scanner sc=new Scanner(System.in);

        N=sc.nextInt();
        K=sc.nextInt();

        //n,n-1,n-2,,,,n-k+1
        //k! (n-k)!

        for (int i = N - K + 1; i <= N; i++) {
            saveFactor(i,ls1);
        }

        for (int i = 1; i <= K; i++) {
            saveFactor(i,ls2);
        }
        if (ls2.isEmpty()) {
            ls2.add(1);
        }

        for (int num : ls2) {
            ls1.remove(Integer.valueOf(num));
        }
        int result = 1;
        for (int num : ls1) {
            result = (result * num) % 10007;
        }

        System.out.println(result);

    }
    static void saveFactor(int k, List<Integer> ls) // 8 -> 2, 2, 2
    {                                               // 5 -> x
        int temp = k;
        if(!ls.contains(Integer.valueOf(1))) ls.add(1);
        //소인수 분해 12 = 2,2,3
        for (int i = 2; i*i <= k; i++) {
            if (temp % i == 0) {
                ls.add(i);
                temp /= i;

                while (temp % i == 0) {
                    ls.add(i);
                    temp /= i;
                }
            }
        }
        ls.add(temp);



    }



}

//100을 6으로 나눈 나머지: 4
//100=5*20 -> 5*2 -> 4
//=2*50 -> 2*2