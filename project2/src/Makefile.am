## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS =project2

project2_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h\
	utilisateur.c utilisateur.h\
	function.c function.h\
	electorale.c electorale.h\
	election.c election.h
project2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

