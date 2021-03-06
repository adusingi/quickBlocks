#pragma once
/*-------------------------------------------------------------------------------------------
 * qblocks - fast, easily-accessible, fully-decentralized data from blockchains
 * copyright (c) 2018 Great Hill Corporation (http://greathill.com)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include <vector>
#include <map>
#include "transaction.h"

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class QSetDailyLimit : public CTransaction {
public:
    biguint_t _newLimit;

public:
    QSetDailyLimit(void);
    QSetDailyLimit(const QSetDailyLimit& se);
    virtual ~QSetDailyLimit(void);
    QSetDailyLimit& operator=(const QSetDailyLimit& se);

    DECLARE_NODE(QSetDailyLimit);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const QSetDailyLimit& item) const;
    bool operator!=(const QSetDailyLimit& item) const { return !operator==(item); }
    friend bool operator<(const QSetDailyLimit& v1, const QSetDailyLimit& v2);
    friend ostream& operator<<(ostream& os, const QSetDailyLimit& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const QSetDailyLimit& se);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline QSetDailyLimit::QSetDailyLimit(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline QSetDailyLimit::QSetDailyLimit(const QSetDailyLimit& se) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(se);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline QSetDailyLimit::~QSetDailyLimit(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QSetDailyLimit::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QSetDailyLimit::initialize(void) {
    CTransaction::initialize();

    _newLimit = 0;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QSetDailyLimit::duplicate(const QSetDailyLimit& se) {
    clear();
    CTransaction::duplicate(se);

    _newLimit = se._newLimit;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline QSetDailyLimit& QSetDailyLimit::operator=(const QSetDailyLimit& se) {
    duplicate(se);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool QSetDailyLimit::operator==(const QSetDailyLimit& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const QSetDailyLimit& v1, const QSetDailyLimit& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<QSetDailyLimit> QSetDailyLimitArray;
extern CArchive& operator>>(CArchive& archive, QSetDailyLimitArray& array);
extern CArchive& operator<<(CArchive& archive, const QSetDailyLimitArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

