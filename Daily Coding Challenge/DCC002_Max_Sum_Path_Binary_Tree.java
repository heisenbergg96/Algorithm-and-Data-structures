
// Definition for a binary tree node.
public class TreeNode {
	int val;
   TreeNode left;
   TreeNode right;
   TreeNode(int x) { val = x; }
}
 
class Solution {
   
    int maxSum = Integer.MIN_VALUE;
   
    public int maxPathSum(TreeNode root) {
       
        util(root);
        return maxSum;
    }
   
    public int util(TreeNode root) {
       
        if(root == null)
            return 0;
       
        int left = util(root.left);
        int right = util(root.right);
       
        int leftRightMax = Math.max(root.val, root.val + Math.max(left, right));
        int crossOverSum = root.val + left + right;
        maxSum = Math.max(leftRightMax, Math.max(maxSum, crossOverSum));
       
        return leftRightMax;
    }
   

}
