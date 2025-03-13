import java.util.*;
import java.io.*;

//1 2 3 4 5
//4
//12 - 2 * 2
//24 - 6( 2 + 4) * 2
//40 - 12(2 + 4 + 6) * 2

public class Main{

    static int T, W;
    static boolean[] isMove;
    static int result;
    static int[] applePos;
    static int max=0;

    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens= new StringTokenizer(br.readLine()," ");
        T=Integer.valueOf(tokens.nextToken());
        W=Integer.valueOf(tokens.nextToken());
        isMove=new boolean[T+1];
        applePos=new int[T+1];

        for(int i=1;i<=T;i++)
        {
            applePos[i]=Integer.valueOf(br.readLine());
        }

        //when
        dfs(1,0);

        System.out.print(max);

    }

    static void dfs(int k, int moveCount)	//k초
    {
        //탈출조건
        if(k>T)
        {
            int pos=1;
            int sum=0;
            for(int i=1;i<=T;i++)
            {
                if(isMove[i])
                {
                    pos= (pos==1?2:1);
                    if(pos==applePos[i]) sum++;
                }else{
                    pos=pos;
                    if(pos==applePos[i]) sum++;
                }
            }
            if(max<sum) max=sum;
            return;
        }

        else
        {
            if (moveCount < W) {
                isMove[k]=true;
                dfs(k+1,moveCount+1);
            }
            isMove[k]=false;
            dfs(k+1,moveCount);
        }
    }


}
