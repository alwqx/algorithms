/******************************************************************************
 *  Compilation:  javac SequentialSearchST.java
 *  Execution:    java SequentialSearchST
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/31elementary/tinyST.txt  
 *  
 *  Symbol table implementation with sequential search in an
 *  unordered linked list of key-value pairs.
 *
 *  % more tinyST.txt
 *  S E A R C H E X A M P L E
 *
 *  % java SequentialSearchST < tinyST.txt 
 *  L 11
 *  P 10
 *  M 9
 *  X 7
 *  H 5
 *  C 4
 *  R 3
 *  A 8
 *  E 12
 *  S 0
 *
 ******************************************************************************/

package search;

import java.util.NoSuchElementException;

import utils.StdIn;
import utils.StdOut;
import queue.Queue;

public class SequentialSearchST<Key, Value> {
    private int size;
    private Node first;

    private class Node {
        private Key key;
        private Value value;
        private Node next;

        public Node(Key key, Value value, Node next) {
            this.key = key;
            this.value = value;
            this.next = next;
        }
    }

    public SequentialSearchST() {}

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean contains(Key key) {
        if(key == null) throw new NoSuchElementException("calls contains() with null key");
        return get(key) != null;
    }

    public Value get(Key key) {
        if(key == null) throw new NoSuchElementException("calls get with null key");
        for(Node x=first; x!=null; x=x.next) {
            if(key.equals(x.key))
                return x.value;
        }

        return null;
    }

    public void put(Key key, Value value) {
        if(key == null) throw new IllegalArgumentException("key to put() is null");
        if(value == null) {
            delete(key);
            return;
        }

        for(Node x=first; x!=null; x=x.next) {
            if(key.equals(x.key)) {
                x.value = value;
                return;
            }
        }

        first = new Node(key, value, first);
        size++;
    }

    // linked list use head insert when call put()
    public void delete(Key key) {
        if(key == null) throw new IllegalArgumentException("key to delete() is null");
        first = delete(first, key);
    }

    // use recursion
    public Node delete(Node x, Key key) {
        if(x == null) return null;
        if(key.equals(x.key)) {
            size--;
            return x.next;
        }

        x.next = delete(x.next, key);
        return x;
    }

    public Iterable<Key> keys() {
        Queue<Key> queue = new Queue<Key>();
        for(Node x=first; x!=null; x=x.next)
            queue.enqueue(x.key);

        return queue;
    }

    public static void main(String[] args) {
        SequentialSearchST<String, Integer> st = new SequentialSearchST<String, Integer>();
        for(int i=0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        for(String s:st.keys()) {
            StdOut.println(s + " " + st.get(s));
        }
    }
}