#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=-g \
  -O3 \
  -pipe \
  -W \
  -Wall \
  -Wextra \
  -fPIC \
  -pthread \
  -std=c++11 \
  -Wno-parentheses \
  -Wno-literal-suffix \
  -Wno-unused-parameter \
  -Wno-unused-local-typedefs
CFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CPPFLAGS=
INCPATH=-I. \
  -I/home/chenkang/chenkang02/com/btest/gtest/output/include/
DEP_INCPATH=

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=6682dc25817be2f88f0cbff289e8bc9a  COMAKE


.PHONY:all
all:comake2_makefile_check libtable_parser.a example1 example2 table_parser_test common_test fs_reader_test table_parser_test 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf libtable_parser.a
	rm -rf ./output/lib/libtable_parser.a
	rm -rf ./output/include/parse_helper.h
	rm -rf ./output/include/common.h
	rm -rf ./output/include/fs_reader.h
	rm -rf ./output/include/table_parser.h
	rm -rf example1
	rm -rf ./examples/example1
	rm -rf example2
	rm -rf ./examples/example2
	rm -rf table_parser_test
	rm -rf ./tests/table_parser_test
	rm -rf common_test
	rm -rf ./tests/common_test
	rm -rf fs_reader_test
	rm -rf ./tests/fs_reader_test
	rm -rf table_parser_test
	rm -rf ./tests/table_parser_test
	rm -rf table_parser_parse_helper.o
	rm -rf table_parser_common.o
	rm -rf table_parser_fs_reader.o
	rm -rf table_parser_table_parser.o
	rm -rf examples/example1_example1.o
	rm -rf examples/example2_example2.o
	rm -rf tests/table_parser_test_test_parse_helper.o
	rm -rf tests/common_test_test_common.o
	rm -rf tests/fs_reader_test_test_fs_reader.o
	rm -rf tests/table_parser_test_test_table_parser.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

