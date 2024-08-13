#pragma once
#include "nvector.h"

template<typename T, size_t TDim>
class NBox {
public:
	NVec<T, TDim> center;
	NVec<T, TDim> halfsizes;

	NBox(NVec<T, TDim> cntr = 0, NVec<T, TDim> hfsz = 0) :center(cntr), halfsizes(hfsz) {}
	
	
	bool containPoint(Nec<T, TDim> point) {
		for (int i = 0; i < TDim; i++) {
			T bottom = center[i] - halfsizes[i];
			T top = center[i] + halfsizes[i];
			if point.coords[i] < bottom || point.coords[i] > top{
				return false;
			}
		}
		return true;
	}
	bool intersects(NBox<T, TDim> other) {
		for (int i = 0; i < TDim; i++) {
		    T thistop
			if()
		}
	}

};