/**12. Integer to Roman
Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.



Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
   **/

// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string RoMaN(int c)
    {
        switch (c)
        {
        case 1000:
            return "M";
        case 2000:
            return "MM";
        case 3000:
            return "MMM";
        case 900:
            return "CM";
        case 800:
            return "DCCC";
        case 700:
            return "DCC";
        case 600:
            return "DC";
        case 500:
            return "D";
        case 400:
            return "CD";
        case 300:
            return "CCC";
        case 200:
            return "CC";
        case 100:
            return "C";
        case 90:
            return "XC";
        case 80:
            return "LXXX";
        case 70:
            return "LXX";
        case 60:
            return "LX";
        case 50:
            return "L";
        case 40:
            return "XL";
        case 30:
            return "XXX";
        case 20:
            return "XX";
        case 10:
            return "X";
        case 9:
            return "IX";
        case 8:
            return "VIII";
        case 7:
            return "VII";
        case 6:
            return "VI";
        case 5:
            return "V";
        case 4:
            return "IV";
        case 3:
            return "III";
        case 2:
            return "II";
        case 1:
            return "I";
        default:
            return "";
        }
    }
    string intToRoman(int num)
    {
        string roman;

        int thousands = (num / 1000) * 1000;
        num %= 1000;
        int hundreds = (num / 100) * 100;
        num %= 100;
        int tens = (num / 10) * 10;
        num %= 10;
        int single = num;

        roman += RoMaN(thousands);
        roman += RoMaN(hundreds);
        roman += RoMaN(tens);
        roman += RoMaN(single);
        return roman;
    }
};