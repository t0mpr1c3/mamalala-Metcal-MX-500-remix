#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360919505/adc.o ${OBJECTDIR}/_ext/2096227361/config_manager.o ${OBJECTDIR}/_ext/2096227361/config_memory.o ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o ${OBJECTDIR}/_ext/2096227361/config_editor.o ${OBJECTDIR}/_ext/1360921861/crc.o ${OBJECTDIR}/_ext/1222360273/eeprom.o ${OBJECTDIR}/_ext/1007093709/encoder.o ${OBJECTDIR}/_ext/439174825/hardware.o ${OBJECTDIR}/_ext/439174825/configbits.o ${OBJECTDIR}/_ext/874682058/helpers.o ${OBJECTDIR}/_ext/1709864581/infodisplay.o ${OBJECTDIR}/_ext/1709864581/infoicons.o ${OBJECTDIR}/_ext/444254420/interrupt.o ${OBJECTDIR}/_ext/1459581580/languages.o ${OBJECTDIR}/_ext/1459581580/languages_strings.o ${OBJECTDIR}/_ext/1360930046/lcd.o ${OBJECTDIR}/_ext/1360930046/backlight.o ${OBJECTDIR}/_ext/1013000001/logger.o ${OBJECTDIR}/_ext/760809394/menu.o ${OBJECTDIR}/_ext/760809394/menudata.o ${OBJECTDIR}/_ext/818898020/power_manager.o ${OBJECTDIR}/_ext/767886417/rf_manager.o ${OBJECTDIR}/_ext/760597060/time.o ${OBJECTDIR}/_ext/1360937932/tip_detect.o ${OBJECTDIR}/_ext/760574787/uart_fifo.o ${OBJECTDIR}/_ext/760574787/uart.o ${OBJECTDIR}/_ext/1472/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360919505/adc.o.d ${OBJECTDIR}/_ext/2096227361/config_manager.o.d ${OBJECTDIR}/_ext/2096227361/config_memory.o.d ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o.d ${OBJECTDIR}/_ext/2096227361/config_editor.o.d ${OBJECTDIR}/_ext/1360921861/crc.o.d ${OBJECTDIR}/_ext/1222360273/eeprom.o.d ${OBJECTDIR}/_ext/1007093709/encoder.o.d ${OBJECTDIR}/_ext/439174825/hardware.o.d ${OBJECTDIR}/_ext/439174825/configbits.o.d ${OBJECTDIR}/_ext/874682058/helpers.o.d ${OBJECTDIR}/_ext/1709864581/infodisplay.o.d ${OBJECTDIR}/_ext/1709864581/infoicons.o.d ${OBJECTDIR}/_ext/444254420/interrupt.o.d ${OBJECTDIR}/_ext/1459581580/languages.o.d ${OBJECTDIR}/_ext/1459581580/languages_strings.o.d ${OBJECTDIR}/_ext/1360930046/lcd.o.d ${OBJECTDIR}/_ext/1360930046/backlight.o.d ${OBJECTDIR}/_ext/1013000001/logger.o.d ${OBJECTDIR}/_ext/760809394/menu.o.d ${OBJECTDIR}/_ext/760809394/menudata.o.d ${OBJECTDIR}/_ext/818898020/power_manager.o.d ${OBJECTDIR}/_ext/767886417/rf_manager.o.d ${OBJECTDIR}/_ext/760597060/time.o.d ${OBJECTDIR}/_ext/1360937932/tip_detect.o.d ${OBJECTDIR}/_ext/760574787/uart_fifo.o.d ${OBJECTDIR}/_ext/760574787/uart.o.d ${OBJECTDIR}/_ext/1472/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360919505/adc.o ${OBJECTDIR}/_ext/2096227361/config_manager.o ${OBJECTDIR}/_ext/2096227361/config_memory.o ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o ${OBJECTDIR}/_ext/2096227361/config_editor.o ${OBJECTDIR}/_ext/1360921861/crc.o ${OBJECTDIR}/_ext/1222360273/eeprom.o ${OBJECTDIR}/_ext/1007093709/encoder.o ${OBJECTDIR}/_ext/439174825/hardware.o ${OBJECTDIR}/_ext/439174825/configbits.o ${OBJECTDIR}/_ext/874682058/helpers.o ${OBJECTDIR}/_ext/1709864581/infodisplay.o ${OBJECTDIR}/_ext/1709864581/infoicons.o ${OBJECTDIR}/_ext/444254420/interrupt.o ${OBJECTDIR}/_ext/1459581580/languages.o ${OBJECTDIR}/_ext/1459581580/languages_strings.o ${OBJECTDIR}/_ext/1360930046/lcd.o ${OBJECTDIR}/_ext/1360930046/backlight.o ${OBJECTDIR}/_ext/1013000001/logger.o ${OBJECTDIR}/_ext/760809394/menu.o ${OBJECTDIR}/_ext/760809394/menudata.o ${OBJECTDIR}/_ext/818898020/power_manager.o ${OBJECTDIR}/_ext/767886417/rf_manager.o ${OBJECTDIR}/_ext/760597060/time.o ${OBJECTDIR}/_ext/1360937932/tip_detect.o ${OBJECTDIR}/_ext/760574787/uart_fifo.o ${OBJECTDIR}/_ext/760574787/uart.o ${OBJECTDIR}/_ext/1472/main.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2620
MP_PROCESSOR_OPTION_LD=18f2620
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0xfd30 -u_DEBUGCODELEN=0x2d0 -u_DEBUGDATASTART=0xef4 -u_DEBUGDATALEN=0xb
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360919505/adc.o: ../adc/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360919505 
	@${RM} ${OBJECTDIR}/_ext/1360919505/adc.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360919505/adc.o   ../adc/adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360919505/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360919505/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_manager.o: ../config_manager/config_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_manager.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_manager.o   ../config_manager/config_manager.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_memory.o: ../config_manager/config_memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_memory.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_memory.o   ../config_manager/config_memory.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_memory.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_memory.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_iteminfo.o: ../config_manager/config_iteminfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o   ../config_manager/config_iteminfo.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_iteminfo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_editor.o: ../config_manager/config_editor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_editor.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_editor.o   ../config_manager/config_editor.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_editor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_editor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360921861/crc.o: ../crc/crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360921861 
	@${RM} ${OBJECTDIR}/_ext/1360921861/crc.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360921861/crc.o   ../crc/crc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360921861/crc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360921861/crc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1222360273/eeprom.o: ../eeprom/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1222360273 
	@${RM} ${OBJECTDIR}/_ext/1222360273/eeprom.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1222360273/eeprom.o   ../eeprom/eeprom.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1222360273/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1222360273/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1007093709/encoder.o: ../encoder/encoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1007093709 
	@${RM} ${OBJECTDIR}/_ext/1007093709/encoder.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1007093709/encoder.o   ../encoder/encoder.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1007093709/encoder.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007093709/encoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/439174825/hardware.o: ../hardware/hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/439174825 
	@${RM} ${OBJECTDIR}/_ext/439174825/hardware.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/439174825/hardware.o   ../hardware/hardware.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/439174825/hardware.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/439174825/hardware.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/439174825/configbits.o: ../hardware/configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/439174825 
	@${RM} ${OBJECTDIR}/_ext/439174825/configbits.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/439174825/configbits.o   ../hardware/configbits.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/439174825/configbits.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/439174825/configbits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/874682058/helpers.o: ../helpers/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/874682058 
	@${RM} ${OBJECTDIR}/_ext/874682058/helpers.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/874682058/helpers.o   ../helpers/helpers.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/874682058/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/874682058/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1709864581/infodisplay.o: ../infodisplay/infodisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1709864581 
	@${RM} ${OBJECTDIR}/_ext/1709864581/infodisplay.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1709864581/infodisplay.o   ../infodisplay/infodisplay.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1709864581/infodisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1709864581/infodisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1709864581/infoicons.o: ../infodisplay/infoicons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1709864581 
	@${RM} ${OBJECTDIR}/_ext/1709864581/infoicons.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1709864581/infoicons.o   ../infodisplay/infoicons.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1709864581/infoicons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1709864581/infoicons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/444254420/interrupt.o: ../interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/444254420 
	@${RM} ${OBJECTDIR}/_ext/444254420/interrupt.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/444254420/interrupt.o   ../interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/444254420/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/444254420/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1459581580/languages.o: ../languages/languages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1459581580 
	@${RM} ${OBJECTDIR}/_ext/1459581580/languages.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1459581580/languages.o   ../languages/languages.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1459581580/languages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1459581580/languages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1459581580/languages_strings.o: ../languages/languages_strings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1459581580 
	@${RM} ${OBJECTDIR}/_ext/1459581580/languages_strings.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1459581580/languages_strings.o   ../languages/languages_strings.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1459581580/languages_strings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1459581580/languages_strings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360930046/lcd.o: ../lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360930046 
	@${RM} ${OBJECTDIR}/_ext/1360930046/lcd.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360930046/lcd.o   ../lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360930046/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360930046/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360930046/backlight.o: ../lcd/backlight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360930046 
	@${RM} ${OBJECTDIR}/_ext/1360930046/backlight.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360930046/backlight.o   ../lcd/backlight.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360930046/backlight.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360930046/backlight.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1013000001/logger.o: ../logger/logger.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1013000001 
	@${RM} ${OBJECTDIR}/_ext/1013000001/logger.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1013000001/logger.o   ../logger/logger.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1013000001/logger.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1013000001/logger.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760809394/menu.o: ../menu/menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760809394 
	@${RM} ${OBJECTDIR}/_ext/760809394/menu.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760809394/menu.o   ../menu/menu.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760809394/menu.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760809394/menu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760809394/menudata.o: ../menu/menudata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760809394 
	@${RM} ${OBJECTDIR}/_ext/760809394/menudata.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760809394/menudata.o   ../menu/menudata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760809394/menudata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760809394/menudata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/818898020/power_manager.o: ../power_manager/power_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/818898020 
	@${RM} ${OBJECTDIR}/_ext/818898020/power_manager.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/818898020/power_manager.o   ../power_manager/power_manager.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/818898020/power_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/818898020/power_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/767886417/rf_manager.o: ../rf_manager/rf_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/767886417 
	@${RM} ${OBJECTDIR}/_ext/767886417/rf_manager.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/767886417/rf_manager.o   ../rf_manager/rf_manager.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/767886417/rf_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767886417/rf_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760597060/time.o: ../time/time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760597060 
	@${RM} ${OBJECTDIR}/_ext/760597060/time.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760597060/time.o   ../time/time.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760597060/time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760597060/time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360937932/tip_detect.o: ../tip/tip_detect.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937932 
	@${RM} ${OBJECTDIR}/_ext/1360937932/tip_detect.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360937932/tip_detect.o   ../tip/tip_detect.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360937932/tip_detect.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937932/tip_detect.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760574787/uart_fifo.o: ../uart/uart_fifo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760574787 
	@${RM} ${OBJECTDIR}/_ext/760574787/uart_fifo.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760574787/uart_fifo.o   ../uart/uart_fifo.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760574787/uart_fifo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760574787/uart_fifo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760574787/uart.o: ../uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760574787 
	@${RM} ${OBJECTDIR}/_ext/760574787/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760574787/uart.o   ../uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760574787/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760574787/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1360919505/adc.o: ../adc/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360919505 
	@${RM} ${OBJECTDIR}/_ext/1360919505/adc.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360919505/adc.o   ../adc/adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360919505/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360919505/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_manager.o: ../config_manager/config_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_manager.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_manager.o   ../config_manager/config_manager.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_memory.o: ../config_manager/config_memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_memory.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_memory.o   ../config_manager/config_memory.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_memory.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_memory.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_iteminfo.o: ../config_manager/config_iteminfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o   ../config_manager/config_iteminfo.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_iteminfo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_iteminfo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2096227361/config_editor.o: ../config_manager/config_editor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2096227361 
	@${RM} ${OBJECTDIR}/_ext/2096227361/config_editor.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/2096227361/config_editor.o   ../config_manager/config_editor.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2096227361/config_editor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2096227361/config_editor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360921861/crc.o: ../crc/crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360921861 
	@${RM} ${OBJECTDIR}/_ext/1360921861/crc.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360921861/crc.o   ../crc/crc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360921861/crc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360921861/crc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1222360273/eeprom.o: ../eeprom/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1222360273 
	@${RM} ${OBJECTDIR}/_ext/1222360273/eeprom.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1222360273/eeprom.o   ../eeprom/eeprom.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1222360273/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1222360273/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1007093709/encoder.o: ../encoder/encoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1007093709 
	@${RM} ${OBJECTDIR}/_ext/1007093709/encoder.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1007093709/encoder.o   ../encoder/encoder.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1007093709/encoder.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007093709/encoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/439174825/hardware.o: ../hardware/hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/439174825 
	@${RM} ${OBJECTDIR}/_ext/439174825/hardware.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/439174825/hardware.o   ../hardware/hardware.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/439174825/hardware.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/439174825/hardware.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/439174825/configbits.o: ../hardware/configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/439174825 
	@${RM} ${OBJECTDIR}/_ext/439174825/configbits.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/439174825/configbits.o   ../hardware/configbits.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/439174825/configbits.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/439174825/configbits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/874682058/helpers.o: ../helpers/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/874682058 
	@${RM} ${OBJECTDIR}/_ext/874682058/helpers.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/874682058/helpers.o   ../helpers/helpers.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/874682058/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/874682058/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1709864581/infodisplay.o: ../infodisplay/infodisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1709864581 
	@${RM} ${OBJECTDIR}/_ext/1709864581/infodisplay.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1709864581/infodisplay.o   ../infodisplay/infodisplay.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1709864581/infodisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1709864581/infodisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1709864581/infoicons.o: ../infodisplay/infoicons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1709864581 
	@${RM} ${OBJECTDIR}/_ext/1709864581/infoicons.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1709864581/infoicons.o   ../infodisplay/infoicons.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1709864581/infoicons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1709864581/infoicons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/444254420/interrupt.o: ../interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/444254420 
	@${RM} ${OBJECTDIR}/_ext/444254420/interrupt.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/444254420/interrupt.o   ../interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/444254420/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/444254420/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1459581580/languages.o: ../languages/languages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1459581580 
	@${RM} ${OBJECTDIR}/_ext/1459581580/languages.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1459581580/languages.o   ../languages/languages.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1459581580/languages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1459581580/languages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1459581580/languages_strings.o: ../languages/languages_strings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1459581580 
	@${RM} ${OBJECTDIR}/_ext/1459581580/languages_strings.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1459581580/languages_strings.o   ../languages/languages_strings.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1459581580/languages_strings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1459581580/languages_strings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360930046/lcd.o: ../lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360930046 
	@${RM} ${OBJECTDIR}/_ext/1360930046/lcd.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360930046/lcd.o   ../lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360930046/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360930046/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360930046/backlight.o: ../lcd/backlight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360930046 
	@${RM} ${OBJECTDIR}/_ext/1360930046/backlight.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360930046/backlight.o   ../lcd/backlight.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360930046/backlight.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360930046/backlight.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1013000001/logger.o: ../logger/logger.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1013000001 
	@${RM} ${OBJECTDIR}/_ext/1013000001/logger.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1013000001/logger.o   ../logger/logger.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1013000001/logger.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1013000001/logger.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760809394/menu.o: ../menu/menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760809394 
	@${RM} ${OBJECTDIR}/_ext/760809394/menu.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760809394/menu.o   ../menu/menu.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760809394/menu.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760809394/menu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760809394/menudata.o: ../menu/menudata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760809394 
	@${RM} ${OBJECTDIR}/_ext/760809394/menudata.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760809394/menudata.o   ../menu/menudata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760809394/menudata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760809394/menudata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/818898020/power_manager.o: ../power_manager/power_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/818898020 
	@${RM} ${OBJECTDIR}/_ext/818898020/power_manager.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/818898020/power_manager.o   ../power_manager/power_manager.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/818898020/power_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/818898020/power_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/767886417/rf_manager.o: ../rf_manager/rf_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/767886417 
	@${RM} ${OBJECTDIR}/_ext/767886417/rf_manager.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/767886417/rf_manager.o   ../rf_manager/rf_manager.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/767886417/rf_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767886417/rf_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760597060/time.o: ../time/time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760597060 
	@${RM} ${OBJECTDIR}/_ext/760597060/time.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760597060/time.o   ../time/time.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760597060/time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760597060/time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1360937932/tip_detect.o: ../tip/tip_detect.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937932 
	@${RM} ${OBJECTDIR}/_ext/1360937932/tip_detect.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1360937932/tip_detect.o   ../tip/tip_detect.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1360937932/tip_detect.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937932/tip_detect.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760574787/uart_fifo.o: ../uart/uart_fifo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760574787 
	@${RM} ${OBJECTDIR}/_ext/760574787/uart_fifo.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760574787/uart_fifo.o   ../uart/uart_fifo.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760574787/uart_fifo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760574787/uart_fifo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760574787/uart.o: ../uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/760574787 
	@${RM} ${OBJECTDIR}/_ext/760574787/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760574787/uart.o   ../uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760574787/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760574787/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../" -I"../adc" -I"../interrupt" -I"../encoder" -I"../lcd" -I"../hardware" -I"../tip" -I"../power_manager" -I"../uart" -I"../power_manager" -I"../helpers" -I"../config_manager" -I"../crc" -I"../languages" -I"../eeprom" -I"../rf_manager" -I"../logger" -I"../infodisplay" -I"../time" -I"../menu" -I"../menu/languages" -I"../config_manager/languages" -ms -oa- -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../18F2620.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../18F2620.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../F:/MCC18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../18F2620.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../18F2620.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../F:/MCC18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/RFSupply.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
