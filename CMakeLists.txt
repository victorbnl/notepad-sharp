cmake_minimum_required(VERSION 3.5)

project(notepad-sharp LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets PrintSupport)

set(CMAKE_AUTOUIC_SEARCH_PATHS forms)

set(
    PROJECT_SOURCES
    src/closedialog.cpp
    src/editor.cpp
    src/editortabs.cpp
    src/findform.cpp
    src/main.cpp
    src/notepad.cpp
    src/statusbar.cpp
    src/textfile.cpp
    include/closedialog.h
    include/editor.h
    include/editortabs.h
    include/findform.h
    include/notepad.h
    include/statusbar.h
    include/textfile.h
    forms/closedialog.ui
    forms/findform.ui
    forms/notepad.ui
    icons/icons.qrc
)

add_executable(
    ${CMAKE_PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::PrintSupport)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)
