#include <iostream>
#include<vector>
#include<cmath>
#include<random>
#include<ctime>
#include<time.h>
#include<algorithm>
#include <chrono>
#include <thread>
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TFitResult.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TLegend.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TROOT.h"
#include "TRandom.h"
#include "TStyle.h"
constexpr int dimension =1e5;
constexpr int days =10000 ;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

class GRID {
public:
    GRID(int n,int days) : m_state(n) , counter(n) {
        dim = n;
        srand(time(NULL));
        int casual = 0;
        for (int i = 0; i < dim; ++i) {
            int casual = rand() % 2;
            m_state[i] = 10;
            
        }
    }
    void Evolve() {
        
        srand(time(NULL));
        int x=0;
        for (int i = 0; i < dim;i++) {
            x = rand() % 2;
            if (x == 1) {
                if (m_state[i] >= 0 && m_state[i + 1] > 0) {
                    m_state[i] = m_state[i] + 1;
                    m_state[i + 1] = m_state[i + 1] - 1;
                }
               
            }
                if(x==0) {
                    if (m_state[i] > 0 && m_state[i + 1] >= 0) {
                        m_state[i] = m_state[i] - 1;
                        m_state[i + 1] = m_state[i + 1] + 1;
                    }
               
                }
                else {
                    m_state[i] = m_state[i];
                    m_state[i + 1] = m_state[i + 1];
                }
            ++i;
            
            
        }
        Counter();
        std::random_shuffle(m_state.begin(), m_state.end());
    }  
    void Draw() {
        day++;
        int somma = 0;
        for (int i = 0; i < 50; ++i) {
            if (day == days) {
               std::cout << "Denaro " << i << " =" << counter[i] << "\n";
                //std::cout<<m_state[i]<<" ";
                 }
                 //std::this_thread::sleep_for(std::chrono::milliseconds(100));      
            }
        //std::cout<<"\n";

        }
    int GetSize(){
        return counter.size();
    }  
    int GetCounterElement(int i){
        return counter[i];
    }
    void Counter() {
        for (int i = 0; i < 100; i++) {
            counter[i]=std::count(m_state.begin(), m_state.end(),i);
        }
    }
private:
    int day = 0;
    int dim=0;
    std::vector<int> m_state;
    std::vector<int> counter;
};
void macro()
 {
      TH1F* h1 =    new TH1F("Money", "Money",50,0,50);
    gROOT->SetStyle("Plain");
	gStyle->SetPalette(57);
	gStyle->SetOptFit(1111);
	gStyle->SetOptStat(1111);
    GRID Economy(dimension,days);
    for (int i = 0; i < days; ++i) {
        Economy.Evolve();
        Economy.Draw();
    }
    for(int i=0;i<50;++i){
        for(int j=0;j<Economy.GetCounterElement(i);++j){
        h1->Fill(i);
        }
    }
    TCanvas* firstFit = new TCanvas("Fit1", "Fit1");
	gPad->SetGrid();
	gPad->SetFillColor(42);
	gPad->SetFrameFillColor(44);
	h1->SetFillColor(kBlue - 2);
	gPad->SetGrid();
	gPad->SetFrameFillColor(19);
    h1->Draw();
}
