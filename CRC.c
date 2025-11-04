#include <stdio.h>
#include <string.h>

#define CRC12_POLY     "1100000001011"
#define CRC16_POLY     "11000000000000101"
#define CRC_CCITT_POLY "10001000000100001"

void computeCRC(char data[], char crc[], const char *poly) {
    int datalen = strlen(data);
    int polylen = strlen(poly);
    char temp[200];

    strcpy(temp, data);
    for (int i = 0; i < polylen - 1; i++)
        strcat(temp, "0");

    for (int i = 0; i <= strlen(temp) - polylen;) {
        if (temp[i] == '1') {
            for (int j = 0; j < polylen; j++)
                temp[i + j] = temp[i + j] == poly[j] ? '0' : '1';
        }
        i++;
        while (i < strlen(temp) && temp[i] != '1') i++;
    }

    strncpy(crc, &temp[datalen], polylen - 1);
    crc[polylen - 1] = '\0';
}

int main() {
    char data[100], crc[50], transmitted[200];
    int choice;

    printf("Enter the binary data: ");
    scanf("%s", data);

    printf("\nSelect CRC Polynomial:\n");
    printf("1. CRC-12 (x^12 + x^11 + x^3 + x^2 + x + 1)\n");
    printf("2. CRC-16 (x^16 + x^15 + x^2 + 1)\n");
    printf("3. CRC-CCITT (x^16 + x^12 + x^5 + 1)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            computeCRC(data, crc, CRC12_POLY);
            break;
        case 2:
            computeCRC(data, crc, CRC16_POLY);
            break;
        case 3:
            computeCRC(data, crc, CRC_CCITT_POLY);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    strcpy(transmitted, data);
    strcat(transmitted, crc);

    printf("\nGenerated CRC: %s\n", crc);
    printf("Transmitted Frame: %s\n", transmitted);

    return 0;
}