libtable_parser.a:table_parser_parse_helper.o \
  table_parser_common.o \
  table_parser_fs_reader.o \
  table_parser_table_parser.o \
  parse_helper.h \
  common.h \
  fs_reader.h \
  table_parser.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibtable_parser.a[0m']"
	ar crs libtable_parser.a table_parser_parse_helper.o \
  table_parser_common.o \
  table_parser_fs_reader.o \
  table_parser_table_parser.o
	mkdir -p ./output/lib
	cp -f libtable_parser.a ./output/lib
	mkdir -p ./output/include
	cp -f parse_helper.h common.h fs_reader.h table_parser.h ./output/include

example1:libtable_parser.a \
  examples/example1_example1.o \
  libtable_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mexample1[0m']"
	$(CXX) examples/example1_example1.o -Xlinker "-(" libtable_parser.a  -L \
  /home/chenkang/chenkang02/com/btest/gtest/output/lib \
  -pthread \
  -lgtest \
  -lgtest_main -Xlinker "-)" -o example1
	mkdir -p ./examples
	cp -f example1 ./examples

example2:libtable_parser.a \
  examples/example2_example2.o \
  libtable_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mexample2[0m']"
	$(CXX) examples/example2_example2.o -Xlinker "-(" libtable_parser.a  -L \
  /home/chenkang/chenkang02/com/btest/gtest/output/lib \
  -pthread \
  -lgtest \
  -lgtest_main -Xlinker "-)" -o example2
	mkdir -p ./examples
	cp -f example2 ./examples

table_parser_test:libtable_parser.a \
  tests/table_parser_test_test_parse_helper.o \
  libtable_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtable_parser_test[0m']"
	$(CXX) tests/table_parser_test_test_parse_helper.o -Xlinker "-(" libtable_parser.a  -L \
  /home/chenkang/chenkang02/com/btest/gtest/output/lib \
  -pthread \
  -lgtest \
  -lgtest_main -Xlinker "-)" -o table_parser_test
	mkdir -p ./tests
	cp -f table_parser_test ./tests

common_test:libtable_parser.a \
  tests/common_test_test_common.o \
  libtable_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcommon_test[0m']"
	$(CXX) tests/common_test_test_common.o -Xlinker "-(" libtable_parser.a  -L \
  /home/chenkang/chenkang02/com/btest/gtest/output/lib \
  -pthread \
  -lgtest \
  -lgtest_main -Xlinker "-)" -o common_test
	mkdir -p ./tests
	cp -f common_test ./tests

fs_reader_test:libtable_parser.a \
  tests/fs_reader_test_test_fs_reader.o \
  libtable_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mfs_reader_test[0m']"
	$(CXX) tests/fs_reader_test_test_fs_reader.o -Xlinker "-(" libtable_parser.a  -L \
  /home/chenkang/chenkang02/com/btest/gtest/output/lib \
  -pthread \
  -lgtest \
  -lgtest_main -Xlinker "-)" -o fs_reader_test
	mkdir -p ./tests
	cp -f fs_reader_test ./tests

table_parser_test:libtable_parser.a \
  tests/table_parser_test_test_table_parser.o \
  libtable_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtable_parser_test[0m']"
	$(CXX) tests/table_parser_test_test_table_parser.o -Xlinker "-(" libtable_parser.a  -L \
  /home/chenkang/chenkang02/com/btest/gtest/output/lib \
  -pthread \
  -lgtest \
  -lgtest_main -Xlinker "-)" -o table_parser_test
	mkdir -p ./tests
	cp -f table_parser_test ./tests

table_parser_parse_helper.o:parse_helper.cpp \
  parse_helper.h \
  common.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtable_parser_parse_helper.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o table_parser_parse_helper.o parse_helper.cpp

table_parser_common.o:common.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtable_parser_common.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o table_parser_common.o common.cpp

table_parser_fs_reader.o:fs_reader.cpp \
  fs_reader.h \
  common.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtable_parser_fs_reader.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o table_parser_fs_reader.o fs_reader.cpp

table_parser_table_parser.o:table_parser.cpp \
  common.h \
  fs_reader.h \
  table_parser.h \
  parse_helper.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtable_parser_table_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o table_parser_table_parser.o table_parser.cpp

examples/example1_example1.o:examples/example1.cpp \
  parse_helper.h \
  common.h \
  common.h \
  fs_reader.h \
  table_parser.h \
  fs_reader.h \
  parse_helper.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mexamples/example1_example1.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o examples/example1_example1.o examples/example1.cpp

examples/example2_example2.o:examples/example2.cpp \
  parse_helper.h \
  common.h \
  common.h \
  fs_reader.h \
  table_parser.h \
  fs_reader.h \
  parse_helper.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mexamples/example2_example2.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o examples/example2_example2.o examples/example2.cpp

tests/table_parser_test_test_parse_helper.o:tests/test_parse_helper.cpp \
  parse_helper.h \
  common.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtests/table_parser_test_test_parse_helper.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tests/table_parser_test_test_parse_helper.o tests/test_parse_helper.cpp

tests/common_test_test_common.o:tests/test_common.cpp \
  common.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtests/common_test_test_common.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tests/common_test_test_common.o tests/test_common.cpp

tests/fs_reader_test_test_fs_reader.o:tests/test_fs_reader.cpp \
  fs_reader.h \
  common.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtests/fs_reader_test_test_fs_reader.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tests/fs_reader_test_test_fs_reader.o tests/test_fs_reader.cpp

tests/table_parser_test_test_table_parser.o:tests/test_table_parser.cpp \
  table_parser.h \
  fs_reader.h \
  common.h \
  parse_helper.h \
  fs_reader.h \
  common.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtests/table_parser_test_test_table_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tests/table_parser_test_test_table_parser.o tests/test_table_parser.cpp

endif #ifeq ($(shell uname -m),x86_64)


