#ifndef LAB4AKINATOR_GAME_H
#define LAB4AKINATOR_GAME_H

#include "tree.h"

char checkIfAnswer(const struct treeNode* treeNode);
struct treeNode* RunTroughTree(struct treeNode* treeNode, FILE* fileWithGame);
int checkInputFromLeftToRight(int left, int right);
FILE * copyLogFile();
void freeMemoryOfTree(struct treeNode* treeRoot);

#endif //LAB4AKINATOR_GAME_H