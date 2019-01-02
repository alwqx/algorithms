package ds;

public class FixedCapacityStackOfStrings {
    private int N;
    private String[] s;

    public FixedCapacityStackOfStrings(int capacity) {
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
        String item = s[N];
        s[N] = null;
        N--;
        return item;
    }
}
