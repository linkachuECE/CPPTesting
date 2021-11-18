#include "gates.h"

namespace gate {

	bool Not(bool x) {
		return !x;
	}

	bool And(bool x, bool y) {
		return x & y;
	}

	bool And3(bool x, bool y, bool z){
		return x & y & z;
	}

	bool Nand(bool x, bool y) {
		return !(x & y);
	}

	bool Or(bool x, bool y) {
		return x | y;
	}

	bool Or3(bool x, bool y, bool z) {
		return x | y | z;
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
}