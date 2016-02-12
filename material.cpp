#include "material.h"
#include <string>

using namespace std;

void material(const string& matName, double& cp, double& hf, double& Tmelt, double& rho)
{
	if (matName == "Acrylic")
	{
		Tmelt = 505.0;    // K
		cp = 1465.0;      // J / kg.K
		hf = 1.0;         // J / kg.K
		rho = 1170.0;     // kg / m ^ 3
		return;
	}
	else if(matName == "Alumina")
	{
		Tmelt = 2305.4;
		cp = 1011.0;
		hf = 106757.0;
		rho = 3990.0;
		return;
	}
	else if(matName == "Aluminum")
	{
		Tmelt = 850.0;
		cp = 1100.0;
		hf = 390000.0;
		rho = 2700.0;
		return;
	}
	else if(matName == "Aluminum1145-H19")
	{
		Tmelt = 919.0;
		cp = 904.0;
		hf = 386116.0;
		rho = 2697.0;
		return;
	}
	else if(matName == "Aluminum2024-T3")
	{
		Tmelt = 856.0;
		cp = 972.7;
		hf = 386116.0;
		rho = 2803.2;
		return;
	}
	else if(matName == "Aluminum2024-T8xx")
	{
		Tmelt = 856.0;
		cp = 972.65;
		hf = 386116.0;
		rho = 2803.0;
		return;
	}
	else if(matName == "Aluminum2219-T8xx")
	{
		Tmelt = 867.0;
		cp = 1006.6;
		hf = 386116.0;
		rho = 2812.8;
		return;
	}
	else if(matName == "Aluminum5052")
	{
		Tmelt = 880.0;
		cp = 900.2;
		hf = 386116.0;
		rho = 2684.9;
		return;
	}
	else if(matName == "Aluminum6061-T6")
	{
		Tmelt = 867.0;
		cp = 896.0;
		hf = 386116.0;
		rho = 2707.0;
		return;
	}
	else if(matName == "Aluminum7075-T6")
	{
		Tmelt = 830.0;
		cp = 1012.35;
		hf = 376788.0;
		rho = 2787.0;
		return;
	}
	else if(matName == "Barium")
	{
		Tmelt = 983.0;
		cp = 285.0;
		hf = 55824.0;
		rho = 3492.0;
		return;
	}
	else if(matName == "Beryllium")
	{
		Tmelt = 1557.0;
		cp = 2635.1;
		hf = 1093220.0;
		rho = 1842.0;
		return;
	}
	else if(matName == "BetaCloth")
	{
		Tmelt = 650.0;
		cp = 837.5;
		hf = 232.6;
		rho = 1581.0;
		return;
	}
	else if(matName == "Brass-Red")
	{
		Tmelt = 1280.0;
		cp = 404.0;
		hf = 195372.0;
		rho = 8746.0;
		return;
	}
	else if(matName == "Brass-Cartridge")
	{
		Tmelt = 1208.0;
		cp = 406.1;
		hf = 179091.0;
		rho = 8521.8;
		return;
	}
	else if(matName == "Brass-Muntz")
	{
		Tmelt = 1174.0;
		cp = 412.35;
		hf = 167461.0;
		rho = 8393.67;
		return;
	}
	else if(matName == "CarbonCarbonReinforced")
	{
		Tmelt = 2144.0;
		cp = 1257.55;
		hf = 37650.0;
		rho = 1688.47;
		return;
	}
	else if(matName == "Cobalt")
	{
		Tmelt = 1768.0;
		cp = 658.45;
		hf = 259600;
		rho = 8862.0;
		return;
	}
	else if(matName == "Cork")
	{
		Tmelt = 922.0;
		cp = 1629.2;
		hf = 2860980.0;
		rho = 261.29;
		return;
	}
	else if(matName == "CopperAlloy")
	{
		Tmelt = 1356.0;
		cp = 430.6;
		hf = 204921.0;
		rho = 8938.0;
		return;
	}
	else if(matName == "CopperBeryllium05")
	{
		Tmelt = 1320.0;
		cp = 397.0;
		hf = 204921.0;
		rho = 8800.0;
		return;
	}
	else if(matName == "CopperBeryllium19")
	{
		Tmelt = 1199.0;
		cp = 452.5;
		hf = 204921.0;
		rho = 8248.6;
		return;
	}
	else if(matName == "Fiberfrax")
	{
		Tmelt = 2089.0;
		cp = 1130.5;
		hf = 1.0;
		rho = 96.10;
		return;
	}
	else if(matName == "Fiberglass")
	{
		Tmelt = 1200.0;
		cp = 1046.8;
		hf = 232.6;
		rho = 1840.35;
		return;
	}
	else if(matName == "FRCI12")
	{
		Tmelt = 1922.0;
		cp = 989.45;
		hf = 1.0;
		rho = 192.22;
		return;
	}
	else if(matName == "GalliumArsenide")
	{
		Tmelt = 1510.0;
		cp = 325.0;
		hf = 1.0;
		rho = 5316.0;
		return;
	}
	else if(matName == "Germanium")
	{
		Tmelt = 1210.7;
		cp = 363.7;
		hf = 430282.6;
		rho = 5320.0;
		return;
	}
	else if(matName == "Gold")
	{
		Tmelt = 1336.0;
		cp = 139.85;
		hf = 64895.0;
		rho = 19300.0;
		return;
	}
	else if(matName == "GraphiteEpoxy1")
	{
		Tmelt = 700.0;
		cp = 879.0;
		hf = 232.6;
		rho = 1550.5;
		return;
	}
	else if(matName == "GraphiteEpoxy2")
	{
		Tmelt = 700.0;
		cp = 879.0;
		hf = 232.6;
		rho = 1550.50;
		return;
	}
	else if(matName == "HastelloyC")
	{
		Tmelt = 1620.0;
		cp = 596.5;
		hf = 309803.0;
		rho = 8920.67;
		return;
	}
	else if(matName == "Hastelloy25")
	{
		Tmelt = 1643.0;
		cp = 498.1;
		hf = 309803.0;
		rho = 9130.0;
		return;
	}
	else if(matName == "Hastelloy188")
	{
		Tmelt = 1635.0;
		cp = 498.1;
		hf = 309803.0;
		rho = 8980.0;
		return;
	}
	else if(matName == "HastelloyN")
	{
		Tmelt = 1623.0;
		cp = 501.7;
		hf = 309803.0;
		rho = 8576.4;
		return;
	}
	else if(matName == "InconelX")
	{
		Tmelt = 1683.2;
		cp = 484.05;
		hf = 311664.0;
		rho = 8297.5;
		return;
	}
	else if(matName == "Inconel600")
	{
		Tmelt = 1683.9;
		cp = 538.45;
		hf = 297206.0;
		rho = 8415.0;
		return;
	}
	else if(matName == "Inconel601")
	{
		Tmelt = 1659.0;
		cp = 632.9;
		hf = 311664.0;
		rho = 8057.29;
		return;
	}
	else if(matName == "Inconel625")
	{
		Tmelt = 1593.0;
		cp = 410.0;
		hf = 311664.0;
		rho = 8440.0;
		return;
	}
	else if(matName == "Inconel718")
	{
		Tmelt = 1571.0;
		cp = 435.0;
		hf = 311664.0;
		rho = 8190.0;
		return;
	}
	else if(matName == "Invar")
	{
		Tmelt = 1700.0;
		cp = 566.55;
		hf = 2740000.0;
		rho = 8050.0;
		return;
	}
	else if(matName == "Iron")
	{
		Tmelt = 1812.0;
		cp = 572.6;
		hf = 272125.0;
		rho = 7865.0;
		return;
	}
	else if(matName == "Lead")
	{
		Tmelt = 600.0;
		cp = 134.65;
		hf = 23958.0;
		rho = 11677.0;
		return;
	}
	else if(matName == "MacorCeramic")
	{
		Tmelt = 1300.0;
		cp = 790.0;
		hf = 236850.0;
		rho = 2520.0;
		return;
	}
	else if(matName == "MagnesiumAZ31")
	{
		Tmelt = 868.0;
		cp = 1212.8;
		hf = 339574.0;
		rho = 1682.0;
		return;
	}
	else if(matName == "MagnesiumHK31A")
	{
		Tmelt = 877.0;
		cp = 1184.75;
		hf = 325619.0;
		rho = 1794.0;
		return;
	}
	else if(matName == "Molybdenum")
	{
		Tmelt = 2899.0;
		cp = 321.85;
		hf = 293057.0;
		rho = 10219.0;
		return;
	}
	else if(matName == "MLI")
	{
		Tmelt = 617.0;
		cp = 1046.6;
		hf = 232.6;
		rho = 772.48;
		return;
	}
	else if(matName == "MP35N")
	{
		Tmelt = 1650.0;
		cp = 583.0;
		hf = 309803.0;
		rho = 8430.0;
		return;
	}
	else if(matName == "Nickel")
	{
		Tmelt = 1728.2;
		cp = 583.35;
		hf = 309803.0;
		rho = 8906.26;
		return;
	}
	else if(matName == "Niobium")
	{
		Tmelt = 2741.0;
		cp = 307.65;
		hf = 290000.0;
		rho = 8570.0;
		return;
	}
	else if(matName == "NOMEX")
	{
		Tmelt = 572.0;
		cp = 1256.0;
		hf = 232.6;
		rho = 1380.0;
		return;
	}
	else if(matName == "Platinum")
	{
		Tmelt = 2046.4;
		cp = 138.45;
		hf = 113967.0;
		rho = 21448.7;
		return;
	}
	else if(matName == "Polyamide")
	{
		Tmelt = 723.0;
		cp = 1130.0;
		hf = 232.6;
		rho = 1420.0;
		return;
	}
	else if(matName == "Polycarbonate")
	{
		Tmelt = 573.0;
		cp = 1260.0;
		hf = 1.0;
		rho = 1665.91;
		return;
	}
	else if(matName == "RCGCoating")
	{
		Tmelt = 1922.0;
		cp = 1224.2;
		hf = 1.0;
		rho = 1665.91;
		return;
	}
	else if(matName == "Rene41")
	{
		Tmelt = 1728.0;
		cp = 630.9;
		hf = 311664.0;
		rho = 8249.0;
		return;
	}
	else if(matName == "Silver")
	{
		Tmelt = 1234.0;
		cp = 233.15;
		hf = 105833.0;
		rho = 10492.0;
		return;
	}
	else if(matName == "SodiumIodide")
	{
		Tmelt = 924.0;
		cp = 84.0;
		hf = 290759.0;
		rho = 3470.0;
		return;
	}
	else if(matName == "StainlessSteel")
	{
		Tmelt = 1700.0;
		cp = 600.0;
		hf = 270000.0;
		rho = 7800.0;
		return;
	}
	else if(matName == "Steel17-4PH")
	{
		Tmelt = 1728.0;
		cp = 666.8;
		hf = 286098.0;
		rho = 7833.03;
		return;
	}
	else if(matName == "Steel21-6-9")
	{
		Tmelt = 1728.0;
		cp = 439.0;
		hf = 286098.0;
		rho = 7832.8;
		return;
	}
	else if(matName == "SteelA-286")
	{
		Tmelt = 1644.0;
		cp = 460.6;
		hf = 286098.0;
		rho = 7944.9;
		return;
	}
	else if(matName == "SteelAISI304")
	{
		Tmelt = 1700.0;
		cp = 545.1;
		hf = 286098.0;
		rho = 7900.0;
		return;
	}
	else if(matName == "SteelAISI316")
	{
		Tmelt = 1644.0;
		cp = 460.6;
		hf = 286098.0;
		rho = 8026.85;
		return;
	}
	else if(matName == "SteelAISI321")
	{
		Tmelt = 1672.0;
		cp = 608.2;
		hf = 286098.0;
		rho = 8026.6;
		return;
	}
	else if(matName == "SteelAISI347")
	{
		Tmelt = 1686.0;
		cp = 554.95;
		hf = 286098.0;
		rho = 7960.0;
		return;
	}
	else if(matName == "SteelAISI410")
	{
		Tmelt = 1756.0;
		cp = 485.7;
		hf = 286098.0;
		rho = 7749.5;
		return;
	}
	else if(matName == "Strontium")
	{
		Tmelt = 1043.0;
		cp = 737.0;
		hf = 95599.0;
		rho = 2595.0;
		return;
	}
	else if(matName == "Teflon")
	{
		Tmelt = 533.0;
		cp = 1674.0;
		hf = 1.0;
		rho = 2162.5;
		return;
	}
	else if(matName == "Titanium")
	{
		Tmelt = 1950.0;
		cp = 600.0;
		hf = 470000.0;
		rho = 4400.0;
		return;
	}
	else if(matName == "Titanium6Al-4V")
	{
		Tmelt = 1943.0;
		cp = 807.5;
		hf = 393559.0;
		rho = 4437.0;
		return;
	}
	else if(matName == "Tungsten")
	{
		Tmelt = 3650.0;
		cp = 157.55;
		hf = 220040.0;
		rho = 19300.0;
		return;
	}
	else if(matName == "Uranium")
	{
		Tmelt = 1405.0;
		cp = 158.95;
		hf = 52523.0;
		rho = 19099.0;
		return;
	}
	else if(matName == "UraniumZirconiumHydride")
	{
		Tmelt = 2144.0;
		cp = 418.7;
		hf = 131419.0;
		rho = 6086.8;
		return;
	}
	else if(matName == "Water")
	{
		Tmelt = 273.0;
		cp = 5490.55;
		hf = 0.1;
		rho = 999.0;
		return;
	}
	else if(matName == "Zerodur")
	{
		Tmelt = 1424.0;
		cp = 1243.55;
		hf = 250000.0;
		rho = 2530.0;
		return;
	}
	else if (matName == "Zinc")
	{
		Tmelt = 692.6;
		cp = 405.3;
		hf = 100942.0;
		rho = 7144.2;
		return;
	};
		
};