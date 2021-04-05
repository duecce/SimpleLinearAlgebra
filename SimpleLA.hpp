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
        _element get(_index r, _index c);
        _element get(_index i);
        _index getnrow ( );
        _index getncol ( );
        _index getnelements ( );
        Matrix operator+(Matrix b);
        Matrix operator+(_element value);
        Matrix operator-(Matrix b);
        Matrix operator-(_element value);
        Matrix operator*(Matrix& arg2);
        Matrix operator*(_element scalar);
};

#endif // SIMPLE_LINEAR_ALGEBRA
