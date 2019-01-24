/******************************************************************************
 *  Compilation:  javac DepthFirstSearch.java
 *  Execution:    java DepthFirstSearch filename.txt s
 *  Dependencies: Graph.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/41graph/tinyG.txt
 *                https://algs4.cs.princeton.edu/41graph/mediumG.txt
 *
 *  Run depth first search on an undirected graph.
 *  Runs in O(E + V) time.
 *
 *  % java DepthFirstSearch tinyG.txt 0
 *  0 1 2 3 4 5 6 
 *  NOT connected
 *
 *  % java DepthFirstSearch tinyG.txt 9
 *  9 10 11 12 
 *  NOT connected
 *
 ******************************************************************************/

package graph;

import utils.StdOut;
import utils.In;

public class DepthFirstSearch {
    private boolean[] marked;
    private int count;

    public DepthFirstSearch(Graph g, int s) {
        marked = new boolean[g.V()];
        validateVertex(s);
        dfs(g, s);
    }

    public int count() {
        return count;
    }

    public boolean marked(int s) {
        validateVertex(s);
        return marked[s];
    }

    private void validateVertex(int v) {
        int V = marked.length;
        if(v<0 || v>=V)
            throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
    }

    private void dfs(Graph g, int v) {
        count++;
        marked[v] = true;
        for(int w:g.adj(v)) {
            if(!marked[w])
                dfs(g, w);
        }
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph g = new Graph(in);
        int s = Integer.parseInt(args[1]);

        DepthFirstSearch dfs = new DepthFirstSearch(g, s);
        for(int i=0; i<g.V(); i++) {
            if(dfs.marked(i))
                StdOut.print(i + " ");
        }
        StdOut.println();
        StdOut.println("Graph: " + g);
        if(dfs.count() != g.V()) StdOut.println("NOT connected");
        else                     StdOut.println("connected");
    }
}