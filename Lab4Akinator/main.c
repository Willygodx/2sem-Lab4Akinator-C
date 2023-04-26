#include "tree.h"
#include "menu.h"

int main() {
    FILE* logFile = copyLogFile();
    FILE* saveFile = fopen("binaryTree.txt", "r");
    if (saveFile == NULL)
    {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }
    struct treeNode* treeRoot = fromFileToTree(saveFile);
    fclose(saveFile);
    menu(logFile, saveFile, treeRoot);
    freeMemoryOfTree(treeRoot);
    fclose(logFile);
    return 0;
}