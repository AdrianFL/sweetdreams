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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Clock.o \
	${OBJECTDIR}/Enemy.o \
	${OBJECTDIR}/Mapa.o \
	${OBJECTDIR}/Personaje.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/tinystr.o \
	${OBJECTDIR}/tinyxml.o \
	${OBJECTDIR}/tinyxmlerror.o \
	${OBJECTDIR}/tinyxmlparser.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libsfml-audio.so /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-network.so /usr/lib/x86_64-linux-gnu/libsfml-system.so /usr/lib/x86_64-linux-gnu/libsfml-window.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje: /usr/lib/x86_64-linux-gnu/libsfml-audio.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje: /usr/lib/x86_64-linux-gnu/libsfml-network.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje: /usr/lib/x86_64-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje: /usr/lib/x86_64-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Clock.o: Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clock.o Clock.cpp

${OBJECTDIR}/Enemy.o: Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemy.o Enemy.cpp

${OBJECTDIR}/Mapa.o: Mapa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mapa.o Mapa.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/Sprite.o: Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/tinystr.o: tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinystr.o tinystr.cpp

${OBJECTDIR}/tinyxml.o: tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml.o tinyxml.cpp

${OBJECTDIR}/tinyxmlerror.o: tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxmlerror.o tinyxmlerror.cpp

${OBJECTDIR}/tinyxmlparser.o: tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxmlparser.o tinyxmlparser.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapapersonaje

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
