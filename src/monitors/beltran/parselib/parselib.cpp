/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
/*
 * This code was generated automatically from grabABI and makeClass. You may
 * edit the file, but keep your edits inside the 'EXISTING_CODE' tags.
 *
 * This monitor code is part of the 'beltran' monitor.
 */
#include "tokenlib.h"
#include "walletlib.h"
#include "parselib.h"

//-----------------------------------------------------------------------
void parselib_init(QUITHANDLER qh) {
    etherlib_init(qh);

    CAuctionStartedEvent::registerClass();
    CBidRevealedEvent::registerClass();
    CHashInvalidatedEvent::registerClass();
    CHashRegisteredEvent::registerClass();
    CHashReleasedEvent::registerClass();
    CNewBidEvent::registerClass();
    CAcceptRegistrarTransfer::registerClass();
    CCancelBid::registerClass();
    CEraseNode::registerClass();
    CFinalizeAuction::registerClass();
    CInvalidateName::registerClass();
    CNewBid::registerClass();
    CReleaseDeed::registerClass();
    CStartAuction::registerClass();
    CStartAuctions::registerClass();
    CStartAuctionsAndBid::registerClass();
    CTransfer::registerClass();
    CTransferAnyERC20Token::registerClass();
    CTransferOwnership::registerClass();
    CTransferRegistrars::registerClass();
    CUnsealBid::registerClass();
    CUnsealBid0122::registerClass();

    tokenlib_init();
}

//-----------------------------------------------------------------------
static const string_q func_acceptRegistrarTransfer = "0xea9e107a";
static const string_q func_cancelBid = "0x2525f5c1";
static const string_q func_ens = "0x3f15457f";
static const string_q func_entries = "0x267b6922";
static const string_q func_eraseNode = "0xde10f04b";
static const string_q func_finalizeAuction = "0x983b94fb";
static const string_q func_getAllowedTime = "0x13c89a8f";
static const string_q func_invalidateName = "0x15f73331";
static const string_q func_isAllowed = "0x93503337";
static const string_q func_launchLength = "0xae1a0b0c";
static const string_q func_newBid = "0xce92dced";
static const string_q func_owner = "0x8da5cb5b";
static const string_q func_registryStarted = "0x9c67f06f";
static const string_q func_releaseDeed = "0x0230a07c";
static const string_q func_rootNode = "0xfaff50a8";
static const string_q func_sealedBids = "0x5e431709";
static const string_q func_shaBid = "0x22ec1244";
static const string_q func_startAuction = "0xede8acdb";
static const string_q func_startAuctions = "0xe27fe50f";
static const string_q func_startAuctionsAndBid = "0xfebefd61";
static const string_q func_state = "0x61d585da";
static const string_q func_transfer = "0x79ce9fac";
static const string_q func_transferAnyERC20Token = "0xdc39d06d";
static const string_q func_transferOwnership = "0xf2fde38b";
static const string_q func_transferRegistrars = "0x5ddae283";
static const string_q func_unsealBid = "0x47872b42";
static const string_q func_unsealBid0122 = "0xaefc8c72";

