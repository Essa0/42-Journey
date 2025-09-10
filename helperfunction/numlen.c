int ft_numlen(unsigned long n, int base)
{
    int len;

    len = 0;
    while (n)
    {
        n /= base;
        len++;
    }
    return (len);
}
