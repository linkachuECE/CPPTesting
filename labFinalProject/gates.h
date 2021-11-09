#ifndef GATES_H
#define GATES_H
#include <vector>
#include <functional>
#include <utility>

namespace gate {

	bool Not(bool x);

	bool And(bool x, bool y);

	bool Nand(bool x, bool y);

	bool Or(bool x, bool y);

	bool Nor(bool x, bool y);

	bool Xor(bool x, bool y);

	bool Xnor(bool x, bool y);

	bool And_N(bool* arr, int length);

	bool Or_N(bool* arr, int length);

}

#endif