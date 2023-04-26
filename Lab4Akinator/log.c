#include "tree.h"

void log(FILE* treeFile, char* text, const int* value) {
    char buffer[256];
    fseek(treeFile, 0, SEEK_END);
    time_t timeInNumbers = time(NULL);
    struct tm timeFormat;
    localtime_r(&timeInNumbers, &timeFormat);
    strftime(buffer, 256, "%Y-%m-%d %H:%M:%S", &timeFormat);
    if (value == NULL) fprintf(treeFile, "[%s]: username INPUT: %s\n", buffer, text);
    else if (text == NULL) fprintf(treeFile, "[%s]: username INPUT: %d\n", buffer, *value);
}
