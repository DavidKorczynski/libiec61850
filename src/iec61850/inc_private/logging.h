/*
 *  logging.h
 *
 *  Copyright 2016 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */


#ifndef LIBIEC61850_SRC_IEC61850_INC_PRIVATE_LOGGING_H_
#define LIBIEC61850_SRC_IEC61850_INC_PRIVATE_LOGGING_H_

typedef struct {
    char* name;
    LogicalNode* parentLN;

    LogStorage logStorage;

    uint64_t newEntryId;
    uint64_t newEntryTime;

    uint64_t oldEntryId;
    uint64_t oldEntryTime;

} LogInstance;

typedef struct {
    char* name;
    LogControlBlock* logControlBlock;
    MmsMapping* mmsMapping;

    DataSet* dataSet;
    char* dataSetRef;

    LogicalNode* logicalNode;
    MmsDomain* domain;

    MmsValue* mmsValue;
    MmsVariableSpecification* mmsType;

    MmsValue* oldEntr;
    MmsValue* oldEntrTm;
    MmsValue* newEntr;
    MmsValue* newEntrTm;

    LogInstance* logInstance;

    bool enabled;

    int triggerOps;

} LogControl;


LogInstance*
LogInstance_create(LogicalNode* parentLN, const char* name);

void
LogInstance_setLogStorage(LogInstance* self, LogStorage logStorage);

void
LogInstance_logSingleData(LogInstance* self, const char* dataRef, MmsValue* value, uint8_t flag);

void
LogInstance_destroy(LogInstance* self);

LogControl*
LogControl_create(LogicalNode* parentLN, MmsMapping* mmsMapping);

void
LogControl_destroy(LogControl* self);

void
LogControl_setLogStorage(LogControl* self, LogStorage logStorage);

MmsVariableSpecification*
Logging_createLCBs(MmsMapping* self, MmsDomain* domain, LogicalNode* logicalNode,
        int lcbCount);

MmsValue*
LIBIEC61850_LOG_SVC_readAccessControlBlock(MmsMapping* self, MmsDomain* domain, char* variableIdOrig);

#endif /* LIBIEC61850_SRC_IEC61850_INC_PRIVATE_LOGGING_H_ */
