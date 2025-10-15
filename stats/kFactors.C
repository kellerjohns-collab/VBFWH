#include "kFactors.h"

vector<double> kFactors::GetValue(TString opt, int ind){
  
  vector<TString> regions = {"WCR_Neg","WtCR_Neg","ttbarCR_Neg", "SRNeg"};
  if(opt.Contains("posl")) regions = {"WCR_Pos","WtCR_Pos","ttbarCR_Pos", "SRPosLoose"};
  if(opt.Contains("post")) regions = {"WCR_Pos","WtCR_Pos","ttbarCR_Pos", "SRPosTight"};
  
  if(opt.Contains("WCRalt")) regions.at(0) = "WCR_Neg_alt";
  if(opt.Contains("WtCRalt")) regions.at(1) = "WtCR_Neg_alt";
  if(opt.Contains("ttbarCRalt")) regions.at(2) = "ttbarCR_Neg_alt";
  
  if(opt.Contains("VR")){
    if(opt.Contains("posl")) regions.at(3) = "VRPosLoose";
    else if(opt.Contains("post")) regions.at(3) = "VRPosTight";
    else regions.at(3) = "VRNeg";
  }
  
  TString samples[5] = {"da", "tt", "wt", "wj", "re"};
  
  vector<double> nom = GetFactors(opt);

  vector<double> varUP[5];
  vector<double> varDO[5];

  for(int j = 0; j < 5; j++){
    for(int i = 0; i < 4; i++){
      varUP[j].push_back(GetFactors(regions[i]+samples[j]+"UP"+opt).at(ind));
      varDO[j].push_back(GetFactors(regions[i]+samples[j]+"DO"+opt).at(ind));      
    }
  }

  double total = nom[ind];
  vector<double> total_UP;
  vector<double> total_DO;
  total_UP.assign(5, 0);
  total_DO.assign(5, 0);
  double sum_UP = 0;
  double sum_DO = 0;
  
  for(int j = 0; j < 5; j++){
    for(int i = 0; i < 4; i++){
      if(varUP[j].at(i) > total) total_UP.at(j) = TMath::Sqrt(total_UP.at(j)*total_UP.at(j) + (total-varUP[j].at(i))*(total-varUP[j].at(i)));
      else total_DO.at(j) = TMath::Sqrt(total_DO.at(j)*total_DO.at(j) + (total-varUP[j].at(i))*(total-varUP[j].at(i)));
      if(varDO[j].at(i) > total) total_UP.at(j) = TMath::Sqrt(total_UP.at(j)*total_UP.at(j) + (total-varDO[j].at(i))*(total-varDO[j].at(i)));
      else total_DO.at(j) = TMath::Sqrt(total_DO.at(j)*total_DO.at(j) + (total-varDO[j].at(i))*(total-varDO[j].at(i)));
    }
    sum_UP = TMath::Sqrt(total_UP.at(j)*total_UP.at(j)+sum_UP*sum_UP);
    sum_DO = TMath::Sqrt(total_DO.at(j)*total_DO.at(j)+sum_DO*sum_DO);	
  }

  if(ind == 0) cout<<"Total prediction in SR = ";
  if(ind == 1) cout<<"W+jets in SR = ";
  if(ind == 2) cout<<"Wt in SR = ";
  if(ind == 3) cout<<"ttbar in SR = ";
  if(ind == 4) cout<<"kW = ";
  if(ind == 5) cout<<"kWt = ";
  if(ind == 6) cout<<"ktt = ";
  if(ind == 7) cout<<"MC prediction in SR = ";
  if(ind == 8) cout<<"Rest in SR = ";
  printf("%4.3f +%4.3f -%4.3f (CR data), ",total, total_UP.at(0),total_DO.at(0));
  printf("+%4.3f -%4.3f (tt MC), ", total_UP.at(1), total_DO.at(1));
  printf("+%4.3f -%4.3f (Wt MC), ", total_UP.at(2), total_DO.at(2));
  printf("+%4.3f -%4.3f (W MC), ", total_UP.at(3), total_DO.at(3));
  printf("+%4.3f -%4.3f (rest MC) ", total_UP.at(4), total_DO.at(4));
  printf(" = %4.3f +%4.3f -%4.3f \n",total, sum_UP,sum_DO);

  vector<double> vec = {total, sum_UP, sum_DO};
  return vec;
  
}


vector<double> kFactors::GetFactors(TString opt){

  TString SysString = "NominalFull";
  if(opt.Contains("SYS_")){
    SysString = opt( opt.Index("SYS_")+4,opt.Length());
  }
  
  vector<TString> regions = {"WCR_Neg","WtCR_Neg","ttbarCR_Neg", "SRNeg"};
  if(opt.Contains("posl")) regions = {"WCR_Pos","WtCR_Pos","ttbarCR_Pos", "SRPosLoose"};
  if(opt.Contains("post")) regions = {"WCR_Pos","WtCR_Pos","ttbarCR_Pos", "SRPosTight"};

  if(opt.Contains("WCRalt")) regions.at(0) = "WCR_Neg_alt";
  if(opt.Contains("WtCRalt")) regions.at(1) = "WtCR_Neg_alt";
  if(opt.Contains("ttbarCRalt")) regions.at(2) = "ttbarCR_Neg_alt";

  if(opt.Contains("WCRalt") && opt.Contains("pos")) regions.at(0) = "WCR_Pos_alt";
  if(opt.Contains("WtCRalt") && opt.Contains("pos")) regions.at(1) = "WtCR_Pos_alt";
  if(opt.Contains("ttbarCRalt") && opt.Contains("pos")) regions.at(2) = "ttbarCR_Pos_alt";

  if(opt.Contains("VR")){
    if(opt.Contains("posl")) regions.at(3) = "VRPosLoose";
    else if(opt.Contains("post")) regions.at(3) = "VRPosTight";
    else regions.at(3) = "VRNeg";
  }
  
  float wj[4]; float ewj[4];
  float tt[4]; float ett[4];
  float wt[4]; float ewt[4];
  float da[4]; float eda[4];
  float re[4]; float ere[4];

  for(int i = 0; i < 4; i++){
    TH1F* h;
    h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_"+SysString);
    wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    h = (TH1F*)f_tt->Get("sum_"+regions[i]+"_"+SysString);
    tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    h = (TH1F*)f_wt->Get("sum_"+regions[i]+"_"+SysString);
    wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    h = (TH1F*)f_da->Get("sum_"+regions[i]+"_NominalFull");
    da[i] = h->Integral(); eda[i] = h->GetBinError(1);
    h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
    re[i] = h->Integral(); ere[i] = h->GetBinError(1);
    h = (TH1F*)f_wz->Get("sum_"+regions[i]+"_"+SysString);
    re[i] += h->Integral(); ere[i] = TMath::Sqrt(ere[i]*ere[i]+h->GetBinError(1)*h->GetBinError(1));
    h = (TH1F*)f_ot->Get("sum_"+regions[i]+"_"+SysString);
    re[i] += h->Integral(); ere[i] = TMath::Sqrt(ere[i]*ere[i]+h->GetBinError(1)*h->GetBinError(1));
    
    //Background systematic options
    if(opt.Contains("ttbar_aMC")){
      h = (TH1F*)f_tt_amc->Get("sum_"+regions[i]+"_"+SysString);
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_Herwig")){
      h = (TH1F*)f_tt_her->Get("sum_"+regions[i]+"_"+SysString);
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_RadHi")){
      h = (TH1F*)f_tt_rhi->Get("sum_"+regions[i]+"_"+SysString);
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_RadHiPrime")){
      h = (TH1F*)f_tt_rhp->Get("sum_"+regions[i]+"_RadHiPrime");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_hdamp")){
      h = (TH1F*)f_tt_hda->Get("sum_"+regions[i]+"_"+SysString);
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_RadLo")){
      h = (TH1F*)f_tt->Get("sum_"+regions[i]+"_RadLo");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_Var3cUp") || opt.Contains("ttbar_Var3cup")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_Var3cUp");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_Var3cDown") || opt.Contains("ttbar_Var3cdown")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_Var3cDown");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_MURup")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_MUR__1up");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_MURdown")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_MUR__1down");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_MUFup")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_MUF__1up");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_MUFdown")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_MUF__1down");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_FSRup")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_FSR__1up");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_FSRdown")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_ttbar_FSR__1down");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_PDF13165")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_PDF13165");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_PDF25200")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_PDF25200");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_PDF265000")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_PDF265000");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("ttbar_PDF266000")){
      h = (TH1F*)f_tt_v05->Get("sum_"+regions[i]+"_PDF266000");
      tt[i] = h->Integral(); ett[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_aMC")){
      h = (TH1F*)f_wt_amc->Get("sum_"+regions[i]+"_"+SysString);
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_Herwig")){
      h = (TH1F*)f_wt_her->Get("sum_"+regions[i]+"_"+SysString);
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_DS")){
      h = (TH1F*)f_wt_ds->Get("sum_"+regions[i]+"_"+SysString);
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_RadLo")){
      h = (TH1F*)f_wt->Get("sum_"+regions[i]+"_RadLo");
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_RadHi")){
      h = (TH1F*)f_wt->Get("sum_"+regions[i]+"_RadHi");
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_PDF13165")){
      h = (TH1F*)f_wt_v05->Get("sum_"+regions[i]+"_PDF13165");
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("Wt_PDF25200")){
      h = (TH1F*)f_wt_v05->Get("sum_"+regions[i]+"_PDF25200");
      wt[i] = h->Integral(); ewt[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MGPy8")){
      h = (TH1F*)f_wj_mg->Get("sum_"+regions[i]+"_"+SysString);
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_Sh2211")){
      h = (TH1F*)f_wj_11->Get("sum_"+regions[i]+"_"+SysString);
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_FxFx")){
      h = (TH1F*)f_wj_fx->Get("sum_"+regions[i]+"_"+SysString);
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MUFdown")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUF__1down");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MUFup")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUF__1up");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MURdown")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUR__1down");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MURup")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUR__1up");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MURMUFdown")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MURMUF__1down");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_MURMUFup")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MURMUF__1up");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_PDF13000")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUR1_MUF1_PDF13000");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_PDF25300")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUR1_MUF1_PDF25300");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }    
    if(opt.Contains("W_PDF269000")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUR1_MUF1_PDF269000");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("W_PDF270000")){
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+"_MUR1_MUF1_PDF270000");
      wj[i] = h->Integral(); ewj[i] = h->GetBinError(1);
    }
    if(opt.Contains("Z_MUFdown")){
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_MUF__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("Z_MUFup")){
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_MUF__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("Z_MURdown")){
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_MUR__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("Z_MURup")){
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_MUR__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("Z_MURMUFdown")){
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_MURMUF__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("Z_MURMUFup")){
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_MURMUF__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_zj->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("stopt_RadHi")){
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_RadHi");
      re[i] += h->Integral();
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("stopt_RadLo")){
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_RadLo");
      re[i] += h->Integral();
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("stopt_XSup")){
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += 0.042*h->Integral();
    }
    if(opt.Contains("stopt_XSdown")){
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= 0.036*h->Integral();
    }
    if(opt.Contains("stopt_aMC")){
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
      h = (TH1F*)f_tc_amc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += h->Integral();
    }
    if(opt.Contains("stopt_Herwig")){
      h = (TH1F*)f_tc->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
      h = (TH1F*)f_tc_her->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += h->Integral();
    }    
    if(opt.Contains("WH_MUFdown")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_MUF__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WH_MUFup")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_MUF__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WH_MURdown")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_MUR__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WH_MURup")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_MUR__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WH_MURMUFdown")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_MURMUF__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WH_MURMUFup")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_MURMUF__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WH_XSup")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += 0.02*h->Integral();
    }
    if(opt.Contains("WH_XSdown")){
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= 0.02*h->Integral();
    }
    if(opt.Contains("WZqcd_MUFdown")){
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_MUF__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZqcd_MUFup")){
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_MUF__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZqcd_MURdown")){
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_MUR__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZqcd_MURup")){
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_MUR__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZqcd_MURMUFdown")){
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_MURMUF__1down");
      re[i] += h->Integral();
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZqcd_MURMUFup")){
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_MURMUF__1up");
      re[i] += h->Integral();
      h = (TH1F*)f_wzq->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZewk_MUFdown")){
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_MUR1_MUF05");
      re[i] += h->Integral();
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZewk_MUFup")){
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_MUR1_MUF2");
      re[i] += h->Integral();
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZewk_MURdown")){
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_MUR05_MUF1");
      re[i] += h->Integral();
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZewk_MURup")){
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_MUR2_MUF1");
      re[i] += h->Integral();
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZewk_MURMUFdown")){
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_MUR05_MUF05");
      re[i] += h->Integral();
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("WZewk_MURMUFup")){
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_MUR2_MUF2");
      re[i] += h->Integral();
      h = (TH1F*)f_wze->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= h->Integral();
    }
    if(opt.Contains("ZH_XSup")){
      h = (TH1F*)f_zh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += 0.041*h->Integral();
    }
    if(opt.Contains("ZH_XSdown")){
      h = (TH1F*)f_zh->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= 0.035*h->Integral();
    }
    if(opt.Contains("ttH_XSup")){
      h = (TH1F*)f_th->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += 0.068*h->Integral();
    }
    if(opt.Contains("ttH_XSdown")){
      h = (TH1F*)f_th->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= 0.1*h->Integral();
    }
    if(opt.Contains("ttV_XSup")){
      h = (TH1F*)f_tv->Get("sum_"+regions[i]+"_"+SysString);
      re[i] += 0.097*h->Integral();
    }
    if(opt.Contains("ttV_XSdown")){
      h = (TH1F*)f_tv->Get("sum_"+regions[i]+"_"+SysString);
      re[i] -= 0.108*h->Integral();
    }
            
    //Signal options
    h = (TH1F*)f_sp->Get("sum_"+regions[i]+"_"+SysString);
    if(opt.Contains("SigSys_")){
      TSubString subStr = opt.SubString("SigSys_");
      TString SigStr = opt(subStr.Start()+6,14);
      h = (TH1F*)f_sp->Get("sum_"+regions[i]+SigStr);
    }
    if(opt.Contains("kW") && opt.Contains("kZ")){
      TString kapString = opt(opt.First("Z")-1,10);
      h = (TH1F*)f_sp->Get("sum_"+regions[i]+"_"+kapString);
    }
    if(opt.Contains("CKKW")){
      h = new TH1F("","",1,0,1);
      if(regions[i] == "WCR_Pos") h->SetBinContent(1,0.0675);
      if(regions[i] == "WtCR_Pos") h->SetBinContent(1,0.0118);
      if(regions[i] == "ttbarCR_Pos") h->SetBinContent(1,0.1186);
      if(regions[i] == "SRPosLoose") h->SetBinContent(1,3.678);
      if(regions[i] == "SRPosTight") h->SetBinContent(1,2.8224);
    }
    //cout<<"jk region "<<regions[i]<<" has integral "<<h->Integral()<<endl;
    if(!(opt.Contains("post") || opt.Contains("posl")) && !(opt.Contains("SplusB"))) re[i] += h->Integral(); ere[i] = TMath::Sqrt(ere[i]*ere[i]+h->GetBinError(1)*h->GetBinError(1));
    if((opt.Contains("post") || opt.Contains("posl")) && (opt.Contains("SplusB"))) re[i] += h->Integral(); ere[i] = TMath::Sqrt(ere[i]*ere[i]+h->GetBinError(1)*h->GetBinError(1));
    
    h = (TH1F*)f_sn->Get("sum_"+regions[i]+"_"+SysString);
    if(opt.Contains("SigSys_")){
      TSubString subStr = opt.SubString("SigSys_");
      TString SigStr = opt(subStr.Start()+6,12);
      h = (TH1F*)f_sn->Get("sum_"+regions[i]+SigStr);
    }
    if(opt.Contains("kW") && opt.Contains("kZ")){
      TString kapString = opt(opt.First("Z")-1,10);
      h = (TH1F*)f_sn->Get("sum_"+regions[i]+"_"+kapString);
    }
    if(!(opt.Contains("post") || opt.Contains("posl")) && (opt.Contains("SplusB"))) re[i] += h->Integral(); ere[i] = TMath::Sqrt(ere[i]*ere[i]+h->GetBinError(1)*h->GetBinError(1));
      
    
  
    if(opt.Contains("JER_")){
      
      TString JerMCString = "_JET_JERMC_"+opt( opt.Index("JER_")+4,opt.Length());
      TString JerPDString = "_JET_JERPD_"+opt( opt.Index("JER_")+4,opt.Length());
      
      //usual case: variation = Nominal + MC smear - PD smear
      //For NP 1 and 12, want PD up = nominal; mc down = nominal
      //For Data vs MC, the opposite
      if(opt.Contains("EffectiveNP_1_") || opt.Contains("EffectiveNP_12rest")){
	if(opt.Contains("__1up")) JerPDString = "_NominalFull";
	if(opt.Contains("__1down")) JerMCString = "_NominalFull";
      }
      if(opt.Contains("DataVsMC_MC16")){
	if(opt.Contains("__1up")) JerMCString = "_NominalFull";
	if(opt.Contains("__1down")) JerPDString = "_NominalFull";
      }
      
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+JerMCString);
      wj[i] += h->Integral();
      h = (TH1F*)f_wj->Get("sum_"+regions[i]+JerPDString);
      wj[i] -= h->Integral();
      h = (TH1F*)f_tt->Get("sum_"+regions[i]+JerMCString);
      tt[i] += h->Integral();
      h = (TH1F*)f_tt->Get("sum_"+regions[i]+JerPDString);
      tt[i] -= h->Integral();
      h = (TH1F*)f_wt->Get("sum_"+regions[i]+JerMCString);
      wt[i] += h->Integral();
      h = (TH1F*)f_wt->Get("sum_"+regions[i]+JerPDString);
      wt[i] -= h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+JerMCString);
      re[i] += h->Integral();
      h = (TH1F*)f_wh->Get("sum_"+regions[i]+JerPDString);
      re[i] -= h->Integral();
      h = (TH1F*)f_wz->Get("sum_"+regions[i]+JerMCString);
      re[i] += h->Integral();
      h = (TH1F*)f_wz->Get("sum_"+regions[i]+JerPDString);
      re[i] -= h->Integral();
      h = (TH1F*)f_ot->Get("sum_"+regions[i]+JerMCString);
      re[i] += h->Integral();
      h = (TH1F*)f_ot->Get("sum_"+regions[i]+JerPDString);
      re[i] -= h->Integral();
      h = (TH1F*)f_sp->Get("sum_"+regions[i]+JerMCString);
      if(!(opt.Contains("post") || opt.Contains("posl")) && !(opt.Contains("SplusB"))) re[i] += h->Integral(); 
      if((opt.Contains("post") || opt.Contains("posl")) && (opt.Contains("SplusB"))) re[i] += h->Integral();
      h = (TH1F*)f_sp->Get("sum_"+regions[i]+JerPDString);
      if(!(opt.Contains("post") || opt.Contains("posl")) && !(opt.Contains("SplusB"))) re[i] -= h->Integral(); 
      if((opt.Contains("post") || opt.Contains("posl")) && (opt.Contains("SplusB"))) re[i] -= h->Integral();
      h = (TH1F*)f_sn->Get("sum_"+regions[i]+JerMCString);
      if(!(opt.Contains("post") || opt.Contains("posl")) && (opt.Contains("SplusB"))) re[i] += h->Integral();
      h = (TH1F*)f_sn->Get("sum_"+regions[i]+JerPDString);
      if(!(opt.Contains("post") || opt.Contains("posl")) && (opt.Contains("SplusB"))) re[i] -= h->Integral();
      
    }
  
    
    if(opt.Contains(regions[i])){
      if(opt.Contains("daUP")) da[i] += eda[i];
      if(opt.Contains("daDO")) da[i] -= eda[i];
      if(opt.Contains("ttUP")) tt[i] += ett[i];
      if(opt.Contains("ttDO")) tt[i] -= ett[i];
      if(opt.Contains("wtUP")) wt[i] += ewt[i];
      if(opt.Contains("wtDO")) wt[i] -= ewt[i];
      if(opt.Contains("wjUP")) wj[i] += ewj[i];
      if(opt.Contains("wjDO")) wj[i] -= ewj[i];
      if(opt.Contains("reUP")) re[i] += ere[i];
      if(opt.Contains("reDO")) re[i] -= ere[i];
    }

    if(opt.Contains("Lumi__")){
      float factor = 1.0083;
      if(opt.Contains("__1down")) factor = 0.9917;
      tt[i] = tt[i]*factor;
      wt[i] = wt[i]*factor;
      wj[i] = wj[i]*factor;
      re[i] = re[i]*factor;
    }

    if(opt.Contains("verb") ){
      cout<<"In "<<regions[i]<<endl;
      if(!(regions[i].Contains("SR"))) printf(" data - rest: %4.2f - %4.2f = %4.2f \n", da[i], re[i], da[i] - (re[i]));
      printf(" W+jets: %4.2f \n", wj[i]);
      printf(" Wt:     %4.2f \n", wt[i]);
      printf(" ttbar:  %4.2f \n", tt[i]);
      if(regions[i].Contains("SR")) printf(" rest:   %4.2f \n", re[i]);
    }
    
  }
  
  TMatrixD dmat(3,1);
  dmat(0,0) = da[0] - re[0];
  dmat(1,0) = da[1] - re[1];
  dmat(2,0) = da[2] - re[2];

  TMatrixD nmat(3,3);
  nmat(0,0) = wj[0];   nmat(1,0) = wj[1];   nmat(2,0) = wj[2];
  nmat(0,1) = wt[0];   nmat(1,1) = wt[1];   nmat(2,1) = wt[2];
  nmat(0,2) = tt[0];   nmat(1,2) = tt[1];   nmat(2,2) = tt[2];

  nmat.Invert();
  
  TMatrixD kmat(3,1);
  kmat = nmat*dmat;
  if(opt.Contains("verb")){
    cout<<endl;
    printf("kW =  %4.3f \n", kmat(0,0));
    printf("kWt = %4.3f \n", kmat(1,0));
    printf("ktt = %4.3f \n\n", kmat(2,0));
  }

  double total = wj[3]*kmat(0,0) + wt[3]*kmat(1,0) + tt[3]*kmat(2,0) + re[3];
  double totalRaw = wj[3] + wt[3] + tt[3] + re[3];
  
  if(opt.Contains("verb")) printf("SR: \n%4.2f W + %4.2f Wt + %4.2f tt + %4.2f rest = %4.2f. \n", wj[3]*kmat(0,0), wt[3]*kmat(1,0), tt[3]*kmat(2,0), re[3], total);
  
  vector<double> vec = {total, wj[3]*kmat(0,0), wt[3]*kmat(1,0), tt[3]*kmat(2,0), kmat(0,0), kmat(1,0), kmat(2,0), totalRaw, re[3]};
  return vec;
  
}


