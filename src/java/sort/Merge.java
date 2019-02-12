/******************************************************************************
 *  Compilation:  javac Merge.java
 *  Execution:    java Merge < input.txt
 *  Dependencies: StdOut.java StdIn.java
 *  Data files:   https://algs4.cs.princeton.edu/22mergesort/tiny.txt
 *                https://algs4.cs.princeton.edu/22mergesort/words3.txt
 *   
 *  Sorts a sequence of strings from standard input using mergesort.
 *   
 *  % more tiny.txt
 *  S O R T E X A M P L E
 *
 *  % java Merge < tiny.txt
 *  A E E L M O P R S T X                 [ one string per line ]
 *    
 *  % more words3.txt
 *  bed bug dad yes zoo ... all bad yet
 *  
 *  % java Merge < words3.txt
 *  all bad bed bug dad ... yes yet zoo    [ one string per line ]
 *  
 ******************************************************************************/

package sort;

import utils.StdIn;

public class Merge {
    private Merge() {}

    // stably merge a[low .. mid] with a[mid+1 ..high] using aux[low .. high]
    public static void merge(Comparable[] a, Comparable[] aux, int low, int mid, int high) {
        assert SortUtil.isSorted(a, low, mid);
        assert SortUtil.isSorted(a, mid+1, high);
        
        // copy to aux
        for(int k=low; k<=high; k++)
            aux[k] = a[k];
        
        // merge back to a[]
        int i=low, j=mid+1;
        for(int k=low; k<=high; k++) {
            if(i>mid)                               a[k] = aux[j++];
            else if(j>high)                         a[k] = aux[i++];
            else if(SortUtil.less(aux[j], aux[i]))  a[k] = aux[j++];
            else                                    a[k] = aux[i++];
        }

        assert SortUtil.isSorted(a, low, high);
    }

    /***************************************************************************
    *  Index mergesort.
    ***************************************************************************/
    // stably merge a[low .. mid] with a[mid+1 .. high] using aux[low .. high]
    private static void merge(Comparable[] a, int[] index, int[] aux, int low, int mid, int high) {
        for(int k=low; k<=high; k++)
            aux[k] = index[k];
        
        // merge back to a[]
        int i=low, j=mid+1;
        for(int k=low; k<=high; k++) {
            if(i>mid)                                       index[k] = aux[j++];
            else if(j>high)                                 index[k] = aux[i++];
            else if(SortUtil.less(a[aux[j]], a[aux[i]]))    index[k] = aux[j++];
            else                                            index[k] = aux[i++];
        }
    }

    private static void sort(Comparable[] a, Comparable[] aux, int low, int high) {
        if(low>=high) return;
        int mid = (low+high)/2;
        sort(a, aux, low, mid);
        sort(a, aux, mid+1, high);
        merge(a, aux, low, mid, high);
    }

    private static void sort(Comparable[] a, int[] index, int[] aux, int low, int high) {
        if (low >= high) return;
        int mid = (low+high)/2;
        sort(a, index, aux, low, mid);
        sort(a, index, aux, mid+1, high);
        merge(a, index, aux, low, mid, high);
    }

    public static void sort(Comparable[] a){
        Comparable[] aux = new Comparable[a.length];
        sort(a, aux, 0, a.length-1);
        assert SortUtil.isSorted(a);
    }

    // Returns a permutation that gives the elements in the array in ascending order
    public static int[] indexSort(Comparable[] a) {
        // initialize index array
        int n = a.length;
        int[] index = new int[n];
        for (int i=0; i<n; i++)
            index[i] = i;

        int[] aux = new int[n];
        sort(a, index, aux, 0, n-1);
        return index;
    }
    
    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Merge.sort(a);
        SortUtil.show(a);
    }
}
