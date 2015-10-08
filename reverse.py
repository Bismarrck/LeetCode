__author__ = 'bismarrck, Bismarrck@me.com'



class Solution:

    INT_MAX =  2147483647
    INT_MIN = -2147483648

    def isbeyond(self, x, sign):
        v = long(x) * sign
        if v > Solution.INT_MAX or v < Solution.INT_MIN:
            return True
        else:
            return False


    def reverse(self, x):
        string = str(x)
        n = len(string)
        if n == 1:
            return x

        signs = {"+":1, "-":-1}
        if string[0] in signs.keys():
            sign = signs[string[0]]
            string = string[1:]
            if n == 2:
                return x
        else:
            sign = 1

        string = string[::-1]
        if self.isbeyond(string, sign):
            return 0
        else:
            return int(string) * sign


if __name__ == "__main__":

    clf = Solution()

    assert clf.reverse(321) == 123
    assert clf.reverse(-321) == -123
    assert clf.reverse(1534236469) == 0