/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for main node (stores unique word details)
typedef struct mainnode
{
    char word[50];                 // Word stored in database
    int file_count;                // Number of files containing the word
    struct subnode *sublink;       // Link to sub node list
    struct mainnode *mainlink;     // Link to next main node
} Mainnode;

// Structure for sub node (stores file-wise word count)
typedef struct subnode
{
    char filename[50];             // File name
    int word_count;                // Word occurrence count in file
    struct subnode *link;          // Link to next sub node
} Subnode;

// Structure for file linked list
typedef struct node
{
    char filename[50];             // File name
    struct node *link;             // Link to next file
} Slist;

// Structure for hash table
typedef struct hash
{
    int index;                     // Hash index
    struct mainnode *link;         // Link to main node list
} hash_t;

// Enum for function return status
typedef enum
{
    Success = 1,                   // Operation successful
    Failure = 0                    // Operation failed
} Status;

// Function prototypes
Status validate_arguments(int argc, char *argv[], Slist **head);
void create_database(hash_t *arr, Slist **head);
void display_database(hash_t *arr);
void search_database(hash_t *arr);
void save_database(hash_t *arr);
void create_HT(hash_t *arr);
void update_database(hash_t *arr, Slist **head);
void remove_duplicates(Slist **head);
#endif