vector<float> kFactors::GetDetectorSysts(TString opt, bool print){
  
  float mc_btagUP = 0.0; float mc_btagDOWN = 0.0;
  float mc_ctagUP = 0.0; float mc_ctagDOWN = 0.0;
  float mc_ltagUP = 0.0; float mc_ltagDOWN = 0.0;
  float mc_metUP = 0.0; float mc_metDOWN = 0.0;
  float mc_jesUP = 0.0;  float mc_jesDOWN = 0.0;
  float mc_jerUP = 0.0;  float mc_jerDOWN = 0.0;
  float mc_muonUP = 0.0;  float mc_muonDOWN = 0.0;
  float mc_elUP = 0.0;  float mc_elDOWN = 0.0;
  float mc_tauUP = 0.0;  float mc_tauDOWN = 0.0;
  float mc_jvtUP = 0.0;  float mc_jvtDOWN = 0.0;
  float mc_totUP = 0.0;  float mc_totDOWN = 0.0;
  
  float dd_btagUP = 0.0; float dd_btagDOWN = 0.0;
  float dd_ctagUP = 0.0; float dd_ctagDOWN = 0.0;
  float dd_ltagUP = 0.0; float dd_ltagDOWN = 0.0;
  float dd_metUP = 0.0; float dd_metDOWN = 0.0;
  float dd_jesUP = 0.0;  float dd_jesDOWN = 0.0;
  float dd_jerUP = 0.0;  float dd_jerDOWN = 0.0;
  float dd_muonUP = 0.0;  float dd_muonDOWN = 0.0;
  float dd_tauUP = 0.0;  float dd_tauDOWN = 0.0;
  float dd_elUP = 0.0;  float dd_elDOWN = 0.0;
  float dd_jvtUP = 0.0;  float dd_jvtDOWN = 0.0;
  float dd_totUP = 0.0;  float dd_totDOWN = 0.0;

  vector<double> vdnom = GetFactors(opt);
  float dd_nom = vdnom.at(0); float mc_nom = vdnom.at(7);

  if(print) printf(" %8s     %10s %12s \n", "", "DD", "MC");
  if(print) printf(" %11s     %9.3f     %9.3f \n", "nominal", vdnom.at(0), vdnom.at(7));

  for(unsigned int i = 0; i < BVars.size(); i++){
    vector<double> vd = GetFactors(opt+BVars.at(i));
    dd_btagUP = TMath::Sqrt( dd_btagUP*dd_btagUP + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
    dd_btagDOWN = TMath::Sqrt( dd_btagDOWN*dd_btagDOWN + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
    mc_btagUP = TMath::Sqrt( mc_btagUP*mc_btagUP + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
    mc_btagDOWN = TMath::Sqrt( mc_btagDOWN*mc_btagDOWN + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
        
    if(print) printf(" %11s     %+9.3f     %+9.3f \n", ((string)BVars.at(i)).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  }
  if(print) printf(" %11s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Total b-tag: ",dd_btagUP, dd_btagDOWN, mc_btagUP, mc_btagDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_btagUP*dd_btagUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_btagDOWN*dd_btagDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_btagUP*mc_btagUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_btagDOWN*mc_btagDOWN);
  
  for(unsigned int i = 0; i < CVars.size(); i++){
    vector<double> vd = GetFactors(opt+CVars.at(i));
    dd_ctagUP = TMath::Sqrt( dd_ctagUP*dd_ctagUP + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
    dd_ctagDOWN = TMath::Sqrt( dd_ctagDOWN*dd_ctagDOWN + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
    mc_ctagUP = TMath::Sqrt( mc_ctagUP*mc_ctagUP + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
    mc_ctagDOWN = TMath::Sqrt( mc_ctagDOWN*mc_ctagDOWN + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
        
    if(print) printf(" %11s     %+9.3f     %+9.3f \n", ((string)CVars.at(i)).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  }
  if(print) printf(" %11s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Total c-tag: ",dd_ctagUP, dd_ctagDOWN, mc_ctagUP, mc_ctagDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_ctagUP*dd_ctagUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_ctagDOWN*dd_ctagDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_ctagUP*mc_ctagUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_ctagDOWN*mc_ctagDOWN);
  
  for(unsigned int i = 0; i < LVars.size(); i++){
    vector<double> vd = GetFactors(opt+LVars.at(i));
    dd_ltagUP = TMath::Sqrt( dd_ltagUP*dd_ltagUP + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
    dd_ltagDOWN = TMath::Sqrt( dd_ltagDOWN*dd_ltagDOWN + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
    mc_ltagUP = TMath::Sqrt( mc_ltagUP*mc_ltagUP + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
    mc_ltagDOWN = TMath::Sqrt( mc_ltagDOWN*mc_ltagDOWN + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
        
    if(print) printf(" %11s     %+9.3f     %+9.3f \n", ((string)LVars.at(i)).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  }
  if(print) printf(" %11s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total light-tag: ",dd_ltagUP, dd_ltagDOWN, mc_ltagUP, mc_ltagDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_ltagUP*dd_ltagUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_ltagDOWN*dd_ltagDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_ltagUP*mc_ltagUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_ltagDOWN*mc_ltagDOWN);

  
  //JES. Must correctly treat same-sided variations.
  for(unsigned int i = 0; i < JESVars.size(); i++){
    vector<double> vdup = GetFactors(opt+JESVars.at(i)+"__1up");
    vector<double> vddown = GetFactors(opt+JESVars.at(i)+"__1down");

    if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
      float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
      dd_jesUP = TMath::Sqrt( dd_jesUP*dd_jesUP + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
      float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
      dd_jesDOWN = TMath::Sqrt( dd_jesDOWN*dd_jesDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
      dd_jesUP = TMath::Sqrt( dd_jesUP*dd_jesUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_jesDOWN = TMath::Sqrt( dd_jesDOWN*dd_jesDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
      dd_jesDOWN = TMath::Sqrt( dd_jesDOWN*dd_jesDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_jesUP = TMath::Sqrt( dd_jesUP*dd_jesUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    
    if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
      float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
      mc_jesUP = TMath::Sqrt( mc_jesUP*mc_jesUP + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
      float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
      mc_jesDOWN = TMath::Sqrt( mc_jesDOWN*mc_jesDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
      mc_jesUP = TMath::Sqrt( mc_jesUP*mc_jesUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_jesDOWN = TMath::Sqrt( mc_jesDOWN*mc_jesDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
      mc_jesDOWN = TMath::Sqrt( mc_jesDOWN*mc_jesDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_jesUP = TMath::Sqrt( mc_jesUP*mc_jesUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
        
    if(print) printf(" %44s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)JESVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  }
  if(print) printf(" %44s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total JES: ",dd_jesUP, dd_jesDOWN, mc_jesUP, mc_jesDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_jesUP*dd_jesUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_jesDOWN*dd_jesDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_jesUP*mc_jesUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_jesDOWN*mc_jesDOWN);


  //JER. 
  for(unsigned int i = 0; i < JERVars.size(); i++){
    vector<double> vdup = GetFactors(opt+JERVars.at(i)+"__1up");
    vector<double> vddown = GetFactors(opt+JERVars.at(i)+"__1down");

    if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
      float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
      dd_jerUP = TMath::Sqrt( dd_jerUP*dd_jerUP + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
      float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
      dd_jerDOWN = TMath::Sqrt( dd_jerDOWN*dd_jerDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
      dd_jerUP = TMath::Sqrt( dd_jerUP*dd_jerUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_jerDOWN = TMath::Sqrt( dd_jerDOWN*dd_jerDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
      dd_jerDOWN = TMath::Sqrt( dd_jerDOWN*dd_jerDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_jerUP = TMath::Sqrt( dd_jerUP*dd_jerUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    
    if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
      float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
      mc_jerUP = TMath::Sqrt( mc_jerUP*mc_jerUP + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
      float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
      mc_jerDOWN = TMath::Sqrt( mc_jerDOWN*mc_jerDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
      mc_jerUP = TMath::Sqrt( mc_jerUP*mc_jerUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_jerDOWN = TMath::Sqrt( mc_jerDOWN*mc_jerDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
      mc_jerDOWN = TMath::Sqrt( mc_jerDOWN*mc_jerDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_jerUP = TMath::Sqrt( mc_jerUP*mc_jerUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    
    if(print) printf(" %30s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)JERVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  }
  if(print) printf(" %30s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total JER: ",dd_jerUP, dd_jerDOWN, mc_jerUP, mc_jerDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_jerUP*dd_jerUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_jerDOWN*dd_jerDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_jerUP*mc_jerUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_jerDOWN*mc_jerDOWN);
  
  //MET. Contains some 1-sided.
  for(unsigned int i = 0; i < METVars.size(); i++){
    if(!METVars.at(i).Contains("Reso")){
      vector<double> vdup = GetFactors(opt+METVars.at(i)+"__1up");
      vector<double> vddown = GetFactors(opt+METVars.at(i)+"__1down");
      
      if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
	float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
	dd_metUP = TMath::Sqrt( dd_metUP*dd_metUP + (maxVar-dd_nom)*(maxVar-dd_nom));
      }
      else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
	float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
	dd_metDOWN = TMath::Sqrt( dd_metDOWN*dd_metDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
      }
      else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
	dd_metUP = TMath::Sqrt( dd_metUP*dd_metUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
	dd_metDOWN = TMath::Sqrt( dd_metDOWN*dd_metDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
      }
      else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
	dd_metDOWN = TMath::Sqrt( dd_metDOWN*dd_metDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
	dd_metUP = TMath::Sqrt( dd_metUP*dd_metUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
      }
      
      if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
	float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
	mc_metUP = TMath::Sqrt( mc_metUP*mc_metUP + (maxVar-mc_nom)*(maxVar-mc_nom));
      }
      else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
	float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
	mc_metDOWN = TMath::Sqrt( mc_metDOWN*mc_metDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
      }
      else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
	mc_metUP = TMath::Sqrt( mc_metUP*mc_metUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
	mc_metDOWN = TMath::Sqrt( mc_metDOWN*mc_metDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
      }
      else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
	mc_metDOWN = TMath::Sqrt( mc_metDOWN*mc_metDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
	mc_metUP = TMath::Sqrt( mc_metUP*mc_metUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
      }
      if(print) printf(" %30s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)METVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
    }
    
    else{
      vector<double> vdup = GetFactors(opt+METVars.at(i)+"__1up");
      dd_metUP = TMath::Sqrt( dd_metUP*dd_metUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_metDOWN = TMath::Sqrt( dd_metDOWN*dd_metDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      mc_metUP = TMath::Sqrt( mc_metUP*mc_metUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_metDOWN = TMath::Sqrt( mc_metDOWN*mc_metDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      if(print) printf(" %30s     %+9.3f     %+9.3f \n", ((string)METVars.at(i)).c_str(), vdup.at(0)-dd_nom, vdup.at(7)-mc_nom);
    }
    
  }
  if(print) printf(" %30s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total MET: ",dd_metUP, dd_metDOWN, mc_metUP, mc_metDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_metUP*dd_metUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_metDOWN*dd_metDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_metUP*mc_metUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_metDOWN*mc_metDOWN);

  //Muon 
  for(unsigned int i = 0; i < MuonVars.size(); i++){
    vector<double> vdup = GetFactors(opt+MuonVars.at(i)+"__1up");
    vector<double> vddown = GetFactors(opt+MuonVars.at(i)+"__1down");

    if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
      float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
      dd_muonUP = TMath::Sqrt( dd_muonUP*dd_muonUP + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
      float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
      dd_muonDOWN = TMath::Sqrt( dd_muonDOWN*dd_muonDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
      dd_muonUP = TMath::Sqrt( dd_muonUP*dd_muonUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_muonDOWN = TMath::Sqrt( dd_muonDOWN*dd_muonDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
      dd_muonDOWN = TMath::Sqrt( dd_muonDOWN*dd_muonDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_muonUP = TMath::Sqrt( dd_muonUP*dd_muonUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    
    if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
      float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
      mc_muonUP = TMath::Sqrt( mc_muonUP*mc_muonUP + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
      float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
      mc_muonDOWN = TMath::Sqrt( mc_muonDOWN*mc_muonDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
      mc_muonUP = TMath::Sqrt( mc_muonUP*mc_muonUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_muonDOWN = TMath::Sqrt( mc_muonDOWN*mc_muonDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
      mc_muonDOWN = TMath::Sqrt( mc_muonDOWN*mc_muonDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_muonUP = TMath::Sqrt( mc_muonUP*mc_muonUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    
    if(print) printf(" %33s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)MuonVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  }
  if(print) printf(" %33s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total Muon: ",dd_muonUP, dd_muonDOWN, mc_muonUP, mc_muonDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_muonUP*dd_muonUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_muonDOWN*dd_muonDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_muonUP*mc_muonUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_muonDOWN*mc_muonDOWN);
  
  //El 
  for(unsigned int i = 0; i < ElVars.size(); i++){
    vector<double> vdup = GetFactors(opt+ElVars.at(i)+"__1up");
    vector<double> vddown = GetFactors(opt+ElVars.at(i)+"__1down");

    if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
      float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
      dd_elUP = TMath::Sqrt( dd_elUP*dd_elUP + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
      float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
      dd_elDOWN = TMath::Sqrt( dd_elDOWN*dd_elDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
      dd_elUP = TMath::Sqrt( dd_elUP*dd_elUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_elDOWN = TMath::Sqrt( dd_elDOWN*dd_elDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
      dd_elDOWN = TMath::Sqrt( dd_elDOWN*dd_elDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_elUP = TMath::Sqrt( dd_elUP*dd_elUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    
    if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
      float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
      mc_elUP = TMath::Sqrt( mc_elUP*mc_elUP + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
      float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
      mc_elDOWN = TMath::Sqrt( mc_elDOWN*mc_elDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
      mc_elUP = TMath::Sqrt( mc_elUP*mc_elUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_elDOWN = TMath::Sqrt( mc_elDOWN*mc_elDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
      mc_elDOWN = TMath::Sqrt( mc_elDOWN*mc_elDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_elUP = TMath::Sqrt( mc_elUP*mc_elUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    
    if(print) printf(" %45s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)ElVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  }
  if(print) printf(" %45s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total El: ",dd_elUP, dd_elDOWN, mc_elUP, mc_elDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_elUP*dd_elUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_elDOWN*dd_elDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_elUP*mc_elUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_elDOWN*mc_elDOWN);

  //Tau 
  for(unsigned int i = 0; i < TauVars.size(); i++){
    vector<double> vdup = GetFactors(opt+TauVars.at(i)+"__1up");
    vector<double> vddown = GetFactors(opt+TauVars.at(i)+"__1down");

    if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
      float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
      dd_tauUP = TMath::Sqrt( dd_tauUP*dd_tauUP + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
      float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
      dd_tauDOWN = TMath::Sqrt( dd_tauDOWN*dd_tauDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
      dd_tauUP = TMath::Sqrt( dd_tauUP*dd_tauUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_tauDOWN = TMath::Sqrt( dd_tauDOWN*dd_tauDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
      dd_tauDOWN = TMath::Sqrt( dd_tauDOWN*dd_tauDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_tauUP = TMath::Sqrt( dd_tauUP*dd_tauUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    
    if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
      float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
      mc_tauUP = TMath::Sqrt( mc_tauUP*mc_tauUP + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
      float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
      mc_tauDOWN = TMath::Sqrt( mc_tauDOWN*mc_tauDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
      mc_tauUP = TMath::Sqrt( mc_tauUP*mc_tauUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_tauDOWN = TMath::Sqrt( mc_tauDOWN*mc_tauDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
      mc_tauDOWN = TMath::Sqrt( mc_tauDOWN*mc_tauDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_tauUP = TMath::Sqrt( mc_tauUP*mc_tauUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    
    if(print) printf(" %44s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)TauVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  }
  if(print) printf(" %44s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total Tau: ",dd_tauUP, dd_tauDOWN, mc_tauUP, mc_tauDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_tauUP*dd_tauUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_tauDOWN*dd_tauDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_tauUP*mc_tauUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_tauDOWN*mc_tauDOWN);


  //Jvt
  for(unsigned int i = 0; i < JvtVars.size(); i++){
    vector<double> vdup = GetFactors(opt+JvtVars.at(i)+"__1up");
    vector<double> vddown = GetFactors(opt+JvtVars.at(i)+"__1down");

    if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
      float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
      dd_jvtUP = TMath::Sqrt( dd_jvtUP*dd_jvtUP + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
      float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
      dd_jvtDOWN = TMath::Sqrt( dd_jvtDOWN*dd_jvtDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
    }
    else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
      dd_jvtUP = TMath::Sqrt( dd_jvtUP*dd_jvtUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_jvtDOWN = TMath::Sqrt( dd_jvtDOWN*dd_jvtDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
      dd_jvtDOWN = TMath::Sqrt( dd_jvtDOWN*dd_jvtDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
      dd_jvtUP = TMath::Sqrt( dd_jvtUP*dd_jvtUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
    }
    
    if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
      float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
      mc_jvtUP = TMath::Sqrt( mc_jvtUP*mc_jvtUP + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
      float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
      mc_jvtDOWN = TMath::Sqrt( mc_jvtDOWN*mc_jvtDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
    }
    else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
      mc_jvtUP = TMath::Sqrt( mc_jvtUP*mc_jvtUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_jvtDOWN = TMath::Sqrt( mc_jvtDOWN*mc_jvtDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
      mc_jvtDOWN = TMath::Sqrt( mc_jvtDOWN*mc_jvtDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
      mc_jvtUP = TMath::Sqrt( mc_jvtUP*mc_jvtUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
    }
    
    if(print) printf(" %30s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", ((string)JvtVars.at(i)).c_str(),vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  }
  if(print) printf(" %30s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Total JVT: ",dd_jvtUP, dd_jvtDOWN, mc_jvtUP, mc_jvtDOWN);
  dd_totUP = TMath::Sqrt(dd_totUP*dd_totUP + dd_jvtUP*dd_jvtUP);
  dd_totDOWN = TMath::Sqrt(dd_totDOWN*dd_totDOWN + dd_jvtDOWN*dd_jvtDOWN);
  mc_totUP = TMath::Sqrt(mc_totUP*mc_totUP + mc_jvtUP*mc_jvtUP);
  mc_totDOWN = TMath::Sqrt(mc_totDOWN*mc_totDOWN + mc_jvtDOWN*mc_jvtDOWN);

  if(print) printf(" %25s     %6s %14s \n", "", "DD", "MC");
  if(print) printf(" %25s     %8.3f     %10.3f \n", "nominal: ", vdnom.at(0), vdnom.at(7));
  
  //Lumi
  vector<double> vdup = GetFactors(opt+"Lumi__1up");
  vector<double> vddown = GetFactors(opt+"Lumi__1down");
  if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
    float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
    dd_totUP = TMath::Sqrt( dd_totUP*dd_totUP + (maxVar-dd_nom)*(maxVar-dd_nom));
  }
  else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
    float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
    dd_totDOWN = TMath::Sqrt( dd_totDOWN*dd_totDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
  }
  else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
    dd_totUP = TMath::Sqrt( dd_totUP*dd_totUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
    dd_totDOWN = TMath::Sqrt( dd_totDOWN*dd_totDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
  }
  else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
    dd_totDOWN = TMath::Sqrt( dd_totDOWN*dd_totDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
    dd_totUP = TMath::Sqrt( dd_totUP*dd_totUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
  }  
  if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
    float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
    mc_totUP = TMath::Sqrt( mc_totUP*mc_totUP + (maxVar-mc_nom)*(maxVar-mc_nom));
  }
  else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
    float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
    mc_totDOWN = TMath::Sqrt( mc_totDOWN*mc_totDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
  }
  else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
    mc_totUP = TMath::Sqrt( mc_totUP*mc_totUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
    mc_totDOWN = TMath::Sqrt( mc_totDOWN*mc_totDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
  }
  else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
    mc_totDOWN = TMath::Sqrt( mc_totDOWN*mc_totDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
    mc_totUP = TMath::Sqrt( mc_totUP*mc_totUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
  }  
  if(print) printf(" %25s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", "Luminosity: ",vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  float dd_lumiUP = vdup.at(0)-dd_nom;
  float dd_lumiDOWN = vddown.at(0)-dd_nom;
  
  //PRW
  vdup = GetFactors(opt+"SYS_PRW_DATASF__1up");
  vddown = GetFactors(opt+"SYS_PRW_DATASF__1down");
  if(vdup.at(0) > dd_nom && vddown.at(0) > dd_nom){
    float maxVar = TMath::Max(vdup.at(0), vddown.at(0));
    dd_totUP = TMath::Sqrt( dd_totUP*dd_totUP + (maxVar-dd_nom)*(maxVar-dd_nom));
  }
  else if(vdup.at(0) < dd_nom && vddown.at(0) < dd_nom){
    float maxVar = TMath::Min(vdup.at(0), vddown.at(0));
    dd_totDOWN = TMath::Sqrt( dd_totDOWN*dd_totDOWN + (maxVar-dd_nom)*(maxVar-dd_nom));
  }
  else if(vdup.at(0) > dd_nom && vddown.at(0) < dd_nom){
    dd_totUP = TMath::Sqrt( dd_totUP*dd_totUP + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
    dd_totDOWN = TMath::Sqrt( dd_totDOWN*dd_totDOWN + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
  }
  else if(vdup.at(0) < dd_nom && vddown.at(0) > dd_nom){
    dd_totDOWN = TMath::Sqrt( dd_totDOWN*dd_totDOWN + (vdup.at(0)-dd_nom)*(vdup.at(0)-dd_nom));
    dd_totUP = TMath::Sqrt( dd_totUP*dd_totUP + (vddown.at(0)-dd_nom)*(vddown.at(0)-dd_nom));
  }  
  if(vdup.at(7) > mc_nom && vddown.at(7) > mc_nom){
    float maxVar = TMath::Max(vdup.at(7), vddown.at(7));
    mc_totUP = TMath::Sqrt( mc_totUP*mc_totUP + (maxVar-mc_nom)*(maxVar-mc_nom));
  }
  else if(vdup.at(7) < mc_nom && vddown.at(7) < mc_nom){
    float maxVar = TMath::Min(vdup.at(7), vddown.at(7));
    mc_totDOWN = TMath::Sqrt( mc_totDOWN*mc_totDOWN + (maxVar-mc_nom)*(maxVar-mc_nom));
  }
  else if(vdup.at(7) > mc_nom && vddown.at(7) < mc_nom){
    mc_totUP = TMath::Sqrt( mc_totUP*mc_totUP + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
    mc_totDOWN = TMath::Sqrt( mc_totDOWN*mc_totDOWN + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
  }
  else if(vdup.at(7) < mc_nom && vddown.at(7) > mc_nom){
    mc_totDOWN = TMath::Sqrt( mc_totDOWN*mc_totDOWN + (vdup.at(7)-mc_nom)*(vdup.at(7)-mc_nom));
    mc_totUP = TMath::Sqrt( mc_totUP*mc_totUP + (vddown.at(7)-mc_nom)*(vddown.at(7)-mc_nom));
  }  
  if(print) printf(" %25s   %+4.3f %+4.3f  %+4.3f %+4.3f \n", "Pileup Rwt: ",vdup.at(0)-dd_nom, vddown.at(0)-dd_nom, vdup.at(7)-mc_nom, vddown.at(7)-mc_nom);
  float dd_prwUP = vdup.at(0)-dd_nom;
  float dd_prwDOWN = vddown.at(0)-dd_nom;

  
  //Summary
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "b-tag: ",dd_btagUP, dd_btagDOWN, mc_btagUP, mc_btagDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "c-tag: ",dd_ctagUP, dd_ctagDOWN, mc_ctagUP, mc_ctagDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "light-tag: ",dd_ltagUP, dd_ltagDOWN, mc_ltagUP, mc_ltagDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "JES: ",dd_jesUP, dd_jesDOWN, mc_jesUP, mc_jesDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "JER: ",dd_jerUP, dd_jerDOWN, mc_jerUP, mc_jerDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "JVT: ",dd_jvtUP, dd_jvtDOWN, mc_jvtUP, mc_jvtDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "MET: ",dd_metUP, dd_metDOWN, mc_metUP, mc_metDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Muon: ",dd_muonUP, dd_muonDOWN, mc_muonUP, mc_muonDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Electron: ",dd_elUP, dd_elDOWN, mc_elUP, mc_elDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Tau: ",dd_tauUP, dd_tauDOWN, mc_tauUP, mc_tauDOWN);
  if(print) printf(" %25s   +%4.3f -%4.3f  +%4.3f -%4.3f \n \n", "Sum Detector: ",dd_totUP, dd_totDOWN, mc_totUP, mc_totDOWN);

  vector<float> vf = {(dd_btagUP+fabs(dd_btagDOWN))/2, (dd_ctagUP+fabs(dd_ctagDOWN))/2, (dd_ltagUP+fabs(dd_ltagDOWN))/2, dd_jesUP, dd_jesDOWN, dd_jerUP, dd_jerDOWN, dd_jvtUP, dd_jvtDOWN, dd_metUP, dd_metDOWN, dd_elUP, dd_elDOWN, dd_muonUP, dd_muonDOWN, dd_tauUP, dd_tauDOWN, (fabs(dd_prwUP)+fabs(dd_prwDOWN))/2, (dd_lumiUP+fabs(dd_lumiDOWN))/2, dd_totUP, dd_totDOWN};
  return vf;
  
}

vector<float> kFactors::GetBackgroundSysts(TString opt, bool print){

  float totalUP_dd = 0.; float totalUP_mc = 0.;
  float totalDOWN_dd = 0.; float totalDOWN_mc = 0.;
  
  vector<double> vd = GetFactors(opt);
  float dd_nom = vd.at(0); float mc_nom = vd.at(7);

  if(print) printf(" %8s     %10s %12s \n", "", "DD", "MC");
  if(print) printf(" %13s     %9.3f     %9.3f \n", "nominal", vd.at(0), vd.at(7));

  //ttbar
  vd = GetFactors(opt+"ttbar_aMC");
  float delta_ttbar_aMC = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar aMC@NLO", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  vd = GetFactors(opt+"ttbar_Herwig");
  float delta_ttbar_Herwig = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar Herwig", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  vd = GetFactors(opt+"ttbar_hdamp");
  float delta_ttbar_hdamp = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar hdamp", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  vd = GetFactors(opt+"ttbar_Var3cDown");
  float delta_ttbar_Var3cDown = vd.at(0)-dd_nom;
  float delta_ttbar_Var3cDown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar Var3cDown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"ttbar_Var3cUp");
  float delta_ttbar_Var3cUp = vd.at(0)-dd_nom;
  float delta_ttbar_Var3cUp_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar Var3cUp", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  if(delta_ttbar_Var3cDown > 0 && delta_ttbar_Var3cUp > 0) totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp)*TMath::Max(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp));
  else if(delta_ttbar_Var3cDown < 0 && delta_ttbar_Var3cUp < 0) totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp)*TMath::Min(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp));
  else {
    totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp)*TMath::Max(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp));
    totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp)*TMath::Min(delta_ttbar_Var3cDown,delta_ttbar_Var3cUp));
  }

  if(delta_ttbar_Var3cDown_mc > 0 && delta_ttbar_Var3cUp_mc > 0) totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc)*TMath::Max(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc));
  else if(delta_ttbar_Var3cDown_mc < 0 && delta_ttbar_Var3cUp_mc < 0) totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc)*TMath::Min(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc));
  else {
    totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc)*TMath::Max(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc));
    totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc)*TMath::Min(delta_ttbar_Var3cDown_mc,delta_ttbar_Var3cUp_mc));
  }

  vd = GetFactors(opt+"ttbar_MURdown");
  float delta_ttbar_MURdown = vd.at(0)-dd_nom;
  float delta_ttbar_MURdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar MURdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"ttbar_MURup");
  float delta_ttbar_MURup = vd.at(0)-dd_nom;
  float delta_ttbar_MURup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar MURup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  if(delta_ttbar_MURdown > 0 && delta_ttbar_MURup > 0) totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttbar_MURdown,delta_ttbar_MURup)*TMath::Max(delta_ttbar_MURdown,delta_ttbar_MURup));
  else if(delta_ttbar_MURdown < 0 && delta_ttbar_MURup < 0) totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttbar_MURdown,delta_ttbar_MURup)*TMath::Min(delta_ttbar_MURdown,delta_ttbar_MURup));
  else {
    totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttbar_MURdown,delta_ttbar_MURup)*TMath::Max(delta_ttbar_MURdown,delta_ttbar_MURup));
    totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttbar_MURdown,delta_ttbar_MURup)*TMath::Min(delta_ttbar_MURdown,delta_ttbar_MURup));
  }

  if(delta_ttbar_MURdown_mc > 0 && delta_ttbar_MURup_mc > 0) totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc)*TMath::Max(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc));
  else if(delta_ttbar_MURdown_mc < 0 && delta_ttbar_MURup_mc < 0) totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc)*TMath::Min(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc));
  else {
    totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc)*TMath::Max(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc));
    totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc)*TMath::Min(delta_ttbar_MURdown_mc,delta_ttbar_MURup_mc));
  }

  vd = GetFactors(opt+"ttbar_MUFdown");
  float delta_ttbar_MUFdown = vd.at(0)-dd_nom;
  float delta_ttbar_MUFdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar MUFdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"ttbar_MUFup");
  float delta_ttbar_MUFup = vd.at(0)-dd_nom;
  float delta_ttbar_MUFup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttbar MUFup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  if(delta_ttbar_MUFdown > 0 && delta_ttbar_MUFup > 0) totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttbar_MUFdown,delta_ttbar_MUFup)*TMath::Max(delta_ttbar_MUFdown,delta_ttbar_MUFup));
  else if(delta_ttbar_MUFdown < 0 && delta_ttbar_MUFup < 0) totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttbar_MUFdown,delta_ttbar_MUFup)*TMath::Min(delta_ttbar_MUFdown,delta_ttbar_MUFup));
  else {
    totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttbar_MUFdown,delta_ttbar_MUFup)*TMath::Max(delta_ttbar_MUFdown,delta_ttbar_MUFup));
    totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttbar_MUFdown,delta_ttbar_MUFup)*TMath::Min(delta_ttbar_MUFdown,delta_ttbar_MUFup));
  }

  if(delta_ttbar_MUFdown_mc > 0 && delta_ttbar_MUFup_mc > 0) totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc)*TMath::Max(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc));
  else if(delta_ttbar_MUFdown_mc < 0 && delta_ttbar_MUFup_mc < 0) totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc)*TMath::Min(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc));
  else {
    totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc)*TMath::Max(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc));
    totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc)*TMath::Min(delta_ttbar_MUFdown_mc,delta_ttbar_MUFup_mc));
  }


  
  //Wt
  vd = GetFactors(opt+"Wt_aMC");
  float delta_Wt_aMC = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","Wt aMC@NLO", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  vd = GetFactors(opt+"Wt_Herwig");
  float delta_Wt_Herwig = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","Wt Herwig", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  vd = GetFactors(opt+"Wt_DS");
  float delta_Wt_DS = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","Wt DS", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  
  vd = GetFactors(opt+"Wt_RadLo");
  float delta_Wt_RadLo = vd.at(0)-dd_nom;
  float delta_Wt_RadLo_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","Wt RadLo", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"Wt_RadHi");
  float delta_Wt_RadHi = vd.at(0)-dd_nom;
  float delta_Wt_RadHi_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","Wt RadHi", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  if(delta_Wt_RadLo > 0 && delta_Wt_RadHi > 0) totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_Wt_RadLo,delta_Wt_RadHi)*TMath::Max(delta_Wt_RadLo,delta_Wt_RadHi));
  else if(delta_Wt_RadLo < 0 && delta_Wt_RadHi < 0) totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_Wt_RadLo,delta_Wt_RadHi)*TMath::Min(delta_Wt_RadLo,delta_Wt_RadHi));
  else {
    totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_Wt_RadLo,delta_Wt_RadHi)*TMath::Max(delta_Wt_RadLo,delta_Wt_RadHi));
    totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_Wt_RadLo,delta_Wt_RadHi)*TMath::Min(delta_Wt_RadLo,delta_Wt_RadHi));
  }

  if(delta_Wt_RadLo_mc > 0 && delta_Wt_RadHi_mc > 0) totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc)*TMath::Max(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc));
  else if(delta_Wt_RadLo_mc < 0 && delta_Wt_RadHi_mc < 0) totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc)*TMath::Min(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc));
  else {
    totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc)*TMath::Max(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc));
    totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc)*TMath::Min(delta_Wt_RadLo_mc,delta_Wt_RadHi_mc));
  }
  

  //W+jets
  vd = GetFactors(opt+"W_FxFx");
  float delta_W_FxFx = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","W FxFx", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));

  float maxUP_W_dd = 0.0;
  float maxDOWN_W_dd = 0.0;
  float maxUP_W_mc = 0.0;
  float maxDOWN_W_mc = 0.0;

  vector<TString> MUs = {"MUR", "MUF", "MURMUF"};

  for(int i = 0; i < MUs.size(); i++){
    vd = GetFactors(opt+"W_"+MUs.at(i)+"up");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("W "+MUs.at(i)+" UP")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_W_dd) maxUP_W_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_W_dd) maxDOWN_W_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_W_mc) maxUP_W_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_W_mc) maxDOWN_W_mc = mc_nom-vd.at(7);
    vd = GetFactors(opt+"W_"+MUs.at(i)+"down");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("W "+MUs.at(i)+" DOWN")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_W_dd) maxUP_W_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_W_dd) maxDOWN_W_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_W_mc) maxUP_W_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_W_mc) maxDOWN_W_mc = mc_nom-vd.at(7);
  }

  if(print) printf(" %13s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "W scales",maxUP_W_dd, maxDOWN_W_dd, maxUP_W_mc, maxDOWN_W_mc);
  
  totalUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd + maxUP_W_dd*maxUP_W_dd);
  totalDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd + maxDOWN_W_dd*maxDOWN_W_dd);
  totalUP_mc = TMath::Sqrt(totalUP_mc*totalUP_mc + maxUP_W_mc*maxUP_W_mc);
  totalDOWN_mc = TMath::Sqrt(totalDOWN_mc*totalDOWN_mc + maxDOWN_W_mc*maxDOWN_W_mc);

  //Z+jets
  float maxUP_Z_dd = 0.0;
  float maxDOWN_Z_dd = 0.0;
  float maxUP_Z_mc = 0.0;
  float maxDOWN_Z_mc = 0.0;
  
  for(int i = 0; i < MUs.size(); i++){
    vd = GetFactors(opt+"Z_"+MUs.at(i)+"up");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("Z "+MUs.at(i)+" UP")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_Z_dd) maxUP_Z_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_Z_dd) maxDOWN_Z_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_Z_mc) maxUP_Z_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_Z_mc) maxDOWN_Z_mc = mc_nom-vd.at(7);
    vd = GetFactors(opt+"Z_"+MUs.at(i)+"down");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("Z "+MUs.at(i)+" DOWN")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_Z_dd) maxUP_Z_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_Z_dd) maxDOWN_Z_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_Z_mc) maxUP_Z_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_Z_mc) maxDOWN_Z_mc = mc_nom-vd.at(7);
  }
  
  if(print) printf(" %13s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Z scales",maxUP_Z_dd, maxDOWN_Z_dd, maxUP_Z_mc, maxDOWN_Z_mc);
  
  totalUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd + maxUP_Z_dd*maxUP_Z_dd);
  totalDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd + maxDOWN_Z_dd*maxDOWN_Z_dd);
  totalUP_mc = TMath::Sqrt(totalUP_mc*totalUP_mc + maxUP_Z_mc*maxUP_Z_mc);
  totalDOWN_mc = TMath::Sqrt(totalDOWN_mc*totalDOWN_mc + maxDOWN_Z_mc*maxDOWN_Z_mc);

  float intermediateUP = totalUP_dd;
  float intermediateDOWN = totalDOWN_dd;
  
  //t-channel single top  
  vd = GetFactors(opt+"stopt_RadLo");
  float delta_stopt_RadLo = vd.at(0)-dd_nom;
  float delta_stopt_RadLo_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","stopt RadLo", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"stopt_RadHi");
  float delta_stopt_RadHi = vd.at(0)-dd_nom;
  float delta_stopt_RadHi_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","stopt RadHi", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  if(delta_stopt_RadLo > 0 && delta_stopt_RadHi > 0) totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_stopt_RadLo,delta_stopt_RadHi)*TMath::Max(delta_stopt_RadLo,delta_stopt_RadHi));
  else if(delta_stopt_RadLo < 0 && delta_stopt_RadHi < 0) totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_stopt_RadLo,delta_stopt_RadHi)*TMath::Min(delta_stopt_RadLo,delta_stopt_RadHi));
  else {
    totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_stopt_RadLo,delta_stopt_RadHi)*TMath::Max(delta_stopt_RadLo,delta_stopt_RadHi));
    totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_stopt_RadLo,delta_stopt_RadHi)*TMath::Min(delta_stopt_RadLo,delta_stopt_RadHi));
  }

  if(delta_stopt_RadLo_mc > 0 && delta_stopt_RadHi_mc > 0) totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc)*TMath::Max(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc));
  else if(delta_stopt_RadLo_mc < 0 && delta_stopt_RadHi_mc < 0) totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc)*TMath::Min(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc));
  else {
    totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc)*TMath::Max(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc));
    totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc)*TMath::Min(delta_stopt_RadLo_mc,delta_stopt_RadHi_mc));
  }

  vd = GetFactors(opt+"stopt_XSup");
  float delta_stopt_XSup = vd.at(0)-dd_nom;
  float delta_stopt_XSup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","stopt XSup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"stopt_XSdown");
  float delta_stopt_XSdown = vd.at(0)-dd_nom;
  float delta_stopt_XSdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","stopt XSdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_stopt_XSup,delta_stopt_XSdown)*TMath::Max(delta_stopt_XSup,delta_stopt_XSdown));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_stopt_XSup,delta_stopt_XSdown)*TMath::Min(delta_stopt_XSup,delta_stopt_XSdown));

  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_stopt_XSup_mc,delta_stopt_XSdown_mc)*TMath::Max(delta_stopt_XSup_mc,delta_stopt_XSdown_mc));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_stopt_XSup_mc,delta_stopt_XSdown_mc)*TMath::Min(delta_stopt_XSup_mc,delta_stopt_XSdown_mc));

  vd = GetFactors(opt+"stopt_Herwig");
  float delta_stopt_Herwig = vd.at(0)-dd_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","stopt Herwig", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + (vd.at(0)-dd_nom)*(vd.at(0)-dd_nom));
  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + (vd.at(7)-mc_nom)*(vd.at(7)-mc_nom));
  
  float stoptUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd - intermediateUP*intermediateUP);
  float stoptDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd - intermediateDOWN*intermediateDOWN);
  
  intermediateUP = totalUP_dd;
  intermediateDOWN = totalDOWN_dd;  
  
  //WH
  vd = GetFactors(opt+"WH_XSup");
  float delta_WH_XSup = vd.at(0)-dd_nom;
  float delta_WH_XSup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","WH XSup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"WH_XSdown");
  float delta_WH_XSdown = vd.at(0)-dd_nom;
  float delta_WH_XSdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","WH XSdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_WH_XSup,delta_WH_XSdown)*TMath::Max(delta_WH_XSup,delta_WH_XSdown));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_WH_XSup,delta_WH_XSdown)*TMath::Min(delta_WH_XSup,delta_WH_XSdown));

  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_WH_XSup_mc,delta_WH_XSdown_mc)*TMath::Max(delta_WH_XSup_mc,delta_WH_XSdown_mc));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_WH_XSup_mc,delta_WH_XSdown_mc)*TMath::Min(delta_WH_XSup_mc,delta_WH_XSdown_mc));
  
  float maxUP_WH_dd = 0.0;
  float maxDOWN_WH_dd = 0.0;
  float maxUP_WH_mc = 0.0;
  float maxDOWN_WH_mc = 0.0;
  
  for(int i = 0; i < MUs.size(); i++){
    vd = GetFactors(opt+"WH_"+MUs.at(i)+"up");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("WH "+MUs.at(i)+" UP")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_WH_dd) maxUP_WH_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_WH_dd) maxDOWN_WH_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_WH_mc) maxUP_WH_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_WH_mc) maxDOWN_WH_mc = mc_nom-vd.at(7);
    vd = GetFactors(opt+"WH_"+MUs.at(i)+"down");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("WH "+MUs.at(i)+" DOWN")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_WH_dd) maxUP_WH_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_WH_dd) maxDOWN_WH_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_WH_mc) maxUP_WH_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_WH_mc) maxDOWN_WH_mc = mc_nom-vd.at(7);
  }
  
  if(print) printf(" %13s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "WH scales",maxUP_WH_dd, maxDOWN_WH_dd, maxUP_WH_mc, maxDOWN_WH_mc);
  
  totalUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd + maxUP_WH_dd*maxUP_WH_dd);
  totalDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd + maxDOWN_WH_dd*maxDOWN_WH_dd);
  totalUP_mc = TMath::Sqrt(totalUP_mc*totalUP_mc + maxUP_WH_mc*maxUP_WH_mc);
  totalDOWN_mc = TMath::Sqrt(totalDOWN_mc*totalDOWN_mc + maxDOWN_WH_mc*maxDOWN_WH_mc);

  float WHUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd - intermediateUP*intermediateUP);
  float WHDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd - intermediateDOWN*intermediateDOWN);
  
  intermediateUP = totalUP_dd;
  intermediateDOWN = totalDOWN_dd;  

  //WZ
  float maxUP_WZqcd_dd = 0.0;
  float maxDOWN_WZqcd_dd = 0.0;
  float maxUP_WZqcd_mc = 0.0;
  float maxDOWN_WZqcd_mc = 0.0;
  
  for(int i = 0; i < MUs.size(); i++){
    vd = GetFactors(opt+"WZqcd_"+MUs.at(i)+"up");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("WZqcd "+MUs.at(i)+" UP")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_WZqcd_dd) maxUP_WZqcd_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_WZqcd_dd) maxDOWN_WZqcd_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_WZqcd_mc) maxUP_WZqcd_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_WZqcd_mc) maxDOWN_WZqcd_mc = mc_nom-vd.at(7);
    vd = GetFactors(opt+"WZqcd_"+MUs.at(i)+"down");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("WZqcd "+MUs.at(i)+" DOWN")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_WZqcd_dd) maxUP_WZqcd_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_WZqcd_dd) maxDOWN_WZqcd_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_WZqcd_mc) maxUP_WZqcd_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_WZqcd_mc) maxDOWN_WZqcd_mc = mc_nom-vd.at(7);
  }
  
  if(print) printf(" %13s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "WZqcd scales",maxUP_WZqcd_dd, maxDOWN_WZqcd_dd, maxUP_WZqcd_mc, maxDOWN_WZqcd_mc);
  
  totalUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd + maxUP_WZqcd_dd*maxUP_WZqcd_dd);
  totalDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd + maxDOWN_WZqcd_dd*maxDOWN_WZqcd_dd);
  totalUP_mc = TMath::Sqrt(totalUP_mc*totalUP_mc + maxUP_WZqcd_mc*maxUP_WZqcd_mc);
  totalDOWN_mc = TMath::Sqrt(totalDOWN_mc*totalDOWN_mc + maxDOWN_WZqcd_mc*maxDOWN_WZqcd_mc);

  float maxUP_WZewk_dd = 0.0;
  float maxDOWN_WZewk_dd = 0.0;
  float maxUP_WZewk_mc = 0.0;
  float maxDOWN_WZewk_mc = 0.0;
  
  for(int i = 0; i < MUs.size(); i++){
    vd = GetFactors(opt+"WZewk_"+MUs.at(i)+"up");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("WZewk "+MUs.at(i)+" UP")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_WZewk_dd) maxUP_WZewk_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_WZewk_dd) maxDOWN_WZewk_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_WZewk_mc) maxUP_WZewk_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_WZewk_mc) maxDOWN_WZewk_mc = mc_nom-vd.at(7);
    vd = GetFactors(opt+"WZewk_"+MUs.at(i)+"down");
    if(print) printf(" %15s     %+9.3f     %+9.3f \n",((string)("WZewk "+MUs.at(i)+" DOWN")).c_str(), vd.at(0)-dd_nom, vd.at(7)-mc_nom);
    if(vd.at(0)-dd_nom > maxUP_WZewk_dd) maxUP_WZewk_dd = vd.at(0)-dd_nom;
    if(dd_nom-vd.at(0) > maxDOWN_WZewk_dd) maxDOWN_WZewk_dd = dd_nom-vd.at(0);
    if(vd.at(7)-mc_nom > maxUP_WZewk_mc) maxUP_WZewk_mc = vd.at(7)-mc_nom;
    if(mc_nom-vd.at(7) > maxDOWN_WZewk_mc) maxDOWN_WZewk_mc = mc_nom-vd.at(7);
  }
  
  if(print) printf(" %13s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "WZewk scales",maxUP_WZewk_dd, maxDOWN_WZewk_dd, maxUP_WZewk_mc, maxDOWN_WZewk_mc);
  
  totalUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd + maxUP_WZewk_dd*maxUP_WZewk_dd);
  totalDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd + maxDOWN_WZewk_dd*maxDOWN_WZewk_dd);
  totalUP_mc = TMath::Sqrt(totalUP_mc*totalUP_mc + maxUP_WZewk_mc*maxUP_WZewk_mc);
  totalDOWN_mc = TMath::Sqrt(totalDOWN_mc*totalDOWN_mc + maxDOWN_WZewk_mc*maxDOWN_WZewk_mc);

  float WZUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd - intermediateUP*intermediateUP);
  float WZDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd - intermediateDOWN*intermediateDOWN);
  
  intermediateUP = totalUP_dd;
  intermediateDOWN = totalDOWN_dd;  

  //ttH
  vd = GetFactors(opt+"ttH_XSup");
  float delta_ttH_XSup = vd.at(0)-dd_nom;
  float delta_ttH_XSup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttH XSup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"ttH_XSdown");
  float delta_ttH_XSdown = vd.at(0)-dd_nom;
  float delta_ttH_XSdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttH XSdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttH_XSup,delta_ttH_XSdown)*TMath::Max(delta_ttH_XSup,delta_ttH_XSdown));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttH_XSup,delta_ttH_XSdown)*TMath::Min(delta_ttH_XSup,delta_ttH_XSdown));

  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttH_XSup_mc,delta_ttH_XSdown_mc)*TMath::Max(delta_ttH_XSup_mc,delta_ttH_XSdown_mc));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttH_XSup_mc,delta_ttH_XSdown_mc)*TMath::Min(delta_ttH_XSup_mc,delta_ttH_XSdown_mc));

  float ttHUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd - intermediateUP*intermediateUP);
  float ttHDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd - intermediateDOWN*intermediateDOWN);
  
  intermediateUP = totalUP_dd;
  intermediateDOWN = totalDOWN_dd;  


  //ZH
  vd = GetFactors(opt+"ZH_XSup");
  float delta_ZH_XSup = vd.at(0)-dd_nom;
  float delta_ZH_XSup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ZH XSup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"ZH_XSdown");
  float delta_ZH_XSdown = vd.at(0)-dd_nom;
  float delta_ZH_XSdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ZH XSdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ZH_XSup,delta_ZH_XSdown)*TMath::Max(delta_ZH_XSup,delta_ZH_XSdown));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ZH_XSup,delta_ZH_XSdown)*TMath::Min(delta_ZH_XSup,delta_ZH_XSdown));

  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ZH_XSup_mc,delta_ZH_XSdown_mc)*TMath::Max(delta_ZH_XSup_mc,delta_ZH_XSdown_mc));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ZH_XSup_mc,delta_ZH_XSdown_mc)*TMath::Min(delta_ZH_XSup_mc,delta_ZH_XSdown_mc));

  float ZHUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd - intermediateUP*intermediateUP);
  float ZHDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd - intermediateDOWN*intermediateDOWN);
  
  intermediateUP = totalUP_dd;
  intermediateDOWN = totalDOWN_dd;  

  
  //ttV
  vd = GetFactors(opt+"ttV_XSup");
  float delta_ttV_XSup = vd.at(0)-dd_nom;
  float delta_ttV_XSup_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttV XSup", vd.at(0)-dd_nom, vd.at(7)-mc_nom);
  vd = GetFactors(opt+"ttV_XSdown");
  float delta_ttV_XSdown = vd.at(0)-dd_nom;
  float delta_ttV_XSdown_mc = vd.at(7)-mc_nom;
  if(print) printf(" %13s     %+9.3f     %+9.3f \n","ttV XSdown", vd.at(0)-dd_nom, vd.at(7)-mc_nom);

  totalUP_dd = TMath::Sqrt( totalUP_dd*totalUP_dd + TMath::Max(delta_ttV_XSup,delta_ttV_XSdown)*TMath::Max(delta_ttV_XSup,delta_ttV_XSdown));
  totalDOWN_dd = TMath::Sqrt( totalDOWN_dd*totalDOWN_dd + TMath::Min(delta_ttV_XSup,delta_ttV_XSdown)*TMath::Min(delta_ttV_XSup,delta_ttV_XSdown));

  totalUP_mc = TMath::Sqrt( totalUP_mc*totalUP_mc + TMath::Max(delta_ttV_XSup_mc,delta_ttV_XSdown_mc)*TMath::Max(delta_ttV_XSup_mc,delta_ttV_XSdown_mc));
  totalDOWN_mc = TMath::Sqrt( totalDOWN_mc*totalDOWN_mc + TMath::Min(delta_ttV_XSup_mc,delta_ttV_XSdown_mc)*TMath::Min(delta_ttV_XSup_mc,delta_ttV_XSdown_mc));

  float ttVUP_dd = TMath::Sqrt(totalUP_dd*totalUP_dd - intermediateUP*intermediateUP);
  float ttVDOWN_dd = TMath::Sqrt(totalDOWN_dd*totalDOWN_dd - intermediateDOWN*intermediateDOWN);
  
  intermediateUP = totalUP_dd;
  intermediateDOWN = totalDOWN_dd;  
  
  
  //Summary
  
  if(print) printf(" %13s   +%4.3f -%4.3f  +%4.3f -%4.3f \n", "Total",totalUP_dd, totalDOWN_dd, totalUP_mc, totalDOWN_mc);

  vector<float> vf = { delta_ttbar_aMC, delta_ttbar_Herwig, delta_ttbar_hdamp, delta_ttbar_Var3cDown, delta_ttbar_Var3cUp, delta_ttbar_MURdown, delta_ttbar_MURup, delta_ttbar_MUFdown, delta_ttbar_MUFup, delta_Wt_aMC, delta_Wt_Herwig, delta_Wt_RadLo, delta_Wt_RadHi, delta_Wt_DS, delta_W_FxFx, maxDOWN_W_dd, maxUP_W_dd, maxDOWN_Z_dd, maxUP_Z_dd, stoptDOWN_dd, stoptUP_dd, WHDOWN_dd, WHUP_dd, WZDOWN_dd, WZUP_dd, ttHDOWN_dd, ttHUP_dd, ZHDOWN_dd, ZHUP_dd, ttVDOWN_dd, ttVUP_dd, totalDOWN_dd, totalUP_dd};
  return vf;
  
}


