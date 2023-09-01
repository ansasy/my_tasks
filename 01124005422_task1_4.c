#include <stdio.h>

// Define sensor arrays and their accuracies
float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
float accuracy_mpu6050 = 0.79;
float accuracy_bno55 = 0.92;

// Function to calculate weighted average
float weightedAverage(float val1, float val2, float weight1, float weight2) {
    return (weight1 * val1 + weight2 * val2) / (weight1 + weight2);
}

int main() {
    int numElements = sizeof(mpu6050) / sizeof(mpu6050[0]);


    printf("Fused Measurement:\n");

    for (int i = 0; i < numElements; i++) {
        // Calculate fused measurement using weighted averaging
        float fusedValue = weightedAverage(mpu6050[i], bno55[i], accuracy_mpu6050, accuracy_bno55);
        printf("Time: %d - Fused Value: %.2f m\n", i, fusedValue);
    }

    return 0;
}
