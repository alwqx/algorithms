// refer https://github.com/kevin-wayne/algs4/blob/master/src/main/java/edu/princeton/cs/algs4/AVLTreeST.java
import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.*;

public class AVLTreeST<Key extends Comparable<Key>, Value> {
    private Node root;

    private class Node{
        private final Key key;
        private Value value;
        private int height;
        private int size;
        private Node left;
        private Node right;

        public Node(Key key, Value value, int height, int size) {
            this.key = key;
            this.value = value;
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
        return x==null?0:x.size;
    }

    public int height() {
        return height(root);
    }

    private int height(Node x) {
        return x==null?-1:x.height;
    }

    public Value get(Key key) {
        if (key == null) throw new IllegalArgumentException("Argiment to get() is null");
        Node x = get(root, key);
        if (x == null) return null;
        return x.value;
    }

    private Node get(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp < 0) return get(x.left, key);
        else if (cmp > 0) return get(x.right, key);
        else return x;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    public void put(Key key, Value value) {
        if (key == null) throw new IllegalArgumentException("first argument to put is null");
        if (value == null) {
            delete(key);
            return;
        }
        root = put(root, key, value);
        assert check();
    }

    //put()进行递归调用，需要仔细阅读这个函数，对各种情况的处理，以及判断条件后size/height的更新
    private Node put(Node x, Key key, Value value) {
        if (x == null) return new Node(key, value, 0, 1);
        int cmp = key.compareTo(x.key);
        if (cmp < 0) x.left = put(x.left, key, value);//这里的递归需要仔细思考
        else if(cmp > 0) x.right = put(x.right, key, value);
        else {
            x.value = value;
            return x;//这里和上面的递归呼应，算是最基本的情况，所有递归到了最初的情形。
        }
        x.size = size(x.left) + size(x.right) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1; //这里为什么不直接 x.size+=1 x.height+=1?
        return balance(x); //make tree to AVL
    }

    private Node balance(Node x){
        if (balanceFactor(x) < -1) { //左子树低，需要对x进行左旋转
            if (balanceFactor(x.right) > 0) {//如果右子树比左子树高，这是“右左插入”，先右旋转，再左旋转
                x.right = rotateRight(x.right);
            }
            x = rotateLeft(x);
        }
        else if (balanceFactor(x) > 1) {
            if (balanceFactor(x.left) < 0) {
                x.left = rotateLeft(x.left);
            }
            x = rotateRight(x);
        }
        return x;
    }

    private int balanceFactor(Node x) {
        return height(x.left) - height(x.right);
    }

