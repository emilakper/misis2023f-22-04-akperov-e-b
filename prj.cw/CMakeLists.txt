add_executable (poromarker "poromarker.cpp" "poromarker.h")
target_link_libraries(poromarker PRIVATE imgui::imgui opencv_core opencv_highgui opencv_imgproc glad::glad)

