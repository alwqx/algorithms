/******************************************************************************
 *  Compilation:  javac AVLTreeST.java
 *  Execution:    java AVLTreeST < input.txt
 *  Dependencies: StdIn.java StdOut.java  
 *  Data files:   https://algs4.cs.princeton.edu/33balanced/tinyST.txt  
 *    
 *  A symbol table implemented using an AVL tree.
 *
 *  % more tinyST.txt
 *  S E A R C H E X A M P L E
 *  
 *  % java AVLTreeST < tinyST.txt
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

public class AVLTreeST<Key extends Comparable<Key>, Value> {
    private Node root;

    private class Node {
        private int size;
        private int height;
        private final Key key;
        private Value value;
        private Node left;
        private Node right;

        public Node(Key key, Value val, int height, int size) {
            this.key = key;
            this.value = val;
            this.height = height;
            this.size = size;
        }
    }

    public AVLTreeST() {}

    public boolean isEmpty() {
        return root == null;
    }

    public int size() {
        return size(root);
    }

    private int size(Node x) {
        if(x == null) return 0;
        return x.size;
    }

    public int height() {
        return height(root);
    }

    private int height(Node x) {
        if(x==null) return -1;
        return x.height;
    }

    public Value get(Key key) {
        if(key == null) throw new IllegalArgumentException("argument to get() is null");
        Node x = get(root, key);
        if(x == null) return null;
        return x.value;
    }

    private Node get(Node x, Key key) {
        if(x == null) return null;
        int cmp = key.compareTo(x.key);
        if(cmp<0) return get(x.left, key);
        else if(cmp>0) return get(x.right, key);
        else return x;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    public void put(Key key, Value val) {
        if (key == null) throw new IllegalArgumentException("first argument to put() is null");
        if (val == null) {
            delete(key);
            return;
        }

        root = put(root, key, val);
        assert check();
    }

    private Node put(Node x, Key key, Value val) {
        if(x == null) return new Node(key, val, 0, 1);
        int cmp = key.compareTo(x.key);

        if(cmp < 0) x.left = put(x.left, key, val);
        else if(cmp > 0) x.right = put(x.right, key, val);
        else {
            x.value = val;
            return x;
        }

        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));

        return balance(x);
    }

    private Node balance(Node x) {
        if(balanceFactor(x) < -1) {
            if(balanceFactor(x.right) > 0)
                x.right = rotateRight(x.right);
            x = rotateLeft(x);
        }else if(balanceFactor(x) > 1) {
            if(balanceFactor(x.left) < 0)
                x.left = rotateLeft(x.left);
            x = rotateRight(x);
        }

        return x;
    }

    private int balanceFactor(Node x) {
        return height(x.left) - height(x.right);
    }

    private Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        y.size = x.size;
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + height(x.left) + height(x.right);
        y.height = 1 + height(y.left) + height(y.right);

        return y;
    }

    private Node rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        y.size = x.size;
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));
        y.height = 1 + Math.max(height(y.left), height(y.right));

        return y;
    }

    public void delete(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to delete() is null");
        if(!contains(key)) return;

        root = delete(root, key);
        assert check();
    }

    private Node delete(Node x, Key key) {
        int cmp = key.compareTo(x.key);
        if(cmp < 0) x.left = delete(x.left, key);
        else if(cmp > 0) x.right = delete(x.right, key);
        else{
            if(x.left == null) return x.right;
            else if(x.right == null) return x.left;
            else{
                Node y = x;
                x = min(y.right);
                x.right = deleteMin(y.right);
                x.left = y.left;
            }
        }

        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));
        return balance(x);
    }

    public void deleteMin() {
        if (isEmpty()) throw new NoSuchElementException("called deleteMin() with empty symbol table");
        root = deleteMin(root);
        assert check();
    }

    private Node deleteMin(Node x) {
        if(x.left == null) return x.right;
        x.left = deleteMin(x.left);
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));
        
        return balance(x);
    }

    public void deleteMax() {
        if (isEmpty()) throw new NoSuchElementException("called deleteMax() with empty symbol table");
        root = deleteMax(root);
        assert check();
    }

    private Node deleteMax(Node x) {
        if (x.right == null) return x.left;
        x.right = deleteMax(x.right);
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));

        return balance(x);
    }

    public Key min() {
        if (isEmpty()) throw new NoSuchElementException("called min() with empty symbol table");
        return min(root).key;
    }

    private Node min(Node x) {
        if (x.left == null) return x;
        return min(x.left);
    }

    public Key max() {
        if (isEmpty()) throw new NoSuchElementException("called max() with empty symbol table");
        return max(root).key;
    }

    private Node max(Node x) {
        if (x.right == null) return x;
        return max(x.right);
    }

    // Returns the largest key in the symbol table less than or equal to key
    public Key floor(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to floor() is null");
        if (isEmpty()) throw new NoSuchElementException("called floor() with empty symbol table");

        Node x = floor(root, key);
        if(x==null) return null;
        else return x.key;
    }

    // Returns the node in the subtree with the largest key less than or equal
    // to the given key
    private Node floor(Node x, Key key) {
        if(x == null) return null;
        int cmp = key.compareTo(x.key);
        if(cmp == 0) return x;
        if(cmp < 0) return floor(x.left, key);

        Node y = floor(x.right, key);
        if(y != null) return y;
        return x;
    }

    // Returns the smallest key in the symbol table greater than or equal to key
    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        if (isEmpty()) throw new NoSuchElementException("called ceiling() with empty symbol table");
        Node x = ceiling(root, key);
        if (x == null) return null;
        else return x.key;
    }

    // Returns the node in the subtree with the smallest key greater than or
    // equal to the given key
    private Node ceiling(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp > 0) return ceiling(x.right, key);
        Node y = ceiling(x.left, key);
        if (y != null) return y;
        else return x;
    }

    // Returns the kth smallest key in the symbol table
    public Key select(int k) {
        if (k < 0 || k >= size()) throw new IllegalArgumentException("k is not in range 0-" + (size() - 1));
        Node x = select(root, k);
        return x.key;
    }

    // Returns the node with key the kth smallest key in the subtree
    private Node select(Node x, int k) {
        if (x == null) return null;
        int t = size(x.left);
        if (t > k) return select(x.left, k);
        else if (t < k) return select(x.right, k - t - 1);
        else return x;
    }

    // Returns the number of keys in the symbol table strictly less than key
    public int rank(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to rank() is null");
        return rank(key, root);
    }

    // Returns the number of keys in the subtree less than key
    private int rank(Key key, Node x) {
        if (x == null) return 0;
        int cmp = key.compareTo(x.key);
        if (cmp < 0) return rank(key, x.left);
        else if (cmp > 0) return 1 + size(x.left) + rank(key, x.right);
        else return size(x.left);
    }

    // Returns all keys in the symbol table
    public Iterable<Key> keys() {
        return keysInOrder();
    }

    // Returns all keys in the symbol table following an in-order traversal
    public Iterable<Key> keysInOrder() {
        Queue<Key> queue = new Queue<Key>();
        keysInOrder(root, queue);
        return queue;
    }

    // Adds the keys in the subtree to queue following an in-order traversal
    private void keysInOrder(Node x, Queue<Key> queue) {
        if (x == null) return;
        keysInOrder(x.left, queue);
        queue.enqueue(x.key);
        keysInOrder(x.right, queue);
    }

    // Returns all keys in the symbol table following a level-order traversal
    public Iterable<Key> keysLevelOrder() {
        Queue<Key> queue = new Queue<Key>();
        if (!isEmpty()) {
            Queue<Node> queue2 = new Queue<Node>();
            queue2.enqueue(root);
            while (!queue2.isEmpty()) {
                Node x = queue2.dequeue();
                queue.enqueue(x.key);
                if (x.left != null) {
                    queue2.enqueue(x.left);
                }
                if (x.right != null) {
                    queue2.enqueue(x.right);
                }
            }
        }
        return queue;
    }

    // Returns all keys in the symbol table in the given range
    public Iterable<Key> keys(Key low, Key high) {
        if (low == null) throw new IllegalArgumentException("first argument to keys() is null");
        if (high == null) throw new IllegalArgumentException("second argument to keys() is null");
        Queue<Key> queue = new Queue<Key>();
        keys(root, queue, low, high);
        return queue;
    }

    // Adds the keys between {@code lo} and {@code hi} in the subtree
    private void keys(Node x, Queue<Key> queue, Key low, Key high) {
        if (x == null) return;
        int cmplo = low.compareTo(x.key);
        int cmphi = high.compareTo(x.key);
        if (cmplo < 0) keys(x.left, queue, low, high);
        if (cmplo <= 0 && cmphi >= 0) queue.enqueue(x.key);
        if (cmphi > 0) keys(x.right, queue, low, high);
    }

    // Returns the number of keys in the symbol table in the given range
    public int size(Key lo, Key hi) {
        if (lo == null) throw new IllegalArgumentException("first argument to size() is null");
        if (hi == null) throw new IllegalArgumentException("second argument to size() is null");
        if (lo.compareTo(hi) > 0) return 0;
        if (contains(hi)) return rank(hi) - rank(lo) + 1;
        else return rank(hi) - rank(lo);
    }

    // Checks if the AVL tree invariants are fine
    private boolean check() {
        if (!isBST()) StdOut.println("Symmetric order not consistent");
        if (!isAVL()) StdOut.println("AVL property not consistent");
        if (!isSizeConsistent()) StdOut.println("Subtree counts not consistent");
        if (!isRankConsistent()) StdOut.println("Ranks not consistent");
        return isBST() && isAVL() && isSizeConsistent() && isRankConsistent();
    }

    // Checks if AVL property is consistent
    private boolean isAVL() {
        return isAVL(root);
    }

    // Checks if AVL property is consistent in the subtree
    private boolean isAVL(Node x) {
        if (x == null) return true;
        int bf = balanceFactor(x);
        if (bf > 1 || bf < -1) return false;
        return isAVL(x.left) && isAVL(x.right);
    }

    // Checks if the symmetric order is consistent
    private boolean isBST() {
        return isBST(root, null, null);
    }

    // Checks if the tree rooted at x is a BST with all keys strictly between
    // min and max (if min or max is null, treat as empty constraint) Credit:
    // Bob Dondero's elegant solution
    private boolean isBST(Node x, Key min, Key max) {
        if (x == null) return true;
        if (min != null && x.key.compareTo(min) <= 0) return false;
        if (max != null && x.key.compareTo(max) >= 0) return false;
        return isBST(x.left, min, x.key) && isBST(x.right, x.key, max);
    }

    // Checks if size is consistent
    private boolean isSizeConsistent() {
        return isSizeConsistent(root);
    }

    // Checks if the size of the subtree is consistent
    private boolean isSizeConsistent(Node x) {
        if (x == null) return true;
        if (x.size != size(x.left) + size(x.right) + 1) return false;
        return isSizeConsistent(x.left) && isSizeConsistent(x.right);
    }

    // Checks if rank is consistent
    private boolean isRankConsistent() {
        for (int i = 0; i < size(); i++)
            if (i != rank(select(i))) return false;
        for (Key key : keys())
            if (key.compareTo(select(rank(key))) != 0) return false;
        return true;
    }

    public static void main(String[] args) {
        AVLTreeST<String, Integer> st = new AVLTreeST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}