#include "akinator.h"

int StartPlay (Tree* tree)
{
    /*CHEKER*/
    AskQuestion (THEAD);
    /*CHEKER*/
    return 0;
}

int AskQuestion (Node* node)
{

    /*
    if (LNODE == NULL && RNODE == NULL)
    {
        TryGuess
    }
    */
    bool flag = 1;
    char answer[5] = {};
    while (flag)
    {
        if (LNODE == NULL && RNODE == NULL)
        {
            TryGuess (node);
            return 0;
        }

        printf ("%s\n", DATA.cp);

        scanf ("%s", answer);

        if (strncmp (answer, "yes", 3) == 0)
        {
            node = LNODE;
            continue;
        }
        if (strncmp (answer, "no", 2) == 0)
        {
            node = RNODE;
            continue;
        }
        else 
        {
            printf ("incorrect answer\n");
            return 1;
        }
    }
}

int TryGuess (Node* node)
{
    printf ("is this %s?\n", DATA.cp);

    char answer [5] = {};

    scanf ("%s", answer);

    if (strncmp (answer, "yes", 3) == 0)
    {
        printf ("Cool! Please, donate me [my bank account must be hear]\n");
        return 1;
    }
    if (strncmp (answer, "no", 2) == 0)
    {
        InsertQuestion (node);
        return 0;
    }
    else
    {
        printf ("incorrect answer\n");
        return 1;
    }
}

int InsertQuestion (Node* node)
{
    printf ("tell me what or who is this?\n");

    char yep[20] = {};
    scanf ("%s", yep);

    printf ("Pls, ask the que about differnt between %s and %s\n", yep, DATA.cp);

    char que[30] = {};
    QueScan (que, 30);

    node_data_t tmp_data;
    tmp_data.type = OTHER;

    tmp_data.data.cp = DATA.cp;
    NodeInsert (node, tmp_data, RIGHT_N);

    tmp_data.data.cp = (char*)calloc (20,  sizeof(char));
    strcpy (tmp_data.data.cp, yep);
    NodeInsert (node, tmp_data, LEFT_N);
    LNODE->free_flag = NEED_FREE;

    DATA.cp = (char*)calloc(30, sizeof(char));
    node->free_flag = NEED_FREE;
    QueCpy (DATA.cp, que);

    printf ("10q!\n");

    return 0;
}

int QueScan (char* que, uint16_t max_size)
{
    char cur_symbol = 81;
    uint16_t i = 0;
    while (cur_symbol != '?' && i < max_size)
    {
        scanf ("%c", &cur_symbol);
        que[i] = cur_symbol;
        i++;
    }

    return 0;
}

int QueCpy (char* reciver, const char* sourse)
{
    uint16_t i = 0;
    while (sourse[i] != '\0')
    {
        reciver[i] = sourse[i];
        i++;
    }
    
    return 0;
}