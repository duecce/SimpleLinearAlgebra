#include <iostream>
#include "SimpleLA.hpp"
using namespace std;


void printMatrix ( Matrix a ) {
    // print matrix
    for (int i = 0; i < a.getnelements(); i++ ) {
        printf ( "element %d = %f\n", i, a.get(i));
    }
}

int main (int argc, char **argv) {
    Matrix a = Matrix(3, 4);
    a.set(0, 1);
    a.set(1, 4);
    a.set(2, 5);
    a.set(3, 7);
    a.set(4, 2);
    a.set(5, 2);
    a.set(6, 3);
    a.set(7, 1);
    a.set(8, 4);
    a.set(9, 3);
    a.set(10, 2);
    a.set(11, 1);

    Matrix b = Matrix(4, 2);
    b.set(0, 2);
    b.set(1, 2);
    b.set(2, 3);
    b.set(3, 2);
    b.set(4, 1);
    b.set(5, 2);
    b.set(6, 2);
    b.set(7, 1);

    cout << "elementi di A:" << endl;
    a.print();
    cout << "elementi di B:" << endl;
    b.print();

    Matrix c = a * b;
    printf("c = a * b\n" );
    c.print();


    c = c + 10.0;
    printf ( "c = c + 10.0\n" );
    c.print();

    c = (a * b + 10) * 2;
    printf ( "c = (a * b + 10) * 2;\n" );
    c.print();
    return 0;
}
