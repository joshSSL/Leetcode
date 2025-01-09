class Solution:
    def scoreOfString(self, s: str) -> int:
        count=0
        for i in range(len(s)-1):
            j=i+1
            count+=abs(ord(s[i])-ord(s[j]))
        return count
        