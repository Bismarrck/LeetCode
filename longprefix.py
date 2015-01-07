__author__ = 'bismarrck, Bismarrck@me.com'


class Solution(object):

	def longestCommonPrefix(self, strings):
		nstring = len(strings)
		if nstring == 0:
			return ""

		lenghts = map(len, strings)
		minimum = min(lenghts)
		sample = strings[lenghts.index(minimum)]

		for i in xrange(minimum):
			prefix = sample[0:i+1]
			all = filter(lambda x : x.startswith(prefix), strings)
			if len(all) < nstring:
				return sample[0:i]

		return sample



if __name__ == "__main__":

	clf = Solution()

	strings = ("com.apple.ios", "com.apple.mac", "com.apple.ipad")
	assert clf.longestCommonPrefix(strings) == "com.apple."