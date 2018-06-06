#ifndef TYPES_H__15_05_2009__14_37
#define TYPES_H__15_05_2009__14_37

//#ifdef _WIN32
//#ifndef WIN32
//#define WIN32
//#endif
//#endif

#ifdef WIN32
#endif 

#define __packed /**/
#define __softfp /**/
#define __irq /**/



typedef unsigned char byte, u8;
typedef unsigned short int word, u16;
typedef unsigned long int dword, u32;
typedef signed char i8;
typedef signed short int i16;
typedef signed long int i32;
typedef signed long long int i64;
typedef unsigned long long int u64;

#define ArraySize(x) (sizeof(x)/sizeof(x[0]))

#ifndef NAN
static const dword __NAN_dword = 0xFFFFFFFF;
#define NAN (*((const float*)(&__NAN_dword)))
#endif

inline float ABS(float v) { *((u32*)&v) &= 0x7FFFFFFF; return v; }

inline bool fIsValid(float v) { return (((u16*)&v)[2] & 0x7F80) != 0x7F80; }
inline bool dIsValid(float v) { return (((u32*)&v)[2] & 0x7FF0) != 0x7FF0; }

#define GD(adr, t, i) (*(((t*)adr)+i))

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
union DataCRC
{
	word	w;
	byte	b[2];
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

union U16u 
{
	word w; byte b[2]; 

	U16u(word v) {w = v;}
	operator word() {return w;}
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

union U32u 
{ 
	dword d; word w[2]; byte b[4]; 

	U32u(dword v) {d = v;}
	U32u() {d = 0;}
	operator dword() {return d;}
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

union F32u
{ 
	float f; dword d; word w[2]; byte b[4]; 

	F32u (float v) {f = v;}
	operator float() {return f;}
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

union DataPointer
{
	__packed void	*v;
	__packed byte	*b;
	__packed word	*w;
	__packed dword	*d;
	__packed float	*f;

	DataPointer(__packed void *p) { v = p; } 

	void operator=(__packed void *p) { v = p; } 
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

union ConstDataPointer
{
	__packed const void		*v;
	__packed const byte		*b;
	__packed const word		*w;
	__packed const dword	*d;
	__packed const float	*f;

	ConstDataPointer(__packed const void *p) { v = p; } 

	void operator=(__packed const void *p) { v = p; } 
};


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // TYPES_H__15_05_2009__14_37
