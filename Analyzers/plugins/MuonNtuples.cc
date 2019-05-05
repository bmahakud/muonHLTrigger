/** \class MuonNtuples
 */
      
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/View.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/L1Trigger/interface/Muon.h"
#include "DataFormats/Luminosity/interface/LumiDetails.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/RecoCandidate/interface/IsoDeposit.h"
#include "DataFormats/RecoCandidate/interface/IsoDepositFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidateFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidateIsolation.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Scalers/interface/LumiScalers.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "HLTrigger/HLTcore/interface/HLTEventAnalyzerAOD.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "RecoMuon/TrackingTools/interface/MuonServiceProxy.h"
#include <map>
#include <string>
#include <iomanip>
#include "TTree.h"
#include "MuonHLTNtuples/Analyzers/src/MuonTree.h"
#include "DataFormats/MuonReco/interface/MuonTrackLinks.h"
#include "DataFormats/TrackerRecHit2D/interface/BaseTrackerRecHit.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit1D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/OmniClusterRef.h"
class MuonServiceProxy;

enum HLTCollectionType { 
  iL2muons=0,
  iL3muons,
  itkmuons,
  iL3OImuons,
  iL3IOmuons,
};


//*********INCLUDED*********// 
enum TrackCollectionType {
  ihltTrackOI=0,
  ihltTrackIOL1,
  ihltTrackIOL2,
};
//**************************//


const double NOMATCH = 999.;
const double NOMATCHITS =  0.;



class MuonNtuples : public edm::EDAnalyzer {

 public:
  MuonNtuples(const edm::ParameterSet& cfg);
  virtual ~MuonNtuples() {};

  virtual void analyze (const edm::Event& event, const edm::EventSetup & eventSetup);
  virtual void beginJob();
  virtual void endJob();
  virtual void beginEvent();
  virtual void beginRun(const edm::Run & run,    const edm::EventSetup & eventSetup);
  virtual void endRun  (const edm::Run & run,    const edm::EventSetup & eventSetup);

//  std::vector<size_t> matchBySharedHits(const reco::MuonCollection& Muons, trigger::TriggerObjectCollection& hltl3muons,const edm::Handle<reco::MuonTrackLinksCollection>& links, const double minSharedFrac=NOMATCHITS) ;

 // float matchedL3hitFrac(const std::vector<reco::Muon>::const_iterator & mu, trigger::TriggerObjectCollection& hltl3muons,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi);

 // float matchedL3hitFrac(const std::vector<reco::Muon>::const_iterator & mu,const edm::Handle<reco::RecoChargedCandidateCollection> & l3cands,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi);

 // float matchedL3hitFracPixel(const std::vector<reco::Muon>::const_iterator & mu,const edm::Handle<reco::RecoChargedCandidateCollection> & l3cands,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi);

 // float matchedL3hitFracStrip(const std::vector<reco::Muon>::const_iterator & mu,const edm::Handle<reco::RecoChargedCandidateCollection> & l3cands,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi);




 // std::vector<size_t> matchBySharedHits(const reco::TrackExtraCollection& Muons, trigger::TriggerObjectCollection& hltl3muons, const edm::Handle<reco::MuonTrackLinksCollection>& links, const double minSharedFrac=NOMATCHITS) ;


 // int sharedHits(const reco::Track& track1, const reco::Track& track2,int &NumMuonHits,int &NumL3Hits) const;
 // int sharedHits(const reco::TrackExtra& track1, const reco::Track& track2) const;

 // float frac_sharedHitsPixel(const reco::Track& track1, const reco::Track& track2) const;
 // float frac_sharedHitsStrip(const reco::Track& track1, const reco::Track& track2) const;



 private:

  void fillHlt(const edm::Handle<edm::TriggerResults> &, 
               const edm::Handle<trigger::TriggerEvent> &,
               const edm::TriggerNames &,
               const edm::Event &,
               bool 
              );
  
  void fillMuons(const edm::Handle<reco::MuonCollection> &,
                  trigger::TriggerObjectCollection & hltl3muons,
                 const edm::Handle<reco::RecoChargedCandidateCollection> & l3cands,
                 const edm::Handle<reco::MuonTrackLinksCollection>& links,
                 const reco::Vertex &, 
                 const edm::Event   & 
		 );
  //*****************************INCLUDED*****************************//
  void fillHltTrack(const edm::Handle<reco::TrackCollection>  &,
		    const edm::Event    &,
                    TrackCollectionType type
		    );
  //******************************************************************//


  void fillHltMuons(const edm::Handle<reco::RecoChargedCandidateCollection> &,
                    const edm::Event   &,
		    HLTCollectionType type
                   );

  void fillL1Muons(const edm::Handle<l1t::MuonBxCollection> &,
                    const edm::Event   &
                   );

  void MonteCarloStudies(const edm::Event&);
  

//   virtual void endEvent();

  edm::InputTag offlinePVTag_;
  edm::EDGetTokenT<reco::VertexCollection> offlinePVToken_;
  edm::InputTag offlineMuonTag_;
  edm::EDGetTokenT<std::vector<reco::Muon>> offlineMuonToken_;
  /// file service
  edm::Service<TFileService> outfile_;

//*****************************INCLUDED*****************************//
  edm::InputTag theTrackOITag_;
  edm::EDGetTokenT<reco::TrackCollection> theTrackOIToken_;
  edm::InputTag theTrackIOL2Tag_;
  edm::EDGetTokenT<reco::TrackCollection> theTrackIOL2Token_;
  edm::InputTag theTrackIOL1Tag_;
  edm::EDGetTokenT<reco::TrackCollection> theTrackIOL1Token_;
//******************************************************************//


  // Trigger process
  edm::InputTag triggerResultTag_;
  edm::EDGetTokenT<edm::TriggerResults>   triggerResultToken_;
  edm::InputTag triggerSummTag_;
  edm::EDGetTokenT<trigger::TriggerEvent> triggerSummToken_;
  edm::InputTag tagTriggerResultTag_;
  edm::EDGetTokenT<edm::TriggerResults>   tagTriggerResultToken_;
  edm::InputTag tagTriggerSummTag_;
  edm::EDGetTokenT<trigger::TriggerEvent> tagTriggerSummToken_;

  // Input tags
  edm::InputTag l3candTag_;
  edm::EDGetTokenT<reco::RecoChargedCandidateCollection> l3candToken_; 
  edm::InputTag l2candTag_;
  edm::EDGetTokenT<reco::RecoChargedCandidateCollection> l2candToken_; 
  edm::InputTag l1candTag_;
  edm::EDGetTokenT<l1t::MuonBxCollection> l1candToken_; 
  edm::InputTag tkMucandTag_;
  edm::EDGetTokenT<reco::RecoChargedCandidateCollection> tkMucandToken_; 
  edm::InputTag l3OIcandTag_;
  edm::EDGetTokenT<reco::RecoChargedCandidateCollection> l3OIcandToken_; 
  edm::InputTag l3IOcandTag_;
  edm::EDGetTokenT<reco::RecoChargedCandidateCollection> l3IOcandToken_; 

  edm::EDGetTokenT<reco::MuonTrackLinksCollection>  theLinksToken_;
  edm::EDGetTokenT<reco::TrackExtraCollection>  theMuonsWithHitsToken_;
 


  //trigger process
  std::string triggerProcess_;
  std::string triggerName_;
  std::string l1filterLabel_;
  std::string l2filterLabel_;
  std::string l3filterLabel_;



  edm::InputTag lumiScalerTag_;
  edm::EDGetTokenT<LumiScalersCollection> lumiScalerToken_;

  edm::InputTag puTag_;
  edm::EDGetTokenT<std::vector< PileupSummaryInfo>> puToken_;

  edm::InputTag genTag_;
  edm::EDGetTokenT<reco::GenParticleCollection> genToken_;

  edm::InputTag NumOISeedTag_;
  edm::EDGetTokenT<std::vector<int>>  NumOISeedToken_;

  edm::InputTag NumOIHitlessSeedTag_;
  edm::EDGetTokenT<std::vector<int>>  NumOIHitlessSeedToken_;