void kFactors::GetDDSysts(TString opt){

  float totalUP = 0.;
  float totalDOWN = 0.;
  
  vector<double> vd = GetFactors(opt);
  float nom = vd.at(0);

  printf(" %8s     %10s  \n", "", "DD");
  printf(" %13s     %9.3f  \n", "nominal", vd.at(0));

 
  vd = GetFactors(opt+"WCRalt");
  printf(" %13s     %+9.3f   \n","W CR alt", vd.at(0)- nom);
  if(vd.at(0) > nom) totalUP = TMath::Sqrt( totalUP*totalUP + (vd.at(0)-nom)*(vd.at(0)-nom));
  else totalDOWN = TMath::Sqrt( totalDOWN*totalDOWN + (vd.at(0)-nom)*(vd.at(0)-nom));

  vd = GetFactors(opt+"WtCRalt");
  printf(" %13s     %+9.3f   \n","Wt CR alt", vd.at(0)- nom);
  if(vd.at(0) > nom) totalUP = TMath::Sqrt( totalUP*totalUP + (vd.at(0)-nom)*(vd.at(0)-nom));
  else totalDOWN = TMath::Sqrt( totalDOWN*totalDOWN + (vd.at(0)-nom)*(vd.at(0)-nom));

  vd = GetFactors(opt+"ttbarCRalt");
  printf(" %13s     %+9.3f   \n","ttbar CR alt", vd.at(0)- nom);
  if(vd.at(0) > nom) totalUP = TMath::Sqrt( totalUP*totalUP + (vd.at(0)-nom)*(vd.at(0)-nom));
  else totalDOWN = TMath::Sqrt( totalDOWN*totalDOWN + (vd.at(0)-nom)*(vd.at(0)-nom));

  printf("  %13s     +%4.3f  -%4.3f \n","Quad sum", totalUP, totalDOWN);

  vd = GetFactors(opt+"WCRaltWtCRaltttbarCRalt");
  printf(" %13s     %+9.3f   \n","All varied", vd.at(0)- nom);

}

