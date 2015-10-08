__author__ = 'bismarrck'


class TreeNode(object):

    def __init__(self, val, left, right, name=""):
        assert isinstance(val, int)
        self.val = val
        self.left = left
        self.right = right
        self.name = name


class Solution(object):

    def hasPathSum(self, root, target):
        assert isinstance(target, int)

        if root is None:
            return False

        if root.val == target and not root.left and not root.right:
            return True

        hasL = self.hasPathSum(root.left, target - root.val)
        hasR = self.hasPathSum(root.right, target - root.val)

        return hasL or hasR


    def pathSum(self, root, target):
        assert isinstance(target, int)
        def search(root, target, path, result):
            if not root:
                return result
            if root.val == target and not root.left and not root.right:
                path.append(root.val)
                result.append(path)
                return result
            if root.left:
                path1 = list(path)
                path1.append(root.val)
                result = search(root.left, target - root.val, path1, result)
            if root.right:
                path2 = list(path)
                path2.append(root.val)
                result = search(root.right, target - root.val, path2, result)
            return result
        return search(root, target, [], [])



if __name__ == "__main__":

    n41 = TreeNode(7, None, None, "n41")
    n42 = TreeNode(2, None, None, "n42")
    n43 = TreeNode(5, None, None, "n43")
    n44 = TreeNode(1, None, None, "n44")
    n31 = TreeNode(11, n41, n42, "n31")
    n32 = TreeNode(13, None, None, "n32")
    n33 = TreeNode(4, None, n43, "n33")
    n21 = TreeNode(4, n31, None, "n21")
    n22 = TreeNode(8, n32, n33, "n22")
    n11 = TreeNode(5, n21, n22, "n11")
    solution = Solution()
    print solution.hasPathSum(n11, 22)
    print solution.pathSum(n11,	22)

