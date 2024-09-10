#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 // จำนวน thread ที่ต้องการสร้าง

char *x;
int n;

void* fill_array(void* arg) {
    int thread_id = *((int*)arg);
    int start = (n / NUM_THREADS) * thread_id;
    int end = (thread_id == NUM_THREADS - 1) ? n : start + (n / NUM_THREADS);

    for (int i = start; i < end; i++) {
        x[i] = 'A';
    }

    return NULL;
}

int main() {
    printf("Enter size of array: ");
    scanf("%d", &n);

    // จัดสรรหน่วยความจำให้กับอาร์เรย์ x
    x = (char *)realloc(x, n * sizeof(char));
    if (x == NULL) {
        perror("Failed to reallocate memory");
        return 1;
    }

    // สร้าง threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, fill_array, (void*)&thread_ids[i]);
    }

    // รอให้แต่ละ thread ทำงานเสร็จ
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // แสดงผลค่าในอาร์เรย์
    for (int i = 0; i < n; i++) {
        printf("%c ", x[i]);
    }
    printf("\n");

    // ล้างหน่วยความจำ
    free(x);

    return 0;
}
