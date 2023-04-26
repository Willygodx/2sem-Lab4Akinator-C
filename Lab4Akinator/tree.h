#ifndef LAB4AKINATOR_TREE_H
#define LAB4AKINATOR_TREE_H
#define STRING_MAX_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include "log.h"

typedef struct treeNode {
    char* text;
    struct treeNode* yesAnswer;
    struct treeNode* noAnswer;
} treeNode;

struct treeNode* newTreeNode(char* text);
void treeToFile(FILE *treeFile, struct treeNode *treeRoot);
struct treeNode* fromFileToTree(FILE *treeFile);

#endif //LAB4AKINATOR_TREE_H