import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int _t = scan.nextInt();
        for (int _i = 0; _i < _t; ++_i) {
            int n = scan.nextInt();
            String s = scan.next();
            s = " " + s;
            long[] sp = new long[s.length()];

            int[] cl = new int[n + 1];
            int[] cr = new int[n + 1];
            ArrayList<Long> sl = new ArrayList<>();
            sl.add(0L);
            ArrayList<Long> sr = new ArrayList<>();
            sr.add(0L);
            long[] res = new long[n + 1];

            for (int i = 1; i <= n; ++i) {
                if (s.charAt(i) == '<') {
                    cl[i] = 1;
                    sl.add(sl.get(sl.size() - 1) + i);
                    sp[i] = 1;
                } else {
                    cr[i] = 1;
                    sr.add(sr.get(sr.size() - 1) + i);
                    sp[i] = -1;
                }
                cl[i] += cl[i - 1];
                cr[i] += cr[i - 1];
            }

            for (int i = 1; i < sl.size(); ++i) {
                res[i] = sp[i] * i + (sl.get(i) - sl.get(cl[i]) - sr.get(cr[i - 1])) * 2L;
            }
            for (int i = sl.size(); i <= n; ++i) {
                res[i] = sp[i] * i + (n + 1) + (sl.get(sl.size() - 1) - sl.get(cl[i])
                        + sr.get(Math.max(i - 1 - sl.size() + 1, 0)) - sr.get(cr[i - 1])) * 2;
            }
            for (int i = 1; i <= n; ++i)
                System.out.print(res[i] + " ");
            System.out.println();
        }
        scan.close();
    }
}
