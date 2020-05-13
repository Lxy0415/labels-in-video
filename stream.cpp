//
// Created by lxy on 2020/5/13.
//
#include <iostream>
extern "C" {
#include "libavformat/avformat.h"
}

#define CHECK(x) do { \
        if(!(x)) return -1; \
    }while(0)

int main(int argc, char* argv[]) {
    std::cout << "extract labels from stream" << std::endl;
    AVFormatContext *fmt_ctx = nullptr;
    int ret = 0;
    ret = avformat_open_input(&fmt_ctx, "../data/stream.flv", NULL, NULL);
    CHECK(ret == 0);
    ret = avformat_find_stream_info(fmt_ctx, NULL);
    CHECK(ret == 0);
    std::cout << "find " << fmt_ctx->nb_streams << " streams" << std::endl;
    int label_stream_id = 0;
    for (int i = 0; i < fmt_ctx->nb_streams; ++i) {
        auto s = fmt_ctx->streams[i];
        std::cout << "stream " << i << " " << av_get_media_type_string(s->codecpar->codec_type) << std::endl;
        if(s->codecpar->codec_type == AVMEDIA_TYPE_SUBTITLE)
            label_stream_id = i;
    }
    //av_dump_format(fmt_ctx, 0, "", 0);
    AVPacket p;
    do {
        ret = av_read_frame(fmt_ctx, &p);
        if(p.stream_index != label_stream_id) {
            std::cout << "find a packet that is not a label packet, skip it" << std::endl;
            continue;
        }
        std::cout << "find a label packet, pts = " << p.pts << " len = " << p.size << std::endl;
        std::string content(reinterpret_cast<char*>(p.data), p.size);
        std::cout << "content of label: " << content << std::endl;
    } while (ret >= 0);
    avformat_close_input(&fmt_ctx);
    return 0;
}