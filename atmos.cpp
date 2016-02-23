#include "atmos.h"
#include "atmprops.h"
#include "usstdatm1976.h"

using namespace std;

void atmos(atmprops& atmProperties)
{
	switch (atmProperties.model)
	{
		case 1: // US STD ATM 1976
			usstdatm1976(atmProperties);
			break;
		case 2: // MSISE
			//msise(atmProperties);
			break;
		case 3: // Jacchia
			//jacchia(atmProperties);)
			break;
		case 4: // GRAM
			//gram99(atmProperties);
			break;
		default:
			break;
	}
	return;
};
