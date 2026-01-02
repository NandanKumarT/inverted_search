/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/
#include "inverted_search.h"

// Function to create inverted search database
void create_database(hash_t *arr, Slist **head)
{
    // Pointer to traverse file list
    Slist *file_node = *head;

    // Loop through all files
    while (file_node != NULL)
    {
        // Open file in read mode
        FILE *fptr = fopen(file_node->filename, "r");
        if (fptr == NULL)
        {
            perror("File open failed");
            file_node = file_node->link;
            continue;
        }

        // Store current filename
        char filename[50];
        strcpy(filename, file_node->filename);

        char temp1[50];

        // Read words from file
        while (fscanf(fptr, "%49s", temp1) == 1)
        {
            int index;

            // Calculate hash index based on first character
            if (isupper(temp1[0]))
                index = (temp1[0] - 'A');
            else if (islower(temp1[0]))
                index = (temp1[0] - 'a');
            else if (isdigit(temp1[0]))
                index = 26;
            else
                index = 27;

            // If no main node exists at this index
            if (arr[index].link == NULL)
            {
                // Create new main node
                Mainnode *new = malloc(sizeof(Mainnode));
                strcpy(new->word, temp1);
                new->file_count = 1;
                new->mainlink = NULL;

                // Create new sub node
                Subnode *new1 = malloc(sizeof(Subnode));
                strcpy(new1->filename, filename);
                new1->word_count = 1;
                new1->link = NULL;

                // Link sub node to main node
                new->sublink = new1;
                arr[index].link = new;
            }
            else
            {
                Mainnode *mtemp = arr[index].link;
                Mainnode *prev_main = NULL;
                int word_found = 0;

                // Traverse main node list
                while (mtemp != NULL)
                {
                    // Check if word already exists
                    if (strcmp(mtemp->word, temp1) == 0)
                    {
                        word_found = 1;

                        Subnode *temp_sub = mtemp->sublink;
                        Subnode *prev_sub = NULL;
                        int file_found = 0;

                        // Traverse sub node list
                        while (temp_sub != NULL)
                        {
                            // Check if file already exists
                            if (strcmp(temp_sub->filename, filename) == 0)
                            {
                                temp_sub->word_count++;
                                file_found = 1;
                                break;
                            }
                            prev_sub = temp_sub;
                            temp_sub = temp_sub->link;
                        }

                        // If file not found, create new sub node
                        if (file_found == 0)
                        {
                            Subnode *new1 = malloc(sizeof(Subnode));
                            strcpy(new1->filename, filename);
                            new1->word_count = 1;
                            new1->link = NULL;

                            if (prev_sub == NULL)
                                mtemp->sublink = new1;
                            else
                                prev_sub->link = new1;

                            mtemp->file_count++;
                        }
                        break;
                    }

                    prev_main = mtemp;
                    mtemp = mtemp->mainlink;
                }

                // If word not found, create new main node
                if (word_found == 0)
                {
                    Mainnode *new = malloc(sizeof(Mainnode));
                    strcpy(new->word, temp1);
                    new->file_count = 1;
                    new->mainlink = NULL;

                    Subnode *new1 = malloc(sizeof(Subnode));
                    strcpy(new1->filename, filename);
                    new1->word_count = 1;
                    new1->link = NULL;

                    new->sublink = new1;
                    prev_main->mainlink = new;
                }
            }
        }

        // Close current file
        fclose(fptr);

        // Move to next file in list
        file_node = file_node->link;
    }
}
