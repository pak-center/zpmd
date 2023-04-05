#include "tod2utc.h"

// TIME FUNCTION
__eu64 tod2utc(__eu64 time)
{
    time = (__eu64) time - (__eu64) 0x7d91048bca000000ULL;
    time = time >> 12;
    //time = do_div(time, 1000000);
    time = time / 1000000;
    return time;
};
