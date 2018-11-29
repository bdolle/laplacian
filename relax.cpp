//
// Created by Brian Dolle on 3/3/18.
//

#include <math.h>

void setbc(double v[500][500]){                        // function to set boundary conditions
    for (int i=0; i<500; i++){
        for (int j=0; j<500; j++){
            v[i][0] = 0.0;                             // These 4 lines set the border of the
            v[i][499] = 0.0;                           // array to 0.0
            v[499][j] = 0.0;
            v[0][j] = 0.0;
        } // closes j loop

    } //closes i loop

} // closes function

void relax(double v[500][500], double vprime[500][500]){     // function to 'dissipate' charge
    for (int i = 1; i <499; i++){                            // through space.
        for (int j = 1; j<499; j++){
            double x = -20.0 + i*(40.0/499.0);               // Defines x and y so that there are
            double y = -20.0 + j*(40.0/499.0);               // 500 values between -20 and 20.
            double delta = 40.0/499.0;                       // the change between each array position
            double r = pow(pow(x,2)+pow(y,2),.5);            // defining radius of the charge density circle

            // Calculates the second derivative of potential with respect to x and y using multidimensional
            // taylor expansion, Poisson's eqn and the Laplacian.

            if(r<3){                     // sets the interior of the circle to charge density 2.5
                                         // and stores these values in a temporary array "vprime"
                vprime[i][j]=(v[i+1][j]+v[i-1][j]+v[i][j+1]+v[i][j-1]+(2.5*pow(delta,2)))/(4.0);
            } //closes if
            else{                       // sets outside of circle to 0 charge density.
                vprime[i][j]=(v[i+1][j]+v[i-1][j]+v[i][j+1]+v[i][j-1])/4.0;
            } //closes else

        } //closes j loop
    } //closes i loop
} //closes function

// this function simply updates the values of the v array with the temporary values of vprime.
void update(double v[500][500], double vprime[500][500]){
    for (int i = 1; i <499; i++){
        for (int j = 1; j<499; j++){

            v[i][j]=vprime[i][j];

        } //closes j loop
    } //closes i loop
} //closes function