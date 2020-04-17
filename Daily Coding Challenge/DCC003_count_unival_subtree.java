/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

public class Solution {
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
     int count = 0;
    public int countUnivalSubtrees(TreeNode root) {
        // write your code here
        util(root);
        return count;
    }
    
     boolean util(TreeNode root) {
        
        if(root == null)
            return true;
        
        boolean left = util(root.left);
        boolean right = util(root.right);
        if(right == false || right == false)
            return false;
        if(root.left != null && root.left.val != root.val)
            return false;
        if(root.right != null && root.right.val != root.val)
            return false;
            
        count++;
        return true;
    }
}