void kFactors::GetSigKappas(TString opt){

  vector<TString> kapVars = {   "kZ087kW093",   "kZ087kW105",   "kZ091kW113",   "kZ093kW099",   "kZ093kW105",   "kZ094kW111",   "kZ099kW093",   "kZ099kW105",   "kZ099kW111",   "kZ099kW117",   "kZ105kW099",   "kZ105kW105",   "kZ105kW111",   "kZ108kW095",   "kZ111kW105",   "kZ111kW117"};

  for(int k = 0; k < kapVars.size(); k++){

    vector<double> vd = GetFactors("SplusB"+kapVars.at(k)+opt);
    cout<<"For kZ = "<<kapVars.at(k)(2,3)<<" kW = "<<kapVars.at(k)(7,3)<<" S+B = "<<vd.at(0)<<endl;

  }

  return; 
}

void kFactors::GetContour(){

  vector<TString> kapVars = {  "kZ087kW093",   "kZ087kW105",   "kZ091kW113",   "kZ093kW099",   "kZ093kW105",   "kZ094kW111",   "kZ099kW093",   "kZ099kW105",   "kZ099kW111",   "kZ099kW117",   "kZ105kW099",   "kZ105kW105",   "kZ105kW111",   "kZ108kW095",   "kZ111kW105",   "kZ111kW117"};

  vector<double> vd_loose = GetFactors("posl");
  vector<double> vd_tight = GetFactors("post");
  vector<double> vd_looseS = GetFactors("SplusBposl");
  vector<double> vd_tightS = GetFactors("SplusBpost");  
  float Bloose = vd_loose.at(0);
  float Btight = vd_tight.at(0);
  float Sloose = vd_looseS.at(0) - vd_loose.at(0);
  float Stight = vd_tightS.at(0) - vd_tight.at(0);
  
  vector<float>* Errors = GetPosLamMu(Bloose, Btight, "");

  cout<<"Background = "<<Bloose<<"/"<<Btight<<endl<<endl;;
  cout<<"For kappaZ = 1.00, kappaW = 1.00,"<<endl;
  cout<<" Signal = "<<Sloose<<"/"<<Stight<<endl;
  cout<<" upper limit = "<<GetMuUpperLimit( Bloose, Btight, Bloose, Btight, Sloose, Stight, Errors->at(1), Errors->at(2), false)<<endl;

  vector<TString> commands;
  
  for(int k = 0; k < kapVars.size(); k++){

    vd_looseS = GetFactors("SplusB"+kapVars.at(k)+"posl");
    vd_tightS = GetFactors("SplusB"+kapVars.at(k)+"post");

    Errors = GetPosLamMu(Bloose, Btight, kapVars.at(k));
    
    Sloose = vd_looseS.at(0) - Bloose;
    Stight = vd_tightS.at(0) - Btight;
    
    // float upLim = GetMuUpperLimit( Bloose, Btight, Bloose, Btight, Sloose, Stight, Errors->at(1), Errors->at(2), false);
    // cout<<" upper limit = "<<upLim<<endl;

    commands.push_back((TString)"a.GetMuUpperLimit( "+Bloose+", "+Btight+", "+Bloose+", "+Btight+", "+Sloose+", "+Stight+", "+Errors->at(1)+", "+Errors->at(2)+", false)");
    
  }

  for(int k = 0; k < kapVars.size(); k++){
    cout<<"For kappaZ = "<<kapVars.at(k)(2,3)<<" kappaW = "<<kapVars.at(k)(7,3)<<","<<endl;
    cout<<" "<<commands.at(k)<<endl<<endl;
  }
  
}

