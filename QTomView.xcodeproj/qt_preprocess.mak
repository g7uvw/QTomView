#############################################################################
# Makefile for building: QTomView.app/Contents/MacOS/QTomView
# Generated by qmake (3.1) (Qt 5.9.7)
# Project:  QTomView.pro
# Template: app
# Command: /Users/dm/anaconda2/bin/qmake -o QTomView.xcodeproj/project.pbxproj QTomView.pro -spec macx-xcode
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/dm/anaconda2/bin/moc
UIC       = /Users/dm/anaconda2/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I. -I../../anaconda2/include/qt -I../../anaconda2/include/qt/QtWidgets -I../../anaconda2/include/qt/QtGui -I../../anaconda2/include/qt/QtCore -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -I../../anaconda2/mkspecs/macx-clang
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers: qrc_qtomviewresources.cpp moc_predefs.h moc_mainwindow.cpp moc_infodialog.cpp moc_qtomv_view.cpp ui_mainwindow.h ui_infodialog.h
compiler_rcc_make_all: qrc_qtomviewresources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_qtomviewresources.cpp
qrc_qtomviewresources.cpp: qtomviewresources.qrc \
		../../anaconda2/bin/rcc \
		icons/Open_file.png \
		icons/YZ.ico \
		icons/XZ.ico \
		icons/Color_wheel.png \
		icons/Up.png \
		icons/Info.png \
		icons/XY.ico \
		icons/Down.png
	/Users/dm/anaconda2/bin/rcc -name qtomviewresources qtomviewresources.qrc -o qrc_qtomviewresources.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: ../../anaconda2/mkspecs/features/data/dummy.cpp
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -pipe -stdlib=libc++ -Wall -O2 -std=gnu++11 -Wall -W -dM -E -o moc_predefs.h ../../anaconda2/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_mainwindow.cpp moc_infodialog.cpp moc_qtomv_view.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_infodialog.cpp moc_qtomv_view.cpp
moc_mainwindow.cpp: ../../anaconda2/include/qt/QtWidgets/QMainWindow \
		TomHeader.h \
		qtomv_view.h \
		../../anaconda2/include/qt/QtGui/QPainter \
		../../anaconda2/include/qt/QtWidgets/QtWidgets \
		mainwindow.h \
		tomslicer.h \
		../../anaconda2/include/qt/QtCore/QtCore \
		mainwindow.h \
		moc_predefs.h \
		../../anaconda2/bin/moc
	/Users/dm/anaconda2/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/dm/anaconda2/mkspecs/macx-clang -I/Users/dm/Development/QTomView -I/Users/dm/anaconda2/include/qt -I/Users/dm/anaconda2/include/qt/QtWidgets -I/Users/dm/anaconda2/include/qt/QtGui -I/Users/dm/anaconda2/include/qt/QtCore -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/usr/include mainwindow.h -o moc_mainwindow.cpp

moc_infodialog.cpp: ../../anaconda2/include/qt/QtWidgets/QDialog \
		mainwindow.h \
		../../anaconda2/include/qt/QtWidgets/QMainWindow \
		TomHeader.h \
		qtomv_view.h \
		../../anaconda2/include/qt/QtGui/QPainter \
		../../anaconda2/include/qt/QtWidgets/QtWidgets \
		../../anaconda2/include/qt/QtCore/QtCore \
		tomslicer.h \
		infodialog.h \
		moc_predefs.h \
		../../anaconda2/bin/moc
	/Users/dm/anaconda2/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/dm/anaconda2/mkspecs/macx-clang -I/Users/dm/Development/QTomView -I/Users/dm/anaconda2/include/qt -I/Users/dm/anaconda2/include/qt/QtWidgets -I/Users/dm/anaconda2/include/qt/QtGui -I/Users/dm/anaconda2/include/qt/QtCore -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/usr/include infodialog.h -o moc_infodialog.cpp

moc_qtomv_view.cpp: ../../anaconda2/include/qt/QtGui/QPainter \
		../../anaconda2/include/qt/QtWidgets/QtWidgets \
		mainwindow.h \
		../../anaconda2/include/qt/QtWidgets/QMainWindow \
		TomHeader.h \
		qtomv_view.h \
		../../anaconda2/include/qt/QtCore/QtCore \
		tomslicer.h \
		qtomv_view.h \
		moc_predefs.h \
		../../anaconda2/bin/moc
	/Users/dm/anaconda2/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/dm/anaconda2/mkspecs/macx-clang -I/Users/dm/Development/QTomView -I/Users/dm/anaconda2/include/qt -I/Users/dm/anaconda2/include/qt/QtWidgets -I/Users/dm/anaconda2/include/qt/QtGui -I/Users/dm/anaconda2/include/qt/QtCore -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/usr/include qtomv_view.h -o moc_qtomv_view.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_infodialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_infodialog.h
ui_mainwindow.h: mainwindow.ui \
		../../anaconda2/bin/uic
	/Users/dm/anaconda2/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_infodialog.h: infodialog.ui \
		../../anaconda2/bin/uic
	/Users/dm/anaconda2/bin/uic infodialog.ui -o ui_infodialog.h

compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

