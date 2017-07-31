// The solution of the problem was written by Izaron
// Date: 01:04:28   29 Jul 2017
// Execution time: 0.249

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    Scanner in;
    PrintWriter out;

    void sub(String a, String b) {
        StringBuffer patt = new StringBuffer();
        patt.append("^");

        int cnt = 0;
        for (int i = 0; i < b.length(); i++) {
            if (b.charAt(i) == ']')
                cnt--;
            cnt = Math.min(cnt, 1);
            cnt = Math.max(cnt, 0);

            if (b.charAt(i) == '_' && cnt == 0) {
                patt.append(".");
            } else if (b.charAt(i) == '%' && cnt == 0) {
                if (patt.length() >= 2) {
                    if (patt.charAt(patt.length() - 2) == '.' &&
                            patt.charAt(patt.length() - 1) == '*') {

                    } else {
                        patt.append(".*");
                    }
                } else {
                    patt.append(".*");
                }
            } else if ((b.charAt(i) == '[' || b.charAt(i) == ']') && cnt > 0) {
                patt.append("\\");
                patt.append(b.charAt(i));
            } else {
                patt.append(b.charAt(i));
            }

            if (b.charAt(i) == '[')
                cnt++;

            cnt = Math.min(cnt, 1);
            cnt = Math.max(cnt, 0);
        }
        patt.append("$");

        try {
            Pattern p = Pattern.compile(patt.toString());
            Matcher m = p.matcher(a);
            boolean match = m.matches();

            out.println(match ? "YES" : "NO");
        } catch (Exception e) {
            out.println("NO");
        }
    }

    void test() {
        String s = in.nextLine();
        StringBuffer a = new StringBuffer();
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '\'') {
                if (s.charAt(i + 1) == '\'') {
                    a.append(s.charAt(i));
                    i++;
                } else {
                    String bs = s.substring(i + 8, s.length() - 1);
                    StringBuffer b = new StringBuffer();
                    for (int z = 0; z < bs.length(); z++) {
                        b.append(bs.charAt(z));
                        if (bs.charAt(z) == '\'')
                            z++;
                    }

                    sub(a.toString(), b.toString());
                    return;
                }
            } else {
                a.append(s.charAt(i));
            }
        }
    }

    public void solve() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);

        int n = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++)
            test();

        out.close();
    }

    public static void main(String[] args) {
        (new Main()).solve();
    }
}
