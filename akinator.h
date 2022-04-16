#ifndef AKINATOR_H_INCLUDED
#define AKINATOR_H_INCLUDED

#include "tree.h"
#include <string.h>


int             StartPlay           (Tree* tree);

int             AskQuestion         (Node* node);

int             TryGuess            (Node* node);

int             InsertQuestion      (Node* node);

int             QueScan             (char* que, uint16_t max_size);

int             QueCpy              (char* reciver, const char* sourse);

#endif