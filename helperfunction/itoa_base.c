char *itoa_base(unsigned long n, char *base)
{
    char *str;
    int len_base;
    int digit_len;
    int index;

    len_base = strlen(base);
    digit_len = ft_numlen(n, len_base);
    index = digit_len - 1;
    str = malloc(digit_len + 1);
    if (n == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    while (n != 0)
    {
        str[index] = base[n % len_base];
        n /= len_base;
        index--;
    }
    str[digit_len] = '\0';
    return str;
}