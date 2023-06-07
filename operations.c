/*
** EPITECH PROJECT, 2022
** operations.c
** File description:
** operations
*/

void swap_elem(int *array, int index1, int index2)
{
    int temp;

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void rotate_left(int *array, int size)
{
    int temp = array[0];

    for (int i = 1; i < size; i++)
        array[i - 1] = array[i];
    array[size - 1] = temp;
}

void rotate_right(int *array, int size)
{
    int temp = array[size - 1];

    for (int i = size - 1; i > 0; i--)
        array[i] = array[i - 1];
    array[0] = temp;
}
