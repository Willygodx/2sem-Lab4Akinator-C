#include "functions.h"
#include "tree.h"

char checkIfAnswer(const struct treeNode* treeNode) {
    if (treeNode->yesAnswer == NULL && treeNode->noAnswer == NULL) return 1;
    return 0;
}

int checkInputFromLeftToRight(int left, int right) {
    while ((scanf("%d", &left)) != 1 || getchar() != '\n') {
        printf("Error: wrong input!\n>");
        rewind(stdin);
    }
    if (left < 0 || left > right) {
        printf("Error: wrong input!\n>");
        rewind(stdin);
        left = checkInputFromLeftToRight(left, right);
    } else return left;
    return 0;
}

void freeMemoryOfTree(struct treeNode *treeRoot) {
    if (treeRoot == NULL) {
        return;
    }
    freeMemoryOfTree(treeRoot->yesAnswer);
    freeMemoryOfTree(treeRoot->noAnswer);
    free(treeRoot->text);
    free(treeRoot);
}

struct treeNode* RunTroughTree(struct treeNode* treeNode, FILE* fileWithGame) {
    int answer = -1;
    printf("%s?\n", treeNode->text);
    if (checkIfAnswer(treeNode)) {
        answer = checkInputFromLeftToRight(0, 1);
        log(fileWithGame, NULL, &answer);
        rewind(stdin);
        if (answer == 1) {
            printf("It was very fun to play with you!\n");
            return NULL;
        } else {
            printf("Oops, I don't know what did you mean.\n");
            printf("Could you tell me what you wanted me to answer?\n");
            char *tempStringForTheAnswer = malloc(sizeof(char) * STRING_MAX_SIZE);
            fgets(tempStringForTheAnswer, STRING_MAX_SIZE, stdin);
            tempStringForTheAnswer[strlen(tempStringForTheAnswer) - 1] = '\0';
            log(fileWithGame, tempStringForTheAnswer, NULL);
            printf("How can I differ this object?\n");
            char *mainString = malloc(sizeof(char) * STRING_MAX_SIZE);
            fgets(mainString, STRING_MAX_SIZE, stdin);
            mainString[strlen(mainString) - 1] = '\0';
            log(fileWithGame, mainString, NULL);
            struct treeNode *tempTreeNode = newTreeNode(tempStringForTheAnswer);
            struct treeNode *treeNodeNew = newTreeNode(treeNode->text);
            treeNode->text = mainString;
            treeNode->noAnswer = tempTreeNode;
            treeNode->yesAnswer = treeNodeNew;
            return NULL;
        }
    } else {
        answer = checkInputFromLeftToRight(0, 1);
        log(fileWithGame, NULL, &answer);
        rewind(stdin);
        if (answer == 1) return treeNode->noAnswer;
        else return treeNode->yesAnswer;
    }
}

FILE* copyLogFile() {
    FILE* logFile = fopen("log.txt", "r");
    if (logFile == NULL)
        exit(0);
    FILE* tempLogFile = fopen("tempLog.txt", "w");
    if (tempLogFile == NULL)
        exit(0);
    char* buffer = malloc(sizeof(char) * STRING_MAX_SIZE);
    while (fgets(buffer, STRING_MAX_SIZE, logFile) != 0) {
        fprintf(tempLogFile, "%s", buffer);
    }
    fclose(tempLogFile);
    fclose(logFile);
    logFile = fopen("log.txt", "w");
    if (logFile == NULL)
        exit(0);
    tempLogFile = fopen("tempLog.txt", "r");
    if (tempLogFile == NULL)
        exit(0);
    while (fgets(buffer, STRING_MAX_SIZE, tempLogFile) != 0) {
        fprintf(logFile, "%s", buffer);
    }
    fclose(tempLogFile);
    remove("tempLog.txt");
    free(buffer);
    return logFile;
}