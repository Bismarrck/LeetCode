__author__ = 'bismarrck, Bismarrck@me.com'


class Solution:

	# @param A, a list of integer
	# @return an integer
	def singleNumber(self, A):
		s = {}
		for i in A:
			s[i] = s.get(i, 0) + 1
		for key, val in s.items():
			if val == 1:
				return key
