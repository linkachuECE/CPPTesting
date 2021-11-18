#ifndef GATES_H
#define GATES_H
#include <vector>
#include <functional>
#include <utility>

namespace gate {

	bool Not(bool x);

	bool And(bool x, bool y);

	bool And3(bool x, bool y, bool z);

	bool Nand(bool x, bool y);

	bool Or(bool x, bool y);

	bool Or3(bool x, bool y, bool z);

	bool Nor(bool x, bool y);

	bool Xor(bool x, bool y);

	bool Xnor(bool x, bool y);
}

#endif