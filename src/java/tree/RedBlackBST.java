/******************************************************************************
 *  Compilation:  javac RedBlackBST.java
 *  Execution:    java RedBlackBST < input.txt
 *  Dependencies: StdIn.java StdOut.java  
 *  Data files:   https://algs4.cs.princeton.edu/33balanced/tinyST.txt  
 *    
 *  A symbol table implemented using a left-leaning red-black BST.
 *  This is the 2-3 version.
 *
 *  Note: commented out assertions because DrJava now enables assertions
 *        by default.
 *
 *  % more tinyST.txt
 *  S E A R C H E X A M P L E
 *  
 *  % java RedBlackBST < tinyST.txt
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

import java.util.NoSuchElementException;

import utils.StdIn;
import utils.StdOut;
import queue.Queue;

public class RedBlackBST<Key extends Comparable<Key>, Value> {
    private static final boolean RED = true;
    private static final boolean BLACK = false;

    private Node root; // root of bst

    private class Node {
        private Key key;
        private Value value;
        private Node left, right;
        private boolean color;
        private int size;

        public Node(Key key, Value value, boolean color, int size) {
            this.key = key;
            this.value = value;
            this.color = color;
            this.size = size;
        }
    }

    public RedBlackBST() {}

    private boolean isRed(Node x) {
        if(x == null) return false;
        return x.color == RED;
    }

    private int size(Node x) {
        if(x == null) return 0;
        return x.size;
    }

    public int size() {
        return size(root);
    }

    public boolean isEmpty() {
        return root == null;
    }

    public Value get(Key key) {
        if(key == null) throw new IllegalArgumentException("key of get() is null");
        return get(root, key);
    }

    private Value get(Node x, Key key) {
        while(x != null) {
            int cmp = key.compareTo(x.key);
            if(cmp < 0) return get(x.left, key);
            else if(cmp > 0) return get(x.right, key);
            else return x.value;
        }

        return null;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    /***************************************************************************
    *  Red-black tree insertion.
    ***************************************************************************/
    public void put(Key key, Value value) {
        if(key == null) throw new IllegalArgumentException("key to put() is null");
        if(value == null) {
            delete(key);
            return;
        }

        root = put(root, key, value);
        root.color = BLACK;
        // assert check();
    }

    private Node put(Node h, Key key, Value value) {
        if(h == null) return new Node(key, value, RED, 1);

        int cmp = key.compareTo(h.key);
        if(cmp < 0) h.left = put(h.left, key, value);
        else if(cmp > 0) h.right = put(h.right, key, value);
        else h.value = value;

        // fix right-leaning links
        if(isRed(h.right) && !isRed(h.left)) h = rotateLeft(h);
        if(isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
        if(isRed(h.left) && isRed(h.right)) flipColors(h);

        h.size = 1 + size(h.left) + size(h.right);

        return h;
    }

    public void deleteMin() {
        if(isEmpty()) throw new NoSuchElementException("RedBlack tree underflow");

        if(!isRed(root.left) && !isRed(root.right))
            root.color = RED;
        
        root = deleteMin(root);
        if(!isEmpty()) root.color = BLACK;
    }

    private Node deleteMin(Node h) {
        if(h.left == null) return null;

        if(!isRed(h.left) && !isRed(h.right))
            h = moveRedLeft(h);
        
        h.left = deleteMin(h.left);
        return balance(h);
    }

    public void deleteMax() {
        if(isEmpty()) throw new NoSuchElementException("RedBlack tree underflow");

        if(!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = deleteMax(root);
        if(!isEmpty()) root.color = BLACK;
    }

    private Node deleteMax(Node h) {
        if(isRed(h.left)) h = rotateRight(h);

        if(h.right == null) return null;

        if(!isRed(h.left) && !isRed(h.right))
            h = moveRedRight(h);
        
        h.right = deleteMax(h.right);
        return balance(h);
    }

    public void delete(Key key) {
        if(key == null) throw new IllegalArgumentException("key to delete() is null");
        if(!contains(key)) return;

        if(!isRed(root.left) && !isRed(root.right))
            root.color = RED;
        
        root = delete(root, key);
        if(!isEmpty()) root.color = BLACK;
    }

    private Node delete(Node h, Key key) {
        if(key.compareTo(h.key) < 0) {
            if(!isRed(h.left) && !isRed(h.right))
                h = moveRedLeft(h);
            h.left = delete(h.left, key);
        } else {
            if(isRed(h.left)) h = rotateRight(h);
            if(key.compareTo(h.key)==0 && h.right==null) return null;
            if(!isRed(h.right) && !isRed(h.right.left)) h = moveRedRight(h);
            if(key.compareTo(h.key) == 0) {
                Node x = min(h.right);
                h.key = x.key;
                h.value = x.value;
                h.right = deleteMin(h.right);
            } else {
                h.right = delete(h.right, key);
            }
        }

        return balance(h);
    }

    // make a left-leaning link lean to the right
    private Node rotateRight(Node h) {
        // assert (h != null) && isRed(h.left);
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = x.right.color;
        x.right.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    // make a right-leaning link lean to the left
    private Node rotateLeft(Node h) {
        // assert (h != null) && isRed(h.right);
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = x.left.color;
        x.left.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    // flip the colors of a node and its two children
    private void flipColors(Node h) {
        // h must have opposite color of its two children
        // assert (h != null) && (h.left != null) && (h.right != null);
        // assert (!isRed(h) &&  isRed(h.left) &&  isRed(h.right))
        //    || (isRed(h)  && !isRed(h.left) && !isRed(h.right));
        h.color = !h.color;
        h.left.color = !h.left.color;
        h.right.color = !h.right.color;
    }

    // Assuming that h is red and both h.left and h.left.left
    // are black, make h.left or one of its children red.
    private Node moveRedLeft(Node h) {
        flipColors(h);
        if(isRed(h.right.left)) {
            h.right = rotateRight(h.right);
            h = rotateLeft(h);
            flipColors(h);
        }

        return h;
    }

    // Assuming that h is red and both h.right and h.right.left
    // are black, make h.right or one of its children red.
    private Node moveRedRight(Node h) {
        flipColors(h);
        if(isRed(h.left.left)) {
            h = rotateRight(h);
            flipColors(h);
        }

        return h;
    }

    // restore red-black tree invariant
    private Node balance(Node h) {
        if(isRed(h.right))                          h = rotateLeft(h);
        if(isRed(h.left) && isRed(h.left.left))     h = rotateRight(h);
        if(isRed(h.left) && isRed(h.right))         flipColors(h);

        h.size = 1 + size(h.left) + size(h.right);
        return h;
    }

    public int height() {
        return height(root);
    }

    private int height(Node x) {
        if(x == null) return -1;
        return 1 + Math.max(height(x.left), height(x.right));
    }

    /***************************************************************************
    *  Ordered symbol table methods.
    ***************************************************************************/
    public Key min() {
        if (isEmpty()) throw new NoSuchElementException("calls min() with empty RedBlack tree");
        return min(root).key;
    }

    private Node min(Node x) {
        if(x.left == null) return x;
        else               return min(x.left);
    }

    public Key max() {
        if (isEmpty()) throw new NoSuchElementException("calls max() with empty RedBlack tree");
        return max(root).key;
    }

    private Node max(Node x) {
        if(x.right == null) return x;
        else                return max(x.right);
    }

    // Returns the largest key in the symbol table less than or equal to key
    public Key floor(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to floor() is null");
        if(isEmpty())   throw new NoSuchElementException("calls floor with empty RedBlack tree");

        Node x = floor(root, key);
        if(x == null) return null;
        else return x.key;
    }

    // the largest key in the subtree rooted at x less than or equal to the given key
    private Node floor(Node x, Key key) {
        if(x == null)   return null;
        int cmp = key.compareTo(x.key);
        if(cmp == 0)    return x;
        if(cmp < 0)     return floor(x.left, key);

        Node t = floor(x.right, key);
        if(t != null)   return t;
        else            return x;
    }

    // Returns the smallest key in the symbol table greater than or equal to key
    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        if (isEmpty()) throw new NoSuchElementException("calls ceiling() with empty RedBlack tree");

        Node x = ceiling(root, key);
        if(x == null)   return null;
        else            return x.key;
    }

    private Node ceiling(Node x, Key key) {
        if(x == null)   return null;

        int cmp = key.compareTo(x.key);
        if(cmp == 0)    return x;
        if(cmp > 0)     return ceiling(x.right, key);

        Node t = ceiling(x.left, key);
        if(t != null)   return t;
        else            return x;
    }

    // Return the key in the symbol table whose rank is k
    // This is the (k+1)st smallest key in the symbol table
    public Key select(int k) {
        if(k<0 || k>=size())
            throw new IllegalArgumentException("argument to select() is invalid: " + k);
        
        return select(root, k).key;
    }

    private Node select(Node x, int k) {
        int t = size(x.left);
        if(t>k)         return select(x.left, k);
        else if(t<k)    return select(x.right, k-t-1);
        else            return x;
    }

    // Return the number of keys in the symbol table strictly less than key
    public int rank(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to rank() is null");
        return rank(key, root);
    }

    // number of keys less than key in the subtree rooted at x
    private int rank(Key key, Node x) {
        int cmp = key.compareTo(x.key);
        if(cmp < 0)        return rank(key, x.left);
        else if(cmp > 0)   return 1 + size(x.left) + rank(key, x.right);
        else               return size(x.left);
    }

    // Returns all keys in the symbol table as an Iterable.
    // To iterate over all of the keys in the symbol table named st
    public Iterable<Key> keys() {
        if (isEmpty()) return new Queue<Key>();
        return keys(min(), max());
    }

    private Iterable<Key> keys(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to keys() is null");
        if (high == null) throw new IllegalArgumentException("second argument to keys() is null");

        Queue<Key> queue = new Queue<Key>();
        keys(root, queue, low, high);

        return queue;
    }

    private void keys(Node x, Queue<Key> queue, Key low, Key high) {
        if(x == null) return;
        int cmplow = low.compareTo(x.key);
        int cmphigh = high.compareTo(x.key);

        if(cmplow < 0)              keys(x.left, queue, low, high);
        if(cmplow<=0 && cmphigh>=0) queue.enqueue(x.key);
        if(cmphigh > 0)             keys(x.right, queue, low, high);
    }

    // Returns the number of keys in the symbol table in the given range
    public int size(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to size() is null");
        if (high == null) throw new IllegalArgumentException("second argument to size() is null");

        if (low.compareTo(high) > 0) return 0;
        if (contains(high)) return rank(high) - rank(low) + 1;
        else              return rank(high) - rank(low);
    }

    /***************************************************************************
    *  Check integrity of red-black tree data structure.
    ***************************************************************************/
    private boolean check() {
        if (!isBST())            StdOut.println("Not in symmetric order");
        if (!isSizeConsistent()) StdOut.println("Subtree counts not consistent");
        if (!isRankConsistent()) StdOut.println("Ranks not consistent");
        if (!is23())             StdOut.println("Not a 2-3 tree");
        if (!isBalanced())       StdOut.println("Not balanced");
        return isBST() && isSizeConsistent() && isRankConsistent() && is23() && isBalanced();
    }

    // does this binary tree satisfy symmetric order?
    // Note: this test also ensures that data structure is a binary tree since order is strict
    private boolean isBST() {
        return isBST(root, null, null);
    }

    // is the tree rooted at x a BST with all keys strictly between min and max
    // (if min or max is null, treat as empty constraint)
    // Credit: Bob Dondero's elegant solution
    private boolean isBST(Node x, Key min, Key max) {
        if (x == null) return true;
        if (min != null && x.key.compareTo(min) <= 0) return false;
        if (max != null && x.key.compareTo(max) >= 0) return false;
        return isBST(x.left, min, x.key) && isBST(x.right, x.key, max);
    } 

    // are the size fields correct?
    private boolean isSizeConsistent() { return isSizeConsistent(root); }
    private boolean isSizeConsistent(Node x) {
        if (x == null) return true;
        if (x.size != size(x.left) + size(x.right) + 1) return false;
        return isSizeConsistent(x.left) && isSizeConsistent(x.right);
    }

    // check that ranks are consistent
    private boolean isRankConsistent() {
        for (int i = 0; i < size(); i++)
            if (i != rank(select(i))) return false;
        for (Key key : keys())
            if (key.compareTo(select(rank(key))) != 0) return false;
        return true;
    }

    // Does the tree have no red right links, and at most one (left)
    // red links in a row on any path?
    private boolean is23() { return is23(root); }
    private boolean is23(Node x) {
        if (x == null) return true;
        if (isRed(x.right)) return false;
        if (x != root && isRed(x) && isRed(x.left))
            return false;
        return is23(x.left) && is23(x.right);
    } 

    // do all paths from root to leaf have same number of black edges?
    private boolean isBalanced() { 
        int black = 0;     // number of black links on path from root to min
        Node x = root;
        while (x != null) {
            if (!isRed(x)) black++;
            x = x.left;
        }
        return isBalanced(root, black);
    }

    // does every path from the root to a leaf have the given number of black links?
    private boolean isBalanced(Node x, int black) {
        if (x == null) return black == 0;
        if (!isRed(x)) black--;
        return isBalanced(x.left, black) && isBalanced(x.right, black);
    } 

    public static void main(String[] args) { 
        RedBlackBST<String, Integer> st = new RedBlackBST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
        StdOut.println();
    }
}