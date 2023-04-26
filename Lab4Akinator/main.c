#include "tree.h"

int main() {
    FILE * logFile = copyLogFile();
    FILE * saveFile = fopen("binaryTree.txt", "r");
    if (saveFile == NULL)
        exit(0);
    struct treeNode* treeRoot = fromFileToTree(saveFile);
    fclose(saveFile);
    printf("Hello! Let's play! I can try to find anime show you want with some questions!");
    printf("Please, use 1 for YES answer and 0 for NO answer!\n");
    while (1){
        struct treeNode* pTreeNode = treeRoot;
        do{
            pTreeNode = RunTroughTree(pTreeNode, logFile);
        } while (pTreeNode != NULL);
        printf("Press 0 to continue our game! Press 1 to exit and save this RunTroughTree to a txt file.\n");
        int temp = -1;
        temp = checkInputFromLeftToRight(temp, 2);
        log(saveFile, NULL, &temp);
        if(temp == 1) {
            FILE * file = fopen("binaryTree.txt","w");
            if (file == NULL)
                exit(0);
            treeToFile(file, treeRoot);
            fclose(file);
            break;
        }
    }
    freeMemoryOfTree(treeRoot);
    fclose(logFile);
    return 0;
}