  edm::InputTag NumOIHitSeedTag_;
  edm::EDGetTokenT<std::vector<int>>  NumOIHitSeedToken_;

  edm::InputTag L2ptTag_;
  edm::EDGetTokenT<std::vector<double>>  L2ptToken_;

  edm::InputTag L2etaTag_;
  edm::EDGetTokenT<std::vector<double>>  L2etaToken_;

  edm::InputTag L2phiTag_;
  edm::EDGetTokenT<std::vector<double>>  L2phiToken_;


  edm::InputTag L2validHitTag_;
  edm::EDGetTokenT<std::vector<int>> L2validHitToken_;



  bool doOffline_;

  MuonEvent event_;
  std::map<std::string,TTree*> tree_;
  
  unsigned int nGoodVtx; 
  MuonServiceProxy *theService;

};

/// default constructor
MuonNtuples::MuonNtuples(const edm::ParameterSet& cfg): 
  offlinePVTag_           (cfg.getParameter<edm::InputTag>("offlineVtx")), 
    offlinePVToken_         (consumes<reco::VertexCollection>(offlinePVTag_)), 
  offlineMuonTag_         (cfg.getParameter<edm::InputTag>("offlineMuons")), 
    offlineMuonToken_       (consumes<std::vector<reco::Muon>>(offlineMuonTag_)), 

//********************************************INCLUDED********************************************//
  theTrackOITag_          (cfg.getUntrackedParameter<edm::InputTag>("theTrackOI")),
    theTrackOIToken_        (consumes<reco::TrackCollection>(theTrackOITag_)),
  theTrackIOL2Tag_          (cfg.getUntrackedParameter<edm::InputTag>("theTrackIOL2")),
    theTrackIOL2Token_        (consumes<reco::TrackCollection>(theTrackIOL2Tag_)),
  theTrackIOL1Tag_          (cfg.getUntrackedParameter<edm::InputTag>("theTrackIOL1")),
    theTrackIOL1Token_        (consumes<reco::TrackCollection>(theTrackIOL1Tag_)),
//************************************************************************************************//


  triggerResultTag_       (cfg.getUntrackedParameter<edm::InputTag>("triggerResult")), 
    triggerResultToken_     (consumes<edm::TriggerResults>(triggerResultTag_)),
  triggerSummTag_         (cfg.getUntrackedParameter<edm::InputTag>("triggerSummary")), 
    triggerSummToken_       (consumes<trigger::TriggerEvent>(triggerSummTag_)),
   //l3filterLabel_          (cfg.getParameter<std::string>("l3filterLabel")),

  tagTriggerResultTag_    (cfg.getUntrackedParameter<edm::InputTag>("tagTriggerResult")), 
    tagTriggerResultToken_  (consumes<edm::TriggerResults>(tagTriggerResultTag_)),
  tagTriggerSummTag_      (cfg.getUntrackedParameter<edm::InputTag>("tagTriggerSummary")), 
    tagTriggerSummToken_    (consumes<trigger::TriggerEvent>(tagTriggerSummTag_)),
  // triggerProcess_         (cfg.getParameter<std::string>("triggerProcess")),

  l3candTag_              (cfg.getUntrackedParameter<edm::InputTag>("L3Candidates")),
    l3candToken_            (consumes<reco::RecoChargedCandidateCollection>(l3candTag_)),
  l2candTag_              (cfg.getUntrackedParameter<edm::InputTag>("L2Candidates")),
    l2candToken_            (consumes<reco::RecoChargedCandidateCollection>(l2candTag_)),
  l1candTag_              (cfg.getUntrackedParameter<edm::InputTag>("L1Candidates")),
    l1candToken_            (consumes<l1t::MuonBxCollection>(l1candTag_)),
  tkMucandTag_            (cfg.getUntrackedParameter<edm::InputTag>("TkMuCandidates")),
    tkMucandToken_          (consumes<reco::RecoChargedCandidateCollection>(tkMucandTag_)),
  l3OIcandTag_            (cfg.getUntrackedParameter<edm::InputTag>("L3OIMuCandidates")),
    l3OIcandToken_          (consumes<reco::RecoChargedCandidateCollection>(l3OIcandTag_)),
  l3IOcandTag_          (cfg.getUntrackedParameter<edm::InputTag>("L3IOMuCandidates")),
    l3IOcandToken_        (consumes<reco::RecoChargedCandidateCollection>(l3IOcandTag_)),

  theLinksToken_          (consumes<reco::MuonTrackLinksCollection>(cfg.getUntrackedParameter<edm::InputTag>("MuonLinksTag"))),
  theMuonsWithHitsToken_  (consumes<reco::TrackExtraCollection>(edm::InputTag("globalMuons"))),


  lumiScalerTag_          (cfg.getUntrackedParameter<edm::InputTag>("lumiScalerTag")),
    lumiScalerToken_        (consumes<LumiScalersCollection>(lumiScalerTag_)), 
  puTag_                  (cfg.getUntrackedParameter<edm::InputTag>("puInfoTag")),
    puToken_                (consumes<std::vector< PileupSummaryInfo>>(puTag_)), 

  genTag_                 (cfg.getUntrackedParameter<edm::InputTag>("genParticlesTag")),
    genToken_               (consumes<reco::GenParticleCollection>(genTag_)), 

  doOffline_                 (cfg.getUntrackedParameter<bool>("doOffline"))
{

  theService = new MuonServiceProxy(cfg.getParameter<edm::ParameterSet>("ServiceParameters"));
  //usesResource("TFileService");

  NumOISeedTag_ = cfg.getParameter<edm::InputTag >("NumOISeeds");
  NumOISeedToken_= consumes<std::vector<int>>(NumOISeedTag_);

  NumOIHitlessSeedTag_ = cfg.getParameter<edm::InputTag >("NumOIHitlessSeeds");
  NumOIHitlessSeedToken_= consumes<std::vector<int>>(NumOIHitlessSeedTag_);

  NumOIHitSeedTag_ = cfg.getParameter<edm::InputTag >("NumOIHitSeeds");
  NumOIHitSeedToken_= consumes<std::vector<int>>(NumOIHitSeedTag_);


  L2ptTag_ = cfg.getParameter<edm::InputTag >("L2pt");
  L2ptToken_= consumes<std::vector<double>>(L2ptTag_);

  L2etaTag_ = cfg.getParameter<edm::InputTag >("L2eta");
  L2etaToken_= consumes<std::vector<double>>(L2etaTag_);


  L2phiTag_ = cfg.getParameter<edm::InputTag >("L2phi");
  L2phiToken_= consumes<std::vector<double>>(L2phiTag_);

  L2validHitTag_ = cfg.getParameter<edm::InputTag >("L2ValidHits");
  L2validHitToken_ = consumes<std::vector<int>>(L2validHitTag_);


}

void MuonNtuples::beginJob() {

  TH1::SetDefaultSumw2() ;
  tree_["muonTree"] = outfile_-> make<TTree>("muonTree","muonTree");
  tree_["muonTree"] -> Branch("event" ,&event_, 64000,2);

}    

void MuonNtuples::endJob() {}

void MuonNtuples::beginRun(const edm::Run & run, const edm::EventSetup & eventSetup) {}

void MuonNtuples::endRun  (const edm::Run & run, const edm::EventSetup & eventSetup) {}
 
