

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Sep 24 09:02:32 2019
 */
/* Compiler settings for EAGetMailObj.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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


#ifndef __EAGetMailObj_i_h__
#define __EAGetMailObj_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICategory_FWD_DEFINED__
#define __ICategory_FWD_DEFINED__
typedef interface ICategory ICategory;
#endif 	/* __ICategory_FWD_DEFINED__ */


#ifndef __ICategoryCollection_FWD_DEFINED__
#define __ICategoryCollection_FWD_DEFINED__
typedef interface ICategoryCollection ICategoryCollection;
#endif 	/* __ICategoryCollection_FWD_DEFINED__ */


#ifndef __IMailClient_FWD_DEFINED__
#define __IMailClient_FWD_DEFINED__
typedef interface IMailClient IMailClient;
#endif 	/* __IMailClient_FWD_DEFINED__ */


#ifndef __ICertificate_FWD_DEFINED__
#define __ICertificate_FWD_DEFINED__
typedef interface ICertificate ICertificate;
#endif 	/* __ICertificate_FWD_DEFINED__ */


#ifndef __IHeaderCollection_FWD_DEFINED__
#define __IHeaderCollection_FWD_DEFINED__
typedef interface IHeaderCollection IHeaderCollection;
#endif 	/* __IHeaderCollection_FWD_DEFINED__ */


#ifndef __IHeaderItem_FWD_DEFINED__
#define __IHeaderItem_FWD_DEFINED__
typedef interface IHeaderItem IHeaderItem;
#endif 	/* __IHeaderItem_FWD_DEFINED__ */


#ifndef __IAttachment_FWD_DEFINED__
#define __IAttachment_FWD_DEFINED__
typedef interface IAttachment IAttachment;
#endif 	/* __IAttachment_FWD_DEFINED__ */


#ifndef __IMail_FWD_DEFINED__
#define __IMail_FWD_DEFINED__
typedef interface IMail IMail;
#endif 	/* __IMail_FWD_DEFINED__ */


#ifndef __IMailAddress_FWD_DEFINED__
#define __IMailAddress_FWD_DEFINED__
typedef interface IMailAddress IMailAddress;
#endif 	/* __IMailAddress_FWD_DEFINED__ */


#ifndef __IMailInfo_FWD_DEFINED__
#define __IMailInfo_FWD_DEFINED__
typedef interface IMailInfo IMailInfo;
#endif 	/* __IMailInfo_FWD_DEFINED__ */


#ifndef __IMailReport_FWD_DEFINED__
#define __IMailReport_FWD_DEFINED__
typedef interface IMailReport IMailReport;
#endif 	/* __IMailReport_FWD_DEFINED__ */


#ifndef __IMailServer_FWD_DEFINED__
#define __IMailServer_FWD_DEFINED__
typedef interface IMailServer IMailServer;
#endif 	/* __IMailServer_FWD_DEFINED__ */


#ifndef __ITools_FWD_DEFINED__
#define __ITools_FWD_DEFINED__
typedef interface ITools ITools;
#endif 	/* __ITools_FWD_DEFINED__ */


#ifndef __IUIDLManager_FWD_DEFINED__
#define __IUIDLManager_FWD_DEFINED__
typedef interface IUIDLManager IUIDLManager;
#endif 	/* __IUIDLManager_FWD_DEFINED__ */


#ifndef __IUIDLItem_FWD_DEFINED__
#define __IUIDLItem_FWD_DEFINED__
typedef interface IUIDLItem IUIDLItem;
#endif 	/* __IUIDLItem_FWD_DEFINED__ */


#ifndef __IGetMailInfosParamType_FWD_DEFINED__
#define __IGetMailInfosParamType_FWD_DEFINED__
typedef interface IGetMailInfosParamType IGetMailInfosParamType;
#endif 	/* __IGetMailInfosParamType_FWD_DEFINED__ */


#ifndef __IAddressCollection_FWD_DEFINED__
#define __IAddressCollection_FWD_DEFINED__
typedef interface IAddressCollection IAddressCollection;
#endif 	/* __IAddressCollection_FWD_DEFINED__ */


#ifndef __IAttachmentCollection_FWD_DEFINED__
#define __IAttachmentCollection_FWD_DEFINED__
typedef interface IAttachmentCollection IAttachmentCollection;
#endif 	/* __IAttachmentCollection_FWD_DEFINED__ */


#ifndef __IMailInfoCollection_FWD_DEFINED__
#define __IMailInfoCollection_FWD_DEFINED__
typedef interface IMailInfoCollection IMailInfoCollection;
#endif 	/* __IMailInfoCollection_FWD_DEFINED__ */


#ifndef __IFolderCollection_FWD_DEFINED__
#define __IFolderCollection_FWD_DEFINED__
typedef interface IFolderCollection IFolderCollection;
#endif 	/* __IFolderCollection_FWD_DEFINED__ */


#ifndef __ISimpleJsonArray_FWD_DEFINED__
#define __ISimpleJsonArray_FWD_DEFINED__
typedef interface ISimpleJsonArray ISimpleJsonArray;
#endif 	/* __ISimpleJsonArray_FWD_DEFINED__ */


#ifndef __ISimpleJsonParser_FWD_DEFINED__
#define __ISimpleJsonParser_FWD_DEFINED__
typedef interface ISimpleJsonParser ISimpleJsonParser;
#endif 	/* __ISimpleJsonParser_FWD_DEFINED__ */


#ifndef ___IMailClientEvents_FWD_DEFINED__
#define ___IMailClientEvents_FWD_DEFINED__
typedef interface _IMailClientEvents _IMailClientEvents;
#endif 	/* ___IMailClientEvents_FWD_DEFINED__ */


#ifndef __MailClient_FWD_DEFINED__
#define __MailClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailClient MailClient;
#else
typedef struct MailClient MailClient;
#endif /* __cplusplus */

#endif 	/* __MailClient_FWD_DEFINED__ */


#ifndef __Attachment_FWD_DEFINED__
#define __Attachment_FWD_DEFINED__

#ifdef __cplusplus
typedef class Attachment Attachment;
#else
typedef struct Attachment Attachment;
#endif /* __cplusplus */

#endif 	/* __Attachment_FWD_DEFINED__ */


#ifndef __Certificate_FWD_DEFINED__
#define __Certificate_FWD_DEFINED__

#ifdef __cplusplus
typedef class Certificate Certificate;
#else
typedef struct Certificate Certificate;
#endif /* __cplusplus */

#endif 	/* __Certificate_FWD_DEFINED__ */


#ifndef __HeaderCollection_FWD_DEFINED__
#define __HeaderCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class HeaderCollection HeaderCollection;
#else
typedef struct HeaderCollection HeaderCollection;
#endif /* __cplusplus */

#endif 	/* __HeaderCollection_FWD_DEFINED__ */


#ifndef __HeaderItem_FWD_DEFINED__
#define __HeaderItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class HeaderItem HeaderItem;
#else
typedef struct HeaderItem HeaderItem;
#endif /* __cplusplus */

#endif 	/* __HeaderItem_FWD_DEFINED__ */


#ifndef __Imap4Folder_FWD_DEFINED__
#define __Imap4Folder_FWD_DEFINED__

#ifdef __cplusplus
typedef class Imap4Folder Imap4Folder;
#else
typedef struct Imap4Folder Imap4Folder;
#endif /* __cplusplus */

#endif 	/* __Imap4Folder_FWD_DEFINED__ */


#ifndef __Mail_FWD_DEFINED__
#define __Mail_FWD_DEFINED__

#ifdef __cplusplus
typedef class Mail Mail;
#else
typedef struct Mail Mail;
#endif /* __cplusplus */

#endif 	/* __Mail_FWD_DEFINED__ */


#ifndef __MailAddress_FWD_DEFINED__
#define __MailAddress_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailAddress MailAddress;
#else
typedef struct MailAddress MailAddress;
#endif /* __cplusplus */

#endif 	/* __MailAddress_FWD_DEFINED__ */


#ifndef __MailInfo_FWD_DEFINED__
#define __MailInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailInfo MailInfo;
#else
typedef struct MailInfo MailInfo;
#endif /* __cplusplus */

#endif 	/* __MailInfo_FWD_DEFINED__ */


#ifndef __MailServer_FWD_DEFINED__
#define __MailServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailServer MailServer;
#else
typedef struct MailServer MailServer;
#endif /* __cplusplus */

#endif 	/* __MailServer_FWD_DEFINED__ */


#ifndef __MailReport_FWD_DEFINED__
#define __MailReport_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailReport MailReport;
#else
typedef struct MailReport MailReport;
#endif /* __cplusplus */

#endif 	/* __MailReport_FWD_DEFINED__ */


#ifndef __Tools_FWD_DEFINED__
#define __Tools_FWD_DEFINED__

#ifdef __cplusplus
typedef class Tools Tools;
#else
typedef struct Tools Tools;
#endif /* __cplusplus */

#endif 	/* __Tools_FWD_DEFINED__ */


#ifndef __UIDLManager_FWD_DEFINED__
#define __UIDLManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class UIDLManager UIDLManager;
#else
typedef struct UIDLManager UIDLManager;
#endif /* __cplusplus */

#endif 	/* __UIDLManager_FWD_DEFINED__ */


#ifndef __UIDLItem_FWD_DEFINED__
#define __UIDLItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class UIDLItem UIDLItem;
#else
typedef struct UIDLItem UIDLItem;
#endif /* __cplusplus */

#endif 	/* __UIDLItem_FWD_DEFINED__ */


#ifndef __GetMailInfosParamType_FWD_DEFINED__
#define __GetMailInfosParamType_FWD_DEFINED__

#ifdef __cplusplus
typedef class GetMailInfosParamType GetMailInfosParamType;
#else
typedef struct GetMailInfosParamType GetMailInfosParamType;
#endif /* __cplusplus */

#endif 	/* __GetMailInfosParamType_FWD_DEFINED__ */


#ifndef __AddressCollection_FWD_DEFINED__
#define __AddressCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddressCollection AddressCollection;
#else
typedef struct AddressCollection AddressCollection;
#endif /* __cplusplus */

#endif 	/* __AddressCollection_FWD_DEFINED__ */


#ifndef __AttachmentCollection_FWD_DEFINED__
#define __AttachmentCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class AttachmentCollection AttachmentCollection;
#else
typedef struct AttachmentCollection AttachmentCollection;
#endif /* __cplusplus */

#endif 	/* __AttachmentCollection_FWD_DEFINED__ */


#ifndef __MailInfoCollection_FWD_DEFINED__
#define __MailInfoCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class MailInfoCollection MailInfoCollection;
#else
typedef struct MailInfoCollection MailInfoCollection;
#endif /* __cplusplus */

#endif 	/* __MailInfoCollection_FWD_DEFINED__ */


#ifndef __FolderCollection_FWD_DEFINED__
#define __FolderCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class FolderCollection FolderCollection;
#else
typedef struct FolderCollection FolderCollection;
#endif /* __cplusplus */

#endif 	/* __FolderCollection_FWD_DEFINED__ */


#ifndef __CategoryCollection_FWD_DEFINED__
#define __CategoryCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class CategoryCollection CategoryCollection;
#else
typedef struct CategoryCollection CategoryCollection;
#endif /* __cplusplus */

#endif 	/* __CategoryCollection_FWD_DEFINED__ */


#ifndef __Category_FWD_DEFINED__
#define __Category_FWD_DEFINED__

#ifdef __cplusplus
typedef class Category Category;
#else
typedef struct Category Category;
#endif /* __cplusplus */

#endif 	/* __Category_FWD_DEFINED__ */


#ifndef __SimpleJsonArray_FWD_DEFINED__
#define __SimpleJsonArray_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleJsonArray SimpleJsonArray;
#else
typedef struct SimpleJsonArray SimpleJsonArray;
#endif /* __cplusplus */

#endif 	/* __SimpleJsonArray_FWD_DEFINED__ */


#ifndef __SimpleJsonParser_FWD_DEFINED__
#define __SimpleJsonParser_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleJsonParser SimpleJsonParser;
#else
typedef struct SimpleJsonParser SimpleJsonParser;
#endif /* __cplusplus */

#endif 	/* __SimpleJsonParser_FWD_DEFINED__ */


#ifndef __OAuthResponseParser_FWD_DEFINED__
#define __OAuthResponseParser_FWD_DEFINED__

#ifdef __cplusplus
typedef class OAuthResponseParser OAuthResponseParser;
#else
typedef struct OAuthResponseParser OAuthResponseParser;
#endif /* __cplusplus */

#endif 	/* __OAuthResponseParser_FWD_DEFINED__ */


#ifndef __IOAuthResponseParser_FWD_DEFINED__
#define __IOAuthResponseParser_FWD_DEFINED__
typedef interface IOAuthResponseParser IOAuthResponseParser;
#endif 	/* __IOAuthResponseParser_FWD_DEFINED__ */


#ifndef __IImap4Folder_FWD_DEFINED__
#define __IImap4Folder_FWD_DEFINED__
typedef interface IImap4Folder IImap4Folder;
#endif 	/* __IImap4Folder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __EAGetMailObjLib_LIBRARY_DEFINED__
#define __EAGetMailObjLib_LIBRARY_DEFINED__

/* library EAGetMailObjLib */
/* [helpstring][version][uuid] */ 

























EXTERN_C const IID LIBID_EAGetMailObjLib;

#ifndef __ICategory_INTERFACE_DEFINED__
#define __ICategory_INTERFACE_DEFINED__

