import java.util.*;
import java.io.*;
public class Main{

    //연속 P일 중에서 L일만 사용가능
    //V일의 휴가가 있음
    //L P V 을 입력값
    public static void main(String[] args)throws IOException{
        int P=-1, L=-1, V=-1;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        int count=1;

        while(true){
            StringTokenizer tokens=new StringTokenizer(br.readLine()," ");
            L=Integer.valueOf(tokens.nextToken());
            P=Integer.valueOf(tokens.nextToken());
            V=Integer.valueOf(tokens.nextToken());

            if((P==0 && L==0 && V==0)) break;

            int q= V / P;
            int rest= V % P;
            int result=0;

            if (rest <= L) {
                result += q * L + rest;
            } else {
                result += q * L + L;
            }
            sb.append("Case "+count+": "+result+"\n");
            count++;
        }

        System.out.print(sb.toString());
    }


}