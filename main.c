#include <stdio.h>
#include "list.h"

int main(int argc, char const* argv[])
{
    list_t a = create_list(5);

    append_list(&a, 20);
    print_list(a);
    printf("\n");
    int n = pop_list(&a, 1);
    print_list(a);
    printf("\n");
    remove_list_index(&a, 0);
    print_list(a);
    printf("\n");

    return 0;
}
