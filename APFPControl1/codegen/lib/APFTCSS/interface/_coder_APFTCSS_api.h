//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_APFTCSS_api.h
//
// Code generation for function 'APFTCSS'
//

#ifndef _CODER_APFTCSS_API_H
#define _CODER_APFTCSS_API_H

// Include files
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void APFTCSS(real_T S0[3], real_T V0[3], real_T InputParameters, real_T S[3],
             real_T V[3], real_T *OutputParameters);

void APFTCSS_api(const mxArray *const prhs[3], int32_T nlhs,
                 const mxArray *plhs[3]);

void APFTCSS_atexit();

void APFTCSS_initialize();

void APFTCSS_terminate();

void APFTCSS_xil_shutdown();

void APFTCSS_xil_terminate();

#endif
// End of code generation (_coder_APFTCSS_api.h)
