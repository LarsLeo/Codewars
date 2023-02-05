//https://www.codewars.com/kata/5659c6d896bc135c4c00021e/train/java

import java.util.Arrays;

public class NextSmallerNumberSameDigits
{
    public static long nextSmaller(long n)
    {
        if (n < 21) return -1;

        char[] stringChars = Long.toString(n).toCharArray();
        char currentLeadingNumChar = stringChars[0];
        Arrays.sort(stringChars);



        return -1;
    }
}