
package queue;

import java.util.Iterator;
import java.util.NoSuchElementException;

import utils.StdIn;
import utils.StdOut;

public class ResizingArrayQueue<Item> implements Iterable<Item> {
    private int first;
    private int last;
    private int size;
    private Item[] array;

    public ResizingArrayQueue() {
        array = (Item[]) new Object[2];
        size = 0;
        first = last = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void resize(int cap) {
        assert cap >= size;
        Item[] tmp = (Item[]) new Object[cap];
        for(int i=0; i<size; i++)
            tmp[i] = array[(first+i)%array.length];
        
        array=tmp;
        first=0;
        last=size;
    }

    public void enqueue(Item item) {
        if(size==array.length) resize(size*2);
        array[last++] = item;
        if(last==array.length) last=0;
        size++;
    }

    public Item dequeue() {
        if(isEmpty()) throw new NoSuchElementException("Queue underflow");
        Item item = array[first];
        array[first] = null;
        size--;
        first++;
        if(first==array.length) first=0;
        if(size>0 && size==array.length/4) resize(array.length/2);

        return item;
    }

    public Item peek() {
        if(isEmpty()) throw new NoSuchElementException("Queue underflow");

        return array[first];
    }

    public Iterator<Item> iterator() {
        return new ArrayIterator();
    }

    private class ArrayIterator implements Iterator<Item> {
        private int i=0;
        public boolean hasNext() {return i<size;}
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = array[(first+i)%array.length];
            i++;
            return item;
        }
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        for(int i=0; i<size; i++) {
            s.append(array[i] + " ");
        }

        return s.toString();
    }

    public static void main(String[] args) {
        ResizingArrayQueue<String> q = new ResizingArrayQueue<String>();
        while(!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if(!item.equals("-")) q.enqueue(item);
            else if(!q.isEmpty()) StdOut.print(q.dequeue() + " ");
        }

        StdOut.println("(" + q.size() + " left on queue)");
    }
}