//Michael Granberry
//COMP 322 - Spring 2023
//Process Creation Hierarchy

#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct node {
    int id;
    struct node *next;
}; typedef struct node linked_list;


struct pcb {
    int parent;
    linked_list *children;
}; typedef struct pcb pcb_type;

pcb_type *pcb_array[MAX_PROCESSES]; // array of pcb_type pointers.

/* Define structures and global constants, including:
the pcb type, the children linked list type, the maximum number of processes*/

/***************************************************************/
void procedure_to_print_hierarchy_of_processes(void) {
    /* declare local vars */
    int i;
    linked_list* current_child;
    /* for each process index i from 0 up to (but not including) maximum number of processes*/
    for (i=0; i< (MAX_PROCESSES); i++){
        /* if PCB[i] is not NULL */
        if (pcb_array[i] != NULL) {
            /* print process id, parent id, list of children processes */
            printf("Process id: %d\n", i);
            printf("Parent process: %d\n", pcb_array[i]->parent);
            //children
            current_child = pcb_array[i]->children;
            while (current_child != NULL) {
                printf("/tChild Process: %d\n", current_child->id);
                current_child = current_child->next;
            } //while
        } //if
    } //for
} /* end of procedure */


/***************************************************************/
void initialize_process_hierarchy(void) { // 1
    /* declare local vars */
    int i;

    /* Allocate memory for PCB[0] */
//    pcb_array[0] = (pcb_type *)mallac(sizeof(pcb_type) * 1);
    pcb_type *pcbPtr; // pcb_type pointer.
    pcbPtr = (pcb_type*)malloc(sizeof(pcb_type)*1); // allocating memory for one pcb_type.
    pcb_array[0] = pcbPtr; // pointing first element to allocated memory
    pcb_array[0]->parent = 0;
    pcb_array[0]->children = NULL;

    /* Intitialize all other PCB's to NULL */
    for( i=1; i<MAX_PROCESSES; i++) {
        pcb_array[i] = NULL;
    }
    /* print hierarchy of processes */
    procedure_to_print_hierarchy_of_processes();
    return;
} /* end of procedure */


/***************************************************************/
void create_a_new_child_process() { // 2
    /* define local vars */
    /* prompt for parent process index p */
    /* if PCB[p] is NULL, print message process does not exist, return */
    /* search for first available index q without a parent in a while loop */
    /* if maximum number of processes reached, print message of no more avaiable PCBs */
    /* allocate memory for new child process, initialize fields */
    /* record the parent's index p in PCB[q] */
    /* initialize the list of children of PCB[q] as empty */
    /* append the node containing the child's index q to the children linked list of PCB[p] */
    /* print hierarchy of processes */
    return;
} /* end of procedure */


/***************************************************************/
void recursive_procedure_to_destroy_children_processes(parameter) {
    /* declare local vars */
    /* check if end of linked list--if so return */
    /* else call self on next node in linked list */
    /* set variable q to current node's process index field */
    /* call self on children of PCB[q] */
    /* free memory of PCB[q] and set PCB[q] to NULL*/
    /* free memory of paramter and set to NULL */
    return;
} /* end of procedure */


/***************************************************************/
void destroy_all_descendants_of_a_parent_process(void) { // 3
    /* declare local vars */
    /* prompt for process index p */
    /* call recursive procedure to destroy children of PCB[p] */
    /* reset children of PCB[p] to NULL */
    /* print hierarchy of processes */
    return;
} /* end of procedure */


/***************************************************************/
void quit_program_and_free_memory(void) { // 4
    /* if PCB[0] is non null)
        /* if children of PCB[0] is not null */
    /* call recursive procedure to destroy children of PCB[0] */
    /* free memory of all PCB's */
    return;
} /* end of procedure */


// Menu
void menu(void) {
    int sel = -1;
    do {
        printf("\n=============== MENU ===============\n");
        printf("1) Initialize process hierarchy.\n");
        printf("2) Create a new child process.\n");
        printf("3) Destroy all descendants of a parent process.\n");
        printf("4) Quit program and free memory.\n");
        printf("Select a number 1 through 4: ");

        scanf("%d", &sel);
        switch (sel) {
            case 1:
                printf("1) Initialize process hierarchy.\n");
                //func
                initialize_process_hierarchy();
                break;
            case 2:
                printf("2) Create a new child process.\n");
                //func
                create_a_new_child_process();
                break;
            case 3:
                printf("3) Destroy all descendants of a parent process.\n");
                //func
                destroy_all_descendants_of_a_parent_process();
                break;
            case 4:
                printf("4) Quit program and free memory.\n");
                //func
                quit_program_and_free_memory();
                break;
            default:
                printf("Invalid Choice.\n");
        }
    } while (sel != 4);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    menu();
    return 1;
}
