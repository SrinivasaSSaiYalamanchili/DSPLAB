#include <stdio.h>
#include <string.h>

int longestPalSubstr(char* str)
{

    // The result (length of LPS)
    int maxLength = 1;

    int start = 0;
    int len = strlen(str);

    int low, high;

    // One by one consider every character as center point of even and length palindromes
    for (int i = 1; i < len; ++i) {
        // Find the longest even length palindrome.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            --low;
            ++high;
        }

          // Move back to the last possible valid palindrom substring
        ++low; --high;
          if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
              maxLength = high - low + 1;
        }

        // Find the longest odd length palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            --low;
            ++high;
        }

          // Move back to the last possible valid palindrom substring
        ++low; --high;
          if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
              maxLength = high - low + 1;
        }
    }

    printf("Longest palindrome substring is: ");
    for (int i = start; i <= start + maxLength - 1; ++i)
        printf("%c", str[i]);
}

int main()
{
    char str[50];
    printf("Enter a String\n");
    scanf("%s",str);
    longestPalSubstr(str);
    return 0;
}
