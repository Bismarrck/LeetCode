__author__ = 'bismarrck, Bismarrck@me.com'



class Solution(object):

	INT_MAX =  2147483647
	INT_MIN = -2147483648
	INT_MAX_STR = "2147483647"
	INT_MIN_STR = "2147483648"

	def atoi(self, string):
		string = string.strip()

		if string == "":
			return 0

		digits = tuple(map(str, range(10)))
		signs = {"+":1, "-":-1}

		start = -1
		end = -1
		sign = 1

		for i in xrange(len(string)):
			if string[i] not in digits:
				if string[i] in signs.keys():
					sign = signs[string[i]]
					if string[i+1] not in digits:
						return 0
					else:
						continue
				if start < 0:
					return 0
				else:
					end = i
					break
			else:
				end = i + 1
				if start < 0:
					start = i

		if start < 0:
			return 0

		digit_string = string[start:end]

		if len(digit_string) > 1:
			k = 0
			while k < len(digit_string):
				if digit_string[k] != '0':
					break
				else:
					k = k + 1
			digit_string = digit_string[k:]

		if len(digit_string) < 10:
			return int(digit_string) * sign

		if len(digit_string) >= 11:
			if sign == 1:
				return Solution.INT_MAX
			else:
				return Solution.INT_MIN

		if sign == 1 and digit_string >= Solution.INT_MAX_STR:
			return Solution.INT_MAX

		if sign == -1 and digit_string >= Solution.INT_MIN_STR:
			return Solution.INT_MIN

		return int(digit_string) * sign






if __name__ == "__main__":

	clf = Solution()

	assert clf.atoi("") == 0
	assert clf.atoi("$%^(") == 0
	assert clf.atoi("+-2") == 0
	assert clf.atoi("00122") == 122
	assert clf.atoi("-0012a23") == -12
	assert clf.atoi("123456") == 123456
	assert clf.atoi("+123456") == 123456
	assert clf.atoi("-123456") == -123456
	assert clf.atoi(" 123456") == 123456
	assert clf.atoi("   $123456 #") == 0
	assert clf.atoi("12345678901") == Solution.INT_MAX
	assert clf.atoi("-5678901234") == Solution.INT_MIN
	assert clf.atoi("-2147483647") == -2147483647

	print("All tests are passed!")
