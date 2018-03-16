# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.order = []
        
    def getOrder(self, root):
        if root.left != None:
            self.getOrder(root.left)
        self.order.append(root.val)
        if root.right != None:
            self.getOrder(root.right)
            
    def reConstruct(self, root):
        if root.left != None:
            self.reConstruct(root.left)
        self.order.append(root.val)
        root.val = self.order.pop(0)
        if root.right != None:
            self.reConstruct(root.right)
            
            
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.getOrder(root)
        self.order.sort()
        self.reConstruct(root)
        
        