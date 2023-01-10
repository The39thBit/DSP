//BY: Abdurrahman Aliyu Gambo || Jan./2023 || DSP

#include <vector>
#include <iostream>
#include <cmath>

class DiscreteSignal{
    public:
    std::vector<double> signal;
    int zero_index = 0;
void signalinit(std::vector<double>signalvector, int zero){
    signal = signalvector;
    zero_index = zero;

}
};

void Convolution(DiscreteSignal xn, DiscreteSignal hn ){
    //Initializing Values
    
    int xnzero = xn.zero_index;
    int xnstart = 0 - xnzero;
    int hnzero = hn.zero_index;
    int hnstart = 0 - hnzero;
    int ns = xnstart+ hnstart;
    int ne = (xn.signal.size()-1-xnzero)+(hn.signal.size()-1-hnzero);
    DiscreteSignal yn; 

    bool convcont = true;
    std::cout<<"xnzero "<< xnzero<<" hnzero "<<hnzero<< " ns "<< ns <<" ne "<< ne <<std::endl;
                      
   

    //SignalConvolution
        for(int i = 0; i < xn.signal.size();i ++){
            //Looping through xn values multiplying each with each yn value once.
            for(int j = 0;j<hn.signal.size();j++){
                double temp = xn.signal[i]*hn.signal[j];
                //Write Value to yn, if yn value doesn't exist it makes it, if it does it simple adds to it
                if(yn.signal.size()>1){
                    if(yn.signal.size()-1<(i+j)){
                        //std::cout<<"Entered if on loop: "<< i<<" "<<j<<std::endl;
                        yn.signal.push_back(temp);
    
                    }
                    else {
                       // std::cout<<"Entered Else on loop: "<< i<<" "<<j<<std::endl;
                        yn.signal[i+j] += temp;
                        std::cout<<"y[n] at "<< i+j<<" "<<yn.signal[i+j]<<std::endl;
                    }
                }
                else{
                    yn.signal.push_back(temp);
                    std::cout<<"y[n] at "<< i+j<<" "<<yn.signal[i+j]<<std::endl;

                }
            }
        }
    //TEST 
    std::cout<<"Test 1"<<std::endl;
    if((ne-ns)==yn.signal.size()-1){
        std::cout<<"Passed"<<std::endl;
    }
    else{
        std::cout<<"Failed"<<std::endl;
    }
    std::cout<<"Length as determined by ne and ns "<<ne-ns<<" Length of y[n] "<<yn.signal.size()-1<<std::endl;
    for(int m = 0; m<yn.signal.size();m++){
        std::cout<<yn.signal[m]<<" ";

    }
    std::cout<<std::endl;

}

int main(){
std::vector<double> XN = {3.26794919243112, 3.02323177390689, 4.04508497187474, 4.67097706903124, 3.27713577944361, -5.69584557730837e-15,	-3.27713577944362,	-4.67097706903124,	-4.04508497187474,	-3.02323177390689,	-3.26794919243112,	-4.75528258147577,	-5.77713577944362,	-4.67097706903124,	-1.54508497187474,	1.73205080756888,	3.27713577944361,	2.93892626146237,	2.31303416430586,	3.02323177390689,	5,	6.48733338904465,	5.77713577944362,	2.93892626146237,	-0.186965835694140,	-1.73205080756888,	-1.54508497187474,	-1.20687545389349,	-2.31303416430586,	-4.75528258147577,	-6.73205080756888,	-6.48733338904465,	-4.04508497187474,	-1.20687545389349,	0.186965835694141,	3.85887537858734e-15,	-0.186965835694139,	1.20687545389349,	4.04508497187474,6.48733338904464,6.73205080756888};
DiscreteSignal Input;
Input.signalinit(XN,40);
DiscreteSignal ImpulseResponse;
std::vector<double> HN = {1, 0,	1,	1,	2,	4,	1,	1,	4,	1,	-5,	6,	7,	4,	1,	3,	1,	2,	3,	1,	3,	-1,	2,	-4,	-2};
ImpulseResponse.signalinit(HN,20);
Convolution(Input,ImpulseResponse);
};