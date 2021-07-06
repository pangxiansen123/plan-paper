

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Dec 07 10:11:28 2010
 */
/* Compiler settings for d:\Work\Example\Navigation\bug_simulation_server\bug_simulation_server\mrs_rpc.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __mrs_rpc_h__
#define __mrs_rpc_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __MrsRPC_INTERFACE_DEFINED__
#define __MrsRPC_INTERFACE_DEFINED__

/* interface MrsRPC */
/* [implicit_handle][version][uuid] */ 

void SetMotorAcceleration( 
    double acceleration);

void SetMotorMaxVelocity( 
    double maxVelocity);

void SetRobotPosition( 
    double x,
    double y,
    double theta);

void GetRobotPosition( 
    /* [out] */ double *x,
    /* [out] */ double *y,
    /* [out] */ double *theta);

void GetScanningLaserData( 
    /* [out] */ double data[ 361 ],
    /* [out] */ long *len);

void GoMotorVelocity( 
    double leftMotor,
    double rightMotor);

void GetMotorPosition( 
    /* [out] */ double *leftMotor,
    /* [out] */ double *rightMotor);


extern handle_t hMrsRPCBinding;


extern RPC_IF_HANDLE MrsRPC_v1_0_c_ifspec;
extern RPC_IF_HANDLE MrsRPC_v1_0_s_ifspec;
#endif /* __MrsRPC_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


