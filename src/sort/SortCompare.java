package sort;

import utils.StdOut;
import utils.StdRandom;
import utils.Stopwatch;

public class SortCompare {
    public SortCompare() {}

    public static double time(String alg, Comparable[] a) {
        Stopwatch timer = new Stopwatch();
        if(alg.equals("Insertion")) Insertion.sort(a);
        if(alg.equals("Selection")) Selection.sort(a);

        return timer.elapsedTime();
    }

    // use alg sort T arrays with length N
    public static double timeRandomInput(String alg, int N, int T) {
        double total = 0.0;
        Double[] a = new Double[N];
        
        for(int t=0; t<T; t++) {
            for(int i=0; i<N; i++)
                a[i] = StdRandom.uniform();
            total += time(alg, a);
        }

        return total;
    }

    public static void main(String[] args) {
        String alg1 = args[0];
        String alg2 = args[1];
        int N = Integer.parseInt(args[2]);
        int T = Integer.parseInt(args[3]);

        double t1 = timeRandomInput(alg1, N, T);
        double t2 = timeRandomInput(alg2, N, T);

        StdOut.printf("For %d random Doubles\n", N);
        StdOut.printf("%s is %f\n", alg1, t1);
        StdOut.printf("%s is %f\n", alg2, t2);
        StdOut.printf("%s is %.2f faster than %s\n", alg1, t2/t1, alg2);

    }
}