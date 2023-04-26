#ifndef LAB4AKINATOR_FUNCTIONS_H
#define LAB4AKINATOR_FUNCTIONS_H

#include "tree.h"

char checkIfAnswer(const struct treeNode* treeNode);
struct treeNode* RunTroughTree(struct treeNode* treeNode, FILE* fileWithGame);
FILE* copyLogFile();

#endif //LAB4AKINATOR_FUNCTIONS_H