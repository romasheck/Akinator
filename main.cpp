#include <stdio.h>
#include "akinator.h"

int main()
{
    Tree asscar;
    Tree* tree = &asscar;
    TreeCtor(tree);
    
    FILE* tree_file = fopen ("ak_database.txt", "r");
    char* buffer = TreeTake (tree, tree_file);
    fclose (tree_file);

    StartPlay (tree);

    FILE* tree_file1 = fopen ("ak_database.txt", "w");
    TreeSave(tree, tree_file1);
    fclose (tree_file1);

    TreeDump (tree);

    free (buffer); 
    TreeDtor (tree);

    return 0;
}