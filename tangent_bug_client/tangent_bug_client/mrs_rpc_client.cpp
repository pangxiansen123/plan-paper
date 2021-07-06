#include "StdAfx.h"
#include "mrs_rpc.h"
#include "mrs_rpc_c.c"

int rpc_client_init()
{
	unsigned char* szStringBinding = NULL;

	// Creates a string binding handle.
	// This function formats the passed values in a 
	// predefined format for use by RPC. Just like printf ...
	// Connection is not done here.
	RPC_STATUS status = RpcStringBindingCompose(
		NULL, // UUID to bind to.
		(unsigned char*)("ncacn_ip_tcp"),	// Use TCP/IP protocol.
		(unsigned char*)("localhost"),	// TCP/IP network                                                      							// the same machine as server
		(unsigned char*)("9292"),			// TCP/IP port to use.
		NULL, 							// Protocol dependent network options to use.
		&szStringBinding); 				// String binding output.

	if (status) return status;

	// Validates the format of the string binding handle 
	// and convertsit to a binding handle.
	// Connection is not done here either.
	status = RpcBindingFromStringBinding(
		szStringBinding,		// The string binding to validate.
		&hMrsRPCBinding);		// Put the result in the implicit binding
	// handle defined in the IDL file.

	if (status) return status;

	// Free the memory allocated by a string.
	status = RpcStringFree(&szStringBinding); // String to be freed.

	if (status) return status;

	return 0;
}

int rpc_client_free ()
{
	// Releases binding handle resources and disconnects from the server.
	RPC_STATUS status = RpcBindingFree(
		&hMrsRPCBinding); // Frees the implicit binding handle defined in
	// the IDL file.

	if (status) return status;

	return 0;
}

// Memory allocation function for RPC.
// The runtime uses these two functions for allocating/deallocating
// enough memory to pass the string to the server.
void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

// Memory deallocation function for RPC.
void __RPC_USER midl_user_free(void* p)
{
	free(p);
}

