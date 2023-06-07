/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int negative = 1;

    if (str[0] == '-') {
        i = 1;
        negative = -1;
    }
    for (; str[i] != '\0' || str[i] >= '0' && str[i] <= '9'; i++)
        nb = (nb * 10 + (str[i] - 48));
    nb = nb * negative;
    return (nb);
}
