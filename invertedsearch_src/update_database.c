/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/
#include "inverted_search.h"

// Function to update the database from saved file
void update_database(hash_t *arr, Slist **head)
{
    char filename[50];

    // Ask user for database file name
    printf("Enter the file name to Update: ");
    scanf("%s", filename);

    // Validate file extension (.txt)
    char *str = strstr(filename, ".txt");
    if (str == NULL || strlen(str) != 4)
    {
        printf("Invalid file: %s\n", filename);
        return;
    }

    // Open file in read mode
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL)
    {
        printf("Error while opening the file\n");
        return;
    }

    // Check database file format (must start with #)
    char ch = fgetc(ptr);
    if (ch != '#')
    {
        printf("Invalid database file format\n");
        fclose(ptr);
        return;
    }

    // Move file pointer back to beginning
    rewind(ptr);

    int index, file_count, word_count;
    char word[50], fname[50];

    // Read each main node entry from file
    while (fscanf(ptr, "#%d;%[^;];%d;", &index, word, &file_count) == 3)
    {
        // Create new main node
        Mainnode *new = malloc(sizeof(Mainnode));
        if (!new)
            return;

        // Initialize main node
        strcpy(new->word, word);
        new->file_count = file_count;
        new->mainlink = NULL;
        new->sublink = NULL;

        // Read sub node data for each file
        for (int i = 0; i < file_count; i++)
        {
            if (fscanf(ptr, "%d;%[^;];", &word_count, fname) == 2)
            {
                Slist *temp = *head;
                Slist *prev = NULL;

                // Remove filename from file list if found
                while (temp != NULL)
                {
                    if (strcmp(fname, temp->filename) == 0)
                    {
                        if (prev == NULL)
                        {
                            *head = temp->link;
                            free(temp);
                        }
                        else
                        {
                            prev->link = temp->link;
                            free(temp);
                        }
                        break;
                    }

                    prev = temp;
                    temp = temp->link;
                }

                // Create new sub node
                Subnode *new1 = malloc(sizeof(Subnode));
                if (!new1)
                    return;

                // Initialize sub node
                strcpy(new1->filename, fname);
                new1->word_count = word_count;
                new1->link = NULL;

                // Attach sub node to main node
                if (new->sublink == NULL)
                {
                    new->sublink = new1;
                }
                else
                {
                    Subnode *stemp = new->sublink;
                    while (stemp->link != NULL)
                        stemp = stemp->link;

                    stemp->link = new1;
                }
            }
        }

        // Insert main node into hash table
        if (arr[index].link == NULL)
        {
            arr[index].link = new;
        }
        else
        {
            Mainnode *mtemp = arr[index].link;
            while (mtemp->mainlink != NULL)
                mtemp = mtemp->mainlink;

            mtemp->mainlink = new;
        }

        // Skip "#\n" at end of entry
        fseek(ptr, 2, SEEK_CUR);
    }

    // Close the file
    fclose(ptr);

    // Success message
    printf("Database updated successfully\n");
}
