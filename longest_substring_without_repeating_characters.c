/*
 * Given a string, find the length of the longest substring without repeating characters.
 * Example 1:
 *          Input: "abcabcbb"
 *          Output: 3 
 *          Explanation: The answer is "abc", with the length of 3. 
 * Example 2:
 *          Input: "bbbbb"
 *          Output: 1
 *          Explanation: The answer is "b", with the length of 1.
 * Example 3:
 *          Input: "pwwkew"
 *          Output: 3
 *          Explanation: The answer is "wke", with the length of 3. 
 *                       Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 */

int lengthOfLongestSubstring(char* s)
{
    int i, j;
    int k = 0;

    int res = 1;
    int max_res = 0;

    int length = strlen(s);

    char pre_char;
    for (i = 0; i < length; ++i) {
        res = 1;
        pre_char = s[i];

        for (j = k; j < i; ++j) {
            if (s[j] == pre_char) {
                k = j + 1;
                break;
            }
            res++;
        }

        if (max_res < res) {
            max_res = res;
        }
    }
    return max_res;
}
