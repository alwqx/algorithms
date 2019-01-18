/******************************************************************************
 *  Compilation:  javac LinkedQueue.java
 *  Execution:    java LinkedQueue < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/13stacks/tobe.txt  
 *
 *  A generic queue, implemented using a singly linked list.
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

 public class LinkedQueue<Item> implements Iterable<Item> {
     private class Node {
         private Item item;
         private Node next;
     }

     private Node first;
     private Node last;
     private int size;

     public LinkedQueue() {
         first = last = null;
         size = 0;

         assert check();
     }

     public boolean isEmpty() {
        //  return size == 0;
         return first == null;
     }

     public int size() {
         return size;
     }

     public Item peek() {
         if(isEmpty()) throw new NoSuchElementException("Queue underflow");
         return first.item;
     }

     public void enqueue(Item item) {
         Node oldlast = last;
         last = new Node();
         last.item = item;
         last.next = null;
         size++;
         if(isEmpty()) first=last;
         else oldlast.next = last;

         assert check();
     }

     public Item dequeue() {
         if(isEmpty()) throw new NoSuchElementException("Queue underflow");
         Item item = first.item;
         first = first.next;
         size--;
         if(isEmpty()) last = null;

         assert check();
         return item;
     }

     public String toString() {
         StringBuilder s = new StringBuilder();
         for(Item item:this) {
             s.append(item + " ");
         }

         return s.toString();
     }

     public Iterator<Item> iterator() {
        return new ListIterator();
     }

     private class ListIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {return current != null;}
        public void remove() {throw new UnsupportedOperationException();}

        public Item next() {
            if(!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;

            return item;
        }
     }

     private boolean check() {
        if(size < 0){
            return false;
        }else if(size == 0) {
            if(first != null) return false;
            if(last != null) return false;
        }else if(size==1) {
            if(first==null || last==null) return false;
            if(first != last) return false;
            if(first.next != null) return false;
        }else{
            if(first==null || last==null) return false;
            if(first == last) return false;

            if(first.next==null) return false;
            if(last.next != null) return false;

            int n = 0;
            for(Node x=first; x!=null; x=x.next)
                n++;
            if(n!=size) return false;

            Node lastNode = first;
            while(lastNode.next != null)
                lastNode = lastNode.next;
            if(lastNode!=last) return false;
        }
        
        return true;
     }

     public static void main(String[] args) {
         LinkedQueue<String> q = new LinkedQueue<String>();
         while(!StdIn.isEmpty()) {
             String item = StdIn.readString();
             if(!item.equals("-")) q.enqueue(item);
             else if(!q.isEmpty())
                StdOut.print(q.dequeue() + " ");
         }

         StdOut.println("(" + q.size() + " left on queue)");
     }
 }