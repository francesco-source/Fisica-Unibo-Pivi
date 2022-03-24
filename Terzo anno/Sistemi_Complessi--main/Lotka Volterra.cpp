#include<iostream>
#include<vector>
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
#include"TGraph.h"
#include "TMatrixD.h"
#include "TMultiGraph.h"
#include "TROOT.h"
#include "TRandom.h"
#include "TStyle.h"
void expo(){
    double x_t=1;
    double x_t1=0;
    const int loops=1000;
    double delta=0.001;
    Double_t points[loops];
    Double_t time[loops];
    for(int i=0;i<loops;++i){
      x_t1= x_t+delta*x_t;
      points[i]=x_t1;
      time[i]=i*delta;
      x_t=x_t1;
    }
     TCanvas* c1=new TCanvas(true);
    TGraph* Graph= new TGraph(loops,time,points);
    Graph->Draw();
}
void runge_kutta(){
  double xt1=0;
  double xt=1;
  double xt0=1;
const int loops=1000;
    double delta=0.001;
    Double_t points[loops];
    Double_t time[loops];
   for(int i=0;i<loops;++i){
      xt1= xt0+2*delta*xt;
      points[i]=xt1;
      time[i]=i*delta;
      xt0=xt;
      xt=xt1;

      
    }
    TCanvas* c=new TCanvas(true);
    TGraph* Graph= new TGraph(loops,time,points);
    Graph->Draw();
}
void Secondo_ordine(){
  double xt=0;
  double xt1=0;
  double yt1=1;
  double yt=1;
  double XvalMax=20;
  int nPoints=10000;
  double sigma=XvalMax/nPoints;
  Float_t points[nPoints];
  Float_t time[nPoints];
  for(int i=0;i<nPoints;++i){

    xt1=yt*sigma+xt;
    yt=yt-xt*sigma;
    xt=xt1;
    points[i]=xt;
    time[i]=i*sigma;
  }
  TGraph* Graph= new TGraph(nPoints,time,points);
  Graph->Draw();
}

void SecondoOrdine(){    //x'' +x*t=0;
   double xt=1;
  double xt1=0;
  double yt1=0;
  double yt=1;
  double XvalMax=20;
  int nPoints=10000;
  double sigma=XvalMax/nPoints;
Float_t points[nPoints];
Float_t time[nPoints];
for(int i=0;i<nPoints;++i){
  xt1=xt+yt*sigma;
  yt=yt-xt*i*sigma*sigma;
  xt=xt1;
  points[i]=xt;
    time[i]=i*sigma;
}
TGraph* Graph= new TGraph(nPoints,time,points);
  Graph->Draw();
}
void LotkaVolterra(){
  double XvalMax=100;
  int nPoints=10000;
  double sigma=XvalMax/nPoints;
  double herbivour=100.6;
  double predator=20;
  double predator0=20;
  double herbivour0=100;
  double herbivour1=0;
  double predator1=0;
  std::vector<double> param={1,0.02,1,0.01};
  Float_t points[nPoints];
  Float_t predatori[nPoints];
  Float_t time[nPoints];
  for(int i=0;i<nPoints;++i){
  herbivour1=herbivour0+2*sigma*param[0]*herbivour-2*param[1]*sigma*herbivour*predator;
  predator1=predator0-2*param[2]*sigma*predator +2*param[3]*sigma*herbivour*predator;
    predator0=predator;
    herbivour0=herbivour;
  herbivour=herbivour1;
  predator=predator1;
  predatori[i]=predator;
  points[i]=herbivour;
  time[i]=sigma*i;

}
TMultiGraph *mg = new TMultiGraph();
TGraph* Graph= new TGraph(nPoints,time,points);
  TGraph* Predat= new TGraph(nPoints,time,predatori);
  Predat->SetMarkerColor(2);
  Predat->SetMarkerStyle(7);
  Predat->SetMarkerSize(1);
   Graph->SetMarkerColor(4);
  Graph->SetMarkerStyle(7);
  Graph->SetMarkerSize(1);
  mg->Add(Graph);
  mg->Add(Predat);
  TCanvas* c=new TCanvas(true);
  TGraph* Equilibrium=new TGraph(nPoints,points,predatori);
  Equilibrium->Draw();
  TCanvas* c1=new TCanvas(true);
  mg->Draw("APE");
}


