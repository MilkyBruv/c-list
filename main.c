#include <stdio.h>
#include "list.h"

int custom_sort(list_t* list, int n, int i);

int main(int argc, char const* argv[])
{
    list_t a = create_list(5);
    a.list[0] = 5;
    a.list[1] = 20;
    a.list[2] = 25;
    a.list[3] = 10;
    a.list[4] = 15;
    print_list(a);
    printf("\n");

    set_list_index(&a, 0, 30);
    append_list(&a, 5);
    print_list(a);
    printf("\n");

    int array[5] = {0, 2, 4, 6, 8};
    fill_list_with_array(&a, array);
    print_list(a);
    printf("\n");

    sort_list(&a, NULL);
    print_list(a);
    printf("\n");

    sort_list(&a, &custom_sort);
    print_list(a);
    printf("\n");

    return 0;
}

int custom_sort(list_t* list, int n, int i)
{
    return n - 10;
}
