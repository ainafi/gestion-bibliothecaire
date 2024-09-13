cmake_minimum_required(VERSION 3.16)

project(GestionBibliotecaire VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        #lecteur
        createlecteur.cpp
        createlecteur.h
        createlecteur.ui

        modifierunlecteur.cpp
        modifierunlecteur.h
        modifierunlecteur.ui

        supprimerlecteur.cpp
        supprimerlecteur.h
        supprimerlecteur.ui

        #livre
        ajouterunlivre.cpp
        ajouterunlivre.h
        ajouterunlivre.ui

        modifierunlivre.cpp
        modifierunlecteur.h
        modifierunlecteur.ui

        supprimerunlivre.cpp
        supprimerunlivre.h
        supprimerlecteur.ui

        #prete
        prete.cpp
        prete.h
        prete.ui

        modifierunpret.cpp
        modifierunpret.h
        modifierunpret.ui

        supprimerunpret.cpp
        supprimerunpret.h
        supprimerunpret.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GestionBibliotecaire
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        createlecteur.h createlecteur.cpp createlecteur.ui
        modifierunlecteur.h modifierunlecteur.cpp modifierunlecteur.ui
        supprimerlecteur.h supprimerlecteur.cpp supprimerlecteur.ui
        ajouterunlivre.h ajouterunlivre.cpp ajouterunlivre.ui
        modifierunlivre.h modifierunlivre.cpp modifierunlivre.ui
        supprimerunlivre.h supprimerunlivre.cpp supprimerunlivre.ui
        prete.h prete.cpp prete.ui
        modifierunpret.h modifierunpret.cpp modifierunpret.ui
        supprimerunpret.h supprimerunpret.cpp supprimerunpret.ui
        databaseHeader.h
    )
else()
    if(ANDROID)
        add_library(GestionBibliotecaire SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(GestionBibliotecaire
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GestionBibliotecaire PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GestionBibliotecaire)
endif()
