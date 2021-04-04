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

#endif // SIMPLE_LINEAR_ALGEBRA
