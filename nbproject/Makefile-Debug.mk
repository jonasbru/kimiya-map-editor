#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES=

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lGL -lglut
CXXFLAGS=-lGL -lglut

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=lib/libKE.so lib/libjpeg.a lib/libpng.a lib/libtinyxml.a lib/libMapLoader.so /usr/local/Trolltech/Qt-4.5.3/lib/libQtCore.so /usr/local/Trolltech/Qt-4.5.3/lib/libQtGui.so /usr/local/Trolltech/Qt-4.5.3/lib/libQtOpenGL.so

nbproject/qt-${CONF}.mk: nbproject/qt-${CONF}.pro FORCE
	qmake VPATH=. -o qttmp-${CONF}.mk nbproject/qt-${CONF}.pro
	mv -f qttmp-${CONF}.mk nbproject/qt-${CONF}.mk

FORCE:

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} nbproject/qt-${CONF}.mk
	${MAKE} -f nbproject/qt-${CONF}.mk dist/Debug/GNU-Linux-x86/MapEditor

# Subprojects
.build-subprojects:
	cd ../2DEngine && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: nbproject/qt-Debug.mk
	$(MAKE) -f nbproject/qt-Debug.mk distclean

# Subprojects
.clean-subprojects:
	cd ../2DEngine && ${MAKE}  -f Makefile CONF=Debug clean
