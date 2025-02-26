package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    //정렬: 빈도순(내림차순)
    static int N, C;
    static Integer[] arr;
    static int count=0;
    //    static List<Pair> pairs = new ArrayList<>();
    static Map<Integer, Integer> countMap = new HashMap<>();
    static Map<Integer, Integer> startMap = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();

        StringTokenizer tokens=new StringTokenizer(br.readLine()," ");
        N=Integer.valueOf(tokens.nextToken());
        arr=new Integer[N];
        C=Integer.valueOf(tokens.nextToken());

        StringTokenizer nums=new StringTokenizer(br.readLine()," ");
        while(nums.hasMoreTokens())
        {
            int num=Integer.valueOf(nums.nextToken());
            arr[count++]=num;
        }

        //when
        //빈도, 시작인덱스 저장
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            //원소에 있으면 +1
            if (countMap.get(num) != null) {
                Integer val = countMap.get(num) + 1;
                countMap.put(num, val);
            } else {  //원소가 없으면 추가
                countMap.put(num, 1);
                startMap.put(num, i);
            }
        }

        //정렬(빈도순, 선착순 )
        Arrays.sort(arr, (o1,o2)-> //int o1, o2
                {
                    int o1Count = countMap.get(o1);
                    int o2Count = countMap.get(o2);

                    if(o1Count==o2Count) return startMap.get(o1)-startMap.get(o2);
                    return -(o1Count-o2Count);
                }
        );

        for(int num: arr)
        {
            sb.append(num+" ");
        }

        System.out.print(sb.toString());


    }



}
