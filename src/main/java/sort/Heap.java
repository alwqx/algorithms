public class Heap {
    private Heap() {}

    public static void sort(Comparable[] pq) {
        int n = pq.length;
        for (int i=n/2;i>=1;i--) {
            sink(pq, i, n);
        }
        while(n>1) {
            exch(pq, 1, n--);
            sink(pq, 1, n);
        }
    }

    /*
    private static void sink(Comparable[] pq, int k, int n) {
        while(2*k<=n){
            int j = 2*k;
            if(j<n && less(j,j+1)) j++;
            if(!less(k, j)) break;//forget pq
            exch(pq, k, j);
            k=j;
        }
    }*/
    private static void sink(Comparable[] pq, int k, int n) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && less(pq, j, j+1)) j++;
            if (!less(pq, k, j)) break;
            exch(pq, k, j);
            k = j;
        }
    }

    private static boolean less(Comparable[] pq, int i, int j) {
        return pq[i-1].compareTo(pq[j-1]) < 0;//因为pq的特殊性？调用less的函数传的是什么
    }

    private static void exch(Object[] pq, int i, int j) {
        Object swap = pq[i-1];
        pq[i-1] = pq[j-1];
        pq[j-1] = swap;
    }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    private static boolean isSorted(Comparable[] a) {
        for(int i=1;i<a.length;i++){
            if(less(a[i], a[i-1])){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String[] a = {"S", "B", "C", "X", "A"};
        Heap.sort(a);
        for (String i:a){
            System.out.print(i+" ");
        }
        assert isSorted(a);
    }
}

/*
堆排序是把输入的数组当成堆看待，这个堆是用数组下标之间的关系逻辑上的完全二叉树。
堆排序体现在sink()方法，这个方法依赖于完全二叉堆的性质实现的，在理解sink()方法时
最好自己画一个堆辅助理解。
*/