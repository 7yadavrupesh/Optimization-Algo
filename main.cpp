#include <iostream>
#include "population.cpp"
using namespace std;

int main()
{
    Population pop(Dna("This is rupesh yadav"));
    pop.setMutationRate(.1);
    pop.initializePopulation(1000000);
    //pop.printPopulation();
    for(int i=0; i<5; i++){
        pop.calFitness();
        if(pop.isFinished() == true)
            break;
        pop.buildMatPool();
        pop.generate();
    }
   return 0;
}

