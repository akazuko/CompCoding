/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode merge(int[] nums, int first, int last){
        TreeNode node=null;
        if(first<=last){
            int mid = first + (last-first)/2;
            node = new TreeNode(nums[mid]);
            node.left=merge(nums, first, mid-1);
            node.right=merge(nums, mid+1, last);
        }
        return node;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        return merge(nums, 0, nums.length-1);
    }
}