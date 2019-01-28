/******************************************************************************
 *  Compilation:  javac MinPQ.java
 *  Execution:    java MinPQ < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/24pq/tinyPQ.txt
 *  
 *  Generic min priority queue implementation with a binary heap.
 *  Can be used with a comparator instead of the natural order.
 *
 *  % java MinPQ < tinyPQ.txt
 *  E A E (6 left on pq)
 *
 *  We use a one-based array to simplify parent and child calculations.
 *
 *  Can be optimized by replacing full exchanges with half exchanges
 *  (ala insertion sort).
 *
 ******************************************************************************/

package queue;

import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

import utils.StdIn;
import utils.StdOut;

public class MinPQ<Key> implements Iterable<Key> {
    private Key[] pq;
    private int size;
    private Comparator<Key> comparator;

    public MinPQ(int cap) {
        size = 0;
        pq = (Key[]) new Object[cap + 1];
    }

    public MinPQ() {
        this(1);
    }

    public MinPQ(int cap, Comparator<Key> comparator) {
        this.comparator = comparator;
        pq = (Key[]) new Object[cap + 1];
        size = 0;
    }

    public MinPQ(Comparator<Key> comparator) {
        this(1, comparator);
    }

    public MinPQ(Key[] keys) {
        size = keys.length;
        pq = (Key[]) new Object[keys.length + 1];

        for(int i=0; i<size; i++)
            pq[i+1] = keys[i];
        for(int k=size/2; k>=1; k--)
            sink(k);

        assert isMinHeap();
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public Key min() {
        if(isEmpty()) throw new NoSuchElementException("Priority queue underflow");
        return pq[1];
    }

    private void resize(int cap) {
        assert cap > size;
        Key[] tmp = (Key[]) new Object[cap];

        for(int i=1; i<=size; i++)
            tmp[i] = pq[i];
        
        pq = tmp;
    }

    public void insert(Key key) {
        if(size == pq.length - 1) resize(2*pq.length);

        pq[++size] = key;
        swim(size);

        assert isMinHeap();
    }

    public Key delMin() {
        if (isEmpty()) throw new NoSuchElementException("Priority queue underflow");
        Key min = pq[1];

        exch(1, size--);
        sink(1);
        pq[size+1] = null;

        if((size>0) && (size == (pq.length-1)/4)) resize(pq.length/2);
        assert isMinHeap();
        return min;
    }

    private void swim(int k) {
        while(k>1 && greater(k/2, k)) {
            exch(k, k/2);
            k=k/2;
        }
    }

    private void sink(int k) {
        while(2*k <= size) {
            int j = 2*k;
            if(j<size && greater(j, j+1)) j++;
            if(!greater(k, j)) break;
            exch(k, j);
            k=j;
        }
    }

    private boolean greater(int i, int j) {
        if(comparator == null) {
            return ((Comparable<Key>) pq[i]).compareTo(pq[j]) > 0;
        }else{
            return comparator.compare(pq[i], pq[j]) > 0;
        }
    }

    private void exch(int i, int j) {
        Key tmp = pq[i];
        pq[i] = pq[j];
        pq[j] = tmp;
    }

    // is pq[1..N] a min heap?
    private boolean isMinHeap() {
        return isMinHeap(1);
    }

    // is subtree of pq[1..n] rooted at k a min heap?
    private boolean isMinHeap(int k) {
        if(k > size) return true;
        int left = 2*k;
        int right = 2*k + 1;
        
        if(left<=size && greater(k, left)) return false;
        if(right<=size && greater(k, right)) return false;
        return isMinHeap(left) && isMinHeap(right);
    }

    public Iterator<Key> iterator() {
        return new HeapIterator();
    }

    public class HeapIterator implements Iterator<Key> {
        private MinPQ<Key> copy;

        public HeapIterator() {
            if(comparator == null) copy = new MinPQ<Key>(size());
            else copy = new MinPQ<>(size(), comparator);
            for(int i=1; i<=size; i++)
                copy.insert(pq[i]);
        }

        public boolean hasNext() {return !copy.isEmpty();}
        public void remove()      { throw new UnsupportedOperationException();  }

        public Key next() {
            if (!hasNext()) throw new NoSuchElementException();
            return copy.delMin();
        }
    }

    public static void main(String[] args) {
        MinPQ<String> pq = new MinPQ<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-")) pq.insert(item);
            else if (!pq.isEmpty()) StdOut.print(pq.delMin() + " ");
        }
        StdOut.println("(" + pq.size() + " left on pq)");
    }
}