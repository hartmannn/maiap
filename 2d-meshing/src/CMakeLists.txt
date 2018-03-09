project (refinement)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

cmake_minimum_required(VERSION 2.4.5)

set( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true )

if( COMMAND cmake_policy )
  cmake_policy( SET CMP0003 NEW )  
endif()

find_package(CGAL COMPONENTS Qt5)
find_package(Qt5 QUIET COMPONENTS OpenGL)
find_package(OpenGL)

add_definitions(-DBOOST_NO_CXX11_TEMPLATE_ALIASES)

set( HDRS glviewer.h scene.h window.h  include/cdt.h courbes.h)

set( SRCS glviewer.cpp window.cpp main.cpp)


if(WIN32)
	add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4503 /nologo" )
endif(WIN32)



if( CGAL_FOUND AND Qt5_FOUND AND OPENGL_FOUND )
    include_directories(BEFORE . ./build)
    include(${CGAL_USE_FILE})

    SET(MY_BUILD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)  #Variable build path
    SET(MY_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})  #Variable src path
    INCLUDE_DIRECTORIES(${MY_BUILD_PATH})
    INCLUDE_DIRECTORIES(${MY_SRC_PATH})

    # UI files (Qt Designer files)
    qt5_wrap_ui( DT_UI_FILES refinement.ui)

    ## The executable itself.
    add_executable( refinement ${SRCS} main.cpp ${MOCS} ${DT_UI_FILES} )
    qt5_use_modules(refinement OpenGL)

    # Link with Qt libraries
    target_link_libraries( refinement ${QT_LIBRARIES} )
    
    # Link with  OpenGL
    target_link_libraries( refinement ${OPENGL_LIBRARY})

    # Link with CGAL
    target_link_libraries( refinement ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES})

    ##The second executable
    add_executable(delaunay_parametre_variable delaunay_parametre_variable.cpp courbes.cpp)
    qt5_use_modules(delaunay_parametre_variable OpenGL)

    # Link with CGAL
    target_link_libraries( delaunay_parametre_variable ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES})

else()
  message(STATUS "NOTICE: This program requires CGAL and Qt5, and will not be compiled.")

endif()
