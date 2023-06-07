/*
** EPITECH PROJECT, 2022
** sort_two_by_two.c
** File description:
** swap_two_by_two
*/
#include "include/push_swap.h"
#include "include/my.h"

int swap_two_by_two(int *array, int size, int end)
{
    if (end != 0 && array[0] > array[1]) {
        swap_elem(array, 0, 1);
        rotate_left(array, size);
        rotate_left(array, size);
        my_putstr("sa ra ra");
        end--;
        return (end);
    }
    if (end != 0 && array[0] <= array[1]) {
        rotate_left(array, size);
        rotate_left(array, size);
        my_putstr("ra ra");
        end--;
        return (end);
    }
    if (end <= 0 && (size % 2) == 1) {
        rotate_left(array, size);
        my_putstr("ra");
        end--;
        return (0);
    }
    return (0);
}

void start_the_swap_two_by_two(int *array, int size, int end)
{
    int swap = check_end(array, size, 2);

    if (swap == 0)
        return;
    end = swap_two_by_two(array, size, end);
    start_the_swap_two_by_two(array, size, end);
    return;
}
