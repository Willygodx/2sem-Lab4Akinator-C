#include "tree.h"
#include "menu.h"

int main() {
    FILE* logFile = copyLogFile();
    FILE* saveFile = fopen("binaryTree.txt", "r");
    if (saveFile == NULL)
        exit(0);
    struct treeNode* treeRoot = fromFileToTree(saveFile);
    fclose(saveFile);
    menu(logFile, saveFile, treeRoot);
    freeMemoryOfTree(treeRoot);
    fclose(logFile);
    return 0;
}