cmake_minimum_required(VERSION 3.16)

project(ADAS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Gui Qml)

qt_standard_project_setup(REQUIRES 6.5)

add_executable(appADAS
    main.cpp
    systeminfo.cpp
    systeminfo.h
)

qt_add_qml_module(appADAS
    URI ADAS
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        RESOURCES resources.qrc
)


target_link_libraries(appADAS
    PRIVATE Qt6::Quick Qt6::Core Qt6::Gui Qt6::Qml
)

set_target_properties(appADAS PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS appADAS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
