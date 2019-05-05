#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TTree.h"
#include "TBranch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "DataFormats/Math/interface/deltaR.h"
#include "MuonHLTNtuples/Analyzers/src/MuonTree.h"
#include "TLorentzVector.h"


double pt_bins[17]  = { 5, 7, 9, 12, 16,  20 ,  24 ,  27 ,   30,   35,   40,   45,   50,  60, 70 ,  90, 150 };
double dz_bins[11]  = {-15, -8, -6, -4, -2, 0, 2, 4, 6, 8, 15};
double eta_bins[16] = {-2.4, -2.1, -1.6, -1.2, -1.04, -0.9, -0.3, -0.2,  0.2, 0.3, 0.9, 1.04, 1.2, 1.6, 2.1, 2.4};
double iso_bins[12] = { 0  , 0.02, 0.04, 0.06, 0.08,  0.1, 0.12, 0.16, 0.2, 0.3, 0.6, 1   };
double offlineIsoCut = 0.15;

void printProgBar(int);



void L2NSeedingPlots_forAN(TString inputfilename="/eos/uscms/store/user/bmahakud/NTuples_Jan24_2019/Standard/Standard_24Jan.root", std::string effmeasured="IterL3_"){



 
  TFile *inputfile=new TFile(inputfilename,"READ");
 

  TTree *tree = (TTree*) inputfile -> Get("muonNtuples/muonTree"); 
  
  if (!tree) {
    std::cout << " *** tree not found *** " << std::endl;
    return;
  }
    
  MuonEvent* ev      = new MuonEvent(); 
  TBranch*  evBranch = tree->GetBranch("event"); 
  evBranch -> SetAddress(&ev);

  int nentries = tree->GetEntriesFast();

  std::cout << "Number of entries = " << nentries << std::endl;
  TFile *f=new TFile("IterL3_OISeedingETC.root","RECREATE");


  TH1F *hOISeeds=new TH1F("hOISeeds","hOISeeds",20,0,20);
  TH1F *hOIHitSeeds=new TH1F("hOIHitSeeds","hOIHitSeeds",20,0,20);
  TH1F *hOIHitlessSeeds=new TH1F("hOIHitlessSeeds","hOIHitlessSeeds",20,0,20);
  TH2F *hOISeedsVsEta=new TH2F("hOISeedsVsEta","hOISeedsVsEta",15,eta_bins,20,0,20);//,15,eta_bins);
  TH2F *hOIHitSeedsVsEta=new TH2F("hOIHitSeedsVsEta","hOIHitSeedsVsEta",15,eta_bins,20,0,20);
  TH2F *hOIHitlessSeedsVsEta=new TH2F("hOIHitlessSeedsVsEta","hOIHitlessSeedsVsEta",15,eta_bins,20,0,20);


  TH1F *hL2Hits=new TH1F("hL2Hits","hL2Hits",100,0,100);
  TH2F *hL2HitsVsEta=new TH2F("hL2HitsVsEta","hL2HitsVsEta",15,eta_bins,100,0,100);



	
  for (Int_t eventNo=0; eventNo < 30000; eventNo++)     {
    Int_t IgetEvent   = tree   -> GetEvent(eventNo);
    printProgBar((int)(eventNo*100./30000));
   
    unsigned int nL2muons = ev->L2muonsTSG.size();

   // cout<<""<<nL2muons<<endl;

   for(int i=0;i<nL2muons;i++){

  //cout<<"seeds: "<<ev->L2muonsTSG.at(i).NumOISeeds<<endl;
   
   hOISeedsVsEta->Fill(ev->L2muonsTSG.at(i).eta,ev->L2muonsTSG.at(i).NumOISeeds);//,ev->L2muonsTSG.at(i).eta);//,ev->L2muonsTSG.at(i).NumOISeeds);
   hOIHitSeedsVsEta->Fill(ev->L2muonsTSG.at(i).eta,ev->L2muonsTSG.at(i).NumOIHitSeeds);
   hOIHitlessSeedsVsEta->Fill(ev->L2muonsTSG.at(i).eta,ev->L2muonsTSG.at(i).NumOIHitlessSeeds);
   hOISeeds->Fill(ev->L2muonsTSG.at(i).NumOISeeds);
   hOIHitSeeds->Fill(ev->L2muonsTSG.at(i).NumOIHitSeeds);  
   hOIHitlessSeeds->Fill(ev->L2muonsTSG.at(i).NumOIHitlessSeeds);
   hL2Hits->Fill(ev->L2muonsTSG.at(i).L2ValidHits);
   hL2HitsVsEta->Fill(ev->L2muonsTSG.at(i).eta,ev->L2muonsTSG.at(i).L2ValidHits);
 

    }
   
  }

 //hOISeedsVsEta->Write();

f->Write();




 
  }//main code  
 

void printProgBar( int percent ){
  std::string bar;
  for(int i = 0; i < 50; i++){
    if( i < (percent/2)){
      bar.replace(i,1,"=");
    }else if( i == (percent/2)){
      bar.replace(i,1,">");
    }else{
      bar.replace(i,1," ");
    }
  }

  std::cout<< "\r" "[" << bar << "] ";
  std::cout.width( 3 );
  std::cout<< percent << "%     " << std::flush;
}

 
