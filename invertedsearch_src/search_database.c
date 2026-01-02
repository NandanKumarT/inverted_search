/* Name        : Nandan Kumar T
   Date        : 02/01/2026
   Description : Inverted Search
*/
#include "inverted_search.h"

// Function to search a word in the database
void search_database(hash_t *arr)
{
    char search[50];

    // Read the word to be searched
    printf("Enter the word to Search: ");
    scanf("%s", search);

    int index;

    // Calculate hash index based on first character
    if (isupper(search[0]))
        index = (search[0] - 'A');
    else if (islower(search[0]))
        index = (search[0] - 'a');
    else if (isdigit(search[0]))
        index = 26;
    else
        index = 27;

    // Print table header
    printf("\n+--------------------------------------------------------------------+\n");
    printf("| Filecount       Word                 Word Count           Filename |");
    printf("\n|--------------------------------------------------------------------|\n");

    // If no entry at calculated index
    if (arr[index].link == NULL)
    {
        printf("|\t\t\tEntered Word is Not Found\t             |\n");
        printf("|--------------------------------------------------------------------|\n");
    }
    else
    {
        Mainnode *temp_main = arr[index].link;
        int flag = 0;

        // Traverse main node list
        while (temp_main != NULL)
        {
            // If searched word is found
            if (strcmp(search, temp_main->word) == 0)
            {
                printf("|    %-13d%-26s", temp_main->file_count, temp_main->word);

                Subnode *temp_sub = temp_main->sublink;
                int k = 1;
                flag = 1;

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

                // Print table footer
                printf("|--------------------------------------------------------------------|\n");
                break;
            }

            // Move to next main node
            temp_main = temp_main->mainlink;
        }

        // If word not found in list
        if (flag == 0)
        {
            printf("|\t\t\tEntered Word is Not Found\t             |\n");
            printf("|--------------------------------------------------------------------|\n");
        }
    }
}
