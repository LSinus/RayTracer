cmake_minimum_required(VERSION 3.30)
project(RayTracer)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 QUIET)

if(NOT glfw3_FOUND)
    FetchContent_Declare(
            glfw
            GIT_REPOSITORY https://github.com/glfw/glfw.git
            GIT_TAG 3.3.8
    )
    FetchContent_MakeAvailable(glfw)
endif()

include_directories(/opt/homebrew/include)

add_executable(RayTracer main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        utils.h
        interval.h
        camera.h
        external/imgui/imconfig.h
        external/imgui/imgui.cpp
        external/imgui/imgui.h
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_internal.h
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imstb_rectpack.h
        external/imgui/imstb_textedit.h
        external/imgui/imstb_truetype.h
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_glfw.h
        external/imgui/backends/imgui_impl_opengl3.cpp
        external/imgui/backends/imgui_impl_opengl3.h
        texturedisplay.h

)

target_include_directories(RayTracer PRIVATE
        external/imgui
        external/imgui/backends
)


target_link_libraries(RayTracer PRIVATE OpenGL::GL glfw)