#include "TFile.h"
#include "TH1.h"
#include "THStack.h"

TString GetAxisLabel(TString var){

  if(var == "mLepTop") return "m_{top}^{lep} [GeV]";
  if(var == "centrality_HW") return "Centrality HW";
  if(var == "dyjj") return "#Deltay_{jj}";
  if(var == "pTWjj") return "p_{T}(W+jj)";
  if(var == "pTW") return "p_{T}^{W}";
  if(var == "mTW") return "m_{T}^{W}";
  if(var == "pTbb") return "p_{T}^{b#bar{b}}";
  if(var == "mbb") return "m_{b#bar{b}} [GeV]";
  if(var == "drbb") return "#DeltaR_{b#bar{b}}";
  if(var == "nVeto25") return "N_{jets}^{veto}";
  if(var == "mjj") return "m_{jj} [GeV]";
  if(var == "dphi_jj_HW") return "#Delta#phi(HW, jj)";
  if(var == "pTj1") return "p_{T}^{j1}";
  
  return var;
}

void PlotStack(TString var = "mjj", TString region = "Presel", TString option = ""){

  int rebin = 1;
  bool autoprint = false;
  bool kfactors = false;
  bool ScaleSig = (region == "Presel" || region.Contains("SR"));
  bool integrals = true;
  
  //Get hists etc
  TFile* f_wj = new TFile("histFiles/hists_W.root"); 
  TFile* f_tt = new TFile("histFiles/hists_ttbar.root"); 
  TFile* f_wt = new TFile("histFiles/hists_Wt.root"); 
  TFile* f_wh = new TFile("histFiles/hists_WH.root"); 
  TFile* f_wz = new TFile("histFiles/hists_WZ.root");
  TFile* f_ot = new TFile("histFiles/hists_other.root"); 
  TFile* f_da = new TFile("histFiles/hists_data.root"); 
  TFile* f_sp = new TFile("histFiles/hists_SigPos.root");
  TFile* f_sn = new TFile("histFiles/hists_SigNeg.root");

  if(option.Contains("W_2211")) f_wj = new TFile("histFiles/hists_W_Sh2211.root");
  if(option.Contains("W_MG")) f_wj = new TFile("histFiles/hists_W_MGPy8.root");
  if(option.Contains("W_Fx")) f_wj = new TFile("histFiles/hists_W_FxFx.root"); 
  if(option.Contains("ttbar_aMC")) f_tt = new TFile("histFiles/hists_ttbar_aMC.root");
  if(option.Contains("Wt_DS")) f_wt = new TFile("histFiles/hists_Wt_DS.root");
  
  TH1F* h_wj = (TH1F*)f_wj->Get("h_"+var+"_"+region); 
  TH1F* h_tt = (TH1F*)f_tt->Get("h_"+var+"_"+region); 
  TH1F* h_wt = (TH1F*)f_wt->Get("h_"+var+"_"+region); 
  TH1F* h_wh = (TH1F*)f_wh->Get("h_"+var+"_"+region); 
  TH1F* h_wz = (TH1F*)f_wz->Get("h_"+var+"_"+region);
  TH1F* h_ot = (TH1F*)f_ot->Get("h_"+var+"_"+region); 
  TH1F* h_da = (TH1F*)f_da->Get("h_"+var+"_"+region); 
  TH1F* h_sp = (TH1F*)f_sp->Get("h_"+var+"_"+region);
  TH1F* h_sn = (TH1F*)f_sn->Get("h_"+var+"_"+region);

  gStyle->SetHatchesLineWidth(2);
  //h_wt->SetFillStyle(3345);

  if(option.Contains("W_2211")) h_wj->SetFillStyle(3345);
  if(option.Contains("W_MG")) h_wj->SetFillStyle(3305);
  if(option.Contains("W_Fx")) h_wj->SetFillStyle(3395);
  if(option.Contains("ttbar_aMC")) h_tt->SetFillStyle(3345);
  if(option.Contains("Wt_DS")) h_wt->SetFillStyle(3345);
  
  
  //Apply k-factors
  if(kfactors){
    if(!region.Contains("Pos")){
      if(option.Contains("2211")){
	h_wj->Scale(0.8246);
	h_wt->Scale(0.3409); 
	h_tt->Scale(0.9011);
      }
      else if(option.Contains("W_MG")){
	h_wj->Scale(1.1132);
	h_wt->Scale(0.3450); 
	h_tt->Scale(0.7501);
      }
      else if(option.Contains("W_Fx")){
	h_wj->Scale(0.5105);
	h_wt->Scale(0.3259); 
	h_tt->Scale(0.6676);
      }
      else if(option.Contains("ttbar_aMC")){
	h_wj->Scale(1.0829);
	h_wt->Scale(0.3375); 
	h_tt->Scale(1.0557);
      }
      else{
	h_wj->Scale(1.1193);
	h_wt->Scale(0.3200); 
	h_tt->Scale(0.8788);
      }
    }
    else{
      if(option.Contains("2211")){
	h_wj->Scale(0.7878);
	h_wt->Scale(0.3410); 
	h_tt->Scale(1.0454);
      }
      else if(option.Contains("W_MG")){
	h_wj->Scale(0.9441);
	h_wt->Scale(0.3147); 
	h_tt->Scale(0.9474);
      }
      else if(option.Contains("W_Fx")){
	h_wj->Scale(0.4761);
	h_wt->Scale(0.2704); 
	h_tt->Scale(0.8972);
      }
      else if(option.Contains("ttbar_aMC")){
	h_wj->Scale(1.1436);
	h_wt->Scale(0.2900); 
	h_tt->Scale(1.1897);
      }
      else{
	h_wj->Scale(1.1749);
	h_wt->Scale(0.3024);
	h_tt->Scale(1.0650);
      }
    }
  }

  //Print integrals
  if(integrals){
    int nbins = h_tt->GetNbinsX()+1;
    cout<<"ttbar: "<<h_tt->Integral(0,nbins)<<endl;
    cout<<"W+jets: "<<h_wj->Integral(0,nbins)<<endl;
    cout<<"Wt: "<<h_wt->Integral(0,nbins)<<endl;
    cout<<"WZ: "<<h_wz->Integral(0,nbins)<<endl;
    cout<<"WH: "<<h_wh->Integral(0,nbins)<<endl;
    cout<<"other: "<<h_ot->Integral(0,nbins)<<endl;
    cout<<"Sum Bkg: "<<h_tt->Integral(0,nbins) + h_wt->Integral(0,nbins) + h_wj->Integral(0,nbins) + h_wz->Integral(0,nbins) + h_wh->Integral(0,nbins) + h_ot->Integral(0,nbins)<<endl;
    cout<<"sig pos: "<<h_sp->Integral(0,nbins)<<endl;
    cout<<"Sum SM: "<<h_tt->Integral(0,nbins) + h_wt->Integral(0,nbins) + h_wj->Integral(0,nbins) + h_wz->Integral(0,nbins) + h_wh->Integral(0,nbins) + h_ot->Integral(0,nbins) + h_sp->Integral(0,nbins)<<endl;
    cout<<"sig neg: "<<h_sn->Integral(0,nbins)<<endl;    
  }
  
  h_ot->Add(h_wh); //Include WH in other
  TH1F* c_sp = (TH1F*)h_sp->Clone(); //include positive signal in stack and as a line
  
  if(rebin != -1){
    h_wj->Rebin(rebin);
    h_tt->Rebin(rebin);
    h_wt->Rebin(rebin);
    h_wz->Rebin(rebin);
    h_ot->Rebin(rebin);
    h_da->Rebin(rebin);
    h_sp->Rebin(rebin);
    h_sn->Rebin(rebin);
    c_sp->Rebin(rebin);
  }
  
  h_wj->SetFillColor(kGreen+2);
  h_tt->SetFillColor(kViolet+6);
  h_wt->SetFillColor(kCyan+1);
  h_wz->SetFillColor(kOrange+1);
  h_ot->SetFillColor(28);
  h_sp->SetFillColor(kSpring-2);
  h_sn->SetLineColor(kPink-2);
  c_sp->SetLineColor(kSpring-2);
  
  THStack* hs = new THStack("hs","");
  hs->Add(h_ot);
  hs->Add(h_wz);
  hs->Add(h_wj); 
  hs->Add(h_wt);
  hs->Add(h_tt);
  hs->Add(h_sp);

  h_da->SetMaximum(1.3*h_da->GetMaximum());
  if(hs->GetMaximum() > 0.9*h_da->GetMaximum()) h_da->SetMaximum( 1.2*hs->GetMaximum());
  h_da->SetMinimum(0.0001);

  //MC errors
  TH1F* deno = (TH1F*)h_wj->Clone();
  deno->Add(h_tt);
  deno->Add(h_wt);
  deno->Add(h_wz);
  deno->Add(h_ot);
  deno->Add(h_sp);
  TGraphAsymmErrors* gerr = new TGraphAsymmErrors();
  double xx, yy;

  for(int i = 0; i < deno->GetNbinsX(); i++){
    gerr->SetPoint(i, deno->GetXaxis()->GetBinCenter(i+1), deno->GetBinContent(i+1));
    gerr->SetPointEYhigh(i, deno->GetBinError(i+1));
    gerr->SetPointEYlow(i, deno->GetBinError(i+1));
    gerr->SetPointEXlow(i, deno->GetBinCenter(i+1) - deno->GetBinLowEdge(i+1));
    gerr->SetPointEXhigh(i, deno->GetBinLowEdge(i+2) - deno->GetBinCenter(i+1));
  }

  gerr->SetFillStyle(3365);
  gerr->SetLineColor(kBlack);
  gerr->SetFillColor(kBlack);
  
  //Blind signal regions
  TH1F* h_bl = (TH1F*)h_da->Clone();
  h_bl->SetMarkerColor(kRed);
  h_bl->SetLineColor(kRed);
  for(int i = 0; i < h_da->GetNbinsX()+1; i++){
    //if( (deno->GetBinContent(i)-h_sp->GetBinContent(i)) < 20*h_sp->GetBinContent(i) || var == "bTruthFlav"){
    if(0){
      h_da->SetBinContent( i, -1 );
      h_da->SetBinError(i, 0.9);
      h_bl->SetBinContent(i, deno->GetBinContent(i));
      h_bl->SetBinError(i, TMath::Sqrt( deno->GetBinContent(i)));
    }
    else h_bl->SetBinContent(i, -1);
  }
  
  //scale signal
  if(ScaleSig){
    h_sn->Scale(deno->Integral()/h_sn->Integral());
    c_sp->Scale(deno->Integral()/c_sp->Integral());
  }
  
  //Drawing
  TCanvas* c1 = new TCanvas("c1","c1",50,50,600,700);
  TPad* pad1 = new TPad("pad1","pad1",0.0,0.35,1.0,1.0);
  TPad* pad2 = new TPad("pad2","pad2",0.0,0.0,1.0,0.35);
  
  pad1->SetBottomMargin(0);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.33);
  
  pad1->Draw();
  pad2->Draw();
  pad1->cd();

  h_da->GetYaxis()->SetTitle("Events / bin  ");

  if(var == "centrality_HW") h_da->GetXaxis()->SetRangeUser(0,1.2);
  if(var == "dyjj") h_da->GetXaxis()->SetRangeUser(2.4,9);
  if(var == "dyjj" && region.Contains("ttbarCR")) h_da->GetXaxis()->SetRangeUser(2.4,7);
  if(var == "dphi_jj_HW") h_da->GetXaxis()->SetRangeUser(1.5,3.15);
  if(var == "mLepTop" && !(region == "Presel")) h_da->GetXaxis()->SetRangeUser(200,700);
  if(var == "drbb" && (region.Contains("ttbarCR")||region.Contains("WCR"))) h_da->GetXaxis()->SetRangeUser(0,2.2);
  if(var == "drbb" && (region.Contains("ttbarCR")||region.Contains("WCR")||region.Contains("VR"))) h_da->GetXaxis()->SetRangeUser(0,2.2);
  if(var == "pTbb" && region.Contains("WCR")) h_da->GetXaxis()->SetRangeUser(0,300);
  if(var == "pTbb" && (region.Contains("ttbarCR")||region.Contains("WtCR"))) h_da->GetXaxis()->SetRangeUser(150,600);
  if(var == "pTW" && region.Contains("WtCR")) h_da->GetXaxis()->SetRangeUser(200,600);
  if(var == "mbb" && region.Contains("WCR")) h_da->GetXaxis()->SetRangeUser(0,100);
  if(var == "mbb" && region.Contains("ttbarCR")) h_da->GetXaxis()->SetRangeUser(120,400);
  if(var == "mbb" && region.Contains("WtCR")) h_da->GetXaxis()->SetRangeUser(120,500);
  if(var == "mbb" && region.Contains("VR")) h_da->GetXaxis()->SetRangeUser(0,500);
  if(var == "pTj1" && region.Contains("WtCR")) h_da->GetXaxis()->SetRangeUser(0,400);
  
  h_da->Draw("eP");
  hs->Draw("histsame");
  h_sn->Draw("histsame");
  c_sp->Draw("histsame");
  gerr->Draw("2same");
  h_da->Draw("ePsame");
  h_bl->Draw("ePsame");
  h_da->Draw("axissame");
  
  TLegend* leg = new TLegend(0.65,0.53,0.91,0.92);
  leg->AddEntry(h_da,"Data","P");
  leg->AddEntry(c_sp,"VBF WH, #lambda=+1","L");
  leg->AddEntry(h_sn,"VBF WH, #lambda=-1","L");
  leg->AddEntry(h_tt,"t#bar{t}","F");
  leg->AddEntry(h_wt,"Wt","F");
  leg->AddEntry(h_wj,"W+jets","F");
  leg->AddEntry(h_wz,"WZ","F");
  leg->AddEntry(h_ot,"other","F");
  
  leg->Draw("same");

  //chi-2 test
  TH1F* hch = (TH1F*) deno->Clone();
  for(int i = 1; i <= hch->GetNbinsX(); i++){ 
    if(h_da->GetBinContent(i) > 0) hch->SetBinError(i, 0.5*h_da->GetBinError(i) );
    else hch->SetBinError(i, 2 );
    if(h_da->GetBinContent(i) < 0){
      hch->SetBinContent(i, h_da->GetBinContent(i));
      h_da->SetBinError(i, 1);
    }
  }
  Double_t pval = h_da->Chi2Test(hch, "UW"); 
  
  TLatex specs;
  specs.SetNDC(); specs.SetTextColor(1);
  specs.SetTextFont(72);
  specs.DrawLatex(0.25,0.89,"ATLAS ");
  specs.SetTextFont(42);
  specs.DrawLatex(0.38,0.89,"Internal ");
  specs.DrawLatex(0.25,0.84,region);

  stringstream ss;
  ss<<setprecision(2)<<pval;
  TString tstr = ss.str();
  specs.SetTextSize(.042);
  //specs.DrawLatex(0.65,0.49,"mod #chi^{2} prob = "+tstr);
  
  //ratio plot
  pad2->cd();

  TH1F* rdat = (TH1F*)h_da->Clone();

  TGraphAsymmErrors* grat = new TGraphAsymmErrors();
  TGraphAsymmErrors* grat2 = new TGraphAsymmErrors();

  for(int i = 0; i < rdat->GetNbinsX(); i++){
    
    if(deno->GetBinContent(i+1) > 0){
      rdat->SetBinContent(i+1, h_da->GetBinContent(i+1)/deno->GetBinContent(i+1));
      rdat->SetBinError(i+1, h_da->GetBinError(i+1)/deno->GetBinContent(i+1));

      grat->SetPoint(i, rdat->GetXaxis()->GetBinCenter(i+1), 1);
      if(deno->GetBinError(i+1) < 2*deno->GetBinContent(i+1)){ 
	grat->SetPointEYhigh(i, deno->GetBinError(i+1)/deno->GetBinContent(i+1));
	grat->SetPointEYlow(i, deno->GetBinError(i+1)/deno->GetBinContent(i+1));
      }

    }
    else{
      rdat->SetBinContent(i+1,0);
      grat->SetPoint(i, rdat->GetXaxis()->GetBinCenter(i+1), 1);
    }    
  }

  grat->SetFillColor(kBlue-10);
  // rdat->SetMaximum(1.399);
  // rdat->SetMinimum(0.6);
  rdat->SetMaximum(1.799);
  rdat->SetMinimum(0.401);

  rdat->GetYaxis()->SetTitleOffset(.5);
  rdat->GetYaxis()->SetTitleSize(0.09);
  rdat->GetYaxis()->SetLabelSize(0.09);  
  rdat->GetXaxis()->SetLabelSize(0.10);  
  rdat->GetXaxis()->SetTitleSize(0.11);  
  rdat->GetXaxis()->SetTitleOffset(1.1);  

  rdat->GetYaxis()->SetTitle("data / pred    ");
  TString label = GetAxisLabel(var);
  rdat->GetXaxis()->SetTitle(label);

  TF1* line = new TF1("","1",rdat->GetXaxis()->GetXmin(),rdat->GetXaxis()->GetXmax());
  line->SetLineStyle(7);

  rdat->Draw("");
  grat->Draw("3");
  line->Draw("same");
  rdat->Draw("same");
  
  if(autoprint) c1->Print(var+"_"+region+option+".png");

  return;

}
