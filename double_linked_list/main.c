#include "double_linked_circular_list.h"

#include <assert.h>

void test_push_back()
{
    printf("Test push_back (x10): ");
    double_linked_circular_list_t *list = double_linked_circular_list_create();
    for(int i = 0; i <= 10; i++)
        add(list, i);
    print(list);
}

void test_empty_list_print()
{
    printf("Test print empty list (x10): ");
    double_linked_circular_list_t *list = double_linked_circular_list_create();
    print(list);
}

void test_pop_back()
{
    printf("Test pop_back (x3): ");
    double_linked_circular_list_t *list = double_linked_circular_list_create();
    for(int i = 0; i <= 10; i++)
        add(list, i);
    for(int i = 0; i < 3; i++)
        pop_back(list);
    print(list);
}

void test_remove()
{
    printf("Test remove (10,5,7 index): \n");
    double_linked_circular_list_t *list = double_linked_circular_list_create();
    for(int i = 0; i <= 10; i++)
        add(list, i);

    print(list);
    pop_by_index(list, 10);
    print(list);
    pop_by_index(list, 5);
    print(list);
    pop_by_index(list, 7);
    print(list);
}

void test_pop()
{
    printf("Test pop (2, 3, 4, 5 value): \n");
    double_linked_circular_list_t *list = double_linked_circular_list_create();
    for(int i = 0; i <= 10; i++)
        add(list, i);
    pop(list, 2);
    pop(list, 3);
    pop(list, 4);
    pop(list, 5);

    print(list);
}

void test() {
    test_push_back();
    test_empty_list_print();
    test_pop_back();
    test_remove();
    test_pop();
}
int main(void) {
    test();
    return 0;
}