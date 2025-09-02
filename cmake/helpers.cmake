# === helpers.cmake ===
# Cross-platform build helpers for oneCCL

# -----------------------------------------------------------------------------
# Configure compiler-specific flags.
# This should be included before any targets are defined.
# -----------------------------------------------------------------------------
if (MSVC)
    message(STATUS "Applying MSVC-specific flags")
    # Suppress security warnings, enable large object files, and set warning level.
    # Using add_compile_options is preferred over modifying CMAKE_CXX_FLAGS directly.
    add_compile_options(
        /D_CRT_SECURE_NO_WARNINGS
        /bigobj
        /W3
    )
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
    # Set Position Independent Code, which is required for shared libraries
    # and good practice for static libraries that may be linked into shared ones.
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()


# -----------------------------------------------------------------------------
# Helper function to configure API visibility for a target.
#
# Usage: setup_api_visibility(my_target)
#
# This function checks the library type and sets the appropriate preprocessor
# definitions (CCL_EXPORTS or CCL_STATIC_BUILD) for dllexport/dllimport.
# -----------------------------------------------------------------------------
function(setup_api_visibility target)
    get_target_property(target_type ${target} TYPE)

    if (target_type STREQUAL "STATIC_LIBRARY")
        target_compile_definitions(${target} PRIVATE CCL_STATIC_BUILD)
    elseif(target_type STREQUAL "SHARED_LIBRARY" OR target_type STREQUAL "MODULE_LIBRARY")
        target_compile_definitions(${target} PRIVATE CCL_EXPORTS)
    endif()
endfunction()

# Example use:
# enable_macro(ccl_objects CCL_ENABLE_ZE)
