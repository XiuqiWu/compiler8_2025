# CACT compiler skeleton

## using antlr4 to generate files from grammar file

```bash
java -jar ../deps/antlr-4.13.1-complete.jar -Dlanguage=Cpp CACT.g4 -no-visitor -listener
```

## compile the cmake project

```bash
mkdir -p build
cd build
cmake ..
make -j8
 到根目录下：
 chmod +x batch_functional.sh编译到.s
chmod +x s.sh
./batch_functional.sh执行.s
./s.sh
```
