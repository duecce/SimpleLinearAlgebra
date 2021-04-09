#ifndef SIMPLE_LINEAR_ALGEBRA
#   define SIMPLE_LINEAR_ALGEBRA

#include <iostream>

typedef unsigned char _index;
typedef unsigned int _uint;
typedef double _element;

class Matrix {
private:
    _index nrow, ncol;
    _uint memsize, nelements;
    _element *rawmatrix;
    bool survive;
public:
    Matrix (_index _nrow, _index _ncol);
    ~Matrix ( );
    void print ( );
    void set(_index r, _index c, _element value);
    void set(_index i, _element value);
    _element rank( ); // to do
    _element det( ); // to do
    _element get(_index r, _index c);
    _element get(_index i);
    _index getnrow ( );
    _index getncol ( );
    _index getnelements ( );
    Matrix sub(_index r, _index c);
    Matrix operator+(Matrix b);
    Matrix operator+(_element value);
    Matrix operator-(Matrix b);
    Matrix operator-(_element value);
    Matrix operator*(Matrix& arg2);
    Matrix operator*(_element scalar);
};

class Vector {
private:
    _index nelements;
    _uint memsize;
    _element *rawmatrix;
    bool survive;
public:
    Vector (_index nelements);
    ~Vector();
    void print();
    void set(_index i, _element value);
    _element get(_index i);
    _element norm2();
    _element normInf();
    _element getnelements();
    Vector inner_product(Vector b);
    Vector operator+(Vector b);
    Vector operator+(_element scalar);
    Vector operator-(Vector b);
    Vector operator-(_element scalar);
    Vector operator*(Vector b);
    Vector operator*(_element scalar);
};

#endif // SIMPLE_LINEAR_ALGEBRA
