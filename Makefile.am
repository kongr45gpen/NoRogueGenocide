lib_LTLIBRARIES = NoRogueGenocide.la

NoRogueGenocide_la_SOURCES = NoRogueGenocide.cpp
NoRogueGenocide_la_CXXFLAGS= -I$(top_srcdir)/include -I$(top_srcdir)/plugins/plugin_utils
NoRogueGenocide_la_LDFLAGS = -module -avoid-version -shared
NoRogueGenocide_la_LIBADD = $(top_builddir)/plugins/plugin_utils/libplugin_utils.la

AM_CPPFLAGS = $(CONF_CPPFLAGS)
AM_CFLAGS = $(CONF_CFLAGS)
AM_CXXFLAGS = $(CONF_CXXFLAGS)

EXTRA_DIST = \
	README.txt \
	NoRogueGenocide.def \
	NoRogueGenocide.sln \
	NoRogueGenocide.vcxproj

MAINTAINERCLEANFILES =	\
	Makefile.in
