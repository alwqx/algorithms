import edu.princeton.cs.algs4.*;

public class KosarajuSharirSCC {
    private int[] id;
    private boolean[] marked;
    private int count;

    public KosarajuSharirSCC(Digraph G) {
        DepthFirstOrder dfs = new DepthFirstOrder(G.reverse());
        marked = new boolean[G.V()];
        id = new int[G.V()];

        for (int v : dfs.reversePost()) {
            if (!marked[v]) {
                dfs(G, v);
                count++;
            }
        }
    }

    private void dfs(Digraph G, int v) {
        marked[v] = true;
        id[v] = count;
        for(int w:G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }

    public int count() {
        return count;
    }

    public boolean stronglyConnected(int v, int w) {
        return id[v] == id[w];
    }

    public int id(int v) {
        return id[v];
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Digraph G = new Digraph(in);
        KosarajuSharirSCC scc = new KosarajuSharirSCC(G);

        // number of connected components
        int m = scc.count();
        StdOut.println(m + " strong components");

        // compute list of vertices in each strong component
        Queue<Integer>[] components = (Queue<Integer>[]) new Queue[m];
        for (int i = 0; i < m; i++) {
            components[i] = new Queue<Integer>();
        }
        for (int v = 0; v < G.V(); v++) {
            components[scc.id(v)].enqueue(v);
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