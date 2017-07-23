import sun.reflect.generics.tree.Tree;

import java.util.*;

public class scales {
    public void init(int T) {
        for (int m = 0; m < 3; m++) {   // MODE
            for (int a = 0; a < 6; a++) {
                for (int b = a + 1; b < 6; b++) {
                    for (int c = b + 1; c < 6; c++) {
                        funcs.add(new Func(m, a, b, c));
                    }
                }
            }
        }

        for (int d = 0; d < 6; d++) {
            for (int a = 0; a < 6; a++) {
                for (int b = a + 1; b < 6; b++) {
                    for (int c = b + 1; c < 6; c++) {
                        if (a == d || b == d || c == d)
                            continue;
                        funcs.add(new Func(3, a, b, c, d));
                        funcs.add(new Func(3, a, b, c, d));
                        funcs.add(new Func(3, a, b, c, d));
                    }
                }
            }
        }

        gen(0, new ArrayList<>());

        //Random random = new Random(13);
        //Collections.shuffle(funcs, random);
        //Collections.shuffle(perms, random);
    }

    void gen(int mask, List<Integer> list) {
        if (mask == (1 << 6) - 1) {
            perms.add(new Perm(list));
            return;
        }
        for (int i = 0; i < 6; i++) {
            if ((mask & (1 << i)) != 0)
                continue;
            List<Integer> nlist = new ArrayList<>(list);
            nlist.add(i);
            gen(mask | (1 << i), nlist);
        }
    }

    class Func {
        // 0 - max
        // 1 - min
        // 2 - mid
        // 3 - misc
        int mode;
        int a, b, c, d;
        int res;

        Func(int mode, int a, int b, int c) {
            this.mode = mode;
            this.a = a;
            this.b = b;
            this.c = c;
        }

        Func(int mode, int a, int b, int c, int d) {
            this.mode = mode;
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
    }

    class Perm {
        List<Integer> list = new ArrayList<>(6);
        int ind[];

        Perm(List<Integer> list) {
            this.list = list;
            ind = new int[6];
            for (int i = 0; i < 6; i++)
                ind[list.get(i)] = i;
        }

        boolean can(Func func) {
            if (func.mode == 0) {
                int rval = Math.max(Math.max(ind[func.a], ind[func.b]), ind[func.c]);
                return (rval == ind[func.res]);
            } else if (func.mode == 1) {
                int rval = Math.min(Math.min(ind[func.a], ind[func.b]), ind[func.c]);
                return (rval == ind[func.res]);
            } else if (func.mode == 2) {
                int a = ind[func.a], b = ind[func.b], c = ind[func.c];
                int rval;
                if (a > b && a < c)
                    rval = a;
                else if (b > a && b < c)
                    rval = b;
                else
                    rval = c;
                return (rval == ind[func.res]);
            } else if (func.mode == 3) {
                int a = ind[func.a], b = ind[func.b], c = ind[func.c];
                int d = ind[func.d];
                int rval;
                if (d > a && d > b && d > c) {
                    rval = Math.min(Math.min(a, b), c);
                } else {
                    rval = Integer.MAX_VALUE / 2;
                    if (a > d) rval = Math.min(rval, a);
                    if (b > d) rval = Math.min(rval, b);
                    if (c > d) rval = Math.min(rval, c);
                }
                return (rval == ind[func.res]);
            }

            throw new RuntimeException();
        }

