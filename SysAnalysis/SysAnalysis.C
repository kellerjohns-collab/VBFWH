#define SysAnalysis_cxx
#include "SysAnalysis.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

enum regs{ Presel, WCR_Neg, WtCR_Neg, ttbarCR_Neg, WCR_Pos, WtCR_Pos, ttbarCR_Pos,  SRNeg, SRPosTight, SRPosLoose, VRNeg, VRPosTight, VRPosLoose, nRegs};
TString regNames[nRegs] = {"Presel", "WCR_Neg", "WtCR_Neg", "ttbarCR_Neg", "WCR_Pos", "WtCR_Pos", "ttbarCR_Pos", "SRNeg", "SRPosTight", "SRPosLoose", "VRNeg", "VRPosTight", "VRPosLoose" };

//remove alternative CR systs
// enum alts{ WCR_Neg_alt, WtCR_Neg_alt, ttbarCR_Neg_alt, WCR_Pos_alt, WtCR_Pos_alt, ttbarCR_Pos_alt, nAlts};
// TString altNames[nAlts] = { "WCR_Neg_alt", "WtCR_Neg_alt", "ttbarCR_Neg_alt", "WCR_Pos_alt", "WtCR_Pos_alt", "ttbarCR_Pos_alt" };

enum alts{ WCR_Neg_alt, WtCR_Neg_alt, ttbarCR_Neg_alt, WCR_Pos_alt, WtCR_Pos_alt, ttbarCR_Pos_alt};
TString altNames[6] = { "WCR_Neg_alt", "WtCR_Neg_alt", "ttbarCR_Neg_alt", "WCR_Pos_alt", "WtCR_Pos_alt", "ttbarCR_Pos_alt" };
int nAlts = 0;

