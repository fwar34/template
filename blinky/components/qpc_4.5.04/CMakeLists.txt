set(LIB_NAME "qpc_4.5.04")

file(GLOB qep_srcs CONFIGURE_DEPENDS "qep/source/*.c")
file(GLOB qf_srcs  CONFIGURE_DEPENDS "qf/source/*.c")

add_library(${LIB_NAME} STATIC "")

target_sources(${LIB_NAME} PRIVATE "${qep_srcs}")
target_sources(${LIB_NAME} PRIVATE "${qf_srcs}")

target_include_directories(${LIB_NAME} PRIVATE "qep/source")
target_include_directories(${LIB_NAME} PRIVATE "qf/source")
target_include_directories(${LIB_NAME} PUBLIC  "include")
target_include_directories(${LIB_NAME} PUBLIC  "ports/arm-cortex/vanilla/gnu")
