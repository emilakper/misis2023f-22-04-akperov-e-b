add_subdirectory(libs)

add_executable (poromarker "poromarker.cpp")
target_link_libraries(poromarker PRIVATE imgui::imgui opencv_core opencv_highgui opencv_imgproc imfilebrowser)

install(TARGETS poromarker
DESTINATION bin)


if(WIN32)
    install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/
			DESTINATION bin
			CONFIGURATIONS Debug
			FILES_MATCHING PATTERN "*.dll*"
			)
	install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/
			CONFIGURATIONS Release
			DESTINATION bin
			FILES_MATCHING PATTERN "*.dll*"
			)
	install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO}/
			DESTINATION bin
			CONFIGURATIONS RelWithDebInfo
			FILES_MATCHING PATTERN "*.dll*"
			)
else()
    install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/
			DESTINATION bin
			CONFIGURATIONS Debug
			FILES_MATCHING PATTERN "*.so*"
			)
	install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/
			CONFIGURATIONS Release
			DESTINATION bin
			FILES_MATCHING PATTERN "*.so*"
			)
	install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO}/
			DESTINATION bin
			CONFIGURATIONS RelWithDebInfo
			FILES_MATCHING PATTERN "*.so*"
			)
endif()


install(DIRECTORY ${CMAKE_SOURCE_DIR}/prj.cw/testpics/ 
DESTINATION pics)