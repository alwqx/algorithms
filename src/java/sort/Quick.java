public class Quick {
    public Quick() {}

    private static void exch(Object[] a, int i, int j) {
        Object tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    private static boolean less(Comparable a, Comparable b)     {
        return a.compareTo(b) < 0;
    }

    public static void sort(Comparable[] a){
        sort(a, 0, a.length-1);
    }

    public static void sort(Comparable[] a, int lo, int hi){
        if (hi <= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }

    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo;
        int j = hi+1;
        Comparable v = a[lo];

        while(true) {
            while(less(a[++i], v))
                if (i==hi) break;
            while(less(v, a[--j]))
                if(j==lo) break;
            if (i>=j) break;
            exch(a, i, j);
        }
        exch(a, lo, j);

        return j;
    }

    public static void main(String[] args) {
        Integer[] a = {10,9,7,6,5,4,3,2,1};
        Quick.sort(a);
        for (int i=0; i<a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}