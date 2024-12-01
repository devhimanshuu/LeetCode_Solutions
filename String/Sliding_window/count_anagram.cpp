/**Count Occurences of Anagrams

Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer.
You dont need to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both strings contain lowercase English letters.**/

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(string pat, string txt)
    {
        // code here
        int n = txt.size();
        int k = pat.size();
        int i = 0, j = 0;
        vector<int> patFreq(26, 0), windowFreq(26, 0);
        int count = 0;

        for (char c : pat)
        {
            patFreq[c - 'a']++;
        }

        while (j < n)
        {

            windowFreq[txt[j] - 'a']++;

            if (j - i + 1 < k)
            {
                j++;
            }

            else if (j - i + 1 == k)
            {

                if (patFreq == windowFreq)
                {
                    count++;
                }

                windowFreq[txt[i] - 'a']--;
                i++;
                j++;
            }
        }
        return count;
    }
};