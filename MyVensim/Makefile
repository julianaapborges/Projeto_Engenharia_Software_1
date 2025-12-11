DLL:
	g++ -shared -fPIC -o ./bin/libmyvensim.so ./src/lib/*.cpp

BUILD_APP:
	g++ ./src/*.cpp -Lbin -lmyvensim -o ./bin/testeRegressivo.exe

APP:
	LD_LIBRARY_PATH=./bin ./bin/testeRegressivo.exe

BUILD_UNIT_TEST:
	g++ ./test/unit/*.cpp -Lbin -lmyvensim -o ./bin/testeUnitario.exe

RUN_UNIT_TEST:
	LD_LIBRARY_PATH=./bin ./bin/testeUnitario.exe

BUILD_FUNC_TEST:
	g++ ./test/funcional/*.cpp -Lbin -lmyvensim -o ./bin/testeFuncional.exe

RUN_FUNC_TEST:
	LD_LIBRARY_PATH=./bin ./bin/testeFuncional.exe

CLEAN:
	rm -rf ./bin/*