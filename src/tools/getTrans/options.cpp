/*-------------------------------------------------------------------------------------------
 * QuickBlocks - Decentralized, useful, and detailed data from Ethereum blockchains
 * Copyright (c) 2018 Great Hill Corporation (http://quickblocks.io)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
#include "options.h"

//---------------------------------------------------------------------------------------------------
CParams params[] = {
    CParams("~!trans_list", "a space-separated list of one or more transaction identifiers (tx_hash, bn.txID, blk_hash.txID)"),
    CParams("-raw",         "retrieve raw transaction directly from the running node"),
    CParams("-nTraces",     "report on how many traces the transaction generated and deepest trace"),
    CParams("@trace",       "include the transactions trace after the transaction"),
    CParams("",             "Retrieve an Ethereum transaction from the local cache or a running node."),
};
uint32_t nParams = sizeof(params) / sizeof(CParams);

//---------------------------------------------------------------------------------------------------
bool COptions::parseArguments(string_q& command) {

    if (!standardOptions(command))
        return false;

    Init();
    while (!command.empty()) {
        string_q arg = nextTokenClear(command, ' ');
        if (arg == "-r" || arg == "--raw") {
            isRaw = true;

        } else if (arg == "-t" || arg == "--trace") {
            incTrace = true;

        } else if (arg == "-n" || arg == "--nTraces") {
            nTraces = true;

        } else if (startsWith(arg, '-')) {  // do not collapse

            if (!builtInCmd(arg)) {
                return usage("Invalid option: " + arg);
            }

        } else {

            string_q ret = transList.parseTransList(arg);
            if (!ret.empty())
                return usage(ret);

        }
    }

    if (!transList.hasTrans())
        return usage("Please specify at least one transaction identifier.");

extern const char* STR_DISPLAY_FORMAT;
    format = getGlobalConfig()->getDisplayStr(!verbose, (verbose ? "" : STR_DISPLAY_FORMAT));

    return true;
}

//---------------------------------------------------------------------------------------------------
void COptions::Init(void) {
    paramsPtr = params;
    nParamsRef = nParams;
    pOptions = this;

    transList.Init();
    isRaw = false;
    incTrace = false;
    nTraces = false;
    format = "";
}

//---------------------------------------------------------------------------------------------------
COptions::COptions(void) {
    // will sort the fields in these classes if --parity is given
    sorts[0] = GETRUNTIME_CLASS(CBlock);
    sorts[1] = GETRUNTIME_CLASS(CTransaction);
    sorts[2] = GETRUNTIME_CLASS(CReceipt);
    HIDE_FIELD(CTransaction, "cumulativeGasUsed");

    Init();
    // Don't reset these for each command
    nCmds = 0;
    nVisited = 0;
    if (isTestMode())
        UNHIDE_FIELD(CTransaction, "isError");
}

//--------------------------------------------------------------------------------
COptions::~COptions(void) {
}

//--------------------------------------------------------------------------------
string_q COptions::postProcess(const string_q& which, const string_q& str) const {
    if (which == "options") {
        return str.Substitute("trans_list","<transID> [transID...]");

    } else if (which == "notes" && (verbose || COptions::isReadme)) {

        string_q ret;
        ret += "[{trans_list}] is one or more space-separated identifiers which may be either a transaction hash,|"
                "a blockNumber.transactionID pair, or a blockHash.transactionID pair, or any combination.\n";
        ret += "This tool checks for valid input syntax, but does not check that the transaction requested exists.\n";
        ret += "This tool retrieves information from the local node or the ${FALLBACK} node, if configured (see documentation).\n";
        ret += "If the queried node does not store historical state, the results may be undefined.\n";
        return ret;
    }
    return str;
}

//--------------------------------------------------------------------------------
const char* STR_DISPLAY_FORMAT = "[{DATE}][\t{TIMESTAMP}][\t{BLOCKNUMBER}][\t{TRANSACTIONINDEX}][\t{HASH}]\\n";
