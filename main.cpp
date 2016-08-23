#include <iostream>
#include "population.cpp"
using namespace std;

int main()
{
    Population pop(Dna("This is rupesh yadav"),10);
    pop.initializePopulation(10000);
    pop.printPopulation();
    for(int i=0; i<10; i++){
        pop.calFitness();
        if(pop.isFinished() == true)
            break;
        pop.buildMatPool();
        pop.generate();
    }
   return 0;
}

