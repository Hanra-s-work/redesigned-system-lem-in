/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** linked_lists.h
*/

#ifndef LINKED_LISTS_H_
    #define LINKED_LISTS_H_

typedef enum data_type_e {
    INT,
    VOID,
    CHAR,
    FLOAT,
    STRUCT,
    STRING,
    UNKNOWN,
    INT_ARRAY,
    FLOAT_ARRAY,
    END_OF_LINKED_LIST
} data_type_e;

typedef enum struct_name_e {
    ROOMS,
    TUNNELS,
    OTHER,
    NONE,
} struct_name_e;

struct linked_lists_s {
    int index;
    void *data;
    struct_name_e struct_name;
    data_type_e type;
    struct linked_lists_s *prev;
    struct linked_lists_s *next;
};

typedef struct linked_lists_s linked_lists_t;
typedef struct linked_lists_s llists_t;

linked_lists_t *get_last_node(linked_lists_t *ll);
linked_lists_t *init_list(void *data, data_type_e dt, struct_name_e sn);
linked_lists_t *free_node(linked_lists_t *ll, int index);
linked_lists_t *get_node(linked_lists_t *ll, int node_index);
data_type_e get_node_type(linked_lists_t *ll, int data_index);

void free_linked_list(linked_lists_t *ll);
void *get_node_data(linked_lists_t *ll, int data_index);

int get_list_size(linked_lists_t *ll);
int get_last_node_index(linked_lists_t *ll);
int append(linked_lists_t *ll, void *data, data_type_e type, struct_name_e sn);

#endif
