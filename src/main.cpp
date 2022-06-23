#include <stdio.h>
#include "logger.h"

int main()
{
        printf("Hello World!\n");
        lhg::LOG_INFO("test");
        lhg::LOG_DEBUG("test");
        lhg::LOG_WARN("test");
        lhg::LOG_ERROR("test");
        lhg::LOG_CRIT("test");
        return 0;
}