void MuonNtuples::analyze (const edm::Event &event, const edm::EventSetup &eventSetup) {

  theService->update(eventSetup);


  beginEvent();

  // Fill general info
  event_.runNumber             = event.id().run();
  event_.luminosityBlockNumber = event.id().luminosityBlock();
  event_.eventNumber           = event.id().event();

   edm::Handle<std::vector<int>> NumOISeed_;
   event.getByToken(NumOISeedToken_,NumOISeed_);

   edm::Handle<std::vector<int>> NumOIHitlessSeed_;
   event.getByToken(NumOIHitlessSeedToken_,NumOIHitlessSeed_);

   edm::Handle<std::vector<int>> NumOIHitSeed_;
   event.getByToken(NumOIHitSeedToken_,NumOIHitSeed_);


   edm::Handle<std::vector<double>> L2pt_;
   event.getByToken(L2ptToken_,L2pt_);

   edm::Handle<std::vector<double>> L2eta_;
   event.getByToken(L2etaToken_,L2eta_);

   edm::Handle<std::vector<double>> L2phi_;
   event.getByToken(L2phiToken_,L2phi_);

   edm::Handle<std::vector<int>> NumL2ValidHits_;
   event.getByToken(L2validHitToken_,NumL2ValidHits_);

   if(L2pt_.isValid()){

   for(unsigned int im=0;im<L2pt_->size();im++){
    HLTMuonCand L2muonTSG;
     L2muonTSG.pt=L2pt_->at(im);
     L2muonTSG.eta=L2eta_->at(im);
     L2muonTSG.phi=L2phi_->at(im);
     L2muonTSG.L2ValidHits=NumL2ValidHits_->at(im);
     L2muonTSG.NumOISeeds=NumOISeed_->at(im);
     L2muonTSG.NumOIHitlessSeeds=NumOIHitlessSeed_->at(im);
     L2muonTSG.NumOIHitSeeds=NumOIHitSeed_->at(im);

    event_.L2muonsTSG.push_back(L2muonTSG);
    }
   }


  // Fill vertex info
  //if (doOffline_){
    edm::Handle<reco::VertexCollection> vertices; 
    event.getByToken(offlinePVToken_, vertices);
    for(reco::VertexCollection::const_iterator it = vertices->begin(); it != vertices->end(); ++it) {
      if( !it->isValid())  continue;
      nGoodVtx++;
    }
    event_.nVtx = nGoodVtx;
    const reco::Vertex           & pv      = vertices->at(0);

  // Handle the offline muon collection and fill offline muons
    edm::Handle<std::vector<reco::Muon> > muons;
    event.getByToken(offlineMuonToken_, muons);
    //fillMuons(muons, pv, event);

    // Fill bx and inst lumi info
    if (event.isRealData()) {
      event_.bxId  = event.bunchCrossing();

      if (lumiScalerTag_.label() != "none")
      {
        edm::Handle<LumiScalersCollection> lumiScaler;
        event.getByToken(lumiScalerToken_, lumiScaler);

        if (lumiScaler->begin() != lumiScaler->end())
          event_.instLumi = lumiScaler->begin()->instantLumi();
      } 
    }
 // }


  // Fill PU info
  if (!event.isRealData()) {
    edm::Handle<std::vector< PileupSummaryInfo > > puInfo;
    if ( event.getByToken(puToken_,puInfo)){
      std::vector<PileupSummaryInfo>::const_iterator PVI;
      for(PVI = puInfo->begin(); PVI != puInfo->end(); ++PVI) 
      {
        if(PVI->getBunchCrossing()==0){
          event_.trueNI   = PVI->getTrueNumInteractions();
          continue;
        }
      }
    } 
    else  
      edm::LogError("") << "PU collection not found !!!";
  }

  
  // Fill MC GEN info
  if (!event.isRealData()) 
    MonteCarloStudies(event);


  //Track Outside-In
  edm::Handle<reco::TrackCollection> trackOI;
  event.getByToken(theTrackOIToken_, trackOI);
  
  if (event.getByToken(theTrackOIToken_, trackOI))
    fillHltTrack(trackOI, event, TrackCollectionType::ihltTrackOI);
  
  //Track Inside Out from L2
  edm::Handle<reco::TrackCollection> trackIOL2;
  if (event.getByToken(theTrackIOL2Token_, trackIOL2))
    fillHltTrack(trackIOL2, event, TrackCollectionType::ihltTrackIOL2);
  
  //Track Outside In from L1
  edm::Handle<reco::TrackCollection> trackIOL1;
  if (event.getByToken(theTrackIOL1Token_, trackIOL1))
    fillHltTrack(trackIOL1, event, TrackCollectionType::ihltTrackIOL1);
  
  
  // Fill trigger information for probe muon
  edm::Handle<edm::TriggerResults>   triggerResults;
  edm::Handle<trigger::TriggerEvent> triggerEvent;

  //if(triggerResults.isValid())std::cout<<"Trigger resultsValid"<<std::endl;
 // if(triggerEvent.isValid())std::cout<<"Trigger Event Valid"<<std::endl;
  //std::cout<<"triggerResultToken_: "<<triggerResultToken_<<std::endl;


  if (event.getByToken(triggerResultToken_, triggerResults) &&
      event.getByToken(triggerSummToken_  , triggerEvent)) {
      
    edm::TriggerNames triggerNames_ = event.triggerNames(*triggerResults);
    fillHlt(triggerResults, triggerEvent, triggerNames_, event, false);
  }
  else 
    edm::LogError("") << "Trigger collection for probe muon not found !!!";

  // Fill trigger information for tag muon
  edm::Handle<edm::TriggerResults>   tagTriggerResults;
  edm::Handle<trigger::TriggerEvent> tagTriggerEvent;
      
  if (event.getByToken(tagTriggerResultToken_, tagTriggerResults) &&
      event.getByToken(tagTriggerSummToken_  , tagTriggerEvent)) {
      
    edm::TriggerNames tagTriggerNames_ = event.triggerNames(*tagTriggerResults);
    fillHlt(tagTriggerResults, tagTriggerEvent, tagTriggerNames_, event, true);
  }
  else 
    edm::LogError("") << "Trigger collection for tag muon not found !!!";

 // Handle the online muon collection and fill online muons //the hltmuons branch
  edm::Handle<reco::RecoChargedCandidateCollection> l3cands;
  if (event.getByToken(l3candToken_, l3cands))
    fillHltMuons(l3cands, event, HLTCollectionType::iL3muons);



  // Handle the online muon collection and fill L2 muons //the l2muosn branch
  edm::Handle<reco::RecoChargedCandidateCollection> l2cands;
  if (event.getByToken(l2candToken_, l2cands))
    fillHltMuons(l2cands, event, HLTCollectionType::iL2muons);
//  else
//    edm::LogWarning("") << "Online L2 muon collection not found !!!";

  // Handle the online muon collection and fill L1 muons
  edm::Handle<l1t::MuonBxCollection> l1cands;
  if (event.getByToken(l1candToken_, l1cands))
    fillL1Muons(l1cands, event);
//  else
//    edm::LogWarning("") << "Online L1 muon collection not found !!!";
  
  // Handle the 2nd online muon collection and fill online muons
  edm::Handle<reco::RecoChargedCandidateCollection> tkMucands;
  if (event.getByToken(tkMucandToken_, tkMucands))
    fillHltMuons(tkMucands, event, HLTCollectionType::itkmuons);
//  else
//    edm::LogWarning("") << "Online tracker muon collection not found !!!";
//

  // Handle the online muon collection and fill online muons //the hltmuons branch
  edm::Handle<reco::RecoChargedCandidateCollection> l3OIcands;
  if (event.getByToken(l3OIcandToken_, l3OIcands))
    fillHltMuons(l3OIcands, event, HLTCollectionType::iL3OImuons);

   //if (l3OIcands.isValid())std::cout<<"OI cand size: "<<l3OIcands->size()<<std::endl;
//  else
//    edm::LogWarning("") << "Online OI muon collection not found !!!"; 

  edm::Handle<reco::RecoChargedCandidateCollection> l3IOcands;
  if (event.getByToken(l3IOcandToken_, l3IOcands))
    fillHltMuons(l3IOcands, event, HLTCollectionType::iL3IOmuons);
//  else
//    edm::LogWarning("") << "Online IO muon collection not found !!!"; 

  edm::Handle<reco::MuonTrackLinksCollection> links;
  event.getByToken(theLinksToken_, links);

  edm::Handle<reco::TrackExtraCollection> trackMuons;
  event.getByToken(theMuonsWithHitsToken_, trackMuons);

  edm::Handle<trigger::TriggerEvent> triggerSummary;
  event.getByToken(triggerSummToken_, triggerSummary);


  edm::Handle<reco::MuonCollection> MuonCol;
  event.getByToken(offlineMuonToken_, MuonCol);  



  reco::MuonCollection Muons;
  for(auto const& mu : *MuonCol) Muons.push_back(mu);

  reco::TrackExtraCollection trackerMuons;
  for(auto const& tkmu : *trackMuons) trackerMuons.push_back(tkmu);

  size_t L3MuonFilterIndex = (*triggerSummary).filterIndex(edm::InputTag("Mu","","TEST"));//(edm::InputTag( "hltL3fL1sMu22Or25L1f0L2f10QL3Filtered27Q","","TEST"));
  
  trigger::TriggerObjectCollection L3MuonTrigObjects;
  trigger::TriggerObjectCollection allTriggerObjects = triggerSummary->getObjects();


     if(L3MuonFilterIndex < (*triggerSummary).sizeFilters()) { //check if the trigger object is present
    const trigger::Keys &keysMuons = (*triggerSummary).filterKeys(L3MuonFilterIndex);
    for(size_t j = 0; j < keysMuons.size(); j++) {
      trigger::TriggerObject foundObject = (allTriggerObjects)[keysMuons[j]];
      L3MuonTrigObjects.push_back(foundObject);
    }
  }



  try{
     //std::cout<<"total muons in the event: "<<muons->size()<<std::endl;
     fillMuons(muons,L3MuonTrigObjects,l3cands,links, pv, event);
     }
   catch(...){}




  // endEvent();
  tree_["muonTree"] -> Fill();
}



