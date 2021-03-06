// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// hs_str_count
Rcpp::IntegerVector hs_str_count(Rcpp::CharacterVector string, Rcpp::String pattern);
RcppExport SEXP _hypeRscan_hs_str_count(SEXP stringSEXP, SEXP patternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_count(string, pattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_detect
Rcpp::LogicalVector hs_str_detect(Rcpp::CharacterVector string, Rcpp::String pattern);
RcppExport SEXP _hypeRscan_hs_str_detect(SEXP stringSEXP, SEXP patternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_detect(string, pattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_extract
Rcpp::CharacterVector hs_str_extract(Rcpp::CharacterVector string, Rcpp::String pattern);
RcppExport SEXP _hypeRscan_hs_str_extract(SEXP stringSEXP, SEXP patternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_extract(string, pattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_locate
Rcpp::IntegerVector hs_str_locate(Rcpp::CharacterVector string, Rcpp::String pattern);
RcppExport SEXP _hypeRscan_hs_str_locate(SEXP stringSEXP, SEXP patternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_locate(string, pattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_locate_all
Rcpp::List hs_str_locate_all(Rcpp::CharacterVector string, Rcpp::String pattern);
RcppExport SEXP _hypeRscan_hs_str_locate_all(SEXP stringSEXP, SEXP patternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_locate_all(string, pattern));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_replace
Rcpp::CharacterVector hs_str_replace(Rcpp::CharacterVector string, Rcpp::String pattern, Rcpp::String replacement);
RcppExport SEXP _hypeRscan_hs_str_replace(SEXP stringSEXP, SEXP patternSEXP, SEXP replacementSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type replacement(replacementSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_replace(string, pattern, replacement));
    return rcpp_result_gen;
END_RCPP
}
// hs_str_replace_all
Rcpp::CharacterVector hs_str_replace_all(Rcpp::CharacterVector string, Rcpp::String pattern, Rcpp::String replacement);
RcppExport SEXP _hypeRscan_hs_str_replace_all(SEXP stringSEXP, SEXP patternSEXP, SEXP replacementSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type replacement(replacementSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_replace_all(string, pattern, replacement));
    return rcpp_result_gen;
END_RCPP
}
// hs_verion
Rcpp::String hs_verion();
RcppExport SEXP _hypeRscan_hs_verion() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(hs_verion());
    return rcpp_result_gen;
END_RCPP
}
// hs_platform
Rcpp::List hs_platform();
RcppExport SEXP _hypeRscan_hs_platform() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(hs_platform());
    return rcpp_result_gen;
END_RCPP
}
// hs_str_which
Rcpp::IntegerVector hs_str_which(Rcpp::CharacterVector string, Rcpp::String pattern);
RcppExport SEXP _hypeRscan_hs_str_which(SEXP stringSEXP, SEXP patternSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type string(stringSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type pattern(patternSEXP);
    rcpp_result_gen = Rcpp::wrap(hs_str_which(string, pattern));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_hypeRscan_hs_str_count", (DL_FUNC) &_hypeRscan_hs_str_count, 2},
    {"_hypeRscan_hs_str_detect", (DL_FUNC) &_hypeRscan_hs_str_detect, 2},
    {"_hypeRscan_hs_str_extract", (DL_FUNC) &_hypeRscan_hs_str_extract, 2},
    {"_hypeRscan_hs_str_locate", (DL_FUNC) &_hypeRscan_hs_str_locate, 2},
    {"_hypeRscan_hs_str_locate_all", (DL_FUNC) &_hypeRscan_hs_str_locate_all, 2},
    {"_hypeRscan_hs_str_replace", (DL_FUNC) &_hypeRscan_hs_str_replace, 3},
    {"_hypeRscan_hs_str_replace_all", (DL_FUNC) &_hypeRscan_hs_str_replace_all, 3},
    {"_hypeRscan_hs_verion", (DL_FUNC) &_hypeRscan_hs_verion, 0},
    {"_hypeRscan_hs_platform", (DL_FUNC) &_hypeRscan_hs_platform, 0},
    {"_hypeRscan_hs_str_which", (DL_FUNC) &_hypeRscan_hs_str_which, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_hypeRscan(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
