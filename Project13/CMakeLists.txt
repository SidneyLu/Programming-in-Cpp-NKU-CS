CMAKE_MINIMUM_REQUIRED(VERSION 3.30)
PROJECT(MonetGAN)

# 基础配置
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)
SET(CAFFE2_USE_CUDNN ON)

# 依赖库路径配置
SET(CMAKE_PREFIX_PATH 
    "C:/Qt/6.8.2/msvc2022_64/bin"
    "C:/LibTorch"
    "C:/OpenCV"
)
SET(CUDNN_LIBRARY_PATH "C:/Program Files/NVIDIA/CUDNN/v9.6/bin/12.6")
SET(CUDNN_INCLUDE_PATH "C:/Program Files/NVIDIA/CUDNN/v9.6/include/12.6")
SET(TORCH_INSTALL_PREFIX "C:/LibTorch")
SET(OpenCV_INSTALL_PREFIX "C:/OpenCV")

# 关联 CUDNN 路径
INCLUDE_DIRECTORIES(${CUDNN_INCLUDE_PATH})
LINK_DIRECTORIES(${CUDNN_LIBRARY_PATH})

# 查找依赖库
FIND_PACKAGE(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
FIND_PACKAGE(Torch REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)

# 批量获取源码文件（假设源码在 src 目录下）
FILE(GLOB SOURCES 
    "src/*.cpp" 
    "src/*.h"
    "src/*.ui"  # 若有 UI 文件，需加入
    "src/*.qrc" # 若有资源文件，需加入
)
ADD_EXECUTABLE(MonetGAN ${SOURCES})

# 链接依赖库
TARGET_LINK_LIBRARIES(MonetGAN
    Qt::Core
    Qt::Gui
    Qt::Widgets
    "${TORCH_LIBRARIES}"
    "${OpenCV_LIBS}"
    "${CUDNN_LIBRARY_PATH}/cudnn.lib" # 链接 CUDNN
)

# Windows：复制 Qt 插件和 DLL
IF (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    SET(DEBUG_SUFFIX)
    IF (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        SET(DEBUG_SUFFIX "d")
    ENDIF()

    # 复制 Qt 平台插件
    SET(QT_INSTALL_PATH "C:/Qt/6.8.2/msvc2022_64")
    IF(NOT EXISTS "${QT_INSTALL_PATH}/bin")
        SET(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        IF(NOT EXISTS "${QT_INSTALL_PATH}/bin")
            SET(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        ENDIF()
    ENDIF()
    IF(EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        ADD_CUSTOM_COMMAND(TARGET MonetGAN POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:MonetGAN>/plugins/platforms/"
        )
        ADD_CUSTOM_COMMAND(TARGET MonetGAN POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:MonetGAN>/plugins/platforms/"
        )
    ENDIF()

    # 复制 Qt 核心 DLL
    FOREACH(QT_LIB Core Gui Widgets)
        ADD_CUSTOM_COMMAND(TARGET MonetGAN POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:MonetGAN>"
        )
    ENDFOREACH(QT_LIB)

    # 复制 Torch DLL
    FILE(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    ADD_CUSTOM_COMMAND(TARGET MonetGAN POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${TORCH_DLLS}
        "$<TARGET_FILE_DIR:MonetGAN>"
    )

    # 复制 OpenCV DLL
    FILE(GLOB OpenCV_DLLS "${OpenCV_INSTALL_PREFIX}/x64/vc17/bin/*.dll")
    ADD_CUSTOM_COMMAND(TARGET MonetGAN POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${OpenCV_DLLS}
        "$<TARGET_FILE_DIR:MonetGAN>"
    )
ENDIF()