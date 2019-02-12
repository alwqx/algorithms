/******************************************************************************
 *  Compilation:  javac Shell.java
 *  Execution:    java Shell < input.txt
 *  Dependencies: StdOut.java StdIn.java
 *  Data files:   https://algs4.cs.princeton.edu/21elementary/tiny.txt
 *                https://algs4.cs.princeton.edu/21elementary/words3.txt
 *   
 *  Sorts a sequence of strings from standard input using shellsort.
 *
 *  Uses increment sequence proposed by Sedgewick and Incerpi.
 *  The nth element of the sequence is the smallest integer >= 2.5^n
 *  that is relatively prime to all previous terms in the sequence.
 *  For example, incs[4] is 41 because 2.5^4 = 39.0625 and 41 is
 *  the next integer that is relatively prime to 3, 7, and 16.
 *   
 *  % more tiny.txt
 *  S O R T E X A M P L E
 *
 *  % java Shell < tiny.txt
 *  A E E L M O P R S T X                 [ one string per line ]
 *    
 *  % more words3.txt
 *  bed bug dad yes zoo ... all bad yet
 *  
 *  % java Shell < words3.txt
 *  all bad bed bug dad ... yes yet zoo    [ one string per line ]
 *
 *
 ******************************************************************************/

package sort;

import utils.StdIn;

public class Shell {
    private static int SHELL_H = 2;

    private Shell() {}

    public static void sort(Comparable[] a) {
        int n = a.length;
        int h=1;
        while(h<n/3) h=3*h+1;

        while(h>=1) {
            for(int i=h; i<n; i++) {
                for(int j=i; j>=h&&SortUtil.less(a[j], a[j-h]); j-=h)
                    SortUtil.exch(a, j, j-h);
            }
            assert SortUtil.isHSorted(a, h);
            h/=3;
        }

        assert SortUtil.isSorted(a);
    }

    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Shell.sort(a);
        SortUtil.show(a);
    }
}