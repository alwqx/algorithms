import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MaxPQ<Key> implements Iterable<Key> {
    private Key[] pq;
    private int n;
    private Comparator<Key> comparator;

    public MaxPQ(int capacity) {
        pq = (Key[]) new Object[capacity + 1];
        n = 0;
    }

    public MaxPQ() {
        this(1);
    }

    public MaxPQ(int capacity, Comparator<Key> comparator) {
        this.comparator = comparator;
        pq = (Key[]) new Object[capacity + 1];
        n = 0;
    }

    public MaxPQ(Comparator<Key> comparator) {
        this(1, comparator);
    }

    public MaxPQ(Key[] keys) {
        n = keys.length;
        pq = (Key[]) new Object[n + 1];
        for(int i=0;i<n;i++){
            pq[i+1] = keys[i];
        }
        //sort
        for (int k=n/2;k>=1;k--) {
            sink(k);
        }

        assert isMaxHeap();
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    public Key max() {
        if(isEmpty()) throw new NoSuchElementException("Priority queue underflow");
        return pq[1];
    }

    private void resize(int capacity) {
        assert capacity > 0;
        Key[] tmp = (Key[]) new Object[capacity];
        for (int i=1;i<=n;i++){
            tmp[i] = pq[i];
        }
        pq = tmp;
    }

    public void insert(Key x) {
        if(n>=pq.length-1) resize(2*pq.length);
        pq[++n] = x;
        swim(n);
        assert isMaxHeap();
    }

    public Key delMax() {
        if (isEmpty()) throw new NoSuchElementException("Priority queue underflow");
        Key max = pq[1];
        exch(1,n--);
        sink(1);
        pq[n+1] = null;
        //resize!!!
        //n对应的是pq.length-1，所以永远是n和pq.length比较
        if ((n>0)&&(n==(pq.length-1)/4)) resize(pq.length/2);
        assert isMaxHeap();
        return max;
    }

    //算法里面的代码要和实际情况紧密结合，而不是凭空想出来的。
    private void swim(int k) {
        while(k>1 && less(k/2,k)) {//less()结合
            exch(k, k/2);
            k /= 2;
        }
    }

    private void sink(int k) {
        while(2*k<=n) {
            int j = 2*k;//左孩子
            if(j<n&&less(j, j+1)) j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    //helper 
    private boolean less(int i, int j) {
        if (comparator == null) {
            return ((Comparable<Key>) pq[i]).compareTo(pq[j]) < 0;
            // return ((Comparator<Key>) pq[i].compareTo(pq[j])) < 0;
        }else{
            return comparator.compare(pq[i], pq[j]) < 0;
        }
    }

    private void exch(int i, int j) {
        Key swap = pq[i];
        pq[i] = pq[j];
        pq[j] = swap;
    }

    private boolean isMaxHeap() {
        return isMaxHeap(1);
    }

    private boolean isMaxHeap(int k) {
        if(k>n) return true;
        int left = 2*k;
        int right = 2*k+1;
        if(left<=n&&less(k, left)) return false;
        if(right<=n&&less(k, right)) return false;
        return isMaxHeap(left) && isMaxHeap(right);
    }

    public Iterator<Key> iterator() {
        return new HeapIterator();
    }

    private class HeapIterator implements Iterator<Key> {
        private MaxPQ<Key> copy;

        public HeapIterator() {
            if(comparator == null)  copy = new MaxPQ(size());
            else                    copy = new MaxPQ(size(), comparator);
            for (int i=1;i<=n;i++) {
                copy.insert(pq[i]);
            }
        }

        public boolean hasNext() {
            return !isEmpty();
        }

        public void remove(){throw new NoSuchElementException();}

        public Key next() {
            if (!hasNext()) throw new NoSuchElementException();
            return copy.delMax();
        }
    }

    public static void main(String[] args) {
        MaxPQ<String> pq = new MaxPQ<String>();
        String[] s = {"S", "B", "A", "X"};
        pq.insert("S");
        pq.insert("B");
        pq.insert("A");
        pq.insert("X");
        System.out.println(pq.delMax());
        System.out.println(pq.delMax());
        System.out.println(pq.delMax());
    }
}