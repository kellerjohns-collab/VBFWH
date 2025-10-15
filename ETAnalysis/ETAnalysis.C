#define ETAnalysis_cxx
#include "ETAnalysis.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

//enum regs{ Presel, stopCR, WCR, ttbarSR_A, ttbarCR_B, ttbarCR_C, ttbarCR_D, SRLoose, SRv1, nRegs};
//TString regNames[nRegs] = {"Presel", "stopCR", "WCR", "ttbarSR_A", "ttbarCR_B", "ttbarCR_C", "ttbarCR_D", "SRLoose", "SRv1"};

enum regs{ Presel, stopCR, WCR, SRLoose, SRcut2, SRcut3, SRcut4, SRv1, nRegs};
TString regNames[nRegs] = {"Presel", "stopCR", "WCR", "SRLoose", "SRcut2", "SRcut3", "SRcut4", "SRv1"};

enum vbf{ MAXMJJ, MAXDY, LEADPT};

void ETAnalysis::Loop()
{
   if (fChain == 0) return;

   //jk print out cutflow
   float n0 = 0.;
   float n1 = 0.;
   float n2 = 0.;
   float n3 = 0.;
   float n4 = 0.;
   float n5 = 0.;
   float n6 = 0.;
   float n7 = 0.;

   int vbfopt = LEADPT;

   TFile* fnew = new TFile("histFiles/hists_"+m_process+".root","RECREATE");

   //Declare histograms
   vector<TH1F*>* h_VBFcands = GetHistVec("h_VBFcands",11,-0.5,10.5);
   vector<TH1F*>* h_mjj = GetHistVec("h_mjj", 50,0,2000);
   vector<TH1F*>* h_dyjj = GetHistVec("h_dyjj", 45,0,9);
   vector<TH1F*>* h_pTW = GetHistVec("h_pTW", 53,70,600);
   vector<TH1F*>* h_pTWjj = GetHistVec("h_pTWjj", 60,0,600);
   vector<TH1F*>* h_MET = GetHistVec("h_MET", 50,0,500);
   vector<TH1F*>* h_pTlep = GetHistVec("h_pTlep", 50,0,500);
   vector<TH1F*>* h_mbb = GetHistVec("h_mbb",60,0,600);
   vector<TH1F*>* h_drbb = GetHistVec("h_drbb",50,0,5);
   vector<TH1F*>* h_pTb1 = GetHistVec("h_pTb1",50,0,500);
   vector<TH1F*>* h_pTb2 = GetHistVec("h_pTb2",60,0,300);
   vector<TH1F*>* h_pTj1 = GetHistVec("h_pTj1",70,0,700);
   vector<TH1F*>* h_pTj2 = GetHistVec("h_pTj2",60,0,300);
   vector<TH1F*>* h_nVeto30 = GetHistVec("h_nVeto30",5,-0.5,4.5);
   vector<TH1F*>* h_nVeto40 = GetHistVec("h_nVeto40",5,-0.5,4.5);
   vector<TH1F*>* h_nVeto50 = GetHistVec("h_nVeto50",5,-0.5,4.5);
   vector<TH1F*>* h_nGap30 = GetHistVec("h_nGap30",5,-0.5,4.5);
   vector<TH1F*>* h_nGap40 = GetHistVec("h_nGap40",5,-0.5,4.5);
   vector<TH1F*>* h_nGap50 = GetHistVec("h_nGap50",5,-0.5,4.5);
   vector<TH1F*>* h_centrality_H = GetHistVec("h_centrality_H",80,0,4);
   vector<TH1F*>* h_centrality_lep = GetHistVec("h_centrality_lep",80,0,4);
   vector<TH1F*>* h_centrality_HW = GetHistVec("h_centrality_HW",80,0,4);
   vector<TH1F*>* h_lepCharge = GetHistVec("h_lepCharge",3,-1.5,1.5);
   vector<TH1F*>* h_dphi_jj_HW = GetHistVec("h_dphi_jj_HW",50,0,3.15);
   vector<TH1F*>* h_mLepTop_best = GetHistVec("h_mLepTop_best",100,0,500);
   vector<TH1F*>* h_mLepTop_closest = GetHistVec("h_mLepTop_closest",100,0,500);
   vector<TH1F*>* h_pTbb = GetHistVec("h_pTbb",60,0,600);
   vector<TH1F*>* h_drbbpTWjj = GetHistVec("h_drbbpTWjj",120,0,1200);
   vector<TH1F*>* h_drbbpTbb = GetHistVec("h_drbbpTbb",120,0,1200);
   vector<TH1F*>* h_drminus250overpTWjj = GetHistVec("h_drminus250overpTWjj",60,-1,5);
   vector<TH1F*>* h_drminus250overpTbb = GetHistVec("h_drminus250overpTbb",60,-1,5);
   vector<TH1F*>* h_nTauVBF = GetHistVec("h_nTauVBF",3,-0.5,2.5);
   
   vector<TH2F*>* h_mjj_dyjj = GetHistVec("h_mjj_dyjj",25,0,2000,22,0,8.8);
   vector<TH2F*>* h_pTW_drbb = GetHistVec("h_pTW_drbb",55,50,600,25,0,5);
   vector<TH2F*>* h_pTWjj_drbb = GetHistVec("h_pTWjj_drbb",60,0,600,25,0,5);
   vector<TH2F*>* h_pTWjj_pTbb = GetHistVec("h_pTWjj_pTbb",60,0,600,60,0,600);
   vector<TH2F*>* h_pTbb_drbb = GetHistVec("h_pTbb_drbb",60,0,600,25,0,5);
   vector<TH2F*>* h_mLepTop_drbb = GetHistVec("h_mLepTop_drbb",50,0,500, 25,0,5);

   cout<<"Running on "<<m_process<<" with "<<fChain->GetEntries()<<" events."<<endl;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if(jentry % 200000 == 0) cout<<"On event "<<jentry<<endl;

      //float myWeight = EventWeight;
      float myWeight = LumiWeight*MCEventWeight*PUWeight*BTagSF*TriggerSF*LeptonSF*JVTWeightResolved;
      if(m_process == "WZ") myWeight = EventWeight; //I think, because samples overlap.

      //create vector of b-tags (to remove once we store it in ntuples)
      jet_isTagged = new vector<bool>();
      jet_isTagged->assign(jet_pt->size(), false);
      int tags = 0;
      for(unsigned int j = 0; j < jet_pt->size(); j++){
	float deta1 = jet_eta->at(j) - etaB1;
	float deta2 = jet_eta->at(j) - etaB2;
	float dphi1 = fabs(jet_phi->at(j) - phiB1);
	float dphi2 = fabs(jet_phi->at(j) - phiB2);
	if(dphi1 > TMath::Pi()) dphi1 = 2*TMath::Pi() - dphi1;
	if(dphi2 > TMath::Pi()) dphi2 = 2*TMath::Pi() - dphi2;
	if( TMath::Sqrt(deta1*deta1 + dphi1*dphi1) < 0.2){tags++; jet_isTagged->at(j) = true;}
	if( TMath::Sqrt(deta2*deta2 + dphi2*dphi2) < 0.2){tags++; jet_isTagged->at(j) = true;}
      }
      if(tags != 2) { continue; }

      //VBF candidate jets:
      //Must be 30 GeV, not b-tagged
      vector<TLorentzVector>* VBFcands = new vector<TLorentzVector>();
      for(unsigned int j = 0; j < jet_pt->size(); j++){
	if( jet_isTagged->at(j) ) continue;
	if(jet_pt->at(j) < 30) continue;
	TLorentzVector jvec;
	jvec.SetPtEtaPhiE( jet_pt->at(j), jet_eta->at(j), jet_phi->at(j), jet_e->at(j) );
	VBFcands->push_back(jvec);
      }

      //Require 2 VBF candidate jets
      if(VBFcands->size() < 2) continue; 

      //Choose the VBF jets: 3 options 
      float leadpt = 0.;
      float subleadpt = 0.;
      int leadpt_ind0 = -1;
      int leadpt_ind1 = -1;
      float max_dy = 0.;
      int maxdy_ind0 = -1;
      int maxdy_ind1 = -1;
      float max_mjj = 0.;
      int mjj_ind0 = -1;
      int mjj_ind1 = -1;

      for(unsigned int j = 0; j < VBFcands->size(); j++){

	//leading 2 jets
	if( VBFcands->at(j).Pt() > leadpt ){
	  subleadpt = leadpt;
	  leadpt = VBFcands->at(j).Pt();
	  leadpt_ind1 = leadpt_ind0;
	  leadpt_ind0 = j;
	}
	else if( VBFcands->at(j).Pt() > subleadpt ){
	  subleadpt = VBFcands->at(j).Pt();
	  leadpt_ind1 = j;
	}
	
	for(unsigned int jj = j+1; jj < VBFcands->size(); jj++){
	  //max mass pair
	  float mass = (VBFcands->at(j) + VBFcands->at(jj)).M();
	  if(mass > max_mjj){
	    max_mjj = mass;
	    mjj_ind0 = j;
	    mjj_ind1 = jj;
	  }
	  //max dy pair
	  float dy = TMath::Abs(VBFcands->at(j).Rapidity() - VBFcands->at(jj).Rapidity());
	  if(dy > max_dy){
	    max_dy = dy;
	    maxdy_ind0 = j;
	    maxdy_ind1 = jj;
	  }
	}	
      }
      

      //Define global 4-vectors
      if(vbfopt == LEADPT){
	m_j1TLV = VBFcands->at(leadpt_ind0);
	m_j2TLV = VBFcands->at(leadpt_ind1);
      }
      else if(vbfopt == MAXMJJ){
	m_j1TLV = VBFcands->at(mjj_ind0);
	m_j2TLV = VBFcands->at(mjj_ind1);
      }
      else if(vbfopt == MAXDY){
	m_j1TLV = VBFcands->at(maxdy_ind0);
	m_j2TLV = VBFcands->at(maxdy_ind1);
      }
      m_b1TLV.SetPtEtaPhiM(pTB1, etaB1, phiB1, mB1);
      m_b2TLV.SetPtEtaPhiM(pTB2, etaB2, phiB2, mB2);
      m_metTLV.SetPtEtaPhiM(met_met, etaL1, met_phi, 0); //asume MET has same eta as lepton
      m_lepTLV.SetPtEtaPhiM(ptL1, etaL1, phiL1, 0);
      

      //Define variables
      TLorentzVector VBFtlv = (m_j1TLV + m_j2TLV);
      TLorentzVector Wtlv = (m_metTLV + m_lepTLV);
      TLorentzVector Htlv = m_b1TLV + m_b2TLV;

      float mjj = VBFtlv.M();
      float dyjj = TMath::Abs(m_j1TLV.Rapidity() - m_j2TLV.Rapidity());
      float dRBB_Rap = m_b1TLV.DeltaR(m_b2TLV, 1);

      //Count "veto" jets, either with simple y requirement, or between VBF jets
      int nVeto30 = 0;
      int nVeto40 = 0;
      int nVeto50 = 0;
      int nGap30 = 0;
      int nGap40 = 0;
      int nGap50 = 0;
      for(unsigned int j = 0; j < VBFcands->size(); j++){
	if(VBFcands->at(j) == m_j1TLV || VBFcands->at(j) == m_j2TLV) continue;
	if( TMath::Abs(VBFcands->at(j).Rapidity()) < 2.5 ){
	  nVeto30++;
	  if( VBFcands->at(j).Pt() > 40 ) nVeto40++;
	  if( VBFcands->at(j).Pt() > 50 ) nVeto50++;
	}
	if( (VBFcands->at(j).Rapidity() < m_j1TLV.Rapidity() && VBFcands->at(j).Rapidity() > m_j2TLV.Rapidity()) || (VBFcands->at(j).Rapidity() > m_j1TLV.Rapidity() && VBFcands->at(j).Rapidity() < m_j2TLV.Rapidity()) ){
	  nGap30++;
	  if( VBFcands->at(j).Pt() > 40 ) nGap40++;
	  if( VBFcands->at(j).Pt() > 50 ) nGap50++;
	}
      }

      //Calculate centrality
      //(ybb - yjj)/Dyjj
      float y_bb = Htlv.Rapidity();
      float y_jj = VBFtlv.Rapidity();
      float centrality_H = fabs(y_bb - y_jj)/dyjj;
      float centrality_lep = fabs(etaL1 - y_jj)/dyjj;

      float y_HW =(Htlv + Wtlv).Rapidity();
      float centrality_HW = fabs( y_HW - y_jj)/dyjj;

      float ptWjj = (Wtlv + VBFtlv).Pt();

      //invariant mass of leptonic top: choose mass closest to top mass, or choose b closest in DR to W
      float mtop1 = (m_lepTLV + m_metTLV + m_b1TLV).M();
      float mtop2 = (m_lepTLV + m_metTLV + m_b2TLV).M();
      float mtopbest = mtop1;
      if( TMath::Abs(172.7 - mtop1) > TMath::Abs(172.7 - mtop2) ) mtopbest = mtop2;
      float drWb1 = (m_lepTLV + m_metTLV).DeltaR(m_b1TLV);
      float drWb2 = (m_lepTLV + m_metTLV).DeltaR(m_b2TLV);
      float mtopclosest = mtop1;
      if(drWb1 > drWb2) mtopclosest = mtop2;

      //quick check if vbf jets are taus
      int nTau = 0;
      for(unsigned int j = 0; j < jet_pt->size(); j++){
	if(m_process == "data") break;
	if(TMath::Abs(jet_eta->at(j) - m_j1TLV.Eta()) < 0.001 && TMath::Abs(jet_phi->at(j) - m_j1TLV.Phi() < 0.001) && TMath::Abs(jet_truthflav->at(j)) == 15) nTau++;
	if(TMath::Abs(jet_eta->at(j) - m_j2TLV.Eta()) < 0.001 && TMath::Abs(jet_phi->at(j) - m_j2TLV.Phi() < 0.001) && TMath::Abs(jet_truthflav->at(j)) == 15) nTau++;
      }
      
      //
      //Define the regions

      vector<bool>* regVec = new vector<bool>(nRegs, 0);

      //Preselection: you've already passed it.
      regVec->at(Presel) = true;

      //W CR
      regVec->at(WCR) = dyjj > 3.0 && (ptWjj < 250 && ptWjj > 150) && (ptWjj*-0.007 + 2.23 > dRBB_Rap) && mtopbest > 272.7 && (mBB < 90);

      //single top CR
      regVec->at(stopCR) =  (ptWjj > 250) && (dRBB_Rap > 1.5) && (dyjj > 3.0) && (mtopbest > 272.7);
      
      // //ttbar estimate: ABCD method. B: leptop mass, C: CJV, D: both
      // regVec->at(ttbarSR_A) = (mBB < 70 || mBB > 160) && mjj > 120 && (nVeto30 == 0) && (mtopbest < 120 || mtopbest > 220);
      // regVec->at(ttbarCR_B) = (mBB < 70 || mBB > 160) && mjj > 120 && (nVeto30 == 0) && (mtopbest > 120 && mtopbest < 220);
      // regVec->at(ttbarCR_C) = (mBB < 70 || mBB > 160) && mjj > 120 && (nVeto30 > 0) && (mtopbest < 120 || mtopbest > 220);
      // regVec->at(ttbarCR_D) = (mBB < 70 || mBB > 160) && mjj > 120 && (nVeto30 > 0) && (mtopbest > 120 && mtopbest < 220);
      
      //Loose signal region
      regVec->at(SRLoose) = (dyjj > 3) && (mtopbest > 220) && (ptWjj > 150) && (mBB > 70 && mBB < 160);

      //Signal region, version 1.0
      regVec->at(SRv1) = (dyjj > 4.4) && (mtopbest > 272.7) && (ptWjj > 250) && (mBB > 100 && mBB < 150) && (centrality_HW < 0.3) && (dRBB_Rap < 1.2);

      //Steps along the way
      regVec->at(SRcut2) = (dyjj > 4.4) && (ptWjj > 250);
      regVec->at(SRcut3) = (dyjj > 4.4) && (ptWjj > 250) && (mtopbest > 272.7);
      regVec->at(SRcut4) = (dyjj > 4.4) && (ptWjj > 250) && (mtopbest > 272.7) && (centrality_HW < 0.3);

      n0 += myWeight;
      if( dyjj > 4.4 ) {
	n1 += myWeight;
	if( ptWjj > 250 ){
	  n2 += myWeight;
	  if( mtopbest > 272.7 ){
	    n3 += myWeight;
	    if( centrality_HW < 0.3){
	      n4 += myWeight;
	      if( dRBB_Rap < 1.2){
		n5 += myWeight;
		if( (mBB > 100 && mBB < 150) ){
		  n6 += myWeight;
		}
	      }
	    }
	  }
	}
      }    

      //Fill histograms
      FillHists( regVec, h_VBFcands, VBFcands->size(), myWeight );
      FillHists( regVec, h_mjj, mjj, myWeight );
      FillHists( regVec, h_dyjj, dyjj, myWeight );
      FillHists( regVec, h_mjj_dyjj, mjj, dyjj, myWeight );

      FillHists( regVec, h_pTW, pTV, myWeight );
      FillHists( regVec, h_MET, MET, myWeight );
      FillHists( regVec, h_pTlep, ptL1, myWeight );
      FillHists( regVec, h_mbb, mBB, myWeight );
      FillHists( regVec, h_drbb, dRBB_Rap, myWeight );
      FillHists( regVec, h_pTbb, pTBB, myWeight );
      FillHists( regVec, h_pTW_drbb, pTV, dRBB_Rap, myWeight );
      FillHists( regVec, h_pTb1, pTB1, myWeight );
      FillHists( regVec, h_pTb2, pTB2, myWeight );
      FillHists( regVec, h_pTj1, m_j1TLV.Pt(), myWeight );
      FillHists( regVec, h_pTj2, m_j2TLV.Pt(), myWeight );
      FillHists( regVec, h_lepCharge, chargeL1, myWeight );

      FillHists( regVec, h_nVeto30, nVeto30, myWeight);
      FillHists( regVec, h_nVeto40, nVeto40, myWeight);
      FillHists( regVec, h_nVeto50, nVeto50, myWeight);
      FillHists( regVec, h_nGap30, nGap30, myWeight);
      FillHists( regVec, h_nGap40, nGap40, myWeight);
      FillHists( regVec, h_nGap50, nGap50, myWeight);

      FillHists( regVec, h_centrality_H, centrality_H, myWeight);
      FillHists( regVec, h_centrality_lep, centrality_lep, myWeight);
      FillHists( regVec, h_centrality_HW, centrality_HW, myWeight);

      FillHists( regVec, h_pTWjj, ptWjj, myWeight );
      FillHists( regVec, h_pTWjj_drbb, ptWjj, dRBB_Rap, myWeight );
      FillHists( regVec, h_pTWjj_pTbb, ptWjj, pTBB, myWeight );
      FillHists( regVec, h_pTbb_drbb, pTBB, dRBB_Rap, myWeight );
      FillHists( regVec, h_mLepTop_drbb, mtopbest, dRBB_Rap, myWeight );
      FillHists( regVec, h_drbbpTWjj, dRBB_Rap*ptWjj, myWeight );
      FillHists( regVec, h_drbbpTbb, dRBB_Rap*pTBB, myWeight );
      FillHists( regVec, h_dphi_jj_HW, VBFtlv.DeltaPhi((Wtlv+Htlv)), myWeight );
      FillHists( regVec, h_drminus250overpTbb, dRBB_Rap-(250./pTBB), myWeight );
      FillHists( regVec, h_drminus250overpTWjj, dRBB_Rap-(250./ptWjj), myWeight );

      FillHists( regVec, h_mLepTop_best, mtopbest, myWeight );
      FillHists( regVec, h_mLepTop_closest, mtopclosest, myWeight );

      FillHists( regVec, h_nTauVBF, nTau, myWeight );

   } //end event loop


   fnew->cd();

   if(m_process != "data"){
     cout<<"Presel "<<n0<<endl;
     cout<<"dyjj "<<n1<<endl;
     cout<<"pTWjj "<<n2<<endl;
     cout<<"m Lep Top "<<n3<<endl;
     cout<<"Centrality HW "<<n4<<endl;
     cout<<"drBB "<<n5<<endl;
     cout<<"mbb "<<n6<<endl;
   }
     
   //Write out hists
   for(int i = 0; i < nRegs; i++){
     h_VBFcands->at(i)->Write();
     h_mjj->at(i)->Write();
     h_dyjj->at(i)->Write();
     h_mjj_dyjj->at(i)->Write();
     h_pTW->at(i)->Write();
     h_pTWjj->at(i)->Write();
     h_MET->at(i)->Write();
     h_pTlep->at(i)->Write(); 
     h_mbb->at(i)->Write(); 
     h_drbb->at(i)->Write();
     h_pTbb->at(i)->Write();
     h_pTW_drbb->at(i)->Write();
     h_pTWjj_drbb->at(i)->Write();
     h_pTWjj_pTbb->at(i)->Write();
     h_pTbb_drbb->at(i)->Write();
     h_mLepTop_drbb->at(i)->Write();
     h_drbbpTWjj->at(i)->Write();
     h_drbbpTbb->at(i)->Write();
     h_drminus250overpTbb->at(i)->Write();
     h_drminus250overpTWjj->at(i)->Write();
     h_pTb1->at(i)->Write();
     h_pTb2->at(i)->Write();
     h_pTj1->at(i)->Write();
     h_pTj2->at(i)->Write();
     h_nVeto30->at(i)->Write();
     h_nVeto40->at(i)->Write();
     h_nVeto50->at(i)->Write();
     h_nGap30->at(i)->Write();
     h_nGap40->at(i)->Write();
     h_nGap50->at(i)->Write();
     h_centrality_H->at(i)->Write();
     h_centrality_lep->at(i)->Write();
     h_centrality_HW->at(i)->Write();
     h_lepCharge->at(i)->Write();
     h_dphi_jj_HW->at(i)->Write();
     h_mLepTop_best->at(i)->Write();
     h_mLepTop_closest->at(i)->Write();
     h_nTauVBF->at(i)->Write();
   }

   fnew->Close();     

}


