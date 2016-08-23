#include <iostream>
#include <vector>
#include "dna.cpp"
using namespace std;

class Population{
private:
    vector<Dna> population;
    vector<Dna> matingPool;
    int generation;
    bool finished;
    Dna target;
    float mutatoinRate;
    float perfectScore = 1;
public:
    Population(Dna target,float mutationRate):target{target},mutatoinRate{mutatoinRate},finished{false}{}
    
    void initializePopulation(int popMax){
        int len = target.gens.length();
        for(int j=0; j<popMax; j++){
            population.push_back(Dna(len));
        }
        cout << "population initialized with " << population.size() << endl;
    }
    void printPopulation() const{
        for(auto elem: population){
            cout << elem.gens << endl;
        }
    }
    void calFitness(){
        for(auto& elem: population){
            elem.calFitness(target);
            if(elem.fitness == target.fitness){
                cout << "found it";
                cout << elem.gens << endl;
                finished = true;
                break;
            }
        }
    }
    
    float getMaxScore(){
        float maxScore =0.0;
        for(auto& elem: population){
            //cout << "elem.fitness " << elem.fitness << endl;
            if(maxScore < elem.fitness)
                maxScore = elem.fitness;
        }
        cout << maxScore << endl;
        return maxScore;
    }
    
    void buildMatPool(){
        float max = getMaxScore();
        if(max<=0){
            cout << "max calculation is zero";
            max = 1;
        }
        cout << "maxScore " << max << endl;
        for(auto & elem: population){
            float n = floor(elem.fitness/max);
            for(int i=0; i<n*100; i++){
                matingPool.push_back(elem);
            }
        }
    }
    void generate(){
        for(int i=0; i<population.size(); i++){
            int a = floor(rand()%matingPool.size());
            int b = floor(rand()%matingPool.size());
            Dna partnerA = matingPool[a];
            Dna partnerB = matingPool[b];
            Dna child = partnerA.crossover(partnerB);
            child.mutate(mutatoinRate);
            population[i] = child;
        }
    }
    bool isFinished(){
        return finished;
    }
};
