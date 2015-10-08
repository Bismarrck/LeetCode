__author__ = 'bismarrck, Bismarrck@me.com'


class Solution:

    def intToRoman(self, num):
        assert num <= 3999

        info = {
            1000 : [" ", " ", "M"],
            100  : ["M", "D", "C"],
            10   : ["C", "L", "X"],
            1    : ["X", "V", "I"]
        }

        def _intToRoman(string, num, level):
            n = num / level
            H, M, L = info[level][:3]

            if n == 9:
                string += L + H
            elif n >= 5:
                string += M + L * (n - 5)
            elif n == 4:
                string += L + M
            else:
                string += L * n

            num -= n * level
            level /= 10
            if num == 0:
                return string
            else:
                return _intToRoman(string, num, level)

        string = _intToRoman("", num, 1000)
        return string


if __name__ == "__main__":

    clf = Solution()

    assert clf.intToRoman(3000) == "MMM"
    assert clf.intToRoman(1700) == "MDCC"
    assert clf.intToRoman(1400) == "MCD"
    assert clf.intToRoman(3999) == "MMMCMXCIX"
