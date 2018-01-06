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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Date.o \
	${OBJECTDIR}/Inventory.o \
	${OBJECTDIR}/Sales.o \
	${OBJECTDIR}/SalesStruct.o \
	${OBJECTDIR}/StockItem.o \
	${OBJECTDIR}/StockProgram.o


# C Compiler Flags
CFLAGS=-std=c11

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coursework1.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coursework1.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coursework1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Date.o: Date.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Ibuild -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Date.o Date.c

${OBJECTDIR}/Inventory.o: Inventory.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Ibuild -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Inventory.o Inventory.c

${OBJECTDIR}/Sales.o: Sales.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Ibuild -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sales.o Sales.c

${OBJECTDIR}/SalesStruct.o: SalesStruct.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Ibuild -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SalesStruct.o SalesStruct.c

${OBJECTDIR}/StockItem.o: StockItem.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Ibuild -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StockItem.o StockItem.c

${OBJECTDIR}/StockProgram.o: StockProgram.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Ibuild -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StockProgram.o StockProgram.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coursework1.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
