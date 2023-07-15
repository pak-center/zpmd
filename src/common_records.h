#ifndef _COMMON_RECORDS_H
#define	_COMMON_RECORDS_H

#ifdef	__cplusplus
extern "C" {
#endif

struct mce
{
__u8 rec_type;
__u8 domains;
__u16 ibm;
__u32 rec_start;
__u32 rec_end;
};

struct header
{
__u16 rec_length;
__u16 zeros;
__u8 domain_id;
__u8 ibm;
__u16 rec_id;
__eu64 build_time; //TOD
__u32 ibm2;
};

#ifdef	__cplusplus
}
#endif

#endif	/* _COMMON_RECORDS_H */