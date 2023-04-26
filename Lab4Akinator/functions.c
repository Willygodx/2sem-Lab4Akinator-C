#include "functions.h"

char checkIfAnswer(const struct treeNode* treeNode) {
    if (treeNode->yesAnswer == NULL && treeNode->noAnswer == NULL) return 1;
    return 0;
}

struct treeNode* RunTroughTree(struct treeNode* treeNode, FILE* fileWithGame) {
    int answer = 0;
    printf("%s?\n", treeNode->text);
    if (checkIfAnswer(treeNode)) {
        checkValue(&answer);
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
            log(fileWithGame, tempStringForTheAnswer, NULL);
            printf("How can I differ this object?\n");
            char *mainString = malloc(sizeof(char) * STRING_MAX_SIZE);
            fgets(mainString, STRING_MAX_SIZE, stdin);
            log(fileWithGame, mainString, NULL);
            struct treeNode *tempTreeNode = newTreeNode(tempStringForTheAnswer);
            struct treeNode *treeNodeNew = newTreeNode(treeNode->text);
            treeNode->text = mainString;
            treeNode->noAnswer = tempTreeNode;
            treeNode->yesAnswer = treeNodeNew;
            return NULL;
        }
    } else {
        checkValue(&answer);
        log(fileWithGame, NULL, &answer);
        rewind(stdin);
        if (answer == 1) return treeNode->noAnswer;
        else return treeNode->yesAnswer;
    }
}

FILE* copyLogFile() {
    FILE* logFile = fopen("log.txt", "r");
    if (logFile == NULL)
    {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }
    FILE* tempLogFile = fopen("tempLog.txt", "w");
    if (tempLogFile == NULL)
    {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }
    char* buffer = malloc(sizeof(char) * STRING_MAX_SIZE);
    while (fgets(buffer, STRING_MAX_SIZE, logFile) != 0) {
        fprintf(tempLogFile, "%s", buffer);
    }
    fclose(tempLogFile);
    fclose(logFile);
    logFile = fopen("log.txt", "w");
    if (logFile == NULL)
    {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }
    tempLogFile = fopen("tempLog.txt", "r");
    if (tempLogFile == NULL)
    {
        fprintf(stderr, "Error: unable to open this file!\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, STRING_MAX_SIZE, tempLogFile) != 0) {
        fprintf(logFile, "%s", buffer);
    }
    fclose(tempLogFile);
    remove("tempLog.txt");
    free(buffer);
    return logFile;
}