#include <iostream>

using namespace std;

enum {
    DIFFERENT_SIZE_EXCTEPTION
};

class MATRIX {
    private:
        unsigned int nrow, ncol;
        unsigned int memsize, nelements;
        double *rawmatrix;
        typedef unsigned char _index;
        typedef double _element;
    public:
        MATRIX (unsigned int _nrow, unsigned int _ncol) {
            nrow = _nrow;
            ncol = _ncol;
            nelements = nrow * ncol;
            memsize = _nrow * _ncol * sizeof(double);
            this->rawmatrix = new double[nelements];
        }
        ~MATRIX ( ) {
            delete this->rawmatrix;
        }
        void set (_index r, _index c, _element value) {
            this->rawmatrix[r*(ncol + 1) + c] = value;
        }
        // @overload
        void set (_index i, _element value) {
            this->rawmatrix[i] = value;
        }
        _element get(_index r, _index c) {
            return rawmatrix[r*(ncol+1) + c];
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
            MATRIX result = MATRIX(this->getnrow(), this->getncol());
            if (this->nrow != b.getnrow() || this->ncol != b.getncol() ) {
                throw DIFFERENT_SIZE_EXCTEPTION;
                return result;
            }
            for (int i = 0; i < nelements; i++){
                result.set(i, b.get(i) + this->get(i));
            }
            return result;
        }
};

int main(int argc, char **argv) {
    MATRIX a = MATRIX(2, 2);
    a.set(0, 1);
    a.set(1, 2);
    a.set(2, 3);
    a.set(3, 4);
    MATRIX b = MATRIX(2, 2);
    b.set(0, 5);
    b.set(1, 6);
    b.set(2, 7);
    b.set(3, 8);
    MATRIX c = a + b;
    for ( int i = 0; i < c.getnelements(); i ++ ) {
        cout << "elements: " << i << " = " << c.get(i) << endl;
    
    return 0;
}