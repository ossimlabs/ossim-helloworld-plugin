project(ossim-helloworld-plugin)
cmake_minimum_required(VERSION 2.6)
MESSAGE("**********************Setting up ossim-helloworld-plugin********************")

# Include ossim cmake stuff:
include(OssimVersion)
include(OssimCommonVariables)
include(OssimUtilities)

SET(BUILD_OSSIM_FRAMEWORKS "OFF")
SET(OSSIM_PLUGIN_LINK_TYPE "SHARED")


find_package( ossim )
if(OSSIM_FOUND)
   include_directories( ${OSSIM_INCLUDE_DIR} )
   set( requiredLibs ${requiredLibs} ${OSSIM_LIBRARIES} )
else(OSSIM_FOUND)
   message(FATAL_ERROR "Could not find ossim")
endif(OSSIM_FOUND)
# OpenThreads - Required:

find_package( OpenThreads )
if( OPENTHREADS_FOUND )
   include_directories( ${OPENTHREADS_INCLUDE_DIR} )
   set( ossimDependentLibs ${ossimDependentLibs} ${OPENTHREADS_LIBRARY} )
else( OPENTHREADS_FOUND )
   message( FATAL_ERROR "Could not find required OpenThreads package!" )
endif( OPENTHREADS_FOUND )

set(LIB_NAME ossim_helloworld_plugin)


INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/src")
FILE(GLOB_RECURSE OSSIMPLUGIN_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
FILE(GLOB_RECURSE OSSIMPLUGIN_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

####
# OSSIMPLUGINSMAKINGDLL controls dll linkage on windows.  
# Adding this sets OSSIM_PLUGINS_DLL #define TO "__declspec(dllexport)".
###
add_definitions("-DOSSIMPLUGINSMAKINGDLL")



# Adjust the install library path:
if(OSSIM_INSTALL_PLUGINS_WITH_VERSION)
   set(INSTALL_LIBRARY_DIR   "${INSTALL_LIBRARY_DIR}/ossim-${OSSIM_VERSION}/plugins")
else(OSSIM_INSTALL_PLUGINS_WITH_VERSION)
   set(INSTALL_LIBRARY_DIR   "${INSTALL_LIBRARY_DIR}/ossim/plugins")
endif(OSSIM_INSTALL_PLUGINS_WITH_VERSION)
if(WIN32)
 set(INSTALL_RUNTIME_DIR "${INSTALL_RUNTIME_DIR}/ossim/plugins")
endif()

OSSIM_LINK_LIBRARY(${LIB_NAME}
         COMPONENT_NAME ossim TYPE "${OSSIM_PLUGIN_LINK_TYPE}"
         LIBRARIES ${OSSIM_LIBRARIES} ${OPENTHREADS_LIBRARY} ${GDAL_LIBRARY} ${KAKADU_LIBRARY} ${KAKADU_AUX_LIBRARY}  ${KAKADU_ADDITIONAL_OBJS}  ${TIFF_LIBRARY} ${CURL_LIBRARY} ${PROJ4_LIBRARY} ${SQLITE_LIBRARY} ${EXPAT_LIBRARIES} ${ZLIB_LIBRARY} ${GEOTIFF_LIBRARY}
         HEADERS "${OSSIMPLUGIN_HEADERS}"
         SOURCE_FILES "${OSSIMPLUGIN_SRCS}"
                   INSTALL_LIB)