void SysAnalysis::Loop(TChain* chain)
{
   if (chain == 0) return;
   bool isNominal = ((TString)chain->GetName()).Contains("Nominal") && m_isNominalMC;

   //Declare hists
   vector<TH1F*>* hvec = new vector<TH1F*>();
   for(int r = 0; r < nRegs; r++){
     TH1F* ht = new TH1F("sum_"+regNames[r]+"_"+chain->GetName(), "sum_"+regNames[r]+"_"+chain->GetName(), 1,0,1);
     hvec->push_back(ht);
   }

   vector<vector<TH1F*>*>* bvec;
   vector<vector<TH1F*>*>* cvec;
   vector<vector<TH1F*>*>* lvec;
   vector<vector<TH1F*>*>* tvec;
   vector<vector<TH1F*>*>* sample_vec;
   

   if(isNominal){

     bvec = new vector<vector<TH1F*>*>();
     cvec = new vector<vector<TH1F*>*>();
     lvec = new vector<vector<TH1F*>*>();
     tvec = new vector<vector<TH1F*>*>();
     sample_vec = new vector<vector<TH1F*>*>();

     for(int r = 0; r < nRegs; r++){
       vector<TH1F*>* tempvec = new vector<TH1F*>();
       for(unsigned int b = 0; b < bsys->size();b++){
	 TH1F* ht = new TH1F("sum_"+regNames[r]+"_B"+intNames[b],"",1,0,1);
	 tempvec->push_back(ht);
       }
       bvec->push_back(tempvec);

       tempvec = new vector<TH1F*>();
       for(unsigned int c = 0; c < csys->size();c++){
	 TH1F* ht = new TH1F("sum_"+regNames[r]+"_C"+intNames[c],"",1,0,1);
	 tempvec->push_back(ht);
       }
       cvec->push_back(tempvec);

       tempvec = new vector<TH1F*>();
       for(unsigned int l = 0; l < lsys->size();l++){
	 TH1F* ht = new TH1F("sum_"+regNames[r]+"_L"+intNames[l],"",1,0,1);
	 tempvec->push_back(ht);
       }
       lvec->push_back(tempvec);

       tempvec = new vector<TH1F*>();
       for(unsigned int t = 0; t < tsys->size();t++){
	 TH1F* ht = new TH1F("sum_"+regNames[r]+"_"+TrigNames[t],"",1,0,1);
	 tempvec->push_back(ht);
       }
       tvec->push_back(tempvec);

       tempvec = new vector<TH1F*>();
       for(unsigned int s = 0; s < sample_sys->size();s++){
	 TH1F* ht;
	 if(m_process.Contains("Sig")) ht = new TH1F("sum_"+regNames[r]+"_"+SigVarNames[s],"",1,0,1);
	 if(m_process == "W") ht = new TH1F("sum_"+regNames[r]+"_"+WVarNames[s],"",1,0,1);
	 if(m_process == "Wt") ht = new TH1F("sum_"+regNames[r]+"_"+WtVarNames[s],"",1,0,1);
	 if(m_process == "stopt") ht = new TH1F("sum_"+regNames[r]+"_"+stoptVarNames[s],"",1,0,1);
	 if(m_process == "Z") ht = new TH1F("sum_"+regNames[r]+"_"+ZVarNames[s],"",1,0,1);
	 if(m_process == "WH") ht = new TH1F("sum_"+regNames[r]+"_"+WHVarNames[s],"",1,0,1);
	 if(m_process == "WZqcd") ht = new TH1F("sum_"+regNames[r]+"_"+WZVarNames[s],"",1,0,1);
	 if(m_process == "WZewk") ht = new TH1F("sum_"+regNames[r]+"_"+WZjjVarNames[s],"",1,0,1);

	 tempvec->push_back(ht);
       }
       if(tempvec->size() > 0) sample_vec->push_back(tempvec);       

     }

   }

   if(m_process == "ttbar05"){
     sample_vec = new vector<vector<TH1F*>*>();
     for(int r = 0; r < nRegs; r++){
       vector<TH1F*>* tempvec = new vector<TH1F*>();
       for(unsigned int s = 0; s < sample_sys->size();s++){
	 TH1F* ht;
	 ht = new TH1F("sum_"+regNames[r]+"_"+ttbar05VarNames[s],"",1,0,1);
	 tempvec->push_back(ht);
       }
       if(tempvec->size() > 0) sample_vec->push_back(tempvec);       
     }
   }
   if(m_process == "Wt05"){
     sample_vec = new vector<vector<TH1F*>*>();
     for(int r = 0; r < nRegs; r++){
       vector<TH1F*>* tempvec = new vector<TH1F*>();
       for(unsigned int s = 0; s < sample_sys->size();s++){
	 TH1F* ht;
	 ht = new TH1F("sum_"+regNames[r]+"_"+Wt05VarNames[s],"",1,0,1);
	 tempvec->push_back(ht);
       }
       if(tempvec->size() > 0) sample_vec->push_back(tempvec);       
     }
   }
   
   if(isNominal || m_process == "data"){
     for(int a = 0; a < nAlts; a++){
       TH1F* ht = new TH1F("sum_"+altNames[a]+"_"+chain->GetName(), "sum_"+altNames[a]+"_"+chain->GetName(), 1,0,1);
       hvec->push_back(ht);
     }
   }

   cout<<"Running on "<<m_process<<", tree "<<chain->GetName()<<" with "<<chain->GetEntries()<<" events."<<endl;


   Long64_t nentries = chain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      chain->LoadTree(jentry);
      nb = chain->GetEntry(jentry);
      
      if(jentry % 1000000 == 0 && jentry > 0) cout<<"On event "<<jentry<<endl;

      if(!passIsoNom) continue;

      float myWeight = EventWeight;
      if(m_process.Contains("Wt") || m_process.Contains("ttbar")) myWeight = LumiWeight*MCEventWeight*PUWeight*BTagSF*TriggerSF*JVTWeightResolved*LeptonSF*fJVTSF;
      if(m_process == "WZ") myWeight = EventWeight; //because samples overlap.
      if(m_process == "W_Sh2211") myWeight = myWeight*(Sys__MUR1_MUF1_PDF303200_ASSEW/MCEventWeight);

      //Define 4-vectors
      TLorentzVector j1TLV, j2TLV, b1TLV, b2TLV;
      j1TLV.SetPtEtaPhiM(vbf_j1_pt,vbf_j1_eta,vbf_j1_phi,vbf_j1_m);
      j2TLV.SetPtEtaPhiM(vbf_j2_pt,vbf_j2_eta,vbf_j2_phi,vbf_j2_m);
      b1TLV.SetPtEtaPhiM(pTB1,etaB1,phiB1,mB1);
      b2TLV.SetPtEtaPhiM(pTB2,etaB2,phiB2,mB2);

      float dRBB_Rap = b1TLV.DeltaR(b2TLV, 1);

      //Count "veto" jets, either with simple y requirement, or between VBF jets
      int nVeto25 = 0;

      for(unsigned int j = 0; j < jet_pt->size(); j++){
	if( jet_btagbin->at(j) > 3 ) continue;
	if(jet_pt->at(j) < 25) continue;
	TLorentzVector jvec;
	jvec.SetPtEtaPhiE( jet_pt->at(j), jet_eta->at(j), jet_phi->at(j), jet_e->at(j) );
	if(jvec.DeltaR( j1TLV ) < 0.01 || jvec.DeltaR( j2TLV ) < 0.01) continue;

	if( TMath::Abs(jvec.Rapidity()) < 2.5 ){
	  nVeto25++;
	}

      }


      //
      //Define the regions

      vector<bool>* regVec = new vector<bool>(nRegs, 0);

      //Preselection: you've already passed it.
      regVec->at(Presel) = true;

      //
      //Control regions: negative lambda
      //W CR_Neg
      regVec->at(WCR_Neg) = vbf_dyjj > 3.0 && (pTBB < 250 && pTBB > 150) && (pTBB*-0.007 + 2.23 > dRBB_Rap) && vbf_mLepTop > 275 && (mBB < 70)  && (vbf_j1_pt > 70);  

      //Wt CR_Neg
      regVec->at(WtCR_Neg) = (pTBB > 250) && (dRBB_Rap > 1.5) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 320) && (pTV > 250) && (j1TLV.Pt() < 350); //March 3 version
      //regVec->at(WtCR_Neg) = (pTBB > 250) && (dRBB_Rap > 1.5) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 260) && (pTV > 250) && (j1TLV.Pt() < 300); //March 7 test

      //ttbar CR_Neg
      regVec->at(ttbarCR_Neg) = (pTBB > 200) && (dRBB_Rap < 1.2) && (vbf_dyjj > 3.0 && vbf_dyjj < 4.4) && (vbf_mLepTop > 260) && (mBB > 145); 

      //Positive lambda CRs
      //W CR Positive
      regVec->at(WCR_Pos) = (vbf_dyjj > 3.0) && (pTBB > 80) && (pTBB*-0.007 + 2.23 > dRBB_Rap) && (vbf_mLepTop > 260) && (mBB < 70) && (vbf_mjj > 500) && (nVeto25 == 0) && (vbf_j1_pt > 70) && (mTW < 200);
      
      //Wt CR Positive
      regVec->at(WtCR_Pos) = (pTBB > 180) && (dRBB_Rap > 1.6) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 320) && (vbf_mjj > 500) && (nVeto25 < 2) && (mBB > 145) && (pTV > 250) && (j1TLV.Pt() < 350); //March 3 version
      //regVec->at(WtCR_Pos) = (pTBB > 180) && (dRBB_Rap > 1.6) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 260) && (vbf_mjj > 500) && (nVeto25 < 2) && (mBB > 145) && (pTV > 250) && (j1TLV.Pt() < 300); //March 7 test

      //ttbar CR Positive
      regVec->at(ttbarCR_Pos) = (dRBB_Rap < 1.5) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 220) && (mBB > 145) && (vbf_mjj > 400 && vbf_mjj < 1000) && (nVeto25 < 2) && (pTV < 350); 

      //
      //Signal regions

      //Signal region, Negative lambda (version 2.0)
      regVec->at(SRNeg) = (vbf_dyjj > 4.4) && (vbf_mLepTop > 260) && (pTBB > 250) && (mBB > 105 && mBB < 145) && (vbf_centralityHW < 0.3) && (dRBB_Rap < 1.2);

      //Positive lambda signal regions, loose and tight
      regVec->at(SRPosTight) = (mBB > 105 && mBB < 145) && (dRBB_Rap < 1.2) && (pTBB > 180) && (vbf_mLepTop > 260) && (vbf_mjj > 1000) && (vbf_dyjj > 3.0) && (vbf_centralityHW < 0.30) && (nVeto25 == 0) && (vbf_dphiHWjj > 2.7);

      regVec->at(SRPosLoose) = (!regVec->at(SRPosTight)) && (mBB > 105 && mBB < 145) && (dRBB_Rap < 1.6) && (vbf_mLepTop > 260) && (vbf_mjj > 600) && (vbf_dyjj > 3.0) && (vbf_centralityHW < 0.3) && (nVeto25 < 2) && (pTBB > 100);

      //Validation regions
      regVec->at(VRNeg) = passIsoNom && (vbf_dyjj > 4.4) && (vbf_mLepTop > 260) && (pTBB > 250) && (mBB < 80 || mBB > 160) && (vbf_centralityHW < 0.3) && (dRBB_Rap < 1.5) && (vbf_j1_pt > 70 || mBB > 100);

      regVec->at(VRPosTight) = passIsoNom && (mBB < 105 || mBB > 145) && (dRBB_Rap < 1.6) && (pTBB > 180) && (vbf_mLepTop > 260) && (vbf_mjj > 1000) && (vbf_dyjj > 3.0) && (vbf_centralityHW < 0.30) && (nVeto25 == 0) && (vbf_dphiHWjj > 2.7) && (vbf_j1_pt > 70 || mBB > 125) && ((pTBB*-0.007 + 2.23 < dRBB_Rap) || mBB > 125); //last criterion to avoid overlap with WCR

      regVec->at(VRPosLoose) = passIsoNom && (!regVec->at(VRPosTight)) && (mBB < 105 || mBB > 145) && (dRBB_Rap < 1.6) && (vbf_mLepTop > 260) && (vbf_mjj > 600) && (vbf_dyjj > 3.0) && (vbf_centralityHW < 0.3) && (nVeto25 < 2) && ((pTBB*-0.007 + 2.23 < dRBB_Rap) || mBB > 125) && ((vbf_mjj > 1000 || mBB < 125) || (pTV > 350 || mBB < 125)) && (vbf_j1_pt > 70 || mBB > 125);

      //Alternative control regions
      vector<bool>* altVec = new vector<bool>(nAlts, 0);
      // //W CR Neg Alt
      // altVec->at(WCR_Neg_alt) = vbf_dyjj > 4.4 && (pTBB < 250 && pTBB > 100) && (pTBB*-0.007 + 2.23 > dRBB_Rap) && vbf_mLepTop > 275 && (mBB < 70);

      // //Wt CR_Neg alt
      // altVec->at(WtCR_Neg_alt) = (pTBB > 250) && (dRBB_Rap > 1.2) && (vbf_dyjj > 4.4) && (vbf_mLepTop > 300) && (pTV > 250) && (j1TLV.Pt() < 350);

      // //ttbar CR_Neg alt
      // altVec->at(ttbarCR_Neg_alt) = (pTBB > 200) && (dRBB_Rap < 1.3) && (vbf_dyjj > 4.4) && (vbf_mLepTop > 250) && (mBB > 140) && (pTV < 350); //

      // //W CR Pos Alt
      // altVec->at(WCR_Pos_alt) = vbf_dyjj > 3.0 && (pTBB > 50) && (pTBB*-0.007 + 2.23 > dRBB_Rap) && vbf_mLepTop > 275 && (mBB < 70) && (vbf_mjj > 800) && (nVeto25 == 0); ;

      // //Wt CR_Pos alt
      // altVec->at(WtCR_Pos_alt) = (pTBB > 180) && (dRBB_Rap > 1.3) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 300) && (vbf_mjj > 800) && (nVeto25 < 2) && (mBB > 145) && (pTV > 250) && (j1TLV.Pt() < 350);

      // //ttbar CR_Pos alt
      // altVec->at(ttbarCR_Pos_alt) = (dRBB_Rap < 1.5) && (vbf_dyjj > 3.0) && (vbf_mLepTop > 260) && (mBB > 140) && (vbf_mjj > 800) && (nVeto25 < 3) && (pTV < 250); //

      //Fill hists
      for(int r = 0; r < nRegs; r++){

	if(regVec->at(r)){

	  hvec->at(r)->Fill(0.5, myWeight);

	  if(isNominal){

	    for(unsigned int b = 0; b < bsys->size(); b++){
	      bvec->at(r)->at(b)->Fill(0.5, myWeight*bsys->at(b));
	    }
	    for(unsigned int c = 0; c < csys->size(); c++){
	      cvec->at(r)->at(c)->Fill(0.5, myWeight*csys->at(c));
	    }
	    for(unsigned int l = 0; l < lsys->size(); l++){
	      lvec->at(r)->at(l)->Fill(0.5, myWeight*lsys->at(l));
	    }
	    for(unsigned int t = 0; t < tsys->size(); t++){
	      tvec->at(r)->at(t)->Fill(0.5, myWeight*tsys->at(t));
	    }
	    if(sample_vec->size() > 0) {
	      for(unsigned int s = 0; s < sample_sys->size(); s++){
		sample_vec->at(r)->at(s)->Fill(0.5, myWeight*sample_sys->at(s)/MCEventWeight);
	      }
	    }

	  }
	  if(m_process == "ttbar05" || m_process == "Wt05"){
	    for(unsigned int s = 0; s < sample_sys->size(); s++){
	      sample_vec->at(r)->at(s)->Fill(0.5, myWeight*sample_sys->at(s)/MCEventWeight);
	    }
	  }

	}

      }

      if(isNominal || m_process == "data"){
	for( int a = 0; a < nAlts; a++){
	  if(altVec->at(a)) hvec->at(a+nRegs)->Fill(0.5, myWeight);
	}	
      }

   } //end event loop


   //Write out hists
   m_outFile->cd();
   for(int r = 0; r < nRegs; r++){
     hvec->at(r)->Write();
     
     if(isNominal){
       for(unsigned int b = 0; b < bsys->size(); b++){
	 bvec->at(r)->at(b)->Write();
       }
       for(unsigned int c = 0; c < csys->size(); c++){
	 cvec->at(r)->at(c)->Write();
       }
       for(unsigned int l = 0; l < lsys->size(); l++){
	 lvec->at(r)->at(l)->Write();
       }
       for(unsigned int t = 0; t < tsys->size(); t++){
	 tvec->at(r)->at(t)->Write();
       }
       if(sample_vec->size() > 0) {
	 for(unsigned int s = 0; s < sample_sys->size(); s++){
	   sample_vec->at(r)->at(s)->Write();
	 }
       }

     }
     if(m_process == "ttbar05" || m_process == "Wt05"){
       for(unsigned int s = 0; s < sample_sys->size(); s++){
	 sample_vec->at(r)->at(s)->Write();
       }
     }

   }

   if(isNominal || m_process == "data"){
     for( int a = 0; a < nAlts; a++){
       hvec->at(a+nRegs)->Write();
     }	
   }


}

