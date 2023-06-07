/*
** EPITECH PROJECT, 2022
** my_amazing_sorter.c
** File description:
** sort an array of a given size
*/
#include <stdlib.h>
#include "include/push_swap.h"
#include "include/my.h"
/*
int swap_one_by_one(int *array, int size, int end, int *nb_operation)
{
    if (end != 0 && array[0] > array[1]) {
        swap_elem(array, 0, 1);
        rotate_left(array, size);
        my_putstr("sa ra");
        end--;
        nb_operation[0] += 2;
        return (end);
    }
    if (end != 0 && array[0] <= array[1]) {
        rotate_left(array, size);
        my_putstr("ra");
        end--;
        nb_operation[0]++;
        return (end);
    }
    return (0);
}

void start_the_swap_one_by_one(int *array, int size, int end, int *nb_operation)
{
//how to stop
    if (end == 0)
        return;
//
    if (end != 0 && nb_operation[0] != 0)
        my_putchar(' ');
    end = swap_one_by_one(array, size, end, nb_operation);
    start_the_swap_one_by_one(array, size, end, nb_operation);
    return;
}
*/

/*
rotate_right :
        rotate_right(array, size);
        my_putstr("rra");

rotate_left :
        rotate_left(array, size);
        my_putstr("ra ");

swap :
        swap_elem(array, 0, 1);
        my_putstr("sa ");
*/

void sort_array(int *array, int size)
{
    if (array[0] > array[1]) {
        swap_elem(array, 0, 1);
        my_putstr("sa");
    } else {
        rotate_right(array, size);
        my_putstr("rra");
    }
}

void start_sort(int *array, int size)
{
    int biggest_nb = find_biggest_number(array, size);
    int smallest_nb = find_smallest_number(array, size);

    if (array[0] == smallest_nb && array[size] == biggest_nb)
        return;
    sort_array(array, size);
    start_sort(array, size);
}

//

int swap_two_by_two(int *array, int size, int end, int *nb_operation)
{
    if (end != 0 && array[0] > array[1]) {
        swap_elem(array, 0, 1);
        rotate_left(array, size);
        rotate_left(array, size);
        my_putstr("sa ra ra"); //still spaces at the end
        end--;
        nb_operation[0] += 3;
        return (end);
    }
    if (end != 0 && array[0] <= array[1]) {
        rotate_left(array, size);
        rotate_left(array, size);
        my_putstr("ra ra");
        end--;
        nb_operation[0] += 2;
        return (end);
    }
    if (end <= 0 && (size % 2) == 1) {
        rotate_left(array, size);
        my_putstr("ra ");
        nb_operation[0]++;
        end--;
        return (0);
    }
    return (0);
}

void start_the_swap_two_by_two(int *array, int size, int end, int *nb_operation)
{
    int swap = check_end(array, size, 2);

    if (swap == 0)
        return;
    if (swap == 84 && nb_operation[0] != 0)
        my_putchar(' ');
    end = swap_two_by_two(array, size, end, nb_operation);
    start_the_swap_two_by_two(array, size, end, nb_operation);
    return;
}

//

void my_amazing_sorter(int *array, int size, int *nb_operation)
{
    int swap = check_end(array, size, 1);

    if (swap == 0)
        return;
    if (swap == 84 && nb_operation[0] != 0) {
        rotate_left(array, size);
        my_putstr("ra");
    }
    start_the_swap_two_by_two(array, size, size / 2, nb_operation);
    //swap = check_end(array, size, 1);
    //if (swap == 0)
    //    return;
    //start_sort(array, size);
    //start_the_swap_one_by_one(array, size, size, nb_operation);

    //my_putchar('\n');
    //for (int i = 0; i < size; i++)
    //    my_put_nbr(array[i]);
    my_amazing_sorter(array, size, nb_operation);
    return;
}

void main(int ac, char **ag)
{
    int *array = malloc(sizeof(int) * (ac - 1));
    int *nb_operation = malloc(sizeof(int));

    nb_operation[0] = 0;
    for (int i = 1; i < ac; i++)
        array[i - 1] = my_getnbr(ag[i]);
    my_amazing_sorter(array, ac - 1, nb_operation);
    my_putchar('\n');

    for (int i = 1; i < ac; i++)
        my_put_nbr(array[i - 1]);
    my_putchar('\n');

    free(array);
    free(nb_operation);
}
