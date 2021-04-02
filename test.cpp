#include <iostream>

using namespace std;

class MATRIX {
    private:
        typedef unsigned char _index;
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
        void set (_index r, _index c, _element value) {
            this->rawmatrix[r*ncol + c] = value;
        }
        void set (_index i, _element value) {
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
        unsigned int getnelements ( ) {
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
            MATRIX result = MATRIX(this->nrow, this->ncol);
            for (_index i = 0; i < nelements; i++)
                result.set(i, this->get(i) - value);
            return result;
        }
        MATRIX operator*(MATRIX b) {
            if (this->ncol != b.getnrow()) {
                throw std::invalid_argument("different size exception");
                return *this;
            }
            MATRIX result = MATRIX(this->nrow, b.ncol);
            _element sum;
            for (int i = 0; i < b.ncol; i++) {
                for (int j = 0; j < this->nrow; j++ ){
                    sum = 0;
                    for (int k = 0; k < this->ncol; k++ )
                        sum += this->get(j, k) * b.get(k, i);
                    result.set(j, i, sum);
                }
            }
            return result;
        }
};

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
    MATRIX c = MATRIX(2, 2);
    c.set(0, 2);
    c.set(1, 3);
    c.set(2, 2);
    c.set(3, 4);
    c = a * b * c;
    for ( int i = 0; i < c.getnelements(); i ++ )
        cout << "element: " << i << " = " << c.get(i) << endl;
    c = c + 10.0;
    for ( int i = 0; i < c.getnelements(); i ++ )
        cout << "element: " << i << " = " << c.get(i) << endl;
    return 0;
}
