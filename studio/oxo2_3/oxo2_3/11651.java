import java.util.*;
import java.io.*;
public class Main {

    static class Point implements Comparable<Point>{
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point nextPoint) {
//            Point nextPoint = (Point) nextPointObj;
            if(this.y==nextPoint.y ) return this.x - nextPoint.x;

            return this.y - nextPoint.y;
        }
    }
    static int N;
    static List<Point> pointList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.valueOf(br.readLine());
        int n=N;
        while (n-- > 0) {
            StringTokenizer tokens = new StringTokenizer(br.readLine(), " ");
            int x = Integer.valueOf(tokens.nextToken());
            int y = Integer.valueOf(tokens.nextToken());
            pointList.add(new Point(x, y));
        }

        Collections.sort(pointList);

        for (Point p : pointList) {
            sb.append(p.x + " " + p.y + "\n");
        }
        System.out.println(sb.toString());
    }
}
