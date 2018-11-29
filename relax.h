//
// Created by Brian Dolle on 3/3/18.
//

#ifndef LAPLACE2_RELAX_H
#define LAPLACE2_RELAX_H

void setbc(double v[500][500]);                             // Initializing three functions being
void relax(double v[500][500], double vprime[500][500]);    // passed arrays
void update(double v[500][500],double vprime[500][500]);


#endif //LAPLACE2_RELAX_H
