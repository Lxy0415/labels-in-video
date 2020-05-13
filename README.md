# labels-in-video

## what
本示例从flv文件或rtmp流的subtitle流中获取label并打印出来，label具体格式未完全确定，拟使用json字符串。

## dep
ffmpeg4.0以上

cmake3.10以上

pkgconfig

## how
```$xslt
mkdir build
cd build
cmake ..
make
./stream
```
