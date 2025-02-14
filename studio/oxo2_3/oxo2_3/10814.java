package org.example;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    static int N;
    static Set<Integer> ages;
    static Map<Integer, List<String>> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.valueOf(br.readLine());
        ages = new HashSet<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer tokens = new StringTokenizer(br.readLine()," ");

            Integer age = Integer.valueOf(tokens.nextToken());
            ages.add(age);
            String name = tokens.nextToken();
            if (map.get(age) == null) {
                map.put(age, new ArrayList<>());
            }
            map.get(age).add(name);
        }

        List<Integer> ageList = new ArrayList<>(ages);
        Collections.sort(ageList);

        for (int age : ages) {
            for (int i = 0; i < map.get(age).size(); i++) {
                List<String> names = map.get(age);
                sb.append(age + " "+names.get(i)+"\n");
            }
        }

        System.out.println(sb.toString());
    }

}