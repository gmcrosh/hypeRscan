#include <Rcpp.h>
#include <hs.h>
#include <iostream>

// [[Rcpp::export]]
Rcpp::String hs_verion() {
  std::string version = hs_version();
  return version;
}

// [[Rcpp::export]]
Rcpp::List hs_platform() {
  hs_platform_info_t plat;
  hs_populate_platform(&plat);
  std::string cpu_features, tune;
  int cpu_int, tune_int;
  cpu_int = plat.cpu_features;
  tune_int = plat.tune;
  switch(cpu_int) {
    case HS_CPU_FEATURES_AVX2: cpu_features = "AVX2";
      break;
    case HS_CPU_FEATURES_AVX512: cpu_features = "AVX512";
      break;
    default: cpu_features = "UNKNOWN";
      break;
  }
  
  switch(tune_int) {
    case HS_TUNE_FAMILY_SNB: tune = "SNB";
      break;
    case HS_TUNE_FAMILY_IVB: tune = "IVB";
      break;
    case HS_TUNE_FAMILY_HSW: tune = "HSW";
      break;
    case HS_TUNE_FAMILY_SLM: tune = "SLM";
      break;
    case HS_TUNE_FAMILY_BDW: tune = "BDW";
      break;
    case HS_TUNE_FAMILY_SKL: tune = "SKL";
      break;
    case HS_TUNE_FAMILY_SKX: tune = "SKX";
      break;
    case HS_TUNE_FAMILY_GLM: tune = "GLM";
      break;
    default: tune = "UNKNOWN";
      break;
  }
  
  Rcpp::List L = Rcpp::List::create(cpu_features, tune);
  return L;
}
