// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// hs_str_count
Rcpp::IntegerVector hs_str_count(Rcpp::CharacterVector Rstring, Rcpp::String Rpattern);
RcppExport SEXP _hypeRscan_hs_str_count(SEXP RstringSEXP, SEXP RpatternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type Rstring(RstringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type Rpattern(RpatternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_count(Rstring, Rpattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_detect
Rcpp::LogicalVector hs_str_detect(Rcpp::CharacterVector Rstring, Rcpp::String Rpattern);
RcppExport SEXP _hypeRscan_hs_str_detect(SEXP RstringSEXP, SEXP RpatternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type Rstring(RstringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type Rpattern(RpatternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_detect(Rstring, Rpattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_location
IntegerVector hs_str_location(CharacterVector Rstring, String Rpattern);
RcppExport SEXP _hypeRscan_hs_str_location(SEXP RstringSEXP, SEXP RpatternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type Rstring(RstringSEXP);
    Rcpp::traits::input_parameter< String >::type Rpattern(RpatternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_location(Rstring, Rpattern));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_hypeRscan_hs_str_count", (DL_FUNC) &_hypeRscan_hs_str_count, 2},
    {"_hypeRscan_hs_str_detect", (DL_FUNC) &_hypeRscan_hs_str_detect, 2},
    {"_hypeRscan_hs_str_location", (DL_FUNC) &_hypeRscan_hs_str_location, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_hypeRscan(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
