/******************************************************************************
 *  Compilation:  javac Selection.java
 *  Execution:    java  Selection < input.txt
 *  Dependencies: StdOut.java StdIn.java
 *  Data files:   https://algs4.cs.princeton.edu/21elementary/tiny.txt
 *                https://algs4.cs.princeton.edu/21elementary/words3.txt
 *   
 *  Sorts a sequence of strings from standard input using selection sort.
 *   
 *  % more tiny.txt
 *  S O R T E X A M P L E
 *
 *  % java Selection < tiny.txt
 *  A E E L M O P R S T X                 [ one string per line ]
 *    
 *  % more words3.txt
 *  bed bug dad yes zoo ... all bad yet
 *  
 *  % java Selection < words3.txt
 *  all bad bed bug dad ... yes yet zoo    [ one string per line ]
 *
 ******************************************************************************/

package sort;

import utils.StdIn;
import utils.StdOut;

import java.util.Comparator;

public class Selection {
    private Selection() {}

    public static void sort(Comparable[] a) {
        int n = a.length;
        for(int i=0; i<n; i++) {
            int minIndex = i;
            for(int j=i+1; j<n; j++)
                if(SortUtil.less(a[j], a[minIndex])) minIndex=j;
            SortUtil.exch(a, i, minIndex);
            assert SortUtil.isSorted(a, 0, i);
        }

        assert SortUtil.isSorted(a);
    }

    public static void sort(Object[] a, Comparator comparator) {
        int n = a.length;
        for(int i=0; i<n; i++) {
            int minIndex = i;
            for(int j=i+1; j<n; j++)
                if(SortUtil.less(comparator, a[j], a[minIndex])) minIndex = j;
            SortUtil.exch(a, i, minIndex);
            assert SortUtil.isSorted(a, comparator, 0, minIndex);
        }

        assert SortUtil.isSorted(a, comparator);
    }

    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Selection.sort(a);
        SortUtil.show(a);
    }
}