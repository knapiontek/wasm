QT += core
TARGET = pip
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17
HEADERS += point.hpp \
    paint.hpp \
    sparse.hpp \
    data.hpp \
    convert.hpp \
    pipe.hpp \
    solve-pipe.hpp \
    clip.hpp
SOURCES += main.cpp
