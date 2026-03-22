#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct list_t
{
    size_t len;
    int* list;
} list_t;

list_t create_list(size_t initial_length);
list_t create_list_from_array(int array[]);
void append_list(list_t* list, int value);
void remove_list_index(list_t* list, size_t index);
void set_list_index(list_t* list, size_t index, int value);
int pop_list(list_t* list, size_t index);
void fill_list(list_t* list, int value);
void fill_list_with_array(list_t* list, int array[]);
void clear_list(list_t* list);
void sort_list(list_t* list, int (*sort_callback)(list_t*, int, int));
void print_list(list_t list);

#endif