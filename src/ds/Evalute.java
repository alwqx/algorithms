package ds;

import utils.*;
import java.util.Stack;

public class Evalute {
    public static void main(String[] args){
        Stack<Double> vals = new Stack<Double>();
        Stack<String> opt = new Stack<String>();
        while (!StdIn.isEmpty()) {
            String s = StdIn.readString();
            if (s.equals("(")) {}
            else if (s.equals("+")) {opt.push(s);}
            else if (s.equals("*")) {opt.push(s);}
            else if (s.equals(")")) {
                String op = opt.pop();
                if (op.equals("+")) vals.push(vals.pop() + vals.pop());
                else if (op.equals("*")) vals.push(vals.pop() * vals.pop());
            }
            else vals.push(Double.parseDouble(s));
        }
        StdOut.println(vals.pop());
    }
}
