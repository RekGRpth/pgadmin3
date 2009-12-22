//////////////////////////////////////////////////////////////////////////
//
// pgScript - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2009, The pgAdmin Development Team
// This software is released under the BSD Licence
//
//////////////////////////////////////////////////////////////////////////


#ifndef PGSCONTINUEEXCEPTION_H_
#define PGSCONTINUEEXCEPTION_H_

#include "pgscript/pgScript.h"
#include "pgscript/exceptions/pgsException.h"

class pgsContinueException : public pgsException
{
	
public:
	
	pgsContinueException();
	
	virtual ~pgsContinueException();
	
	virtual const wxString message() const;
	
};

#endif /*PGSCONTINUEEXCEPTION_H_*/