

/* this ALWAYS GENERATED file contains the RPC client stubs */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "mrs_rpc.h"

#define TYPE_FORMAT_STRING_SIZE   17                                
#define PROC_FORMAT_STRING_SIZE   253                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _mrs_rpc_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } mrs_rpc_MIDL_TYPE_FORMAT_STRING;

typedef struct _mrs_rpc_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } mrs_rpc_MIDL_PROC_FORMAT_STRING;

typedef struct _mrs_rpc_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } mrs_rpc_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const mrs_rpc_MIDL_TYPE_FORMAT_STRING mrs_rpc__MIDL_TypeFormatString;
extern const mrs_rpc_MIDL_PROC_FORMAT_STRING mrs_rpc__MIDL_ProcFormatString;
extern const mrs_rpc_MIDL_EXPR_FORMAT_STRING mrs_rpc__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: MrsRPC, ver. 1.0,
   GUID={0xF0C37BD0,0x0D1B,0x4513,{0x8C,0x51,0xEC,0x0D,0x69,0x97,0x40,0xC2}} */

handle_t hMrsRPCBinding;


static const RPC_CLIENT_INTERFACE MrsRPC___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xF0C37BD0,0x0D1B,0x4513,{0x8C,0x51,0xEC,0x0D,0x69,0x97,0x40,0xC2}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE MrsRPC_v1_0_c_ifspec = (RPC_IF_HANDLE)& MrsRPC___RpcClientInterface;

extern const MIDL_STUB_DESC MrsRPC_StubDesc;

static RPC_BINDING_HANDLE MrsRPC__MIDL_AutoBindHandle;


void SetMotorAcceleration( 
    double acceleration)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&acceleration);
    
}


void SetMotorMaxVelocity( 
    double maxVelocity)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[30],
                  ( unsigned char * )&maxVelocity);
    
}


void SetRobotPosition( 
    double x,
    double y,
    double theta)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[60],
                  ( unsigned char * )&x);
    
}


void GetRobotPosition( 
    /* [out] */ double *x,
    /* [out] */ double *y,
    /* [out] */ double *theta)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[102],
                  ( unsigned char * )&x);
    
}


void GetScanningLaserData( 
    /* [out] */ double data[ 361 ],
    /* [out] */ long *len)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[144],
                  ( unsigned char * )&data);
    
}


void GoMotorVelocity( 
    double leftMotor,
    double rightMotor)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[180],
                  ( unsigned char * )&leftMotor);
    
}


void GetMotorPosition( 
    /* [out] */ double *leftMotor,
    /* [out] */ double *rightMotor)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&MrsRPC_StubDesc,
                  (PFORMAT_STRING) &mrs_rpc__MIDL_ProcFormatString.Format[216],
                  ( unsigned char * )&leftMotor);
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const mrs_rpc_MIDL_PROC_FORMAT_STRING mrs_rpc__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure SetMotorAcceleration */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x10 ),	/* 16 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acceleration */

/* 24 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 26 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 28 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Procedure SetMotorMaxVelocity */

/* 30 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x1 ),	/* 1 */
/* 38 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 40 */	NdrFcShort( 0x10 ),	/* 16 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	0x40,		/* Oi2 Flags:  has ext, */
			0x1,		/* 1 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxVelocity */

/* 54 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 56 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 58 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Procedure SetRobotPosition */

/* 60 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 62 */	NdrFcLong( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0x2 ),	/* 2 */
/* 68 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 70 */	NdrFcShort( 0x30 ),	/* 48 */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 76 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 84 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 86 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 88 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y */

/* 90 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 92 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 94 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter theta */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 100 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Procedure GetRobotPosition */

/* 102 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x3 ),	/* 3 */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x6c ),	/* 108 */
/* 116 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 126 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 128 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 130 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y */

/* 132 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter theta */

/* 138 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Procedure GetScanningLaserData */

/* 144 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x4 ),	/* 4 */
/* 152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0xb74 ),	/* 2932 */
/* 158 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter data */

/* 168 */	NdrFcShort( 0x12 ),	/* Flags:  must free, out, */
/* 170 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 172 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter len */

/* 174 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoMotorVelocity */

/* 180 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x5 ),	/* 5 */
/* 188 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 190 */	NdrFcShort( 0x20 ),	/* 32 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter leftMotor */

/* 204 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 206 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 208 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter rightMotor */

/* 210 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Procedure GetMotorPosition */

/* 216 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x6 ),	/* 6 */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x48 ),	/* 72 */
/* 230 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter leftMotor */

/* 240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 242 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 244 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter rightMotor */

/* 246 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 250 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

			0x0
        }
    };

static const mrs_rpc_MIDL_TYPE_FORMAT_STRING mrs_rpc__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x7,		/* 7 */
/*  8 */	NdrFcShort( 0xb48 ),	/* 2888 */
/* 10 */	0xc,		/* FC_DOUBLE */
			0x5b,		/* FC_END */
/* 12 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 14 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const unsigned short MrsRPC_FormatStringOffsetTable[] =
    {
    0,
    30,
    60,
    102,
    144,
    180,
    216
    };


static const MIDL_STUB_DESC MrsRPC_StubDesc = 
    {
    (void *)& MrsRPC___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &hMrsRPCBinding,
    0,
    0,
    0,
    0,
    mrs_rpc__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