void Lotka(){
  double herb0=100;
  double pred0=20;
  double herb=100;
  double pred=20;
  double herb1=0;
  double pred1=0;
  int NPoints=10000;
  Float_t predat[NPoints] ;
  Float_t pray[NPoints];
  Float_t time[NPoints];
  double XMax=100;
  double sigma=XMax/NPoints;
  Float_t param[5]={1,0.02,1,0.01,500};
  for(int i=0;i<NPoints;++i){
    herb1= herb+herb*param[0]*sigma*(1-(herb/param[4]))-param[1]*herb*pred*sigma;
    pred1=pred-pred*param[2]*sigma+sigma*param[3]*herb*pred;
    herb0=herb;
    pred0=pred;
    herb=herb1;
    pred=pred1;
    predat[i]=pred1;
    pray[i]=herb1;
    time[i]=i*sigma;
  }
  TMultiGraph *mg = new TMultiGraph();
TGraph* Pray= new TGraph(NPoints,time,pray);
  TGraph* Predat= new TGraph(NPoints,time,predat);
   TGraph* Equilibrium=new TGraph(NPoints,pray,predat);
  Predat->SetMarkerColor(2);
  Predat->SetMarkerStyle(8);
  Predat->SetMarkerSize(1);
   Pray->SetMarkerColor(4);
  Pray->SetMarkerStyle(8);
  Pray->SetMarkerSize(1);
  mg->Add(Pray);
  mg->Add(Predat);
  TCanvas* OScillation= new TCanvas(true);
  OScillation->SetGrid();
  Equilibrium->Draw();
  TCanvas* SpaceofFase= new TCanvas(true);
  SpaceofFase->SetGrid();
  mg->Draw("AP");
}






/*void LotkaVolterra2Prede(){
  double pred0=40;
  double prayA0=20;
  double prayB0=50;
  double pred=40;
  double prayA=20;
  double prayB=50;
  double pred1=0;
  double prayA1=0;
  double prayB1=0;
   int NPoints=100;
  Float_t predatv[NPoints] ;
  Float_t prayAv[NPoints];
  Float_t prayBv[NPoints];
  Float_t timev[NPoints];
  double XMax=100;
  double sigma=XMax/NPoints;
  double k[3]={-1,0.10,0.5};
  std::vector<double> a= {1,1,-1,1,-1,-1};
  std::vector<double> b={100,500,400};
  for(int i=0;i<NPoints-1;i++){
  prayA1=prayA+sigma*k[0]*prayA-(1./b[0])*(prayB+pred)*prayA*sigma;
  prayB1=prayB+sigma*k[1]*prayB-(1./b[1])*(-prayA+pred)*prayB*sigma;
  pred1=pred+sigma*k[2]*pred-(1./b[2])*(-prayA-prayB)*sigma*pred;
  /*prayA0=prayA;
  prayB0=prayB;
  pred0=pred;
  prayA=prayA1;
  prayB=prayB1;
  pred=pred1;
  prayAv[i]=prayA1;
  prayBv[i]=prayB1;
  predatv[i]=pred1;
  timev[i]=i*sigma;
  }
  TMultiGraph *mg = new TMultiGraph();
  TGraph* PrayA= new TGraph(NPoints,timev,prayAv);
  TGraph* Pred= new TGraph(NPoints,timev,predatv);
  Pred->Draw();
  TCanvas*c= new TCanvas(true);
  TGraph* PrayB= new TGraph(NPoints,timev,prayBv);
  Pred->SetMarkerColor(2);
  Pred->SetMarkerStyle(8);
  Pred->SetMarkerSize(1);
  PrayA->SetMarkerColor(4);
  PrayA->SetMarkerStyle(8);
  PrayA->SetMarkerSize(1);
  PrayB->SetMarkerColor(5);
  PrayB->SetMarkerStyle(9);
  PrayB->SetMarkerSize(1);
  mg->Add(PrayA);
  mg->Add(Pred);
  mg->Add(PrayB);
  mg->Draw("AP");
}*/


void CicloAttrattoreAttrattore(){
  //pagina 33 del libro di modelling complex sistems
  double pray0=1.5;
  double pred0=0.5;
  double pray=2;
  double pred=1.6;
  double pred1=0;
  double pray1=0;
   int NPoints=10000;
  Float_t predatv[NPoints] ;
  Float_t prayv[NPoints];
  Float_t predv[NPoints];
  Float_t timev[NPoints];
  double XMax=100;
  double sigma=XMax/NPoints;
  double k=3.5;
  double y=0.5;
  double b=1;
  double ah=(1-(1/k))*(b+1);
  double ap=y*(b+1);
  for(int i=0;i<NPoints;++i){
    pray1= pray +pray*sigma*(1-(pray/k))-((ah*pred*pray)/(b+pray))*sigma;
    pred1=pred+((ap*pred*pray)/(b+pray))*sigma-y*pred*sigma;

  pred=pred1;
  pray=pray1;
  prayv[i]=pray;
  predv[i]=pred;
  timev[i]=i*sigma;
  }
  TCanvas* canvas1= new TCanvas(true);
TGraph* Hamilton=new TGraph(NPoints,prayv,predv);
Hamilton->Draw();
 TCanvas* canvas2= new TCanvas(true);
  TMultiGraph *mg = new TMultiGraph();
TGraph* Pred=new TGraph(NPoints,timev,predv);
TGraph* Pray= new TGraph(NPoints,timev,prayv);
Pray->SetMarkerColor(2);
Pred->SetMarkerColor(4);
Pred->SetMarkerStyle(7);
Pray->SetMarkerStyle(7);
mg->Add(Pray);
mg->Add(Pred);
mg->Draw("AP");
}
void Leslie_predator_pray_model(){}
void Competition2Specie(){
  // pagina 587 document 4.

}

