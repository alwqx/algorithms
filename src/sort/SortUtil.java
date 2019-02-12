package sort;

import java.util.Comparator;

import utils.StdOut;

public class SortUtil {
    public SortUtil() {}

    public static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    public static boolean less(Comparator comparator, Object v, Object w) {
        return comparator.compare(v, w) < 0;
    }

    public static void exch(Object[] a, int i, int j) {
        Object swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    // exchange a[i] and a[j]  (for indirect sort)
    public static void exch(int[] a, int i, int j) {
        int swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    /***************************************************************************
    *  Check if array is sorted - useful for debugging.
    ***************************************************************************/
    public static boolean isSorted(Comparable[] a) {
        return isSorted(a, 0, a.length);
    }

    // is the array a[lo..hi) sorted
    public static boolean isSorted(Comparable[] a, int lo, int hi) {
        for (int i = lo + 1; i < hi; i++)
            if (less(a[i], a[i-1])) return false;
        return true;
    }

    public static boolean isSorted(Object[] a, Comparator comparator) {
        return isSorted(a, comparator, 0, a.length);
    }

    // is the array a[lo..hi) sorted
    public static boolean isSorted(Object[] a, Comparator comparator, int lo, int hi) {
        for (int i = lo + 1; i < hi; i++)
            if (less(comparator, a[i], a[i-1])) return false;
        return true;
    }

    // is the array h-sorted?
    public static boolean isHSorted(Comparable[] a, int h) {
        for (int i = h; i < a.length; i++)
            if (less(a[i], a[i-h])) return false;
        return true;
    }

    // print array to standard output
    public static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            StdOut.println(a[i]);
        }
    }
}