        int get(Func func) {
            int rval;
            if (func.mode == 0) {
                rval = Math.max(Math.max(ind[func.a], ind[func.b]), ind[func.c]);
            } else if (func.mode == 1) {
                rval = Math.min(Math.min(ind[func.a], ind[func.b]), ind[func.c]);
            } else if (func.mode == 2) {
                int a = ind[func.a], b = ind[func.b], c = ind[func.c];
                if (a > b && a < c)
                    rval = a;
                else if (b > a && b < c)
                    rval = b;
                else
                    rval = c;
            } else if (func.mode == 3) {
                int a = ind[func.a], b = ind[func.b], c = ind[func.c];
                int d = ind[func.d];
                if (d > a && d > b && d > c) {
                    rval = Math.min(Math.min(a, b), c);
                } else {
                    rval = Integer.MAX_VALUE / 2;
                    if (a > d) rval = Math.min(rval, a);
                    if (b > d) rval = Math.min(rval, b);
                    if (c > d) rval = Math.min(rval, c);
                }
            } else {
                throw new RuntimeException();
            }

            if (rval == ind[func.a])
                return 0;
            else if (rval == ind[func.b])
                return 1;
            else if (rval == ind[func.c])
                return 2;

            throw new RuntimeException();
        }
    }

    void defineFunc(Func func) {
        cnt++;
        if (func.mode == 0) {
            func.res = grader.lib.getHeaviest(func.a + 1, func.b + 1, func.c + 1) - 1;
        } else if (func.mode == 1) {
            func.res = grader.lib.getLightest(func.a + 1, func.b + 1, func.c + 1) - 1;
        } else if (func.mode == 2) {
            func.res = grader.lib.getMedian(func.a + 1, func.b + 1, func.c + 1) - 1;
        } else if (func.mode == 3) {
            func.res = grader.lib.getNextLightest(func.a + 1, func.b + 1, func.c + 1, func.d + 1) - 1;
        }
    }

    List<Func> funcs = new ArrayList<>();
    List<Perm> perms = new ArrayList<>();

    int[] calc(Set<Integer> canPerms, Func func) {
        int[] res = new int[3];
        for (Integer it : canPerms)
            res[perms.get(it).get(func)]++;
        return res;
    }

    void run(Set<Integer> canPerms, Set<Integer> canFuncs) {
        if (canPerms.size() == 1)
            return;

        int index = -1;
        List<Integer> badFuncs = new ArrayList<>();

        int best = Integer.MAX_VALUE / 2;

        for (Integer it : canFuncs) {
            int[] res = calc(canPerms, funcs.get(it));
            int cnt = 0;
            if (res[0] > 0) cnt++;
            if (res[1] > 0) cnt++;
            if (res[2] > 0) cnt++;
            if (cnt > 1) {
                int curBest = Math.max(Math.max(res[0], res[1]), res[2]);
                if (best > curBest) {
                    best = curBest;
                    index = it;
                }
                //break;
            } else {
                badFuncs.add(it);
            }
        }
        canFuncs.removeAll(badFuncs);

        if (index == -1)
            throw new RuntimeException();

        defineFunc(funcs.get(index));

        List<Integer> badPerms = new ArrayList<>();
        for (Integer it : canPerms) {
            if (!perms.get(it).can(funcs.get(index)))
                badPerms.add(it);
        }
        canPerms.removeAll(badPerms);

        run(canPerms, canFuncs);
    }


    boolean out = false;
    int test = 0;
    int cnt = 0;
    int maxCnt = 0;

    public void orderCoins() {
        cnt = 0;
        TreeSet<Integer> aa = new TreeSet<>();
        for (int i = 0; i < perms.size(); i++)
            aa.add(i);
        TreeSet<Integer> bb = new TreeSet<>();
        for (int i = 0; i < funcs.size(); i++)
            bb.add(i);
        run(aa, bb);

        int index = aa.first();

        if (out) {
            maxCnt = Math.max(maxCnt, cnt);
            System.out.print("Test #" + (test++) + " count: " + cnt + " (");
            for (int i = 0; i < 6; i++)
                System.out.print((perms.get(index).list.get(i) + 1) + ", ");
            System.out.println(") " + maxCnt);
            System.out.flush();
        }

        int[] w = new int[6];
        for (int i = 0; i < 6; i++)
            w[i] = perms.get(index).list.get(i) + 1;
        grader.lib.answer(w);
    }
}
