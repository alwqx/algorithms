// package main.java.xyz.adolphlwq.algs4.graph;

import edu.princeton.cs.algs4.*;

public class DepthFirstPaths {
    private boolean[] marked;
    private int[] edgeTo;
    private int s;

    public DepthFirstPaths(Graph G, int s) {
        this.s = s;
        this.marked = new boolean[G.V()];
        this.edgeTo = new int[G.V()];

        dfs(G, s);
    }

    public void dfs(Graph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }

    public boolean hasPathTo(int v) {
        return this.marked[v];
    }

    public Iterable<Integer> pathTo(int v) {
        if (!hasPathTo(v)) {
            return null;
        }
        Stack<Integer> path = new Stack<Integer>();
        for (int x=v; x != s; x=edgeTo[x]){
            path.push(x);
        }
        path.push(s);

        return path;
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        int s = Integer.parseInt(args[1]);
        DepthFirstPaths dfp = new DepthFirstPaths(G, s);

        for (int v=0; v<G.V(); v++) {
            if (dfp.hasPathTo(v)) {
                StdOut.printf("%d to %d: ", s, v);
                for (int x : dfp.pathTo(v)) {
                    if (x == s) StdOut.print(x);
                    else        StdOut.print("-" + x);
                }
                StdOut.println();
            }else {
                StdOut.printf("%d to %d:  not connected\n", s, v);
            }
        }
    }
}