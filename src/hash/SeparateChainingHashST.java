/******************************************************************************
 *  Compilation:  javac SeparateChainingHashST.java
 *  Execution:    java SeparateChainingHashST < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/34hash/tinyST.txt
 *
 *  A symbol table implemented with a separate-chaining hash table.
 * 
 ******************************************************************************/

package hash;

import search.SequentialSearchST;
import queue.Queue;
import utils.StdOut;
import utils.StdIn;

public class SeparateChainingHashST<Key, Value> {
    private static final int INIT_CAP = 4;
    private int m;
    private int size; // number of key-pairs
    private SequentialSearchST<Key, Value>[] st;

    public SeparateChainingHashST() {
        this(INIT_CAP);
    }

    public SeparateChainingHashST(int cap) {
        this.m = cap;
        size = 0;
        st = (SequentialSearchST<Key, Value>[]) new SequentialSearchST[cap];
        for(int i=0; i<m; i++) {
            st[i] = new SequentialSearchST<Key, Value>();
        }
    }

    private void resize(int cap) {
        SeparateChainingHashST<Key, Value> tmp = new SeparateChainingHashST<Key, Value>(cap);
        for(int i=0; i<m; i++) {
            for(Key k:st[i].keys())
                tmp.put(k, st[i].get(k));
        }

        this.m = tmp.m;
        this.size = tmp.size;
        this.st = tmp.st;
    }

    private int hash(Key key) {
        return (key.hashCode() & 0x7fffffff) % m;
    }

    public int size() {
        return size;
    } 

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean contains(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to contains() is null");
        return get(key) != null;
    }

    public Value get(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to get() is null");
        int i = hash(key);
        return st[i].get(key);
    }

    public void put(Key key, Value value) {
        if (key == null) throw new IllegalArgumentException("first argument to put() is null");
        if (value == null) {
            delete(key);
            return;
        }

        if(size>=10*m) resize(2*m);
        int i = hash(key);
        if(!st[i].contains(key)) size++;
        st[i].put(key, value);
    }

    public void delete(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to delete() is null");
        int i = hash(key);
        if(st[i].contains(key)) size--;
        st[i].delete(key);

        // halve table size if average length of list <= 2
        if (m > INIT_CAP && size <= 2*m) resize(m/2);
    }

    public Iterable<Key> keys() {
        Queue<Key> queue = new Queue<Key>();
        for(int i=0; i<m; i++) {
            for(Key key:st[i].keys())
                queue.enqueue(key);
        }

        return queue;
    }

    public static void main(String[] args) { 
        SeparateChainingHashST<String, Integer> st = new SeparateChainingHashST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        // print keys
        for (String s : st.keys()) 
            StdOut.println(s + " " + st.get(s)); 
    }
}