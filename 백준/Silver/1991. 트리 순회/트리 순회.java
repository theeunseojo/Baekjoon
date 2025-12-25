

import java.util.Scanner;

public class Main {
    static class Node{
        char val;
        Node left, right;

        public Node(char val){
            this.val = val;
            this.left = this.right = null;
        }
    }
    static Node root = new Node('A');


    public static void insertNode(Node temp, char parent, char left, char right){
        if(temp == null) return;

        if(temp.val == parent){
            temp.left = left == '.' ? null : new Node(left);
            temp.right = right == '.' ? null : new Node(right);
        }else{
            insertNode(temp.left, parent, left, right);
            insertNode(temp.right, parent, left, right);
        }


    }
    //
    public static void preOrder(Node node){
        if(node == null) return;
        System.out.print(node.val);
        preOrder(node.left);
        preOrder(node.right);
    }
    public static void inOrder(Node node){
        if(node == null) return;
        inOrder(node.left);
        System.out.print(node.val);
        inOrder(node.right);
    }
    public static void postOrder(Node node){
        if(node == null ) return;
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.val);
    }
   public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

       for (int i = 0; i < n; i++) {
           char p = sc.next().charAt(0);
           char l = sc.next().charAt(0);
           char r = sc.next().charAt(0);

           insertNode(root, p, l, r);
       }

       preOrder(root);
       System.out.println();
       inOrder(root);
       System.out.println();
       postOrder(root);
       System.out.println();


   }
}