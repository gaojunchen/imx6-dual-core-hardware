/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 * 	found in "supl.asn"
 * 	`asn1c -gen-PER -fnative-types`
 */

#ifndef	_SetSessionID_H_
#define	_SetSessionID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "SETId.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SetSessionID */
typedef struct SetSessionID {
	long	 sessionId;
	SETId_t	 setId;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SetSessionID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SetSessionID;

#ifdef __cplusplus
}
#endif

#endif	/* _SetSessionID_H_ */
#include <asn_internal.h>