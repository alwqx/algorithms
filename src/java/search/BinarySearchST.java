/******************************************************************************
 *  Compilation:  javac BinarySearchST.java
 *  Execution:    java BinarySearchST
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/31elementary/tinyST.txt  
 *  
 *  Symbol table implementation with binary search in an ordered array.
 *
 *  % more tinyST.txt
 *  S E A R C H E X A M P L E
 *  
 *  % java BinarySearchST < tinyST.txt
 *  A 8
 *  C 4
 *  E 12
 *  H 5
 *  L 11
 *  M 9
 *  P 10
 *  R 3
 *  S 0
 *  X 7
 *
 ******************************************************************************/

package search;

import java.util.NoSuchElementException;

import queue.Queue;
import utils.StdIn;
import utils.StdOut;

public class BinarySearchST<Key extends Comparable<Key>, Value> {
    private static final int INT_CAP = 2;
    private int size = 0;
    private Key[] keys;
    private Value[] vals;

    public BinarySearchST() {
        this(INT_CAP);
    }

    public BinarySearchST(int cap) {
        keys = (Key[]) new Comparable[cap];
        vals = (Value[]) new Object[cap];
    }

    private void resize(int cap) {
        assert cap>=size;

        Key[] tempk = (Key[]) new Comparable[cap];
        Value[] tempv = (Value[]) new Object[cap];
        for(int i=0; i<size; i++) {
            tempk[i] = keys[i];
            tempv[i] = vals[i];
        }
        
        keys = tempk;
        vals = tempv;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public Value get(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to get() is null");
        if(isEmpty()) return null;

        int i = rank(key);
        if(i<size && key.compareTo(keys[i]) == 0) return vals[i];
        return null;
    }

    public int rank(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to rank() is null");
        int low=0, high=size-1;
        while(low<=high) {
            int mid = (low+high)/2;
            int i = key.compareTo(keys[mid]);
            if(i<0) high = mid-1;
            else if(i>0) low=mid+1;
            else return mid;
        }

        return low;
    }

    public boolean contains(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to contains() is null");
        return get(key) != null;
    }

    public void delete(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to delete() is null");
        if(isEmpty()) return;

        int i = rank(key);
        // key not in table
        if(i==size || key.compareTo(keys[i]) != 0) return;

        for(int j=i; j<size-1; j++) {
            keys[j] = keys[j+1];
            vals[j] = vals[j+1];
        }
        size--;
        keys[size] = null;
        vals[size] = null;

        // resize
        if(size>0 && size==keys.length/4) resize(keys.length/2);
        assert check();
    }

    private boolean isSorted() {
        for(int i=1; i<size; i++)
            if(keys[i].compareTo(keys[i-1]) < 0)
                return false;
        
        return true;
    }

    private boolean isRanked() {
        for(int i=0; i<size; i++)
            if(i!=rank(select(i))) return false;
        for(int i=0; i<size; i++)
            if(keys[i].compareTo(select(rank(keys[i]))) != 0) return false;
        
        return true;
    }

    private boolean check() {
        return isSorted() && isRanked();
    }

    public void put(Key key, Value val) {
        if(key == null) throw new IllegalArgumentException("first argument to put() is null");
        if(val == null) {
            delete(key);
            return;
        }

        int i = rank(key);
        if(i<size && key.compareTo(keys[i]) == 0) {
            vals[i] = val;
            return;
        }

        // insert
        if(size == keys.length) resize(2*size);
        for(int j=size; j>i; j--) {
            keys[j] = keys[j-1];
            vals[j] = vals[j-1];
        }
        keys[i] = key;
        vals[i] = val;
        size++;

        assert check();
    }

    public Key min() {
        if(isEmpty()) throw new NoSuchElementException("call min() with empty symbal table");
        return keys[0];
    }

    public Key max() {
        if(isEmpty()) throw new NoSuchElementException("call max() with empty symbal table");
        return keys[size-1];
    }

    public void deleteMin() {
        if(isEmpty()) throw new NoSuchElementException("symbal table underflow error");
        delete(min());
    }

    public void deleteMax() {
        if(isEmpty()) throw new NoSuchElementException("symbal table underflow error");
        delete(max());
    }

    // Return the kth smallest key in this symbol table.
    public Key select(int k) {
        // if(isEmpty()) throw new NoSuchElementException("symbal table is empty");
        // st is empty, i=rank(key), i=0;
        if(k<0 || k>=size()) throw new IllegalArgumentException("call select with invalid argument: " + k);
        return keys[k];
    }

    // Returns the largest key in this symbol table less than or equal to key
    public Key floor(Key key) {
        if(isEmpty()) throw new NoSuchElementException("symbal table is empty");
        if(key == null) throw new IllegalArgumentException("argument to floor is empty");

        int i = rank(key);
        if(i<size && key.compareTo(keys[i]) == 0) return keys[i];
        else if(i==0) return null;
        else return keys[i-1];
    }

    // Returns the smallest key in this symbol table greater than or equal to key
    public Key ceiling(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to ciling() is null");
        int i = rank(key);
        if(i==size) return null;
        else return keys[i];
    }

    // Returns the number of keys in this symbol table in the specified range
    public int size(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to size() is null"); 
        if (high == null) throw new IllegalArgumentException("second argument to size() is null"); 
        
        if(low.compareTo(high) > 0) return 0;
        if(contains(high)) return rank(high)-rank(low)+1;
        else return rank(high)-rank(low);
    }

    public Iterable<Key> keys() {
        return keys(min(), max());
    }

    public Iterable<Key> keys(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to keys() is null");
        if (high == null) throw new IllegalArgumentException("second argument to keys() is null");

        Queue<Key> queue = new Queue<Key>();
        if(low.compareTo(high) > 0) return queue;
        for(int i=rank(low); i<rank(high); i++)
            queue.enqueue(keys[i]);
        if(contains(high))
            queue.enqueue(keys[rank(high)]);

        return queue;
    }

    public static void main(String[] args) {
        BinarySearchST<String, Integer> st = new BinarySearchST<String, Integer>();
        for(int i=0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        for(String s:st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}