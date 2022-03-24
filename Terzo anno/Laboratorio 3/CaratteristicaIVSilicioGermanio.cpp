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
#include"TGraphErrors.h"
#include "TFitResult.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TLegend.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TMultiGraph.h"
#include "TROOT.h"
#include "TRandom.h"
#include "TStyle.h"

void macro(){
    /////////////////////TENSIONE Silicio/////////////////////////////////////////////////
    Float_t xS[10]={400, 450, 500, 550, 600, 650, 700, 720, 760, 800};
     Float_t exS[10]={10,10,10,10,10,10,10,10,10,10};
   ///////////////////////////////////////////////////////////////////////////////////////

    /////////////////CORRENTE Silicio//////////////////////////////////////////
    Float_t yS[10]={0.005, 0.020, 0.068, 0.198, 0.612, 1.783, 4.89, 9.81, 18.4, 30.0};
      Float_t eyS[10]={0,0,0,0,0,0,0,0,0,0};
    ///////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////TENSIONE GERMANIO //////////////////////////////////////////
    Float_t xGe[10]={400, 450, 500, 550, 600, 650, 700, 720, 760, 800};
    Float_t exGe[10]={10,10,10,10,10,10,10,10,10,10};
    //////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////CORRENTE GERMANIO ////////////////////////////////////////
    Float_t yGe[10]={0.005, 0.020, 0.068, 0.198, 0.612, 1.783, 4.89, 9.81, 18.4, 30.0};
      Float_t eyGe[10]={0,0,0,0,0,0,0,0,0,0};
  //////////////////////////////////////////////////////////////////////////////////////////
  
  /////////////////////////////FIT SILICIO/////////////////////////////////////////////////////
      TF1* f1 = new TF1("f1", "[0]*(exp(x/[1])-1.)", 400, 800);
        TGraphErrors* si = new TGraphErrors(10,xS,yS,exS,eyS);
         si->SetTitle("Diodo al Silicio");
    f1->SetParameter(0, 1e-6);
    f1->SetParameter(1,50.);
    f1->SetParName(0, "I0");
    f1->SetParName(1, "eta*Vt");
    si->Fit("f1", "R");
    gStyle->SetOptFit(1111);
///////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////FIT GERMANIO//////////////////////////////////////////////////
    TF1* f2 = new TF1("f2", "[0]*(exp(x/[1])-1.)", 400, 800);
        TGraphErrors* gr = new TGraphErrors(10,xGe,yGe,exGe,eyGe);
          gr->SetTitle("Diodo al Germanio");
    f2->SetParameter(0, 1e-6);
    f2->SetParameter(1,50.);
    f2->SetParName(0, "I0");
    f2->SetParName(1, "eta*Vt");
    gr->Fit("f2", "R");
    gStyle->SetOptFit(1111);
    //////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////
//              GRAFICA                 /////////
///////////////////////////////////////////////////
	TCanvas* c1 = new TCanvas(true);
    c1->Divide(1,2);
////////Silicio////////////////////////////////
    c1->cd(1)->SetLogy();
    si->SetMarkerStyle(4);
    gPad->SetGrid();
    si->Draw("AP");
    c1->SetGrid();
    si->GetXaxis()->SetTitle("Voltage (mV)");
    si->GetYaxis()->SetTitle("Current (mA)");
///////Germanio/////////////////////
    c1->cd(2)->SetLogy();
    gr->SetMarkerStyle(4);
    gPad->SetGrid();
    c1->SetGrid();
    gr->GetXaxis()->SetTitle("Voltage (mV)");
    gr->GetYaxis()->SetTitle("Current (mA)");
    gr->Draw("APE");
    }