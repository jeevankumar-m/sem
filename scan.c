#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int requests[100], n, head, disk_size;
    int i, total_seek = 0, direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // Sort requests
    sort(requests, n);

    int left[100], right[100];
    int l = 0, r = 0;

    // Divide requests into left and right of head
    for(i = 0; i < n; i++) {
        if(requests[i] < head)
            left[l++] = requests[i];
        else
            right[r++] = requests[i];
    }

    // SCAN execution
    printf("\nSeek Sequence:\n");

    if(direction == 1) { // Move right first

        for(i = 0; i < r; i++) {
            printf("%d -> ", right[i]);
            total_seek += abs(head - right[i]);
            head = right[i];
        }

        // Go to end
        total_seek += abs(head - (disk_size - 1));
        head = disk_size - 1;

        // Reverse direction
        for(i = l - 1; i >= 0; i--) {
            printf("%d -> ", left[i]);
            total_seek += abs(head - left[i]);
            head = left[i];
        }

    } else { // Move left first

        for(i = l - 1; i >= 0; i--) {
            printf("%d -> ", left[i]);
            total_seek += abs(head - left[i]);
            head = left[i];
        }

        // Go to start
        total_seek += abs(head - 0);
        head = 0;

        // Reverse direction
        for(i = 0; i < r; i++) {
            printf("%d -> ", right[i]);
            total_seek += abs(head - right[i]);
            head = right[i];
        }
    }

    printf("\n\nTotal Seek Time = %d\n", total_seek);

    return 0;
}