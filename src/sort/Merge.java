public class Merge {
    private Merge(){}

    public static void merge(Comparable[] a, Comparable[] aux, int lo, int mid, int hi) {
        assert isSorted(a, lo, mid);
        assert isSorted(a, mid+1, hi);

        //copy a to aux
        for (int k=lo; k<=hi; k++) {
            aux[k] = a[k];
        }

        //merge back to a[]
        int i=lo, j=mid+1;
        for (int k=lo;k<=hi;k++) {
            if (i > mid)                    a[k] = aux[j++];
            else if(j > hi)                 a[k] = aux[i++];
            else if(less(aux[j], aux[i]))   a[k] = aux[j++];
            else                            a[k] = aux[i++];//确保小的值在左边
            /*
            for (int k=lo;k<=hi;k++) {
                if (less(aux[j], aux[i]))       a[k]=aux[j++];
                else if (less(aux[i], aux[j]))  a[k]=aux[i++];
                else if (i>mid)                 a[k]=aux[j++]
                else                            a[k]=aux[i++];
            }
            //这样子写更好理解一些，但是它们不一定是等价的
            */
        }

        assert isSorted(a);
    }

    private static boolean less(Comparable m, Comparable n) {
        return m.compareTo(n) < 0;
    }

    /*
    不要将辅助数组的创建放在递归中，这样会创建很多小数组，归并排序效率低通常是由这个引起的。
    */
    private static void sort(Comparable[] a, Comparable[] aux, int lo, int hi) {
        if (hi <= lo) return;
        int mid = lo+(hi-lo)/2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid+1, hi);
        merge(a, aux, lo, mid, hi);
    }

    public static void sort(Comparable[] a){
        Comparable[] aux = new Comparable[a.length];
        sort(a, aux, 0, a.length-1);
        assert isSorted(a);
    }

    private static boolean isSorted(Comparable[] a) {
        return isSorted(a, 0, a.length-1);
    }

    private static boolean isSorted(Comparable[] a, int lo, int hi) {
        for (int i=lo; i<hi; i++) {
            if (less(a[i+1], a[i])) return false;
        }
        return true;
    }

    // index merge sort
    private static void merge(Comparable[] a, int[] index, int[] aux, int lo, int mid, int hi) {
        //copy index of a to aux
        for (int k=lo; k<= hi; k++) {
            aux[k] = index[k];
        }

        //merge back to a
        int i=lo, j=mid+1;
        for (int k=lo; k<=hi; k++) {
            if (i > mid)                            index[k] = aux[j++];
            else if (j>hi)                          index[k] = aux[i++];
            else if (less(a[aux[j]], a[aux[i]]))    index[k] = aux[j++];
            else                                    index[k] = aux[i++];
        }
        /*
        for (int k=lo; k<=hi; k++) {
            if (less(a[aux[j]], a[aux[i]]))         index[k] = aux[j++];
            else if (less(a[aux[i]], a[aux[j]]))    index[k] = aux[i++];
            else if (i > mid)                       index[k] = aux[j++];
            else                                    index[k] = aux[i++];
        }*/
    }

    public static int[] indexMergeSort(Comparable[] a) {
        // initialize index array
        int n = a.length;
        int[] index = new int[n];
        for (int i=0; i<n; i++) {
            index[i] = i;
        }

        int[] aux = new int[n];
        sort(a, index, aux, 0, n-1);
        return index;
    }

    private static void sort(Comparable[] a, int[] index, int[] aux, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi-lo)/2;
        sort(a, index, aux, lo, mid);
        sort(a, index, aux, mid+1, hi);
        merge(a, index, aux, lo, mid, hi);
    }

    private static void show(Comparable[] a) {
        for (int i=0;i<a.length;i++) {
            System.out.print(a[i] + " ");
        }
    }
    
    public static void main(String[] args) {
        Merge m = new Merge();

        Integer[] a = {5,4,3,2,1};
        Integer[] b = {7,6,5,4,3,2,1};        
        System.out.println("origin array a is:");
        m.show(a);
        
        System.out.println("using origin merge sort function");
        m.sort(a);
        System.out.println("result of origin merge sort function:");
        m.show(a);

        System.out.println("origin array b is:");
        m.show(b);
        System.out.println("using index merge sort function");        
        int[] ret = m.indexMergeSort(b);
        System.out.println("result of index merge sort function:");
        //System.out.println(ret);
        for (int i:ret) {
            System.out.print(b[i] + " ");
        }
    }
}
