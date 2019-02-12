/******************************************************************************
 *  Compilation:  javac Quick.java
 *  Execution:    java Quick < input.txt
 *  Dependencies: StdOut.java StdIn.java
 *  Data files:   https://algs4.cs.princeton.edu/23quicksort/tiny.txt
 *                https://algs4.cs.princeton.edu/23quicksort/words3.txt
 *
 *  Sorts a sequence of strings from standard input using quicksort.
 *   
 *  % more tiny.txt
 *  S O R T E X A M P L E
 *
 *  % java Quick < tiny.txt
 *  A E E L M O P R S T X                 [ one string per line ]
 *
 *  % more words3.txt
 *  bed bug dad yes zoo ... all bad yet
 *       
 *  % java Quick < words3.txt
 *  all bad bed bug dad ... yes yet zoo    [ one string per line ]
 *
 *
 *  Remark: For a type-safe version that uses static generics, see
 *
 *    https://algs4.cs.princeton.edu/23quicksort/QuickPedantic.java
 *
 ******************************************************************************/

package sort;

import utils.StdIn;
import utils.StdRandom;

public class Quick {
    private Quick() {}

    public static void sort(Comparable[] a) {
        StdRandom.shuffle(a);
        sort(a, 0, a.length-1);
        assert SortUtil.isSorted(a);
    }

    private static void sort(Comparable[] a, int low, int high) {
        if(low>=high) return;

        int j = partition(a, low, high);
        sort(a, low, j-1);
        sort(a, j+1, high);
        assert SortUtil.isSorted(a, low, high);
    }

    private static int partition(Comparable[] a, int low, int high) {
        int i=low, j=high+1;
        Comparable v = a[low];

        while(true) {
            // find item on low to swap
            while(SortUtil.less(a[++i], v))
                if(i==high) break;
            
            // find item on high to swap
            while(SortUtil.less(v, a[--j]))
                if(j==low) break;

            if(i>=j) break;
            SortUtil.exch(a, i, j);
        }

        // put partitioning item v at a[j]
        SortUtil.exch(a, low, j);
        // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
        return j;
    }

    // Rearranges the array so that a[k] contains the kth smallest key
    public static Comparable select(Comparable[] a, int k) {
        throw new UnsupportedOperationException("method select not implemented");
    }

    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Quick.sort(a);
        SortUtil.show(a);
    }
}