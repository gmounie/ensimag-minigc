cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(Ensigc)
enable_testing()
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Werror -std=gnu11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -std=gnu++11")

#########
# Gestion des logins
#########
# Vous devez editer la ligne suivante pour y mettre votre login
#########
set(LOGINS login1)

if (LOGINS MATCHES "login1")
  message(FATAL_ERROR "** ERREUR / ERROR **: Vous devez modifier CMakeLists.txt pour remplacer login1 par votre login / Substitute login1 with your own login in CMakeLists.txt")
endif()



##
# Si vous utilisez d'autres fichiers .c, en plus de ceux listés,
# il faut les ajouter ici
##
add_library(ensigc SHARED src/libgc.c src/libbitset1000.cpp)
add_executable(ensitestgc tests/gctests.c tests/gctest0.c tests/gctest1.c tests/gctest2.c tests/gctest3.c tests/gctest4.c)
target_link_libraries(ensitestgc ensigc)


##
# Programme de test
##
add_test(TestsGC ensitestgc)
