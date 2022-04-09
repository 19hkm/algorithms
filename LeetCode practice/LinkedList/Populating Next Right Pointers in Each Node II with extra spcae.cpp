// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root == null) return root;
        Queue<Node> q = new LinkedList<>();
        q.add(root); q.add(null);
        while(!q.isEmpty()) {
            Node curr = q.remove();
            if(curr == null ) {
                if(!q.isEmpty()) q.add(curr);
                else break;
            } else {
                Node nextNode = q.peek();
                curr.next = nextNode;
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
        }
        return root;
    }
}

