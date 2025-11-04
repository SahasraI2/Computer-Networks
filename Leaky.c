#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h>

#define BUCKET_SIZE 512

int main() {
    int outputRate, packetSize;
    srand(time(0));

    printf("Enter output rate: ");
    scanf("%d", &outputRate);

    for (int i = 1; i <= 5; i++) {
        sleep(rand() % 2);
        packetSize = rand() % 1000;

        printf("\nPacket %d -> Size: %d bytes", i, packetSize);

        if (packetSize > BUCKET_SIZE) {
            printf("\n\tBucket overflow! Packet discarded.\n");
            continue;
        }

        printf("\n\tProcessing packet...");
        while (packetSize > 0) {
            if (packetSize >= outputRate) {
                printf("\n\t%d bytes sent.", outputRate);
                packetSize -= outputRate;
            } else {
                printf("\n\tLast %d bytes sent.", packetSize);
                packetSize = 0;
            }
            sleep(1);
        }

        printf("\n\tBucket output successful!\n");
    }

    return 0;
}


Enter output rate: 200

Packet 1 -> Size: 450 bytes
    Processing packet...
    200 bytes sent.
    200 bytes sent.
    Last 50 bytes sent.
    Bucket output successful!

Packet 2 -> Size: 780 bytes
    Bucket overflow! Packet discarded.

Packet 3 -> Size: 300 bytes
    Processing packet...
    200 bytes sent.
    Last 100 bytes sent.
    Bucket output successful!

Packet 4 -> Size: 120 bytes
    Processing packet...
    Last 120 bytes sent.
    Bucket output successful!

Packet 5 -> Size: 600 bytes
    Bucket overflow! Packet discarded.

