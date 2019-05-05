#ifndef  MuonTree_h
#define  MuonTree_h

#include "TROOT.h"
#include "TMath.h"
#include <vector>
#include <string>



class GenParticleCand {
public:
  Int_t   pdgId; 
  Int_t   status; 
  Float_t energy; 
  Float_t pt; 
  Float_t eta; 
  Float_t phi; 
  std::vector<Int_t>  pdgMother; 
  std::vector<Int_t>  pdgRealMother; 

  GenParticleCand(){};
  virtual ~GenParticleCand(){};
  
  ClassDef(GenParticleCand,1)
};


//INCLUDED2//
class HltTrackCand {
 public:

  Float_t pt;
  Float_t eta;
  Float_t phi;

  Double_t  chi2;

  Float_t dxy;
  Float_t dz;
  Float_t fracValidTrackhit;

  Int_t validHits;
  Int_t pixelHits;
  Int_t layerHits;
  Int_t pixelLayers;


  HltTrackCand(){};
  virtual ~HltTrackCand(){};

  ClassDef(HltTrackCand,1)
    };


class MuonCand {
public:

  Float_t pt;  
  Float_t eta; 
  Float_t phi; 
  Int_t   charge;    

  Int_t   isGlobal;
  Int_t   isTracker;

  Int_t   isLoose;
  Int_t   isMedium;
  Int_t   isTight;
  std::vector<double> SharedHitFrac;

  Float_t L3pt;
  Float_t L3eta;
  Float_t L3phi;
  Float_t delRmuL3;
  Float_t sharedFrac;
  Float_t sharedFracPixel;
  Float_t sharedFracStrip;

//***************************INCLUDED*********************//
  Double_t  chi2; 
  Double_t innerchi2;

  Float_t validHits;
  Float_t innerpt;
  Float_t innereta;
  Float_t innerphi;
  Float_t innerdxy;
  Float_t innerdz;

  Int_t innervalidHits;

  Float_t dxy;
  Float_t dz;
  Float_t chi2LocalPosition;
  Float_t kickFinder;
  Float_t innerfracValidTrackhit;

  Int_t matchedStations;
  Int_t innerpixelHits;
  Int_t innerlayerHits;
  Int_t innerpixelLayers;
  Int_t isPFMuon;


  //******************************************************//

  Float_t chargedDep_dR03;
  Float_t neutralDep_dR03;
  Float_t photonDep_dR03;
  Float_t puPt_dR03;

  Float_t chargedDep_dR04;
  Float_t neutralDep_dR04;
  Float_t photonDep_dR04;
  Float_t puPt_dR04;

  MuonCand(){};
  virtual ~MuonCand(){};

  ClassDef(MuonCand,1)
};


class HLTMuonCand {
public:

  Float_t pt;           
  Float_t eta;          
  Float_t phi;          
  Float_t dxy;
  Float_t dz;



  Int_t NumOISeeds;
  Int_t NumOIHitlessSeeds;
  Int_t NumOIHitSeeds;
  Int_t L2ValidHits;


  Float_t trkpt;         // pt of the track of the hlt muon [GeV]
  Int_t   charge;         // pt of the track of the hlt muon [GeV]
 
  HLTMuonCand(){};
  virtual ~HLTMuonCand(){};

  ClassDef(HLTMuonCand,1)

};


class L1MuonCand {
public:

  Float_t pt;           
  Float_t eta;          
  Float_t phi;          
  Int_t   charge;      
  Int_t   quality;      
  
  L1MuonCand(){};
  virtual ~L1MuonCand(){};

  ClassDef(L1MuonCand,1)

};



class HLTObjCand {
public:

  std::string filterTag; // name of filter passed by the object
  Float_t pt;            // pt of the object passing the filter [GeV]
  Float_t eta;           // eta of the object passing the filter
  Float_t phi;           // phi of the object passing the filter
  
  HLTObjCand(){};
  virtual ~HLTObjCand(){};

  ClassDef(HLTObjCand,1)

};





class HLTInfo {
public:
  std::vector<std::string>  triggers;  
  std::vector<HLTObjCand>   objects;   
 

  HLTInfo(){};
  virtual ~HLTInfo(){};
  bool match( const std::string & path ) {
	if (  std::find (  triggers.begin(), triggers.end(), path ) != triggers.end() )  return true;
//     if (! iname.compare("HLT_Mu20_v1") == 0) continue;
	return false;
  }

  bool find( const std::string & path ) {
	for ( std::vector<std::string>::const_iterator it = triggers.begin(); it != triggers.end(); ++it ) {
      if ( it-> compare(path) == 0) return true;
//       if ( it->find ( path ) != std::string::npos ) return true;
	}
	return false;
  }

  ClassDef(HLTInfo,1)

};


class MuonEvent {
public:

  Int_t   runNumber;             
  Int_t   luminosityBlockNumber; 
  Int_t   eventNumber;           

  Int_t   nVtx;                    
  Float_t primaryVertex[3];        
  Float_t cov_primaryVertex[3][3]; 

  Float_t trueNI;   

  
  Float_t bxId;
  Float_t instLumi; 

  std::vector <GenParticleCand> genParticles; 
  std::vector <MuonCand>        muons;         
  std::vector <HLTMuonCand>     tkmuons;      
  std::vector <HLTMuonCand>     hltmuons;     
  std::vector <HLTMuonCand>     hltOImuons;
  std::vector <HLTMuonCand>     hltIOmuons;
  std::vector <HLTMuonCand>     L2muons;      
  std::vector <L1MuonCand>      L1muons;      
  std::vector <HLTMuonCand>     L2muonsTSG;


//*******************INCLUDED*******************//
  std::vector <HltTrackCand>    hltTrackOI;
  std::vector <HltTrackCand>    hltTrackIOL1;
  std::vector <HltTrackCand>    hltTrackIOL2;
//**********************************************//



  HLTInfo                       hlt;           
  HLTInfo                       hltTag;            

  MuonEvent(){};
  virtual ~MuonEvent(){};

  ClassDef(MuonEvent,1)
};


#endif

