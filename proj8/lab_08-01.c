#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Function sh(x)
double sh(double x) {
    return (exp(x) - exp(-x)) / 2;
}

// Function f(x)
double f(double x) {
    if (x < -2) {
        return exp(2 * x) - 1;
    }
    else if (x <= 2) {
        return x - exp(-x * x);
    }
    else {
        return (x + fabs(3 - x)) / sqrt(x + 1);
    }
}

int main() {
    // Variables for tabulation
    double x, step, a, b;
    FILE* fp;

    // Function sh(x)
    a = 0;
    b = 1;
    step = 0.2;

    // Open file for writing
    fp = fopen("output.txt", "w");

    // Tabulate function sh(x)
    printf("x\tsh(x)\n");
    fprintf(fp, "x\tsh(x)\n");
    for (x = a; x <= b; x += step) {
        printf("%.2lf\t%.4lf\n", x, sh(x));
        fprintf(fp, "%.2lf\t%.4lf\n", x, sh(x));
    }

    // Function f(x)
    a = -3;
    b = 3;
    step = 0.15;

    // Tabulate function f(x)
    printf("\nx\tf(x)\n");
    fprintf(fp, "\nx\tf(x)\n");
    for (x = a; x <= b; x += step) {
        printf("%.2lf\t%.4lf\n", x, f(x));
        fprintf(fp, "%.2lf\t%.4lf\n", x, f(x));
    }

    // Close the file
    fclose(fp);

    return 0;
}