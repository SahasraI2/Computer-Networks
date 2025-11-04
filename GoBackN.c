#include <stdio.h>

int main() {
    int window_size, sent = 0, ack, i;

    printf("Enter window size: ");
    scanf("%d", &window_size);

    while (1) {
        for (i = 0; i < window_size; i++) {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
            if (sent == window_size)
                break;
        }

        printf("\nPlease enter the last Acknowledgement received: ");
        scanf("%d", &ack);

        if (ack == window_size) {
            printf("All frames acknowledged. Transmission complete.\n");
            break;
        } else {
            sent = ack;
            printf("Resending from frame %d...\n\n", sent);
        }
    }

    return 0;
}