//FUNZIONAAAAAAAAAAAAAAAAAAAAAAAAAAA
void Crescita_illimitata3Specie(){
  double k[3]={0.09,0.06,0.05};
  double b[3]={400,500,250};
  double xt0=2;
  double xt1=0;
  double xt=30;
  double yt1=0;
  double yt=10;
  double yt0=50;
  double zt1=0;
  double zt=20;
  double zt0=40;
     int NPoints=10000;
  Float_t xv[NPoints] ;
  Float_t yv[NPoints];
  Float_t zv[NPoints];
  Float_t timev[NPoints];
  double XMax=500;
  double sigma=XMax/NPoints;
  for(int i=0;i<NPoints;++i){

    xt1= xt+(k[0]-(1/(b[0]))*(yt+zt))*sigma*xt;
    yt1=yt+(-k[1]+(1/(b[1]))*(+xt+zt))*sigma*yt;
    zt1=zt+(k[2]-(1/(b[2]))*(-xt+yt))*sigma*zt;
    xv[i]=xt1;
    yv[i]=yt1;
    zv[i]=zt1;
    xt=xt1;
    yt=yt1;
    zt=zt1;
    timev[i]=sigma*i;
  }
  
  TMultiGraph *mg =new TMultiGraph();
  TGraph* x= new TGraph(NPoints,timev,xv);
  TGraph* y= new TGraph(NPoints,timev,yv);
  TGraph* z= new TGraph(NPoints,timev,zv);
  TCanvas* c= new TCanvas(true);
   x->SetMarkerColor(46);
    y->SetMarkerColor(4);
     z->SetMarkerColor(8);
    x->SetMarkerStyle(7);
    y->SetMarkerStyle(7);
    z->SetMarkerStyle(7);
mg->Add(x);
mg->Add(y);
mg->Add(z);
mg->Draw("AP");
}

void Competizione_Crescita_Limitata(){
  double k[3]={0.04,0.06,0.08};
  double b[3]={400,400,300};
  double limit[3]={100,100};
  double xt0=30;
  double xt1=0;
  double xt=30;
  double yt1=0;
  double yt=10;
  double yt0=10;
  double zt1=0;
  double zt=20;
  double zt0=20; 
      int NPoints=10000;
  Float_t xv[NPoints] ;
  Float_t yv[NPoints];
  Float_t zv[NPoints];
  Float_t timev[NPoints];
  double XMax=500;
  double sigma=XMax/NPoints;
  for(int i=0;i<NPoints;++i){
    xt1=xt+(k[0]*(1-(xt/limit[0]))-(1/b[0])*yt)*xt*sigma;
    yt1=yt+(-k[1]+((1/b[1])*(xt+zt)))*sigma*yt;
    zt1=zt+(k[2]*(1-(zt/limit[1]))-(1/b[2])*yt)*sigma*zt;
    xt0=xt;
    yt0=yt;
    zt0=zt;
    xt=xt1;
    yt=yt1;
    zt=zt1;
    xv[i]=xt;
    yv[i]=yt;
    zv[i]=zt;
    timev[i]=sigma*i;

  }
  TMultiGraph* mg=new TMultiGraph();
  TGraph* X=new TGraph(NPoints,timev,xv);
  TGraph* Y=new TGraph(NPoints,timev,yv);
  TGraph* Z=new TGraph(NPoints,timev,zv);
  TCanvas* c= new TCanvas(true);
    X->SetMarkerColor(46);
    Y->SetMarkerColor(4);
     Z->SetMarkerColor(8);
    X->SetMarkerStyle(7);
    Y->SetMarkerStyle(7);
    Z->SetMarkerStyle(7);
  mg->Add(X);
  mg->Add(Y);
  mg->Add(Z);
  mg->Draw("AP");

}
