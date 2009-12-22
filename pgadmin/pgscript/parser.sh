#!/bin/sh

#######################################################################
#
# pgAdmin III - PostgreSQL Tools
# Copyright (C) 2002 - 2009, The pgAdmin Development Team
# This software is released under the BSD Licence
#
# parser.sh - Runs Flex and Bison and processes the generated files
#
#######################################################################

# Directory containing pgScript includes (relative to the src directory)
INCLUDEDIR="include/pgscript"
# Directory containing pgScript sources (relative to the src directory)
SOURCEDIR="pgscript"
# Headers generated by Bison that need to be moved to ${INCLUDEDIR}
FILESTOMOVE=( "location.hh" "parser.tab.hh" "position.hh" "stack.hh" )

# Flex destination
LEXER="pgscript/lex.pgs.cc"
# A temporary file
AUX="pgscript/auxfile"
# Bison destination
PARSER="pgscript/parser.tab.cc"

#######################################################################

# Find the current directory
THISDIR=`dirname $0`
PREVDIR="$PWD"

# Go to the directory on top of the script directory
echo -n "cd ${THISDIR}/.. ... "
cd "${THISDIR}/.."
echo "done"
pwd
echo ""

# Generate Bison file
echo -n "+ Generating Bison output... "
bison -o"${PARSER}" "${SOURCEDIR}/pgsParser.yy"
echo "done"

# Generate Flex file
echo -n "+ Generating Flex output... "
flex -o"${LEXER}" "${SOURCEDIR}/pgsScanner.ll"
echo "done"

# Add pgAdmin3.h include at the beginning and change <FlexLexer.h> to
# "pgscript/FlexLexer.h" for the Flex output
echo -n "+ Processing Flex output... "
cat "${LEXER}" | awk 'BEGIN {print "#include \"pgAdmin3.h\"\n\n"}{print $0}' \
	| sed -e 's/<FlexLexer\.h>/"pgscript\/FlexLexer\.h"/g' > "${AUX}"
mv -f "${AUX}" "${LEXER}"
echo "done"

# Add pgAdmin3.h include at the beginning and a pragma and change
# "parser.tab.hh" to "pgscript/parser.tab.hh" to the Bison output
echo -n "+ Processing Bison output... "
cat "${PARSER}" | awk 'BEGIN {print "#include \"pgAdmin3.h\"\n#if _MSC_VER > 1000\n#pragma warning(disable: 4800)\n#endif\n"}{print $0}' | \
	sed -e 's/"parser.tab.hh"/"pgscript\/parser\.tab\.hh"/g' > "${AUX}"
sleep 1
mv -f "${AUX}" "${PARSER}"
echo "done"

# Move Bison include files to the include directory
echo + "Moving Bison header files... "
for file in ${FILESTOMOVE[@]}
do
	echo "    + mv ${SOURCEDIR}/${file} ${INCLUDEDIR}/${file}"
	mv "${SOURCEDIR}/${file}" "${INCLUDEDIR}/${file}"
done
echo "... done"

# Go back to the previous directory
echo ""
echo -n "cd $PREVDIR ... "
cd "$PREVDIR"
echo "done"