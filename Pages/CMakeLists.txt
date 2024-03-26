

add_library(MaskPage MaskPage.cpp)
target_link_libraries(MaskPage Qt::Core
        Qt::Gui
        Qt::Widgets)

add_library(MainPage MainPage.cpp)
target_link_libraries(MainPage MaskPage  Qt::Core
        Qt::Gui
        Qt::Widgets)