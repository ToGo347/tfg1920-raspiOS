/**
 * This library contains a linked list
 * defined with macros.
 *
 * Obtained in 
 * https://github.com/jsandler18/raspi-kernel/tree/bd5026277370360fb04f04f5b050c6853466c86d
 *  
 * Raúl Sánchez Montaño
 * 
 * Dic 16, 2019
 */



#ifndef LIST_H
#define LIST_H

#define DEFINE_LIST(nodeType)                                                       \
typedef struct nodeType##list {     \
    struct nodeType * head;         \
    struct nodeType * tail;         \
    uint32_t size;                  \
} nodeType##_list_t;

#define DEFINE_LINK(nodeType)       \
struct nodeType * next##nodeType;   \
struct nodeType * prev##nodeType;

#define INITIALIZE_LIST(list)           \
    list.head = list.tail = (void *)0;  \
    list.size = 0;

#define IMPLEMENT_LIST(nodeType)                                                    \
void append_##nodeType##_list(nodeType##_list_t * list, struct nodeType * node) {   \
    list->tail->next##nodeType = node;                                              \
    node->prev##nodeType = list->tail;                                              \
    list->tail = node;                                                              \
    node->next##nodeType = NULL;                                                    \
    list->size += 1;                                                                \
}                                                                                   \
                                                                                    \
void push_##nodeType##_list(nodeType##_list_t * list, struct nodeType * node) {     \
    node->next##nodeType = list->head;                                              \
    node->prev##nodeType = NULL;                                                    \
    list->head = node;                                                              \
    list->size += 1;                                                                \
}                                                                                   \
                                                                                    \
struct nodeType * peek_##nodeType##_list(nodeType##_list_t * list) {                \
    return list->head;                                                              \
}                                                                                   \
                                                                                    \
struct nodeType * pop_##nodeType##_list(nodeType##_list_t * list) {                 \
    struct nodeType * res = list->head;                                             \
    list->head = list->head->next##nodeType;                                        \
    list->head->prev##nodeType = NULL;                                              \
    list->size -= 1;                                                                \
    return res;                                                                     \
}                                                                                   \
                                                                                    \
uint32_t size_##nodeType##_list(nodeType##_list_t * list) {                         \
    return list->size;                                                              \
}                                                                                   \
                                                                                    \
struct nodeType * next_##nodeType##_list(struct nodeType * node) {                  \
    return node->next##nodeType;                                                    \
}                                                                                   \

#endif