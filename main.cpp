#include "headers.h"
using namespace std;

namespace animals {
	enum animals{
		chicken,
		duck,
		cat,
		elephant,
		dog,
		snake,
		animalMaxLength
	};
}  


int main()
{
	int animalLegCount[animals::animalMaxLength]{};

	animalLegCount[animals::chicken] = 2;
	animalLegCount[animals::duck] = 2;
	animalLegCount[animals::cat] = 4;
	animalLegCount[animals::elephant] = 4;
	animalLegCount[animals::dog] = 4;
	animalLegCount[animals::snake] = 0;

	return 0;
}