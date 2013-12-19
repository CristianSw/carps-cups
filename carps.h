#define u8 unsigned char
#define u16 unsigned short

#define ESC 0x1b

#define DICT_SIZE 16

//#define BUF_SIZE 4096
#define BUF_SIZE 65536

#define MAX_BLOCK_LEN 4096

#define MASK(n)	((1 << n) - 1)

#define be16_to_cpu(x) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))
#define cpu_to_be16(x) be16_to_cpu(x)

#define cpu_to_le16(x) (x)
#define le16_to_cpu(x) (x)

struct carps_header {
	u8 magic1;	/* 0xCD */
	u8 magic2;	/* 0xCA */
	u8 magic3;	/* 0x10 */
	u8 data_type;	/* 0x00 = control data, 0x02 = print data */
	u8 zero1;	/* 0x00 */
	u8 block_type;	/* 0x11, 0x12, 0x13, 0x14, 0x16, 0x17, 0x18, 0x19, 0x1a */
	u8 zero2;	/* 0x00 */
	u8 one;		/* 0x01 */
	u16 data_len;	/* number of following data bytes, big endian */
	u8 empty[10];	/* zeros */
} __attribute__((packed));

#define CARPS_DATA_CONTROL	0x00
#define CARPS_DATA_PRINT	0x02

#define CARPS_BLOCK_BEGIN	0x11
#define CARPS_BLOCK_DOC_INFO	0x12
#define CARPS_BLOCK_END		0x13
#define CARPS_BLOCK_BEGIN1	0x14
#define CARPS_BLOCK_END1	0x16
#define CARPS_BLOCK_BEGIN2	0x17
#define CARPS_BLOCK_PARAMS	0x18
#define CARPS_BLOCK_END2	0x19
#define CARPS_BLOCK_PRINT	0x1a

struct carps_doc_info {
	u16 type;
	u16 unknown;
	u8 data_len;
} __attribute__((packed));
#define CARPS_DOC_INFO_TITLE	0x0004
#define CARPS_DOC_INFO_USER	0x0006

struct carps_print_params {
	u8 magic;
	u8 param;
	u8 enabled;
} __attribute__((packed));
#define CARPS_PARAM_MAGIC	0x08
#define CARPS_PARAM_IMAGEREFINE	0x2d
#define CARPS_PARAM_TONERSAVE	0x5a
#define CARPS_PARAM_DISABLED	0x01
#define CARPS_PARAM_ENABLED	0x02

struct carps_print_header {
	u8 one;		/* 0x01 */
	u8 two;		/* 0x02 */
	u8 four;	/* 0x04 */
	u8 eight;	/* 0x08 */
	u16 zero1;	/* 0x0000 */
	u8 magic;	/* 0x50 */
	u8 zero2;	/* 0x00 */
	u8 last;	/* 0x00 = last packet, 0x01 = not last packet */
	u16 data_len;	/* little endian?? */
	u16 zero3;
} __attribute__((packed));

#define PRINT_DATA_XOR 0x43
