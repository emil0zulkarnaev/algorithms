PWD=$(shell pwd)
INCLUDE=${PWD}/../common/ \
		${PWD}/../sorting/ \
		${PWD}/../search

%:
	g++ $(foreach d, $(INCLUDE), -I$d) $@.cpp ${PWD}/../common/structs.cpp ${PWD}/../common/ioms.cpp ${PWD}/../sorting/fast.cpp ${PWD}/../search/binary.cpp && ./a.out
