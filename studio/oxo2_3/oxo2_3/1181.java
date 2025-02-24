package org.example;

import java.util.*;
import java.io.*;
import java.util.*;
import java.io.*;

public class Main {

    //정렬 기준: 길이순 -> 사전순
    //입력값 중복제거
    static int N;
    static String[] words;
    static Set<String> set=new HashSet<>();

    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();

        N= Integer.valueOf(br.readLine());
//        words=new String[N];

        for(int i=0;i<N;i++)
        {
            String word=String.valueOf(br.readLine());
            set.add(word);
        }
        words = new String[set.size()];
        int I=0;
        for (String word : set) {
            words[I++]=word;
        }

        //when
        //정렬

        Arrays.sort(words, (o1, o2) ->  //Comparator인터페이스 구현
                o1.length() == o2.length() ? o1.compareTo(o2) : o1.length() - o2.length()
        );

        for(String word:words)
        {
            sb.append(word+"\n");
        }
        System.out.print(sb.toString());
    }

}