vector<float> kFactors::GetSigSysts(TString opt, bool print){
  
  vector<double> vd = GetFactors(opt);
  float nom = vd.at(0);

  if(print) printf(" %8s     %10s  \n", "", "DD");
  if(print) printf(" %13s     %9.3f  \n", "nominal", vd.at(0));

  vector<TString> MUs = {"MUR2_MUF1", "MUR05_MUF1", "MUR1_MUF2", "MUR1_MUF05", "MUR2_MUF2", "MUR05_MUF05"};  
  
  float musUP = 0.;
  float musDOWN = 0.;

  for(int i = 0; i < MUs.size(); i++){
    vd = GetFactors(opt+"SigSys_"+MUs.at(i));
    if(print) printf(" %13s     %+9.3f   \n",((string)MUs.at(i)).c_str(), vd.at(0)- nom);
    if(vd.at(0) - nom > musUP) musUP = vd.at(0)- nom;
    if(vd.at(0) - nom < musDOWN) musDOWN = vd.at(0)- nom;
  }

  if(print) printf("Scale uncertainty: %+9.3f %+9.3f \n \n ",musUP,musDOWN);

  float pdfsUP = 0.;
  float pdfsDOWN = 0.;
  
  for(int p = 260001; p < 260100; p++){
    stringstream ss;
    ss<<p;
    TString pStr = "PDF"+ss.str();
    vd = GetFactors(opt+"SigSys_"+pStr);
    if(print) printf(" %13s     %+9.3f   \n",((string)pStr).c_str(), vd.at(0)- nom);
    if(vd.at(0) - nom > pdfsUP) pdfsUP = vd.at(0)- nom;
    if(vd.at(0) - nom < pdfsDOWN) pdfsDOWN = vd.at(0)- nom;
  }

  if(print) printf("Scale uncertainty: %+9.3f %+9.3f \n",musUP,musDOWN);
  if(print) printf("PDF uncertainty: %+9.3f %+9.3f \n",pdfsUP,pdfsDOWN);
  
  vd = GetFactors(opt+"SigSys_PDF265000");
  float as1 = vd.at(0)- nom;
  vd = GetFactors(opt+"SigSys_PDF266000");
  float as2 = vd.at(0)- nom;
  if(print) printf("alphaS uncertainty: %+9.3f %+9.3f \n",as1,as2);

  float ckkw = 0.0;
  
  if(opt.Contains("posl") || opt.Contains("post")){
    vd = GetFactors(opt+"CKKW");
    ckkw = vd.at(0) - nom;
    if(print) printf("CKKW unceratinty: %+9.3f \n",ckkw);
  }

  
  float totUP = TMath::Sqrt(musUP*musUP + pdfsUP*pdfsUP + as1*as1);
  float totDOWN = TMath::Sqrt(musDOWN*musDOWN + pdfsDOWN*pdfsDOWN + as2*as2);

  if(ckkw > 0) totUP = TMath::Sqrt(totUP*totUP + ckkw*ckkw);
  else totDOWN = TMath::Sqrt(totDOWN*totDOWN + ckkw*ckkw);
  
  if(print) printf("Signal Theory: +%9.3f -%9.3f \n",totUP, totDOWN);

  vector<float> vf = {musUP, musDOWN, pdfsUP, pdfsDOWN, as1, as2, ckkw, totUP, totDOWN};
  return vf;
  
}


