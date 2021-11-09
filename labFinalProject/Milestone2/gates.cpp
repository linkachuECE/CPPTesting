#include "gates.h"
#include <iostream>

#define DEBUG true

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

	void debugNGateInput(char* gateName, int length, bool* arr1, bool* arr2 = nullptr){
		std::cout << "Input to " << gateName << ":" << std::endl;
		std::cout << " Input 1: ";
		for(int i = 0; i < length; i++)
			std::cout << arr1[i] << " ";
		std::cout << std::endl;
		if(arr2){
			std::cout << " Input 2: ";
			for(int i = 0; i < length; i++)
				std::cout << arr2[i] << " ";
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	void debugNGateOutput(char* gateName, int length, bool* arr){
		std::cout << "Output of " << gateName << ":" << std::endl;
		for(int i = 0; i < length; i++)
			std::cout << arr[i] << " ";
		
		std::cout << std::endl << std::endl;
	}

	bool* And_N(bool* arr1, bool* arr2, int length){
		bool* output = new bool[length];
		for(int i = 0; i < length; i++)
			output[i] = (arr1[i] && arr2[i]);
		
		if(DEBUG) debugNGateInput("AND" , length, arr1, arr2);
		if(DEBUG) debugNGateOutput("AND", length, output);
		return output;
	}

	bool* Or_N(bool* arr1, bool* arr2, int length){

		bool* output = new bool[length];
		for(int i = 0; i < length; i++)
			output[i] = (arr1[i] || arr2[i]);
		
		if(DEBUG) debugNGateInput("OR", length, arr1, arr2);
		if(DEBUG) debugNGateOutput("OR", length, output);
		return output;
	}
	
	bool* Xnor_N(bool* arr1, bool* arr2, int length){

		bool* output = new bool[length];
		for(int i = 0; i < length; i++)
			output[i] = !(arr1[i] ^ arr2[i]);
		
		if(DEBUG) debugNGateInput("XNOR", length, arr1, arr2);
		if(DEBUG) debugNGateOutput("XNOR", length, output);
		return output;
	}

	bool* Not_N(bool* arr, int length){

		bool* output = new bool[length];
		for(int i = 0; i < length; i++){
			output[i] = !arr[i];
		}

		if(DEBUG) debugNGateInput("NOT", length, arr);
		if(DEBUG) debugNGateOutput("NOT", length, output);
		return output;
	}
}