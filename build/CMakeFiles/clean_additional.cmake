# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GestionBibliotecaire_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GestionBibliotecaire_autogen.dir/ParseCache.txt"
  "GestionBibliotecaire_autogen"
  )
endif()
