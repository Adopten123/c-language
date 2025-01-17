#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node_t {
    int data;
    struct node_t *next;
    struct node_t *prev;
} node_t;

typedef struct {
    node_t *head;
    size_t size;
} double_linked_circular_list_t;

double_linked_circular_list_t* double_linked_circular_list_create();
node_t* create_node(double_linked_circular_list_t* list, int data);
void add(double_linked_circular_list_t *list, int data);
void pop_back(double_linked_circular_list_t *list);
void pop(double_linked_circular_list_t *list, int value);
void pop_by_index(double_linked_circular_list_t *list, int index);
void print (double_linked_circular_list_t *list);