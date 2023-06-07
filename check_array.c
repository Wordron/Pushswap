/*
** EPITECH PROJECT, 2022
** check_end.c
** File description:
** check_end
*/

int find_smallest_number(int *array, int size)
{
    int smallest = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] < smallest)
            smallest = array[i];
    }
    return (smallest);
}

int find_biggest_number(int *array, int size)
{
    int biggest = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > biggest)
            biggest = array[i];
    }
    return (biggest);
}

int check_end(int *array, int size, int jump)
{
    int swap = 0;

    for (int i = 0; i < size - 1; i += jump) {
        if (i < size - 1 && array[i] > array[i + 1])
            return (84);
    }
    return (0);
}