//-----------------------------------------------------------------------
const CTransaction *promoteToFunc(const CTransaction *p) {

    if (p && (p->input.length() >= 10 || p->input == "0x")) {
        string_q items[256];
        size_t nItems = 0;

        string_q encoding = extract(p->input, 0, 10);
        string_q params   = extract(p->input, 10);
        // EXISTING_CODE
        // EXISTING_CODE

        if (encoding == func_acceptRegistrarTransfer) {
            // function acceptRegistrarTransfer(bytes32 hash, address deed, uint256 registrationDate)
            // 0xea9e107a
            CAcceptRegistrarTransfer *a = new CAcceptRegistrarTransfer;
            a->CTransaction::operator=(*p);
            a->hash = extract(params, 0*64, 64);
            a->deed = str_2_Addr(extract(params, 1*64, 64));
            a->registrationDate = str_2_Wei("0x" + extract(params, 2*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "address";
            items[nItems++] = "uint256";
            a->articulatedTx = decodeRLP("acceptRegistrarTransfer", params, nItems, items);
            return a;

        } else if (encoding == func_cancelBid) {
            // function cancelBid(address bidder, bytes32 seal)
            // 0x2525f5c1
            CCancelBid *a = new CCancelBid;
            a->CTransaction::operator=(*p);
            a->bidder = str_2_Addr(extract(params, 0*64, 64));
            a->seal = extract(params, 1*64, 64);
            items[nItems++] = "address";
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("cancelBid", params, nItems, items);
            return a;

        } else if (encoding == func_eraseNode) {
            // function eraseNode(bytes32[] labels)
            // 0xde10f04b
            CEraseNode *a = new CEraseNode;
            a->CTransaction::operator=(*p);
            while (!params.empty()) {
                string_q val = extract(params, 0, 64);
                params = extract(params, 64);
                a->labels.push_back(val);
            }
            items[nItems++] = "bytes32[]";
            a->articulatedTx = decodeRLP("eraseNode", params, nItems, items);
            return a;

        } else if (encoding == func_finalizeAuction) {
            // function finalizeAuction(bytes32 _hash)
            // 0x983b94fb
            CFinalizeAuction *a = new CFinalizeAuction;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("finalizeAuction", params, nItems, items);
            return a;

        } else if (encoding == func_invalidateName) {
            // function invalidateName(string unhashedName)
            // 0x15f73331
            CInvalidateName *a = new CInvalidateName;
            a->CTransaction::operator=(*p);
            a->unhashedName = extract(params, 0*64, 64);
            items[nItems++] = "string";
            a->articulatedTx = decodeRLP("invalidateName", params, nItems, items);
            return a;

        } else if (encoding == func_newBid) {
            // function newBid(bytes32 sealedBid)
            // 0xce92dced
            CNewBid *a = new CNewBid;
            a->CTransaction::operator=(*p);
            a->sealedBid = extract(params, 0*64, 64);
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("newBid", params, nItems, items);
            return a;

        } else if (encoding == func_releaseDeed) {
            // function releaseDeed(bytes32 _hash)
            // 0x0230a07c
            CReleaseDeed *a = new CReleaseDeed;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("releaseDeed", params, nItems, items);
            return a;

        } else if (encoding == func_startAuction) {
            // function startAuction(bytes32 _hash)
            // 0xede8acdb
            CStartAuction *a = new CStartAuction;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("startAuction", params, nItems, items);
            return a;

        } else if (encoding == func_startAuctions) {
            // function startAuctions(bytes32[] _hashes)
            // 0xe27fe50f
            CStartAuctions *a = new CStartAuctions;
            a->CTransaction::operator=(*p);
            while (!params.empty()) {
                string_q val = extract(params, 0, 64);
                params = extract(params, 64);
                a->_hashes.push_back(val);
            }
            items[nItems++] = "bytes32[]";
            a->articulatedTx = decodeRLP("startAuctions", params, nItems, items);
            return a;

        } else if (encoding == func_startAuctionsAndBid) {
            // function startAuctionsAndBid(bytes32[] hashes, bytes32 sealedBid)
            // 0xfebefd61
            CStartAuctionsAndBid *a = new CStartAuctionsAndBid;
            a->CTransaction::operator=(*p);
            while (!params.empty()) {
                string_q val = extract(params, 0, 64);
                params = extract(params, 64);
                a->hashes.push_back(val);
            }
            a->sealedBid = extract(params, 1*64, 64);
            items[nItems++] = "bytes32[]";
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("startAuctionsAndBid", params, nItems, items);
            return a;

        } else if (encoding == func_transfer) {
            // function transfer(bytes32 _hash, address newOwner)
            // 0x79ce9fac
            CTransfer *a = new CTransfer;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            a->newOwner = str_2_Addr(extract(params, 1*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "address";
            a->articulatedTx = decodeRLP("transfer", params, nItems, items);
            return a;

        } else if (encoding == func_transferAnyERC20Token) {
            // function transferAnyERC20Token(address tokenAddress, uint256 amount)
            // 0xdc39d06d
            CTransferAnyERC20Token *a = new CTransferAnyERC20Token;
            a->CTransaction::operator=(*p);
            a->tokenAddress = str_2_Addr(extract(params, 0*64, 64));
            a->amount = str_2_Wei("0x" + extract(params, 1*64, 64));
            items[nItems++] = "address";
            items[nItems++] = "uint256";
            a->articulatedTx = decodeRLP("transferAnyERC20Token", params, nItems, items);
            return a;

        } else if (encoding == func_transferOwnership) {
            // function transferOwnership(address _newOwner)
            // 0xf2fde38b
            CTransferOwnership *a = new CTransferOwnership;
            a->CTransaction::operator=(*p);
            a->_newOwner = str_2_Addr(extract(params, 0*64, 64));
            items[nItems++] = "address";
            a->articulatedTx = decodeRLP("transferOwnership", params, nItems, items);
            return a;

        } else if (encoding == func_transferRegistrars) {
            // function transferRegistrars(bytes32 _hash)
            // 0x5ddae283
            CTransferRegistrars *a = new CTransferRegistrars;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("transferRegistrars", params, nItems, items);
            return a;

        } else if (encoding == func_unsealBid) {
            // function unsealBid(bytes32 _hash, uint256 _value, bytes32 _salt)
            // 0x47872b42
            CUnsealBid *a = new CUnsealBid;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            a->_value = str_2_Wei("0x" + extract(params, 1*64, 64));
            a->_salt = extract(params, 2*64, 64);
            items[nItems++] = "bytes32";
            items[nItems++] = "uint256";
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("unsealBid", params, nItems, items);
            return a;

        } else if (encoding == func_unsealBid0122) {
            // function unsealBid(bytes32 _hash, address _owner, uint256 _value, bytes32 _salt)
            // 0xaefc8c72
            CUnsealBid0122 *a = new CUnsealBid0122;
            a->CTransaction::operator=(*p);
            a->_hash = extract(params, 0*64, 64);
            a->_owner = str_2_Addr(extract(params, 1*64, 64));
            a->_value = str_2_Wei("0x" + extract(params, 2*64, 64));
            a->_salt = extract(params, 3*64, 64);
            items[nItems++] = "bytes32";
            items[nItems++] = "address";
            items[nItems++] = "uint256";
            items[nItems++] = "bytes32";
            a->articulatedTx = decodeRLP("unsealBid0122", params, nItems, items);
            return a;

        }
        // falls through
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // never returns NULL
    return promoteToToken(p);
}

//-----------------------------------------------------------------------
static const string_q evt_AuctionStarted = "0x87e97e825a1d1fa0c54e1d36c7506c1dea8b1efd451fe68b000cf96f7cf40003";
static const string_q evt_BidRevealed = "0x7b6c4b278d165a6b33958f8ea5dfb00c8c9d4d0acf1985bef5d10786898bc3e7";
static const string_q evt_HashInvalidated = "0x1f9c649fe47e58bb60f4e52f0d90e4c47a526c9f90c5113df842c025970b66ad";
static const string_q evt_HashRegistered = "0x0f0c27adfd84b60b6f456b0e87cdccb1e5fb9603991588d87fa99f5b6b61e670";
static const string_q evt_HashReleased = "0x292b79b9246fa2c8e77d3fe195b251f9cb839d7d038e667c069ee7708c631e16";
static const string_q evt_NewBid = "0xb556ff269c1b6714f432c36431e2041d28436a73b6c3f19c021827bbdc6bfc29";

//-----------------------------------------------------------------------
const CLogEntry *promoteToEvent(const CLogEntry *p) {

    size_t nTops = p->topics.size();
    if (nTops > 0) {  // the '0'th topic is the event signature
        string_q items[256];
        size_t nItems = 0;
        string_q data = extract(p->data, 2);
        string_q params;
        bool first = true;
        for (auto t : p->topics) {
            if (!first)
                params += extract(topic_2_Str(t),2);
            first = false;
        }
        params += data;
        // EXISTING_CODE
        // EXISTING_CODE

        if (topic_2_Str(p->topics[0]) % evt_AuctionStarted) {
            // event AuctionStarted(bytes32 indexed hash, uint256 registrationDate)
            // 0x87e97e825a1d1fa0c54e1d36c7506c1dea8b1efd451fe68b000cf96f7cf40003
            CAuctionStartedEvent *a = new CAuctionStartedEvent;
            a->CLogEntry::operator=(*p);
            a->hash = nTops > 1 ? topic_2_Str(p->topics[1]) : "";
            a->registrationDate = str_2_Wei("0x" + extract(data, 0*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "uint256";
            a->articulatedLog = decodeRLP("AuctionStarted", params, nItems, items);
            return a;

        } else if (topic_2_Str(p->topics[0]) % evt_BidRevealed) {
            // event BidRevealed(bytes32 indexed hash, address indexed owner, uint256 value, uint8 status)
            // 0x7b6c4b278d165a6b33958f8ea5dfb00c8c9d4d0acf1985bef5d10786898bc3e7
            CBidRevealedEvent *a = new CBidRevealedEvent;
            a->CLogEntry::operator=(*p);
            a->hash = nTops > 1 ? topic_2_Str(p->topics[1]) : "";
            a->owner = str_2_Addr(nTops > 2 ? topic_2_Str(p->topics[2]) : "");
            a->value = str_2_Wei("0x" + extract(data, 0*64, 64));
            a->status = (uint32_t)str_2_Uint("0x" + extract(data, 1*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "address";
            items[nItems++] = "uint256";
            items[nItems++] = "uint8";
            a->articulatedLog = decodeRLP("BidRevealed", params, nItems, items);
            return a;

        } else if (topic_2_Str(p->topics[0]) % evt_HashInvalidated) {
            // event HashInvalidated(bytes32 indexed hash, string indexed name, uint256 value, uint256 registrationDate)
            // 0x1f9c649fe47e58bb60f4e52f0d90e4c47a526c9f90c5113df842c025970b66ad
            CHashInvalidatedEvent *a = new CHashInvalidatedEvent;
            a->CLogEntry::operator=(*p);
            a->hash = nTops > 1 ? topic_2_Str(p->topics[1]) : "";
            a->name = nTops > 2 ? topic_2_Str(p->topics[2]) : "";
            a->value = str_2_Wei("0x" + extract(data, 0*64, 64));
            a->registrationDate = str_2_Wei("0x" + extract(data, 1*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "string";
            items[nItems++] = "uint256";
            items[nItems++] = "uint256";
            a->articulatedLog = decodeRLP("HashInvalidated", params, nItems, items);
            return a;

        } else if (topic_2_Str(p->topics[0]) % evt_HashRegistered) {
            // event HashRegistered(bytes32 indexed hash, address indexed owner, uint256 value, uint256 registrationDate)
            // 0x0f0c27adfd84b60b6f456b0e87cdccb1e5fb9603991588d87fa99f5b6b61e670
            CHashRegisteredEvent *a = new CHashRegisteredEvent;
            a->CLogEntry::operator=(*p);
            a->hash = nTops > 1 ? topic_2_Str(p->topics[1]) : "";
            a->owner = str_2_Addr(nTops > 2 ? topic_2_Str(p->topics[2]) : "");
            a->value = str_2_Wei("0x" + extract(data, 0*64, 64));
            a->registrationDate = str_2_Wei("0x" + extract(data, 1*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "address";
            items[nItems++] = "uint256";
            items[nItems++] = "uint256";
            a->articulatedLog = decodeRLP("HashRegistered", params, nItems, items);
            return a;

        } else if (topic_2_Str(p->topics[0]) % evt_HashReleased) {
            // event HashReleased(bytes32 indexed hash, uint256 value)
            // 0x292b79b9246fa2c8e77d3fe195b251f9cb839d7d038e667c069ee7708c631e16
            CHashReleasedEvent *a = new CHashReleasedEvent;
            a->CLogEntry::operator=(*p);
            a->hash = nTops > 1 ? topic_2_Str(p->topics[1]) : "";
            a->value = str_2_Wei("0x" + extract(data, 0*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "uint256";
            a->articulatedLog = decodeRLP("HashReleased", params, nItems, items);
            return a;

        } else if (topic_2_Str(p->topics[0]) % evt_NewBid) {
            // event NewBid(bytes32 indexed hash, address indexed bidder, uint256 deposit)
            // 0xb556ff269c1b6714f432c36431e2041d28436a73b6c3f19c021827bbdc6bfc29
            CNewBidEvent *a = new CNewBidEvent;
            a->CLogEntry::operator=(*p);
            a->hash = nTops > 1 ? topic_2_Str(p->topics[1]) : "";
            a->bidder = str_2_Addr(nTops > 2 ? topic_2_Str(p->topics[2]) : "");
            a->deposit = str_2_Wei("0x" + extract(data, 0*64, 64));
            items[nItems++] = "bytes32";
            items[nItems++] = "address";
            items[nItems++] = "uint256";
            a->articulatedLog = decodeRLP("NewBid", params, nItems, items);
            return a;

        }
        // fall through
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // never returns NULL
    return promoteToTokenEvent(p);
}

/*
 ABI for addr : 0x1d40c444ad973d9ddc7c14989d96b5a01ed0afda
 {"status":"0","message":"NOTOK","result":"Contractsourcecodenotverified"}

 ABI for addr : 0x314159265dd8dbb310642f98f50c066173c1259b
 {"status":"0","message":"NOTOK","result":"Contractsourcecodenotverified"}

 ABI for addr : 0x6090a6e47849629b7245dfa1ca21d94cd15878ef
 [{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"releaseDeed","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"getAllowedTime","outputs":[{"name":"timestamp","type":"uint256"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"unhashedName","type":"string"}],"name":"invalidateName","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"hash","type":"bytes32"},{"name":"owner","type":"address"},{"name":"value","type":"uint256"},{"name":"salt","type":"bytes32"}],"name":"shaBid","outputs":[{"name":"sealedBid","type":"bytes32"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"bidder","type":"address"},{"name":"seal","type":"bytes32"}],"name":"cancelBid","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"entries","outputs":[{"name":"","type":"uint8"},{"name":"","type":"address"},{"name":"","type":"uint256"},{"name":"","type":"uint256"},{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"ens","outputs":[{"name":"","type":"address"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"},{"name":"_value","type":"uint256"},{"name":"_salt","type":"bytes32"}],"name":"unsealBid","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"transferRegistrars","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"address"},{"name":"","type":"bytes32"}],"name":"sealedBids","outputs":[{"name":"","type":"address"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"state","outputs":[{"name":"","type":"uint8"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"},{"name":"newOwner","type":"address"}],"name":"transfer","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"_hash","type":"bytes32"},{"name":"_timestamp","type":"uint256"}],"name":"isAllowed","outputs":[{"name":"allowed","type":"bool"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"finalizeAuction","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"registryStarted","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"launchLength","outputs":[{"name":"","type":"uint32"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"sealedBid","type":"bytes32"}],"name":"newBid","outputs":[],"payable":true,"type":"function"},{"constant":false,"inputs":[{"name":"labels","type":"bytes32[]"}],"name":"eraseNode","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hashes","type":"bytes32[]"}],"name":"startAuctions","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"hash","type":"bytes32"},{"name":"deed","type":"address"},{"name":"registrationDate","type":"uint256"}],"name":"acceptRegistrarTransfer","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"startAuction","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"rootNode","outputs":[{"name":"","type":"bytes32"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"hashes","type":"bytes32[]"},{"name":"sealedBid","type":"bytes32"}],"name":"startAuctionsAndBid","outputs":[],"payable":true,"type":"function"},{"inputs":[{"name":"_ens","type":"address"},{"name":"_rootNode","type":"bytes32"},{"name":"_startDate","type":"uint256"}],"payable":false,"type":"constructor"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":false,"name":"registrationDate","type":"uint256"}],"name":"AuctionStarted","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"bidder","type":"address"},{"indexed":false,"name":"deposit","type":"uint256"}],"name":"NewBid","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"owner","type":"address"},{"indexed":false,"name":"value","type":"uint256"},{"indexed":false,"name":"status","type":"uint8"}],"name":"BidRevealed","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"owner","type":"address"},{"indexed":false,"name":"value","type":"uint256"},{"indexed":false,"name":"registrationDate","type":"uint256"}],"name":"HashRegistered","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":false,"name":"value","type":"uint256"}],"name":"HashReleased","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"name","type":"string"},{"indexed":false,"name":"value","type":"uint256"},{"indexed":false,"name":"registrationDate","type":"uint256"}],"name":"HashInvalidated","type":"event"}]

 ABI for addr : 0x012233b3c8177f0778d910ed88170b82de3bfe57
 [{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"releaseDeed","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"unhashedName","type":"string"}],"name":"invalidateName","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"hash","type":"bytes32"},{"name":"owner","type":"address"},{"name":"value","type":"uint256"},{"name":"salt","type":"bytes32"}],"name":"shaBid","outputs":[{"name":"sealedBid","type":"bytes32"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"bidder","type":"address"},{"name":"seal","type":"bytes32"}],"name":"cancelBid","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"entries","outputs":[{"name":"","type":"uint8"},{"name":"","type":"address"},{"name":"","type":"uint256"},{"name":"","type":"uint256"},{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"ens","outputs":[{"name":"","type":"address"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"transferRegistrars","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"address"},{"name":"","type":"bytes32"}],"name":"sealedBids","outputs":[{"name":"","type":"address"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"state","outputs":[{"name":"","type":"uint8"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"},{"name":"newOwner","type":"address"}],"name":"transfer","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"finalizeAuction","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"registryStarted","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"},{"name":"_owner","type":"address"},{"name":"_value","type":"uint256"},{"name":"_salt","type":"bytes32"}],"name":"unsealBid","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"sealedBid","type":"bytes32"}],"name":"newBid","outputs":[],"payable":true,"type":"function"},{"constant":false,"inputs":[{"name":"_hashes","type":"bytes32[]"}],"name":"startAuctions","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"_hash","type":"bytes32"}],"name":"startAuction","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"rootNode","outputs":[{"name":"","type":"bytes32"}],"payable":false,"type":"function"},{"inputs":[{"name":"_ens","type":"address"},{"name":"_rootNode","type":"bytes32"},{"name":"_startDate","type":"uint256"}],"payable":false,"type":"constructor"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":false,"name":"registrationDate","type":"uint256"}],"name":"AuctionStarted","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"bidder","type":"address"},{"indexed":false,"name":"deposit","type":"uint256"}],"name":"NewBid","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"owner","type":"address"},{"indexed":false,"name":"value","type":"uint256"},{"indexed":false,"name":"status","type":"uint8"}],"name":"BidRevealed","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"owner","type":"address"},{"indexed":false,"name":"value","type":"uint256"},{"indexed":false,"name":"registrationDate","type":"uint256"}],"name":"HashRegistered","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":false,"name":"value","type":"uint256"}],"name":"HashReleased","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"hash","type":"bytes32"},{"indexed":true,"name":"name","type":"string"},{"indexed":false,"name":"value","type":"uint256"},{"indexed":false,"name":"registrationDate","type":"uint256"}],"name":"HashInvalidated","type":"event"}]

 ABI for addr : 0x1122b6a0e00dce0563082b6e2953f3a943855c1f
 [{"constant":true,"inputs":[],"name":"name","outputs":[{"name":"","type":"string"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"name":"_spender","type":"address"},{"name":"_value","type":"uint256"}],"name":"approve","outputs":[{"name":"success","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"totalSupply","outputs":[{"name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"name":"_from","type":"address"},{"name":"_to","type":"address"},{"name":"_value","type":"uint256"}],"name":"transferFrom","outputs":[{"name":"success","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"decimals","outputs":[{"name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[{"name":"_owner","type":"address"}],"name":"balanceOf","outputs":[{"name":"balance","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"owner","outputs":[{"name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"symbol","outputs":[{"name":"","type":"string"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"name":"_to","type":"address"},{"name":"_value","type":"uint256"}],"name":"transfer","outputs":[{"name":"success","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":false,"inputs":[{"name":"tokenAddress","type":"address"},{"name":"amount","type":"uint256"}],"name":"transferAnyERC20Token","outputs":[{"name":"success","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[{"name":"_owner","type":"address"},{"name":"_spender","type":"address"}],"name":"allowance","outputs":[{"name":"remaining","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"name":"_newOwner","type":"address"}],"name":"transferOwnership","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"inputs":[],"payable":false,"stateMutability":"nonpayable","type":"constructor"},{"payable":false,"stateMutability":"nonpayable","type":"fallback"},{"anonymous":false,"inputs":[{"indexed":true,"name":"from","type":"address"},{"indexed":true,"name":"to","type":"address"},{"indexed":false,"name":"value","type":"uint256"}],"name":"Transfer","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"name":"owner","type":"address"},{"indexed":true,"name":"spender","type":"address"},{"indexed":false,"name":"value","type":"uint256"}],"name":"Approval","type":"event"}]

 */
