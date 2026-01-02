/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/
#include "inverted_search.h"

// Function to display the complete database
void display_database(hash_t *arr)
{
    int flag = 0;

    // Print table header
    printf("\n+--------------------------------------------------------------------+\n");
    printf("| Filecount       Word                 Word Count           Filename |");
    printf("\n|--------------------------------------------------------------------|\n");

    // Traverse all hash table indices
    for (int i = 0; i < 28; i++)
    {
        // Skip empty hash index
        if (arr[i].link == NULL)
            continue;
        else
        {
            Mainnode *temp_main = arr[i].link;

            // Traverse main node list
            while (temp_main != NULL)
            {
                printf("|    %-13d%-26s",
                       temp_main->file_count,
                       temp_main->word);

                Subnode *temp_sub = temp_main->sublink;
                int k = 1;

                // Traverse sub node list
                while (temp_sub != NULL)
                {
                    if (k)
                    {
                        printf("%-15d%-10s|\n",
                               temp_sub->word_count,
                               temp_sub->filename);
                        k = 0;
                    }
                    else
                    {
                        printf("|%44d%20s    |\n",
                               temp_sub->word_count,
                               temp_sub->filename);
                    }
                    temp_sub = temp_sub->link;
                }

                // Move to next main node
                temp_main = temp_main->mainlink;

                // Print separator line
                printf("|--------------------------------------------------------------------|\n");

                flag = 1;
            }
        }
    }

    // If database is empty
    if (flag == 0)
    {
        printf("|\t\t\tDatabase is Empty\t                     |\n");
        printf("|--------------------------------------------------------------------|\n");
    }
}
