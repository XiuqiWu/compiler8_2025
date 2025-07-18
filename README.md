# CACT compiler 

## using antlr4 to generate files from grammar file

```bash
java -jar ../deps/antlr-4.13.1-complete.jar -Dlanguage=Cpp CACT.g4 -no-visitor -listener
```

## compile the cmake project

```bash
./run.sh
输出到out目录下
```
