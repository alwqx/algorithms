public class MergeBU {
    private MergeBU(){}

    //merge过程中真横涉及到排序，sort是一个“分”的过程。
    private void merge(Comparable[] a, Comparable[] aux, int lo, int mid, int hi) {
        if (lo >= hi) return;
        for (int k=lo;k<=hi;k++) {
            aux[k] = a[k];
        }
        
        int i=lo, j=mid+1;
        for(int k=lo;k<=hi;k++) {
            if      (i>mid)                 a[k] = aux[j++];
            else if (j>hi)                  a[k] = aux[i++];
            else if (less(aux[j], aux[i]))  a[k] = aux[j++];
            else                            a[k] = aux[i++];
        }
    }

    private boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

    //private void sort(Comparable[] a, Comparable[] aux, int lo, int hi) {
    private void sort(Comparable[] a) {
        int n = a.length;
        Comparable[] aux = new Comparable[n];
        for (int len=1;len<n;len*=2) {//分治次数
            for (int lo=0;lo<n-len;lo+=len+len) {
                int mid = lo+len-1;
                int hi = Math.min(lo+len+len-1, n-1);
                merge(a, aux, lo, mid, hi);
            }
        }
    }

    private boolean isSorted(Comparable[] a) {
        int N = a.length;
        for (int i=1; i<N; i++){
            if (less(a[i], a[i-1])) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Integer[] a = {5,4,3,2,1};
        String[] b = {"e", "d", "c", "a", "b"};
        MergeBU mb = new MergeBU();
        mb.sort(a);
        mb.sort(b);
        for (Integer i:a) {
            System.out.print(i+" ");
        }
        for (String s:b){
            System.out.print(s+' ');
        }
    }
}