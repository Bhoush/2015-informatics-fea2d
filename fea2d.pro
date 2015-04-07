TEMPLATE = subdirs

SUBDIRS += \
    meshgen2d \
    solver2d \
    visualizer2d \
    fea2d

fea2d.depends = meshgen2d
