#include "list.h"

list_t create_list(size_t initial_length)
{
    list_t list;
    list.len = initial_length;
    list.list = malloc(sizeof(int) * initial_length);

    for (size_t i = 0; i < initial_length; i++) { list.list[i] = 0; }

    return list;
}

list_t create_list_from_array(int array[])
{
    list_t list = create_list(sizeof(*array) / sizeof(int));
    fill_list_with_array(&list, array);

    return list;
}

void append_list(list_t* list, int item)
{   
    list->len++;
    int* new_list = realloc(list->list, (sizeof(int) * list->len));
    list->list = new_list;
    list->list[list->len - 1] = item;
}

void remove_list_index(list_t* list, size_t index)
{
    list->len--;
    int* new_list = malloc(sizeof(int) * list->len);

    for (size_t i = 0; i < list->len; i++)
    {
        if (i >= index) { new_list[i] = list->list[i + 1]; }
        else { new_list[i] = list->list[i]; }
    }
    
    free(list->list);
    list->list = new_list;
}

void set_list_index(list_t* list, size_t index, int value)
{
    list->list[index] = value;
}

int pop_list(list_t* list, size_t index)
{
    int value = list->list[index];
    remove_list_index(list, index);

    return value;
}

void fill_list(list_t* list, int value)
{
    for (size_t i = 0; i < list->len; i++) { list->list[i] = value; }
}

void fill_list_with_array(list_t* list, int array[])
{
    for (size_t i = 0; i < list->len; i++) { list->list[i] = array[i]; }
}

void clear_list(list_t* list)
{
    list->len = 0;
    free(list->list);
}

void sort_list(list_t* list, int (*sort_callback)(list_t*, int, int))
{
    if (sort_callback != NULL)
    {
        for (size_t i = 0; i < list->len; i++)
        {
            list->list[i] = sort_callback(list, list->list[i], i);
        }
    }
    else
    {
        size_t j = 1;
        size_t temp_left, temp_right;

        for (size_t i = 0; i < list->len; i++)
        {
            j = 1;

            for (size_t i = 0; i < list->len - 1; i++, j++)
            {
                temp_left = list->list[i];
                temp_right = list->list[j];

                if (list->list[i] > list->list[j])
                {
                    list->list[i] = temp_right;
                    list->list[j] = temp_left;
                }
            }
        }
    }
}

void print_list(list_t list)
{
    for (size_t i = 0; i < list.len; i++) { printf("%i\n", list.list[i]); }
}
