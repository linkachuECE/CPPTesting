#include "gates.h"

namespace gate {

	bool Not(bool x) {
		return !x;
	}

	bool And(bool x, bool y) {
		return x & y;
	}

	bool Nand(bool x, bool y) {
		return !(x & y);
	}

	bool Or(bool x, bool y) {
		return x | y;
	}

	bool Nor(bool x, bool y) {
		return !(x | y);
	}

	bool Xor(bool x, bool y) {
		return x ^ y;
	}

	bool Xnor(bool x, bool y) {
		return !(x ^ y);
	}

	bool And_N(bool* arr, int length){
		bool output{true};
		for(int i = 0; i < length; i++)
			if(arr[i] == 0)
				output = false;
		
		return output;
	}

	bool Or_N(bool* arr, int length){
		bool output{false};
		for(int i = 0; i < length; i++)
			if(arr[i] == 1){
				output = true;
				break;
			}
		
		return output;
	}
}