#include <stdio.h>
#include <string.h>
int main() {
    char data[200];
    printf("\nEnter bit string: ");
    scanf("%s", data);
    int count = 0;
    printf("After stuffing : 01111110");
    for (int i = 0; i < strlen(data); i++) {
        printf("%c", data[i]);
        if (data[i] == '1') {
            count++;
            if (count == 5) {
                printf("0");
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    printf("01111110\n");
    return 0;
}
