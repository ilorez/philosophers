
#include <stdio.h>
#include <time.h>

int main() {
    time_t max_time = ((time_t)1 << (sizeof(time_t) * 8 - 1)) -1;  // Max value (all bits set if unsigned, -1 if signed)
    time_t min_time = (time_t)1 << (sizeof(time_t) * 8 - 1); // Min value for signed

    printf("Size of time_t: %zu bytes\n", sizeof(time_t));
    printf("Max time_t: %lld\n", (long long)max_time);
    printf("Min time_t: %lld\n", (long long)min_time);

    return 0;
}
