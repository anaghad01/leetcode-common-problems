
/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there will not be input like 3a or 2[4].
*/

class Solution {
public:
    string solve(int &i, string &s) {
	string result;
	while(i < s.size() && s[i] != ']') {
		if(s[i] >= 'a' && s[i] <= 'z')
			result += s[i++];
		else {
			int n = 0;
			while(s[i] >= '0' && s[i] <= '9')
				n = n * 10 + s[i++] - '0';
			i++;
			string str = solve(i, s);
			for(int j = 0; j < n; j++)
				result += str;
			i++;
		}
	}
	return result;
}

string decodeString(string s) {
	int i = 0;
	return solve(i, s);
}
};
