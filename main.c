/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include <stdlib.h>
#include "include/push_swap.h"
#include "include/my.h"

void sort_start(int *array, int size, char operation_name[6])
{
    int swap = check_end(array, size, 1);

    my_putstr(operation_name);
    if (swap == 0)
        return;
    if (my_strlen(operation_name) != 0)
        my_putchar(' ');
    if (array[0] == find_biggest_number(array, size)) {
        rotate_left(array, size);
        my_strcpy(operation_name, "ra");
    } else if (array[0] > array[1]) {
        swap_elem(array, 0, 1);
        rotate_left(array, size);
        my_strcpy(operation_name, "sa ra");
    } else {
        rotate_left(array, size);
        my_strcpy(operation_name, "ra");
    }
    sort_start(array, size, operation_name);
    return;
}

int check_validity(char *ag)
{
    if (ag[0] == '-')
        ag++;
    for (int j = 0; ag[j] != '\0'; j++) {
        if (ag[j] < '0' || ag[j] > '9')
            return (84);
    }
    return (0);
}

int main(int ac, char **ag)
{
    int *array = malloc(sizeof(int) * (ac - 1));
    char operation_name[6] = "\0";
    int error = 0;

    if (ac > 500)
        return (0);
    for (int i = 1; i < ac; i++) {
        error = check_validity(ag[i]);
        if (error == 84)
            return (84);
    }
    for (int i = 1; i < ac; i++)
        array[i - 1] = my_getnbr(ag[i]);
    sort_start(array, ac - 1, operation_name);
    my_putchar('\n');
    free(array);
    return (0);
}