//------------------------------------------------------------------------
void MuonNtuples::MonteCarloStudies(const edm::Event& event)
{
  edm::Handle<reco::GenParticleCollection> genParticles;
  event.getByToken(genToken_, genParticles);
  int muId  =    13;

  for ( size_t i=0; i< genParticles->size(); ++i) 
  { 
    const reco::GenParticle &p = (*genParticles)[i];
    // only save muons
    if(fabs(p.pdgId()) != muId )     continue; 
      
    GenParticleCand theGen;
    theGen.pdgId  = p.pdgId();
    theGen.pt     = p.pt() ;
    theGen.eta    = p.eta();
    theGen.phi    = p.phi();
    theGen.energy = p.energy();
    theGen.status = p.status();
    
    unsigned int n_moms = p.numberOfMothers();
    if (n_moms == 0 ){
      theGen.pdgMother.push_back(0);
      theGen.pdgRealMother.push_back(0);
    }
    else {
      for (unsigned int im=0; im < n_moms; ++im){
        theGen.pdgMother.push_back(p.motherRef(im)->pdgId());
        // if coming from a muon, go back one step ** to be improved **
        if(n_moms == 1 && fabs(p.motherRef(0)->pdgId()) == muId){
          for (unsigned int igm = 0; igm < p.motherRef(0)->numberOfMothers(); igm++){
            theGen.pdgRealMother.push_back(p.motherRef(0)->motherRef(igm)->pdgId());
          }
        }
        else
          theGen.pdgRealMother.push_back(0);
      }
    }

    event_.genParticles.push_back(theGen);

  }  // end for genParticles
}



// --------------------------------------------------------------------
void MuonNtuples::fillHlt(const edm::Handle<edm::TriggerResults>   & triggerResults, 
                          const edm::Handle<trigger::TriggerEvent> & triggerEvent  ,
                          const edm::TriggerNames                  & triggerNames  ,
                          const edm::Event                         & event         ,
                          bool                                       isTag         )
{    
   
  for (unsigned int itrig=0; itrig < triggerNames.size(); ++itrig) 
  {
    LogDebug ("triggers") << triggerNames.triggerName(itrig) ;
    if (triggerResults->accept(itrig)) 
    {
      std::string pathName = triggerNames.triggerName(itrig);
      
//      if ( pathName.find ("HLT_IsoMu"  ) !=std::string::npos ||
//           pathName.find ("HLT_Mu"     ) !=std::string::npos ||
//           pathName.find ("HLT_Mu5"    ) !=std::string::npos ||
//           pathName.find ("HLT_TkMu5"  ) !=std::string::npos ||
//           pathName.find ("HLT_IsoTkMu") !=std::string::npos ||
//           pathName.find ("HLT_Mu17"   ) !=std::string::npos ||
//           pathName.find ("HLT_Mu8_T"  ) !=std::string::npos 
//      ){
      if (isTag) event_.hltTag.triggers.push_back(pathName);
      else       event_.hlt   .triggers.push_back(pathName);
//      }
    }
  }
     
     
  const trigger::size_type nFilters(triggerEvent->sizeFilters());
  for (trigger::size_type iFilter=0; iFilter!=nFilters; ++iFilter) 
  {
    std::string filterTag = triggerEvent->filterTag(iFilter).encode();

    if ( ( filterTag.find ("Mu"     ) !=std::string::npos)
	 && 
	 filterTag.find ("Tau"       ) ==std::string::npos   &&
	 filterTag.find ("EG"        ) ==std::string::npos   &&
	 filterTag.find ("MultiFit"  ) ==std::string::npos  
	 )   
    {
      trigger::Keys objectKeys = triggerEvent->filterKeys(iFilter);
      const trigger::TriggerObjectCollection& triggerObjects(triggerEvent->getObjects());


      
      for (trigger::size_type iKey=0; iKey<objectKeys.size(); ++iKey) 
      {  
        trigger::size_type objKey = objectKeys.at(iKey);
        const trigger::TriggerObject& triggerObj(triggerObjects[objKey]);
        
        HLTObjCand hltObj;
        
        hltObj.filterTag = filterTag;
  
        hltObj.pt  = triggerObj.pt();
        hltObj.eta = triggerObj.eta();
        hltObj.phi = triggerObj.phi();
        
        if (isTag)       event_.hltTag.objects.push_back(hltObj);
        else             event_.hlt   .objects.push_back(hltObj);
      }  
    }       
  }
}


// ---------------------------------------------------------------------
//**********************************************INCLUDED*********************************************//
//Incluir hltTrack copiar collection dentro de muons en innertrack

void MuonNtuples::fillHltTrack(const edm::Handle<reco::TrackCollection>  & trackm ,
			       const edm::Event                          & tevent ,
			       TrackCollectionType type)
{
  int t_mu=0;
  for(reco::TrackCollection::const_iterator t=trackm->begin(); t!=trackm->end(); t++){

    t_mu++;
    HltTrackCand MuTrack;

    MuTrack.pt   = t -> pt() ;
    MuTrack.eta  = t -> eta();
    MuTrack.phi  = t -> phi();

    MuTrack.chi2           = t  ->  normalizedChi2();
    MuTrack.dxy            = t  ->  dxy();
    MuTrack.dz             = t  ->  dz() ;
    MuTrack.pixelHits      = t  ->  hitPattern().numberOfValidPixelHits();
    MuTrack.validHits      = t  ->  numberOfValidHits();

    MuTrack.layerHits         = t -> hitPattern().trackerLayersWithMeasurement(); 
    MuTrack.pixelLayers       = t -> hitPattern().pixelLayersWithMeasurement(); 
    MuTrack.fracValidTrackhit = t -> validFraction();  
  
    if (type == TrackCollectionType::ihltTrackOI)   {event_.hltTrackOI.push_back(MuTrack)  ;  continue; }
    if (type == TrackCollectionType::ihltTrackIOL1) {event_.hltTrackIOL1.push_back(MuTrack);  continue; }
    if (type == TrackCollectionType::ihltTrackIOL2) {event_.hltTrackIOL2.push_back(MuTrack);  continue; }

  }
}
//****************************************************************************************************//

