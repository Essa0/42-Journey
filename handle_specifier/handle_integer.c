#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void handle_integer(va_list args)
{
    int num = va_arg(args, int);
    ft_putnbr_fd(num, 1);
    i += 2;
}