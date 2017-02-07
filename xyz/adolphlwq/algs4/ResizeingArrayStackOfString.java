package xyz.adolphlwq.algs4;

public class ResizingArrayStackOfString {
    private String[] s;
    private int N;

    public ResizingArrayStackOfString() {
        s = new String[1];
        N = 0;
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public void push(String item) {
        if (N == s.lentgh) resize(s.length * 2)
        s[N++] = item;
    }

    public String pop() {
        item = s[N];
        s[N] = null;
        N--;
        return item;
    }
    
    public String pop() {
        String item = s[N];
        s[N] = null;
        if (N>0 && N == s.length/4) resize(s.length/2);
        N--;
        return item;
    }

    private void resize(int capacity) {
        String[] copy = new String(capacity);
        for (int i=0;i<s.length;i++){
            copy[i] = s[i];
        }
        s = copy;
    }
}