// ---------------------------------------------------------------------
void MuonNtuples::fillMuons(const edm::Handle<reco::MuonCollection>       & muons ,
                            trigger::TriggerObjectCollection & hltl3muons,
                            const edm::Handle<reco::RecoChargedCandidateCollection> & l3cands,
                            const edm::Handle<reco::MuonTrackLinksCollection>& links,
                            const reco::Vertex                            & pv    ,
                            const edm::Event                              & event )
{


  


  int n_mu = 0;
  for(std::vector<reco::Muon>::const_iterator mu1=muons->begin(); mu1!=muons->end(); ++mu1) 
  { 

    n_mu++;
    MuonCand theMu;

    theMu.pt      = mu1 -> pt();
    theMu.eta     = mu1 -> eta();
    theMu.phi     = mu1 -> phi();
    theMu.charge  = mu1 -> charge();

    mu1 -> isGlobalMuon  () ? theMu.isGlobal  = 1 : theMu.isGlobal   = 0;
    mu1 -> isTrackerMuon () ? theMu.isTracker = 1 : theMu.isTracker  = 0;
    mu1 -> isPFMuon()       ? theMu.isPFMuon  = 1 : theMu.isPFMuon   = 0;

    muon::isTightMuon ( (*mu1), pv ) ? theMu.isTight  = 1 : theMu.isTight  = 0;
    muon::isLooseMuon ( (*mu1)     ) ? theMu.isLoose  = 1 : theMu.isLoose  = 0;
    muon::isMediumMuon( (*mu1)     ) ? theMu.isMedium = 1 : theMu.isMedium = 0;

 

    //New variables in the Ntuple 

    if (mu1 -> globalTrack().isNonnull()){
      theMu.chi2 = mu1 -> globalTrack() -> normalizedChi2(); //normalized global-track chi2
      theMu.validHits      = mu1 -> globalTrack() -> hitPattern().numberOfValidHits(); //number of muon-chamber  hit included in the global muon track
    } 


    if (mu1 -> innerTrack().isNonnull()){
      theMu.innerpt           = mu1 -> innerTrack() -> pt();
      theMu.innereta          = mu1 -> innerTrack() -> eta();
      theMu.innerphi          = mu1 -> innerTrack() -> phi();
      theMu.innervalidHits    = mu1 -> innerTrack() -> numberOfValidHits();
      theMu.innerchi2         = mu1 -> innerTrack() -> normalizedChi2();
      theMu.innerdxy          = mu1 -> innerTrack() -> dxy();
      theMu.innerdz           = mu1 -> innerTrack() -> dz();
      theMu.innerpixelHits    = mu1 -> innerTrack() -> hitPattern().numberOfValidPixelHits()      ; //number of pixel hits
      theMu.innerlayerHits    = mu1 -> innerTrack() -> hitPattern().trackerLayersWithMeasurement(); //hits per layer
      theMu.innerpixelLayers  = mu1 -> innerTrack() -> hitPattern().pixelLayersWithMeasurement()  ; //number of pixel layers
      theMu.innerfracValidTrackhit = mu1 -> innerTrack() -> validFraction();  //fraction of valid tracker hits 
    }

    theMu.dxy               = mu1 -> muonBestTrack() -> dxy();//transverse distance of the tracker track wrt primary vertex
    theMu.dz                = mu1 -> muonBestTrack() -> dz() ; //longitudinal distance of the tracker track wrt primary vertex
    theMu.chi2LocalPosition = mu1 -> combinedQuality().chi2LocalPosition; //tracker standalone position match
    theMu.kickFinder        = mu1 -> combinedQuality().trkKink; //kick finder
    theMu.matchedStations   = mu1 -> numberOfMatchedStations(); //number of muons stations with segment


    theMu.chargedDep_dR03 = mu1->pfIsolationR03().sumChargedHadronPt ;
    theMu.neutralDep_dR03 = mu1->pfIsolationR03().sumNeutralHadronEt ;
    theMu.photonDep_dR03  = mu1->pfIsolationR03().sumPhotonEt        ;
    theMu.puPt_dR03       = mu1->pfIsolationR03().sumPUPt            ;
    theMu.chargedDep_dR04 = mu1->pfIsolationR04().sumChargedHadronPt ;
    theMu.neutralDep_dR04 = mu1->pfIsolationR04().sumNeutralHadronEt ;
    theMu.photonDep_dR04  = mu1->pfIsolationR04().sumPhotonEt        ;
    theMu.puPt_dR04       = mu1->pfIsolationR04().sumPUPt            ;

    //float offlineiso04 = theMu.chargedDep_dR04 + std::max(0., theMu.photonDep_dR04 + theMu.neutralDep_dR04 - 0.5*theMu.puPt_dR04);
    //float Relofflineiso04       = float(offlineiso04) / float(theMu.pt);
    //if(theMu.isTight !=1 || Relofflineiso04 >0.15)continue;

    //std::cout<<"For offline muon with pt, eta, phi: "<<mu1 -> pt()<<", "<<mu1 -> eta()<<", "<<mu1 -> phi()<<std::endl; 




    float L3pt=-1.0;
    float L3eta=-1.0;
    float L3phi=-1.0;
    float delRmuL3=-1.0;
    float sharedFrac=-1.0;
    float sharedFracPixel=-1.0;
    float sharedFracStrip=-1.0;
   
    theMu.sharedFrac=0.5;//matchedL3hitFrac(mu1,l3cands,links,L3pt,L3eta,L3phi);
    theMu.L3pt=L3pt;
    theMu.L3eta=L3eta;
    theMu.L3phi=L3phi;
    float deta = mu1 -> eta() - L3eta;
    float dphi = std::abs(mu1 -> phi()-L3phi); if (dphi>3.14) dphi-=(2*3.14); 
    float DeltaRv=sqrt((deta*deta)+(dphi*dphi));
    delRmuL3=DeltaRv;
    theMu.delRmuL3=delRmuL3;

    float dummypt=0.;
    float dummyeta=0.;
    float dummyphi=0.;  

 
    theMu.sharedFracPixel=0.5;//matchedL3hitFracPixel(mu1,l3cands,links,dummypt,dummyeta,dummyphi);
    theMu.sharedFracStrip=0.5;//matchedL3hitFracStrip(mu1,l3cands,links,dummypt,dummyeta,dummyphi);
  





    event_.muons.push_back(theMu);
  }
}



// ---------------------------------------------------------------------
void MuonNtuples::fillHltMuons(const edm::Handle<reco::RecoChargedCandidateCollection> & l3cands , //candidates to HLT 
                               const edm::Event                                        & event   , 
			       HLTCollectionType type
                               )
{

  for( unsigned int il3 = 0; il3 < l3cands->size(); ++il3) {

    HLTMuonCand theL3Mu;

    reco::RecoChargedCandidateRef candref(l3cands, il3);
    theL3Mu.pt      = candref -> pt();
    theL3Mu.eta     = candref -> eta();
    theL3Mu.phi     = candref -> phi();
    theL3Mu.charge  = candref -> charge();


    reco::TrackRef trkmu = candref->track();
    theL3Mu.trkpt   = trkmu -> pt();
    if (type == HLTCollectionType::iL3muons)     { event_.hltmuons   .push_back(theL3Mu);  continue; }
    if (type == HLTCollectionType::iL3OImuons)   { event_.hltOImuons .push_back(theL3Mu);  continue; }
    if (type == HLTCollectionType::iL3IOmuons)   { event_.hltIOmuons .push_back(theL3Mu);  continue; }
    if (type == HLTCollectionType::itkmuons)     { event_.tkmuons    .push_back(theL3Mu);  continue; }
    if (type == HLTCollectionType::iL2muons)     { event_.L2muons    .push_back(theL3Mu);  continue; }
  }
}



// ---------------------------------------------------------------------
void MuonNtuples::fillL1Muons(const edm::Handle<l1t::MuonBxCollection> & l1cands ,
                              const edm::Event                         & event    
                              )
{

  for (int ibx = l1cands->getFirstBX(); ibx <= l1cands->getLastBX(); ++ibx) {
    if (ibx != 0) continue;
    for (auto it = l1cands->begin(ibx); it != l1cands->end(ibx); it++){

      l1t::MuonRef muon(l1cands, distance(l1cands->begin(l1cands->getFirstBX()),it) );

      L1MuonCand theL1Mu;

      theL1Mu.pt       = muon -> pt();
      theL1Mu.eta      = muon -> eta();
      theL1Mu.phi      = muon -> phi();
      theL1Mu.charge   = muon -> charge();
      theL1Mu.quality  = muon -> hwQual();

      event_.L1muons.push_back(theL1Mu);
    }
  }
}




