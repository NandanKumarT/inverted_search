/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/
#include "inverted_search.h"

// Function to save the database into a file
void save_database(hash_t *arr)
{
    // Open output file in write mode
    FILE *ptr = fopen("output.txt", "w");

    // Check if file opening failed
    if (ptr == NULL)
    {
        printf("Error: while opening the file\n");
    }
    else
    {
        // Traverse all hash table indices
        for (int i = 0; i < 28; i++)
        {
            // Skip empty hash index
            if (arr[i].link == NULL)
                continue;
            else
            {
                // Traverse main node list
                Mainnode *temp_main = arr[i].link;
                while (temp_main != NULL)
                {
                    // Write main node data
                    fprintf(ptr, "#%d;%s;%d;", i, temp_main->word, temp_main->file_count);

                    // Traverse sub node list
                    Subnode *temp_sub = temp_main->sublink;
                    while (temp_sub != NULL)
                    {
                        // Write sub node data
                        fprintf(ptr, "%d;%s;", temp_sub->word_count, temp_sub->filename);
                        temp_sub = temp_sub->link;
                    }

                    // End of one word entry
                    fprintf(ptr, "#\n");

                    // Move to next main node
                    temp_main = temp_main->mainlink;
                }
            }
        }
    }

    // Close the output file
    fclose(ptr);
}
