#include "memory.h"

void freeMemoryOfTree(struct treeNode *treeRoot) {
    if (treeRoot == NULL) {
        return;
    }
    freeMemoryOfTree(treeRoot->yesAnswer);
    freeMemoryOfTree(treeRoot->noAnswer);
    free(treeRoot->text);
    free(treeRoot);
}
