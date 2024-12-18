@echo off
rem build.bat 파일 예제
rem 첫 번째 인자: 컴파일할 소스 파일명 (예: test.cpp)
rem 그 외 인자: cl에 전달할 추가 옵션들

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars32.bat"
cl %*