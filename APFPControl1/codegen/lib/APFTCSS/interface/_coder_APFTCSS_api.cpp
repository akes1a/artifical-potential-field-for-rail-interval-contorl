//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_APFTCSS_api.cpp
//
// Code generation for function 'APFTCSS'
//

// Include files
#include "_coder_APFTCSS_api.h"
#include "_coder_APFTCSS_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131610U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "APFTCSS",                                            // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *InputParameters,
                                 const char_T *identifier);

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *S0,
                                 const char_T *identifier))[3];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[3];

static const mxArray *emlrt_marshallOut(const real_T u[3]);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *InputParameters,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(InputParameters), &thisId);
  emlrtDestroyArray(&InputParameters);
  return y;
}

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2]{1, 3};
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *S0,
                                 const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(S0), &thisId);
  emlrtDestroyArray(&S0);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[3])
{
  static const int32_T i{0};
  static const int32_T i1{3};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void APFTCSS_api(const mxArray *const prhs[3], int32_T nlhs,
                 const mxArray *plhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*S)[3];
  real_T(*S0)[3];
  real_T(*V)[3];
  real_T(*V0)[3];
  real_T InputParameters;
  real_T OutputParameters;
  st.tls = emlrtRootTLSGlobal;
  S = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  V = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  // Marshall function inputs
  S0 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "S0");
  V0 = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "V0");
  InputParameters =
      b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "InputParameters");
  // Invoke the target function
  APFTCSS(*S0, *V0, InputParameters, *S, *V, &OutputParameters);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*S);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*V);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(OutputParameters);
  }
}

void APFTCSS_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  APFTCSS_xil_terminate();
  APFTCSS_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void APFTCSS_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void APFTCSS_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (_coder_APFTCSS_api.cpp)
