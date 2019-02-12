/******************************************************************************
 *  Compilation:  javac Insertion.java
 *  Execution:    java Insertion < input.txt
 *  Dependencies: StdOut.java StdIn.java
 *  Data files:   https://algs4.cs.princeton.edu/21elementary/tiny.txt
 *                https://algs4.cs.princeton.edu/21elementary/words3.txt
 *  
 *  Sorts a sequence of strings from standard input using insertion sort.
 *
 *  % more tiny.txt
 *  S O R T E X A M P L E
 *
 *  % java Insertion < tiny.txt
 *  A E E L M O P R S T X                 [ one string per line ]
 *
 *  % more words3.txt
 *  bed bug dad yes zoo ... all bad yet
 *
 *  % java Insertion < words3.txt
 *  all bad bed bug dad ... yes yet zoo   [ one string per line ]
 *
 ******************************************************************************/

package sort;

import java.util.Comparator;

import utils.StdIn;

public class Insertion {
    public Insertion() {}

    public static void sort(Comparable[] a) {
        int n = a.length;
        for(int i=1; i<n; i++) {
            for(int j=i; j>0&&SortUtil.less(a[j], a[j-1]); j--)
                SortUtil.exch(a, j, j-1);
            assert SortUtil.isSorted(a, 0, i);
        }

        assert SortUtil.isSorted(a);
    }

    public static void sort(Comparable[] a, int low, int high) {
        for(int i=low+1; i<high; i++) {
            for(int j=i; j>low&&SortUtil.less(a[j], a[j-1]); j--)
                SortUtil.exch(a, j, j-1);
        }

        assert SortUtil.isSorted(a, low, high);
    }

    public static void sort(Object[] a, Comparator comparator) {
        int n = a.length;
        for(int i=1; i<n; i++) {
            for(int j=i; j>0&&SortUtil.less(comparator, a[j], a[j-1]); j--)
                SortUtil.exch(a, j, j-1);
            assert SortUtil.isSorted(a, comparator, 0, i);
        }

        assert SortUtil.isSorted(a, comparator);
    }

    public static void sort(Object[] a, int low, int high, Comparator comparator) {
        for(int i=low+1; i<high; i++) {
            for(int j=i; j>low&&SortUtil.less(comparator, a[j], a[j-1]); j--)
                SortUtil.exch(a, j, j-1);
            assert SortUtil.isSorted(a, comparator, low, i);
        }

        assert SortUtil.isSorted(a, comparator);
    }

    // return a permutation that gives the elements in a[] in ascending order
    // do not change the original array a[]
    public static int[] indexSort(Comparable[] a) {
        int n = a.length;
        int[] index = new int[n];
        for(int i=0; i<n; i++)
            index[i] = i;

        for(int i=1; i<n; i++) {
            for(int j=i; j>0&&SortUtil.less(a[index[j]], a[index[j-1]]); j--)
                SortUtil.exch(index, j, j-1);
        }

        return index;
    }

    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Insertion.sort(a);
        SortUtil.show(a);
    }
}