//---------------------------------------------
void MuonNtuples::beginEvent()
{

  event_.hlt.triggers.clear();
  event_.hlt.objects.clear();


  event_.hltTag.triggers.clear();
  event_.hltTag.objects.clear();


  event_.genParticles.clear();

//*******************INCLUDED*******************//
  event_.hltTrackOI.clear();
  event_.hltTrackIOL1.clear();
  event_.hltTrackIOL2.clear();
//**********************************************//
  event_.muons.clear();
  event_.hltmuons.clear();
  event_.L2muons.clear();
  event_.L2muonsTSG.clear();
  event_.L1muons.clear();
  event_.tkmuons.clear();
  event_.hltOImuons.clear();
  event_.hltIOmuons.clear();

  for (unsigned int ix=0; ix<3; ++ix) {
    event_.primaryVertex[ix] = 0.;
    for (unsigned int iy=0; iy<3; ++iy) {
      event_.cov_primaryVertex[ix][iy] = 0.;
    }
  }
  event_.nVtx       = -1;
  event_.trueNI     = -1;
 
  event_.bxId       = -1;
  event_.instLumi   = -1;
  
  nGoodVtx = 0; 
}


/*
vector<size_t> MuonNtuples::matchBySharedHits(const reco::MuonCollection& muons,
                                                  trigger::TriggerObjectCollection& hltl3muons,
                                                  const edm::Handle<reco::MuonTrackLinksCollection>& links, const double minSharedFrac)
{


  const size_t n1 = muons.size();
  const size_t n2 = hltl3muons.size();

  vector<size_t> result(n1, -1);
  vector<vector<double> > SharedHitMatrix;//(n1, vector<double>(n2, NOMATCHITS));

  for (size_t i = 0; i < n1; i++) {
    const reco::Muon  recoMu = muons[i];
    reco::TrackRef mutk = recoMu.innerTrack();

  //   std::cout<<"##########Muon number: "<<i<<"...............................................>>>"<<std::endl;
    //    cout<<"##########Muon pt, eta, phi: "<<recoMu.pt()<<", "<<recoMu.eta()<<",  "<<recoMu.phi()<<endl;
      //  cout<<"##########Total valid hits:  "<<recoMu.innerTrack()->numberOfValidHits()<<endl;
        //cout<<"##########Total rechits:   "<<*mutk.recHitsSize()<<endl;
    for (size_t j = 0; j < n2; j++) {
      trigger::TriggerObject & l3mu = hltl3muons[j];
      //cout<<"     L3 muon number:    "<<j<<": ( pt, eta, phi)"<<l3mu.pt()<<", "<<l3mu.eta()<<", "<<l3mu.phi()<<endl;
      //cout<<"     Num. links: "<<links->size()<<endl;
      for(unsigned int l(0); l <links->size(); ++l){
     // cout<<"        Link num: "<<l<<endl;
        const reco::MuonTrackLinks* link = &links->at(l);
        const reco::Track& globalTrack = *link->globalTrack();
        float dR2 = deltaR2(l3mu.eta(),l3mu.phi(),globalTrack.eta(),globalTrack.phi());
        float dPt = std::abs(l3mu.pt() - globalTrack.pt())/l3mu.pt();

         if (dR2 < 0.01 and dPt < 0.2) {
           reco::TrackRef tk = link->trackerTrack();
           int numHitsShared=sharedHits(*mutk, *tk);
           SharedHitMatrix[i][j] = numHitsShared/recoMu.innerTrack()->numberOfValidHits();
           //cout<<"        shared Hits: "<<numHitsShared<<endl;

         }
        }
       //cout<<"Frac Shared hits with L3: "<<SharedHitMatrix[i][j]<<std::endl;  

       }
    }
   

 
   for (size_t k = 0; k < n1; k++) {
    size_t i_min = -1;
    size_t j_min = -1;
    double maxSharedFrac = minSharedFrac;

   for (size_t i = 0; i < n1; i++)
      for (size_t j = 0; j < n2; j++)
        if (SharedHitMatrix[i][j] > maxSharedFrac) {
          i_min = i;
          j_min = j;
          maxSharedFrac = SharedHitMatrix[i][j];
        }


   if (maxSharedFrac > minSharedFrac) {
      result[i_min] = j_min;
      SharedHitMatrix[i_min] = vector<double>(n2, NOMATCHITS);
      for (size_t i = 0; i < n1; i++)
        SharedHitMatrix[i][j_min] = NOMATCHITS;
    }
  }
  
  
  return result;



}//function end

*/

/*

float MuonNtuples::matchedL3hitFrac(const std::vector<reco::Muon>::const_iterator & mu,trigger::TriggerObjectCollection& hltl3muons,const edm::Handle<reco::MuonTrackLinksCollection>& links, float &L3pt, float &L3eta, float &L3phi){



    const size_t n2 = hltl3muons.size();
    float hitFracs;
    hitFracs=0;
    reco::TrackRef mutk = mu->innerTrack();

    for (size_t j = 0; j < n2; j++) {//loop over L3
      trigger::TriggerObject & l3mu = hltl3muons[j];
  
      for(unsigned int l(0); l <links->size(); ++l){
        
        const reco::MuonTrackLinks* link = &links->at(l);
        const reco::Track& globalTrack = *link->globalTrack();
        float dR2 = deltaR2(l3mu.eta(),l3mu.phi(),globalTrack.eta(),globalTrack.phi());
        float dR=sqrt(dR2);
        float dPt = std::abs(l3mu.pt() - globalTrack.pt())/l3mu.pt();

           if(dR < 0.2 ) {
           reco::TrackRef tk = link->trackerTrack();

           int NumMuonHits=0;int NumL3Hits=0;
           int numHitsShared = sharedHits(*mutk, *tk,NumMuonHits,NumL3Hits);
              ///comment
              for (trackingRecHit_iterator hit1 = mutk->recHitsBegin(); hit1 != mutk->recHitsEnd(); ++hit1) {
                 if ( !(*hit1)->isValid() ) continue;
                 DetId id1 = (*hit1)->geographicalId();

                 std::cout<<"Offline Muon SubdetID: "<<id1.subdetId()<<std::endl;
                 std::cout<<"Offline Muon RawID: "<<id1.rawId()<<std::endl;
                 }

           for (trackingRecHit_iterator hit1 = tk->recHitsBegin(); hit1 != tk->recHitsEnd(); ++hit1) {
                 if ( !(*hit1)->isValid() ) continue;
                 DetId id1 = (*hit1)->geographicalId();

                 std::cout<<"Online Muon SubdetID: "<<id1.subdetId()<<std::endl;
                 std::cout<<"Online Muon RawID: "<<id1.rawId()<<std::endl;
                 }
             ////////////////////////////////////comment
           float hitFrac= float(numHitsShared)/float(mu->innerTrack()->numberOfValidHits());
           if(hitFrac>hitFracs){

             hitFracs=hitFrac;
             L3pt=l3mu.pt();
             L3eta=l3mu.eta();
             L3phi=l3mu.phi();

            }
          // std::cout<<"Shared Hit Frac: "<<hitFrac<<std::endl;

          }
        }//loop over links
      }//loop over L3
   

  return hitFracs;

}
*/
/*
float MuonNtuples::matchedL3hitFrac(const std::vector<reco::Muon>::const_iterator & mu,const edm::Handle<reco::RecoChargedCandidateCollection> & hltl3muons,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi){
    const size_t n2 = hltl3muons->size();
    float hitFracs;
    hitFracs=0;
    reco::TrackRef mutk = mu->innerTrack();

      for( unsigned int il3 = 0; il3 < hltl3muons->size(); ++il3) {

       reco::RecoChargedCandidateRef candref(hltl3muons, il3);
       reco::TrackRef tk=candref->track();      
       int NumMuonHits=0;int NumL3Hits=0;
       int numHitsShared = sharedHits(*mutk, *tk,NumMuonHits,NumL3Hits);
 
       float hitFrac= float(numHitsShared)/float(mu->innerTrack()->numberOfValidHits());
           if(hitFrac>hitFracs){

             hitFracs=hitFrac;
             L3pt=candref->pt();
             L3eta=candref->eta();
             L3phi=candref->phi();

            }
  
    }
  return hitFracs;
}
*/


