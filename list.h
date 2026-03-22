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
void append_list(list_t* list, int item);
void remove_list_index(list_t* list, size_t index);
int pop_list(list_t* list, size_t index);
void fill_list(list_t* list, int value);
void clear_list(list_t* list);
void sort(list_t* list, int (*sort_callback)(int));
void print_list(list_t list);

#endif