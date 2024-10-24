## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = subdir-objects foreign

SUBDIRS = src/funcs src/headers
include_HEADERS = src/headers/ishappynum.h src/headers/isSorted.h src/headers/removeNthFromEnd.h src/headers/longcommonprefix.h src/headers/mergestrings.h src/headers/mergesort.h src/headers/multiplystrings.h src/headers/findball.h src/headers/removeDupes.h src/headers/removeelement.h src/headers/spiralorder.h
leetcode = leetcode
leetcode_SOURCES=src/leetcode.c

#subdirHeaders = src/headers

bin_PROGRAMS = leetcode

## some rules to test...
clean-local:
	@rm config.status configure config.log Makefile -r autom4te.cache/ aclocal.m4 compile install-sh missing Makefile.in depcomp config.guess config.h.in config.sub


#Notes for self:
#	 $<  translates to "the first prereq"
#	 $@  translates to "the target of the make"
#	 $^  translates to "all prereqs" (objs would be every object file), spec by pattern
#	 %   is wildcard
#	 *   is a different wildcard...
#	 $() is reference to a variable defined in the makefile, substitutes the value in.
#	 ... didn't figure out how to "specify variable for sub-prereq"...
#
#	 normal prereqs | order-only-prereqs (see 4.2 of make manual)
#	 	normal prereqs assume "new prereq means we must rebuild the target"
#	 	order-only prereqs will not force a rebuild of the target.
