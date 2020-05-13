find_package(PkgConfig REQUIRED)

foreach(comp postproc avfilter avformat avcodec avutil swscale swresample)
  pkg_check_modules(${comp} REQUIRED IMPORTED_TARGET lib${comp})
  list(APPEND FFMPEG_LIBRARY PkgConfig::${comp})
endforeach(comp)
set(FFMPEG_INCLUDE_DIR ${avcodec_INCLUDE_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FFmpeg
        DEFAULT_MSG
        FFMPEG_LIBRARY
        FFMPEG_INCLUDE_DIR
        )

if (FFMPEG_FOUND)
  message("FFMPEG_INCLUDE_DIR = ${FFMPEG_INCLUDE_DIR} ")
  message("FFMPEG_LIBRARY = ${FFMPEG_LIBRARY} ")
else()
  message(FATAL_ERROR "FFMPEG not found")
endif ()
