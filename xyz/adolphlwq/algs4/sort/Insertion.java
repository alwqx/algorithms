public class Insertion {
    public Insertion() {}

    public static int[] insertSort(int[] array) {
        if (array == nul || a.lenth <= 1) return;
        int i,j,len,tmp;
        len = array.length;

        for (i=1; i<len; i++) {
            tmp = array[i];
            for (j=i; j>=&&array[j-1]>array[j; j--)
                array[j] = array[j-1]; //将值向后移动一位，直到找到正确的位置
            array[j] = tmp;//为什么是j不是j-1，因为循环中(j--)是后置执行语句。
        }
        return array;
    }

    public static void main(String[] args) {
        int[] ori = {5,4,3,2,1};
        Insertion insert = new Insertion();
        int[] ret = insert.insertSort(ori);
        for (int i=0; i<5; i++)
            System.out.println(ret[i]);
    }
}