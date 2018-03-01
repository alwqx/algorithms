import edu.princeton.cs.algs4.*;

public class DepthFirstPathsNonRecurise {
    private boolean[] marked;
    private int s;
    private int[] edgeTo;

    public DepthFirstPathsNonRecurise(Graph G, int s) {
        this.s = s;
        this.marked  = new boolean[G.V()];
        this.edgeTo = new int[G.V()];

        dfsnr(G, s);
    }

    public void dfsnr(Graph G, int s) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(s);
        marked[s] = true;

        while(!stack.isEmpty()) {
            int top = stack.pop();
            for (int w : G.adj(top)) {
                if (!marked[w]) {
                    marked[w] = true;
                    edgeTo[w] = top;
                    stack.push(w);
                }
            }
        }
    }

    public boolean hasPathTo(int v) {
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v) {
        if (!hasPathTo(v)) {
            return null;
        }

        Stack<Integer> path = new Stack<Integer>();
        int x;
        for (x=v; x != s; x=edgeTo[x]) {
            path.push(x);
        }
        path.push(x);

        return path;
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        int s = Integer.parseInt(args[1]);
        DepthFirstPathsNonRecurise dfp = new DepthFirstPathsNonRecurise(G, s);

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