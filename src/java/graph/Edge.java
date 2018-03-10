import edu.princeton.cs.algs4.*;

public class Edge implements Comparable<Edge>{
    private final int v;
    private final int w;
    private final double weight;

    public Edge(int v, int w, double weight) {
        // check 
        if (v < 0) throw new IllegalArgumentException("vertex index must be a nonnegative integer");
        if (w < 0) throw new IllegalArgumentException("vertex index must be a nonnegative integer");
        if (Double.isNaN(weight)) throw new IllegalArgumentException("Weight is NaN");

        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    public double weight() {
        return weight;
    }

    public int either() {
        return v;
    }

    public int other(int vertex) {
        if (this.v == vertex) return w;
        else if (this.w == vertex) return v;
        else throw new IllegalArgumentException("Illegal endpoint");
    }

    public int compareTo(Edge other) {
        return Double.compare(this.weight, other.weight);
    }

    public String toString() {
        return String.format("%d-%d %.5f", v, w, weight);
    }

    public static void main(String[] args) {
        Edge e = new Edge(12, 34, 5.67);
        System.out.println(e);
    }
}