#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct list_t
{
    size_t size;
    size_t len;
    int* list;
} list_t;

void append(list_t* list, int item);
void rem(list_t* list, size_t index);
int pop(list_t* list, size_t index);
void print_list(list_t list);

int main(int argc, char const* argv[])
{
    list_t a;
    a.list = malloc(sizeof(int) * 3);
    a.list[0] = 5;
    a.list[1] = 10;
    a.list[2] = 15;
    a.size = sizeof(a.list);
    a.len = 3;

    append(&a, 20);
    int n = pop(&a, 1);
    rem(&a, 0);
    printf("removed %i\n", n);

    return 0;
}

void append(list_t *list, int item)
{   
    list->len++;
    int* new_list = realloc(list->list, (sizeof(int) * list->len));
    list->list = new_list;
    list->list[list->len - 1] = item;
}

void rem(list_t* list, size_t index)
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

int pop(list_t* list, size_t index)
{
    int value = list->list[index];
    rem(list, index);
    return value;
}

void print_list(list_t list)
{
    for (size_t i = 0; i < list.len; i++)
    {
        printf("%i\n", list.list[i]);
    }
}
