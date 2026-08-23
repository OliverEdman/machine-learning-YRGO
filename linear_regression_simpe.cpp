#include <iostream>

using namespace std;

int main() {
 
    double x_vals[] = {0, 1, 2, 3, 4};
    double y_ref_vals[] = {1, 3, 5, 7, 9};

    int n = 5; //antal uppsättningar

    // startvärde
    double k = 0.0;
    double m = 0.0;
    

    double lr = 0.2;       // Learing rate (20 %)
    int antal_epoker = 59; 

    cout << "TRÄNING STARTAR \n";

    for (int e = 0; e < antal_epoker; e++) {
        cout << "-Epok " << e + 1 << " ---\n";

        for (int i = 0; i < n; i++) {
            double x = x_vals[i];
            double y_ref = y_ref_vals[i];

            double y_p = k * x + m;

            double delta = y_ref - y_p;

            double delta_e = delta * lr;

            m = m + delta_e;
            k = k + delta_e * x;
        }
        cout << "Efter detta varv -> k: " << k << ", m: " << m << "\n\n";
    }

    cout << "Slutgiltig formel: y = " << k << " * x + " << m << "\n\n";

    return 0;
}