/* interface ICategory */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37AEBDA7-44BF-4C51-B32E-2527312D4AB8")
    ICategory : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICategory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICategory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICategory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICategory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICategory * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICategory * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            ICategory * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ICategoryVtbl;

    interface ICategory
    {
        CONST_VTBL struct ICategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICategory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICategory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICategory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICategory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICategory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICategory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICategory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICategory_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define ICategory_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICategory_INTERFACE_DEFINED__ */


#ifndef __ICategoryCollection_INTERFACE_DEFINED__
#define __ICategoryCollection_INTERFACE_DEFINED__

/* interface ICategoryCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICategoryCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3ED5EED7-9AB0-4D85-9665-5C530EBED66A")
    ICategoryCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            ICategory *Category) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ ICategory **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICategoryCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICategoryCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICategoryCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICategoryCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICategoryCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICategoryCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICategoryCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICategoryCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            ICategoryCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ICategoryCollection * This,
            ICategory *Category);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ICategoryCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            ICategoryCollection * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            ICategoryCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ ICategory **pVal);
        
        END_INTERFACE
    } ICategoryCollectionVtbl;

    interface ICategoryCollection
    {
        CONST_VTBL struct ICategoryCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICategoryCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICategoryCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICategoryCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICategoryCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICategoryCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICategoryCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICategoryCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICategoryCollection_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define ICategoryCollection_Add(This,Category)	\
    ( (This)->lpVtbl -> Add(This,Category) ) 

#define ICategoryCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ICategoryCollection_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#define ICategoryCollection_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> Item(This,Index,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICategoryCollection_INTERFACE_DEFINED__ */


#ifndef __IMailClient_INTERFACE_DEFINED__
#define __IMailClient_INTERFACE_DEFINED__

/* interface IMailClient */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7463672-BDA9-428F-8A03-E30C0F1B7EA8")
    IMailClient : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ IImap4Folder *oFolder,
            /* [in] */ VARIANT data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AppendEx( 
            /* [in] */ IImap4Folder *oFolder,
            /* [in] */ VARIANT data,
            /* [in] */ BSTR Flags,
            /* [in] */ DATE MailDateTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeMailFlags( 
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ BSTR Flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IMailServer *oServer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ IImap4Folder *oFolder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFolder( 
            /* [in] */ IImap4Folder *RootFolder,
            /* [in] */ BSTR FolderName,
            /* [retval][out] */ IImap4Folder **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ IMailInfo *oInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteFolder( 
            /* [in] */ IImap4Folder *oFolder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Expunge( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMail( 
            /* [in] */ IMailInfo *oInfo,
            /* [retval][out] */ IMail **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMailHeader( 
            /* [in] */ IMailInfo *oInfo,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMailInfos( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logout( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Quit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReConnect( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SearchMail( 
            /* [in] */ BSTR Condition,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectFolder( 
            /* [in] */ IImap4Folder *oFolder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubscribeFolder( 
            /* [in] */ IImap4Folder *oFolder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnsubscribeFolder( 
            /* [in] */ IImap4Folder *oFolder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteLog( 
            /* [in] */ BSTR v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Connected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Conversation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CRLFAfterAppendCommand( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CRLFAfterAppendCommand( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentMailServer( 
            /* [retval][out] */ IMailServer **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Imap4Folders( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogFileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogFileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PreviousCommand( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectedFolder( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Timeout( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Timeout( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LicenseCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LicenseCode( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMailsByQueue( 
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR DownloadFolder,
            /* [in] */ VARIANT_BOOL LeaveCopy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RenameFolder( 
            /* [in] */ IImap4Folder *oFolder,
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoveDoubleDot( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoveDoubleDot( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarkAsRead( 
            /* [in] */ IMailInfo *oInfo,
            VARIANT_BOOL Read) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshMailInfos( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshFolders( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ IImap4Folder *oFolder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Undelete( 
            /* [in] */ IMailInfo *oInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryEWSPublicFolders( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrorDescription( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastErrorDescription( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NOOP( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitNewEmail( 
            LONG WaitTimeout,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelWaitEmail( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GetMailInfosParam( 
            /* [retval][out] */ IGetMailInfosParamType **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMailCount( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Delimiter( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMailInfoList( 
            /* [retval][out] */ IMailInfoCollection **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFolderList( 
            /* [retval][out] */ IFolderCollection **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEWSPublicFolderList( 
            /* [retval][out] */ IFolderCollection **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEWSCategories( 
            /* [in] */ IMailInfo *oInfo,
            /* [retval][out] */ ICategoryCollection **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateEWSCategories( 
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ ICategoryCollection *oCategories) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FetchMails( 
            /* [in] */ VARIANT_BOOL HeaderOnly,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SearchMailList( 
            /* [in] */ BSTR Condition,
            /* [retval][out] */ IMailInfoCollection **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMailClient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMailClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMailClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMailClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMailClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMailClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMailClient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder,
            /* [in] */ VARIANT data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AppendEx )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder,
            /* [in] */ VARIANT data,
            /* [in] */ BSTR Flags,
            /* [in] */ DATE MailDateTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeMailFlags )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ BSTR Flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IMailClient * This,
            /* [in] */ IMailServer *oServer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ IImap4Folder *oFolder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFolder )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *RootFolder,
            /* [in] */ BSTR FolderName,
            /* [retval][out] */ IImap4Folder **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFolder )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Expunge )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMail )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [retval][out] */ IMail **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMailHeader )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMailInfos )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Logout )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Quit )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReConnect )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SearchMail )( 
            IMailClient * This,
            /* [in] */ BSTR Condition,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectFolder )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SubscribeFolder )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnsubscribeFolder )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteLog )( 
            IMailClient * This,
            /* [in] */ BSTR v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Connected )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Conversation )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CRLFAfterAppendCommand )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CRLFAfterAppendCommand )( 
            IMailClient * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentMailServer )( 
            IMailClient * This,
            /* [retval][out] */ IMailServer **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Imap4Folders )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogFileName )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogFileName )( 
            IMailClient * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreviousCommand )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SelectedFolder )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IMailClient * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Timeout )( 
            IMailClient * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Timeout )( 
            IMailClient * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseCode )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LicenseCode )( 
            IMailClient * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMailsByQueue )( 
            IMailClient * This,
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR DownloadFolder,
            /* [in] */ VARIANT_BOOL LeaveCopy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RenameFolder )( 
            IMailClient * This,
            /* [in] */ IImap4Folder *oFolder,
            /* [in] */ BSTR NewName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveDoubleDot )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveDoubleDot )( 
            IMailClient * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarkAsRead )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            VARIANT_BOOL Read);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshMailInfos )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshFolders )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ IImap4Folder *oFolder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Undelete )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryEWSPublicFolders )( 
            IMailClient * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrorDescription )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastErrorDescription )( 
            IMailClient * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NOOP )( 
            IMailClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitNewEmail )( 
            IMailClient * This,
            LONG WaitTimeout,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelWaitEmail )( 
            IMailClient * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GetMailInfosParam )( 
            IMailClient * This,
            /* [retval][out] */ IGetMailInfosParamType **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMailCount )( 
            IMailClient * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delimiter )( 
            IMailClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMailInfoList )( 
            IMailClient * This,
            /* [retval][out] */ IMailInfoCollection **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFolderList )( 
            IMailClient * This,
            /* [retval][out] */ IFolderCollection **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEWSPublicFolderList )( 
            IMailClient * This,
            /* [retval][out] */ IFolderCollection **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEWSCategories )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [retval][out] */ ICategoryCollection **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateEWSCategories )( 
            IMailClient * This,
            /* [in] */ IMailInfo *oInfo,
            /* [in] */ ICategoryCollection *oCategories);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FetchMails )( 
            IMailClient * This,
            /* [in] */ VARIANT_BOOL HeaderOnly,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SearchMailList )( 
            IMailClient * This,
            /* [in] */ BSTR Condition,
            /* [retval][out] */ IMailInfoCollection **pVal);
        
        END_INTERFACE
    } IMailClientVtbl;

    interface IMailClient
    {
        CONST_VTBL struct IMailClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMailClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMailClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMailClient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMailClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMailClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMailClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMailClient_Append(This,oFolder,data)	\
    ( (This)->lpVtbl -> Append(This,oFolder,data) ) 

#define IMailClient_AppendEx(This,oFolder,data,Flags,MailDateTime)	\
    ( (This)->lpVtbl -> AppendEx(This,oFolder,data,Flags,MailDateTime) ) 

#define IMailClient_ChangeMailFlags(This,oInfo,Flags)	\
    ( (This)->lpVtbl -> ChangeMailFlags(This,oInfo,Flags) ) 

#define IMailClient_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMailClient_Connect(This,oServer)	\
    ( (This)->lpVtbl -> Connect(This,oServer) ) 

#define IMailClient_Copy(This,oInfo,oFolder)	\
    ( (This)->lpVtbl -> Copy(This,oInfo,oFolder) ) 

#define IMailClient_CreateFolder(This,RootFolder,FolderName,pVal)	\
    ( (This)->lpVtbl -> CreateFolder(This,RootFolder,FolderName,pVal) ) 

#define IMailClient_Delete(This,oInfo)	\
    ( (This)->lpVtbl -> Delete(This,oInfo) ) 

#define IMailClient_DeleteFolder(This,oFolder)	\
    ( (This)->lpVtbl -> DeleteFolder(This,oFolder) ) 

#define IMailClient_Expunge(This)	\
    ( (This)->lpVtbl -> Expunge(This) ) 

#define IMailClient_GetMail(This,oInfo,pVal)	\
    ( (This)->lpVtbl -> GetMail(This,oInfo,pVal) ) 

#define IMailClient_GetMailHeader(This,oInfo,pVal)	\
    ( (This)->lpVtbl -> GetMailHeader(This,oInfo,pVal) ) 

#define IMailClient_GetMailInfos(This,pVal)	\
    ( (This)->lpVtbl -> GetMailInfos(This,pVal) ) 

#define IMailClient_Logout(This)	\
    ( (This)->lpVtbl -> Logout(This) ) 

#define IMailClient_Quit(This)	\
    ( (This)->lpVtbl -> Quit(This) ) 

#define IMailClient_ReConnect(This)	\
    ( (This)->lpVtbl -> ReConnect(This) ) 

#define IMailClient_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IMailClient_SearchMail(This,Condition,pVal)	\
    ( (This)->lpVtbl -> SearchMail(This,Condition,pVal) ) 

#define IMailClient_SelectFolder(This,oFolder)	\
    ( (This)->lpVtbl -> SelectFolder(This,oFolder) ) 

#define IMailClient_SubscribeFolder(This,oFolder)	\
    ( (This)->lpVtbl -> SubscribeFolder(This,oFolder) ) 

#define IMailClient_UnsubscribeFolder(This,oFolder)	\
    ( (This)->lpVtbl -> UnsubscribeFolder(This,oFolder) ) 

#define IMailClient_WriteLog(This,v)	\
    ( (This)->lpVtbl -> WriteLog(This,v) ) 

#define IMailClient_get_Connected(This,pVal)	\
    ( (This)->lpVtbl -> get_Connected(This,pVal) ) 

#define IMailClient_get_Conversation(This,pVal)	\
    ( (This)->lpVtbl -> get_Conversation(This,pVal) ) 

#define IMailClient_get_CRLFAfterAppendCommand(This,pVal)	\
    ( (This)->lpVtbl -> get_CRLFAfterAppendCommand(This,pVal) ) 

#define IMailClient_put_CRLFAfterAppendCommand(This,newVal)	\
    ( (This)->lpVtbl -> put_CRLFAfterAppendCommand(This,newVal) ) 

#define IMailClient_get_CurrentMailServer(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentMailServer(This,pVal) ) 

#define IMailClient_get_Imap4Folders(This,pVal)	\
    ( (This)->lpVtbl -> get_Imap4Folders(This,pVal) ) 

#define IMailClient_get_LogFileName(This,pVal)	\
    ( (This)->lpVtbl -> get_LogFileName(This,pVal) ) 

#define IMailClient_put_LogFileName(This,newVal)	\
    ( (This)->lpVtbl -> put_LogFileName(This,newVal) ) 

#define IMailClient_get_PreviousCommand(This,pVal)	\
    ( (This)->lpVtbl -> get_PreviousCommand(This,pVal) ) 

#define IMailClient_get_SelectedFolder(This,pVal)	\
    ( (This)->lpVtbl -> get_SelectedFolder(This,pVal) ) 

#define IMailClient_get_Tag(This,pVal)	\
    ( (This)->lpVtbl -> get_Tag(This,pVal) ) 

#define IMailClient_put_Tag(This,newVal)	\
    ( (This)->lpVtbl -> put_Tag(This,newVal) ) 

#define IMailClient_get_Timeout(This,pVal)	\
    ( (This)->lpVtbl -> get_Timeout(This,pVal) ) 

#define IMailClient_put_Timeout(This,newVal)	\
    ( (This)->lpVtbl -> put_Timeout(This,newVal) ) 

#define IMailClient_get_LicenseCode(This,pVal)	\
    ( (This)->lpVtbl -> get_LicenseCode(This,pVal) ) 

#define IMailClient_put_LicenseCode(This,newVal)	\
    ( (This)->lpVtbl -> put_LicenseCode(This,newVal) ) 

#define IMailClient_GetMailsByQueue(This,oServer,DownloadFolder,LeaveCopy)	\
    ( (This)->lpVtbl -> GetMailsByQueue(This,oServer,DownloadFolder,LeaveCopy) ) 

#define IMailClient_RenameFolder(This,oFolder,NewName)	\
    ( (This)->lpVtbl -> RenameFolder(This,oFolder,NewName) ) 

#define IMailClient_get_RemoveDoubleDot(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoveDoubleDot(This,pVal) ) 

#define IMailClient_put_RemoveDoubleDot(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoveDoubleDot(This,newVal) ) 

#define IMailClient_MarkAsRead(This,oInfo,Read)	\
    ( (This)->lpVtbl -> MarkAsRead(This,oInfo,Read) ) 

#define IMailClient_RefreshMailInfos(This)	\
    ( (This)->lpVtbl -> RefreshMailInfos(This) ) 

#define IMailClient_RefreshFolders(This)	\
    ( (This)->lpVtbl -> RefreshFolders(This) ) 

#define IMailClient_Move(This,oInfo,oFolder)	\
    ( (This)->lpVtbl -> Move(This,oInfo,oFolder) ) 

#define IMailClient_Undelete(This,oInfo)	\
    ( (This)->lpVtbl -> Undelete(This,oInfo) ) 

#define IMailClient_QueryEWSPublicFolders(This,pVal)	\
    ( (This)->lpVtbl -> QueryEWSPublicFolders(This,pVal) ) 

#define IMailClient_get_LastErrorDescription(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrorDescription(This,pVal) ) 

#define IMailClient_put_LastErrorDescription(This,newVal)	\
    ( (This)->lpVtbl -> put_LastErrorDescription(This,newVal) ) 

#define IMailClient_NOOP(This)	\
    ( (This)->lpVtbl -> NOOP(This) ) 

#define IMailClient_WaitNewEmail(This,WaitTimeout,pVal)	\
    ( (This)->lpVtbl -> WaitNewEmail(This,WaitTimeout,pVal) ) 

#define IMailClient_CancelWaitEmail(This)	\
    ( (This)->lpVtbl -> CancelWaitEmail(This) ) 

#define IMailClient_get_GetMailInfosParam(This,pVal)	\
    ( (This)->lpVtbl -> get_GetMailInfosParam(This,pVal) ) 

#define IMailClient_GetMailCount(This,pVal)	\
    ( (This)->lpVtbl -> GetMailCount(This,pVal) ) 

#define IMailClient_get_Delimiter(This,pVal)	\
    ( (This)->lpVtbl -> get_Delimiter(This,pVal) ) 

#define IMailClient_GetMailInfoList(This,pVal)	\
    ( (This)->lpVtbl -> GetMailInfoList(This,pVal) ) 

#define IMailClient_GetFolderList(This,pVal)	\
    ( (This)->lpVtbl -> GetFolderList(This,pVal) ) 

#define IMailClient_GetEWSPublicFolderList(This,pVal)	\
    ( (This)->lpVtbl -> GetEWSPublicFolderList(This,pVal) ) 

#define IMailClient_GetEWSCategories(This,oInfo,pVal)	\
    ( (This)->lpVtbl -> GetEWSCategories(This,oInfo,pVal) ) 

#define IMailClient_UpdateEWSCategories(This,oInfo,oCategories)	\
    ( (This)->lpVtbl -> UpdateEWSCategories(This,oInfo,oCategories) ) 

#define IMailClient_FetchMails(This,HeaderOnly,pVal)	\
    ( (This)->lpVtbl -> FetchMails(This,HeaderOnly,pVal) ) 

#define IMailClient_SearchMailList(This,Condition,pVal)	\
    ( (This)->lpVtbl -> SearchMailList(This,Condition,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMailClient_INTERFACE_DEFINED__ */


#ifndef __ICertificate_INTERFACE_DEFINED__
#define __ICertificate_INTERFACE_DEFINED__

/* interface ICertificate */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICertificate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98790582-CE44-47C9-8F70-90DCFEAF46AC")
    ICertificate : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToStore( 
            /* [in] */ LONG StoreLocation,
            /* [in] */ BSTR StoreName) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE FindCertId( 
            /* [in] */ ULONGLONG CertId) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE FindCertIdInStore( 
            /* [in] */ ULONGLONG CertId,
            /* [in] */ ULONG StoreLocation,
            /* [in] */ BSTR StoreName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindSubject( 
            /* [in] */ BSTR FindKey,
            /* [in] */ LONG StoreLocation,
            /* [in] */ BSTR StoreName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ VARIANT PFXContent,
            /* [in] */ BSTR Password,
            /* [in] */ LONG KeyLocation) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromFile( 
            /* [in] */ BSTR PFXFile,
            /* [in] */ BSTR Password,
            /* [in] */ LONG KeyLocation) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unload( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasCertificate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Store( 
            /* [retval][out] */ ULONGLONG *pVal) = 0;
        
        virtual /* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ ULONGLONG *pVal) = 0;
        
        virtual /* [restricted][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Handle( 
            /* [in] */ ULONGLONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerialNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SerialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subject( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICertificateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICertificate * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICertificate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICertificate * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICertificate * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICertificate * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICertificate * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICertificate * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddToStore )( 
            ICertificate * This,
            /* [in] */ LONG StoreLocation,
            /* [in] */ BSTR StoreName);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindCertId )( 
            ICertificate * This,
            /* [in] */ ULONGLONG CertId);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindCertIdInStore )( 
            ICertificate * This,
            /* [in] */ ULONGLONG CertId,
            /* [in] */ ULONG StoreLocation,
            /* [in] */ BSTR StoreName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindSubject )( 
            ICertificate * This,
            /* [in] */ BSTR FindKey,
            /* [in] */ LONG StoreLocation,
            /* [in] */ BSTR StoreName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            ICertificate * This,
            /* [in] */ VARIANT PFXContent,
            /* [in] */ BSTR Password,
            /* [in] */ LONG KeyLocation);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromFile )( 
            ICertificate * This,
            /* [in] */ BSTR PFXFile,
            /* [in] */ BSTR Password,
            /* [in] */ LONG KeyLocation);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unload )( 
            ICertificate * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasCertificate )( 
            ICertificate * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [restricted][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Store )( 
            ICertificate * This,
            /* [retval][out] */ ULONGLONG *pVal);
        
        /* [restricted][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICertificate * This,
            /* [retval][out] */ ULONGLONG *pVal);
        
        /* [restricted][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Handle )( 
            ICertificate * This,
            /* [in] */ ULONGLONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerialNumber )( 
            ICertificate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SerialNumber )( 
            ICertificate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            ICertificate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Subject )( 
            ICertificate * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ICertificateVtbl;

    interface ICertificate
    {
        CONST_VTBL struct ICertificateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICertificate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICertificate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICertificate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICertificate_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICertificate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICertificate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICertificate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICertificate_AddToStore(This,StoreLocation,StoreName)	\
    ( (This)->lpVtbl -> AddToStore(This,StoreLocation,StoreName) ) 

#define ICertificate_FindCertId(This,CertId)	\
    ( (This)->lpVtbl -> FindCertId(This,CertId) ) 

#define ICertificate_FindCertIdInStore(This,CertId,StoreLocation,StoreName)	\
    ( (This)->lpVtbl -> FindCertIdInStore(This,CertId,StoreLocation,StoreName) ) 

#define ICertificate_FindSubject(This,FindKey,StoreLocation,StoreName)	\
    ( (This)->lpVtbl -> FindSubject(This,FindKey,StoreLocation,StoreName) ) 

#define ICertificate_Load(This,PFXContent,Password,KeyLocation)	\
    ( (This)->lpVtbl -> Load(This,PFXContent,Password,KeyLocation) ) 

#define ICertificate_LoadFromFile(This,PFXFile,Password,KeyLocation)	\
    ( (This)->lpVtbl -> LoadFromFile(This,PFXFile,Password,KeyLocation) ) 

#define ICertificate_Unload(This)	\
    ( (This)->lpVtbl -> Unload(This) ) 

#define ICertificate_get_HasCertificate(This,pVal)	\
    ( (This)->lpVtbl -> get_HasCertificate(This,pVal) ) 

#define ICertificate_get_Store(This,pVal)	\
    ( (This)->lpVtbl -> get_Store(This,pVal) ) 

#define ICertificate_get_Handle(This,pVal)	\
    ( (This)->lpVtbl -> get_Handle(This,pVal) ) 

#define ICertificate_put_Handle(This,newVal)	\
    ( (This)->lpVtbl -> put_Handle(This,newVal) ) 

#define ICertificate_get_SerialNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_SerialNumber(This,pVal) ) 

#define ICertificate_put_SerialNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_SerialNumber(This,newVal) ) 

#define ICertificate_get_Subject(This,pVal)	\
    ( (This)->lpVtbl -> get_Subject(This,pVal) ) 

#define ICertificate_put_Subject(This,newVal)	\
    ( (This)->lpVtbl -> put_Subject(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICertificate_INTERFACE_DEFINED__ */


#ifndef __IHeaderCollection_INTERFACE_DEFINED__
#define __IHeaderCollection_INTERFACE_DEFINED__

/* interface IHeaderCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHeaderCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00AC14C1-BCB6-48AF-BEBF-C1F41BA7CF07")
    IHeaderCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IHeaderItem **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetValueOfKey( 
            /* [in] */ BSTR HeaderKey,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IHeaderItem *oHeader) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ LONG Index,
            /* [in] */ IHeaderItem *oHeader) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SearchKey( 
            /* [in] */ BSTR HeaderKey,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ BSTR HeaderKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IHeaderItem **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHeaderCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHeaderCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHeaderCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHeaderCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHeaderCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHeaderCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHeaderCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHeaderCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IHeaderCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IHeaderCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IHeaderItem **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetValueOfKey )( 
            IHeaderCollection * This,
            /* [in] */ BSTR HeaderKey,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IHeaderCollection * This,
            /* [in] */ IHeaderItem *oHeader);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IHeaderCollection * This,
            /* [in] */ LONG Index,
            /* [in] */ IHeaderItem *oHeader);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SearchKey )( 
            IHeaderCollection * This,
            /* [in] */ BSTR HeaderKey,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IHeaderCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IHeaderCollection * This,
            /* [in] */ BSTR HeaderKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IHeaderCollection * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IHeaderCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            IHeaderCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IHeaderItem **pVal);
        
        END_INTERFACE
    } IHeaderCollectionVtbl;

    interface IHeaderCollection
    {
        CONST_VTBL struct IHeaderCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHeaderCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHeaderCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHeaderCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHeaderCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHeaderCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHeaderCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHeaderCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHeaderCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IHeaderCollection_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> Item(This,Index,pVal) ) 

#define IHeaderCollection_GetValueOfKey(This,HeaderKey,pVal)	\
    ( (This)->lpVtbl -> GetValueOfKey(This,HeaderKey,pVal) ) 

#define IHeaderCollection_Add(This,oHeader)	\
    ( (This)->lpVtbl -> Add(This,oHeader) ) 

#define IHeaderCollection_Insert(This,Index,oHeader)	\
    ( (This)->lpVtbl -> Insert(This,Index,oHeader) ) 

#define IHeaderCollection_SearchKey(This,HeaderKey,pVal)	\
    ( (This)->lpVtbl -> SearchKey(This,HeaderKey,pVal) ) 

#define IHeaderCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IHeaderCollection_Remove(This,HeaderKey)	\
    ( (This)->lpVtbl -> Remove(This,HeaderKey) ) 

#define IHeaderCollection_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#define IHeaderCollection_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IHeaderCollection_IndexOf(This,Index,pVal)	\
    ( (This)->lpVtbl -> IndexOf(This,Index,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHeaderCollection_INTERFACE_DEFINED__ */


#ifndef __IHeaderItem_INTERFACE_DEFINED__
#define __IHeaderItem_INTERFACE_DEFINED__

/* interface IHeaderItem */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHeaderItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF9B19FF-8766-4931-8A3A-405A91475645")
    IHeaderItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeaderKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeaderKey( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeaderValue( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeaderValue( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DecodedValue( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubValue( 
            /* [in] */ BSTR SubKey,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHeaderItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHeaderItem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHeaderItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHeaderItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHeaderItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHeaderItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHeaderItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHeaderItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeaderKey )( 
            IHeaderItem * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeaderKey )( 
            IHeaderItem * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeaderValue )( 
            IHeaderItem * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeaderValue )( 
            IHeaderItem * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecodedValue )( 
            IHeaderItem * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SubValue )( 
            IHeaderItem * This,
            /* [in] */ BSTR SubKey,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IHeaderItemVtbl;

    interface IHeaderItem
    {
        CONST_VTBL struct IHeaderItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHeaderItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHeaderItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHeaderItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHeaderItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHeaderItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHeaderItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHeaderItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHeaderItem_get_HeaderKey(This,pVal)	\
    ( (This)->lpVtbl -> get_HeaderKey(This,pVal) ) 

#define IHeaderItem_put_HeaderKey(This,newVal)	\
    ( (This)->lpVtbl -> put_HeaderKey(This,newVal) ) 

#define IHeaderItem_get_HeaderValue(This,pVal)	\
    ( (This)->lpVtbl -> get_HeaderValue(This,pVal) ) 

#define IHeaderItem_put_HeaderValue(This,newVal)	\
    ( (This)->lpVtbl -> put_HeaderValue(This,newVal) ) 

#define IHeaderItem_get_DecodedValue(This,pVal)	\
    ( (This)->lpVtbl -> get_DecodedValue(This,pVal) ) 

#define IHeaderItem_SubValue(This,SubKey,pVal)	\
    ( (This)->lpVtbl -> SubValue(This,SubKey,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHeaderItem_INTERFACE_DEFINED__ */


#ifndef __IAttachment_INTERFACE_DEFINED__
#define __IAttachment_INTERFACE_DEFINED__

/* interface IAttachment */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAttachment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D531D50D-CDC6-400A-B938-46D36382173E")
    IAttachment : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Headers( 
            /* [retval][out] */ IHeaderCollection **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Overwrite) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Charset( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Content( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContentID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContentType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodedContent( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ VARIANT vt,
            /* [in] */ LONG CodePage,
            /* [in] */ LONG Start,
            /* [in] */ LONG Index) = 0;
        
        virtual /* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartIndex( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodedContentLen( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoveDoubleDot( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoveDoubleDot( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAttachmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAttachment * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAttachment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAttachment * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAttachment * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAttachment * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAttachment * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAttachment * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Headers )( 
            IAttachment * This,
            /* [retval][out] */ IHeaderCollection **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IAttachment * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Overwrite);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Charset )( 
            IAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Content )( 
            IAttachment * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentID )( 
            IAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentType )( 
            IAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodedContent )( 
            IAttachment * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IAttachment * This,
            /* [in] */ VARIANT vt,
            /* [in] */ LONG CodePage,
            /* [in] */ LONG Start,
            /* [in] */ LONG Index);
        
        /* [restricted][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartIndex )( 
            IAttachment * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodedContentLen )( 
            IAttachment * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveDoubleDot )( 
            IAttachment * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveDoubleDot )( 
            IAttachment * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IAttachmentVtbl;

    interface IAttachment
    {
        CONST_VTBL struct IAttachmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAttachment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAttachment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAttachment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAttachment_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAttachment_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAttachment_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAttachment_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAttachment_get_Headers(This,pVal)	\
    ( (This)->lpVtbl -> get_Headers(This,pVal) ) 

#define IAttachment_SaveAs(This,FileName,Overwrite)	\
    ( (This)->lpVtbl -> SaveAs(This,FileName,Overwrite) ) 

#define IAttachment_get_Charset(This,pVal)	\
    ( (This)->lpVtbl -> get_Charset(This,pVal) ) 

#define IAttachment_get_Content(This,pVal)	\
    ( (This)->lpVtbl -> get_Content(This,pVal) ) 

#define IAttachment_get_ContentID(This,pVal)	\
    ( (This)->lpVtbl -> get_ContentID(This,pVal) ) 

#define IAttachment_get_ContentType(This,pVal)	\
    ( (This)->lpVtbl -> get_ContentType(This,pVal) ) 

#define IAttachment_get_EncodedContent(This,pVal)	\
    ( (This)->lpVtbl -> get_EncodedContent(This,pVal) ) 

#define IAttachment_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IAttachment_Init(This,vt,CodePage,Start,Index)	\
    ( (This)->lpVtbl -> Init(This,vt,CodePage,Start,Index) ) 

#define IAttachment_get_StartIndex(This,pVal)	\
    ( (This)->lpVtbl -> get_StartIndex(This,pVal) ) 

#define IAttachment_get_EncodedContentLen(This,pVal)	\
    ( (This)->lpVtbl -> get_EncodedContentLen(This,pVal) ) 

#define IAttachment_get_RemoveDoubleDot(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoveDoubleDot(This,pVal) ) 

#define IAttachment_put_RemoveDoubleDot(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoveDoubleDot(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAttachment_INTERFACE_DEFINED__ */


#ifndef __IMail_INTERFACE_DEFINED__
#define __IMail_INTERFACE_DEFINED__

/* interface IMail */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMail;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F71E6CF-9417-46EB-B7C8-1760FDAC17C6")
    IMail : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ VARIANT data) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Content( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Overwrite) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Decrypt( 
            /* [in] */ ICertificate *Cert,
            /* [retval][out] */ IMail **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReport( 
            /* [retval][out] */ IMailReport **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL LateLoadBody) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParseTNEF( 
            /* [in] */ VARIANT data,
            /* [in] */ VARIANT_BOOL IncludeRTFBody,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAttachment( 
            /* [in] */ IAttachment *Att) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VerifySignature( 
            /* [retval][out] */ ICertificate **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attachments( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BodyHeaders( 
            /* [retval][out] */ IHeaderCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cc( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_From( 
            /* [retval][out] */ IMailAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Headers( 
            /* [retval][out] */ IHeaderCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HtmlBody( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsEncrypted( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsReport( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsSigned( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalBodyFormat( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Priority( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReceivedDate( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReplyTo( 
            /* [retval][out] */ IMailAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SentDate( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextBody( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_To( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bcc( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LicenseCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LicenseCode( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateHeader( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToAddr( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoveDoubleDot( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoveDoubleDot( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Html2Text( 
            /* [in] */ BSTR Html,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RTFToHTML( 
            /* [in] */ VARIANT RTFData,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeTNEF( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadOMSG( 
            /* [in] */ VARIANT MsgData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TNEFToMail( 
            /* [in] */ VARIANT TNEFData,
            /* [retval][out] */ IMail **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadOMSGFile( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeTNEFEx( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasAlternativeBody( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAsOMSG( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Overwrite,
            /* [in] */ VARIANT_BOOL Unsent) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToList( 
            /* [retval][out] */ IAddressCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CcList( 
            /* [retval][out] */ IAddressCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BccList( 
            /* [retval][out] */ IAddressCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AttachmentList( 
            /* [retval][out] */ IAttachmentCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDetectHtmlCharset( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsDetectHtmlCharset( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMail * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMail * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMail * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMail * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMail * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMail * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMail * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IMail * This,
            /* [in] */ VARIANT data);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Content )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IMail * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Overwrite);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IMail * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            IMail * This,
            /* [in] */ ICertificate *Cert,
            /* [retval][out] */ IMail **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReport )( 
            IMail * This,
            /* [retval][out] */ IMailReport **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFile )( 
            IMail * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL LateLoadBody);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParseTNEF )( 
            IMail * This,
            /* [in] */ VARIANT data,
            /* [in] */ VARIANT_BOOL IncludeRTFBody,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAttachment )( 
            IMail * This,
            /* [in] */ IAttachment *Att);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifySignature )( 
            IMail * This,
            /* [retval][out] */ ICertificate **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attachments )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BodyHeaders )( 
            IMail * This,
            /* [retval][out] */ IHeaderCollection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cc )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_From )( 
            IMail * This,
            /* [retval][out] */ IMailAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Headers )( 
            IMail * This,
            /* [retval][out] */ IHeaderCollection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HtmlBody )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsEncrypted )( 
            IMail * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReport )( 
            IMail * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsSigned )( 
            IMail * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalBodyFormat )( 
            IMail * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Priority )( 
            IMail * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReceivedDate )( 
            IMail * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReplyTo )( 
            IMail * This,
            /* [retval][out] */ IMailAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SentDate )( 
            IMail * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IMail * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextBody )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_To )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bcc )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseCode )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LicenseCode )( 
            IMail * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateHeader )( 
            IMail * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToAddr )( 
            IMail * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveDoubleDot )( 
            IMail * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveDoubleDot )( 
            IMail * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Html2Text )( 
            IMail * This,
            /* [in] */ BSTR Html,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IMail * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RTFToHTML )( 
            IMail * This,
            /* [in] */ VARIANT RTFData,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecodeTNEF )( 
            IMail * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadOMSG )( 
            IMail * This,
            /* [in] */ VARIANT MsgData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TNEFToMail )( 
            IMail * This,
            /* [in] */ VARIANT TNEFData,
            /* [retval][out] */ IMail **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadOMSGFile )( 
            IMail * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecodeTNEFEx )( 
            IMail * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasAlternativeBody )( 
            IMail * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAsOMSG )( 
            IMail * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT_BOOL Overwrite,
            /* [in] */ VARIANT_BOOL Unsent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToList )( 
            IMail * This,
            /* [retval][out] */ IAddressCollection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CcList )( 
            IMail * This,
            /* [retval][out] */ IAddressCollection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BccList )( 
            IMail * This,
            /* [retval][out] */ IAddressCollection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AttachmentList )( 
            IMail * This,
            /* [retval][out] */ IAttachmentCollection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDetectHtmlCharset )( 
            IMail * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsDetectHtmlCharset )( 
            IMail * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IMail * This);
        
        END_INTERFACE
    } IMailVtbl;

    interface IMail
    {
        CONST_VTBL struct IMailVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMail_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMail_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMail_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMail_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMail_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMail_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMail_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMail_Load(This,data)	\
    ( (This)->lpVtbl -> Load(This,data) ) 

#define IMail_get_Content(This,pVal)	\
    ( (This)->lpVtbl -> get_Content(This,pVal) ) 

#define IMail_SaveAs(This,FileName,Overwrite)	\
    ( (This)->lpVtbl -> SaveAs(This,FileName,Overwrite) ) 

#define IMail_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IMail_Decrypt(This,Cert,pVal)	\
    ( (This)->lpVtbl -> Decrypt(This,Cert,pVal) ) 

#define IMail_GetReport(This,pVal)	\
    ( (This)->lpVtbl -> GetReport(This,pVal) ) 

#define IMail_LoadFile(This,FileName,LateLoadBody)	\
    ( (This)->lpVtbl -> LoadFile(This,FileName,LateLoadBody) ) 

#define IMail_ParseTNEF(This,data,IncludeRTFBody,pVal)	\
    ( (This)->lpVtbl -> ParseTNEF(This,data,IncludeRTFBody,pVal) ) 

#define IMail_RemoveAttachment(This,Att)	\
    ( (This)->lpVtbl -> RemoveAttachment(This,Att) ) 

#define IMail_VerifySignature(This,pVal)	\
    ( (This)->lpVtbl -> VerifySignature(This,pVal) ) 

#define IMail_get_Attachments(This,pVal)	\
    ( (This)->lpVtbl -> get_Attachments(This,pVal) ) 

#define IMail_get_BodyHeaders(This,pVal)	\
    ( (This)->lpVtbl -> get_BodyHeaders(This,pVal) ) 

#define IMail_get_Cc(This,pVal)	\
    ( (This)->lpVtbl -> get_Cc(This,pVal) ) 

#define IMail_get_From(This,pVal)	\
    ( (This)->lpVtbl -> get_From(This,pVal) ) 

#define IMail_get_Headers(This,pVal)	\
    ( (This)->lpVtbl -> get_Headers(This,pVal) ) 

#define IMail_get_HtmlBody(This,pVal)	\
    ( (This)->lpVtbl -> get_HtmlBody(This,pVal) ) 

#define IMail_get_IsEncrypted(This,pVal)	\
    ( (This)->lpVtbl -> get_IsEncrypted(This,pVal) ) 

#define IMail_get_IsReport(This,pVal)	\
    ( (This)->lpVtbl -> get_IsReport(This,pVal) ) 

#define IMail_get_IsSigned(This,pVal)	\
    ( (This)->lpVtbl -> get_IsSigned(This,pVal) ) 

#define IMail_get_OriginalBodyFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalBodyFormat(This,pVal) ) 

#define IMail_get_Priority(This,pVal)	\
    ( (This)->lpVtbl -> get_Priority(This,pVal) ) 

#define IMail_get_ReceivedDate(This,pVal)	\
    ( (This)->lpVtbl -> get_ReceivedDate(This,pVal) ) 

#define IMail_get_ReplyTo(This,pVal)	\
    ( (This)->lpVtbl -> get_ReplyTo(This,pVal) ) 

#define IMail_get_SentDate(This,pVal)	\
    ( (This)->lpVtbl -> get_SentDate(This,pVal) ) 

#define IMail_get_Subject(This,pVal)	\
    ( (This)->lpVtbl -> get_Subject(This,pVal) ) 

#define IMail_get_Tag(This,pVal)	\
    ( (This)->lpVtbl -> get_Tag(This,pVal) ) 

#define IMail_put_Tag(This,newVal)	\
    ( (This)->lpVtbl -> put_Tag(This,newVal) ) 

#define IMail_get_TextBody(This,pVal)	\
    ( (This)->lpVtbl -> get_TextBody(This,pVal) ) 

#define IMail_get_To(This,pVal)	\
    ( (This)->lpVtbl -> get_To(This,pVal) ) 

#define IMail_get_Bcc(This,pVal)	\
    ( (This)->lpVtbl -> get_Bcc(This,pVal) ) 

#define IMail_get_LicenseCode(This,pVal)	\
    ( (This)->lpVtbl -> get_LicenseCode(This,pVal) ) 

#define IMail_put_LicenseCode(This,newVal)	\
    ( (This)->lpVtbl -> put_LicenseCode(This,newVal) ) 

#define IMail_UpdateHeader(This)	\
    ( (This)->lpVtbl -> UpdateHeader(This) ) 

#define IMail_get_ToAddr(This,pVal)	\
    ( (This)->lpVtbl -> get_ToAddr(This,pVal) ) 

#define IMail_get_RemoveDoubleDot(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoveDoubleDot(This,pVal) ) 

#define IMail_put_RemoveDoubleDot(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoveDoubleDot(This,newVal) ) 

#define IMail_Html2Text(This,Html,pVal)	\
    ( (This)->lpVtbl -> Html2Text(This,Html,pVal) ) 

#define IMail_get_Version(This,pVal)	\
    ( (This)->lpVtbl -> get_Version(This,pVal) ) 

#define IMail_RTFToHTML(This,RTFData,pVal)	\
    ( (This)->lpVtbl -> RTFToHTML(This,RTFData,pVal) ) 

#define IMail_DecodeTNEF(This)	\
    ( (This)->lpVtbl -> DecodeTNEF(This) ) 

#define IMail_LoadOMSG(This,MsgData)	\
    ( (This)->lpVtbl -> LoadOMSG(This,MsgData) ) 

#define IMail_TNEFToMail(This,TNEFData,pVal)	\
    ( (This)->lpVtbl -> TNEFToMail(This,TNEFData,pVal) ) 

#define IMail_LoadOMSGFile(This,FileName)	\
    ( (This)->lpVtbl -> LoadOMSGFile(This,FileName) ) 

#define IMail_DecodeTNEFEx(This)	\
    ( (This)->lpVtbl -> DecodeTNEFEx(This) ) 

#define IMail_get_HasAlternativeBody(This,pVal)	\
    ( (This)->lpVtbl -> get_HasAlternativeBody(This,pVal) ) 

#define IMail_SaveAsOMSG(This,FileName,Overwrite,Unsent)	\
    ( (This)->lpVtbl -> SaveAsOMSG(This,FileName,Overwrite,Unsent) ) 

#define IMail_get_ToList(This,pVal)	\
    ( (This)->lpVtbl -> get_ToList(This,pVal) ) 

#define IMail_get_CcList(This,pVal)	\
    ( (This)->lpVtbl -> get_CcList(This,pVal) ) 

#define IMail_get_BccList(This,pVal)	\
    ( (This)->lpVtbl -> get_BccList(This,pVal) ) 

#define IMail_get_AttachmentList(This,pVal)	\
    ( (This)->lpVtbl -> get_AttachmentList(This,pVal) ) 

#define IMail_get_IsDetectHtmlCharset(This,pVal)	\
    ( (This)->lpVtbl -> get_IsDetectHtmlCharset(This,pVal) ) 

#define IMail_put_IsDetectHtmlCharset(This,newVal)	\
    ( (This)->lpVtbl -> put_IsDetectHtmlCharset(This,newVal) ) 

#define IMail_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMail_INTERFACE_DEFINED__ */


#ifndef __IMailAddress_INTERFACE_DEFINED__
#define __IMailAddress_INTERFACE_DEFINED__

/* interface IMailAddress */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9E7048E1-3574-4EFA-AE7B-67A015BA470F")
    IMailAddress : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncodeAddr( 
            /* [in] */ BSTR Charset,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailAddressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMailAddress * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMailAddress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMailAddress * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMailAddress * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMailAddress * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMailAddress * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMailAddress * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMailAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IMailAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IMailAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            IMailAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncodeAddr )( 
            IMailAddress * This,
            /* [in] */ BSTR Charset,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IMailAddressVtbl;

    interface IMailAddress
    {
        CONST_VTBL struct IMailAddressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailAddress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMailAddress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMailAddress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMailAddress_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMailAddress_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMailAddress_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMailAddress_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMailAddress_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IMailAddress_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IMailAddress_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define IMailAddress_put_Address(This,newVal)	\
    ( (This)->lpVtbl -> put_Address(This,newVal) ) 

#define IMailAddress_EncodeAddr(This,Charset,pVal)	\
    ( (This)->lpVtbl -> EncodeAddr(This,Charset,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMailAddress_INTERFACE_DEFINED__ */


#ifndef __IMailInfo_INTERFACE_DEFINED__
#define __IMailInfo_INTERFACE_DEFINED__

/* interface IMailInfo */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE217339-CBC8-4A35-B0F1-93E376462658")
    IMailInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Size( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UIDL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UIDL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Index( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAP4Flags( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAP4Flags( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChangeKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChangeKey( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Read( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Read( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Deleted( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Deleted( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PR_ENTRYID( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PR_ENTRYID( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Categories( 
            /* [retval][out] */ ICategoryCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Categories( 
            /* [in] */ ICategoryCollection *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMailInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMailInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMailInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMailInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMailInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMailInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMailInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IMailInfo * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Size )( 
            IMailInfo * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UIDL )( 
            IMailInfo * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UIDL )( 
            IMailInfo * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IMailInfo * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Index )( 
            IMailInfo * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAP4Flags )( 
            IMailInfo * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAP4Flags )( 
            IMailInfo * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChangeKey )( 
            IMailInfo * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChangeKey )( 
            IMailInfo * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Read )( 
            IMailInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Read )( 
            IMailInfo * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Deleted )( 
            IMailInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Deleted )( 
            IMailInfo * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PR_ENTRYID )( 
            IMailInfo * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PR_ENTRYID )( 
            IMailInfo * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Categories )( 
            IMailInfo * This,
            /* [retval][out] */ ICategoryCollection **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Categories )( 
            IMailInfo * This,
            /* [in] */ ICategoryCollection *newVal);
        
        END_INTERFACE
    } IMailInfoVtbl;

    interface IMailInfo
    {
        CONST_VTBL struct IMailInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMailInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMailInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMailInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMailInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMailInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMailInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMailInfo_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IMailInfo_put_Size(This,newVal)	\
    ( (This)->lpVtbl -> put_Size(This,newVal) ) 

#define IMailInfo_get_UIDL(This,pVal)	\
    ( (This)->lpVtbl -> get_UIDL(This,pVal) ) 

#define IMailInfo_put_UIDL(This,newVal)	\
    ( (This)->lpVtbl -> put_UIDL(This,newVal) ) 

#define IMailInfo_get_Index(This,pVal)	\
    ( (This)->lpVtbl -> get_Index(This,pVal) ) 

#define IMailInfo_put_Index(This,newVal)	\
    ( (This)->lpVtbl -> put_Index(This,newVal) ) 

#define IMailInfo_get_IMAP4Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAP4Flags(This,pVal) ) 

#define IMailInfo_put_IMAP4Flags(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAP4Flags(This,newVal) ) 

#define IMailInfo_get_ChangeKey(This,pVal)	\
    ( (This)->lpVtbl -> get_ChangeKey(This,pVal) ) 

#define IMailInfo_put_ChangeKey(This,newVal)	\
    ( (This)->lpVtbl -> put_ChangeKey(This,newVal) ) 

#define IMailInfo_get_Read(This,pVal)	\
    ( (This)->lpVtbl -> get_Read(This,pVal) ) 

#define IMailInfo_put_Read(This,newVal)	\
    ( (This)->lpVtbl -> put_Read(This,newVal) ) 

#define IMailInfo_get_Deleted(This,pVal)	\
    ( (This)->lpVtbl -> get_Deleted(This,pVal) ) 

#define IMailInfo_put_Deleted(This,newVal)	\
    ( (This)->lpVtbl -> put_Deleted(This,newVal) ) 

#define IMailInfo_get_PR_ENTRYID(This,pVal)	\
    ( (This)->lpVtbl -> get_PR_ENTRYID(This,pVal) ) 

#define IMailInfo_put_PR_ENTRYID(This,newVal)	\
    ( (This)->lpVtbl -> put_PR_ENTRYID(This,newVal) ) 

#define IMailInfo_get_Categories(This,pVal)	\
    ( (This)->lpVtbl -> get_Categories(This,pVal) ) 

#define IMailInfo_put_Categories(This,newVal)	\
    ( (This)->lpVtbl -> put_Categories(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMailInfo_INTERFACE_DEFINED__ */


#ifndef __IMailReport_INTERFACE_DEFINED__
#define __IMailReport_INTERFACE_DEFINED__

/* interface IMailReport */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailReport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("372B933C-CB50-48C5-81E5-B1C3122379B1")
    IMailReport : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ErrCode( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrDescription( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ErrDescription( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalHeaders( 
            /* [retval][out] */ IHeaderCollection **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginalHeaders( 
            /* [in] */ IHeaderCollection *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalMessageID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginalMessageID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalRecipient( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginalRecipient( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalSender( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginalSender( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalSubject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginalSubject( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReportMTA( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReportMTA( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReportType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReportType( 
            /* [in] */ LONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMailReport * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMailReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMailReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMailReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMailReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMailReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMailReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrCode )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ErrCode )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrDescription )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ErrDescription )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalHeaders )( 
            IMailReport * This,
            /* [retval][out] */ IHeaderCollection **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginalHeaders )( 
            IMailReport * This,
            /* [in] */ IHeaderCollection *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalMessageID )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginalMessageID )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalRecipient )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginalRecipient )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalSender )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginalSender )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalSubject )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginalSubject )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReportMTA )( 
            IMailReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReportMTA )( 
            IMailReport * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReportType )( 
            IMailReport * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReportType )( 
            IMailReport * This,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IMailReportVtbl;

    interface IMailReport
    {
        CONST_VTBL struct IMailReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailReport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMailReport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMailReport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMailReport_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMailReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMailReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMailReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMailReport_get_ErrCode(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrCode(This,pVal) ) 

#define IMailReport_put_ErrCode(This,newVal)	\
    ( (This)->lpVtbl -> put_ErrCode(This,newVal) ) 

#define IMailReport_get_ErrDescription(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrDescription(This,pVal) ) 

#define IMailReport_put_ErrDescription(This,newVal)	\
    ( (This)->lpVtbl -> put_ErrDescription(This,newVal) ) 

#define IMailReport_get_OriginalHeaders(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalHeaders(This,pVal) ) 

#define IMailReport_put_OriginalHeaders(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginalHeaders(This,newVal) ) 

#define IMailReport_get_OriginalMessageID(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalMessageID(This,pVal) ) 

#define IMailReport_put_OriginalMessageID(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginalMessageID(This,newVal) ) 

#define IMailReport_get_OriginalRecipient(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalRecipient(This,pVal) ) 

#define IMailReport_put_OriginalRecipient(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginalRecipient(This,newVal) ) 

#define IMailReport_get_OriginalSender(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalSender(This,pVal) ) 

#define IMailReport_put_OriginalSender(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginalSender(This,newVal) ) 

#define IMailReport_get_OriginalSubject(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalSubject(This,pVal) ) 

#define IMailReport_put_OriginalSubject(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginalSubject(This,newVal) ) 

#define IMailReport_get_ReportMTA(This,pVal)	\
    ( (This)->lpVtbl -> get_ReportMTA(This,pVal) ) 

#define IMailReport_put_ReportMTA(This,newVal)	\
    ( (This)->lpVtbl -> put_ReportMTA(This,newVal) ) 

#define IMailReport_get_ReportType(This,pVal)	\
    ( (This)->lpVtbl -> get_ReportType(This,pVal) ) 

#define IMailReport_put_ReportType(This,newVal)	\
    ( (This)->lpVtbl -> put_ReportType(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMailReport_INTERFACE_DEFINED__ */


#ifndef __IMailServer_INTERFACE_DEFINED__
#define __IMailServer_INTERFACE_DEFINED__

/* interface IMailServer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33520F78-AF50-44E7-9730-00E4083AA765")
    IMailServer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AuthType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AuthType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Port( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Port( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Protocol( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Protocol( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProxyProtocol( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProxyProtocol( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Server( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Server( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SocksProxyPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SocksProxyPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SocksProxyPort( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SocksProxyPort( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SocksProxyServer( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SocksProxyServer( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SocksProxyUser( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SocksProxyUser( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SSLType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SSLType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_User( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_User( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [retval][out] */ IMailServer **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SSLConnection( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SSLConnection( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToConversationString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Alias( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Alias( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMailServer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMailServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMailServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMailServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMailServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMailServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMailServer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AuthType )( 
            IMailServer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AuthType )( 
            IMailServer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Port )( 
            IMailServer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Port )( 
            IMailServer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Protocol )( 
            IMailServer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Protocol )( 
            IMailServer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProxyProtocol )( 
            IMailServer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProxyProtocol )( 
            IMailServer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Server )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Server )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SocksProxyPassword )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SocksProxyPassword )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SocksProxyPort )( 
            IMailServer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SocksProxyPort )( 
            IMailServer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SocksProxyServer )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SocksProxyServer )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SocksProxyUser )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SocksProxyUser )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SSLType )( 
            IMailServer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SSLType )( 
            IMailServer * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_User )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IMailServer * This,
            /* [retval][out] */ IMailServer **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SSLConnection )( 
            IMailServer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SSLConnection )( 
            IMailServer * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ToConversationString )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Alias )( 
            IMailServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Alias )( 
            IMailServer * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IMailServerVtbl;

    interface IMailServer
    {
        CONST_VTBL struct IMailServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailServer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMailServer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMailServer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMailServer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMailServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMailServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMailServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMailServer_get_AuthType(This,pVal)	\
    ( (This)->lpVtbl -> get_AuthType(This,pVal) ) 

#define IMailServer_put_AuthType(This,newVal)	\
    ( (This)->lpVtbl -> put_AuthType(This,newVal) ) 

#define IMailServer_get_Password(This,pVal)	\
    ( (This)->lpVtbl -> get_Password(This,pVal) ) 

#define IMailServer_put_Password(This,newVal)	\
    ( (This)->lpVtbl -> put_Password(This,newVal) ) 

#define IMailServer_get_Port(This,pVal)	\
    ( (This)->lpVtbl -> get_Port(This,pVal) ) 

#define IMailServer_put_Port(This,newVal)	\
    ( (This)->lpVtbl -> put_Port(This,newVal) ) 

#define IMailServer_get_Protocol(This,pVal)	\
    ( (This)->lpVtbl -> get_Protocol(This,pVal) ) 

#define IMailServer_put_Protocol(This,newVal)	\
    ( (This)->lpVtbl -> put_Protocol(This,newVal) ) 

#define IMailServer_get_ProxyProtocol(This,pVal)	\
    ( (This)->lpVtbl -> get_ProxyProtocol(This,pVal) ) 

#define IMailServer_put_ProxyProtocol(This,newVal)	\
    ( (This)->lpVtbl -> put_ProxyProtocol(This,newVal) ) 

#define IMailServer_get_Server(This,pVal)	\
    ( (This)->lpVtbl -> get_Server(This,pVal) ) 

#define IMailServer_put_Server(This,newVal)	\
    ( (This)->lpVtbl -> put_Server(This,newVal) ) 

#define IMailServer_get_SocksProxyPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_SocksProxyPassword(This,pVal) ) 

#define IMailServer_put_SocksProxyPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_SocksProxyPassword(This,newVal) ) 

#define IMailServer_get_SocksProxyPort(This,pVal)	\
    ( (This)->lpVtbl -> get_SocksProxyPort(This,pVal) ) 

#define IMailServer_put_SocksProxyPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SocksProxyPort(This,newVal) ) 

#define IMailServer_get_SocksProxyServer(This,pVal)	\
    ( (This)->lpVtbl -> get_SocksProxyServer(This,pVal) ) 

#define IMailServer_put_SocksProxyServer(This,newVal)	\
    ( (This)->lpVtbl -> put_SocksProxyServer(This,newVal) ) 

#define IMailServer_get_SocksProxyUser(This,pVal)	\
    ( (This)->lpVtbl -> get_SocksProxyUser(This,pVal) ) 

#define IMailServer_put_SocksProxyUser(This,newVal)	\
    ( (This)->lpVtbl -> put_SocksProxyUser(This,newVal) ) 

#define IMailServer_get_SSLType(This,pVal)	\
    ( (This)->lpVtbl -> get_SSLType(This,pVal) ) 

#define IMailServer_put_SSLType(This,newVal)	\
    ( (This)->lpVtbl -> put_SSLType(This,newVal) ) 

#define IMailServer_get_User(This,pVal)	\
    ( (This)->lpVtbl -> get_User(This,pVal) ) 

#define IMailServer_put_User(This,newVal)	\
    ( (This)->lpVtbl -> put_User(This,newVal) ) 

#define IMailServer_Copy(This,pVal)	\
    ( (This)->lpVtbl -> Copy(This,pVal) ) 

#define IMailServer_get_SSLConnection(This,pVal)	\
    ( (This)->lpVtbl -> get_SSLConnection(This,pVal) ) 

#define IMailServer_put_SSLConnection(This,newVal)	\
    ( (This)->lpVtbl -> put_SSLConnection(This,newVal) ) 

#define IMailServer_ToConversationString(This,pVal)	\
    ( (This)->lpVtbl -> ToConversationString(This,pVal) ) 

#define IMailServer_get_Alias(This,pVal)	\
    ( (This)->lpVtbl -> get_Alias(This,pVal) ) 

#define IMailServer_put_Alias(This,newVal)	\
    ( (This)->lpVtbl -> put_Alias(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMailServer_INTERFACE_DEFINED__ */


#ifndef __ITools_INTERFACE_DEFINED__
#define __ITools_INTERFACE_DEFINED__

/* interface ITools */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITools;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6AA9C7EE-BBD2-4941-A348-9E9C343366D2")
    ITools : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VarToBSTR( 
            /* [in] */ VARIANT Var,
            /* [in] */ LONG CodePage,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFolder( 
            /* [in] */ BSTR FolderName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistFile( 
            /* [in] */ BSTR FileOrFolderName,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFile( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFolder( 
            /* [in] */ BSTR FolderName,
            /* [in] */ VARIANT_BOOL Recursive) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFiles( 
            /* [in] */ BSTR FolderName,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadTextFile( 
            /* [in] */ BSTR FileName,
            /* [in] */ LONG CodePage,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteTextFile( 
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR Content,
            /* [in] */ LONG CodePage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenFileName( 
            /* [in] */ LONG Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BSTRToVar( 
            /* [in] */ BSTR Src,
            /* [in] */ LONG CodePage,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadFileToBase64( 
            /* [in] */ BSTR FileName,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBinaryFile( 
            /* [in] */ BSTR FileName,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RenameFile( 
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR NewName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IToolsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITools * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITools * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITools * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITools * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITools * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITools * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITools * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VarToBSTR )( 
            ITools * This,
            /* [in] */ VARIANT Var,
            /* [in] */ LONG CodePage,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFolder )( 
            ITools * This,
            /* [in] */ BSTR FolderName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistFile )( 
            ITools * This,
            /* [in] */ BSTR FileOrFolderName,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFile )( 
            ITools * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFolder )( 
            ITools * This,
            /* [in] */ BSTR FolderName,
            /* [in] */ VARIANT_BOOL Recursive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFiles )( 
            ITools * This,
            /* [in] */ BSTR FolderName,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadTextFile )( 
            ITools * This,
            /* [in] */ BSTR FileName,
            /* [in] */ LONG CodePage,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteTextFile )( 
            ITools * This,
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR Content,
            /* [in] */ LONG CodePage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenFileName )( 
            ITools * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BSTRToVar )( 
            ITools * This,
            /* [in] */ BSTR Src,
            /* [in] */ LONG CodePage,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadFileToBase64 )( 
            ITools * This,
            /* [in] */ BSTR FileName,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBinaryFile )( 
            ITools * This,
            /* [in] */ BSTR FileName,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RenameFile )( 
            ITools * This,
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR NewName);
        
        END_INTERFACE
    } IToolsVtbl;

    interface ITools
    {
        CONST_VTBL struct IToolsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITools_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITools_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITools_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITools_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITools_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITools_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITools_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITools_VarToBSTR(This,Var,CodePage,pVal)	\
    ( (This)->lpVtbl -> VarToBSTR(This,Var,CodePage,pVal) ) 

#define ITools_CreateFolder(This,FolderName)	\
    ( (This)->lpVtbl -> CreateFolder(This,FolderName) ) 

#define ITools_ExistFile(This,FileOrFolderName,pVal)	\
    ( (This)->lpVtbl -> ExistFile(This,FileOrFolderName,pVal) ) 

#define ITools_RemoveFile(This,FileName)	\
    ( (This)->lpVtbl -> RemoveFile(This,FileName) ) 

#define ITools_RemoveFolder(This,FolderName,Recursive)	\
    ( (This)->lpVtbl -> RemoveFolder(This,FolderName,Recursive) ) 

#define ITools_GetFiles(This,FolderName,pVal)	\
    ( (This)->lpVtbl -> GetFiles(This,FolderName,pVal) ) 

#define ITools_ReadTextFile(This,FileName,CodePage,pVal)	\
    ( (This)->lpVtbl -> ReadTextFile(This,FileName,CodePage,pVal) ) 

#define ITools_WriteTextFile(This,FileName,Content,CodePage)	\
    ( (This)->lpVtbl -> WriteTextFile(This,FileName,Content,CodePage) ) 

#define ITools_GenFileName(This,Index,pVal)	\
    ( (This)->lpVtbl -> GenFileName(This,Index,pVal) ) 

#define ITools_BSTRToVar(This,Src,CodePage,pVal)	\
    ( (This)->lpVtbl -> BSTRToVar(This,Src,CodePage,pVal) ) 

#define ITools_ReadFileToBase64(This,FileName,pVal)	\
    ( (This)->lpVtbl -> ReadFileToBase64(This,FileName,pVal) ) 

#define ITools_ReadBinaryFile(This,FileName,pVal)	\
    ( (This)->lpVtbl -> ReadBinaryFile(This,FileName,pVal) ) 

#define ITools_RenameFile(This,FileName,NewName)	\
    ( (This)->lpVtbl -> RenameFile(This,FileName,NewName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITools_INTERFACE_DEFINED__ */


#ifndef __IUIDLManager_INTERFACE_DEFINED__
#define __IUIDLManager_INTERFACE_DEFINED__

/* interface IUIDLManager */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUIDLManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("63D8237A-5DC3-4C82-BE6B-073B32A78759")
    IUIDLManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SyncUIDL( 
            /* [in] */ IMailServer *oServer,
            /* [in] */ VARIANT Infos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddUIDL( 
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR UIDL,
            /* [in] */ BSTR LocalFileName,
            /* [retval][out] */ IUIDLItem **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveUIDL( 
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR UIDL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveUIDLEX( 
            /* [in] */ IUIDLItem *oItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IUIDLItem **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindUIDL( 
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR UIDL,
            /* [retval][out] */ IUIDLItem **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindLocalFile( 
            /* [in] */ BSTR FileName,
            /* [retval][out] */ IUIDLItem **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SyncUIDLEX( 
            /* [in] */ IMailServer *oServer,
            /* [in] */ IMailInfoCollection *Infos) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUIDLManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUIDLManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUIDLManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUIDLManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUIDLManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUIDLManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUIDLManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUIDLManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IUIDLManager * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IUIDLManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SyncUIDL )( 
            IUIDLManager * This,
            /* [in] */ IMailServer *oServer,
            /* [in] */ VARIANT Infos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddUIDL )( 
            IUIDLManager * This,
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR UIDL,
            /* [in] */ BSTR LocalFileName,
            /* [retval][out] */ IUIDLItem **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveUIDL )( 
            IUIDLManager * This,
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR UIDL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveUIDLEX )( 
            IUIDLManager * This,
            /* [in] */ IUIDLItem *oItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IUIDLManager * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IUIDLManager * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IUIDLManager * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IUIDLManager * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IUIDLItem **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindUIDL )( 
            IUIDLManager * This,
            /* [in] */ IMailServer *oServer,
            /* [in] */ BSTR UIDL,
            /* [retval][out] */ IUIDLItem **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindLocalFile )( 
            IUIDLManager * This,
            /* [in] */ BSTR FileName,
            /* [retval][out] */ IUIDLItem **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SyncUIDLEX )( 
            IUIDLManager * This,
            /* [in] */ IMailServer *oServer,
            /* [in] */ IMailInfoCollection *Infos);
        
        END_INTERFACE
    } IUIDLManagerVtbl;

    interface IUIDLManager
    {
        CONST_VTBL struct IUIDLManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUIDLManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUIDLManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUIDLManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUIDLManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUIDLManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUIDLManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUIDLManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUIDLManager_Load(This,FileName)	\
    ( (This)->lpVtbl -> Load(This,FileName) ) 

#define IUIDLManager_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IUIDLManager_SyncUIDL(This,oServer,Infos)	\
    ( (This)->lpVtbl -> SyncUIDL(This,oServer,Infos) ) 

#define IUIDLManager_AddUIDL(This,oServer,UIDL,LocalFileName,pVal)	\
    ( (This)->lpVtbl -> AddUIDL(This,oServer,UIDL,LocalFileName,pVal) ) 

#define IUIDLManager_RemoveUIDL(This,oServer,UIDL)	\
    ( (This)->lpVtbl -> RemoveUIDL(This,oServer,UIDL) ) 

#define IUIDLManager_RemoveUIDLEX(This,oItem)	\
    ( (This)->lpVtbl -> RemoveUIDLEX(This,oItem) ) 

#define IUIDLManager_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#define IUIDLManager_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IUIDLManager_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IUIDLManager_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> Item(This,Index,pVal) ) 

#define IUIDLManager_FindUIDL(This,oServer,UIDL,pVal)	\
    ( (This)->lpVtbl -> FindUIDL(This,oServer,UIDL,pVal) ) 

#define IUIDLManager_FindLocalFile(This,FileName,pVal)	\
    ( (This)->lpVtbl -> FindLocalFile(This,FileName,pVal) ) 

#define IUIDLManager_SyncUIDLEX(This,oServer,Infos)	\
    ( (This)->lpVtbl -> SyncUIDLEX(This,oServer,Infos) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUIDLManager_INTERFACE_DEFINED__ */


#ifndef __IUIDLItem_INTERFACE_DEFINED__
#define __IUIDLItem_INTERFACE_DEFINED__

/* interface IUIDLItem */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUIDLItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BB66CC9-2E20-4567-97C0-494109F5B12B")
    IUIDLItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UIDL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UIDL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerUser( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServerUser( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DownloadTime( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DownloadTime( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flags( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Index( 
            /* [in] */ LONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUIDLItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUIDLItem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUIDLItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUIDLItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUIDLItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUIDLItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUIDLItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUIDLItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UIDL )( 
            IUIDLItem * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UIDL )( 
            IUIDLItem * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerUser )( 
            IUIDLItem * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServerUser )( 
            IUIDLItem * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IUIDLItem * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            IUIDLItem * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadTime )( 
            IUIDLItem * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DownloadTime )( 
            IUIDLItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            IUIDLItem * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            IUIDLItem * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IUIDLItem * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Index )( 
            IUIDLItem * This,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IUIDLItemVtbl;

    interface IUIDLItem
    {
        CONST_VTBL struct IUIDLItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUIDLItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUIDLItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUIDLItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUIDLItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUIDLItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUIDLItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUIDLItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUIDLItem_get_UIDL(This,pVal)	\
    ( (This)->lpVtbl -> get_UIDL(This,pVal) ) 

#define IUIDLItem_put_UIDL(This,newVal)	\
    ( (This)->lpVtbl -> put_UIDL(This,newVal) ) 

#define IUIDLItem_get_ServerUser(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerUser(This,pVal) ) 

#define IUIDLItem_put_ServerUser(This,newVal)	\
    ( (This)->lpVtbl -> put_ServerUser(This,newVal) ) 

#define IUIDLItem_get_FileName(This,pVal)	\
    ( (This)->lpVtbl -> get_FileName(This,pVal) ) 

#define IUIDLItem_put_FileName(This,newVal)	\
    ( (This)->lpVtbl -> put_FileName(This,newVal) ) 

#define IUIDLItem_get_DownloadTime(This,pVal)	\
    ( (This)->lpVtbl -> get_DownloadTime(This,pVal) ) 

#define IUIDLItem_put_DownloadTime(This,newVal)	\
    ( (This)->lpVtbl -> put_DownloadTime(This,newVal) ) 

#define IUIDLItem_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 

#define IUIDLItem_put_Flags(This,newVal)	\
    ( (This)->lpVtbl -> put_Flags(This,newVal) ) 

#define IUIDLItem_get_Index(This,pVal)	\
    ( (This)->lpVtbl -> get_Index(This,pVal) ) 

#define IUIDLItem_put_Index(This,newVal)	\
    ( (This)->lpVtbl -> put_Index(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUIDLItem_INTERFACE_DEFINED__ */


#ifndef __IGetMailInfosParamType_INTERFACE_DEFINED__
#define __IGetMailInfosParamType_INTERFACE_DEFINED__

/* interface IGetMailInfosParamType */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IGetMailInfosParamType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E9777121-432A-41A1-A895-BE0BBBDD1969")
    IGetMailInfosParamType : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GetMailInfosOptions( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GetMailInfosOptions( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SeqRange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SeqRange( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UIDRange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UIDRange( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubjectContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubjectContains( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SenderContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SenderContains( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ValueChanged( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ValueChanged( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DateRangeSINCE( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DateRangeSINCE( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DateRangeBEFORE( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DateRangeBEFORE( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ToContains( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CcContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CcContains( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToOrCcContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ToOrCcContains( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BodyContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BodyContains( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubjectOrBodyContains( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubjectOrBodyContains( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetMailInfosParamTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGetMailInfosParamType * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGetMailInfosParamType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGetMailInfosParamType * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGetMailInfosParamType * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGetMailInfosParamType * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGetMailInfosParamType * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGetMailInfosParamType * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GetMailInfosOptions )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GetMailInfosOptions )( 
            IGetMailInfosParamType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SeqRange )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SeqRange )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UIDRange )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UIDRange )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubjectContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SubjectContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SenderContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SenderContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueChanged )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ValueChanged )( 
            IGetMailInfosParamType * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DateRangeSINCE )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DateRangeSINCE )( 
            IGetMailInfosParamType * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DateRangeBEFORE )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DateRangeBEFORE )( 
            IGetMailInfosParamType * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IGetMailInfosParamType * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CcContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CcContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToOrCcContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToOrCcContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BodyContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BodyContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubjectOrBodyContains )( 
            IGetMailInfosParamType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SubjectOrBodyContains )( 
            IGetMailInfosParamType * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IGetMailInfosParamTypeVtbl;

    interface IGetMailInfosParamType
    {
        CONST_VTBL struct IGetMailInfosParamTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetMailInfosParamType_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGetMailInfosParamType_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGetMailInfosParamType_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGetMailInfosParamType_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGetMailInfosParamType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGetMailInfosParamType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGetMailInfosParamType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGetMailInfosParamType_get_GetMailInfosOptions(This,pVal)	\
    ( (This)->lpVtbl -> get_GetMailInfosOptions(This,pVal) ) 

#define IGetMailInfosParamType_put_GetMailInfosOptions(This,newVal)	\
    ( (This)->lpVtbl -> put_GetMailInfosOptions(This,newVal) ) 

#define IGetMailInfosParamType_get_SeqRange(This,pVal)	\
    ( (This)->lpVtbl -> get_SeqRange(This,pVal) ) 

#define IGetMailInfosParamType_put_SeqRange(This,newVal)	\
    ( (This)->lpVtbl -> put_SeqRange(This,newVal) ) 

#define IGetMailInfosParamType_get_UIDRange(This,pVal)	\
    ( (This)->lpVtbl -> get_UIDRange(This,pVal) ) 

#define IGetMailInfosParamType_put_UIDRange(This,newVal)	\
    ( (This)->lpVtbl -> put_UIDRange(This,newVal) ) 

#define IGetMailInfosParamType_get_SubjectContains(This,pVal)	\
    ( (This)->lpVtbl -> get_SubjectContains(This,pVal) ) 

#define IGetMailInfosParamType_put_SubjectContains(This,newVal)	\
    ( (This)->lpVtbl -> put_SubjectContains(This,newVal) ) 

#define IGetMailInfosParamType_get_SenderContains(This,pVal)	\
    ( (This)->lpVtbl -> get_SenderContains(This,pVal) ) 

#define IGetMailInfosParamType_put_SenderContains(This,newVal)	\
    ( (This)->lpVtbl -> put_SenderContains(This,newVal) ) 

#define IGetMailInfosParamType_get_ValueChanged(This,pVal)	\
    ( (This)->lpVtbl -> get_ValueChanged(This,pVal) ) 

#define IGetMailInfosParamType_put_ValueChanged(This,newVal)	\
    ( (This)->lpVtbl -> put_ValueChanged(This,newVal) ) 

#define IGetMailInfosParamType_get_DateRangeSINCE(This,pVal)	\
    ( (This)->lpVtbl -> get_DateRangeSINCE(This,pVal) ) 

#define IGetMailInfosParamType_put_DateRangeSINCE(This,newVal)	\
    ( (This)->lpVtbl -> put_DateRangeSINCE(This,newVal) ) 

#define IGetMailInfosParamType_get_DateRangeBEFORE(This,pVal)	\
    ( (This)->lpVtbl -> get_DateRangeBEFORE(This,pVal) ) 

#define IGetMailInfosParamType_put_DateRangeBEFORE(This,newVal)	\
    ( (This)->lpVtbl -> put_DateRangeBEFORE(This,newVal) ) 

#define IGetMailInfosParamType_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IGetMailInfosParamType_get_ToContains(This,pVal)	\
    ( (This)->lpVtbl -> get_ToContains(This,pVal) ) 

#define IGetMailInfosParamType_put_ToContains(This,newVal)	\
    ( (This)->lpVtbl -> put_ToContains(This,newVal) ) 

#define IGetMailInfosParamType_get_CcContains(This,pVal)	\
    ( (This)->lpVtbl -> get_CcContains(This,pVal) ) 

#define IGetMailInfosParamType_put_CcContains(This,newVal)	\
    ( (This)->lpVtbl -> put_CcContains(This,newVal) ) 

#define IGetMailInfosParamType_get_ToOrCcContains(This,pVal)	\
    ( (This)->lpVtbl -> get_ToOrCcContains(This,pVal) ) 

#define IGetMailInfosParamType_put_ToOrCcContains(This,newVal)	\
    ( (This)->lpVtbl -> put_ToOrCcContains(This,newVal) ) 

#define IGetMailInfosParamType_get_BodyContains(This,pVal)	\
    ( (This)->lpVtbl -> get_BodyContains(This,pVal) ) 

#define IGetMailInfosParamType_put_BodyContains(This,newVal)	\
    ( (This)->lpVtbl -> put_BodyContains(This,newVal) ) 

#define IGetMailInfosParamType_get_SubjectOrBodyContains(This,pVal)	\
    ( (This)->lpVtbl -> get_SubjectOrBodyContains(This,pVal) ) 

#define IGetMailInfosParamType_put_SubjectOrBodyContains(This,newVal)	\
    ( (This)->lpVtbl -> put_SubjectOrBodyContains(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGetMailInfosParamType_INTERFACE_DEFINED__ */


#ifndef __IAddressCollection_INTERFACE_DEFINED__
#define __IAddressCollection_INTERFACE_DEFINED__

/* interface IAddressCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAddressCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BDF40F78-205A-4651-B0C6-4B2870485E5D")
    IAddressCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailAddress **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IMailAddress *Address) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ LONG Index,
            /* [in] */ IMailAddress *Address) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ IMailAddress *Address) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailAddress **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddressCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddressCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddressCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddressCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAddressCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAddressCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAddressCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAddressCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAddressCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IAddressCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAddressCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailAddress **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAddressCollection * This,
            /* [in] */ IMailAddress *Address);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IAddressCollection * This,
            /* [in] */ LONG Index,
            /* [in] */ IMailAddress *Address);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAddressCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IAddressCollection * This,
            /* [in] */ IMailAddress *Address);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IAddressCollection * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            IAddressCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailAddress **pVal);
        
        END_INTERFACE
    } IAddressCollectionVtbl;

    interface IAddressCollection
    {
        CONST_VTBL struct IAddressCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddressCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAddressCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAddressCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAddressCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAddressCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAddressCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAddressCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAddressCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IAddressCollection_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IAddressCollection_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IAddressCollection_Add(This,Address)	\
    ( (This)->lpVtbl -> Add(This,Address) ) 

#define IAddressCollection_Insert(This,Index,Address)	\
    ( (This)->lpVtbl -> Insert(This,Index,Address) ) 

#define IAddressCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAddressCollection_Remove(This,Address)	\
    ( (This)->lpVtbl -> Remove(This,Address) ) 

#define IAddressCollection_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#define IAddressCollection_IndexOf(This,Index,pVal)	\
    ( (This)->lpVtbl -> IndexOf(This,Index,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAddressCollection_INTERFACE_DEFINED__ */


#ifndef __IAttachmentCollection_INTERFACE_DEFINED__
#define __IAttachmentCollection_INTERFACE_DEFINED__

/* interface IAttachmentCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAttachmentCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("380C4C5A-C4AF-4314-9B5F-53EC125DE749")
    IAttachmentCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IAttachment **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IAttachment **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IAttachment *Attachment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ LONG Index,
            /* [in] */ IAttachment *Attachment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ IAttachment *Attachment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAttachmentCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAttachmentCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAttachmentCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAttachmentCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAttachmentCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAttachmentCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAttachmentCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAttachmentCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAttachmentCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IAttachmentCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAttachmentCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IAttachment **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            IAttachmentCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IAttachment **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAttachmentCollection * This,
            /* [in] */ IAttachment *Attachment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IAttachmentCollection * This,
            /* [in] */ LONG Index,
            /* [in] */ IAttachment *Attachment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAttachmentCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IAttachmentCollection * This,
            /* [in] */ IAttachment *Attachment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IAttachmentCollection * This,
            /* [in] */ LONG Index);
        
        END_INTERFACE
    } IAttachmentCollectionVtbl;

    interface IAttachmentCollection
    {
        CONST_VTBL struct IAttachmentCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAttachmentCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAttachmentCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAttachmentCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAttachmentCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAttachmentCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAttachmentCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAttachmentCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAttachmentCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IAttachmentCollection_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IAttachmentCollection_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IAttachmentCollection_IndexOf(This,Index,pVal)	\
    ( (This)->lpVtbl -> IndexOf(This,Index,pVal) ) 

#define IAttachmentCollection_Add(This,Attachment)	\
    ( (This)->lpVtbl -> Add(This,Attachment) ) 

#define IAttachmentCollection_Insert(This,Index,Attachment)	\
    ( (This)->lpVtbl -> Insert(This,Index,Attachment) ) 

#define IAttachmentCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAttachmentCollection_Remove(This,Attachment)	\
    ( (This)->lpVtbl -> Remove(This,Attachment) ) 

#define IAttachmentCollection_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAttachmentCollection_INTERFACE_DEFINED__ */


#ifndef __IMailInfoCollection_INTERFACE_DEFINED__
#define __IMailInfoCollection_INTERFACE_DEFINED__

/* interface IMailInfoCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMailInfoCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("861D4252-62F3-4ECD-8F48-BD1C1F703CD1")
    IMailInfoCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IMailInfo *Info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ LONG Index,
            /* [in] */ IMailInfo *Info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ IMailInfo *Info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailInfo **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailInfo **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMailInfoCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMailInfoCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMailInfoCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMailInfoCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMailInfoCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMailInfoCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMailInfoCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMailInfoCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMailInfoCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMailInfoCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMailInfoCollection * This,
            /* [in] */ IMailInfo *Info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IMailInfoCollection * This,
            /* [in] */ LONG Index,
            /* [in] */ IMailInfo *Info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IMailInfoCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMailInfoCollection * This,
            /* [in] */ IMailInfo *Info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IMailInfoCollection * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            IMailInfoCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailInfo **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMailInfoCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IMailInfo **pVal);
        
        END_INTERFACE
    } IMailInfoCollectionVtbl;

    interface IMailInfoCollection
    {
        CONST_VTBL struct IMailInfoCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMailInfoCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMailInfoCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMailInfoCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMailInfoCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMailInfoCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMailInfoCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMailInfoCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMailInfoCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IMailInfoCollection_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IMailInfoCollection_Add(This,Info)	\
    ( (This)->lpVtbl -> Add(This,Info) ) 

#define IMailInfoCollection_Insert(This,Index,Info)	\
    ( (This)->lpVtbl -> Insert(This,Index,Info) ) 

#define IMailInfoCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IMailInfoCollection_Remove(This,Info)	\
    ( (This)->lpVtbl -> Remove(This,Info) ) 

#define IMailInfoCollection_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#define IMailInfoCollection_IndexOf(This,Index,pVal)	\
    ( (This)->lpVtbl -> IndexOf(This,Index,pVal) ) 

#define IMailInfoCollection_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMailInfoCollection_INTERFACE_DEFINED__ */


#ifndef __IFolderCollection_INTERFACE_DEFINED__
#define __IFolderCollection_INTERFACE_DEFINED__

/* interface IFolderCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFolderCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BD47F56-8B9E-4B8F-A253-63C9D79BD674")
    IFolderCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IImap4Folder **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IndexOf( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IImap4Folder **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IImap4Folder *Folder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ LONG Index,
            /* [in] */ IImap4Folder *Folder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ IImap4Folder *Folder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFolderCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFolderCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFolderCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFolderCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFolderCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFolderCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFolderCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFolderCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IFolderCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IFolderCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IFolderCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IImap4Folder **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IndexOf )( 
            IFolderCollection * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IImap4Folder **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IFolderCollection * This,
            /* [in] */ IImap4Folder *Folder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IFolderCollection * This,
            /* [in] */ LONG Index,
            /* [in] */ IImap4Folder *Folder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IFolderCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IFolderCollection * This,
            /* [in] */ IImap4Folder *Folder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IFolderCollection * This,
            /* [in] */ LONG Index);
        
        END_INTERFACE
    } IFolderCollectionVtbl;

    interface IFolderCollection
    {
        CONST_VTBL struct IFolderCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFolderCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFolderCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFolderCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFolderCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFolderCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFolderCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFolderCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFolderCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IFolderCollection_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define IFolderCollection_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IFolderCollection_IndexOf(This,Index,pVal)	\
    ( (This)->lpVtbl -> IndexOf(This,Index,pVal) ) 

#define IFolderCollection_Add(This,Folder)	\
    ( (This)->lpVtbl -> Add(This,Folder) ) 

#define IFolderCollection_Insert(This,Index,Folder)	\
    ( (This)->lpVtbl -> Insert(This,Index,Folder) ) 

#define IFolderCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IFolderCollection_Remove(This,Folder)	\
    ( (This)->lpVtbl -> Remove(This,Folder) ) 

#define IFolderCollection_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFolderCollection_INTERFACE_DEFINED__ */


#ifndef __ISimpleJsonArray_INTERFACE_DEFINED__
#define __ISimpleJsonArray_INTERFACE_DEFINED__

/* interface ISimpleJsonArray */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISimpleJsonArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40936428-092E-4974-8315-0163B6D33E94")
    ISimpleJsonArray : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleJsonArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleJsonArray * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleJsonArray * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleJsonArray * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISimpleJsonArray * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISimpleJsonArray * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISimpleJsonArray * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISimpleJsonArray * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            ISimpleJsonArray * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ISimpleJsonArray * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ISimpleJsonArray * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            ISimpleJsonArray * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ISimpleJsonArray * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            ISimpleJsonArray * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } ISimpleJsonArrayVtbl;

    interface ISimpleJsonArray
    {
        CONST_VTBL struct ISimpleJsonArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleJsonArray_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleJsonArray_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleJsonArray_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleJsonArray_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISimpleJsonArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISimpleJsonArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISimpleJsonArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISimpleJsonArray_get_Length(This,pVal)	\
    ( (This)->lpVtbl -> get_Length(This,pVal) ) 

#define ISimpleJsonArray_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define ISimpleJsonArray_Add(This,newVal)	\
    ( (This)->lpVtbl -> Add(This,newVal) ) 

#define ISimpleJsonArray_RemoveAt(This,Index)	\
    ( (This)->lpVtbl -> RemoveAt(This,Index) ) 

#define ISimpleJsonArray_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ISimpleJsonArray_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> Item(This,Index,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleJsonArray_INTERFACE_DEFINED__ */


#ifndef __ISimpleJsonParser_INTERFACE_DEFINED__
#define __ISimpleJsonParser_INTERFACE_DEFINED__

/* interface ISimpleJsonParser */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISimpleJsonParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C825340-7B0A-432C-B082-DEEB8B2A3E64")
    ISimpleJsonParser : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJsonValue( 
            /* [in] */ BSTR Source,
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParseArray( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ ISimpleJsonArray **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Trim( 
            /* [in] */ BSTR Source,
            /* [in] */ BSTR Trimer,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleJsonParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleJsonParser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleJsonParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleJsonParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISimpleJsonParser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISimpleJsonParser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISimpleJsonParser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISimpleJsonParser * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetJsonValue )( 
            ISimpleJsonParser * This,
            /* [in] */ BSTR Source,
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParseArray )( 
            ISimpleJsonParser * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ ISimpleJsonArray **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trim )( 
            ISimpleJsonParser * This,
            /* [in] */ BSTR Source,
            /* [in] */ BSTR Trimer,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } ISimpleJsonParserVtbl;

    interface ISimpleJsonParser
    {
        CONST_VTBL struct ISimpleJsonParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleJsonParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleJsonParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleJsonParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleJsonParser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISimpleJsonParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISimpleJsonParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISimpleJsonParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISimpleJsonParser_GetJsonValue(This,Source,Key,pVal)	\
    ( (This)->lpVtbl -> GetJsonValue(This,Source,Key,pVal) ) 

#define ISimpleJsonParser_ParseArray(This,Source,pVal)	\
    ( (This)->lpVtbl -> ParseArray(This,Source,pVal) ) 

#define ISimpleJsonParser_Trim(This,Source,Trimer,pVal)	\
    ( (This)->lpVtbl -> Trim(This,Source,Trimer,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleJsonParser_INTERFACE_DEFINED__ */


#ifndef ___IMailClientEvents_DISPINTERFACE_DEFINED__
#define ___IMailClientEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMailClientEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IMailClientEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F9C5042F-13E4-42B7-8160-F511C74A9904")
    _IMailClientEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMailClientEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMailClientEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMailClientEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMailClientEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMailClientEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMailClientEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMailClientEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMailClientEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IMailClientEventsVtbl;

    interface _IMailClientEvents
    {
        CONST_VTBL struct _IMailClientEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMailClientEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IMailClientEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IMailClientEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IMailClientEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IMailClientEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IMailClientEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IMailClientEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMailClientEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MailClient;

#ifdef __cplusplus

class DECLSPEC_UUID("953EFD7C-8FCE-4D9C-9BD9-E6F19A1B7FC9")
MailClient;
#endif

EXTERN_C const CLSID CLSID_Attachment;

#ifdef __cplusplus

class DECLSPEC_UUID("AD59203B-0C25-4192-98F2-C680D6A16738")
Attachment;
#endif

EXTERN_C const CLSID CLSID_Certificate;

#ifdef __cplusplus

class DECLSPEC_UUID("76BB6AA2-49D5-4452-97A0-C5F7B8910D12")
Certificate;
#endif

EXTERN_C const CLSID CLSID_HeaderCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("3F46EBC3-9D7F-4F73-B779-F2FC6C0B6EE7")
HeaderCollection;
#endif

EXTERN_C const CLSID CLSID_HeaderItem;

#ifdef __cplusplus

class DECLSPEC_UUID("206AF1CC-DF89-4E4E-96EB-40D7641FACFD")
HeaderItem;
#endif

EXTERN_C const CLSID CLSID_Imap4Folder;

#ifdef __cplusplus

class DECLSPEC_UUID("C06966A4-9F1D-497F-84B9-9204F31994A3")
Imap4Folder;
#endif

EXTERN_C const CLSID CLSID_Mail;

#ifdef __cplusplus

class DECLSPEC_UUID("AE30137E-07C8-403F-8772-07AF79C1DD2E")
Mail;
#endif

EXTERN_C const CLSID CLSID_MailAddress;

#ifdef __cplusplus

class DECLSPEC_UUID("D6DA04B9-6D72-424A-9582-9752409AAD9C")
MailAddress;
#endif

EXTERN_C const CLSID CLSID_MailInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("CFED4866-F709-481F-89C1-4D1BF0F830D3")
MailInfo;
#endif

EXTERN_C const CLSID CLSID_MailServer;

#ifdef __cplusplus

class DECLSPEC_UUID("65ACB9B1-68E6-460B-9738-720E0E3A6DD3")
MailServer;
#endif

EXTERN_C const CLSID CLSID_MailReport;

#ifdef __cplusplus

class DECLSPEC_UUID("029033B3-0CFF-452E-8832-8101FDE8D0B4")
MailReport;
#endif

EXTERN_C const CLSID CLSID_Tools;

#ifdef __cplusplus

class DECLSPEC_UUID("8B092B61-AE66-4413-B4D0-6B97FBE6DA08")
Tools;
#endif

EXTERN_C const CLSID CLSID_UIDLManager;

#ifdef __cplusplus

class DECLSPEC_UUID("440B896B-8AAD-4FEE-8F39-066F79F73E5C")
UIDLManager;
#endif

EXTERN_C const CLSID CLSID_UIDLItem;

#ifdef __cplusplus

class DECLSPEC_UUID("7096722C-E10D-42D9-A284-1E582D2B27B3")
UIDLItem;
#endif

EXTERN_C const CLSID CLSID_GetMailInfosParamType;

#ifdef __cplusplus

class DECLSPEC_UUID("B511D930-097E-4E90-9753-956A067D9E0E")
GetMailInfosParamType;
#endif

EXTERN_C const CLSID CLSID_AddressCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("624D5C57-88A2-4F35-9F3A-5D7CFB18D048")
AddressCollection;
#endif

EXTERN_C const CLSID CLSID_AttachmentCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("149A39C9-6C10-49D7-8B8A-D46F5E529315")
AttachmentCollection;
#endif

EXTERN_C const CLSID CLSID_MailInfoCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("77072FF5-D841-4B03-BFD0-BD0D038E71CB")
MailInfoCollection;
#endif

EXTERN_C const CLSID CLSID_FolderCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("59A2F86B-1007-4262-A8AF-D4A912C2A5DD")
FolderCollection;
#endif

EXTERN_C const CLSID CLSID_CategoryCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("05F813DF-CAE6-43C0-AF72-738869697FC0")
CategoryCollection;
#endif

EXTERN_C const CLSID CLSID_Category;

#ifdef __cplusplus

class DECLSPEC_UUID("0565E510-02C1-4A2A-AAF6-42A0AEA7C5D0")
Category;
#endif

EXTERN_C const CLSID CLSID_SimpleJsonArray;

#ifdef __cplusplus

class DECLSPEC_UUID("704C7CE4-C00B-4784-80EA-79F865B3ADCC")
SimpleJsonArray;
#endif

EXTERN_C const CLSID CLSID_SimpleJsonParser;

#ifdef __cplusplus

class DECLSPEC_UUID("A308FA17-B94E-4881-9C1E-E30B936E42C2")
SimpleJsonParser;
#endif

EXTERN_C const CLSID CLSID_OAuthResponseParser;

#ifdef __cplusplus

class DECLSPEC_UUID("faf4de6f-1303-4851-b659-8f8beb51f1a0")
OAuthResponseParser;
#endif

#ifndef __IOAuthResponseParser_INTERFACE_DEFINED__
#define __IOAuthResponseParser_INTERFACE_DEFINED__

/* interface IOAuthResponseParser */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOAuthResponseParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2cba3e15-44bb-428c-9dd5-68dc02957c37")
    IOAuthResponseParser : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR input) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AccessToken( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RefreshToken( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IdToken( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TokenExpiresInSeconds( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EmailInIdToken( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOAuthResponseParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOAuthResponseParser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOAuthResponseParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOAuthResponseParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOAuthResponseParser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOAuthResponseParser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOAuthResponseParser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOAuthResponseParser * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IOAuthResponseParser * This,
            /* [in] */ BSTR input);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AccessToken )( 
            IOAuthResponseParser * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RefreshToken )( 
            IOAuthResponseParser * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IdToken )( 
            IOAuthResponseParser * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TokenExpiresInSeconds )( 
            IOAuthResponseParser * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EmailInIdToken )( 
            IOAuthResponseParser * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IOAuthResponseParserVtbl;

    interface IOAuthResponseParser
    {
        CONST_VTBL struct IOAuthResponseParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOAuthResponseParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOAuthResponseParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOAuthResponseParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOAuthResponseParser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOAuthResponseParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOAuthResponseParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOAuthResponseParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOAuthResponseParser_Load(This,input)	\
    ( (This)->lpVtbl -> Load(This,input) ) 

#define IOAuthResponseParser_get_AccessToken(This,pVal)	\
    ( (This)->lpVtbl -> get_AccessToken(This,pVal) ) 

#define IOAuthResponseParser_get_RefreshToken(This,pVal)	\
    ( (This)->lpVtbl -> get_RefreshToken(This,pVal) ) 

#define IOAuthResponseParser_get_IdToken(This,pVal)	\
    ( (This)->lpVtbl -> get_IdToken(This,pVal) ) 

#define IOAuthResponseParser_get_TokenExpiresInSeconds(This,pVal)	\
    ( (This)->lpVtbl -> get_TokenExpiresInSeconds(This,pVal) ) 

#define IOAuthResponseParser_get_EmailInIdToken(This,pVal)	\
    ( (This)->lpVtbl -> get_EmailInIdToken(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOAuthResponseParser_INTERFACE_DEFINED__ */


#ifndef __IImap4Folder_INTERFACE_DEFINED__
#define __IImap4Folder_INTERFACE_DEFINED__

/* interface IImap4Folder */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImap4Folder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("860EA4DE-9B7D-4C1B-8DC0-67B74B981F41")
    IImap4Folder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FullPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FullPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAP4FolderFlags( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAP4FolderFlags( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LocalPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subscribed( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subscribed( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServerPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubFolders( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoSelect( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoSelect( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChangeKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChangeKey( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UID( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UID( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindChild( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IImap4Folder **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ VARIANT Folders,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IImap4Folder **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EWSPublicFolder( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EWSPublicFolder( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubFolderList( 
            /* [retval][out] */ IFolderCollection **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImap4FolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImap4Folder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImap4Folder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImap4Folder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImap4Folder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImap4Folder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImap4Folder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImap4Folder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FullPath )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAP4FolderFlags )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAP4FolderFlags )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalPath )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subscribed )( 
            IImap4Folder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Subscribed )( 
            IImap4Folder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerPath )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServerPath )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubFolders )( 
            IImap4Folder * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IImap4Folder * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoSelect )( 
            IImap4Folder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoSelect )( 
            IImap4Folder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChangeKey )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChangeKey )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UID )( 
            IImap4Folder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UID )( 
            IImap4Folder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindChild )( 
            IImap4Folder * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IImap4Folder **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            IImap4Folder * This,
            /* [in] */ VARIANT Folders,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IImap4Folder **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EWSPublicFolder )( 
            IImap4Folder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EWSPublicFolder )( 
            IImap4Folder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubFolderList )( 
            IImap4Folder * This,
            /* [retval][out] */ IFolderCollection **pVal);
        
        END_INTERFACE
    } IImap4FolderVtbl;

    interface IImap4Folder
    {
        CONST_VTBL struct IImap4FolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImap4Folder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImap4Folder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImap4Folder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImap4Folder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImap4Folder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImap4Folder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImap4Folder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IImap4Folder_get_FullPath(This,pVal)	\
    ( (This)->lpVtbl -> get_FullPath(This,pVal) ) 

#define IImap4Folder_put_FullPath(This,newVal)	\
    ( (This)->lpVtbl -> put_FullPath(This,newVal) ) 

#define IImap4Folder_get_IMAP4FolderFlags(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAP4FolderFlags(This,pVal) ) 

#define IImap4Folder_put_IMAP4FolderFlags(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAP4FolderFlags(This,newVal) ) 

#define IImap4Folder_get_LocalPath(This,pVal)	\
    ( (This)->lpVtbl -> get_LocalPath(This,pVal) ) 

#define IImap4Folder_put_LocalPath(This,newVal)	\
    ( (This)->lpVtbl -> put_LocalPath(This,newVal) ) 

#define IImap4Folder_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IImap4Folder_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IImap4Folder_get_Subscribed(This,pVal)	\
    ( (This)->lpVtbl -> get_Subscribed(This,pVal) ) 

#define IImap4Folder_put_Subscribed(This,newVal)	\
    ( (This)->lpVtbl -> put_Subscribed(This,newVal) ) 

#define IImap4Folder_get_ServerPath(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerPath(This,pVal) ) 

#define IImap4Folder_put_ServerPath(This,newVal)	\
    ( (This)->lpVtbl -> put_ServerPath(This,newVal) ) 

#define IImap4Folder_get_SubFolders(This,pVal)	\
    ( (This)->lpVtbl -> get_SubFolders(This,pVal) ) 

#define IImap4Folder_Init(This,newVal)	\
    ( (This)->lpVtbl -> Init(This,newVal) ) 

#define IImap4Folder_get_NoSelect(This,pVal)	\
    ( (This)->lpVtbl -> get_NoSelect(This,pVal) ) 

#define IImap4Folder_put_NoSelect(This,newVal)	\
    ( (This)->lpVtbl -> put_NoSelect(This,newVal) ) 

#define IImap4Folder_get_ChangeKey(This,pVal)	\
    ( (This)->lpVtbl -> get_ChangeKey(This,pVal) ) 

#define IImap4Folder_put_ChangeKey(This,newVal)	\
    ( (This)->lpVtbl -> put_ChangeKey(This,newVal) ) 

#define IImap4Folder_get_UID(This,pVal)	\
    ( (This)->lpVtbl -> get_UID(This,pVal) ) 

#define IImap4Folder_put_UID(This,newVal)	\
    ( (This)->lpVtbl -> put_UID(This,newVal) ) 

#define IImap4Folder_FindChild(This,Name,pVal)	\
    ( (This)->lpVtbl -> FindChild(This,Name,pVal) ) 

#define IImap4Folder_Find(This,Folders,Name,pVal)	\
    ( (This)->lpVtbl -> Find(This,Folders,Name,pVal) ) 

#define IImap4Folder_get_EWSPublicFolder(This,pVal)	\
    ( (This)->lpVtbl -> get_EWSPublicFolder(This,pVal) ) 

#define IImap4Folder_put_EWSPublicFolder(This,newVal)	\
    ( (This)->lpVtbl -> put_EWSPublicFolder(This,newVal) ) 

#define IImap4Folder_get_SubFolderList(This,pVal)	\
    ( (This)->lpVtbl -> get_SubFolderList(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImap4Folder_INTERFACE_DEFINED__ */

#endif /* __EAGetMailObjLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