    /* 对https://github.com/kevin-wayne/algs4/blob/master/src/main/java/edu/princeton/cs/algs4/AVLTreeST.java#L288-L296
    代码的分析
    private Node rotateRight(Node x) {
        //传出参数x是对象引用的一个副本，对x的修改会影响到原来的对象。
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        y.size = x.size; //更新了y的size，直接把x的size赋值给y，没有调用方法来计算。
        x.size = 1 + size(x.left) + size(x.right);//此时x已经不是root节点了，原来的size已经给了新的root y，可以放心地更新作为右子树的x的size。
        x.height = 1 + Math.max(height(x.left), height(x.right));//重新计算x的height
        y.height = 1 + Math.max(height(y.left), height(y.right));//重新计算y的height
        return y;//返回y，y是指向原对象的引用，原对象已经被更新。
    }*/
    private Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        y.size = x.size;
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));
        y.height = 1 + Math.max(height(y.left), height(y.right));
        return y;
    }

    public Node rotateLeft(Node x) {
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
        if (!contains(key)) return;
        root = delete(root, key);
        assert check();
    }

    private Node delete(Node x, Key key) {
        int cmp = key.compareTo(x.key);
        if (cmp < 0) {
            x.left = delete(x.left, key);
        }else if (cmp > 0) {
            x.right = delete(x.right, key);
        }else {
            if (x.left == null) {
                return x.right;
            }else if (x.right == null) {
                return x.left;
            }else {
                Node y = x;
                x = min(y.right);
                x.right = deleteMin(y.right);
                x.left = y.left;
            }
        }
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.right), height(x.left));
        return balance(x);
    }

    public void deleteMin() {
        if (isEmpty()) throw new NoSuchElementException("called deleteMin() with symbol table");
        root = deleteMin(root);
        assert check();
    }

    private Node deleteMin(Node x) {
        if (x.left == null) return x.right;
        x.left = deleteMin(x.left);//递归调用，这里用到AVLTree的一个性质：左节点比右节点小。
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.right), height(x.left));
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
        x.left = deleteMin(x.left);//递归调用，这里用到AVLTree的一个性质：左节点比右节点小。
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.right), height(x.left));
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

    //返回<= key的最大的key
    //都是从root节点开始找
    public Key floor(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to floor() is null");
        if (isEmpty()) throw new NoSuchElementException("called floor() with empty symbol table");
        Node x = floor(root, key);
        return (x==null)?null:x.key;
    }

    private Node floor(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp < 0) return floor(x.left, key);
        Node y = floor(x.right, key);
        return (y==null)?x:y;
    }

    //返回>= key的最小key
    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        if (isEmpty()) throw new NoSuchElementException("called ceiling() with empty symbol table");
        Node x = ceiling(root, key);
        return (x==null)?null:x.key;
    }

    private Node ceiling(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp > 0) return ceiling(x.right, key);
        Node y = ceiling(x.left, key);
        return (y==null)?x:y;
    }

    //返回第k个最小的值，下标从0开始。
    public Key select(int k) {
        if (k<0 || k>=size()) throw new IllegalArgumentException("k is not in 0-"+(size()-1));
        Node x = select(root, k);
        return x.key;
    }

    private Node select(Node x, int key) {
        if (x==null) return null;
        int t = size(x.left);
        if (t > key) return select(x.left, key);
        else if (t < key) return select(x.right, key-t-1);//-1是因为去掉子树的根节点
        else return x;
    }

    //
    public int rank(Key key) {
        if (key==null) throw new IllegalArgumentException("argument to rank() is null");
        return rank(key, root);
    }

    private int rank(Key key, Node x) {
        if (x==null) return 0;
        int cmp = key.compareTo(x.key);
        if (cmp<0) return rank(key, x.left);
        else if(cmp>0) return 1+size(x.left)+rank(key, x.right);//+1是根节点。
        else return size(x.left);
    }

    public Iterable<Key> keys() {
        return keysInOrder();
    }

    public Iterable<Key> keysInOrder() {
        Queue<Key> queue = new Queue<Key>();
        keysInOrder(root, queue);
        return queue;
    }

    //基本是递归操作，逆向代码和符号表调用已经弄清楚。
    private void keysInOrder(Node x, Queue<Key> queue) {
        if (x == null) return;
        keysInOrder(x.left, queue);
        queue.enqueue(x.key);
        keysInOrder(x.right, queue);
    }

    public Iterable<Key> keysLevelOrder() {
        Queue<Key> queue = new Queue<Key>();
        if(!isEmpty()) {
            Queue<Node> queue2 = new Queue<Node>();
            queue2.enqueue(root);
            while(!queue2.isEmpty()) {
                Node x = queue2.dequeue();
                queue.enqueue(x.key);
                if (x.left != null) queue2.enqueue(x.left);
                if (x.right != null) queue2.enqueue(x.right);
            }
        }
        return queue;
    }

    public boolean isAVL() {
        return isAVL(root);
    }

    private boolean isAVL(Node x) {
        if (x==null) return true;
        int bf = balanceFactor(x);
        if(bf>1||bf<-1) return false;
        return isAVL(x.left) && isAVL(x.right);
    }

    public boolean isBST() {
        return isBST(root, null, null);
    }

    private boolean isBST(Node x, Key min, Key max) {
        if (x==null) return true;
        if (min!=null&&x.key.compareTo(min)<=0) return false;
        if (max!=null&&x.key.compareTo(max)>=0) return false;
        return isBST(x.left, min, x.key) && isBST(x.right, x.key, max);
    }

    private boolean check() {
        if (!isBST()) StdOut.println("Symmetric order not consistent");
        if (!isAVL()) StdOut.println("AVL property not consistent");
        // if (!isSizeConsistent()) StdOut.println("Subtree counts not consistent");
        // if (!isRankConsistent()) StdOut.println("Ranks not consistent");
        // return isBST() && isAVL() && isSizeConsistent() && isRankConsistent();
        return isBST() && isAVL();
    }

     public static void main(String[] args) {
        AVLTreeST<String, Integer> st = new AVLTreeST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
        StdOut.println();
    }
}