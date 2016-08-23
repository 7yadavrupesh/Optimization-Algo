#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Dna{
public:
    string gens;
    double fitness;
        Dna(){gens="";fitness = 0;}
        Dna(string str):gens{str}{}
        Dna(int len):gens(len,'a'){
            for(int i=0; i<len; i++){
                gens[i] = getNewChar();
            }
        }
        
        char getNewChar(){
            char r = (char)rand()%(122-63+1)+63;
            if(r == 63) r=' ';
            if(r == 64) r='.';
            return r;
        }
        void calFitness(Dna& target){
            float score=0;
            for(int i=0; i<target.gens.length(); i++){
                if(gens[i] == target.gens[i])
                    score++;
            }
            fitness = score;
           // cout << fitness << endl;
        }
        Dna crossover(Dna& partner){
            Dna child(partner.gens.length());
            int mid = floor(rand()%partner.gens.length());
            for(int i=0; i<partner.gens.length(); i++){
                if(i>mid)
                    child.gens[i] = gens[i];
                else
                    child.gens[i] = partner.gens[i];
            }
            //cout << "created Child " << child.gens << endl;
            return child;
        }
        void mutate(int mutationRate){
            for(int i=0; i<gens.length(); i++){
                int r = floor(rand()%100+1);
                cout << "r" << r << "mutationRate" << mutationRate << endl;
                if(mutationRate>r)
                    gens[i] = getNewChar();
            }
            //cout << "gens: " << gens << endl;
        }
};