/*
float MuonNtuples::matchedL3hitFracPixel(const std::vector<reco::Muon>::const_iterator & mu,const edm::Handle<reco::RecoChargedCandidateCollection> & hltl3muons,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi){
    const size_t n2 = hltl3muons->size();
    float hitFracs;
    hitFracs=0;


    reco::TrackRef mutk = mu->innerTrack();

      for( unsigned int il3 = 0; il3 < hltl3muons->size(); ++il3) {

       reco::RecoChargedCandidateRef candref(hltl3muons, il3);


     //  cout<<"...L3 muon: "<<il3<<"(pt,eta,phi): "<<candref->pt()<<", "<<candref->eta()<<", "<<candref->phi()<<endl;

       reco::TrackRef tk=candref->track();
       int NumOfflinePixel=0;int NumMatchedPixel=0;


       float hitFrac= frac_sharedHitsPixel(*mutk, *tk);


           if(hitFrac>hitFracs){

             hitFracs=hitFrac;
             L3pt=candref->pt();
             L3eta=candref->eta();
             L3phi=candref->phi();

            }

    }

  return hitFracs;
}
*/


/*
float MuonNtuples::matchedL3hitFracStrip(const std::vector<reco::Muon>::const_iterator & mu,const edm::Handle<reco::RecoChargedCandidateCollection> & hltl3muons,const edm::Handle<reco::MuonTrackLinksCollection>& links,float &L3pt, float &L3eta, float &L3phi){
    const size_t n2 = hltl3muons->size();
    float hitFracs;
    hitFracs=0;
    reco::TrackRef mutk = mu->innerTrack();

    const reco::Track trackoff=*mutk;


    for (trackingRecHit_iterator hit1 = trackoff.recHitsBegin(); hit1 != trackoff.recHitsEnd(); ++hit1) {//offline rechit loop
      if ( !(*hit1)->isValid() ) continue;

       TrackingRecHit *rhof=*hit1;
       SiStripRecHit1D* ofb1 = dynamic_cast<SiStripRecHit1D*> (rhof);
       SiStripRecHit2D* ofb2 = dynamic_cast<SiStripRecHit2D*> (rhof);
       SiPixelRecHit* ofb3 = dynamic_cast<SiPixelRecHit*> (rhof);

       std::cout<<"Offline Rechit type         : "<<rhof->getType()<<std::endl;
       std::cout<<"Offline rTTI                : "<<rhof->getRTTI()<<std::endl;

       DetId id1 = (*hit1)->geographicalId();
       std::cout<<"Offline rechit RawID        : "<<id1.rawId()<<std::endl;
       GlobalPoint pos1 = theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPosition());
       std::cout<<"Offline Global position     : "<<pos1<<std::endl;
       std::cout<<"Offline Rechit dimension online: "<<(*hit1)->dimension()<<std::endl;

    
       if(ofb1!=NULL)OmniClusterRef::ClusterStripRef RefStr1=ofb1->cluster_strip();
       if(ofb2!=NULL)OmniClusterRef::ClusterStripRef RefStr2=ofb2->cluster_strip();
       if(ofb3!=NULL)OmniClusterRef::ClusterPixelRef RefPixel=ofb3->cluster_pixel();




       }// offline rechit loop




      for( unsigned int il3 = 0; il3 < hltl3muons->size(); ++il3) {

       reco::RecoChargedCandidateRef candref(hltl3muons, il3);
       reco::TrackRef tk=candref->track();

       std::cout<<"Online muon (pt,eta,phi): "<<candref->pt()<<", "<<candref->eta()<<", "<<candref->phi()<<std::endl;

       int NumOfflineStrip=0;int NumMatchedStrip=0;

       const reco::Track track=*tk;

      for (trackingRecHit_iterator hit2 = track.recHitsBegin(); hit2 != track.recHitsEnd(); ++hit2) {//online rechit loop
      if ( !(*hit2)->isValid() ) continue;


        TrackingRecHit *rh=*hit2;
        SiStripRecHit1D* b1 = dynamic_cast<SiStripRecHit1D*> (rh);
        SiStripRecHit2D* b2 = dynamic_cast<SiStripRecHit2D*> (rh);
        SiPixelRecHit* b3 = dynamic_cast<SiPixelRecHit*> (rh);

        if(b1!=NULL)OmniClusterRef::ClusterStripRef RefStr1=b1->cluster_strip();
        if(b2!=NULL)OmniClusterRef::ClusterStripRef RefStr2=b2->cluster_strip();
        if(b3!=NULL)OmniClusterRef::ClusterPixelRef RefPixel=b3->cluster_pixel();

        std::cout<<"Online rechit type      : "<<rh->getType()<<std::endl;
        std::cout<<"Online rTTI             : "<<rh->getRTTI()<<std::endl;
        DetId id2 = (*hit2)->geographicalId();
        std::cout<<"Online  muon RawID      : "<<id2.rawId()<<std::endl;
        GlobalPoint pos2 = theService->trackingGeometry()->idToDet(id2)->surface().toGlobal((*hit2)->localPosition());
        std::cout<<"Online Global position  : "<<pos2<<std::endl;
        std::cout<<"Online Rechit dimension : "<<(*hit2)->dimension()<<std::endl;



         }//online rechit loop

       float hitFrac= frac_sharedHitsStrip(*mutk, *tk);
           if(hitFrac>hitFracs){

             hitFracs=hitFrac;
             L3pt=candref->pt();
             L3eta=candref->eta();
             L3phi=candref->phi();

            }


       std::cout<<"Shared Fraction: "<<hitFrac<<std::endl;
    }
  return hitFracs;
}

*/



/*
vector<size_t> MuonNtuples::matchBySharedHits(const reco::TrackExtraCollection& muons,
                                                  trigger::TriggerObjectCollection& hltl3muons,
                                                  const edm::Handle<reco::MuonTrackLinksCollection>& links, const double minSharedFrac)
{


  const size_t n1 = muons.size();
  const size_t n2 = hltl3muons.size();

  vector<size_t> result(n1, -1);
  vector<vector<double> > SharedHitMatrix(n1, vector<double>(n2, NOMATCHITS));

   for (size_t i = 0; i < n1; i++) {
    const reco::TrackExtra  recoMu = muons[i];


       for (size_t j = 0; j < n2; j++) {
      trigger::TriggerObject & l3mu = hltl3muons[j];

      for(unsigned int l(0); l <links->size(); ++l){
        const reco::MuonTrackLinks* link = &links->at(l);
        const reco::Track& globalTrack = *link->globalTrack();
        float dR2 = deltaR2(l3mu.eta(),l3mu.phi(),globalTrack.eta(),globalTrack.phi());
        float dPt = std::abs(l3mu.pt() - globalTrack.pt())/l3mu.pt();


        if (dR2 < 0.1 and dPt < 0.2) {
          reco::TrackRef tk = link->trackerTrack();
          SharedHitMatrix[i][j] = sharedHits(recoMu, *tk);//recoMu.innerTrack()->numberOfValidHits();

                    }
     }

    }
   }


    for(size_t k = 0; k < n1; k++) {
    size_t i_min = -1;
    size_t j_min = -1;
    double maxSharedFrac = minSharedFrac;

     for(size_t i = 0; i < n1; i++)
      for(size_t j = 0; j < n2; j++)
        if(SharedHitMatrix[i][j] > maxSharedFrac) {
          i_min = i;
          j_min = j;
          maxSharedFrac = SharedHitMatrix[i][j];
        }

      if(maxSharedFrac > minSharedFrac) {
      result[i_min] = j_min;
      SharedHitMatrix[i_min] = vector<double>(n2, NOMATCHITS);
      for(size_t i = 0; i < n1; i++)
        SharedHitMatrix[i][j_min] = NOMATCHITS;
    }
  }
  return result;


}///
*/

