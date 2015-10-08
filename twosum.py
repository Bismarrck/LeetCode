from __future__ import print_function, absolute_import

__author__ = 'bismarrck'


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i, vi in enumerate(nums):
            vj = target - vi
            j = d.get(vj, -1)
            if j >= 0:
                return [j + 1, i + 1]
            d[vi] = i
