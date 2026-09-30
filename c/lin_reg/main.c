#include <stdio.h>

int main(void) {
    double x_vals[] = {0, 1, 2, 3, 4};
    double y_ref_vals[] = {1, 3, 5, 7, 9};

    int n = 5; // antal uppsättningar

    // startvärde
    double k = 0.0;
    double m = 0.0;

    double lr = 0.2;        // Learning rate (20 %)
    int antal_epoker = 66;  

    printf("TRÄNING STARTAR \n");

    for (int e = 0; e < antal_epoker; e++) {
        printf("Epok %d \n", e + 1);

        for (int i = 0; i < n; i++) {
            double x = x_vals[i];
            double y_ref = y_ref_vals[i];

            double y_p = k * x + m;
            double delta = y_ref - y_p;
            double delta_e = delta * lr;

            m = m + delta_e;
            k = k + delta_e * x;
        }
        printf("Efter detta varv -> k: %f, m: %f\n\n", k, m);
    }

    printf("Slutgiltig formel: y = %f * x + %f\n\n", k, m);

    return 0;
}
