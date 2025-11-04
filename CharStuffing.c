#include <stdio.h>
#include <string.h>

int main() {
    char data[30], result[100] = "";
    char start, end;
    printf("Enter data: ");
    scanf("%s", data);
    printf("Enter start delimiter: ");
    scanf(" %c", &start);
    printf("Enter end delimiter: ");
    scanf(" %c", &end);
    int j = 0;
    result[j++] = start;
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == start || data[i] == end) {
            result[j++] = data[i];
        }
        result[j++] = data[i];
    }
    result[j++] = end;
    result[j] = '\0';
    printf("After stuffing: %s\n", result);
    return 0;
}
