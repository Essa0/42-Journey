#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
int main(void)
{
    int len1, len2;
    int num1 = 0;
    int num2 = -123456789;
    int num = 42;
    char *str = "Hello, 42!";
    void *ptr = str;
    char *str1 = "Test string";
    char *str2 = NULL;
    unsigned int unum = 4294967295;
    unsigned int big_num = 4294967295U;

    void *ptr1 = str1;
    void *ptr2 = NULL;

    ft_printf("===== HARD TESTS =====\n\n");

    len1 = ft_printf("Char A: %c | Char Z: %c | Null char: %c\n", 'A', 'Z', '\0');
    len2 = printf("Char A: %c | Char Z: %c | Null char: %c\n", 'A', 'Z', '\0');
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("String1: %s | String2 (NULL): %s | Empty: %s\n", str1, str2, "");
    len2 = printf("String1: %s | String2 (NULL): %s | Empty: %s\n", str1, str2, "");
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("Int0: %d | IntMax: %d | IntMin: %d | Neg: %i\n", num1, INT_MAX, INT_MIN, num2);
    len2 = printf("Int0: %d | IntMax: %d | IntMin: %d | Neg: %i\n", num1, INT_MAX, INT_MIN, num2);
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("Unsigned0: %u | UINT_MAX: %u\n", 0, unum);
    len2 = printf("Unsigned0: %u | UINT_MAX: %u\n", 0, unum);
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("Hex0: %x | HexMax: %x | HexUpper: %X\n", 0, unum, unum);
    len2 = printf("Hex0: %x | HexMax: %x | HexUpper: %X\n", 0, unum, unum);
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("Pointer normal: %p | Pointer NULL: %p\n", ptr1, ptr2);
    len2 = printf("Pointer normal: %p | Pointer NULL: %p\n", ptr1, ptr2);
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("Percent signs: %% %% %% %% %%\n");
    len2 = printf("Percent signs: %% %% %% %% %%\n");
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf(
        "Combined: char %c, string %s, int %d, unsigned %u, hex %X, ptr %p, %%\n",
        'Q', str1, -42, big_num, 305419896, ptr1
    );
    len2 = printf(
        "Combined: char %c, string %s, int %d, unsigned %u, hex %X, ptr %p, %%\n",
        'Q', str1, -42, big_num, 305419896, ptr1
    );
    ft_printf("ft_printf: %d chars | printf: %d chars\n\n", len1, len2);

    len1 = ft_printf("Char test: %c\n", 'A');
    len2 = printf("Char test: %c\n", 'A');
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("String test: %s\n", str);
    len2 = printf("String test: %s\n", str);
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("Int test: %d\n", num);
    len2 = printf("Int test: %d\n", num);
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("Unsigned test: %u\n", unum);
    len2 = printf("Unsigned test: %u\n", unum);
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("Hex lowercase: %x\n", unum);
    len2 = printf("Hex lowercase: %x\n", unum);
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("Hex uppercase: %X\n", unum);
    len2 = printf("Hex uppercase: %X\n", unum);
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("Pointer test: %p\n", ptr);
    len2 = printf("Pointer test: %p\n", ptr);
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n\n", len1, len2);

    len1 = ft_printf("Percent test: %%\n");
    len2 = printf("Percent test: %%\n");
    ft_printf("ft_printf printed %d chars, printf printed %d chars\n", len1, len2);

    return 0;


}