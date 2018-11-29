// This code simulates electric potential in 500x500 space using Poisson's eqn and the Laplacian.
// The boundary values are kept at a constant 0.0 where an interior circle of radius 3 is kept
// at a constant charge density of 2.5.

#include <iostream>
#include "relax.h"
#include <fstream>
using namespace std;


int main() {

    ofstream laplacian2;                            // These two lines create a file variable name and
    laplacian2.open("Laplacian2.csv",ios::app);     // create a file called "Laplacian2" which can be
                                                    // opened with excel.

    double v[500][500];                             //creating 2 500x500 arrays
    double vprime[500][500];

    for (int i=0; i<500; i++){                      // population of initial values of an array
        for (int j=0; j<500; j++){                  // with the value 0.1
            v[i][j] = 0.1;
        }
    }

    setbc(v);                                       // passing the array v through the boundary
                                                    // condition function.

    for (int k=0; k<15000; k++){                    // relaxing and updating the matrices 15,000 times
        relax(v,vprime);
        update(v,vprime);
    }

    for (int j=0; j<500; j++){                      // for loops to output the matrix values to the
        for (int i =0; i<500; i++){                 // "Laplacian2" file. Rows (j) outputted before
                                                    // columns (i).
            laplacian2 << v[i][j] << ",";
        } // closes i loop

        laplacian2 << endl;                         // Not only should the values be separated by
                                                    // commas but the rows should be separated by
    }// closes j loop                               // line ends

    laplacian2.close();                             // closes the csv file

    return 0;
}