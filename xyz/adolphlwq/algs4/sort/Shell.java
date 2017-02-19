public class Shell{
    private static int SHELL_H = 2;
    public Shell(){}

    public static void sort(Comparable[] a) {
        int len = a.length;
        int h = 1;
        //计算h的上界,h=h*3+1是保证下面j-=h时下界正好是1
        while(h<len/SHELL_H) h = SHELL_H*h+1;

        while(h>=1) {
            //h-有序 排序
            for (int i=h; i<len; i++) {
                for (int j=i; j>=h&&less(a[j], a[j-h]); j-=h) {
                    exch(a, j, j-h);
                }
            }
            assert isHSorted(a, h);
            h /= SHELL_H;
        }
        assert isSorted(a);
    }

    private static void exch(Object[] a, int i, int j) {
        Object swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    private static boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

    private static boolean isSorted(Comparable[] a) {
        for (int i=1; i<a.length; i++) {
            if (less(a[i], a[i-1]))
                return false;
        }
        return true;
    }

    private static boolean isHSorted(Comparable[] a, int h) {
        for (int i=h; i<a.length; i++) {
            if (less(a[i], a[i-h]))
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Integer[] a = {10,9,7,6,5,4,3,2,1};
        Shell.sort(a);
        for (int i=0; i<a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}