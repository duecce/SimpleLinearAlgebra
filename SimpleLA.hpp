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
        void print ( ) {
            for (int i = 0; i < this->getnelements(); i++ ) {
                printf ( "internal element %d = %f\n", i, this->get(i));
            }
        }
        ~Matrix ( ) {
            if(!this->survive) delete this->rawmatrix;
        }
        void set(_index r, _index c, _element value) {
            this->rawmatrix[r*ncol + c] = value;
        }
        void set(_index i, _element value) {
            this->rawmatrix[i] = value;
        }
        _element get(_index r, _index c) {
            return rawmatrix[r*ncol + c];
        }
        _element get(_index i) {
            return rawmatrix[i];
        }
        _index getnrow ( ) {
            return nrow;
        }
        _index getncol ( ) {
            return ncol;
        }
        _index getnelements ( ) {
            return nelements;
        }
        Matrix operator+(Matrix b) {
            if (this->nrow != b.getnrow() || this->ncol != b.getncol() ) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            Matrix result = Matrix(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, b.get(i) + this->get(i));
            result.survive = true;
            return result;
        }
        Matrix operator+(_element value) {
            Matrix result = Matrix(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, this->get(i) + value);
            result.survive = true;
            return result;
        }
        Matrix operator-(Matrix b) {
            if (this->nrow != b.getnrow() || this->ncol != b.getncol() ) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            Matrix result = Matrix(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, b.get(i) - this->get(i));
            result.survive = true;
            return result;
        }
        Matrix operator-(_element value) {
            Matrix result = Matrix(this->getnrow(), this->getncol());
            result.survive = true;
            for (_index i = 0; i < nelements; i++)
                result.set(i, this->get(i) - value);
            return result;
        }
        Matrix operator*(Matrix& arg2) {
            if (this->getncol() != arg2.getnrow()) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            Matrix result = Matrix(this->getnrow(), arg2.getncol());
            result.survive = true;
            _element sum = 0;
            for (_index i = 0; i < arg2.getncol(); i++) {
                for (_index j = 0; j < this->getnrow(); j++ ) {
                    sum = 0;
                    for (_index k = 0; k < this->getncol(); k++ ) {
                        sum += this->get(j, k) * arg2.get(k, i);
                    }
                    result.set(j, i, sum);
                }
            }
            return result;
        }
};

#endif // SIMPLE_LINEAR_ALGEBRA
