.PHONY: all dist install uninstall dist dvi clean check rebuild tests
CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror -Wextra -g
OS = $(shell uname -s)
TEST_FLAGS = -o test.out -lgtest

ifeq ($(OS), Linux)
	TEST_FLAGS += -lpthread
endif

all: tests check install dvi

tests: ./Tests/tests.cc
	$(CXX) $(CXXFLAGS) ./Tests/tests.cc ./Model/Object_Handler/Recorder/V_F_Recorder/v_f_parser.cc $(TEST_FLAGS)
	./test.out

dvi:
	touch readme.dvi
	@(echo "В данном проекте предстоит реализовать на языке программирования С++ в парадигме объектно-ориентированного программирования приложение для просмотра 3D моделей в каркасном виде, реализующее те же самые функции, что и разработанное ранее приложение в проекте 3DViewer v1.0." > readme.dvi)
	

dist:
	rm -rf archive_viewer/
	mkdir archive_viewer/
	mkdir archive_viewer/src/
ifeq ($(OS), Darwin)
	cp -r ./build/viewer.app archive_viewer/src/
else
	cp -r ./build/viewer archive_viewer/src/
endif
	tar cvzf archive_viewer.tgz archive_viewer/
	rm -rf archive_viewer/

install:
	cd View/Viewer && qmake && make && make clean && rm Makefile && cd ../../ && mkdir build
ifeq ($(OS), Darwin)
	mv View/Viewer/viewer.app build
else
	mv View/Viewer/viewer build
endif

uninstall:
	rm -rf build*

clean:
	rm -rf *.out *.a *.o *.dSYM .DS_Store *.dvi View/Viewer/.qmake.stash
	
check:
	clang-format -style=google -n ./*/*/*.cc ./*/*/*.h
	clang-format -style=google -i ./*/*/*.cc ./*/*/*.h
	clang-format -style=google -n ./*/*/*/*.cc ./*/*/*/*.h
	clang-format -style=google -i ./*/*/*/*.cc ./*/*/*/*.h
	clang-format -style=google -n ./*/*/*/*/*.cc ./*/*/*/*/*.h
	clang-format -style=google -i ./*/*/*/*/*.cc ./*/*/*/*/*.h
	cppcheck ./*/*.cc
	cppcheck ./*/*/*.cc
	cppcheck ./*/*/*/*.cc
	cppcheck ./*/*/*/*/*.cc

rebuild: clean all