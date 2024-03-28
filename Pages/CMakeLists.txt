# 显式寻找Qt的主要模块，并处理未找到的情况
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# 处理OpenCV版本兼容性问题，建议指定一个期望的版本
# 注意：这里的版本号需要根据实际情况调整
#find_package(OpenCV 4.9.0 REQUIRED)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")
# 定义一个变量来包含所有Qt模块
set(QtModules Qt::Core Qt::Gui Qt::Widgets)

#message("OpenCV libraries: ${OpenCV_LIBS}")

# 添加名为MaskPage的库，包含MaskPage.cpp文件
add_library(MaskPage MaskPage.cpp)
# 为MaskPage库指定链接库，包括找到的OpenCV库和Qt模块
target_link_libraries(MaskPage PRIVATE ${OpenCV_LIBS} ${QtModules})

# 添加名为MainPage的库，包含MainPage.cpp文件
add_library(MainPage MainPage.cpp)
# 为MainPage库指定链接库，包括MaskPage库和Qt模块
target_link_libraries(MainPage PRIVATE MaskPage ${QtModules})

# 优化：如果需要，可以在这里添加更多的配置，例如编译选项，头文件路径等
# 例如，设置包含路径
include_directories(${OpenCV_INCLUDE_DIRS} ${Qt5_INCLUDE_DIRS})

# 使用现代CMake实践，例如使用target的属性来控制可见性等
# 这里暂时没有额外的示例，因为原始代码需求较简单，但是这一步在更复杂的项目中是推荐的
