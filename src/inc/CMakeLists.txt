add_library(${COMMON_PCH} INTERFACE)
target_precompile_headers(
    ${COMMON_PCH} INTERFACE
    stdinc.hpp
)