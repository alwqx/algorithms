/******************************************************************************
 *  Compilation:  javac CC.java
 *  Execution:    java CC filename.txt
 *  Dependencies: Graph.java StdOut.java Queue.java
 *  Data files:   https://algs4.cs.princeton.edu/41graph/tinyG.txt
 *                https://algs4.cs.princeton.edu/41graph/mediumG.txt
 *                https://algs4.cs.princeton.edu/41graph/largeG.txt
 *
 *  Compute connected components using depth first search.
 *  Runs in O(E + V) time.
 *
 *  % java CC tinyG.txt
 *  3 components
 *  0 1 2 3 4 5 6
 *  7 8 
 *  9 10 11 12
 *
 *  % java CC mediumG.txt 
 *  1 components
 *  0 1 2 3 4 5 6 7 8 9 10 ...
 *
 *  % java -Xss50m CC largeG.txt 
 *  1 components
 *  0 1 2 3 4 5 6 7 8 9 10 ...
 *
 *  Note: This implementation uses a recursive DFS. To avoid needing
 *        a potentially very large stack size, replace with a non-recurisve
 *        DFS ala NonrecursiveDFS.java.
 *
 ******************************************************************************/

package graph;

import utils.In;
import utils.StdOut;
import queue.Queue;

public class CC {
    private int[] id;
    private boolean[] marked;
    private int[] size;
    private int count;

    public CC(Graph G) {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        size = new int[G.V()];

        for (int v=0; v<G.V(); v++) {
            if (!marked[v]) {
                dfs(G, v);
                count++;
            }
        }
    }

    public void dfs(Graph G, int v) {
        marked[v] = true;
        id[v] = count;
        size[count]++;

        for (int w : G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }

    public int id(int v) {
        validateVertex(v);
        return id[v];
    }

    public int size(int v) {
        validateVertex(v);
        return size[id[v]];
    }

    public int count() {
        return count;
    }

    public boolean connected(int v, int w) {
        validateVertex(v);
        validateVertex(w);
        return id(v) == id(w);
    }

    private void validateVertex(int v) {
        int V = marked.length;
        if (v < 0 || v >= V)
            throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        CC cc = new CC(G);

        // number of connected components
        int m = cc.count();
        StdOut.println(m + " components");

        // compute list of vertices in each connected component
        Queue<Integer>[] components = (Queue<Integer>[]) new Queue[m];
        for (int i = 0; i < m; i++) {
            components[i] = new Queue<Integer>();
        }
        for (int v = 0; v < G.V(); v++) {
            components[cc.id(v)].enqueue(v);
        }

        // print results
        for (int i = 0; i < m; i++) {
            for (int v : components[i]) {
                StdOut.print(v + " ");
            }
            StdOut.println();
        }
    }
}