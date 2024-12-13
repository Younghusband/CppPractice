/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: 上机编程认证
 * Caution：本地调试时，只编译运行main.cpp文件，不要链接这个文件！因为本文件已经被main.cpp文件include了
 */

#include <array>

using namespace std;

class VideoService {

public:
    VideoService(const array<int, 3>& channels, const array<int, 3>& charge)
    {


    }

    bool AllocateChannel(int time, int userId, int videoType)
    {
        return false;
    }

    int FreeChannel(int time, int userId)
    {
        return 0;
    }

    int QueryChannel(int userId)
    {
        return 0;
    }
};
