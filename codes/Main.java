import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int _t = scan.nextInt();
        for (int _i = 0; _i < _t; ++_i) {
            int n = scan.nextInt();
            String s = scan.next();
            String t = scan.next();
            s = " " + s + "2";
            t = " " + t;

            int res = 0, idx = n;
            Boolean F = true;
            for (int i = n; i > 0; --i) {
                if (s.charAt(i + 1) > t.charAt(i)) {
                    res = 1;
                    idx = i;
                    F = true;
                } else if (F && (s.charAt(i + 1) == t.charAt(i))) {
                    res++;
                } else
                    F = false;
            }
            String ansstr = s.substring(1, 1 + idx) + t.substring(idx, t.length());
            System.out.println(ansstr);
            System.out.println(Math.max(1, res));
        }
    }
}