#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
void ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
    if (n >= 10)
    {
        ft_putnbr_unsigned_fd(n / 10, fd);
        ft_putnbr_unsigned_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + '0', fd);    
}
void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
    }
    else if (n < 0)
    {
        write(fd, "-", 1);
        n *= -1;
        ft_putnbr_fd(n, fd);
    }
    else
    {
        if (n > 9)
        {
            ft_putnbr_fd(n / 10, fd);
            ft_putnbr_fd(n % 10, fd);
        }
        else
        {
            ft_putchar_fd(n + '0', fd);
        }
    }
}

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (s == NULL)
        return;
    while (s[i] != '\0')
    {
        write(fd, &s[i], 1);
        i++;
    }
}

int ft_numlen_base(unsigned long n, int base)
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
int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char *itoa_base(unsigned long n, char *base)
{
    char *str;
    int len_base;
    int digit_len;
    int index;

    len_base = strlen(base);
    digit_len = ft_numlen_base(n, len_base);
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
int print(const char *n, ...)
{
    va_list args;
    va_start(args, n);
    int i = 0;
    int count = 0;
    while (n[i])
    {
        if (n[i] == '%' && n[i + 1] == '%')
        {
            write(1, "%", 1);
            i+=2;
            count += 1;
        }
        else if (n[i] == '%' && n[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            if (!str)
                str = "(null)";
            ft_putstr_fd(str, 1);
            i+=2;
            count += strlen(str);
        }
        else if (n[i] == '%' && n[i + 1] == 'd')
        {
            int num = va_arg(args, int);
            ft_putnbr_fd(num, 1);
            i+=2;
            count += ft_numlen(num);
        }
        else if (n[i] == '%' && n[i + 1] == 'i')
        {
            int num = va_arg(args, int);
            ft_putnbr_fd(num, 1);
            i += 2;
            count += ft_numlen(num);
        }
        else if (n[i] == '%' && n[i + 1] == 'c')
        {
            char c = va_arg(args, int);
            ft_putchar_fd(c, 1);
            i+=2;
            count += 1;
        }
        else if (n[i] == '%' && n[i + 1] == 'u')
        {
            unsigned int u = va_arg(args, unsigned int);
            ft_putnbr_unsigned_fd(u, 1);
            count += ft_numlen_base(u, 10);
            i += 2;
        }
        else if (n[i] == '%' && n[i + 1] == 'p')
        {
            void *p = va_arg(args, void *);
            if (p == NULL)
            {
                write(1, "0x0", 3);
                count += 3;
            }
            else{
                char *hex = itoa_base((uintptr_t)p, "0123456789abcdef");
                write(1, "0x", 2);
                ft_putstr_fd(hex, 1);
                count += strlen(hex) + 2;
                free(hex);
            }
            i+=2;
        }
        else if (n[i] == '%' && n[i + 1] == 'x')
        {
            unsigned int x = va_arg(args, unsigned int);
            char *hex = itoa_base(x, "0123456789abcdef");
            ft_putstr_fd(hex, 1);
            count += strlen(hex);
            free(hex);
            i += 2;
        }
        else if (n[i] == '%' && n[i + 1] == 'X')
        {
            unsigned int x = va_arg(args, unsigned int);
            char *hex = itoa_base(x, "0123456789ABCDEF");
            ft_putstr_fd(hex, 1);
            count += strlen(hex);
            free(hex);
            i += 2;
        }
        else
        {
            write(1, &n[i], 1);
            count++;
            i++;
        }
    }
    va_end(args);
    return (count);
}
int main ()
{
    // int n = 42;
    // int *ptr = &n;
    // print("hello issa u'r family name is: %s\nand u'r age is: %d\nand the first letter of ur name is: %c\nand the pointer is: %p\nand %%\nand unsigned %u\nand xx %x\nand XX %X", "abe", 102, 'i', ptr, -10, 255, 255);
    // printf("%u\n", -40);
    int len = print("Hello %s, num=%d, hex=%x\n", "world", 42, 255);
    print("length printed %d\n", len);
}