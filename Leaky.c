#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUCKET_SIZE 512

int main() {
    int outputRate, packetSize;
    int bucket = 0;
    srand(time(0));

    printf("Enter output rate (bytes per second): ");
    scanf("%d", &outputRate);

    for (int i = 1; i <= 5; i++) {
        sleep(rand() % 2);
        packetSize = rand() % 1000;
        printf("\nPacket %d -> Size: %d bytes\n", i, packetSize);

        if (packetSize + bucket > BUCKET_SIZE) {
            printf("\tBucket overflow! Packet discarded.\n");
            continue;
        }

        bucket += packetSize;
        printf("\tPacket added to bucket. Current bucket: %d bytes\n", bucket);

        while (bucket > 0) {
            if (bucket >= outputRate) {
                printf("\t%d bytes sent.\n", outputRate);
                bucket -= outputRate;
            } else {
                printf("\tLast %d bytes sent.\n", bucket);
                bucket = 0;
            }
            sleep(1);
        }
        printf("\tBucket output successful!\n");
    }

    return 0;
}



Enter output rate (bytes per second): 200



Enter output rate (bytes per second): 200

Packet 1 -> Size: 430 bytes
    Packet added to bucket. Current bucket: 430 bytes
    200 bytes sent.
    200 bytes sent.
    Last 30 bytes sent.
    Bucket output successful!

Packet 2 -> Size: 873 bytes
    Bucket overflow! Packet discarded.

Packet 3 -> Size: 120 bytes
    Packet added to bucket. Current bucket: 120 bytes
    Last 120 bytes sent.
    Bucket output successful!

Packet 4 -> Size: 511 bytes
    Bucket added to bucket. Current bucket: 511 bytes
    200 bytes sent.
    200 bytes sent.
    Last 111 bytes sent.
    Bucket output successful!

Packet 5 -> Size: 950 bytes
    Bucket overflow! Packet discarded.

