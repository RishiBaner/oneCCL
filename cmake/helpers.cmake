# === helpers.cmake ===
# Cross-platform build helpers for oneCCL

# Detect and configure compiler-specific flags
if (MSVC)
    message(STATUS "Applying MSVC-specific flags")

    # Suppress security warnings and enable large object files
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

    # Optional: warning level settings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")

else()
    message(STATUS "Applying GCC/Clang-specific flags")

    # Enable common warnings and suppress some irrelevant ones
    add_compile_options(
        -Wall
        -Wextra
        -Wno-implicit-fallthrough
        -Wno-unused-parameter
        -Wno-missing-field-initializers
    )

    # Position independent code for shared libraries
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

# Define a function to set macro flags for a feature
function(enable_macro target macro)
    target_compile_definitions(${target} PRIVATE ${macro}=1)
endfunction()

# Example use:
# enable_macro(ccl_objects CCL_ENABLE_ZE)