vector<TH1F*>* ETAnalysis::GetHistVec(TString name, int nBins, float xlow, float xhigh){

  vector<TH1F*>* vec = new vector<TH1F*>();
  
  for(int i = 0; i < nRegs; i++){
    TH1F* hh = new TH1F(name+"_"+regNames[i], name+"_"+regNames[i], nBins, xlow, xhigh);
    vec->push_back(hh);
  }

  return vec;
}


vector<TH2F*>* ETAnalysis::GetHistVec(TString name, int nBinsX, float xlow, float xhigh, int nBinsY, float ylow, float yhigh){

  vector<TH2F*>* vec = new vector<TH2F*>();
  
  for(int i = 0; i < nRegs; i++){
    TH2F* hh = new TH2F(name+"_"+regNames[i], name+"_"+regNames[i], nBinsX, xlow, xhigh, nBinsY, ylow, yhigh);
    vec->push_back(hh);
  }

  return vec;
}



void ETAnalysis::FillHists(vector<bool>* rVec, vector<TH1F*>* hVec, float var, float weight){

  for(int r = 0; r < nRegs; r++){
    if(rVec->at(r)) hVec->at(r)->Fill(var, weight);
  }

  return;
}

void ETAnalysis::FillHists(vector<bool>* rVec, vector<TH2F*>* hVec, float varx, float vary, float weight){

  for(int r = 0; r < nRegs; r++){
    if(rVec->at(r)) hVec->at(r)->Fill(varx, vary, weight);
  }

  return;
}
