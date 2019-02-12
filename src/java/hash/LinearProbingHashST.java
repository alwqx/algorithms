
/******************************************************************************
 *  Compilation:  javac LinearProbingHashST.java
 *  Execution:    java LinearProbingHashST < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/34hash/tinyST.txt
 *  
 *  Symbol-table implementation with linear-probing hash table.
 *
 ******************************************************************************/

package hash;

import queue.Queue;
import utils.StdIn;
import utils.StdOut;

public class LinearProbingHashST<Key, Value> {
    private static final int INIT_CAP = 4;

    private int size;
    private int m;
    private Key[] keys;
    private Value[] values;

    public LinearProbingHashST() {
        this(INIT_CAP);
    }

    public LinearProbingHashST(int cap) {
        size = 0;
        m = cap;
        keys = (Key[]) new Object[cap];
        values = (Value[]) new Object[cap];
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size() != 0;
    }

    private void resize(int cap) {
        assert cap > m;
        LinearProbingHashST<Key, Value> tmp = new LinearProbingHashST<Key, Value>(cap);
        for(int i=0; i<m; i++) {
            if(keys[i] != null) {
                tmp.put(keys[i], values[i]);
            }
        }

        keys = tmp.keys;
        values = tmp.values;
        m = tmp.m;
    }

    private int hash(Key key) {
        return (key.hashCode() & 0x7fffffff)%m;
    }

    public boolean contains(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to contains() is null");
        return get(key) != null;
    }

    public void put(Key key, Value value) {
        if (key == null) throw new IllegalArgumentException("first argument to put() is null");
        if(value == null) {
            delete(key);
            return;
        }

        // double table size
        if(size >= m/2) resize(m*2);

        int i;
        for(i=hash(key); keys[i]!=null; i=(i+1)%m) {
            if(keys[i].equals(key)) {
                values[i] = value;
                return;
            }
        }

        keys[i] = key;
        values[i] = value;
        size++;
    }

    public Value get(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to put() is null");
        int i;
        for(i=hash(key); keys[i]!=null; i=(i+1)%m) {
            if(keys[i].equals(key)) {
                return values[i];
            }
        }

        return null;
    }

    public void delete(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to delete() is null");
        if(!contains(key)) return;

        int i = hash(key);
        while(!key.equals(keys[i]))
            i = (i+1)%m;
        keys[i] = null;
        values[i] = null;

        // rehash key-value right of i
        i = (i+1)%m;
        while(keys[i] != null) {
            Key tkey = keys[i];
            Value tvalue = values[i];
            keys[i] = null;
            values[i] = null;
            size--;
            put(tkey, tvalue);
            i = (i+1)%m;
        }

        size--;
        if(size>0 && size<=m/8) resize(m/2);

        assert check();
    }

    public Iterable<Key> keys() {
        Queue<Key> queue = new Queue<Key>();
        for(int i=0; i<m; i++)
            if(keys[i] != null)
                queue.enqueue(keys[i]);
        
        return queue;
    }

    private boolean check() {
        if(m<(2*size)) {
            System.err.println("Hash table size m=" + m + "; array size=" + size);
            return false;
        }

        for(int i=0; i<m; i++) {
            if(keys[i] == null) continue;
            else if(get(keys[i]) != values[i]) {
                System.err.println("get[" + keys[i] + "] = " + get(keys[i]) + "; vals[i] = " + values[i]);
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        LinearProbingHashST<String, Integer> st = new LinearProbingHashST<String, Integer>();
        for(int i=0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        for(String s:st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}