/******************************************************************************
 *  Compilation:  javac IndexMinPQ.java
 *  Execution:    java IndexMinPQ
 *  Dependencies: StdOut.java
 *
 *  Minimum-oriented indexed PQ implementation using a binary heap.
 *
 ******************************************************************************/

package queue;

import java.util.Iterator;
import java.util.NoSuchElementException;

import utils.StdOut;

public class IndexMinPQ<Key extends Comparable<Key>> implements Iterable<Integer> {
    private int maxN;
    private int size;
    private int[] pq;
    private int[] qp;
    private Key[] keys;

    public IndexMinPQ(int maxN) {
        if(maxN<0) throw new IllegalArgumentException();
        this.maxN = maxN;
        size = 0;
        keys = (Key[]) new Comparable[maxN+1];
        pq = new int[maxN+1];
        qp = new int[maxN+1];
        for(int i=0; i<=maxN; i++)
            qp[i] = -1;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean contains(int i) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        return qp[i] != -1;
    }

    public int size() {
        return size;
    }

    public void insert(int i, Key key) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");

        size++;
        qp[i] = size;
        pq[size] = i;
        keys[i] = key;
        swim(size);
    }

    public int minIndex() {
        if (size == 0) throw new NoSuchElementException("Priority queue underflow");
        return pq[1];
    }

    public Key minKey() {
        if (size == 0) throw new NoSuchElementException("Priority queue underflow");
        return keys[pq[1]];
    }

    public int delMin() {
        if (size == 0) throw new NoSuchElementException("Priority queue underflow");
        int min = pq[1];
        exch(1, size--);
        sink(1);

        assert min==pq[size+1];
        qp[min] = -1;
        keys[min] = null;
        pq[size+1] = -1;
        
        return min;
    }

    public Key keyOf(int i) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        else return keys[i];
    }

    public void changeKey(int i, Key key) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        keys[i] = key;

        swim(qp[i]);
        sink(qp[i]);
    }

    public void decreaseKey(int i, Key key) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        if(keys[i].compareTo(key)<=0)
            throw new IllegalArgumentException("Calling decreaseKey() with given argument would not strictly decrease the key");
        keys[i] = key;
        swim(qp[i]);
    }

    public void increaseKey(int i, Key key) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        if(keys[i].compareTo(key)>=0)
            throw new IllegalArgumentException("Calling increaseKey() with given argument would not strictly increase the key");
        keys[i] = key;
        sink(qp[i]);
    }

    public void delete(int i) {
        if (i < 0 || i >= maxN) throw new IllegalArgumentException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        int index = qp[i];
        exch(index, size--);
        swim(index);
        sink(index);
        keys[i] = null;
        qp[i] = -1;
    }

    private boolean greater(int i, int j) {
        return keys[pq[i]].compareTo(keys[pq[j]]) > 0;
    }

    private void exch(int i, int j) {
        int swap = pq[i];
        pq[i] = pq[j];
        pq[j] = swap;
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }

    /***************************************************************************
    * Heap helper functions.
    ***************************************************************************/
    private void swim(int k) {
        while(k>1 && greater(k/2, k)) {
            exch(k/2, k);
            k = k/2;
        }
    }

    private void sink(int k) {
        while(2*k <= size) {
            int j = 2*k;
            if(j<size && greater(j, j+1)) j++;
            if(!greater(k, j)) break;
            exch(j, k);
            k = j;
        }
    }

    public Iterator<Integer> iterator() {return new HeapIterator();}

    private class HeapIterator implements Iterator<Integer> {
        private IndexMinPQ<Key> copy;

        public HeapIterator() {
            copy = new IndexMinPQ<Key>(pq.length-1);
            for(int i=1; i<=size; i++)
                copy.insert(pq[i], keys[pq[i]]);
        }

        public boolean hasNext() {return copy.isEmpty();}

        public void remove()      { throw new UnsupportedOperationException();  }

        public Integer next() {
            if (!hasNext()) throw new NoSuchElementException();
            return copy.delMin();
        }
    }

    public static void main(String[] args) {
        String[] strings = { "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst" };

        IndexMinPQ<String> pq = new IndexMinPQ<String>(strings.length);
        for (int i = 0; i < strings.length; i++) {
            pq.insert(i, strings[i]);
        }

        // delete and print each key
        while (!pq.isEmpty()) {
            int i = pq.delMin();
            StdOut.println(i + " " + strings[i]);
        }
        StdOut.println();

        // reinsert the same strings
        for (int i = 0; i < strings.length; i++) {
            pq.insert(i, strings[i]);
        }

        // print each key using the iterator
        for (int i : pq) {
            StdOut.println(i + " " + strings[i]);
        }
        while (!pq.isEmpty()) {
            pq.delMin();
        }
    }
}