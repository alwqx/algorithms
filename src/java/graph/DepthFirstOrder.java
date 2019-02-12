/******************************************************************************
 *  Compilation:  javac -classpath src src/graph/DepthFirstOrder.java
 *  Execution:    java -classpath src DepthFirstOrder digraph.txt
 *  Dependencies: Digraph.java Queue.java Stack.java StdOut.java
 *                EdgeWeightedDigraph.java DirectedEdge.java
 *  Data files:   https://algs4.cs.princeton.edu/42digraph/tinyDAG.txt
 *                https://algs4.cs.princeton.edu/42digraph/tinyDG.txt
 *
 *  Compute preorder and postorder for a digraph or edge-weighted digraph.
 *  Runs in O(E + V) time.
 *
 *  % java DepthFirstOrder tinyDAG.txt
 *     v  pre post
 *  --------------
 *     0    0    8
 *     1    3    2
 *     2    9   10
 *     3   10    9
 *     4    2    0
 *     5    1    1
 *     6    4    7
 *     7   11   11
 *     8   12   12
 *     9    5    6
 *    10    8    5
 *    11    6    4
 *    12    7    3
 *  Preorder:  0 5 4 1 6 9 11 12 10 2 3 7 8 
 *  Postorder: 4 5 1 12 11 10 9 6 0 3 2 7 8 
 *  Reverse postorder: 8 7 2 3 0 6 9 10 11 12 1 5 4 
 *
 ******************************************************************************/

package graph;

import queue.Queue;
import stack.Stack;
import utils.StdOut;
import utils.In;

public class DepthFirstOrder {
    private boolean[] marked;          // marked[v] = has v been marked in dfs?
    private int[] pre;                 // pre[v]    = preorder  number of v
    private int[] post;                // post[v]   = postorder number of v
    private Queue<Integer> preorder;   // vertices in preorder
    private Queue<Integer> postorder;  // vertices in postorder
    private int preCounter;            // counter or preorder numbering
    private int postCounter;           // counter for postorder numbering

    public DepthFirstOrder(Digraph G) {
        pre    = new int[G.V()];
        post   = new int[G.V()];
        postorder = new Queue<Integer>();
        preorder  = new Queue<Integer>();
        marked    = new boolean[G.V()];
        for (int v = 0; v < G.V(); v++)
            if (!marked[v]) dfs(G, v);

        assert check();
    }

    public DepthFirstOrder(EdgeWeightedDigraph G) {
        pre    = new int[G.V()];
        post   = new int[G.V()];
        postorder = new Queue<Integer>();
        preorder  = new Queue<Integer>();
        marked    = new boolean[G.V()];
        for (int v = 0; v < G.V(); v++)
            if (!marked[v]) dfs(G, v);
    }

    // run DFS in digraph G from vertex v and compute preorder/postorder
    private void dfs(Digraph G, int v) {
        marked[v] = true;
        pre[v] = preCounter++;
        preorder.enqueue(v);
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
        postorder.enqueue(v);
        post[v] = postCounter++;
    }

    // run DFS in edge-weighted digraph G from vertex v and compute preorder/postorder
    private void dfs(EdgeWeightedDigraph G, int v) {
        marked[v] = true;
        pre[v] = preCounter++;
        preorder.enqueue(v);
        for (DirectedEdge e : G.adj(v)) {
            int w = e.to();
            if (!marked[w]) {
                dfs(G, w);
            }
        }
        postorder.enqueue(v);
        post[v] = postCounter++;
    }

    // Returns the preorder number of vertex v
    public int pre(int v) {
        validateVertex(v);
        return pre[v];
    }

    // Returns the postorder number of vertex v
    public int post(int v) {
        validateVertex(v);
        return post[v];
    }

    // Returns the vertices in postorder
    public Iterable<Integer> post() {
        return postorder;
    }

    // Returns the vertices in preorder
    public Iterable<Integer> pre() {
        return preorder;
    }

    public Iterable<Integer> reversePost() {
        Stack<Integer> reverse = new Stack<Integer>();
        for (int v : postorder)
            reverse.push(v);
        return reverse;
    }


    // check that pre() and post() are consistent with pre(v) and post(v)
    private boolean check() {
        // check that post(v) is consistent with post()
        int r = 0;
        for (int v : post()) {
            if (post(v) != r) {
                StdOut.println("post(v) and post() inconsistent");
                return false;
            }
            r++;
        }

        // check that pre(v) is consistent with pre()
        r = 0;
        for (int v : pre()) {
            if (pre(v) != r) {
                StdOut.println("pre(v) and pre() inconsistent");
                return false;
            }
            r++;
        }

        return true;
    }

    // throw an IllegalArgumentException unless {@code 0 <= v < V}
    private void validateVertex(int v) {
        int V = marked.length;
        if (v < 0 || v >= V)
            throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Digraph G = new Digraph(in);

        DepthFirstOrder dfs = new DepthFirstOrder(G);
        StdOut.println("   v  pre post");
        StdOut.println("--------------");
        for (int v = 0; v < G.V(); v++) {
            StdOut.printf("%4d %4d %4d\n", v, dfs.pre(v), dfs.post(v));
        }

        StdOut.print("Preorder:  ");
        for (int v : dfs.pre()) {
            StdOut.print(v + " ");
        }
        StdOut.println();

        StdOut.print("Postorder: ");
        for (int v : dfs.post()) {
            StdOut.print(v + " ");
        }
        StdOut.println();

        StdOut.print("Reverse postorder: ");
        for (int v : dfs.reversePost()) {
            StdOut.print(v + " ");
        }
        
        StdOut.println();
    }
}