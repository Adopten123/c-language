#include "double_linked_circular_list.h"

double_linked_circular_list_t* double_linked_circular_list_create(){
    double_linked_circular_list_t *list = (double_linked_circular_list_t *)malloc(sizeof(double_linked_circular_list_t));

    list->head = NULL;
    list->size = 0;

    return list;
}

node_t* create_node(double_linked_circular_list_t* list, int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

void add(double_linked_circular_list_t* list, int data)
{
    node_t *new_node = create_node(list, data);

    if (list->head == NULL)
        list->head = new_node;

    new_node->next = list->head;
    new_node->prev = list->head->prev;

    list->head->prev->next = new_node;
    list->head->prev = new_node;
    ++list->size;
}

void pop_back(double_linked_circular_list_t* list)
{
    if(list->head == NULL)
        return;

    node_t *tail = list->head->prev;
    list->head->prev = tail->prev;
    tail->prev->next = list->head;
    free(tail);
    --list->size;
}

void pop(double_linked_circular_list_t* list, int value)
{
    node_t* current = list->head;
    do{
        if(current->data == value) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        else {
            current = current->next;
        }
    } while(current != list->head);
}

void pop_by_index(double_linked_circular_list_t *list, int index)
{
      if(list->size <= index)
          return;

      node_t *current = list->head;

      for(int i = 0; i != index; ++i)
          current = current->next;

      current->prev->next = current->next;
      current->next->prev = current->prev;
      free(current);
      --list->size;
}

void print(double_linked_circular_list_t* list){
    char* buffer;
    if (list->head == NULL){
        printf("List is empty\n");
        return;
    }
    node_t* current = list->head;
    do{
        printf("%d ", current->data);
        current = current->next;
    } while(current != list->head);
    printf("\n");
}