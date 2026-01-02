/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/
#include "inverted_search.h"

// Main function
int main(int argc, char *argv[])
{
    hash_t arr[28];          // Hash table
    Slist *head = NULL;     // File list head
    int choice;

    // Validate input arguments and create file list
    if (validate_arguments(argc, argv, &head) == Success)
    {
        // Display menu
        printf("\n==========================\n|      Inveted Seach     |");
        printf("\n==========================\n|1.Create DataBase\t |");
        printf("\n|2.Search DataBase\t |");
        printf("\n|3.Display DataBase\t |");
        printf("\n|4.Save DataBase\t |");
        printf("\n|5.Update DataBase\t |");
        printf("\n|6.Exit                  |");
        printf("\n==========================\n");

        // Initialize hash table
        create_HT(arr);

        // Menu-driven execution
        do
        {
            printf("Enter Your Choice:");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    create_database(arr, &head);
                    break;

                case 2:
                    search_database(arr);
                    break;

                case 3:
                    display_database(arr);
                    break;

                case 4:
                    save_database(arr);
                    break;

                case 5:
                    update_database(arr, &head);
                    break;

                default:
                    printf("Enter Valid Input\n");
                    break;
            }
        } while (choice != 6);
    }
}

// Function to validate command-line arguments
Status validate_arguments(int argc, char *argv[], Slist **head)
{
    // Traverse command-line arguments
    for (int i = 1; i < argc; i++)
    {
        char *str = strstr(argv[i], ".txt");

        // Check for valid .txt extension
        if (str != NULL && strlen(str) == 4)
        {
            printf("Valid file: %s\n", argv[i]);

            FILE *ptr = fopen(argv[i], "r");
            if (ptr == NULL)
            {
                printf("Failed Open the File %s\n", argv[i]);
                continue;
            }

            // Create new file list node
            Slist *new = malloc(sizeof(Slist));
            if (new == NULL)
            {
                printf("Failed create Memory\n");
                continue;
            }

            strcpy(new->filename, argv[i]);
            new->link = NULL;

            // Insert node into file list
            if (*head == NULL)
            {
                *head = new;
            }
            else
            {
                Slist *temp = *head;
                while (temp->link != NULL)
                {
                    temp = temp->link;
                }
                temp->link = new;
            }
        }
        else
        {
            printf("Invalid file extension %d: %s\n", i, argv[i]);
            continue;
        }
    }
	remove_duplicates(head);
    // Display collected filenames
    Slist *temp1 = *head;
    while (temp1 != NULL)
    {
        printf("filename: %s\n", temp1->filename);
        temp1 = temp1->link;
    }

    return Success;
}

// Function to initialize hash table
void create_HT(hash_t *arr)
{
    for (int i = 0; i < 28; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
}

void remove_duplicates(Slist **head)
{
    if (*head == NULL)
        return;

    Slist *current = *head;

    // Traverse each node
    while (current != NULL)
    {
        Slist *prev = current;
        Slist *temp = current->link;

        // Compare current string with remaining nodes
        while (temp != NULL)
        {
            if (strcmp(current->filename, temp->filename) == 0)
            {
				printf("Duplicate found deleting the node\n");
                // Duplicate found → delete node
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
            else
            {
                prev = temp;
                temp = temp->link;
            }
        }
        current = current->link;
    }
}


