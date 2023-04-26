#include "menu.h"

void menu(FILE* logFile, FILE* saveFile, struct treeNode* treeRoot)
{
    printf("Hello! Let's play! I can try to find anime show you want with some questions!\n");
    printf("Please, use 1 for YES answer and 0 for NO answer!\n");
    while (1){
        struct treeNode* pTreeNode = treeRoot;
        do{
            pTreeNode = RunTroughTree(pTreeNode, logFile);
        } while (pTreeNode != NULL);
        printf("Press 0 to continue our game! Press 1 to exit and save this game to a txt file.\n");
        int chooseButton = 0;
        checkValue(&chooseButton);
        log(saveFile, NULL, &chooseButton);
        if(chooseButton == 1) {
            FILE * file = fopen("binaryTree.txt","w");
            if (file == NULL)
                exit(0);
            treeToFile(file, treeRoot);
            fclose(file);
            break;
        }
    }
}