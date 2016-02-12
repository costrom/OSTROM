#ifndef ATMPROPS_H
#define ATMPROPS_H

class atmprops
{
    public:
        double rhoO2, rhoN2, rhoNO, rhoH2, rhoCO2, rhoCH4;
        double rhoO, rhoN, rhoH, rhoAr, rhoNe, rhoKr, rhoHe;
        
        int model;
        
        atmprops(const int& atmType)
        {
            model = atmType;
        };
        
        void getProps(double& h)
        {
            
        };
}

#endif
