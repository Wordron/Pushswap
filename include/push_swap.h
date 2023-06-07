/*
** EPITECH PROJECT, 2022
** push_swap.h
** File description:
** push_swap
*/

#ifndef PUSH_SWAP_H_
    #define PUSH_SWAP_H_

    void swap_elem(int *array, int index1, int index2);
    void rotate_left(int *array, int size);
    void rotate_right(int *array, int size);
    int check_end(int *array, int size, int jump);
    int find_smallest_number(int *array, int size);
    int find_biggest_number(int *array, int size);

    void start_the_swap_two_by_two(int *array, int size, int end);

#endif /* !PUSH_SWAP_H_ */
