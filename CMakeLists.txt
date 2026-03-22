cmake_minimum_required(VERSION 3.19)
project(newqt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.10.2\\mingw_64")
set(CMAKE_C_COMPILER "C:\\Qt\\Tools\\mingw1310_64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\Qt\\Tools\\mingw1310_64\\bin\\g++.exe")

set(QT_INSTALL_PATH ${CMAKE_PREFIX_PATH}/../../)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)
qt_standard_project_setup()
get_target_property(QT_CORE_LOCATION Qt::Core IMPORTED_LOCATION)
message(${QT_CORE_LOCATION})
qt_add_executable(newqt
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

qt_add_translations(
    TARGETS newqt
    TS_FILES newqt_zh_CN.ts
)

target_link_libraries(newqt
    PRIVATE
        Qt::Core
        Qt::Widgets
)

if(WIN32)
    find_program(WINDEPLOYQT_EXE NAMES windeployqt PATHS "${CMAKE_PREFIX_PATH}/bin" REQUIRED)
    add_custom_command(TARGET newqt POST_BUILD
        COMMAND ${WINDEPLOYQT_EXE} --dir $<TARGET_FILE_DIR:newqt> $<TARGET_FILE:newqt>
        COMMENT "Running winDeployQt for Qt dependencies"
    )
endif()


install(TARGETS newqt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET newqt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

