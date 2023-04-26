#include "tree.h"

struct treeNode *newTreeNode(char *text) {
    struct treeNode *node = malloc(sizeof(struct treeNode));
    node->text = text;
    node->noAnswer = NULL;
    node->yesAnswer = NULL;
    return node;
}

void saveTree(struct treeNode *treeRoot, FILE *saveFile) {
    if (treeRoot == NULL) {
        fprintf(saveFile, "NULL");
        return;
    }
    fprintf(saveFile, "%s", treeRoot->text);
    saveTree(treeRoot->yesAnswer, saveFile);
    saveTree(treeRoot->noAnswer, saveFile);
}

void treeToFile(FILE *treeFile, struct treeNode *treeRoot) {
    if (treeRoot == NULL) {
        fprintf(treeFile, "NULL\n");
        return;
    }
    fprintf(treeFile, "%s\n", treeRoot->text);
    treeToFile(treeFile, treeRoot->yesAnswer);
    treeToFile(treeFile, treeRoot->noAnswer);
}

struct treeNode *fromFileToTree(FILE *treeFile) {
    char *buffer = malloc(sizeof(char) * STRING_MAX_SIZE);
    if (!fgets(buffer, STRING_MAX_SIZE, treeFile)) {
        return NULL;
    }
    buffer[strlen(buffer) - 1] = '\0';
    if (strcmp(buffer, "NULL") == 0) {
        return NULL;
    }
    struct treeNode *treeRoot = newTreeNode(buffer);
    treeRoot->yesAnswer = fromFileToTree(treeFile);
    treeRoot->noAnswer = fromFileToTree(treeFile);
    return treeRoot;
}




