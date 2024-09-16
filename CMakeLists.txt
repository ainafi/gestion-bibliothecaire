cmake_minimum_required(VERSION 3.16)

project(GestionBibliotecaire VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

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
        modifierunlivre.h
        modifierunlivre.ui

        supprimerunlivre.cpp
        supprimerunlivre.h
        supprimerunlivre.ui

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

qt_add_executable(GestionBibliotecaire
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(GestionBibliotecaire PRIVATE Qt6::Widgets Qt6::Sql)

qt_finalize_executable(GestionBibliotecaire)
