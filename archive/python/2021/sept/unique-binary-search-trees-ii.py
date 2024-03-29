from common import TreeNode


class Solution:
    def generateTrees(self, n):
        def generate(first, last):
            trees = []
            for root in range(first, last + 1):
                for left in generate(first, root - 1):
                    for right in generate(root + 1, last):
                        node = TreeNode(root)
                        node.left = left
                        node.right = right
                        trees += (node,)
            return trees or [None]

        return generate(1, n)
