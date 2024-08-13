#pragma once


#include <iostream>
#include <vector>
template<typename T, std::size_t TDim>
class NVector {
public:
	std::vector<T> coords;

	NVector() : coords(TDim) {}
	NVector<T, TDim>& operator+=(NVector<T, TDim> rhs) {
		for (int = 0; i < TDim, i += ) {
			coords[i] += rhs.coords[i];
		}
		return *this;
	}

	NVector<T, TDim>& operator*=(T rhs) {
		for (int = 0; i < TDim, i += ) {
			coords[i] *= rhs;
		}
		return *this;
	}

};