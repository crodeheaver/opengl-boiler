# Install script for directory: C:/workspace/opengl-boiler/libs/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/boiler")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/workspace/opengl-boiler/cmake-build-debug/libs/assimp/code/libassimpd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/anim.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/aabb.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/ai_assert.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/camera.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/color4.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/color4.inl"
    "C:/workspace/opengl-boiler/cmake-build-debug/libs/assimp/code/../include/assimp/config.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/defs.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Defines.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/cfileio.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/light.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/material.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/material.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/matrix3x3.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/matrix3x3.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/matrix4x4.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/matrix4x4.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/mesh.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/pbrmaterial.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/postprocess.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/quaternion.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/quaternion.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/scene.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/metadata.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/texture.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/types.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/vector2.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/vector2.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/vector3.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/vector3.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/version.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/cimport.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/importerdesc.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Importer.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/DefaultLogger.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/ProgressHandler.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/IOStream.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/IOSystem.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Logger.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/LogStream.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/NullLogger.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/cexport.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Exporter.hpp"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/DefaultIOStream.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/DefaultIOSystem.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/SceneCombiner.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/fast_atof.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/qnan.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/BaseImporter.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Hash.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/ParsingUtils.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/StreamReader.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/StreamWriter.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/StringComparison.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/StringUtils.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/SGSpatialSort.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/GenericProperty.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/SpatialSort.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/SmoothingGroups.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/SmoothingGroups.inl"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/StandardShapes.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/RemoveComments.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Subdivision.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Vertex.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/LineSplitter.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/TinyFormatter.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Profiler.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/LogAux.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Bitmap.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/XMLTools.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/IOStreamBuffer.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/CreateAnimMesh.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/irrXMLWrapper.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/BlobIOSystem.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/MathFunctions.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Exceptional.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Compiler/poppack1.h"
    "C:/workspace/opengl-boiler/libs/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

