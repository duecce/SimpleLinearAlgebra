#include <iostream>

using namespace std;

class MATRIX;
void printMatrix ( MATRIX a );

class MATRIX {
    private:
        typedef int _index;
        typedef double _element;

        unsigned int nrow, ncol;
        unsigned int memsize, nelements;
        _element *rawmatrix;
    public:
        MATRIX (unsigned int _nrow, unsigned int _ncol) {
            nrow = _nrow;
            ncol = _ncol;
            nelements = nrow * ncol;
            memsize = _nrow * _ncol * sizeof(_element);
            this->rawmatrix = new _element[nelements];
        }
        ~MATRIX ( ) {
            delete this->rawmatrix;
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
        MATRIX operator+(MATRIX b) {
            if (this->nrow != b.getnrow() || this->ncol != b.getncol() ) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            MATRIX result = MATRIX(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, b.get(i) + this->get(i));
            return result;
        }
        MATRIX operator+(_element value) {
            MATRIX result = MATRIX(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, this->get(i) + value);
            return result;
        }
        MATRIX operator-(MATRIX b) {
            if (this->nrow != b.getnrow() || this->ncol != b.getncol() ) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            MATRIX result = MATRIX(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, b.get(i) - this->get(i));

            return result;
        }
        MATRIX operator-(_element value) {
            for (_index i = 0; i < nelements; i++)
                this->set(i, this->get(i) - value);
            return *this;
        }
        MATRIX operator*(MATRIX b) {
            if (this->ncol != b.getnrow()) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            MATRIX result = MATRIX(this->nrow, b.ncol);
            _element sum = 0;
            for (_index i = 0; i < b.getncol(); i++) {
                for (_index j = 0; j < this->getnrow(); j++ ) {
                    sum = 0;
                    for (_index k = 0; k < this->getncol(); k++ ) {
                        sum += this->get(j, k) * b.get(k, i);
                    }
                    result.set(j, i, sum);
                }
            }
            return result;
        }
};

void printMatrix ( MATRIX a ) {
    // print matrix
    for (int i = 0; i < a.getnelements(); i++ ) {
        printf ( "element %d = %f\n", i, a.get(i));
    }
}

int main(int argc, char **argv) {
    MATRIX a = MATRIX(3, 4);
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
    MATRIX b = MATRIX(4, 2);
    b.set(0, 2);
    b.set(1, 2);
    b.set(2, 3);
    b.set(3, 2);
    b.set(4, 1);
    b.set(5, 2);
    b.set(6, 2);
    b.set(7, 1);

    MATRIX c = a * b;
    printf("c = a * b\n" );
    printMatrix(c);

    c = c + 10.0;
    printf ( "c = c + 10.0\n" );
    printMatrix(c);
    return 0;
}
