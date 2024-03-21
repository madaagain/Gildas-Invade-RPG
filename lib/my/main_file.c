/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** only file
*/

#include "my.h"
#include <stdarg.h>

int my_printf(char *s, ...)
{
    va_list ap;
    int arg_nb = 0;

    va_start(ap, s);
    arg_nb = write_s(s, ap);
    va_end(ap);
    return arg_nb;
}

int write_s(char *s, va_list ap)
{
    int count = 0;
    check_flags_t *flags = malloc(sizeof (check_flags_t));

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '%' && check_flags_order(s, i + 1)) {
            i++;
            flags_reset(flags);
            i = what_flags(flags, s, i, count);
            get_star(flags, ap);
            count += assign_function(ap, flags);
        } else {
            my_putchar(s[i]);
            count += 1;
        }
    }
    free(flags);
    return count;
}

int assign_function(va_list ap, check_flags_t *flag)
{
    char *flags = "scid%xXoupbSfFnEeaAGg";
    int (*fptr []) (va_list ap, check_flags_t *flags) = {&wrapper_my_putstr,
    &wrapper_my_putchar, &wrapper_my_put_nbr, &wrapper_my_put_nbr,
    &my_print_percent, &wrapper_my_put_nbr_hexa, &wrapper_my_put_nbr_hexa_m,
    &wrapper_my_put_nbr_octal, &wrapper_my_put_nbr_unsigned_int,
    &wrapper_print_pointer, &wrapper_my_put_b, &wrapper_print_non_printable,
    &wrapper_float, &wrapper_float, &wrapper_point, &wrapper_notation_big,
    &wrapper_notation, &wrapper_put_hexa_float, &wrapper_put_hexa_float,
    &wrapper_put_big_g, &wrapper_put_g};

    for (int i = 0; flags[i] != '\0'; ++i)
        if (flags[i] == flag->flag)
            return fptr[i](ap, flag);
    return 0;
}

int my_print_percent(va_list ap, check_flags_t *flags)
{
    (void) flags;
    (void) ap;
    write(1, "%", 1);
    return 1;
}
