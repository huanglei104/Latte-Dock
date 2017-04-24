set(lattedock_SRCS
    lattedockplugin.cpp
    quickwindowsystem.cpp
    dock.cpp
    iconitem.cpp
    plasmoidbackend.cpp
    worker.cpp
)

add_library(lattedockplugin SHARED ${lattedock_SRCS})

target_link_libraries(lattedockplugin
    Qt5::Quick
    Qt5::Qml
    Qt5::Concurrent
    KF5::CoreAddons
    KF5::Plasma
    KF5::PlasmaQuick
    KF5::QuickAddons
    KF5::IconThemes
    KF5::KIOCore
    KF5::KIOWidgets
)

if(HAVE_X11)
    target_link_libraries(lattedockplugin KF5::WindowSystem Qt5::X11Extras)
endif()

install(TARGETS lattedockplugin DESTINATION ${KDE_INSTALL_QMLDIR}/org/kde/latte)
install(FILES qmldir DESTINATION ${KDE_INSTALL_QMLDIR}/org/kde/latte)
