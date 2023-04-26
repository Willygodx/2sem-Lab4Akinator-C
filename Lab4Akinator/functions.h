#ifndef LAB4AKINATOR_FUNCTIONS_H
#define LAB4AKINATOR_FUNCTIONS_H

#include "tree.h"

char checkIfAnswer(const struct treeNode* treeNode);
struct treeNode* RunTroughTree(struct treeNode* treeNode, FILE* fileWithGame);
int checkInputFromLeftToRight(int left, int right);
FILE* copyLogFile();

#endif //LAB4AKINATOR_FUNCTIONS_H