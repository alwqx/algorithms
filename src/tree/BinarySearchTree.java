/******************************************************************************
 *  Compilation:  javac BinarySearchST.java
 *  Execution:    java BinarySearchST
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/31elementary/tinyST.txt  
 *  
 *  BinarySearch tree implementation with binary search in an ordered array.
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

package tree;

import utils.StdIn;
import utils.StdOut;
import queue.Queue;

import java.util.NoSuchElementException;

public class BinarySearchTree<Key extends Comparable<Key>, Value> {
    private static final int INIT_CAP = 2;
    private Key[] keys;
    private Value[] values;
    private int size;

    public BinarySearchTree() {
        this(INIT_CAP);
    }

    public BinarySearchTree(int cap) {
        keys = (Key[]) new Comparable[cap];
        values = (Value[]) new Object[cap];
    }

    // resize the underlying arrays
    private void resize(int capacity) {
        assert capacity >= size;
        Key[]   tempk = (Key[])   new Comparable[capacity];
        Value[] tempv = (Value[]) new Object[capacity];
        for (int i = 0; i < size; i++) {
            tempk[i] = keys[i];
            tempv[i] = values[i];
        }
        values = tempv;
        keys = tempk;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean contains(Key key) {
        if(key == null) throw new IllegalArgumentException("key to contains() is null");

        return get(key) != null;
    }

    public Value get(Key key) {
        if(key == null) throw new IllegalArgumentException("key to contains() is null");
        if(isEmpty()) return null;

        int i = rank(key);
        if(i<size && key.compareTo(keys[i])==0) return values[i];
        return null;
    }

    // Returns the number of keys in this BinarySearch tree strictly less than key
    public int rank(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to rank() is null");

        int low=0, high=size-1;
        while(low<=high) {
            int mid = (low+high)/2;
            int cmp = key.compareTo(keys[mid]);
            if(cmp<0)       high=mid-1;
            else if(cmp>0)  low=mid+1;
            else            return mid;
        }

        return low;
    }

    public void put(Key key, Value value) {
        if (key == null) throw new IllegalArgumentException("first argument to put() is null"); 

        if (value == null) {
            delete(key);
            return;
        }

        int i = rank(key);
        if(i<size && key.compareTo(keys[i]) == 0) {
            values[i] = value;
            return;
        }

        // insert new key-value pair
        if (size == keys.length) resize(2*keys.length);
        for(int j=size; j>i; j--) {
            keys[j] = keys[j-1];
            values[j] = values[j-1];
        }
        keys[i] = key;
        values[i] = value;
        size++;

        assert check();
    }

    public void delete(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to delete() is null"); 
        if (isEmpty()) return;

        // compute rank
        int i = rank(key);

        // key not in tree
        if(i==size && key.compareTo(keys[i])!=0) return;
        for(int j=i; j<size-1; j++) {
            keys[j] = keys[j+1];
            values[j] = values[j+1];
        }
        size--;
        keys[size] = null;
        values[size] = null;

        // resize
        if(size>0 && size==keys.length/4) resize(keys.length/2);
        assert check();
    }

    public void deleteMin() {
        if(isEmpty()) throw new NoSuchElementException("tree is empty");

        delete(min());
    }

    public void deleteMax() {
        if(isEmpty()) throw new NoSuchElementException("tree is empty");

        delete(max());
    }

    public Key min() {
        if (isEmpty()) throw new NoSuchElementException("called min() with empty BinarySearch tree");
        return keys[0]; 
    }

    public Key max() {
        if (isEmpty()) throw new NoSuchElementException("called max() with empty BinarySearch tree");
        return keys[size-1];
    }

    public Key select(int k) {
        if (k < 0 || k >= size()) {
            throw new IllegalArgumentException("called select() with invalid argument: " + k);
        }
        return keys[k];
    }

    // Returns the largest key in this BinarySearch tree less than or equal to key
    public Key floor(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to floor() is null");

        int i = rank(key);
        int cmp = key.compareTo(keys[i]);
        if(i<size && cmp==0)    return keys[i];
        if(i == 0)              return null;
        else                    return keys[i-1];
    }

    // Returns the smallest key in this BinarySearch tree greater than or equal to key
    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        
        int i = rank(key);
        if(i == size)   return null;
        else            return keys[i];
    }

    public int size(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to size() is null");
        if (high == null) throw new IllegalArgumentException("second argument to size() is null");

        if(low.compareTo(high) > 0) return 0;
        if(contains(high))          return rank(high)-rank(low)+1;
        else                        return rank(high)-rank(low);
    }

    public Iterable<Key> keys() {
        return keys(min(), max());
    }

    // Returns all keys in this BinarySearch tree in the given range,
    // as an Iterable
    public Iterable<Key> keys(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to keys() is null");
        if (high == null) throw new IllegalArgumentException("second argument to keys() is null");

        Queue<Key> queue = new Queue<Key>();
        if(low.compareTo(high) > 0) return queue;
        for(int i=rank(low); i<rank(high); i++)
            queue.enqueue(keys[i]);
        if(contains(high))  queue.enqueue(keys[rank(high)]);

        return queue;
    }

    private boolean check() {
        return isSorted() && rankCheck();
    }

    private boolean isSorted() {
        for (int i = 1; i < size(); i++)
            if (keys[i].compareTo(keys[i-1]) < 0) return false;
        return true;
    }

    // check that rank(select(i)) = i
    private boolean rankCheck() {
        for (int i = 0; i < size(); i++)
            if (i != rank(select(i))) return false;
        for (int i = 0; i < size(); i++)
            if (keys[i].compareTo(select(rank(keys[i]))) != 0) return false;
        return true;
    }

    public static void main(String[] args) { 
        BinarySearchTree<String, Integer> st = new BinarySearchTree<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}