    # A Python3 solution for longest palindrome


# Function to print a subString str[low..high]
def printSubStr(str, low, high):
    for i in range(low, high + 1):
        print(str[i], end="")


# This function prints the
# longest palindrome subString
# It also returns the length
# of the longest palindrome
def longestPalSubstr(str):

    # Get length of input String
    n = len(str)

    # All subStrings of length 1
    # are palindromes
    maxLength = 1
    start = 0

    # Nested loop to mark start
    # and end index
    for i in range(n):
        for j in range(i, n):
            flag = 1

            # Check palindrome
            for k in range(0, ((j - i) // 2) + 1):
                if (str[i + k] != str[j - k]):
                    flag = 0

            # Palindrome
            if (flag != 0 and (j - i + 1) > maxLength):
                start = i
                maxLength = j - i + 1

    print("Longest palindrome substring is: ", end="")
    printSubStr(str, start, start + maxLength - 1)

    # Return length of LPS
    return maxLength


# Driver Code
if __name__ == '__main__':

    str = "forgeeksskeegfor"
    print("\nLength is:", longestPalSubstr(str))

'''
Approaches:
1. Naive Approach for Longest Palindromic Substring:
Check each substring, if it is a palindrome or not and keep updating the longest palindromic substring found till now.


2, Longest Palindromic Substring using Dynamic Programming:
The main idea behind the approach is that if we know the status (i.e., palindrome or not) of the substring ranging [i, j], we can find the status of the substring ranging [i-1, j+1] by only matching the character str[i-1] and str[j+1].

If the substring from i to j is not a palindrome, then the substring from i-1 to j+1 will also not be a palindrome. Otherwise, it will be a palindrome only if str[i-1] and str[j+1] are the same.
Base on this fact, we can create a 2D table (say table[][] which stores status of substring str[i . . . j] ), and check for substrings with length from 1 to N. For each length find all the substrings starting from each character i and find if it is a palindrom or not using the above idea. The longest length for which a palindrome formed will be the required asnwer.


3. Longest Palindromic Substring using Expansion from center:
The LPS is either of even length or odd length. So the idea is to traverse the input string and for each character check if this character can be the center of a palindromic substring of odd length or even length.
'''