void kFactors::PrintTables(){

  //First the table of k-factors
  vector<double> ktt_neg = GetValue("",6);
  vector<double> kW_neg = GetValue("",4);
  vector<double> kWt_neg = GetValue("",5);
  vector<double> ktt_pos = GetValue("posl",6);
  vector<double> kW_pos = GetValue("posl",4);
  vector<double> kWt_pos = GetValue("posl",5);

  printf(" \n \n \n");
  printf("\\hline \n");
  printf("& Negative \\lam & Positive \\lam  \\\\ \n");
  printf("\\hline \n");
  printf("\\ktt  & $ %4.2f \\pm %4.2f $   & $ %4.2f \\pm %4.2f$ \\\\ \n", ktt_neg.at(0), (ktt_neg.at(1) + ktt_neg.at(2))/2, ktt_pos.at(0), (ktt_pos.at(1) + ktt_pos.at(2))/2);
  printf("\\kW   & $ %4.2f \\pm %4.2f $   & $ %4.2f \\pm %4.2f$ \\\\ \n", kW_neg.at(0), (kW_neg.at(1) + kW_neg.at(2))/2, kW_pos.at(0), (kW_pos.at(1) + kW_pos.at(2))/2);
  printf("\\kWt  & $ %4.2f \\pm %4.2f $   & $ %4.2f \\pm %4.2f$ \\\\ \n", kWt_neg.at(0), (kWt_neg.at(1) + kWt_neg.at(2))/2, kWt_pos.at(0), (kWt_pos.at(1) + kWt_pos.at(2))/2);
  printf("\\hline \n");
  printf(" \n \n \n");

  
  //Next a table of yields
  vector<double> ntt_neg = GetValue("",3);
  vector<double> nw_neg = GetValue("",1);
  vector<double> nwt_neg = GetValue("",2);
  vector<double> nrest_neg = GetValue("",8);
  vector<double> sum_neg = GetValue("",0);
  TH1F* hsn_neg = (TH1F*)f_sn->Get("sum_SRNeg_NominalFull");

  vector<double> ntt_pl = GetValue("posl",3);
  vector<double> nw_pl = GetValue("posl",1);
  vector<double> nwt_pl = GetValue("posl",2);
  vector<double> nrest_pl = GetValue("posl",8);
  vector<double> sum_pl = GetValue("posl",0);
  TH1F* hsp_pl = (TH1F*)f_sp->Get("sum_SRPosLoose_NominalFull");

  vector<double> ntt_pt = GetValue("post",3);
  vector<double> nw_pt = GetValue("post",1);
  vector<double> nwt_pt = GetValue("post",2);
  vector<double> nrest_pt = GetValue("post",8);
  vector<double> sum_pt = GetValue("post",0);
  TH1F* hsp_pt = (TH1F*)f_sp->Get("sum_SRPosTight_NominalFull");

  
  printf(" \n \n \n");
  printf("\\hline \n");
  printf("& SR Neg & SR Pos Loose & SR Pos Tight  \\\\ \n");
  printf("\\hline \n");
  printf("\\ttbar    & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", ntt_neg.at(0), (ntt_neg.at(1) + ntt_neg.at(2))/2, ntt_pl.at(0), (ntt_pl.at(1) + ntt_pl.at(2))/2,ntt_pt.at(0), (ntt_pt.at(1) + ntt_pt.at(2))/2);
  printf("$W$+jets  & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", nw_neg.at(0), (nw_neg.at(1) + nw_neg.at(2))/2, nw_pl.at(0), (nw_pl.at(1) + nw_pl.at(2))/2,nw_pt.at(0), (nw_pt.at(1) + nw_pt.at(2))/2);
  printf("$Wt$      & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", nwt_neg.at(0), (nwt_neg.at(1) + nwt_neg.at(2))/2, nwt_pl.at(0), (nwt_pl.at(1) + nwt_pl.at(2))/2,nwt_pt.at(0), (nwt_pt.at(1) + nwt_pt.at(2))/2);
  printf("Other bkg & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", nrest_neg.at(0), (nrest_neg.at(1) + nrest_neg.at(2))/2, nrest_pl.at(0), (nrest_pl.at(1) + nrest_pl.at(2))/2,nrest_pt.at(0), (nrest_pt.at(1) + nrest_pt.at(2))/2);
  printf("\\hline \n");
  printf("Sum bkg   & $ %4.1f \\pm %4.1f$ & $ %4.1f \\pm %4.1f$    &  $ %4.1f \\pm %4.1f$   \\\\ \n", sum_neg.at(0), (sum_neg.at(1) + sum_neg.at(2))/2, sum_pl.at(0), (sum_pl.at(1) + sum_pl.at(2))/2,sum_pt.at(0), (sum_pt.at(1) + sum_pt.at(2))/2); 
  printf("Signal    & $ %4.1f \\pm %4.1f$ & $ %4.1f \\pm %4.1f$    &  $ %4.1f \\pm %4.1f$   \\\\ \n", hsn_neg->GetBinContent(1), hsn_neg->GetBinError(1), hsp_pl->GetBinContent(1), hsp_pl->GetBinError(1), hsp_pt->GetBinContent(1), hsp_pt->GetBinError(1));
  printf("\\hline \n");
  printf("Data      &  %4.0f &  %4.0f   &   %4.0f \\\\ \n", -99., -99., -99.);
  printf("\\hline \n");

  // //Yields for the validation regions
  // ntt_neg = GetValue("VR",3);
  // nw_neg = GetValue("VR",1);
  // nwt_neg = GetValue("VR",2);
  // nrest_neg = GetValue("VR",8);
  // sum_neg = GetValue("VR",0);
  // hsn_neg = (TH1F*)f_sn->Get("sum_VRNeg_NominalFull");
  // TH1F* hsp_neg = (TH1F*)f_sp->Get("sum_VRNeg_NominalFull");
  // TH1F* hda_neg = (TH1F*)f_da->Get("sum_VRNeg_NominalFull");
  
  // ntt_pl = GetValue("poslVR",3);
  // nw_pl = GetValue("poslVR",1);
  // nwt_pl = GetValue("poslVR",2);
  // nrest_pl = GetValue("poslVR",8);
  // sum_pl = GetValue("poslVR",0);
  // TH1F* hsn_pl = (TH1F*)f_sn->Get("sum_VRPosLoose_NominalFull");
  // hsp_pl = (TH1F*)f_sp->Get("sum_VRPosLoose_NominalFull");
  // TH1F* hda_pl = (TH1F*)f_da->Get("sum_VRPosLoose_NominalFull");
  
  // ntt_pt = GetValue("postVR",3);
  // nw_pt = GetValue("postVR",1);
  // nwt_pt = GetValue("postVR",2);
  // nrest_pt = GetValue("postVR",8);
  // sum_pt = GetValue("postVR",0);
  // TH1F* hsn_pt = (TH1F*)f_sn->Get("sum_VRPosTight_NominalFull");
  // hsp_pt = (TH1F*)f_sp->Get("sum_VRPosTight_NominalFull");
  // TH1F* hda_pt = (TH1F*)f_da->Get("sum_VRPosTight_NominalFull");
    
  // printf(" \n \n \n");
  // printf("\\hline \n");
  // printf("& VR Neg & VR Pos Loose & VR Pos Tight  \\\\ \n");
  // printf("\\hline \n");
  // printf("\\ttbar    & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", ntt_neg.at(0), (ntt_neg.at(1) + ntt_neg.at(2))/2, ntt_pl.at(0), (ntt_pl.at(1) + ntt_pl.at(2))/2,ntt_pt.at(0), (ntt_pt.at(1) + ntt_pt.at(2))/2);
  // printf("$W$+jets  & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", nw_neg.at(0), (nw_neg.at(1) + nw_neg.at(2))/2, nw_pl.at(0), (nw_pl.at(1) + nw_pl.at(2))/2,nw_pt.at(0), (nw_pt.at(1) + nw_pt.at(2))/2);
  // printf("$Wt$      & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", nwt_neg.at(0), (nwt_neg.at(1) + nwt_neg.at(2))/2, nwt_pl.at(0), (nwt_pl.at(1) + nwt_pl.at(2))/2,nwt_pt.at(0), (nwt_pt.at(1) + nwt_pt.at(2))/2);
  // printf("Other bkg & $ %4.1f \\pm %4.1f$ &  $ %4.1f \\pm %4.1f$   &  $ %4.1f \\pm %4.1f$   \\\\ \n", nrest_neg.at(0), (nrest_neg.at(1) + nrest_neg.at(2))/2, nrest_pl.at(0), (nrest_pl.at(1) + nrest_pl.at(2))/2,nrest_pt.at(0), (nrest_pt.at(1) + nrest_pt.at(2))/2);
  // printf("\\hline \n");
  // printf("Sum bkg   & $ %4.1f \\pm %4.1f$ & $ %4.1f \\pm %4.1f$    &  $ %4.1f \\pm %4.1f$   \\\\ \n", sum_neg.at(0), (sum_neg.at(1) + sum_neg.at(2))/2, sum_pl.at(0), (sum_pl.at(1) + sum_pl.at(2))/2,sum_pt.at(0), (sum_pt.at(1) + sum_pt.at(2))/2);
  // printf("Data      &  %4.0f &  %4.0f   &   %4.0f \\\\ \n", hda_neg->GetBinContent(1), hda_pl->GetBinContent(1), hda_pt->GetBinContent(1));
  // printf("VBF $WH \\lam = -1$   & $ %4.1f \\pm %4.1f$ & $ %4.1f \\pm %4.1f$    &  $ %4.1f \\pm %4.1f$   \\\\ \n", hsn_neg->GetBinContent(1), hsn_neg->GetBinError(1), hsn_pl->GetBinContent(1), hsn_pl->GetBinError(1), hsn_pt->GetBinContent(1), hsn_pt->GetBinError(1));
  // printf("VBF $WH \\lam = +1$   & $ %4.1f \\pm %4.1f$ & $ %4.1f \\pm %4.1f$    &  $ %4.1f \\pm %4.1f$   \\\\ \n", hsp_neg->GetBinContent(1), hsp_neg->GetBinError(1), hsp_pl->GetBinContent(1), hsp_pl->GetBinError(1), hsp_pt->GetBinContent(1), hsp_pt->GetBinError(1));
  // printf("\\hline \n");

  // printf("\\hline \n");

  
  //detector systematics
  vector<double> posl = GetFactors("poslSplusB");
  vector<double> post = GetFactors("postSplusB");

  vector<float> sysn = GetDetectorSysts("", false);
  vector<float> sysl = GetDetectorSysts("poslSplusB", false);
  vector<float> syst = GetDetectorSysts("postSplusB", false);
  
  printf(" \n \n \n");
  printf("\\hline \n");
  printf("& SR Neg & SR Pos Loose & SR Pos Tight  \\\\ \n");
  printf("\\hline \n");
  printf(" SM Prediction  & %3.1f & %3.1f & %3.2f \\\\ \n", sum_neg.at(0), posl.at(0), post.at(0));
  printf("\\hline \n");	  
  printf(" $b$-tagging     & $ \\pm %3.1f $ & $ \\pm %3.1f $ & $ \\pm %3.2f $ \\\\ \n", sysn.at(0), sysl.at(0), syst.at(0));
  printf(" $c$-tagging     & $ \\pm %3.1f $ & $ \\pm %3.1f $ & $ \\pm %3.2f $ \\\\ \n", sysn.at(1), sysl.at(1), syst.at(1));
  printf(" light-tagging   & $ \\pm %3.1f $ & $ \\pm %3.1f $ & $ \\pm %3.2f $ \\\\ \n", sysn.at(2), sysl.at(2), syst.at(2));
  printf(" JES             &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(3), sysn.at(4), sysl.at(3), sysl.at(4), syst.at(3), syst.at(4));
  printf(" JER             &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(5), sysn.at(6), sysl.at(5), sysl.at(6), syst.at(5), syst.at(6));
  printf(" JVT             &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(7), sysn.at(8), sysl.at(7), sysl.at(8), syst.at(7), syst.at(8));
  printf(" \\met           &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(9), sysn.at(10), sysl.at(9), sysl.at(10), syst.at(9), syst.at(10));
  printf(" Electrons       &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(11), sysn.at(12), sysl.at(11), sysl.at(12), syst.at(11), syst.at(12));
  printf(" Muons           &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(13), sysn.at(14), sysl.at(13), sysl.at(14), syst.at(13), syst.at(14));
  printf(" Taus            &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(15), sysn.at(16), sysl.at(15), sysl.at(16), syst.at(15), syst.at(16));
  printf(" Pileup Reweight & $ \\pm %3.2f $ & $ \\pm %3.1f $ & $ \\pm %3.2f $ \\\\ \n", fabs(sysn.at(17)), fabs(sysl.at(17)), fabs(syst.at(17)));
  printf(" Luminosity      & $ \\pm %3.2f $ & $ \\pm %3.2f $ & $ \\pm %3.2f $ \\\\ \n", fabs(sysn.at(18)), fabs(sysl.at(18)), fabs(syst.at(18)));
  printf("\\hline \n");	 
  printf(" Total detector  &  +%3.1f -%3.1f  &   +%3.1f -%3.1f  &   +%3.2f -%3.2f  \\\\ \n", sysn.at(19), sysn.at(20), sysl.at(19), sysl.at(20), syst.at(19), syst.at(20));
  printf("\\hline \n");	  

  
  //signal systematics
  float sign = hsn_neg->GetBinContent(1);
  float sigl = hsp_pl->GetBinContent(1);
  float sigt = hsp_pt->GetBinContent(1);
    
  sysn = GetSigSysts("SplusB", false);
  sysl = GetSigSysts("SplusBposl", false);
  syst = GetSigSysts("SplusBpost", false);
  
  printf(" \n \n \n");
  printf("\\hline \n");
  printf("& \\multicolumn{2}{c|}{SR Neg} & \\multicolumn{2}{c|}{SR Pos Loose} & \\multicolumn{2}{c|}{SR Pos Tight}  \\\\ \n");
  printf("\\hline \n");
  printf(" $\\mu_{\\mathrm{R}}, \\mu_{\\mathrm{F}}$ &  %+4.1f & %+4.1f  &  %+4.1f & %+4.1f  &  %+4.1f & %+4.1f \\\\ \n", 100*sysn.at(0)/sign, 100*sysn.at(1)/sign, 100*sysl.at(0)/sigl, 100*sysl.at(1)/sigl, 100*syst.at(0)/sigt, 100*syst.at(1)/sigt);
  printf(" PDF                                      &  %+4.1f & %+4.1f  &  %+4.1f & %+4.1f  &  %+4.1f & %+4.1f \\\\ \n", 100*sysn.at(2)/sign, 100*sysn.at(3)/sign, 100*sysl.at(2)/sigl, 100*sysl.at(3)/sigl, 100*syst.at(2)/sigt, 100*syst.at(3)/sigt);
  printf(" $\\alpha_{\\mathrm{S}}$                  &  %+4.1f & %+4.1f  &  %+4.1f & %+4.1f  &  %+4.1f & %+4.1f \\\\ \n", 100*sysn.at(4)/sign, 100*sysn.at(5)/sign, 100*sysl.at(4)/sigl, 100*sysl.at(5)/sigl, 100*syst.at(4)/sigt, 100*syst.at(5)/sigt);
  printf(" Additional jet modelling & \\multicolumn{2}{c|}{--} & \\multicolumn{2}{c|}{%4.1f} & \\multicolumn{2}{c|}{%4.1f} \\\\ \n", 100*sysl.at(6)/sigl, 100*syst.at(6)/sigt);
  printf("\\hline \n");
  printf(" Total                                    &  %+4.1f & -%4.1f  &  %+4.1f & -%4.1f  &  %+4.1f & -%4.1f \\\\ \n", 100*sysn.at(7)/sign, 100*sysn.at(8)/sign, 100*sysl.at(7)/sigl, 100*sysl.at(8)/sigl, 100*syst.at(7)/sigt, 100*syst.at(8)/sigt);
  printf("\\hline \n");


  //background theory systs
  sysn = GetBackgroundSysts("", false);
  sysl = GetBackgroundSysts("posl", false);
  syst = GetBackgroundSysts("post", false);
  
  printf(" \n \n \n");
  printf("\\hline \n");
  printf("& SR Neg & SR Pos Loose & SR Pos Tight  \\\\ \n");
  printf("\\hline \n");
  printf(" SM Prediction  & %4.2f & %4.2f & %4.2f \\\\ \n", sum_neg.at(0), posl.at(0), post.at(0));
  printf("\\hline \n");	  
  if(sysl.at(0)*syst.at(0) > 0) printf(" \\ttbar Generator   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(0)), fabs(sysl.at(0)), fabs(syst.at(0)));
  else printf(" \\ttbar Generator   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(0)), fabs(sysl.at(0)), fabs(syst.at(0)));
  if(sysl.at(1)*syst.at(1) > 0) printf(" \\ttbar Shower      & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(1)), fabs(sysl.at(1)), fabs(syst.at(1)));
  else printf(" \\ttbar Shower      & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(1)), fabs(sysl.at(1)), fabs(syst.at(1)));
  if(sysl.at(2)*syst.at(2) > 0) printf(" $\\ttbar h_{damp}$  & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(2)), fabs(sysl.at(2)), fabs(syst.at(2)));
  else printf(" $\\ttbar h_{damp}$   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(2)), fabs(sysl.at(2)), fabs(syst.at(2)));
  printf(" \\ttbar ISR $\\alpha_S$   &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(4), sysn.at(3), sysl.at(4), sysl.at(3), syst.at(4), syst.at(3));
  printf(" $\\ttbar \\mu_R$          &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(6), sysn.at(5), sysl.at(6), sysl.at(5), syst.at(6), syst.at(5));
  printf(" $\\ttbar \\mu_F$          &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(8), sysn.at(7), sysl.at(8), sysl.at(7), syst.at(8), syst.at(7));  
  if(sysl.at(9)*syst.at(9) > 0) printf(" $Wt$ Generator   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(9)), fabs(sysl.at(9)), fabs(syst.at(9)));
  else printf(" $Wt$ Generator   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(9)), fabs(sysl.at(9)), fabs(syst.at(9)));
  if(sysl.at(10)*syst.at(10) > 0) printf(" $Wt$ Shower      & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(10)), fabs(sysl.at(10)), fabs(syst.at(10)));
  else printf(" $Wt$ Shower      & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(10)), fabs(sysl.at(10)), fabs(syst.at(10)));
  printf(" $Wt$ Radiation   &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(12), sysn.at(11), sysl.at(12), sysl.at(11), syst.at(12), syst.at(11));
  if(sysl.at(13)*syst.at(13) > 0) printf(" $Wt$ DR-DS       & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(13)), fabs(sysl.at(13)), fabs(syst.at(13)));
  else printf(" $Wt$ DR-DS       & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(13)), fabs(sysl.at(13)), fabs(syst.at(13)));
  if(sysl.at(14)*syst.at(14) > 0) printf(" $W$+jets Generator/shower   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\pm$%4.2f \\\\ \n", fabs(sysn.at(14)), fabs(sysl.at(14)), fabs(syst.at(14)));
  else printf(" $W$+jets Generator/shower   & $ \\pm$%4.2f   & $ \\pm$%4.2f  & $ \\mp$%4.2f \\\\ \n", fabs(sysn.at(14)), fabs(sysl.at(14)), fabs(syst.at(14)));
  printf(" $W$+jets $\\mu_{\\mathrm{R}}, \\mu_{\\mathrm{F}}$   &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(16), -1*sysn.at(15), sysl.at(16), -1*sysl.at(15), syst.at(16), -1*syst.at(15));
  printf("\\hline \n");	  
  printf(" $Z$+jets             &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(18), -1*sysn.at(17), sysl.at(18), -1*sysl.at(17), syst.at(18), -1*syst.at(17));
  printf(" single top t-channel &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(20), -1*sysn.at(19), sysl.at(20), -1*sysl.at(19), syst.at(20), -1*syst.at(19));
  printf(" $WH$                 &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(22), -1*sysn.at(21), sysl.at(22), -1*sysl.at(21), syst.at(22), -1*syst.at(21));
  printf(" $WZ$                 &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(24), -1*sysn.at(23), sysl.at(24), -1*sysl.at(23), syst.at(24), -1*syst.at(23));
  printf(" $ttH$                &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(26), -1*sysn.at(25), sysl.at(26), -1*sysl.at(25), syst.at(26), -1*syst.at(25));
  printf(" $ZH$                 &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(28), -1*sysn.at(27), sysl.at(28), -1*sysl.at(27), syst.at(28), -1*syst.at(27));
  printf(" $ttV$                &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(30), -1*sysn.at(29), sysl.at(30), -1*sysl.at(29), syst.at(30), -1*syst.at(29));
  printf("\\hline \n");	  
  printf(" Total &  %+4.2f %+4.2f &  %+4.2f %+4.2f  &  %+4.2f %+4.2f  \\\\ \n", sysn.at(32), -1*sysn.at(31), sysl.at(32), -1*sysl.at(31), syst.at(32), -1*syst.at(31));
  printf("\\hline \n");
  
  return;
  
}

//This is for stat interpretation
float kFactors::GetMu2Bin(float N1, float N2, float B1, float B2, float S1, float S2, bool verbose = false){

  float mu = 0.0;
  float uplim = 5; float downlim = -5;

  
  while(downlim > -50 && uplim < 50){
    TF1* LLH = new TF1("LLH","[0]*TMath::Log([2]+x*[4]) + [1]*TMath::Log([3]+x*[5])-x*[4]-x*[5]",downlim,uplim);
    LLH->SetParameters(N1,N2,B1,B2,S1,S2);
    
    //LLH->Draw();
    
    mu = LLH->GetMaximumX();

    if(verbose) cout<<"Found max llh at "<<mu<<" with limits "<<downlim<<" "<<uplim<<endl;
    
    if(mu < downlim+0.1) downlim -= 1.;
    else if(mu > uplim - 0.1) uplim += 1.;
    else break;
    
  }

  return mu;

}

vector<float>* kFactors::GetPosLamMu(float Nloose, float Ntight, TString opt =  ""){

  //Start by getting default mu
  vector<double> vd_looseB = GetFactors(opt+"posl");
  vector<double> vd_tightB = GetFactors(opt+"post");
  vector<double> vd_looseS = GetFactors(opt+"SplusBposl");
  vector<double> vd_tightS = GetFactors(opt+"SplusBpost");

  float Bloose = vd_looseB.at(0);
  float Btight = vd_tightB.at(0);
  
  float Sloose = vd_looseS.at(0) - vd_looseB.at(0); //"signal" is S+B minus B -> accounts for effect of signal on bkg estimate
  float Stight = vd_tightS.at(0) - vd_tightB.at(0);
  
  float MuHat = GetMu2Bin(Nloose, Ntight, Bloose, Btight, Sloose , Stight);
  cout<<" mu Hat is "<<MuHat<<endl;

  float UpErr = 0.0;
  float DownErr = 0.0;
  
  vector<double> vd_aLoose;
  vector<double> vd_aTight;
  float MuA = 0.;

  
  vector<TString> Theorystrings = {"ttbar_aMC","ttbar_Herwig","ttbar_hdamp","Wt_aMC","Wt_Herwig","Wt_DS","W_FxFx", "stopt_Herwig"};
  vector<TString> Radstrings = {"Wt", "stopt"};
  vector<TString> Scalestrings = {"W", "Z", "WH", "WZewk", "WZqcd"};
  
  vector<TString> DDstrings = {};//{"WCRalt", "WtCRalt", "ttbarCRalt"};

  vector<TString> Statstrings = {"WCR_Posda","WtCR_Posda","ttbarCR_Posda",
			     "WCR_Postt","WtCR_Postt","ttbarCR_Postt","SRPosLoosett","SRPosTighttt",
			     "WCR_Poswt","WtCR_Poswt","ttbarCR_Poswt","SRPosLoosewt","SRPosTightwt",
			     "WCR_Poswj","WtCR_Poswj","ttbarCR_Poswj","SRPosLoosewj","SRPosTightwj",
			     "WCR_Posre","WtCR_Posre","ttbarCR_Posre","SRPosLoosere","SRPosTightre"};


  //Signal
  vector<TString> sigMUs = {"MUR2_MUF1", "MUR05_MUF1", "MUR1_MUF2", "MUR1_MUF05", "MUR2_MUF2", "MUR05_MUF05"};  
  
  float siglooseUP = Bloose+Sloose;
  float siglooseDOWN = Bloose+Sloose;
  float sigtightUP = Btight+Stight;
  float sigtightDOWN = Btight+Stight;
  
  for(int i = 0; i < sigMUs.size(); i++){
    vd_aLoose = GetFactors(opt+"poslSplusBSigSys_"+sigMUs.at(i));
    if(vd_aLoose.at(0) > siglooseUP) siglooseUP = vd_aLoose.at(0);
    if(vd_aLoose.at(0) < siglooseDOWN) siglooseDOWN = vd_aLoose.at(0);
    vd_aTight = GetFactors(opt+"postSplusBSigSys_"+sigMUs.at(i));
    if(vd_aTight.at(0) > sigtightUP) sigtightUP = vd_aTight.at(0);
    if(vd_aTight.at(0) < sigtightDOWN) sigtightDOWN = vd_aTight.at(0);
  }
  float MuAHi = GetMu2Bin(Nloose, Ntight, Bloose, Btight, siglooseUP-Bloose, sigtightUP-Btight);
  float MuALo = GetMu2Bin(Nloose, Ntight, Bloose, Btight, siglooseDOWN-Bloose, sigtightDOWN-Btight);
  if(MuAHi > MuALo){
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuAHi-MuHat)*(MuAHi-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuALo-MuHat)*(MuALo-MuHat));
  }
  else{
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuALo-MuHat)*(MuALo-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuAHi-MuHat)*(MuAHi-MuHat));
  }
  cout<<"delta mu from sig scales = "<<MuAHi - MuHat<<" "<<MuALo - MuHat<<endl;

  siglooseUP = Bloose+Sloose;
  siglooseDOWN = Bloose+Sloose;
  sigtightUP = Btight+Stight;
  sigtightDOWN = Btight+Stight;  
  
  for(int p = 260001; p < 260100; p++){
    stringstream ss;
    ss<<p;
    TString pStr = "PDF"+ss.str();
    vd_aLoose = GetFactors(opt+"poslSplusBSigSys_"+pStr);
    if(vd_aLoose.at(0) > siglooseUP) siglooseUP = vd_aLoose.at(0);
    if(vd_aLoose.at(0) < siglooseDOWN) siglooseDOWN = vd_aLoose.at(0);
    vd_aLoose = GetFactors(opt+"postSplusBSigSys_"+pStr);
    if(vd_aTight.at(0) > sigtightUP) sigtightUP = vd_aTight.at(0);
    if(vd_aTight.at(0) < sigtightDOWN) sigtightDOWN = vd_aTight.at(0);
  }
  MuAHi = GetMu2Bin(Nloose, Ntight, Bloose, Btight, siglooseUP-Bloose, sigtightUP-Btight);
  MuALo = GetMu2Bin(Nloose, Ntight, Bloose, Btight, siglooseDOWN-Bloose, sigtightDOWN-Btight);
  if(MuAHi > MuALo){
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuAHi-MuHat)*(MuAHi-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuALo-MuHat)*(MuALo-MuHat));
  }
  else{
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuALo-MuHat)*(MuALo-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuAHi-MuHat)*(MuAHi-MuHat));
  }
  cout<<"delta mu from sig PDF = "<<MuAHi - MuHat<<" "<<MuALo - MuHat<<endl;

  //sig ckkw syst
  vd_aLoose = GetFactors(opt+"poslSplusBCKKW");
  vd_aTight = GetFactors(opt+"postSplusBCKKW");
  MuA = GetMu2Bin(Nloose, Ntight, Bloose, Btight, vd_aLoose.at(0)-Bloose, vd_aTight.at(0)-Btight);
  cout<<"delta mu with CKKW = "<<MuA - MuHat<<endl;
  if(MuA > MuHat) UpErr = TMath::Sqrt( UpErr*UpErr + (MuA-MuHat)*(MuA-MuHat));
  else DownErr = TMath::Sqrt( DownErr*DownErr + (MuA-MuHat)*(MuA-MuHat));
  
  
  for(int s = 0; s < Theorystrings.size(); s++){
    vd_aLoose = GetFactors(opt+"posl"+Theorystrings.at(s));
    vd_aTight = GetFactors(opt+"post"+Theorystrings.at(s));
    MuA = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    cout<<"delta mu with "<<Theorystrings.at(s)<<" = "<<MuA - MuHat<<endl;
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuA-MuHat)*(MuA-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuA-MuHat)*(MuA-MuHat));
  }

  vector<TString> ttISR = {"Var3c","MUR","MUF"};
  for(int s = 0; s < ttISR.size(); s++){    
    vector<double> vd_aLooseHi = GetFactors(opt+"poslttbar_"+ttISR.at(s)+"up");
    vector<double> vd_aTightHi = GetFactors(opt+"postttbar_"+ttISR.at(s)+"up");
    MuAHi = GetMu2Bin(Nloose, Ntight, vd_aLooseHi.at(0), vd_aTightHi.at(0), Sloose, Stight);
    vector<double> vd_aLooseLo = GetFactors(opt+"poslttbar_"+ttISR.at(s)+"down");
    vector<double> vd_aTightLo = GetFactors(opt+"postttbar_"+ttISR.at(s)+"down");
    MuALo = GetMu2Bin(Nloose, Ntight, vd_aLooseLo.at(0), vd_aTightLo.at(0), Sloose, Stight);
    if(MuAHi > MuALo){
      UpErr = TMath::Sqrt( UpErr*UpErr + (MuAHi-MuHat)*(MuAHi-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MuALo-MuHat)*(MuALo-MuHat));
    }
    else{
      UpErr = TMath::Sqrt( UpErr*UpErr + (MuALo-MuHat)*(MuALo-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MuAHi-MuHat)*(MuAHi-MuHat));
    }
    cout<<"delta mu with ttbar "<<ttISR.at(s)<<" = "<<MuAHi - MuHat<<" "<<MuALo - MuHat<<endl;
  }
  
  //Radhi, radlo for single top samples
  for(int s = 0; s < Radstrings.size(); s++){    
    vector<double> vd_aLooseHi = GetFactors(opt+"posl"+Radstrings.at(s)+"_RadHi");
    vector<double> vd_aTightHi = GetFactors(opt+"post"+Radstrings.at(s)+"_RadHi");
    MuAHi = GetMu2Bin(Nloose, Ntight, vd_aLooseHi.at(0), vd_aTightHi.at(0), Sloose, Stight);
    vector<double> vd_aLooseLo = GetFactors(opt+"posl"+Radstrings.at(s)+"_RadLo");
    vector<double> vd_aTightLo = GetFactors(opt+"post"+Radstrings.at(s)+"_RadLo");
    MuALo = GetMu2Bin(Nloose, Ntight, vd_aLooseLo.at(0), vd_aTightLo.at(0), Sloose, Stight);
    if(MuAHi > MuALo){
      UpErr = TMath::Sqrt( UpErr*UpErr + (MuAHi-MuHat)*(MuAHi-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MuALo-MuHat)*(MuALo-MuHat));
    }
    else{
      UpErr = TMath::Sqrt( UpErr*UpErr + (MuALo-MuHat)*(MuALo-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MuAHi-MuHat)*(MuAHi-MuHat));
    }
    cout<<"delta mu with "<<Radstrings.at(s)<<" Rad = "<<MuAHi - MuHat<<" "<<MuALo - MuHat<<endl;
  }

  //W scales
  vector<TString> MUs = {"MUR", "MUF", "MURMUF"};

  for(int s = 0; s < Scalestrings.size(); s++){    
    float scalelooseUP = Bloose;
    float scaletightUP = Btight;
    float scalelooseDOWN = Bloose;
    float scaletightDOWN = Btight;  
    
    for(int i = 0; i < MUs.size(); i++){
      vd_aLoose = GetFactors(opt+"posl"+Scalestrings.at(s)+"_"+MUs.at(i)+"up");
      if(vd_aLoose.at(0) > scalelooseUP) scalelooseUP = vd_aLoose.at(0);
      if(vd_aLoose.at(0) < scalelooseDOWN) scalelooseDOWN = vd_aLoose.at(0);
      vd_aLoose = GetFactors(opt+"posl"+Scalestrings.at(s)+"_"+MUs.at(i)+"down");
      if(vd_aLoose.at(0) > scalelooseUP) scalelooseUP = vd_aLoose.at(0);
      if(vd_aLoose.at(0) < scalelooseDOWN) scalelooseDOWN = vd_aLoose.at(0);
      vd_aTight = GetFactors(opt+"post"+Scalestrings.at(s)+"_"+MUs.at(i)+"up");
      if(vd_aTight.at(0) > scaletightUP) scaletightUP = vd_aTight.at(0);
      if(vd_aTight.at(0) < scaletightDOWN) scaletightDOWN = vd_aTight.at(0);
      vd_aTight = GetFactors(opt+"post"+Scalestrings.at(s)+"_"+MUs.at(i)+"down");
      if(vd_aTight.at(0) > scaletightUP) scaletightUP = vd_aTight.at(0);
      if(vd_aTight.at(0) < scaletightDOWN) scaletightDOWN = vd_aTight.at(0);
    }
    
    MuAHi = GetMu2Bin(Nloose, Ntight, scalelooseUP, scaletightUP, Sloose, Stight);
    MuALo = GetMu2Bin(Nloose, Ntight, scalelooseDOWN, scaletightDOWN, Sloose, Stight);
    if(MuAHi > MuALo){
      UpErr = TMath::Sqrt( UpErr*UpErr + (MuAHi-MuHat)*(MuAHi-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MuALo-MuHat)*(MuALo-MuHat));
    }
    else{
      UpErr = TMath::Sqrt( UpErr*UpErr + (MuALo-MuHat)*(MuALo-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MuAHi-MuHat)*(MuAHi-MuHat));
    }
    cout<<"delta mu with "<<Scalestrings.at(s)<<" scales = "<<MuAHi - MuHat<<" "<<MuALo - MuHat<<endl;
  }

  //
  //Detector systematics. Flavor and others have different string formats
  for(int s = 0; s < FlavVars.size(); s++){
    vd_aLoose = GetFactors(opt+"posl"+FlavVars.at(s));
    vd_aTight = GetFactors(opt+"post"+FlavVars.at(s));
    MuA = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    cout<<"delta mu with "<<FlavVars.at(s)<<" = "<<MuA - MuHat<<endl;
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuA-MuHat)*(MuA-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuA-MuHat)*(MuA-MuHat));
  }

  for(int s = 0; s < DetVars.size(); s++){
    vd_aLoose = GetFactors(opt+"posl"+DetVars.at(s)+"__1up");
    vd_aTight = GetFactors(opt+"post"+DetVars.at(s)+"__1up");
    float MuAUP = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    float MuADOWN = -1*MuAUP;
    if(!(DetVars.at(s).Contains("SoftTrk_Reso"))){
      vd_aLoose = GetFactors(opt+"posl"+DetVars.at(s)+"__1down");
      vd_aTight = GetFactors(opt+"post"+DetVars.at(s)+"__1down");
      MuADOWN = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    }
    float MaxMu = TMath::Max(MuAUP, MuADOWN);
    float MinMu = TMath::Min(MuAUP, MuADOWN);
    if(MuAUP > MuHat && MuADOWN > MuHat) UpErr = TMath::Sqrt( UpErr*UpErr + (MaxMu-MuHat)*(MaxMu-MuHat));
    else if(MuAUP < MuHat && MuADOWN < MuHat) DownErr = TMath::Sqrt( DownErr*DownErr + (MinMu-MuHat)*(MinMu-MuHat));
    else{
      UpErr = TMath::Sqrt( UpErr*UpErr + (MaxMu-MuHat)*(MaxMu-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MinMu-MuHat)*(MinMu-MuHat));
    }          
    cout<<"delta mu with "<<DetVars.at(s)<<" = "<<MuAUP - MuHat<<" "<<MuADOWN - MuHat<<endl;
  }

  for(int s = 0; s < DDstrings.size(); s++){
    vd_aLoose = GetFactors(opt+"posl"+DDstrings.at(s));
    vd_aTight = GetFactors(opt+"post"+DDstrings.at(s));
    MuA = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    cout<<"delta mu with "<<DDstrings.at(s)<<" = "<<MuA - MuHat<<endl;
    UpErr = TMath::Sqrt( UpErr*UpErr + (MuA-MuHat)*(MuA-MuHat));
    DownErr = TMath::Sqrt( DownErr*DownErr + (MuA-MuHat)*(MuA-MuHat)); 
  }
  
  for(int s = 0; s < Statstrings.size(); s++){
    vd_aLoose = GetFactors(opt+"posl"+Statstrings.at(s)+"UP");
    vd_aTight = GetFactors(opt+"post"+Statstrings.at(s)+"UP");
    float MuAUP = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    vd_aLoose = GetFactors(opt+"posl"+Statstrings.at(s)+"DOWN");
    vd_aTight = GetFactors(opt+"post"+Statstrings.at(s)+"DOWN");
    float MuADOWN = GetMu2Bin(Nloose, Ntight, vd_aLoose.at(0), vd_aTight.at(0), Sloose, Stight);
    float MaxMu = TMath::Max(MuAUP, MuADOWN);
    float MinMu = TMath::Min(MuAUP, MuADOWN);
    if(MuAUP > MuHat && MuADOWN > MuHat) UpErr = TMath::Sqrt( UpErr*UpErr + (MaxMu-MuHat)*(MaxMu-MuHat));
    else if(MuAUP < MuHat && MuADOWN < MuHat) DownErr = TMath::Sqrt( DownErr*DownErr + (MinMu-MuHat)*(MinMu-MuHat));
    else{
      UpErr = TMath::Sqrt( UpErr*UpErr + (MaxMu-MuHat)*(MaxMu-MuHat));
      DownErr = TMath::Sqrt( DownErr*DownErr + (MinMu-MuHat)*(MinMu-MuHat));
    }          
    cout<<"delta mu with "<<Statstrings.at(s)<<" = "<<MuAUP - MuHat<<" "<<MuADOWN - MuHat<<endl;
  }

  cout<<"Mu = "<<MuHat<<" +"<<UpErr<<" -"<<DownErr<<endl;  

  vector<float>* vf = new vector<float>();
  vf->push_back(MuHat); vf->push_back(UpErr); vf->push_back(DownErr);
  return vf;
  
}



float kFactors::GetMuUpperLimit(float N1, float N2, float B1, float B2, float S1, float S2, float SystUp, float SystDown, bool verbose){

  float muObs = GetMu2Bin(N1, N2, B1, B2, S1, S2);
  if(verbose) cout<<"muObs = "<<muObs<<endl;

  TF1* sysLo;
  TF1* sysHi;
  if(SystUp > 0){
    sysLo = new TF1("sysLo","0.5*TMath::Gaus(x,[0],[1],true)",-30,0);
    sysLo->SetParameters(muObs, SystDown);
    sysHi = new TF1("sysHi","0.5*TMath::Gaus(x,[0],[1],true)",0,30);
    sysHi->SetParameters(muObs, SystUp);
    //sys = sysLo + sysHi;
  }

  if(verbose){
    TCanvas* c1 = new TCanvas();
    sysLo->Draw();
    sysHi->Draw("same");
  }
    
  // upper limit
  //Want the mu such that 95% of the time we would have gotten a higher muObs if it were true
  //Divide by the likelihood for B-only due to CLs

  //first, loop over possible n1, n2; keep those that would give a lower muObs:
  vector<vector<bool>* >* isLower = new vector<vector<bool>* >();

  for(int n1 = 0; n1 < N1+10*TMath::Sqrt(N1); n1++){
    vector<bool>* tvec = new vector<bool>();
    tvec->assign(TMath::Floor(N2+10*TMath::Sqrt(N2))+1, false);
    isLower->push_back(tvec);
    for(int n2 = 0; n2 < N2+10*TMath::Sqrt(N2); n2++){
      isLower->at(n1)->at(n2) = false;
      if( GetMu2Bin(n1, n2, B1, B2, S1, S2) < muObs ) isLower->at(n1)->at(n2) = true;
      else break;
    }
  }

  //Build the stat likelihood as a function of mu
  TGraph* P = new TGraph();
  for(int i = -140; i < 300; i++){
    float muTest = i/10.;

    float pCond = 0.;
    
    for(int n1 = 0; n1 < N1+10*TMath::Sqrt(N1); n1++){
      for(int n2 = 0; n2 < N2+10*TMath::Sqrt(N2); n2++){

	if(isLower->at(n1)->at(n2)){
	  float test1 = TMath::Max(0.1, (double)(B1+muTest*S1));
	  float test2 = TMath::Max(0.01, (double)(B2+muTest*S2));
	  float prob = TMath::Poisson(n1, test1)*TMath::Poisson(n2, test2);
	  pCond += prob;
	}
	else break;
	
      }
    }

    if(verbose) cout<<"Setting point in P "<<muTest<<", "<<pCond<<endl;
    P->SetPoint( P->GetN(), muTest, pCond );
    
  }

  if(verbose){
    TCanvas* c2 = new TCanvas();
    P->Draw("APL");
  }

  //get bkg only CL for CLs calculation
  float pZero = 0;
  for(int i = 0; i < P->GetN(); i++){
    pZero += 0.1*P->GetPointY(i)*sysLo->Eval( 0 - P->GetPointX(i) );
    pZero += 0.1*P->GetPointY(i)*sysHi->Eval( 0 - P->GetPointX(i) );
  }
  if(verbose) cout<<"pZero = "<<pZero<<endl;
  
  //Now find the mu that has CLs < 0.05
  float muUp = muObs - 5;

  TGraph* Conv = new TGraph();

  float upperLimit = 0.0;
  
  for(;;){
  
    float intmu = 0;
    for(int i = 0; i < P->GetN(); i++){
      intmu += 0.1*P->GetPointY(i)*sysLo->Eval( muUp - P->GetPointX(i) );
      intmu += 0.1*P->GetPointY(i)*sysHi->Eval( muUp - P->GetPointX(i) );
    }
    Conv->SetPoint( Conv->GetN(), muUp, intmu );
    
    if(intmu/pZero < 0.05 && upperLimit < 0.1){
      upperLimit = muUp;
      if(!verbose) break;
    }
    if(muUp > 30 && verbose) break; 

    if(intmu/pZero > 0.2) muUp += 0.1;
    else if(intmu/pZero > 0.1 || intmu/pZero < 0.05) muUp += 0.1;
    muUp += 0.01;
    
  }

  Conv->SetMarkerColor(kRed);
  Conv->SetLineColor( Conv->GetMarkerColor() );
  if(verbose) Conv->Draw("PLsame");
  
  if(verbose) cout<<"Bin 1: "<<N1<<" obs, "<<B1<<" bkg, "<<S1<<" sig"<<endl;
  if(verbose) cout<<"Bin 2: "<<N2<<" obs, "<<B2<<" bkg, "<<S2<<" sig"<<endl;
  if(verbose) cout<<"Best fit mu = "<<muObs<<endl;
  if(verbose) cout<<"95% upper limit CLs on mu = "<<upperLimit<<endl;

  //delete isLower;
  return upperLimit;
  
}

pair<float,float> kFactors::GetMuErrors(float N1, float N2, float B1, float B2, float S1, float S2, bool verbose){

  float muObs = GetMu2Bin(N1, N2, B1, B2, S1, S2);

  float muUp = muObs + 0.01;
  float muDown = muObs - 0.01; 


  //first, loop over possible n1, n2; keep those that would give a lower muObs:
  vector<vector<bool> >* isLower = new vector<vector<bool> >();
    
  for(int n1 = 0; n1 < N1+10*TMath::Sqrt(N1); n1++){
    vector<bool> tvec;
    tvec.assign(TMath::Floor(N2+10*TMath::Sqrt(N2)+1), false);
    isLower->push_back(tvec);
    for(int n2 = 0; n2 < N2+10*TMath::Sqrt(N2); n2++){
      isLower->at(n1).at(n2) = false;
      if( GetMu2Bin(n1, n2, B1, B2, S1, S2) < muObs ) isLower->at(n1).at(n2) = true;
      else break;
    }
  }
  
  for(;;){
  
    float pCond = 0.;
    
    for(int n1 = 0; n1 < N1+10*TMath::Sqrt(N1); n1++){
      for(int n2 = 0; n2 < N2+10*TMath::Sqrt(N2); n2++){

	float prob = TMath::Poisson(n1, B1+muUp*S1)*TMath::Poisson(n2, B2+muUp*S2);
	
	if(isLower->at(n1).at(n2)) pCond += prob;
	else break;
	
      }
    }

    if(verbose) cout<<"For muUp "<<muUp<<", pCond = "<<pCond<<endl;
    
    if(pCond < 0.158655) break;
    if(pCond > 0.3) muUp += 0.4;
    else if(pCond > 0.2) muUp += 0.2;
    else if(pCond > 0.17) muUp += 0.05;
    else  muUp += 0.02;
    
  }

  for(;;){
  
    float pCond = 0.;
    
    for(int n1 = N1+10*TMath::Sqrt(N1)-1; n1 > 0; n1--){
      for(int n2 = N2+10*TMath::Sqrt(N2)-1; n2 > 0; n2--){

	float prob = TMath::Poisson(n1, B1+muDown*S1)*TMath::Poisson(n2, B2+muDown*S2);
		
	if(!isLower->at(n1).at(n2)) pCond += prob;
	else break;
	
      }
    }

    if(verbose) cout<<"For muDown "<<muDown<<", pCond = "<<pCond<<endl;
    
    if(pCond < 0.158655) break;
    if(pCond > 0.3) muDown -= 0.4;
    else if(pCond > 0.2) muDown -= 0.2;
    else if(pCond > 0.17) muDown -= 0.05;
    else muDown -= 0.02;
    
  }

  cout<<"Bin 1: "<<N1<<" obs, "<<B1<<" bkg, "<<S1<<" sig"<<endl;
  cout<<"Bin 2: "<<N2<<" obs, "<<B2<<" bkg, "<<S2<<" sig"<<endl;
  cout<<"Best fit mu = "<<muObs<<" +"<<muUp-muObs<<" -"<<muObs-muDown<<endl;
  
  
  return make_pair(muUp-muObs, muObs-muDown);
  
}


vector<TH1F*> kFactors::ThrowToys(int nToys){

  vector<pair<float, float> >* LooseVariations = new vector<pair<float, float> >();
  vector<pair<float, float> >* TightVariations = new vector<pair<float, float> >();
  
  vector<TString> Theorystrings = {"ttbar_aMC","ttbar_Herwig","Wt_aMC","Wt_Herwig","Wt_DS","W_FxFx", "stopt_Herwig"};
  vector<TString> Radstrings = {"ttbar", "Wt", "stopt"};
  vector<TString> Scalestrings = {"W", "Z", "WH", "WZewk", "WZqcd"};

  vector<TString> DDstrings = {};//{"WCRalt", "WtCRalt","ttbarCRalt"};

  vector<TString> Statstrings = {"WCR_Posda","WtCR_Posda","ttbarCR_Posda",
			     "WCR_Postt","WtCR_Postt","ttbarCR_Postt","SRPosLoosett","SRPosTighttt",
			     "WCR_Poswt","WtCR_Poswt","ttbarCR_Poswt","SRPosLoosewt","SRPosTightwt",
			     "WCR_Poswj","WtCR_Poswj","ttbarCR_Poswj","SRPosLoosewj","SRPosTightwj",
			     "WCR_Posre","WtCR_Posre","ttbarCR_Posre","SRPosLoosere","SRPosTightre"};


  vector<double> vd_loose = GetFactors("posl");
  vector<double> vd_tight = GetFactors("post");
  vector<double> vd_looseS = GetFactors("SplusBposl");
  vector<double> vd_tightS = GetFactors("SplusBpost");  
  float Bloose = vd_loose.at(0);
  float Btight = vd_tight.at(0);
  float Sloose = vd_looseS.at(0) - vd_loose.at(0);
  float Stight = vd_tightS.at(0) - vd_tight.at(0);

  vector<double> vd_aLoose;
  vector<double> vd_aTight;
  
  for(int s = 0; s < Theorystrings.size(); s++){
    vd_aLoose = GetFactors("posl"+Theorystrings.at(s));
    vd_aTight = GetFactors("post"+Theorystrings.at(s));
    LooseVariations->push_back( make_pair(-1*fabs(vd_aLoose.at(0)-Bloose), fabs(vd_aLoose.at(0)-Bloose) ) );
    TightVariations->push_back( make_pair(-1*fabs(vd_aTight.at(0)-Btight), fabs(vd_aTight.at(0)-Btight) ) );
  }

  //Special treatment for radhi, radlo
  for(int s = 0; s < Radstrings.size(); s++){
    vector<double> vd_aLooseHi = GetFactors("posl"+Radstrings.at(s)+"_RadHi");
    vector<double> vd_aTightHi = GetFactors("post"+Radstrings.at(s)+"_RadHi");
    vector<double> vd_aLooseLo = GetFactors("posl"+Radstrings.at(s)+"_RadLo");
    vector<double> vd_aTightLo = GetFactors("post"+Radstrings.at(s)+"_RadLo");
    if(vd_aLooseHi.at(0) > vd_aLooseLo.at(0)) LooseVariations->push_back( make_pair(TMath::Min( vd_aLooseLo.at(0) - Bloose, 0.), TMath::Max( vd_aLooseHi.at(0) - Bloose, 0.)) );
    else LooseVariations->push_back( make_pair(TMath::Min( vd_aLooseHi.at(0) - Bloose, 0.), TMath::Max( vd_aLooseLo.at(0) - Bloose, 0.)) );
    if(vd_aTightHi.at(0) > vd_aTightLo.at(0)) TightVariations->push_back( make_pair(TMath::Min( vd_aTightLo.at(0) - Btight, 0.), TMath::Max( vd_aTightHi.at(0) - Btight, 0.)) );
    else TightVariations->push_back( make_pair(TMath::Min( vd_aTightHi.at(0) - Btight, 0.), TMath::Max( vd_aTightLo.at(0) - Btight, 0.)) );
  }

  //7-point scales
  for(int s = 0; s < Scalestrings.size(); s++){
    float scaleloosUP = Bloose;
    float scaletightUP = Btight;
    float scaleloosDOWN = Bloose;
    float scaletightDOWN = Btight;  
    vector<TString> MUs = {"MUR", "MUF", "MURMUF"};
    
    for(int i = 0; i < MUs.size(); i++){
      vd_aLoose = GetFactors("posl"+Scalestrings.at(s)+"_"+MUs.at(i)+"up");
      if(vd_aLoose.at(0) > scaleloosUP) scaleloosUP = vd_aLoose.at(0);
      if(vd_aLoose.at(0) < scaleloosDOWN) scaleloosDOWN = vd_aLoose.at(0);
      vd_aLoose = GetFactors("posl"+Scalestrings.at(s)+"_"+MUs.at(i)+"down");
      if(vd_aLoose.at(0) > scaleloosUP) scaleloosUP = vd_aLoose.at(0);
      if(vd_aLoose.at(0) < scaleloosDOWN) scaleloosDOWN = vd_aLoose.at(0);
      vd_aTight = GetFactors("post"+Scalestrings.at(s)+"_"+MUs.at(i)+"up");
      if(vd_aTight.at(0) > scaletightUP) scaletightUP = vd_aTight.at(0);
      if(vd_aTight.at(0) < scaletightDOWN) scaletightDOWN = vd_aTight.at(0);
      vd_aTight = GetFactors("post"+Scalestrings.at(s)+"_"+MUs.at(i)+"down");
      if(vd_aTight.at(0) > scaletightUP) scaletightUP = vd_aTight.at(0);
      if(vd_aTight.at(0) < scaletightDOWN) scaletightDOWN = vd_aTight.at(0);
    }
    LooseVariations->push_back( make_pair(scaleloosDOWN-Bloose, scaleloosUP-Bloose));
    TightVariations->push_back( make_pair(scaletightDOWN-Btight, scaletightUP-Btight));
  }
  
  for(int s = 0; s < FlavVars.size(); s++){
    vd_aLoose = GetFactors("posl"+FlavVars.at(s));
    vd_aTight = GetFactors("post"+FlavVars.at(s));
    LooseVariations->push_back( make_pair(-1*fabs(vd_aLoose.at(0)-Bloose), fabs(vd_aLoose.at(0)-Bloose) ) );
    TightVariations->push_back( make_pair(-1*fabs(vd_aTight.at(0)-Btight), fabs(vd_aTight.at(0)-Btight) ) );
  }

  for(int s = 0; s < DetVars.size(); s++){
    vd_aLoose = GetFactors("posl"+DetVars.at(s)+"__1up");
    vd_aTight = GetFactors("post"+DetVars.at(s)+"__1up");
    float BlooseUP = vd_aLoose.at(0);
    float BtightUP = vd_aTight.at(0);
    if(!(DetVars.at(s).Contains("SoftTrk_Reso"))){      
      vd_aLoose = GetFactors("posl"+DetVars.at(s)+"__1down");
      vd_aTight = GetFactors("post"+DetVars.at(s)+"__1down");
    }
    float BlooseDOWN = vd_aLoose.at(0);
    float BtightDOWN = vd_aTight.at(0);

    float MaxLoose = TMath::Max(BlooseUP, BlooseDOWN);
    float MinLoose = TMath::Min(BlooseUP, BlooseDOWN);
    float MaxTight = TMath::Max(BtightUP, BtightDOWN);
    float MinTight = TMath::Min(BtightUP, BtightDOWN);

    if(MinLoose > Bloose) LooseVariations->push_back( make_pair(0, MaxLoose-Bloose) );
    else if(MaxLoose < Bloose) LooseVariations->push_back( make_pair(MinLoose-Bloose, 0.) );
    else LooseVariations->push_back(make_pair(MinLoose-Bloose, MaxLoose-Bloose) );
    if(MinTight > Btight) TightVariations->push_back( make_pair(0, MaxTight-Btight) );
    else if(MaxTight < Btight) TightVariations->push_back( make_pair(MinTight-Btight, 0.) );
    else TightVariations->push_back(make_pair(MinTight-Btight, MaxTight-Btight) );
  }

  for(int s = 0; s < DDstrings.size(); s++){
    vd_aLoose = GetFactors("posl"+DDstrings.at(s));
    vd_aTight = GetFactors("post"+DDstrings.at(s));
    LooseVariations->push_back( make_pair( -1*fabs(vd_aLoose.at(0)-Bloose), fabs(vd_aLoose.at(0)-Bloose) ) ); //symmetrized
    TightVariations->push_back( make_pair( -1*fabs(vd_aTight.at(0)-Btight), fabs(vd_aTight.at(0)-Btight) ) );
  }

  for(int s = 0; s < Statstrings.size(); s++){
    vd_aLoose = GetFactors("posl"+Statstrings.at(s)+"UP");
    vd_aTight = GetFactors("post"+Statstrings.at(s)+"UP");
    float BlooseUP = vd_aLoose.at(0);
    float BtightUP = vd_aTight.at(0);
    vd_aLoose = GetFactors("posl"+Statstrings.at(s)+"DOWN");
    vd_aTight = GetFactors("post"+Statstrings.at(s)+"DOWN");
    float BlooseDOWN = vd_aLoose.at(0);
    float BtightDOWN = vd_aTight.at(0);

    float MaxLoose = TMath::Max(BlooseUP, BlooseDOWN);
    float MinLoose = TMath::Min(BlooseUP, BlooseDOWN);
    float MaxTight = TMath::Max(BtightUP, BtightDOWN);
    float MinTight = TMath::Min(BtightUP, BtightDOWN);
    
    if(MinLoose > Bloose) LooseVariations->push_back( make_pair(0, MaxLoose-Bloose) );
    else if(MaxLoose < Bloose) LooseVariations->push_back( make_pair(MinLoose-Bloose, 0.) );
    else LooseVariations->push_back(make_pair(MinLoose-Bloose, MaxLoose-Bloose) );
    if(MinTight > Btight) TightVariations->push_back( make_pair(0, MaxTight-Btight) );
    else if(MaxTight < Btight) TightVariations->push_back( make_pair(MinTight-Btight, 0.) );
    else TightVariations->push_back(make_pair(MinTight-Btight, MaxTight-Btight) );
  }

  
  //Now loop over variations, change the prediction based on a random number.
  vector<float>* Central = GetPosLamMu(Bloose, Btight);
  cout<<endl<<"Start with Bloose = "<<Bloose<<", Btight = "<<Btight<<"; Sloose = "<<Sloose<<", Stight = "<<Stight<<endl;
  cout<<" expected mu = "<<Central->at(0)<<" +"<<Central->at(1)<<" -"<<Central->at(2)<<" (syst)"<<endl;
  cout<<" upper limit = "<<GetMuUpperLimit( Bloose, Btight, Bloose, Btight, Sloose, Stight, Central->at(1), Central->at(2), false)<<endl;
  
  TH1F* h_LooseExp = new TH1F("LooseExp","LooseExp",50,200,400);
  TH1F* h_TightExp = new TH1F("TightExp","TightExp",50,10,60);
			               
  TH1F* h_LooseObs = new TH1F("LooseObs","LooseObs",50,200,400);
  TH1F* h_TightObs = new TH1F("TightObs","TightObs",50,10,60);

  TH1F* h_muLim = new TH1F("muLim","muLim",800,0,40);
  
  for(int i = 0; i < nToys; i++){

    TDatime* td = new TDatime();  
    TRandom3* tr = new TRandom3();
    
    tr->SetSeed((int)td->GetTime());
    
    float LooseNew1 = Bloose;
    float TightNew1 = Btight;    
    float LooseNew2 = Bloose;
    float TightNew2 = Btight;    
    
    for(int v = 0; v < LooseVariations->size(); v++){
      
      float rand = tr->Gaus();
    
      //treat separately 1-sided and 2-sided systs
      float LooseChange1 = 0;
      float TightChange1 = 0;
      float LooseChange2 = 0;
      float TightChange2 = 0;

      // //Option 1 for doing this
      // if( LooseVariations->at(v).first == 0 ) LooseChange1 = fabs(rand)*LooseVariations->at(v).second;
      // else if( LooseVariations->at(v).second == 0 ) LooseChange1 = fabs(rand)*LooseVariations->at(v).first;
      // else LooseChange1 = rand*( LooseVariations->at(v).second - LooseVariations->at(v).first )/2.;
      
      // if( TightVariations->at(v).first == 0 ) TightChange1 = fabs(rand)*TightVariations->at(v).second;
      // else if( TightVariations->at(v).second == 0 ) TightChange1 = fabs(rand)*TightVariations->at(v).first;
      // else TightChange1 = rand*( TightVariations->at(v).second - TightVariations->at(v).first )/2.;

      //Option 2 for doing this
      if(rand < 0){
	LooseChange2 = -1*rand*LooseVariations->at(v).first;
	TightChange2 = -1*rand*TightVariations->at(v).first;
      }
      else{
	LooseChange2 = rand*LooseVariations->at(v).second;
	TightChange2 = rand*TightVariations->at(v).second;
      }
      
      // LooseNew1 += LooseChange1;
      // TightNew1 += TightChange1;
      LooseNew2 += LooseChange2;
      TightNew2 += TightChange2;
    
      // cout<<"For Variation "<<v<<", choose random number: "<<rand<<endl;
      // cout<<" Loose has uncertainties: "<<LooseVariations->at(v).first<<" "<<LooseVariations->at(v).second<<", Loose change 1 = "<<LooseChange1<<", Loose Expected 1 currently: "<<LooseNew1<<";  Loose change 2 = "<<LooseChange2<<", Loose expeccted 2 currently: "<<LooseNew2<<endl;
      // cout<<" Tight has uncertainties: "<<TightVariations->at(v).first<<" "<<TightVariations->at(v).second<<", Tight change 1 = "<<TightChange1<<", Tight Expected 1 currently: "<<TightNew1<<";  Tight change 2 = "<<TightChange2<<", Tight expeccted 2 currently: "<<TightNew2<<endl;
      
    }

    float LooseNew = LooseNew2;
    float TightNew = TightNew2;
    
    h_LooseExp->Fill(LooseNew);
    h_TightExp->Fill(TightNew);

    int looseObs = tr->Poisson(LooseNew);
    int tightObs = tr->Poisson(TightNew);

    h_LooseObs->Fill( looseObs );
    h_TightObs->Fill( tightObs );

    cout<<"Trial "<<i<<", expected: "<<LooseNew<<"/"<<TightNew<<", observed "<<looseObs<<"/"<<tightObs;
    float muLim = GetMuUpperLimit( looseObs, tightObs, Bloose, Btight, Sloose, Stight, Central->at(1), Central->at(2), false);
    h_muLim->Fill(muLim);
      
    cout<<", upper limit = "<<muLim<<endl;
    
  }

  h_LooseExp->GetXaxis()->SetTitle("Expected Loose");
  h_LooseObs->GetXaxis()->SetTitle("Observed Loose");  
  h_TightExp->GetXaxis()->SetTitle("Expected Tight");
  h_TightObs->GetXaxis()->SetTitle("Observed Tight");
  h_muLim->GetXaxis()->SetTitle("95% CLs upper limit on mu");
  
  
  TCanvas* c1 = new TCanvas();
  h_LooseExp->Draw();
  TCanvas* c2 = new TCanvas();
  h_TightExp->Draw();
  TCanvas* c3 = new TCanvas();
  h_LooseObs->Draw();
  TCanvas* c4 = new TCanvas();
  h_TightObs->Draw();
  TCanvas* c5 = new TCanvas();
  h_muLim->Draw();

  vector<TH1F*> vv;
  vv = {h_LooseExp, h_TightExp, h_LooseObs, h_TightObs, h_muLim};
  return vv;

  
}
