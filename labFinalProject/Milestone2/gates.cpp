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

	bool* And_N(bool* arr1, bool* arr2, int length){
		bool* output = new bool[length];
		for(int i = 0; i < length; i++)
			output[i] = (arr1[i] && arr2[i]);
		
		return output;
	}

	bool* Or_N(bool* arr1, bool* arr2, int length){
		bool* output = new bool[length];
		for(int i = 0; i < length; i++)
			output[i] = (arr1[i] || arr2[i]);
		
		return output;
	}
	
	bool* Xnor_N(bool* arr1, bool* arr2, int length){
		bool* output = new bool[length];
		for(int i = 0; i < length; i++)
			output[i] = !(arr1[i] ^ arr2[i]);
		
		return output;
	}

	bool* Not_N(bool* arr, int length){
		bool* output = new bool[length];
		bool currInput, currOutput;
		for(int i = 0; i < length; i++){
			currInput = arr[i];
			output[i] = !arr[i];
			currOutput = output[i];
		}

		return output;
	}
}