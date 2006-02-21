//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id: pgfeatures.h 4875 2006-01-06 21:06:46Z dpage $
// Copyright (C) 2002 - 2006, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// pgfeatures.h PostgreSQL features constants
//
//////////////////////////////////////////////////////////////////////////


#ifndef __FEATURE_H
#define __FEATURE_H

enum
{
    FEATURE_INITIALIZED=0,
    FEATURE_SIZE,
    FEATURE_FILEREAD,
    FEATURE_ROTATELOG,
    FEATURE_POSTMASTER_STARTTIME,
    FEATURE_TERMINATE_BACKEND,
    FEATURE_RELOAD_CONF,
    FEATURE_LAST
};

#endif
