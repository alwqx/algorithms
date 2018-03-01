package xyz.adolphlwq.algs4;

public class FixedCapacityStackOfStrings {
    private int N;
    private String[] s;

    public FixedCapacityOfStrings(int capacity) {
        s = new String[capacity];
        N = 0;
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public void push(String item) {
        s[N] = item;
        N++;
    }

    public String pop() {
        item = s[N];
        s[N] = null;
        N--;
        return item
    }
}
