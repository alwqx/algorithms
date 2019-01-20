/******************************************************************************
 *  Compilation:  javac Queue.java
 *  Execution:    java Queue < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/13stacks/tobe.txt  
 *
 *  A generic queue, implemented using a linked list.
 *
 *  % java Queue < tobe.txt 
 *  to be or not to be (2 left on queue)
 *
 ******************************************************************************/

package queue;

import java.util.Iterator;
import java.util.NoSuchElementException;

import utils.StdIn;
import utils.StdOut;

public class Queue<Item> implements Iterable<Item> {
    private static class Node<Item> {
        private Item item;
        private Node<Item> next;
    }

    private Node<Item> first;
    private Node<Item> last;
    private int size;

    public Queue() {
        first = null;
        last = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
        // return first == null;
    }

    public int size() {
        return size;
    }

    public Item peek() {
        if(isEmpty()) throw new NoSuchElementException("Queue underflow");
        return first.item;
    }

    public void enqueue(Item item) {
        Node<Item> oldlast = last;
        last = new Node<Item>();
        last.item = item;
        last.next = null;
        if(isEmpty()) first=last;
        else oldlast.next = last;
        size++;

        // if(isEmpty()) {
        //     first.item = item;
        //     last = first;
        //     size++;
        // }else{
        //     Node<Item> node = new Node<Item>();
        //     node.item = item;
        //     node.next = null;
        //     last.next = node;
        //     last = node;
        //     size++;
        // }
    }

    public Item dequeue() {
        if(isEmpty()) throw new NoSuchElementException("Queue underflow");
        Item item = first.item;
        first = first.next;
        size--;
        if(isEmpty()) last = null;

        return item;
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        for(Item item:this){
            s.append(item + " ");
        }

        return s.toString();
    }

    public Iterator<Item> iterator() {
        return new ListIterator<Item>(first);
    }

    private class ListIterator<Item> implements Iterator<Item> {
        private Node<Item> current;

        public ListIterator(Node<Item> first) {
            current = first;
        }

        public boolean hasNext() {return current != null;}
        public void remove() {throw new UnsupportedOperationException();}

        public Item next() {
            if(!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;

            return item;
        }
    }

    public static void main(String[] args) {
        Queue<String> q = new Queue<String>();
        while(!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if(!item.equals("-"))
                q.enqueue(item);
            else if(!q.isEmpty())
                StdOut.print(q.dequeue() + " ");
        }

        StdOut.println("(" + q.size() + " left on queue)");
    }
}