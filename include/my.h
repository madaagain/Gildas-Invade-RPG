/*
** EPITECH PROJECT, 2022
** myh
** File description:
** myh
*/

#ifndef myh
    #define myh

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>

    typedef struct check_flags {
        int hash;
        int minus;
        int plus;
        int zero;
        int empty;
        int max;
        int min;
        int precison;
        char flag;
        int count;
        int min_star;
        int max_star;
        char conversion;
    } check_flags_t;

    typedef union bit_float {
        float f;
        unsigned int a;
    } bit_float_t;

    typedef union int_len {
        short int shorty;
        char chary;
        long int longy;
        long long int long_longy;
        int inty;
        size_t sizy;
        __uintmax_t maxy;
    }   int_len_t;

    char **my_str_to_word_array_sep(char const *str, char delim);
    int my_array_len(char *const *array);
    int get_arg_number(char *str);
    int my_reverse_nbr(int nb);
    int my_compute_power_rec(long int nb , int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char **str);
    int my_is_prime(int nb);
    int my_isneg(int nb);
    long long int my_put_nbr(long long int nb);
    int my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    void my_sort_int_array(int *tab, int size);
    int my_str_isalpha(char const *str);
    int my_isalpha(char c);
    int my_str_islower(char const *str);
    int my_islower(char c);
    int my_str_isnum(char const *str);
    int my_isnum(char c);
    int my_str_isprintable(char const *str);
    int my_isprintable(char c);
    int my_str_isupper(char const *str);
    int my_isupper(char c);
    void free_my_array(char **array);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_strcmp2(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strncpy2(char *dest, char const *src, int n);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    int my_show_word_array(char * const *tab);
    char *my_strdup(char const *src);
    char **my_str_to_word_array(char const *str);
    int count_letter(char const *str, char c);
    int error_handling(int argc, char ** argv);
    int get_letter_count(char const *str);
    void print_result(char letter, int frequency, int count);
    char *comparativetable(char *str);
    void print_float(int frequency);
    int assign_function(va_list ap, check_flags_t *flags);
    int wrapper_my_put_nbr(va_list ap, check_flags_t *flags);
    int wrapper_my_put_nbr_hexa(va_list ap, check_flags_t *flags);
    int wrapper_my_put_nbr_hexa_m(va_list ap, check_flags_t *flags);
    int wrapper_my_put_nbr_octal(va_list ap, check_flags_t *flags);
    int wrapper_my_put_nbr_unsigned_int(va_list ap, check_flags_t *flags);
    int wrapper_my_putstr(va_list ap, check_flags_t *flags);
    int wrapper_my_putchar(va_list ap, check_flags_t *flags);
    int write_s(char *s, va_list ap);
    int my_print_percent(va_list ap, check_flags_t *flags);
    int my_printf(char *s, ...);
    long long int my_put_nbr_base(long long int nb, char *base);
    int my_nb_len(long long int nb);
    int check_flags_order(char *format, int i);
    int my_nb_len_base(long long int nb, char *str);
    int what_flags(check_flags_t *flags, char *str, int i, int count);
    void flags_reset(check_flags_t *flags);
    int wrapper_my_put_b(va_list ap, check_flags_t *flags);
    int my_print_non_printable(char *str);
    int wrapper_print_non_printable(va_list ap, check_flags_t *flags);
    void do_hex_hash(long long int nb, check_flags_t *flags);
    void do_hex_hash_maj(long long int nb, check_flags_t *flags);
    void do_oct_hash(long long int nb, check_flags_t *flags);
    void do_empty_int(long long int nb, check_flags_t *flags);
    int my_put_float(double nb, int pow);
    char what_pad(check_flags_t *flags);
    void print_pads(char c, int diff);
    int is_flag(char c);
    int do_empty_len(long long int nb, check_flags_t *flags);
    int do_oct_len(long long int nb, check_flags_t *flags);
    int do_hex_len(long long int nb, check_flags_t *flags);
    int count_with_precision(check_flags_t *flags,
    long long int nb, char *base, int count);
    int precision_str(char *str, char *cpy, int count,
    check_flags_t *flags);
    void pad_number(check_flags_t *flags, int count);
    int wrapper_print_pointer(va_list ap, check_flags_t *flags);
    int wrapper_float(va_list ap, check_flags_t *flags);
    int scientific_notation_big_e(double nb, int pow);
    int scientific_notation_e(double nb, int pow);
    int my_get_exponent(double nb);
    int my_put_g(double nb);
    int my_put_big_g(double nb);
    int wrapper_point(va_list ap, check_flags_t *flags);
    void get_star(check_flags_t *flags, va_list ap);
    int wrapper_notation_big(va_list ap, check_flags_t *flags);
    int wrapper_notation(va_list ap, check_flags_t *flags);
    int count_with_precision_decimal(check_flags_t *flags,
    long long int nb, int count);
    int wrapper_put_hexa_float(va_list ap, check_flags_t *flags);
    int my_put_hexa_float(long double nb);
    int my_put_point(long double nb);
    int do_my_put_nbr(long long int nb, check_flags_t *flags);
    int is_length_modifier(char c, int order);
    int get_specifier(int i, char *str, check_flags_t *flags);
    int scientific_notation_g(double nb, int pow);
    int my_put_float_g(double nb, int pow);
    int my_display_e_second(long int e, long int e_sign);
    double my_check_negative(double nb, int *ret);
    double my_round_float(double *d_part, long long int *w_part);
    int display_float_g(int pow, long int w, double d);
    int my_display_big_e_second(long int e, long int e_sign);
    int my_displays_big_g(long int e, double nb, long int e_sign, int pow);
    int scientific_notation_big_g(double nb, int pow);
    int wrapper_put_big_g(va_list ap, check_flags_t *flags);
    int wrapper_put_g(va_list ap, check_flags_t *flags);
    void free_array(char **array, char *line);
#endif /* !myh */
