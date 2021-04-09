#ifndef SIMPLE_LINEAR_ALGEBRA
#   include "SimpleLA.hpp"

Matrix::Matrix (_index _nrow, _index _ncol) {
    this->nrow = _nrow;
    this->ncol = _ncol;
    this->nelements = nrow * ncol;
    this->memsize = _nrow * _ncol * sizeof(_element);
    this->rawmatrix = new _element[nelements];
    this->survive = false;
}

Matrix::~Matrix() {
    if(!this->survive) delete this->rawmatrix;
}

void
Matrix::print ( ) {
    for (int i = 0; i < this->getnelements(); i++ ) {
        printf ( "internal element %d -> (%d, %d) = %f\n", i, (i/this->ncol), (i%this->ncol), this->get(i));
    }
}

void
Matrix::set(_index r, _index c, _element value) {
    this->rawmatrix[r*ncol + c] = value;
}

void
Matrix::set(_index i, _element value) {
    this->rawmatrix[i] = value;
}

_element
Matrix::get(_index r, _index c) {
    return rawmatrix[r*ncol + c];
}

_element Matrix::get(_index i) {
    return rawmatrix[i];
}

_index
Matrix::getnrow ( ) {
    return nrow;
}

_index
Matrix::getncol ( ) {
    return ncol;
}

_index
Matrix::getnelements ( ) {
    return nelements;
}

Matrix
Matrix::sub(_index r, _index c) {
    _index indexSub = 0, indexMain = 0;
    Matrix subMatrix = Matrix(this->nrow - 1, this->ncol - 1);
    while (indexMain < this->nelements) {
        if (indexMain < (r*this->ncol) || indexMain >= ((r+1)*this->ncol)) {
            if ((indexMain - c) % this->ncol != 0) {
                subMatrix.set(indexSub, this->get(indexMain));
                indexSub ++;
            }
        }
        indexMain ++;
    }
    subMatrix.survive = true;
    return subMatrix;
}

Matrix
Matrix::operator+(Matrix b) {
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

Matrix
Matrix::operator+(_element value) {
    Matrix result = Matrix(this->nrow, this->ncol);
    for (_index i = 0; i < nelements; i++)
        result.set(i, this->get(i) + value);
    result.survive = true;
    return result;
}

Matrix
Matrix::operator-(Matrix b) {
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

Matrix
Matrix::operator-(_element value) {
    Matrix result = Matrix(this->getnrow(), this->getncol());
    result.survive = true;
    for (_index i = 0; i < nelements; i++)
        result.set(i, this->get(i) - value);
    return result;
}

Matrix
Matrix::operator*(Matrix& arg2) {
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

Matrix
Matrix::operator*(_element scalar) {
    Matrix result = Matrix(this->getnrow(), this->getncol());
    result.survive = true;
    for ( _index i = 0; i < this->getnelements(); i++ )
        result.set(i, this->get(i) * scalar);
    return result;
}
#endif // SIMPLE_LINEAR_ALGEBRA
