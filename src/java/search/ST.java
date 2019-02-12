/******************************************************************************
 *  Compilation:  javac ST.java
 *  Execution:    java ST < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/35applications/tinyST.txt
 *  
 *  Sorted symbol table implementation using a java.util.TreeMap.
 *  Does not allow duplicates.
 *
 ******************************************************************************/

package search;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.TreeMap;

import utils.StdIn;
import utils.StdOut;

public class ST<Key extends Comparable<Key>, Value> implements Iterable<Key> {
    private TreeMap<Key, Value> st;

    public ST() {
        st = new TreeMap<Key, Value>();
    }

    public Value get(Key key) {
        if(key == null) throw new IllegalArgumentException("calls get() with null key");
        return st.get(key);
    }

    public void put(Key key, Value value) {
        if(key == null) throw new IllegalArgumentException("calls put() with null key");
        if(value == null) st.remove(key);
        else st.put(key, value);
    }

    public void delete(Key key) {
        if(key == null) throw new IllegalArgumentException("calls delete() with null key");
        st.remove(key);
    }

    public boolean contains(Key key) {
        if(key == null) throw new IllegalArgumentException("calls contains() with null key");
        return st.containsKey(key);
    }

    public int size() {
        return st.size();
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public Key min() {
        if(isEmpty()) throw new NoSuchElementException("calls min() with empty symbal table");
        return st.firstKey();
    }

    public Key max() {
        if(isEmpty()) throw new NoSuchElementException("calls max() with empty symbal table");
        return st.lastKey();
    }

    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        Key k = st.ceilingKey(key);
        if(k == null) throw new NoSuchElementException("all keys are less than " + key);

        return k;
    }

    public Key floor(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to floor() is null");
        Key k = st.floorKey(key);
        if(k == null) throw new NoSuchElementException("all keys are more than " + key);

        return k;
    }

    public Iterable<Key> keys() {
        return st.keySet();
    }

    public Iterator<Key> iterator() {
        return st.keySet().iterator();
    }

    public static void main(String[] args) {
        ST<String, Integer> st = new ST<String, Integer>();
        for(int i=0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        for(String s:st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}