package org.example;
import java.util.*;
import java.io.*;

public class Main{

    static int N;
    static int[] arr;
    static List<Integer> cpyList;
    static Set<Integer> set = new TreeSet<>();
    static int[] arrPrime;

    public static void main(String[] args)throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        N=Integer.valueOf(br.readLine());
        arr=new int[N];
        arrPrime=new int[N];

        StringTokenizer tokens = new StringTokenizer(br.readLine(), " ");
        int count=0;	//~size
        while(tokens.hasMoreTokens()){
            arr[count++]=Integer.valueOf(tokens.nextToken());
            set.add(arr[count - 1]);
        }

        //when
        count=arr.length;

        //중복제거1: !List.contains(value) => 1개 원소에 대해 O(N) & N개 원소에 대해 O(N^2)
  /*
        for(int num: arr)
        {
            if(!cpyList.contains(num)){
                cpyList.add(num);
            }
        }*/

        //중복제거2: TreeSet<>() => 1개 원소에 대해 O(logN) & N개 원소에 대해 O(NlogN)
        cpyList = new ArrayList<>(set);

        for(int i=0;i<N;i++)
        {
            int target=arr[i];
            arrPrime[i] = Collections.binarySearch(cpyList, target);
        }

        //then
        StringBuilder sb= new StringBuilder();

        for(int num: arrPrime)
        {
            sb.append(num+" ");
        }
        System.out.print(sb.toString());
    }

}