/*
int MuonNtuples::sharedHits(const reco::Track& track1, const reco::Track& track2, int &NumMuonHits,int &NumL3Hits) const {

  int match = 0;
 // cout << "Number of RecHits Track1: " << track1.recHitsSize() << endl;
 // cout << "Number of RecHits Track2: " << track2.recHitsSize() << endl;
 
    
  for (trackingRecHit_iterator hit1 = track1.recHitsBegin(); hit1 != track1.recHitsEnd(); ++hit1) {
    if ( !(*hit1)->isValid() ) continue;
    NumMuonHits++;
    DetId id1 = (*hit1)->geographicalId();
       
    //std::cout<<"RecHit start offline: "<<NumMuonHits<<std::endl;
    //std::cout<<"Offline Muon SubdetID: "<<id1.subdetId()<<std::endl;
    //std::cout<<"Offline Muon RawID: "<<id1.rawId()<<std::endl;

    NumL3Hits=0;
    for (trackingRecHit_iterator hit2 = track2.recHitsBegin(); hit2 != track2.recHitsEnd(); ++hit2) {
      if ( !(*hit2)->isValid() ) continue;
      NumL3Hits++;
      DetId id2 = (*hit2)->geographicalId();
      
      //std::cout<<"DetID: "<<id2.DetId()<<std::endl;
      if (id2.subdetId() != id1.subdetId()) continue;

      //std::cout<<"DetId----"<<id2<<std::endl;
     // std::cout<<"SubdetID----"<<id2.subdetId()<<std::endl;
      if (id2.rawId() != id1.rawId() ) continue;

     // GlobalPoint pos1 = theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPosition());
     // GlobalPoint pos2 = theService->trackingGeometry()->idToDet(id2)->surface().toGlobal((*hit2)->localPosition());
     // double diff = ( pos1 - pos2 ).mag();
      match++;
    // std::cout<<"Global Position: "<<pos1<<std::endl;

      //cout << "GLOBAL: Pos1 - Pos2 = " << pos1 << " - " << pos2 << " = " << diff << endl;
      //cout << "LOCAL:  Pos1 - Pos2 = " << (*hit1)->localPosition() <<" - "<< (*hit2)->localPosition() << " = " << ((*hit1)->localPosition()-(*hit2)->localPosition()).mag()<< endl;
    }
  }
  //cout << "N Shared Hits: " << match << " / " << track1.numberOfValidHits() << " --> " << track1.pt() << " , " << track1.eta() << " , " << track1.phi() << endl;
  //cout << "N Shared Hits: " << match << " / " << track2.numberOfValidHits() << " --> " << track2.pt() << " , " << track2.eta() << " , " << track2.phi() << endl;
  
 // cout<<"        NumMuonHits: "<<NumMuonHits<<endl;
 // cout<<"        NumL3Hits: "<<NumL3Hits<<endl;

  return match;


}
*/

/*
float MuonNtuples::frac_sharedHitsPixel(const reco::Track& track1, const reco::Track& track2) const {

  float match = 0;

  int NumOfflinePixel=0;int NumMatchedPixel=0;


  for (trackingRecHit_iterator hit1 = track1.recHitsBegin(); hit1 != track1.recHitsEnd(); ++hit1) {
    if ( !(*hit1)->isValid() ) continue;
    DetId id1 = (*hit1)->geographicalId();

    int subdetId=id1.subdetId();
    bool pass=false;
    if(subdetId == 1 || subdetId == 2 ) pass=true;
    if(pass==false)continue;


    NumOfflinePixel++;
    for (trackingRecHit_iterator hit2 = track2.recHitsBegin(); hit2 != track2.recHitsEnd(); ++hit2) {
      if ( !(*hit2)->isValid() ) continue;
      DetId id2 = (*hit2)->geographicalId();



      if (id2.subdetId() != id1.subdetId()) continue;


      if (id2.rawId() != id1.rawId() ) continue;

      GlobalPoint pos1 = theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPosition());
      GlobalPoint pos2 = theService->trackingGeometry()->idToDet(id2)->surface().toGlobal((*hit2)->localPosition());
      double diff = ( pos1 - pos2 ).mag();
      NumMatchedPixel++;

    }
  }

  //cout<<"Num offlinepixel  hits: "<<NumOfflinePixel<<endl;
  //cout<<"Num matched hits pixel: "<<NumMatchedPixel<<endl;


  match=float(NumMatchedPixel)/float(NumOfflinePixel);

  
  return match;

}
*/

/*
float MuonNtuples::frac_sharedHitsStrip(const reco::Track& track1, const reco::Track& track2) const {

  float match = 0;
  int NumOfflineStrip=0;int NumMatchedStrip=0;

  int p=0;
  for(trackingRecHit_iterator hit1 = track1.recHitsBegin(); hit1 != track1.recHitsEnd(); ++hit1) {
    if ( !(*hit1)->isValid() ) continue;
    DetId id1 = (*hit1)->geographicalId();
    int subdetId=id1.subdetId();

    //bool pass=false;
    //if(subdetId == 3 || subdetId == 4 || subdetId == 5 || subdetId == 6) pass=true;
    //if(pass==false)continue;

    //std::cout<<"isMatched ():  "<<(*hit1)->isMatched()<<std::endl;
    //std::cout<<"isMulti (): "<<(*hit1)->isMulti()<<std::endl;
    //std::cout<<"isPixel():  "<<(*hit1)->isPixel()<<std::endl;
    //std::cout<<"isProjected (): "<<(*hit1)->isProjected()<<std::endl;


    NumOfflineStrip++;
    //std::cout<<"rawId of offline muon : "<<id1.rawId()<<std::endl;
   // GlobalPoint pos1 = theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPosition());
    //GlobalError gerr1= theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPositionError());


    for (trackingRecHit_iterator hit2 = track2.recHitsBegin(); hit2 != track2.recHitsEnd(); ++hit2) {
      if ( !(*hit2)->isValid() ) continue;
      DetId id2 = (*hit2)->geographicalId();


      if (id2.subdetId() != id1.subdetId()) continue;

      if (id2.rawId() != id1.rawId() ) continue;

      GlobalPoint pos1 = theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPosition());
      GlobalPoint pos2 = theService->trackingGeometry()->idToDet(id2)->surface().toGlobal((*hit2)->localPosition());
      double diff = ( pos1 - pos2 ).mag();
      NumMatchedStrip++;
      //std::cout <<"This one is a matched RawID"<<std::endl;

    }
  }

  match=float(NumMatchedStrip)/float(NumOfflineStrip);
  return match;

}
*/

/*

int MuonNtuples::sharedHits(const reco::TrackExtra& track1, const reco::Track& track2) const {

  int match = 0;
  cout << "Number of RecHits Track1: " << track1.recHitsSize() << endl;
  cout << "Number of RecHits Track2: " << track2.recHitsSize() << endl;

  
  for (trackingRecHit_iterator hit1 = track1.recHitsBegin(); hit1 != track1.recHitsEnd(); ++hit1) {
    if ( !(*hit1)->isValid() ) continue;
    DetId id1 = (*hit1)->geographicalId();

    
    for (trackingRecHit_iterator hit2 = track2.recHitsBegin(); hit2 != track2.recHitsEnd(); ++hit2) {
      if ( !(*hit2)->isValid() ) continue;
      DetId id2 = (*hit2)->geographicalId();
      if (id2.subdetId() != id1.subdetId()) continue;
      if (id2.rawId() != id1.rawId() ) continue;

      GlobalPoint pos1 = theService->trackingGeometry()->idToDet(id1)->surface().toGlobal((*hit1)->localPosition());
      GlobalPoint pos2 = theService->trackingGeometry()->idToDet(id2)->surface().toGlobal((*hit2)->localPosition());
      double diff = ( pos1 - pos2 ).mag();
      match++;
      cout << "GLOBAL: Pos1 - Pos2 = " << pos1 << " - " << pos2 << " = " << diff << endl;
      cout << "LOCAL:  Pos1 - Pos2 = " << (*hit1)->localPosition() <<" - "<< (*hit2)->localPosition() << " = " << ((*hit1)->localPosition()-(*hit2)->localPosition()).mag()<< endl;

      }
    

  }
  
  return match;
 
}

*/



// define this as a plug-in
DEFINE_FWK_MODULE(MuonNtuples);
